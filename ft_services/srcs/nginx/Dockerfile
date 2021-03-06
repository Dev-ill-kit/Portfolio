FROM alpine:latest
VOLUME [ "/sys/fs/cgroup" ]
RUN apk update && apk upgrade
RUN apk add nginx
RUN apk add openssh
RUN apk add openssl
RUN apk add openrc
RUN apk add supervisor
COPY ./setup.sh /setup.sh
COPY ./default.conf /etc/nginx/conf.d/default.conf
COPY ./supervisord.conf /etc/supervisord.conf
RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
-keyout /etc/ssl/private/service-nginx.key -out /etc/ssl/certs/service-nginx.crt \
-subj "/C=RU/ST=MOSCOW/L=MOSCOW/O=21School/OU=Ctora/CN=localhost/emailAdress=name@index.com" \
&& chmod 600 /etc/ssl/certs/service-nginx.crt && chmod 600 /etc/ssl/private/service-nginx.key
RUN echo -e "root\nroot" | adduser ctora
EXPOSE 443 80 22
RUN mkdir -p /run/nginx
RUN chmod +x /setup.sh
CMD /setup.sh
