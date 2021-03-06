FROM alpine:latest

RUN apk update && apk upgrade
RUN apk add openrc
RUN apk update && apk upgrade \
&& apk add php7 php7-fpm php7-opcache php7-gd php7-mysqli php7-zlib php7-curl php7-mbstring php7-json php7-session \
lighttpd php7-common php7-iconv php7-xml php7-imap php7-cgi fcgi php7-pdo php7-pdo_mysql php7-soap php7-xmlrpc \
php7-posix php7-mcrypt php7-gettext php7-ldap php7-ctype php7-dom
COPY ./lighttpd.conf /etc/lighttpd/lighttpd.conf
COPY ./mod_fastcgi.conf /etc/lighttpd/mod_fastcgi.conf
RUN openrc default
VOLUME [ "/sys/fs/cgroup" ]
RUN rc-service lighttpd restart
RUN adduser -u 2000 -G www-data -s /bin/sh -D www-data
WORKDIR /var/www/localhost/htdocs/
RUN wget http://files.directadmin.com/services/all/phpMyAdmin/phpMyAdmin-5.0.2-all-languages.tar.gz \
&& tar zxvf phpMyAdmin-5.0.2-all-languages.tar.gz \
&& mv phpMyAdmin-5.0.2-all-languages/* ./ \
&& rm -rf phpMyAdmin-5.0.2-all-languages.tar.gz phpMyAdmin-5.0.2-all-languages
COPY ./config.inc.php /var/www/localhost/htdocs/config.inc.php
RUN chmod -R 755 /var/www/localhost/htdocs/config.inc.php
WORKDIR /etc/lighttpd/
EXPOSE 5000
CMD lighttpd -f lighttpd.conf -D
