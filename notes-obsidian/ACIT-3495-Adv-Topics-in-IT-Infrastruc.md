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
# Week 6
## Lab 4
1.     Create an nginx pod, expose it on a service using port 80 and show that the website is working. (1 mark)
```bash
kubectl create deployment nginx --image=nginx
```

```bash
kubectl expose deployment nginx --port=80 --type=NodePort
```

```bash
kubectl get svc
```

![[Pasted image 20240307093925.png]]
![[Pasted image 20240307094250.png]]

2.     Create a namespace **_ns1_** and a create a pod that belongs to ns1 (1 mark).
```bash
kubectl create namespace ns1
kubectl run nginx-ns1 --image=nginx --namespace=ns1
```
![[Pasted image 20240307094310.png]]
3.     Create 3 pods under ns1, and attach two labels to each one of them,  according to this table (2 marks)

```bash
kubectl run pod1 --image=nginx --labels="Label1=Frontend,Label2=Production" --namespace=ns1
kubectl run pod2 --image=nginx --labels="Label1=Frontend,Label2=Test" --namespace=ns1
kubectl run pod3 --image=nginx --labels="Label1=Backend,Label2=Production" --namespace=ns1
```

![[Pasted image 20240307094331.png]]

|      |          |            |
| ---- | -------- | ---------- |
|      | Label1   | Label2     |
| pod1 | Frontend | Production |
| pod2 | Frontend | Test       |
| Pod3 | Backend  | Production |

4.     Then: get all pods that have the Production label, get all pods that are in Production and FE.  (1 mark)
```bash
kubectl get pods -l Label2=Production --namespace=ns1
kubectl get pods -l Label1=Frontend,Label2=Production --namespace=ns1
```
![[Pasted image 20240307094352.png]]
5.     Modify the application in the App folder to show your group members names, build the image, and upload it to your docker hub account. (1 mark)

```bash
docker build -t markusbcit/app:tag .
docker push markusbcit/app:tag
```
![[Pasted image 20240307094525.png]]
![[Pasted image 20240307094546.png]]

6.     Create a deployment (3 replicas) imperatively from the container and test the pods, replicasets, deployments, services you have in the cluster. (1 mark)
```bash
kubectl create deployment myapp --image=markusbcit/app:tag --replicas=3
kubectl get pods,replicasets,deployments,services
```
![[Pasted image 20240307094612.png]]

7.     Expose the deployment in step 7 imperatively using a service and show that the website is working. (1 mark)
```bash
kubectl expose deployment myapp --port=8080 --type=NodePort
kubectl get svc
```
![[Pasted image 20240307094640.png]]
![[Pasted image 20240307102720.png]]
8.     Clean up all objects in **_ns1_** (1 mark)
```bash
kubectl delete namespace ns1
```
![[Pasted image 20240307102827.png]]
9.     Compare K8S to Docker Swarm in terms of differences  and similarities (1 mark)
Similarities:

- Both Kubernetes (K8S) and Docker Swarm are container orchestration platforms used for managing containerized applications.
- Both offer features like service discovery, load balancing, and scaling to manage containerized applications across a cluster of machines.
- They both support Docker containers.

Differences:
- Kubernetes is more feature-rich and complex compared to Docker Swarm. Kubernetes has a larger ecosystem with more advanced features like automatic scaling, rolling updates, and advanced networking capabilities.
- Kubernetes has a declarative configuration model, where users specify the desired state of the system, and Kubernetes takes care of bringing the actual state to match the desired state. Docker Swarm, on the other hand, uses a more imperative approach where users directly issue commands to manipulate the cluster state.
- Kubernetes has a larger community and is backed by multiple large companies like Google, while Docker Swarm is maintained by Docker, Inc.
- Kubernetes has better support for hybrid and multi-cloud environments.
- Kubernetes has more built-in integrations with other tools and platforms.
# Lab5

Q1. Deploy pod.yml. Get the details of the pod using commands: _kubectl get pods hello-pod -o wide, kubectl describe pods hello-pod_  (1 mark)
```bash
kubectl apply -f pod.yml
kubectl get pods hello-pod -o wide
kubectl describe pods hello-pod
```
![[Pasted image 20240307084309.png]]

Q2. Apply a watch on the pods using command: _kubectl get pods –watch_ (1 mark)
```bash
kubectl get pods --watch
```
![[Pasted image 20240307084529.png]]
Q3. Expose the pod **imperatively** and check if the website is working correctly, then delete the service (don’t delete the pod) (1 mark)
```bash
kubectl expose pod hello-pod --port=80 --target-port=8080 --name=hello-service --type=ClusterIP
kubectl get svc
kubectl delete service hello-service
```
![[Pasted image 20240307084853.png]]
![[Pasted image 20240307084940.png]]
Q4. Apply the service declaratively (NodePort) and check if the website is working correctly, then delete the service (don’t delete the pod) (1 mark)
```bash
kubectl apply -f .\svc-nodeport.yml
kubectl get svc
kubectl delete -f .\svc-nodeport.yml
```
![[Pasted image 20240307090616.png]]
Q5. Apply the service declaratively (LoadBalancer) and check if the website is working correctly. (Keep the service and the pod) (1 mark)
![[Pasted image 20240307090748.png]]
Q6. Use file rs1.yml to show how to create a replicaset (declaratively) and scale it up and down. You can open another terminal with a watch on the pods to see details about pods (pending, terminating, running). (1 mark)

Q7. Delete one of the pods and see how K8S self-heal the cluster, then delete the replicaset declaratively. (1 mark)

Q8. Modify the web app, build the docker image and push it to your docker hub account, write a yaml file to create a repliaset with 5 pods of the new app, and expose it using a Load balancer service. (1 mark)

Q9. Refer to this post [https://medium.com/google-cloud/kubernetes-nodeport-vs-loadbalancer-vs-ingress-when-should-i-use-what-922f010849e0](https://medium.com/google-cloud/kubernetes-nodeport-vs-loadbalancer-vs-ingress-when-should-i-use-what-922f010849e0) (and chap7 in the book) to demonstrate the differences between ClusterIP service, NodePort service, Load Balancer Service, and Ingress Service. Explain the sequence of steps that happen when a request arrives to each one of the mentioned services  (2 marks)

# Lab 6
**Deployment Update**
![[Pasted image 20240307103309.png]]
```bash
docker build -t markusbcit/web-app:v2 .
docker push markusbcit/web-app:v2
```
![[Pasted image 20240307103715.png]]
![[Pasted image 20240307103750.png]]

**Rolling Update**
![[Pasted image 20240307104139.png]]

![[Pasted image 20240307104553.png]]]]
![[Pasted image 20240307104636.png]]![[Pasted image 20240307104654.png]]
![[Pasted image 20240307104926.png]]
**Blue/Green Deployment**
![[Pasted image 20240307105210.png]]

![[Pasted image 20240307105201.png]]
![[Pasted image 20240307105749.png]]
![[Pasted image 20240307105911.png]]

![[Pasted image 20240307105827.png]]

**Canary Deployment**

![[Pasted image 20240307110016.png]]
![[Pasted image 20240307110124.png]]
![[Pasted image 20240307110325.png]]
# lab 7
(3 marks)

1.     Create a Pod YAML file with two containers that use the image alpine Provide a command for both containers that keep them running forever.
![[Pasted image 20240328110530.png]]

2.     Define a Volume of type emptyDir for the Pod. Container 1 should mount the Volume to path /etc/a, and container 2 should mount the Volume to path /etc/b.

3.     Open an interactive shell for container 1 and create the directory data in the mount path. Navigate to the directory and create the file hello.txt with the contents “Hello World.” Exit out of the container.

![[Pasted image 20240328110552.png]]

4.     Open an interactive shell for container 2 and navigate to the directory /etc/b/data. Inspect the contents of file hello.txt. Exit out of the container.

![[Pasted image 20240328110602.png]]

(4 marks)

5.     Create a PersistentVolume named logs-pv that maps to the hostPath /var/logs. The access mode should be ReadWriteOnce. Provision a storage capacity of 5Gi. Ensure that the status of the PersistentVolume shows Available.
![[Pasted image 20240328110616.png]]
![[Pasted image 20240328110622.png]]

6.     Create a PersistentVolumeClaim named logs-pvc. The access it uses is ReadWriteOnce. Request a capacity of 2Gi. Ensure that the status of the PersistentVolume shows Bound.
![[Pasted image 20240328110632.png]]
![[Pasted image 20240328110640.png]]
7.     Mount the PersistentVolumeClaim in a Pod running the image nginx at the mount path /var/log/nginx.
![[Pasted image 20240328110711.png]]
8.     Open an interactive shell to the container and create a new file named my-nginx.log in /var/log/nginx. Exit out of the Pod.
![[Pasted image 20240328110703.png]]
9.     Delete the Pod and re-create it with the same YAML manifest. Open an interactive shell to the Pod, navigate to the directory /var/log/nginx, and find the file you created before.
![[Pasted image 20240328110729.png]]
10.  Run the Init Container pattern example (1 mark)
![[Pasted image 20240328110352.png]]

11.  Run the web-app.yaml (Sidecar pattern first example). What is the difference between this and the one in step 10? (1 mark)
this created a service 
![[Pasted image 20240328110327.png]]
![[Pasted image 20240328111359.png]]
12.  Run the sidecar.yaml  (Sidecar pattern second example). Use the commands in the example.txt file to demo how it works:
![[Pasted image 20240328110418.png]]
![[Pasted image 20240328110440.png]]

kubectl create -f sidecar.yaml

kubectl get pods webserver

kubectl logs webserver -c sidecar

kubectl exec webserver -it -c sidecar -- /bin/sh

wget -O- localhost?unknown

cat /var/log/nginx/error.log

(1 mark)

```bash
kubectl create -f pod-with-vol.yaml
kubectl get pod business-app
kubectl exec business-app -it -c nginx -- /bin/sh
kubectl exec business-app -it -c app -- /bin/sh

kubectl create -f db-pv.yaml
kubectl get pv db-pv

kubectl create -f db-pvc.yaml
kubectl get pvc db-pvc
kubectl describe pvc db-pvc

kubectl create -f app-consuming-pvc.yaml
kubectl get pods
kubectl describe pod app-consuming-pvc

kubectl describe pvc db-pvc
kubectl exec app-consuming-pvc -it -- /bin/sh

kubectl create -f pod.yml
kubectl create -f service.yml

kubectl create -f web-app.yml
kubectl create -f sidecar.yaml
kubectl get pods webserver
kubectl logs webserver -c sidecar
 kubectl exec webserver -it -c sidecar -- /bin/sh
wget -O- localhost?unknown
cat /var/log/nginx/error.log
```
# Lab 9
1.     Create (imperatively) a ConfigMap that has two keys and two values  (1 mark)
![[Pasted image 20240404085831.png]]
2.     Write a YAML file to create the same ConfigMap declaratively (1 mark)
![[Pasted image 20240404090000.png]]
3.     Create the same ConfigMap from a configuration file (1 mark)
```bash
~/3495/lab9 on ☁️  acit4640_admin (us-west-2)
❯ kubectl create configmap my-configmap --from-file=config
configmap/my-configmap created

~/3495/lab9 on ☁️  acit4640_admin (us-west-2)
❯ cat config
key1=value1
key2=value2
```
4.     Create a Secret imperatively (1 mark)
![[Pasted image 20240404090133.png]]
5.     Write a YAML file to create the same Secret declaratively (1 mark)
![[Pasted image 20240404090339.png]]
6.     Read all ConfigMaps and Secrets (1 marks)
![[Pasted image 20240404090933.png]]
![[Pasted image 20240404090919.png]]
![[Pasted image 20240404090832.png]]

7.     Get the description of all ConfigMaps and Secrets (1 marks)
![[Pasted image 20240404090616.png]]
![[Pasted image 20240404090713.png]]
![[Pasted image 20240404090722.png]]
8.     Write a YAML to create a pod based on nginx image, the YAML file should read at least one value from a ConfigMap and one value from a Secret.
```yml
❯ cat q8.yml
apiVersion: v1
kind: Pod
metadata:
  name: nginx-pod
spec:
  containers:
    - name: nginx-container
      image: nginx
      env:
        - name: CONFIG_VALUE
          valueFrom:
            configMapKeyRef:
              name: myconfigmap
              key: data.bar
        - name: SECRET_VALUE
          valueFrom:
            secretKeyRef:
              name: my-secret
              key: data.pwd
```

```bash
kubectl create configmap config1 --from-literal=sleep-interval=25
kubectl create configmap myconfigmap --from-literal=foo=bar --from-literal=bar=baz
kubectl get configmap config1 -o yaml
kubectl get configmaps
kubectl create -f fortune-config.yaml
kubectl create -f fortune-pod-env-configmap.yaml
kubectl get secrets
kubectl describe secrets
kubectl create secret generic my-secret --from-literal=pwd=password
kubectl get secrets my-secret -o yaml
```

# Lab 10
Q1. Create a pod using readiness.yml, check if the pod is created.
![[Pasted image 20240404092612.png]]
Q2. Get the description of the pod and notice the readiness probe.
![[Pasted image 20240404092713.png]]
Q3. Change the readiness probe parameters, recreate the pod,  and notice the effect of that. Make sure that you understand the purpose of using readiness probes and how they work.
![[Pasted image 20240404093139.png]]
Q4. Create a pod using liveness.yml, check if the pod is created.
![[Pasted image 20240404093316.png]]
Q5. Get the description of the pod and notice the liveness probe.
![[Pasted image 20240404093308.png]]
Q6. Change the liveness probe parameters, recreate the pod, and notice the effect of that. Make sure that you understand the purpose of using liveness probes and how they work.
![[Pasted image 20240404093644.png]]
Q7. Create a pod using startup.yml, check if the pod is created.
![[Pasted image 20240404093715.png]]
Q8. Get the description of the pod and notice the startup probe.
![[Pasted image 20240404093751.png]]
Q9. Change the startup probe parameters, recreate the pod, and notice the effect of that. Make sure that you understand the purpose of using startup probes and how they work.
![[Pasted image 20240404093855.png]]
Hint: [This reference](https://kubernetes.io/docs/tasks/configure-pod-container/configure-liveness-readiness-startup-probes/) might help in answering the above questions.

Q10. Create a pod using crash-loop-back.yml
![[Pasted image 20240404093943.png]]
Q11. Observe the status of the pod and the logs.
![[Pasted image 20240404094024.png]]
![[Pasted image 20240404094110.png]]
Q12. Create a job using job.yml and notice the job, pod, and the logs.
![[Pasted image 20240404094209.png]]
![[Pasted image 20240404094154.png]]

Q13. Create a cronjob using cronjob.yml and notice the job, pod and the logs.
![[Pasted image 20240404095044.png]]
Q14. Go to [this tutorial](https://kubernetes.io/docs/tutorials/stateful-application/basic-stateful-set/)

Mainly show the following points:

1. How to create a StatefulSet
using a `volumeClaimTemplate` to provision persistent storage for each pod in the StatefulSet
```yaml
apiVersion: v1
kind: Service
metadata:
  name: nginx
  labels:
    app: nginx
spec:
  ports:
  - port: 80
    name: web
  clusterIP: None
  selector:
    app: nginx
---
apiVersion: apps/v1
kind: StatefulSet
metadata:
  name: web
spec:
  serviceName: "nginx"
  replicas: 2
  selector:
    matchLabels:
      app: nginx
  template:
    metadata:
      labels:
        app: nginx
    spec:
      containers:
      - name: nginx
        image: registry.k8s.io/nginx-slim:0.8
        ports:
        - containerPort: 80
          name: web
        volumeMounts:
        - name: www
          mountPath: /usr/share/nginx/html
  volumeClaimTemplates:
  - metadata:
      name: www
    spec:
      accessModes: [ "ReadWriteOnce" ]
      resources:
        requests:
          storage: 1Gi
```
3. How a StatefulSet manages its Pods
A StatefulSet is responsible for managing the deployment and scaling of a set of Pods, and ensuring that each Pod is uniquely identifiable and maintains its identity across restarts. Each Pod in a StatefulSet has a stable network identity and stable storage.
5. How to delete a StatefulSet
```bash
kubectl delete statefulset <name>
```
7. How to scale a StatefulSet
```bash
kubectl scale statefulset web --replicas=5
```