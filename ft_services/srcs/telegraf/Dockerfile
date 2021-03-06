FROM alpine:latest
VOLUME [ "/sys/fs/cgroup" ]
RUN apk update
RUN wget -q -O /etc/apk/keys/sgerrand.rsa.pub https://alpine-pkgs.sgerrand.com/sgerrand.rsa.pub
RUN wget https://github.com/sgerrand/alpine-pkg-glibc/releases/download/2.31-r0/glibc-2.31-r0.apk
RUN echo "http://nl.alpinelinux.org/alpine/edge/testing" >> /etc/apk/repositories
RUN apk add openrc glibc-2.31-r0.apk
RUN apk upgrade
RUN apk add telegraf
COPY ./telegraf.conf /telegraf.conf
COPY ./setup.sh /setup.sh
RUN chmod +x /setup.sh
CMD ./setup.sh