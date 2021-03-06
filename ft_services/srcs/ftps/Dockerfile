FROM alpine:latest
RUN apk update && apk upgrade
RUN apk add openrc --no-cache
RUN apk add vsftpd openssl --allow-untrusted --no-cache
VOLUME [ "/sys/fs/cgroup" ]
COPY ./setup.sh /setup.sh
RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
-keyout /etc/ssl/private/service-ftp.key -out /etc/ssl/certs/service-ftp.crt \
-subj "/C=RU/ST=MOSCOW/L=MOSCOW/O=21School/OU=Ctora/CN=localhost/emailAdress=name@index.com" \
&& chmod 600 /etc/ssl/certs/service-ftp.crt && chmod 600 /etc/ssl/private/service-ftp.key
COPY ./vsftpd.conf /etc/vsftpd/vsftpd.conf
RUN echo -e "root\nroot" | adduser ctora
EXPOSE 20 21 2121
RUN chmod +x /setup.sh
CMD ./setup.sh
