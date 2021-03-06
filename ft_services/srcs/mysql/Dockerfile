FROM alpine:latest
RUN apk update && apk upgrade
RUN apk add mysql mysql-client --allow-untrusted --no-cache
VOLUME [ "/var/lib/mysql" ]
VOLUME [ "/sys/fs/cgroup" ]
RUN apk add openrc --allow-untrusted --no-cache
COPY ./setup.sh /setup.sh
COPY ./wordpress.sql /wordpress.sql
COPY ./my.cnf /etc/mysql/my.cnf
RUN chmod 744 /etc/mysql/my.cnf
EXPOSE 3306
RUN chmod +x /setup.sh
CMD ./setup.sh
