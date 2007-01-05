#!/bin/sh
set -e

### BEGIN INIT INFO
# Provides: ircd
# Required-Start: $local_fs $network $remote_fs
# Required-Stop: $local_fs $network $remote_fs
# Default-Start: 2 3 4 5
# Default-Stop: 0 1 6
# Short-Description: start and stop oftc-hybrid ircd
# Description: This is the IRC server designed for use on OFTC (irc.oftc.net),
#  based on the Hybrid 7 ircd.
### END INIT INFO

PATH=/usr/local/sbin:/usr/local/bin:/sbin:/bin:/usr/sbin:/usr/bin
DAEMON=/usr/sbin/ircd
NAME=ircd
DESC="oftc-hybrid ircd"
PIDFILE="/var/run/ircd.pid"
ARGS="--quiet --chuid irc:irc --pidfile $PIDFILE --exec $DAEMON"

test -x $DAEMON || exit 0

touch_files () {
	LOGS=`perl -lne 'print $1 if /^\s*f\w+_\w+log\s*=\s*"(.*)"/' < /etc/oftc-hybrid/ircd.conf`
	for l in /var/log/oftc-hybrid/ircd.log $LOGS $PIDFILE ; do
		if [ ! -e "$l" ] ; then
			touch $l
			chown irc.irc $l
		fi
	done
}

case "$1" in
  start)
	echo -n "Starting $DESC: "
	touch_files
	start-stop-daemon --start $ARGS
	;;
  stop)
	echo -n "Stopping $DESC: "
	start-stop-daemon --stop --oknodo $ARGS
	echo "$NAME."
	;;
  reload)
	echo "Reloading $DESC configuration files."
	start-stop-daemon --stop --signal 1 $ARGS
	;;
  force-reload)
	echo "Reloading $DESC configuration files."
	start-stop-daemon --stop --signal 1 $ARGS || $0 restart
	;;
  restart)
	$0 stop
	sleep 1
	$0 start
	;;
  *)
	echo "Usage: $0 {start|stop|restart|reload|force-reload}" >&2
	exit 1
	;;
esac

exit 0
