FROM alpine:latest
VOLUME [ "/sys/fs/cgroup" ]
RUN wget -q -O /etc/apk/keys/sgerrand.rsa.pub https://alpine-pkgs.sgerrand.com/sgerrand.rsa.pub
RUN wget https://github.com/sgerrand/alpine-pkg-glibc/releases/download/2.31-r0/glibc-2.31-r0.apk
RUN apk update && apk upgrade
RUN apk add openrc glibc-2.31-r0.apk
RUN wget https://dl.grafana.com/oss/release/grafana-6.7.2.linux-amd64.tar.gz \
&& tar -zxvf grafana-6.7.2.linux-amd64.tar.gz
COPY ./grafana.db ./grafana-6.7.2/data/grafana.db
WORKDIR /grafana-6.7.2/bin
EXPOSE 3000
CMD ./grafana-server
