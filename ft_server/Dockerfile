FROM		debian:buster
LABEL		maintainer="sgang"
ENV		AUTOPATH /etc/nginx/sites-available
ENV		AUTOIDX 1
RUN		apt-get update && apt-get install -y \
		vim \
		wget \
		openssl \
		nginx \
		mariadb-server \
		php-mysql \
		php-mbstring \
		php-xml \
		php7.3-fpm
COPY		./srcs ./init
RUN		bash /init/init.sh
EXPOSE		80 443
ENTRYPOINT	bash /init/entry.sh

