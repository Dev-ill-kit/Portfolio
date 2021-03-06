#OS
FROM		debian:buster

#updating and cleaning space
RUN			apt-get update && apt-get -y dist-upgrade && apt-get clean

#installing apps
RUN			apt-get install -y nginx && apt-get install -y openssl &&\
			apt-get install -y php-fpm && apt-get install -y php-mbstring &&\
			apt-get install -y mariadb-server && apt-get install -y php-mysql &&\
			apt-get install -y wget

#generating ssl key
RUN			mkdir etc/nginx/ssl && openssl req -newkey rsa:2048 -days 365 -nodes -x509 -out etc/nginx/ssl/localhost.pem -keyout etc/nginx/ssl/localhost.key\
			-subj "/C=RU/ST=MOSCOW/L=MOSCOW/O=21School/OU=Ctora/CN=localhost/emailAdress=name@index.com" &&\
			chmod 600 etc/nginx/ssl/localhost.pem && chmod 600 etc/nginx/ssl/localhost.key

#downloading and installing php-myadmin
RUN 		mkdir var/www/index && wget https://files.phpmyadmin.net/phpMyAdmin/5.0.2/phpMyAdmin-5.0.2-all-languages.tar.gz && tar -xvf phpMyAdmin-5.0.2-all-languages.tar.gz &&\
			mv phpMyAdmin-5.0.2-all-languages var/www/index/phpmyadmin

#downloading and installing wordpress
RUN			wget https://wordpress.org/latest.tar.gz && tar -xvf latest.tar.gz && mv wordpress/ var/www/index &&\
			chown -R www-data:www-data var/www/index/wordpress

#creating folders
COPY		./srcs/start.sh ./
COPY		./srcs/config.inc.php var/www/index/phpmyadmin/config.inc.php
COPY		./srcs/default etc/nginx/sites-available/default
COPY		./srcs/wp-config.php var/www/index/wordpress/wp-config.php

#initialisating container
CMD			bash start.sh





