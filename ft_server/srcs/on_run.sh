#!/bin/bash
docker build -t ft_server:d_buster ../
docker run -it -p 80:80 -p 443:443 -e AUTOIDX=1 --name ft_server ft_server:d_buster

bash
