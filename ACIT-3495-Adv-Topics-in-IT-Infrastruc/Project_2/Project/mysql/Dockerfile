FROM mysql:latest

COPY ./init.sql /docker-entrypoint-initdb.d/

# ENV MYSQL_ROOT_PASSWORD=password
# ENV MYSQL_DATABASE=example_db

# Expose the MySQL port
# EXPOSE 3306