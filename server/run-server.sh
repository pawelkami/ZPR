#!/bin/sh

if [ "$#" -gt 1 ]
then
	echo "Usage: ./run-server.sh [option]"
	exit 1 
fi

if [ "$1" = "check" ]
then
	lighttpd -t -f lighttpd.conf
else
	lighttpd -D -f lighttpd.conf
fi

exit 0
