FROM alpine:latest
VOLUME [ "/sys/fs/cgroup" ]
RUN apk update && apk upgrade
RUN apk add openrc
RUN apk add nginx supervisor
RUN apk add php7 php7-fpm php7-opcache php7-gd php7-mysqli php7-zlib php7-curl php7-mbstring php7-json php7-session \
lighttpd php7-common php7-iconv php7-xml php7-imap php7-cgi fcgi php7-pdo php7-pdo_mysql php7-soap php7-xmlrpc \
php7-posix php7-mcrypt php7-gettext php7-ldap php7-ctype php7-dom php7-intl php7-zip
RUN adduser -u 2000 -G www-data -s /bin/sh -D www-data
EXPOSE 5050
RUN mkdir -p /var/www/localhost/
COPY ./default.conf /etc/nginx/conf.d/default.conf
COPY ./www.conf /etc/php7/php-fpm.d/www.conf
COPY ./supervisor.conf /etc/supervisord.conf
COPY ./setup.sh /setup.sh
WORKDIR /var/www/localhost/
RUN mkdir -p /run/nginx
RUN wget https://ru.wordpress.org/wordpress-5.4.2-ru_RU.tar.gz && tar zxvf wordpress-5.4.2-ru_RU.tar.gz \
&& mv wordpress/* ./ && rm -rf wordpress wordpress-5.4.2-ru_RU.tar.gz
COPY ./wp-config.php ./
RUN chown -R www-data:www-data /var/www/*
RUN chmod 755 -R /var/www/*
RUN chmod +x /setup.sh
CMD /setup.sh
