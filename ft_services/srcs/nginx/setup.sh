#!/bin/sh
openrc default
rc-service sshd start
ssh keygen
rc-service sshd stop
/usr/bin/supervisord -c /etc/supervisord.conf