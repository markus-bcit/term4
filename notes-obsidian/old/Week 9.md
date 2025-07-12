# Unicast Routing
## Introduction
Unicast routing in the Internet, with a large number of routers and a huge number of hosts, can be done only by using **hierarchical routing** routing in **several steps** using **different routing algorithms**. 

In unicast routing, a **packet** is routed, **hop by hop**, from its **source** to its **destination** with the use of **forwarding tables**. 

To find the best route, an internet can be **modeled** as a **graph**. A graph is a **set of nodes and edges** that connect the nodes. TO model an internet as a graph, we can represent each **router** as a **node** and each **network** between a pair of routers as an **edge**.

In fact, an internet can be modeled as a **weighted graph**, in which **each edge** is **associated** with a **cost**. If there is no edge between the nodes, the cost is infinity.

## Least-Cost Routing
![[Pasted image 20250314195219.png]]
One of the ways to determine  the **best route** from the source router to the destination router is to find the **least cost** between the two in the **weighted graph** reprensentation.

In other words, the **source router** chooses a **route** to the **destination router** in such a way that the **total cost** for the route is **least cost among all possible routes**.

### Least-cost trees
A **least-cost tree** is a tree with the **source router as teh root** that spans the whole grpah (visits all other nodes) and in which the **path between** the **root** and **any other node** is the **shortest**. Note if there are N routers in an internet, there are N least-cost trees (one shortes-path tree for each node.
![[Pasted image 20250314195440.png]])
## Routing Algorithms
Several routing algorithms have been designed in teh past. The differences between these methods are in the way they **interpret** the **least cost** and the way they **create** the **least-cost tree** for each node.

## Distance-Vector Routing
In distance-vector routing, the first thing **each node** creates is its own **least-cost tree** with the **rudimentary information** it has about its **immediate neighbors**. The **incomplete trees** are **exchanged** between **immediate neighbors** to make the trees **more and more complete** and to represent the whole internet.

In distance-vector routing, a **router** continuously **tells** all of its **neighbours** what it knows about the **whole internet** (although the knowledge can be incomplete).

### Bellman-Ford equation
At the heart of distance vector routing is the **Bellman-Ford equation**. This equation is used to ifnd the **least cost** between a **source node**, x, and a **destination node**, y, through some **intermediary nodes** (a,b,c, ...) where the **costs between the source and the intermediary nodes** and the **least costs between the intermediary nodes and the destination** are given.

The following shows the general case in which $D_{ij}$ is the **shortest distance** and $c_{ij}$ is the **cost between nodes i and j**
![[Pasted image 20250314200415.png]]

![[Pasted image 20250314200527.png]]
![[Pasted image 20250314200536.png]]
![[Pasted image 20250314200551.png]]
## Link-state routing
In link-state routing, the term **link-state** is used to define the **characteristic of a link** (an edge) that represents a network in the internet.
In this algorithm, the cost associated with an edge defines the state of the link. **Links** with **lower costs** are preferred to links with higher costs; if the **cost** of a link is **infinity**, it means that the link **does not exist** or has been **broken**. 

In link-state routing, each **router tells** the **whole internet** what it knows about its neighbours.

To create a **least-cost tree**, each node needs to have a complete map of the network. The **collection of states** for **all links** is called the **link-state database (LSDB)**, represented as a two-dimensional array (matrix). There is only **one LSDB** for the **whole internet;** each node needs to have a duplicate of it to be able to create the least-cost tree.
![[Pasted image 20250314203705.png]]

The LSDB is created by a process called **flooding**. Each node requests and collects two pieces of information in a link-state packet (LSP) from its immediate neighboring nodes: the **identity of the node** and the **cost of the link**. When a node receives a LSP on one of its interfaces, it compares it with the copy it may already have. If it's newer,  it **keeps the newer copy** and then **sends it out to each of its interfaces except the one from which the LSP arrived**. After receiving all new LSPs each node creates the **comprehensive LSDB**
![[Pasted image 20250314203902.png]]


### Least-Cost Tree
To create the **least-cost tree** for itself, each node needs to run the iterative **Dijkstra's algorithm:**
1. The node chooses itself as the root of the tree, creating a tree with a single node, and sets the total cost of each node based on the information in the LSDB
2. The node selects one node, among all nodes not in the tree, which is closest to the root, and adds this into the tree. After this node is added to the tree, the cost of all other nodes not in the tree needs to be updated
3. The node repeats step 2 until all nodes are added to the tree.
![[Pasted image 20250314203915.png]]
# Transport-Layer Protocol
The transport layer is located between the application layer and the network layer. It provides **process-to-process communication** between two application layers, one at the local host and the other at the remote host.
Communication is provided using a **logical connection**
## Services
The transport layer is located between the network layer and the application layer. It is responsible for **providing services** to the **application layer** and **receives services** from the **network layer**.

- Process-to-Process Communication:
	As opposed to host-to-host communication in the network-layer a **process** is an application-layer entity (running program).
- Encapsulation and Decapsulation
	 Process sends message to the transport layer and the sender adds the **transport-layer header** (encapsulation). Packets at the transport layer are called **user datagrams/segments**. Decapsulation happens at the receiver.
- Flow Control
	**balance** between **production** and **consumption** rates.
- Error Control
	the transport layer is responsible for
		**detecting and discarding corrupted packets**
		Keeping track f lost and discarded packets and rending them,
		recognizing duplicate packets and discarding them and 
		buffering out-of-order packets until missing packets arrive.
- Congestion Control
	 Implements **mechanisms** and techniques to keep the load below the capacity
## UDP

UDP (User Datagram Protocol) is a **connectionless, unreliable** transport protocol. However, UDP is a very **simple** and **efficient** protocol using a minimum of overhead.

UDP packets, called user datagrams, have a **fixed-size header** of **8 bytes** made of four fields, each of 2 bytes. the first two fields define the source and destination port numbers, the third field defines the total length of the user datagram, header plus data. The last field can carry the **optional** checksum.

![[Pasted image 20250314210844.png]]
## TCP

TCP (Transmission Control Protocol) is a **connection-oriented**, **reliable** protocol

TCP, unlike UDP, is a **stream-oriented** protocol. It allows the sending process to deliver **data** as a **stream of bytes** and allows the receiving process to obtain data as a stream of bytes. TCP creates an environment in which the two processes seems to be connected by an imaginary tube that carries their bytes across the Internet.
![[Pasted image 20250314211006.png]]

Lets describe the serves offered by TCP protocol (connection-oriented, reliable, full-duplex) to the processes at the application layer.

![[Pasted image 20250314211132.png]]
### TCP Features
To provide the services, TCP **keeps track of** the **segments** being transmitted or received (for flow and error control) using two fields: **sequence number** and the **acknowledgment number.** The bytes of data being transmitted in each connection are numbered by TCP. Numbering is **independent**  in each direction (for full-duplex communication).

Sequence Number: TCP assigns a sequence number to each segment that is being sent. The sequence number of the **first segment** is the **initial sequence number** (ISN) and is an arbitrarily generated random number of \[0, $2^{32-1}$]. The sequence of **any other segment** is the **sequence number** of the previous segment **plus** the **number of bytes** carried by the **previous segment** i.e., first byte of data in the segment. 

Acknowledgement number: the value of the acknowledgement number in a segment defines the **number of the next byte** a **party expects to receive**. The acknowledgement numbering is **cumulative**.

### Segment
A packet in TCP is called a **segment**.
![[Pasted image 20250314212325.png]]
### TCP Connection
TCP is connection-oriented. All of the segments belonging to a message are then sent over this **logical path.** Using a single logical pathway for the entire message **facilitates** the **acknowledgement** process as well as **retransmission** of damaged or lost frames. 

In TCP, connection-oriented transmission requires 3 phases:
- connection establishment
![[Pasted image 20250314212016.png]]
- data trasnfer
![[Pasted image 20250314212026.png]]
- connection termination
![[Pasted image 20250314212047.png]]

half close
![[Pasted image 20250314212104.png]]

Time-line diagram
![[Pasted image 20250314212113.png]]