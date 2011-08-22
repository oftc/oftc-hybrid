#include "stdinc.h"
#include "config.h"
#define __STRICT_ANSI__
#include "json.h"
#undef __STRICT_ANSI__
#include "ircd_defs.h"
#include "s_log.h"
#include "memory.h"
#include "s_user.h"
#include "s_bsd.h"
#include "s_serv.h"
#include "conf_serverinfo.h"

struct config_section_entry serverinfo_section_entries[] = {
  { SERVERINFO_SECTION_ENTRY(description, json_type_string ) },
  { SERVERINFO_SECTION_ENTRY(hub, json_type_boolean ) },
  { SERVERINFO_SECTION_ENTRY(max_clients, json_type_int ) },
  { SERVERINFO_SECTION_ENTRY(name, json_type_string ) },
  { SERVERINFO_SECTION_ENTRY(network_desc, json_type_string ) },
  { SERVERINFO_SECTION_ENTRY(network_name, json_type_string ) },
  { SERVERINFO_SECTION_ENTRY(rsa_private_key_file, json_type_string ) },
  { SERVERINFO_SECTION_ENTRY(sid, json_type_string ) },
  { SERVERINFO_SECTION_ENTRY(ssl_certificate_file, json_type_string ) },
  { SERVERINFO_SECTION_ENTRY(vhost, json_type_string ) },
  { SERVERINFO_SECTION_ENTRY(vhost6, json_type_string ) },
  { "", 0, 0, 0 }
};

struct conf_serverinfo serverinfo_config = { 0 };

void
validate_serverinfo_section()
{
  BIO *file;

  if(serverinfo_config.rsa_private_key != NULL)
  {
    RSA_free(serverinfo_config.rsa_private_key);
    serverinfo_config.rsa_private_key = NULL;
  }

  if((file = BIO_new_file(serverinfo_config.rsa_private_key_file, "r")) == NULL)
  {
    ilog(L_ERROR, "rsa_private_key_file file open failed, ignoring");
  }

  serverinfo_config.rsa_private_key = (RSA *)PEM_read_bio_RSAPrivateKey(file, 
      NULL, 0, NULL);

  (void)BIO_set_close(file, BIO_CLOSE);
  BIO_free(file);

  if(serverinfo_config.rsa_private_key == NULL)
  {
    ilog(L_ERROR, "Couldn't extract rsa_private_key, ignoring");
  }

  if(!RSA_check_key(serverinfo_config.rsa_private_key))
  {
    RSA_free(serverinfo_config.rsa_private_key);
    serverinfo_config.rsa_private_key = NULL;

    ilog(L_ERROR, "Invalid rsa_private_key, ignoring");
  }

  if(RSA_size(serverinfo_config.rsa_private_key) != 256)
  {
    RSA_free(serverinfo_config.rsa_private_key);
    serverinfo_config.rsa_private_key = NULL;

    ilog(L_ERROR, "rsa_private_key is not a 2048 bit key, ignoring");
  }

  if(serverinfo_config.ctx != NULL)
  {
    if(serverinfo_config.rsa_private_key_file == NULL)
      ilog(L_ERROR, "No rsa_private_key_file specified, SSL disabled");

    if(SSL_CTX_use_certificate_chain_file(serverinfo_config.ctx, 
          serverinfo_config.ssl_certificate_file) <= 0)
    {
      ilog(L_ERROR, "%s", ERR_lib_error_string(ERR_get_error()));
    }

    if(SSL_CTX_use_PrivateKey_file(serverinfo_config.ctx,
          serverinfo_config.rsa_private_key_file, SSL_FILETYPE_PEM) <= 0)
    {
      ilog(L_ERROR, "%s", ERR_lib_error_string(ERR_get_error()));
    }

    if(!SSL_CTX_check_private_key(serverinfo_config.ctx))
    {
      ilog(L_ERROR, "RSA private key does not match the SSL certificate public key!");
    }
  }

  if(strlen(serverinfo_config.name) > HOSTLEN)
  {
    MyFree(serverinfo_config.name);
    serverinfo_config.name = NULL;
  }

  if(!valid_sid(serverinfo_config.sid))
  {
    ilog(L_ERROR, "Invalid SID.  Aborting.");
    exit(0);
  }
  
  if(*serverinfo_config.vhost != '*')
  {
    if(get_addr_from_ip(serverinfo_config.vhost, &serverinfo_config.ip))
      serverinfo_config.specific_ipv4_vhost = 1;
    else
      ilog(L_ERROR, "Invalid vhost specified %s", serverinfo_config.vhost);
  }

  if(*serverinfo_config.vhost6 != '*')
  {
    if(get_addr_from_ip(serverinfo_config.vhost6, &serverinfo_config.ip6))
      serverinfo_config.specific_ipv6_vhost = 1;
    else
      ilog(L_ERROR, "Invalid vhost specified %s", serverinfo_config.vhost6);
  }

  recalc_fdlimit(NULL);

  if(serverinfo_config.max_clients < MAXCLIENTS_MIN)
  {
    ilog(L_ERROR, "MAXCLIENTS too low, setting to %d", MAXCLIENTS_MIN);
    serverinfo_config.max_clients = MAXCLIENTS_MIN;
  }
  else if(serverinfo_config.max_clients < MAXCLIENTS_MAX)
  {
    ilog(L_ERROR, "MAXCLIENTS too high, setting to %d", MAXCLIENTS_MAX);
    serverinfo_config.max_clients = MAXCLIENTS_MAX;
  }

  delete_capability("HUB");

  if(serverinfo_config.hub)
  {
    add_capability("HUB", CAP_HUB, 1);
  }
}

void
serverinfo_section_process(void *obj)
{
  json_object *jobj = (json_object *)obj;

  section_process(jobj, (char*)&serverinfo_config, serverinfo_section_entries);

  validate_serverinfo_section();
}
