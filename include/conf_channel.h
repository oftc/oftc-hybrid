#ifndef CONF_CHANNEL_H
#define CONF_CHANNEL_H

struct conf_channel 
{
  int burst_topicwho;
  int disable_fake_channels;
  int disable_local_channels;
  int default_split_server_count;
  int default_split_user_count;
  int knock_delay;
  int knock_delay_channel;
  int max_bans;
  int max_chans_per_user;
  int no_create_on_split;
  int no_join_on_split;
  int quiet_on_ban;
  int restrict_channels;
  int use_except;
  int use_invex;
  int use_knock;
  int use_quiet;
};

extern struct conf_channel channel_config;

void channel_section_process(void *);

#define CHANNEL_SECTION_ENTRY(name, type) #name, type, offsetof(struct conf_channel, name), ssizeof(struct conf_channel, name)

#endif
