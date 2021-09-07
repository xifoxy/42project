#!/bin/bash
if [ $1 -eq 1 ]; then
	sed -i 's/autoindex off/autoindex on/' $AUTOPATH/default
	sed -i 's/ index index.nginx-debian.html/#index index.nginx-debian.html/' $AUTOPATH/default
	export AUTOIDX=1
elif [ $1 -eq 0 ]; then
        sed -i 's/autoindex on/autoindex off/' $AUTOPATH/default
	sed -i 's/#index index.nginx-debian.html/ index index.nginx-debian.html/' $AUTOPATH/default
	export AUTOIDX=0
fi
service nginx reload
exit
