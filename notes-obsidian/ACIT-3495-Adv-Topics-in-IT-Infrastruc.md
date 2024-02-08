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
## Week 4

Delete old images
```bash
docker rmi -f $(docker image ls -aq)
```
### edit image (manual)
Pull Image
```bash
docker pull ubuntu:latest
```
Create container
```bash
docker run -it ubuntu
```
Make changes
```bash
# install vim, curl, ping
apt-get update
apt-get install -y vim
apt-get install -y curl
apt-get install -y iputils-ping
```
commit 
```bash
docker commit container-ID image-name
```

### Using dockerfile

```
#Dockerfile
❯ cat Dockerfile
FROM ubuntu

RUN apt-get update
RUN apt-get install -y vim
RUN apt-get install -y curl
RUN apt-get install -y iputils-ping

CMD ["bash"]
```
Build
```bash
docker build -t l3-ubuntu:v2 .
```
Upload
```bash
docker tag <image_id> markusbcit/l3-ubuntu:v2
```
Push
```bash
docker push markusbcit/l3-ubuntu:v2
```
Pull new image
```bash
docker pull markusbcit/l3-ubuntu:v2
```
Run
```bash
docker run -it markusbcit/l3-ubuntu:v2
```
## inspect docker images
```bash
docker inspect <image id>
```

## Running code (python)
python file
```bash
❯ cat python-app.py
print('Hello')
```
Dockerfile
```bash
❯ cat Dockerfile
FROM node:14
WORKDIR /usr/src/app
COPY python-app.py ./
CMD ["python", "python-app.py"]
```
build
```bash
docker build -t python .
```
run
```bash
docker run python
```
### using [node](https://learn.bcit.ca/d2l/le/content/1007217/viewContent/9694522/View)

## using docker-componse.yml

```
docker-compose up -d
```

- #lab 
	- q1
		- ![[Pasted image 20240201085832.png]]
		- ![[Pasted image 20240201085903.png]]
		- ![[Pasted image 20240201090308.png]]
	- q2
		- ![[Pasted image 20240201093643.png]]
		- ![[Pasted image 20240201093701.png]]
		- ![[Pasted image 20240201094002.png]]
		- ![[Pasted image 20240201094246.png]]
	- Q3
		- the layers show the changes we made
		  ![[Pasted image 20240201094514.png]]
	- q4
		- ![[Pasted image 20240201104747.png]]
	- q5
		- ![[Pasted image 20240201100245.png]]
		- 
	- q6
		- ![[Pasted image 20240201104340.png]]

```yml
❯ cat docker-compose.yml
version: '3.3'

#networking
networks:
  network:
    # Use a custom driver
    driver: bridge

services:
   db:
     image: mysql:5.7
     volumes:
      - db_data:/var/lib/mysql
     restart: always
     environment:
       MYSQL_ROOT_PASSWORD: somewordpress
       MYSQL_DATABASE: wordpress
       MYSQL_USER: wordpress
       MYSQL_PASSWORD: wordpress
     networks:
       - network
   wordpress:
     depends_on:
       - db
     image: wordpress:latest
     volumes:
      - wp_data:/var/www/html
     ports:
       - "8000:80"
     restart: always
     environment:
       WORDPRESS_DB_HOST: db:3306
       WORDPRESS_DB_USER: wordpress
       WORDPRESS_DB_PASSWORD: wordpress
       WORDPRESS_DB_NAME: wordpress
     networks:
       - network

volumes:
  db_data:
  wp_data:
```
# week 5

## kubernetes

#commands
```bash
kubectl cluster-info
kubectl get nodes
kubectl get pods
kubectl get pods -o wide
kubectl get pods --watch
kubectl get svc
kubectl get services
kubectl get deployments
kubectl get replicaset
kubectl describe pods

kubectl run tomcat --image tomcat:8.0 --port=8080
kubectl delete pod tomcat
kubectl expose pod tomcat --name=tomcat-svc --target-port=8080 --type=NodePort

kubectl delete service tomcat-svc
kubectl delete pod tomcat


kubectl create deployment app1 --image aldiab/webapp
kubectl get svc
kubectl get pods
kubectl describe pod .............
kubectl get deployments
kubectl get replicaset
kubectl scale deployment app1 --replicas 3
kubectl scale deployment app1 --replicas 2
kubectl delete pod ................
kubectl expose deployment app1 --type LoadBalancer --port 80 --target-port 8080
kubectl delete service app1
kubectl delete deployment app1
kubectl get namespace
kubectl get pods --namespace=ns1
kubectl create namespace ns1
kubectl get pods --show-labels
kubectl run nginx --image=nginx --namespace=ns1
kubectl create -f https://k8s.io/examples/admin/namespace-dev.json
kubectl get pods -l 'env in (production, development)'
kubectl get pods -l env=development
kubectl run nginx --image=nginx --namespace=ns1
kubectl label pods tomcat label3=healthy
kubectl label --overwrite pods tomcat  status=unhealthy
```

#lab 
- q2
```bash
kubectl run nginx --image=nginx --port=80
kubectl expose pod nginx --name=nginx-service --port=80 --target-port=80 --type=NodePort
kubectl get svc nginx-service
```
![[Pasted image 20240208111033.png]]
![[Pasted image 20240208111335.png]]


- q3
```bash
kubectl create namespace ns1
kubectl run ns1-pod --image=nginx --namespace=ns1
```
![[Pasted image 20240208110049.png]]
- q4
```bash
kubectl run pod1 --image=nginx --namespace=ns1 --labels=Label1=Frontend,Label2=Production

kubectl run pod2 --image=nginx --namespace=ns1 --labels=Label1=Frontend,Label2=Test

kubectl run pod3 --image=nginx --namespace=ns1 --labels=Label1=Backend,Label2=Production
```
![[Pasted image 20240208110108.png]]
- q5
```bash
kubectl get pods -n ns1 --selector=Label2=Production
kubectl get pods -n ns1 --selector=Label1=Frontend,Label2=Production
```
![[Pasted image 20240208110134.png]]
- q6
```basg
docker build -t markusbcit/appname:tag .
docker push markusbcit/appname:tag
```
![[Pasted image 20240208110158.png]]
- q7
```bash
kubectl create deployment nginx-deployment --image=nginx --replicas=3
```
![[Pasted image 20240208110211.png]]
- q8
```bash
kubectl expose deployment nginx-deployment --port=80 --target-port=80 --type=NodePort
kubectl get svc nginx-deployment
```

- q9
```bash
kubectl delete namespace ns1
```
![[Pasted image 20240208110354.png]]
- q10
	- Kubernetes and Docker Swarm are both container orchestration platforms, but they have some differences:
	    - Kubernetes:
	        - More complex architecture with a master-node setup.
	        - Richer feature set including advanced scheduling, auto-scaling, and rolling updates.
	        - Supports larger clusters and more complex deployments.
	    - Docker Swarm:
	        - Simpler architecture with a manager-worker setup.
	        - Easier to set up and manage for smaller-scale deployments.
	        - Better integration with Docker tools and ecosystem.
	        - Suitable for simpler applications and smaller teams.