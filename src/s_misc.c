/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  s_misc.c: Yet another miscellaneous functions file.
 *
 *  Copyright (C) 2002 by the past and present ircd coders, and others.
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307
 *  USA
 *
 *  $Id: s_misc.c 33 2005-10-02 20:50:00Z knight $
 */

#include "client.h"
#include "common.h"
#include "fdlist.h"
#include "irc_res.h"
#include "irc_string.h"
#include "ircd.h"
#include "memory.h"
#include "numeric.h"
#include "s_bsd.h"
#include "s_conf.h"
#include "s_serv.h"
#include "send.h"
#include "s_misc.h"
#include "sprintf_irc.h"
#include "stdinc.h"

#define SHA_DIGEST_LEN 20
#define HEX_DIGEST_LEN 40

static const char *months[] = {"January",   "February", "March",    "April",
                               "May",       "June",     "July",     "August",
                               "September", "October",  "November", "December"};

static const char *weekdays[] = {"Sunday",   "Monday", "Tuesday", "Wednesday",
                                 "Thursday", "Friday", "Saturday"};

char *
date(time_t lclock)
{
    static char buf[80], plus;
    struct tm *lt, *gm;
    struct tm gmbuf;
    int minswest;

    if(!lclock)
        lclock = CurrentTime;
    gm         = gmtime(&lclock);
    memcpy(&gmbuf, gm, sizeof(gmbuf));
    gm = &gmbuf;
    lt = localtime(&lclock);

    /*
     * There is unfortunately no clean portable way to extract time zone
     * offset information, so do ugly things.
     */
    minswest = (gm->tm_hour - lt->tm_hour) * 60 + (gm->tm_min - lt->tm_min);

    if(lt->tm_yday != gm->tm_yday)
    {
        if((lt->tm_yday > gm->tm_yday && lt->tm_year == gm->tm_year) ||
           (lt->tm_yday < gm->tm_yday && lt->tm_year != gm->tm_year))
            minswest -= 24 * 60;
        else
            minswest += 24 * 60;
    }

    plus = (minswest > 0) ? '-' : '+';
    if(minswest < 0)
        minswest = -minswest;

    ircsprintf(buf, "%s %s %d %d -- %02u:%02u:%02u %c%02u:%02u",
               weekdays[lt->tm_wday], months[lt->tm_mon], lt->tm_mday,
               lt->tm_year + 1900, lt->tm_hour, lt->tm_min, lt->tm_sec, plus,
               minswest / 60, minswest % 60);
    return buf;
}

const char *
smalldate(time_t lclock)
{
    static char buf[MAX_DATE_STRING];
    struct tm *lt, *gm;
    struct tm gmbuf;

    if(!lclock)
        lclock = CurrentTime;

    gm = gmtime(&lclock);
    memcpy(&gmbuf, gm, sizeof(gmbuf));
    gm = &gmbuf;
    lt = localtime(&lclock);

    ircsprintf(buf, "%04d-%02d-%02d %02d:%02d:%02d", lt->tm_year + 1900,
               lt->tm_mon + 1, lt->tm_mday, lt->tm_hour, lt->tm_min,
               lt->tm_sec);

    return buf;
}

/* small_file_date()
 * Make a small YYYYMMDD formatted string suitable for a
 * dated file stamp.
 */
char *
small_file_date(time_t lclock)
{
    static char timebuffer[MAX_DATE_STRING];
    struct tm *tmptr;

    if(!lclock)
        time(&lclock);

    tmptr = localtime(&lclock);
    strftime(timebuffer, MAX_DATE_STRING, "%Y%m%d", tmptr);

    return timebuffer;
}

#ifdef HAVE_LIBCRYPTO
char *
ssl_get_cipher(SSL *ssl)
{
    static char buffer[IRCD_BUFSIZE];
    int bits = 0;

    SSL_CIPHER_get_bits(SSL_get_current_cipher(ssl), &bits);

    snprintf(buffer, sizeof(buffer), "%s %s-%d", SSL_get_version(ssl),
             SSL_get_cipher(ssl), bits);
    return buffer;
}
#endif

/*  The following functions are:
 *  Copyright (c) 2001-2004, Roger Dingledine
 *  Copyright (c) 2004-2007, Roger Dingledine, Nick Mathewson
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions are
 *  met:
 *
 *  Redistributions of source code must retain the above copyright
 *  notice, this list of conditions and the following disclaimer.

 * Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer
 * in the documentation and/or other materials provided with the distribution.
 *
 * Neither the names of the copyright owners nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.

 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#define SIZE_T_CEILING (sizeof(char) << (sizeof(size_t) * 8 - 1))

/** Encode the <b>srclen</b> bytes at <b>src</b> in a NUL-terminated,
 * uppercase hexadecimal string; store it in the <b>destlen</b>-byte buffer
 * <b>dest</b>.
 */
void
base16_encode(char *dest, size_t destlen, const char *src, size_t srclen)
{
    const char *end;
    char *cp;

    assert(destlen >= srclen * 2 + 1);

    cp  = dest;
    end = src + srclen;
    while(src < end)
    {
        *cp++ = "0123456789ABCDEF"[(*(const uint8_t *)src) >> 4];
        *cp++ = "0123456789ABCDEF"[(*(const uint8_t *)src) & 0xf];
        ++src;
    }
    *cp = '\0';
}

/** Helper: given a hex digit, return its value, or -1 if it isn't hex. */
static int
hex_decode_digit(char c)
{
    switch(c)
    {
    case '0':
        return 0;
    case '1':
        return 1;
    case '2':
        return 2;
    case '3':
        return 3;
    case '4':
        return 4;
    case '5':
        return 5;
    case '6':
        return 6;
    case '7':
        return 7;
    case '8':
        return 8;
    case '9':
        return 9;
    case 'A':
    case 'a':
        return 10;
    case 'B':
    case 'b':
        return 11;
    case 'C':
    case 'c':
        return 12;
    case 'D':
    case 'd':
        return 13;
    case 'E':
    case 'e':
        return 14;
    case 'F':
    case 'f':
        return 15;
    default:
        return -1;
    }
}

/** Given a hexadecimal string of <b>srclen</b> bytes in <b>src</b>, decode it
 * and store the result in the <b>destlen</b>-byte buffer at <b>dest</b>.
 * Return 0 on success, -1 on failure. */
int
base16_decode(char *dest, size_t destlen, const char *src, size_t srclen)
{
    const char *end;

    int v1, v2;
    if((srclen % 2) != 0)
        return -1;
    if(destlen < srclen / 2 || destlen > SIZE_T_CEILING)
        return -1;
    end = src + srclen;
    while(src < end)
    {
        v1 = hex_decode_digit(*src);
        v2 = hex_decode_digit(*(src + 1));
        if(v1 < 0 || v2 < 0)
            return -1;
        *(uint8_t *)dest = (v1 << 4) | v2;
        ++dest;
        src += 2;
    }
    return 0;
}

/** used by tortls.c: get an equivalent EVP_PKEY* for a crypto_pk_env_t.  Iff
 * private is set, include the private-key portion of the key. */
EVP_PKEY *
_crypto_pk_env_get_evp_pkey(RSA *ekey, int private)
{
    RSA *key       = NULL;
    EVP_PKEY *pkey = NULL;
    assert(ekey);
    if(private)
    {
        if(!(key = RSAPrivateKey_dup(ekey)))
            goto error;
    }
    else
    {
        if(!(key = RSAPublicKey_dup(ekey)))
            goto error;
    }
    if(!(pkey = EVP_PKEY_new()))
        goto error;
    if(!(EVP_PKEY_assign_RSA(pkey, key)))
        goto error;
    return pkey;
error:
    if(pkey)
        EVP_PKEY_free(pkey);
    if(key)
        RSA_free(key);
    return NULL;
}

X509 *
create_certificate(RSA *rsa, RSA *rsa_sign, const char *cname,
                   const char *cname_sign, unsigned int cert_lifetime)
{
    time_t start_time, end_time;
    EVP_PKEY *sign_pkey = NULL, *pkey = NULL;
    X509 *x509      = NULL;
    X509_NAME *name = NULL, *name_issuer = NULL;
    int nid;

    start_time = time(NULL);

    assert(rsa);
    assert(cname);
    assert(rsa_sign);
    assert(cname_sign);
    if(!(sign_pkey = _crypto_pk_env_get_evp_pkey(rsa_sign, 1)))
        goto error;
    if(!(pkey = _crypto_pk_env_get_evp_pkey(rsa, 0)))
        goto error;
    if(!(x509 = X509_new()))
        goto error;
    if(!(X509_set_version(x509, 2)))
        goto error;
    if(!(ASN1_INTEGER_set(X509_get_serialNumber(x509), (long)start_time)))
        goto error;

    if(!(name = X509_NAME_new()))
        goto error;
    if((nid = OBJ_txt2nid("organizationName")) == NID_undef)
        goto error;
    if(!(X509_NAME_add_entry_by_NID(name, nid, MBSTRING_ASC,
                                    (unsigned char *)"ircd", -1, -1, 0)))
        goto error;
    if((nid = OBJ_txt2nid("commonName")) == NID_undef)
        goto error;
    if(!(X509_NAME_add_entry_by_NID(name, nid, MBSTRING_ASC,
                                    (unsigned char *)cname, -1, -1, 0)))
        goto error;
    if(!(X509_set_subject_name(x509, name)))
        goto error;

    if(!(name_issuer = X509_NAME_new()))
        goto error;
    if((nid = OBJ_txt2nid("organizationName")) == NID_undef)
        goto error;
    if(!(X509_NAME_add_entry_by_NID(name_issuer, nid, MBSTRING_ASC,
                                    (unsigned char *)"ircd", -1, -1, 0)))
        goto error;
    if((nid = OBJ_txt2nid("commonName")) == NID_undef)
        goto error;
    if(!(X509_NAME_add_entry_by_NID(name_issuer, nid, MBSTRING_ASC,
                                    (unsigned char *)cname_sign, -1, -1, 0)))
        goto error;
    if(!(X509_set_issuer_name(x509, name_issuer)))
        goto error;

    if(!X509_time_adj(X509_get_notBefore(x509), 0, &start_time))
        goto error;
    end_time = start_time + cert_lifetime;
    if(!X509_time_adj(X509_get_notAfter(x509), 0, &end_time))
        goto error;
    if(!X509_set_pubkey(x509, pkey))
        goto error;
    if(!X509_sign(x509, sign_pkey, EVP_sha1()))
        goto error;

    goto done;
error:
    if(x509)
    {
        X509_free(x509);
        x509 = NULL;
    }
done:
    if(sign_pkey)
        EVP_PKEY_free(sign_pkey);
    if(pkey)
        EVP_PKEY_free(pkey);
    if(name)
        X509_NAME_free(name);
    if(name_issuer)
        X509_NAME_free(name_issuer);
    return x509;
}

/** Compute the SHA1 digest of <b>len</b> bytes in data stored in
 * <b>m</b>.  Write the DIGEST_LEN byte result into <b>digest</b>.
 * Return 0 on success, -1 on failure.
 */
static int
crypto_digest(char *digest, const char *m, size_t len)
{
    assert(m);
    assert(digest);
    return (SHA1((const unsigned char *)m, len, (unsigned char *)digest) ==
            NULL);
}

/* Not quite the tor code, but close.. digest must have DIGEST_LEN len at
 * least
 */
static int
rsa_key_to_digest(RSA *rsa, char *digest)
{
    unsigned char *buf, *bufp;
    int len;

    len = i2d_RSAPublicKey(rsa, NULL);
    if(len < 0)
        return -1;
    buf = bufp = MyMalloc(len + 1);
    len        = i2d_RSAPublicKey(rsa, &bufp);
    if(len < 0)
    {
        MyFree(buf);
        return -1;
    }
    if(crypto_digest(digest, (char *)buf, len) < 0)
    {
        MyFree(buf);
        return -1;
    }
    MyFree(buf);
    return 0;
}

/** Given a private or public key <b>pk</b>, put a fingerprint of the
 * public key into <b>fp_out</b> (must have at least FINGERPRINT_LEN+1 bytes of
 * space).  Return 0 on success, -1 on failure.
 *
 * Fingerprints are computed as the SHA1 digest of the ASN.1 encoding
 * of the public key, converted to hexadecimal, in upper case.
 */
int
get_rsa_fingerprint(RSA *rsa, char *fp_out)
{
    char digest[SHA_DIGEST_LEN];
    char hexdigest[HEX_DIGEST_LEN + 1];
    if(rsa_key_to_digest(rsa, digest))
        return -1;

    base16_encode(hexdigest, sizeof(hexdigest), digest, SHA_DIGEST_LEN);
    strncpy(fp_out, hexdigest, HEX_DIGEST_LEN + 1);
    return 0;
}
