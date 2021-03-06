FROM alpine:latest
VOLUME [ "/sys/fs/cgroup" ]
RUN apk update && apk upgrade
RUN apk add openrc --allow-untrusted --no-cache
RUN apk add influxdb --allow-untrusted --no-cache
COPY ./setup.sh /setup.sh
EXPOSE 3000
RUN chmod +x /setup.sh
CMD ./setup.sh
