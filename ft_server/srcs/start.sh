service mysql start

mysql < var/www/html/phpmyadmin/sql/create_tables.sql -u root --skip-password
mysqladmin -u root -p password 'root'

echo "CREATE DATABASE IF NOT EXISTS wordpress;" | mysql -u root --skip-password
echo "GRANT ALL PRIVILEGES ON wordpress.* TO 'root'@'%' identified by 'root' WITH GRANT OPTION;" | mysql -u root --skip-password
echo "FLUSH PRIVILEGES;" | mysql -u root --skip-password

service php7.3-fpm start
service nginx start
bash