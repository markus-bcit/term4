# Week 1
- #outline  [outline](https://www.bcit.ca/outlines/20241089227/)
	- |**Criteria**|**%**|**Comments**|
	  | --- | --- | --- |
	  |In-class Labs|20|A formative style of guided labs designed to assist students in learning and gradually developing skills|
	  |Practical Projects|32|Two summative group-based projects are scheduled, one around the middle and another towards the end of the semester|
	  |Final Exam|48|
# week 2
## Management Commands:
```bash
# Container Management
docker create
docker start
docker stop
docker restart
docker pause
docker unpause
docker rename
docker rm
docker ps
docker stats
docker top
docker logs
```
## Image Commands:
```bash
# Image Operations
docker pull
docker build
docker push
docker tag
docker rmi
docker images
docker history
docker save
docker load
```
 ## Example Commands:
```bash
# Pulling an image
docker pull ubuntu:latest

# Building an image
docker build -t my-image .

# Pushing an image
docker push my-image

# Tagging an image
docker tag my-image myimage:latest

# Removing an image
docker rmi my-image

# Listing Docker images
docker images

# Displaying image history
docker history my-image

# Saving an image to a tar archive
docker save my-image -o myimage.tar

# Loading an image from a tar archive
docker load -i my-image.tar
```
## Getting Help:
- To get help on the `docker image ls` command:
```bash
docker help image ls
```
## Examples of Commands with Two Ways:
- Listing all containers:
```bash
docker ps -a
```
or
```bash
docker container ls -a
```
-  in interactive mode:
```bash
docker run -it [image_name]
```
or
```bash
docker run --interactive --tty [image_name]
```
## List all images:
```bash
docker images
```
## List Docker containers
```
docker ps -a 
```
## Run 3 containers with different operating systems
```bash
# Interactive mode
docker run -it --name container1 ubuntu
docker run -it --name container2 alpine
docker run -it --name container3 centos

# Detached mode
docker run -d --name container4 ubuntu
docker run -d --name container5 alpine
docker run -d --name container6 centos
```
## Run a Linux command on a container in the background:
```bash
docker exec -d container_name command
# Example:
docker exec -d container1 ls
```
## Rename a container:
```bash
docker rename old_container_name new_container_name
# Example:
docker rename container1 new_container_name1
```
## Clean up all containers:
```bash
# Stop all running containers
docker stop $(docker ps -q)

# Remove all containers
docker rm $(docker ps -a -q)
```

# Week 3
## create sql in volume
```bash
# Creates the Docker container
docker run --name mysql -d \
    -p 3306:3306 \
    -e MYSQL_ROOT_PASSWORD=123456 \
    -v mysql:/var/lib/mysql \
    mysql

# Executes the bash shell in the mysql container
docker exec -it mysql bash
# Log into the container's mysql root user
mysql -u root -p
# password is 123456

DROP DATABASE IF EXISTS todoDB;
CREATE DATABASE todoDB;

USE todoDB;

CREATE TABLE todo(
id INT PRIMARY KEY AUTO_INCREMENT,
todo VARCHAR(40) NOT NULL,
note VARCHAR(255),
finished BOOLEAN DEFAULT false);


INSERT INTO todo(id, todo, note, finished)
VALUES(1, "Wash Car", "", false),
(2, "Laundry", "Jeans", false),
(3, "Wash dishes", "", true);
```
## Open multiple Ubuntu containers and log to a shared text file on the host
```bash
mkdir logsdir
touch logsdir/log1

container1=$(docker run -d --name container1 -v $(pwd)/logsdir:/logsdir ubuntu tail -f /dev/null) 

echo "container id/name: ${container1}" >> logsdir/log1 
echo "----- commands output -----" >> logsdir/log1 
echo "History of commands:" >> logsdir/log1

docker exec container1 sh -c 'mkdir /file >> /logsdir/log1 2>&1'
docker exec container1 sh -c 'mkdir /file >> /logsdir/log1 2>&1'
docker exec container1 sh -c 'touch /file1 >> /logsdir/log1 2>&1'
docker exec container1 sh -c 'ls / >> /logsdir/log1 2>&1'
docker exec container1 sh -c 'mv /file1 /logsdir/newfile >> /logsdir/log1 2>&1'
docker exec container1 sh -c 'rm /file >> /logsdir/log1 2>&1'
docker exec container1 sh -c 'history >> /logsdir/log1 2>&1'

container2=$(docker run -d --name container2 -v $(pwd)/logsdir:/logsdir ubuntu tail -f /dev/null) 

echo "container id/name: ${container2}" >> logsdir/log1 
echo "----- commands output -----" >> logsdir/log1 
echo "History of commands:" >> logsdir/log1

docker exec container2 sh -c 'mkdir /file >> /logsdir/log1 2>&1'
docker exec container2 sh -c 'mkdir /file >> /logsdir/log1 2>&1'
docker exec container2 sh -c 'touch /file1 >> /logsdir/log1 2>&1'
docker exec container2 sh -c 'ls / >> /logsdir/log1 2>&1'
docker exec container2 sh -c 'mv /file1 /logsdir/newfile >> /logsdir/log1 2>&1'
docker exec container2 sh -c 'rm /file >> /logsdir/log1 2>&1'
docker exec container2 sh -c 'history >> /logsdir/log1 2>&1'
```
## adding netwrok
List Docker Networks:
```bash
docker network ls
```
Create a Bridge Network (network1)
```bash
docker network create network1
```
Attach a Container to network1
```bash
docker run -d --name my_container --network network1 ubuntu tail -f /dev/null
```
Inspect the Container
```bash
docker inspect my_container
```
## add another
Run Another Ubuntu Container on the Same Network (`network1`)
```bash
docker run -d --name my_second_container --network network1 ubuntu tail -f /dev/null
```
Ping the First Container from the Second Container (using Container Name):
```bash
docker exec my_second_container sh -c 'apt-get update'
docker exec my_second_container sh -c 'apt-get install -y iputils-ping'
docker exec my_second_container sh -c 'ping my_container'
```
Ping using ip
```bash
# Get the IP address of the first container
container1_ip=$(docker inspect -f '{{range .NetworkSettings.Networks}}{{.IPAddress}}{{end}}' my_container)

# Ping using the IP address
docker exec my_second_container ping $container1_ip
```
Create Another Network (`network2`) and Run a Container on It:
```bash
# Create a new bridge network
docker network create network2

# Run a container on the new network
docker run -d --name my_third_container --network network2 ubuntu tail -f /dev/null

docker exec my_third_container sh -c 'apt-get update'
docker exec my_third_container sh -c 'apt-get install -y iputils-ping'
```
Try to Ping the First Container from the Third Container (using Container Name and IP):
```bash

# This should fail as containers are on different networks
docker exec my_third_container ping my_container
docker exec my_third_container ping $container1_ip
```
## attach webserver
Run a Simple Web Server Container (`web_server`) on `network1`:
```bash
docker run -d --name web_server --network network1 -p 8080:80 httpd:alpine
```
Attach Another Container to the Same Network (`network1`):
```bash
docker run -it --name client_container --network network1 ubuntu
```
Retrieve HTML Content from `web_server` Container:
```bash
# Inside the client_container
apt-get update && apt-get install -y curl

# Retrieve HTML content from the web server
curl web_server/index.html
```
Create Another Network (`network2`) and Run a Container on It:
```bash
# Create a new bridge network
docker network create network2

# Run a container on the new network
docker run -it --name client_container_network2 --network network2 ubuntu
```
Try to Retrieve HTML Content from `web_server` Container (from a Container on `network2`):
```bash
# Inside the client_container_network2
# This should fail as the containers are on different networks
curl web_server/index.html
```