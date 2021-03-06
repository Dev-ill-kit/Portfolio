minikube --vm-driver=virtualbox start
minikube dashboard &
minikube addons enable metallb
kubectl apply -f ./srcs/configmap.yaml
eval $(minikube docker-env);
docker build -t nginx ./srcs/nginx
docker build -t phpmyadmin ./srcs/phpmyadmin
docker build -t wordpress ./srcs/wordpress
docker build -t mysql ./srcs/mysql
docker build -t grafana ./srcs/grafana
docker build -t influxdb ./srcs/influxdb
docker build -t telegraf ./srcs/telegraf
docker build -t ftps ./srcs/ftps
kubectl create -f ./srcs/nginx.yaml
kubectl create -f ./srcs/phpmyadmin.yaml
kubectl create -f ./srcs/wordpress.yaml
kubectl create -f ./srcs/mysql.yaml
kubectl create -f ./srcs/grafana.yaml
kubectl create -f ./srcs/influxdb.yaml
kubectl create -f ./srcs/telegraf.yaml
kubectl create -f ./srcs/ftps.yaml