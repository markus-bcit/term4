FROM handsonsecurity/seed-server:apache-php

ARG WWWDIR=/var/www/mywebsite

COPY ./index.html ./index_red.html $WWWDIR/
COPY ./mywebsite_apache_ssl.conf /etc/apache2/sites-available

COPY ./certs/server.crt ./certs/server.key  /certs/

RUN  chmod 400 /certs/server.key \
     && chmod 644 $WWWDIR/index.html \
     && chmod 644 $WWWDIR/index_red.html \
     && a2ensite mywebsite_apache_ssl   

CMD  tail -f /dev/null

