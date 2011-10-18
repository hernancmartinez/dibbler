#!/bin/bash

# this is example notify script that can be invoked on a server side
# This script will be called by dibbler-server with a single parameter
# describing operation (add, update, delete, expire)
#
# Many parameters will be passed as environment variables

LOGFILE=/var/lib/dibbler/server.sh-log

# uncomment this to get full list of available variables
set >> $LOGFILE

echo "-----------" >> $LOGFILE
#set >> server.sh-log

if [ "$ADDR1" != "" ]; then
    echo "Address ${ADDR1} (operation $1) to client $REMOTE_ADDR on inteface $IFACE/$IFINDEX" >> $LOGNAME
fi

if [ "$PREFIX1" != "" ]; then
    echo "Prefix ${PREFIX1} (operation $1) to client $REMOTE_ADDR on inteface $IFACE/$IFINDEX" >> $LOGFILE
fi

exit 3