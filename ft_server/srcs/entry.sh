#!/bin/bash
service nginx start
bash /init/autoidx.sh $AUTOIDX
service mysql start
service php7.3-fpm start

echo "SERVER LAUNCHED"

bash
