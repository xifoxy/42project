#!/bin/bash
wget https://wordpress.org/latest.tar.gz
wget https://files.phpmyadmin.net/phpMyAdmin/5.1.0/phpMyAdmin-5.1.0-all-languages.tar.gz
tar -zxvf phpMyAdmin-5.1.0-all-languages.tar.gz
tar -zxvf latest.tar.gz

rm -rf latest.tar.gz
rm -rf phpMyAdmin-5.1.0-all-languages.tar.gz
openssl req -newkey rsa:4096 -days 365 -x509 -nodes -subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=SGANG/CN=localhost" -keyout localhost.dev.key -out localhost.dev.crt

mv localhost.dev.key /etc/ssl/private/
mv localhost.dev.crt /etc/ssl/certs/
mv wordpress /var/www/html
mv phpMyAdmin-5.1.0-all-languages phpmyadmin
mv phpmyadmin /var/www/html/

chown -R www-data:www-data /var/www/html/wordpress
chmod 600 /etc/ssl/certs/localhost.dev.crt /etc/ssl/private/localhost.dev.key

cp -rp /init/default /etc/nginx/sites-available/
cp -rp /init/wp-config.php /var/www/html/wordpress
cp -rp /init/config.inc.php /var/www/html/phpmyadmin/

service mysql start
mysql < /init/wp_init.sql
mysql < /var/www/html/phpmyadmin/sql/create_tables.sql
sleep 2
service mysql stop
