#ifndef CONF_SERVERINFO_H
#define CONF_SERVERINFO_H

#define SERVERINFO_SECTION_ENTRY(name, type) #name, type, offsetof(struct conf_serverinfo, name), ssizeof(struct conf_serverinfo, name)

struct conf_serverinfo
{
  char *description;
  int hub;
  int max_clients;
  char *name;
  char *network_desc;
  char *network_name;
  char *rsa_private_key_file;
  char *sid;
  char *ssl_certificate_file;
  char *vhost;
  char *vhost6;

  int can_use_v6;
  struct sockaddr_in dns_host;
  int specific_ipv4_vhost;
  int specific_ipv6_vhost;
#ifdef HAVE_LIBCRYPTO
  SSL_CTX *ctx;
  RSA *rsa_private_key;
#endif
  struct irc_ssaddr ip;
  struct irc_ssaddr ip6;
};

extern struct conf_serverinfo serverinfo_config;

void serverinfo_section_process(void *);

#endif
