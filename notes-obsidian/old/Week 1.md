# Introduction
Chi En Huang
> Program Head, Curriculum Option Head, AIML
> SW02-125
Email: ChiEn_Huang@bcit.ca
Phone: 604-453-4008

4 hours a week
Course Description:
Understand the basic **concepts** and **terminologies** related to **data communications**, **networking** and **network topologies**

Overview of the **TCP/IP protocol suite** and the principles of protocols at **physical, data link, network** and **transport** layers
Final 35%
Each week Quiz 35%
4 assignments 30%
## Packets

TCP = Connection Oriented
UDP = Best Effort
## OSI Layers
### Physical
This layer is responsible for the physical transmission of raw data bits over a communication medium like cables (Ethernet), fiber optic, or radio waves(Wi-Fi). It defines hardware specifications, including voltage levels, timing, and connector types, ensuring data is sent as electrical signals or light pulses
### Data Link
This layer provides reliable data transfer over the physical link by organizing raw bits into **frames**. It manages error detection, flow control, and MAC addressing (e.g Ethernet and Wi-Fi Protocols). It ensures that data packets are delivered to the correct device on a local network.
### Network
The network layer handles logical addressing (IP addresses) and routing, determining how data is forwarded between devices across different networks. It uses protocols like IP (IPv4 and IPv6) to route packets to their destination, even across multiple interconnected networks.
### Transport
This layer ensures end-to-end communication, data integrity and, reliability between devices. Protocols like TCP manage segmentation, reassembly, and retransmission of data if error occur. UDP provides faster, connectionless communication for time-sensitive applications.
### Application 
The application layer interacts directly with the user, enabling network-based applications like web browsing (HTTP), email (SMTP), and file transfers (FTP). It ensures the communication is meaningful and correctly interpreted by the users or software.

## Data Communications
>When we communicate, we are **<u>sharing information</u>. This <u>sharing can be local or remote.</u> The term <u>telecommunication</u>, which includes telephony, telegraph, and television <u>means communication at distance</u>

Data Communications is exchange of data between two devices via some form of transmission media.


## Components
Simplex
Half-duplex
Full-duplex
## Networks
A <u>network is the interconnection of a set of decices capable of communication</u>
In this definition a device can be a host such as a large computer, desktop, laptop, workstation, ceullular phone, or security system. A device in this definition can also be a <u>connecting devices</u> such as a router, a switch, a modem that changes the form of data, and so on.
### Network Criteria
**Performance** 
	 Often evaluated by 
	 1. throughput
	 2. Delay
**Reliability**
	Often measured by
1. Frequency of failure
2. the time it takes to recover from a failure
3. The network's robustness in a catastrophe
**Security**
1. Protecting data from unauthorized access and from damage
2. Implementing policies and procedures for recovery from breaches and data losses.

### Types of connection
#### Point-to-point
![[Pasted image 20250111135939.png]]
#### Multipoint
![[Pasted image 20250111135947.png]]
## Topology
### Mesh
![[Pasted image 20250111140023.png]]
Fully connected p2p between all nodes
A mesh topology with n nodes requires $n(n-1)/2$ full-duplex links

Pros:
- Dedicated Links
- Robust
- Privacy and Security
- Easy fault identification and isolation
Cons:
- Amount of cabling and number of I/O ports required
### Star 
![[Pasted image 20250111140054.png]]
Every Node has a p2p link to a central controller (hub)
Pros:
- Cost
- Robust
- Easy Fault Identification and Isolation
Cons:
- Single point of failure

### Bus
![[Pasted image 20250111140103.png]]
Pros:
- Ease of installation
- Less cabling than either mesh or star topologies
Cons:
- Single point of failure- backbone cable.
- Difficult fault isolation
### Ring
![[Pasted image 20250111140110.png]]
Pros:
- Easy to install and reconfigure
- Simplified fault identification and isolation
Cons:
- Single point of failure
# Network Models
Analog = Sine Wave
Digital = On/Off
![[Pasted image 20250111144039.png]]
## Protocol Layering
A protocol defines the rule that both the sender and receiver and all intermediate devices need to follow to be able to communicate effectively.
When communication is simple, we may need only one simple protocol; when the communication is complex, we need a protocol at each layer, or protocol layering
## Layered Architecture
To Show how the layers in the TCP/IP protocol suite are involved in communication between two hosts, we use the TCP/IP protocol suite in a small internet made up of three LANs (links), each with link-layer switch. we also assume that the links are connected by one router.![[Pasted image 20250111144658.png]]
![[Pasted image 20250111144707.png]]
Note there is a distinction when transfering through the router it is because the destination can be using a different medium of sending information
## Principles of Protocol Layering
<u>Two Principles</u> of protocol Layering:

The **first principle** dictates that if we want **bidirectional communication**, we need to make **each layer** such that it is able to perform two opposite tasks, one in each direction
The **second principle** that we need to follow in protocol layering is that the **two objects under each layer at both sites should be identical.**
![[Pasted image 20250111144840.png]]
#### Encapsulation and Decapsulation
An important concept in protocol layering is <u>encapsulation/decapsulation</u>
![[Pasted image 20250111145638.png]]
#### Addressing![[Pasted image 20250111145659.png]]


Note* 
![[Pasted image 20250118120055.png]]Hop to hop mean it can change between layers (ethernet to wifi)
Note that end-to-end mean the packet doesn't change throughout the entire traversal
