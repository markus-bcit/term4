# Switching
A network is a set of connected devices.
Whenever we have multiple devices, we have the problem of how to connect them to make one-to-one communication possible. The solution is switching.

A switched network consists of a series fo interlinked nodes called switches. Switches are devices capable of creating temporary connections between two or more devices linked to the switch.
![[Pasted image 20250215131159.png]]
## Three Methods of Switching
Traditionally, there are three methods of switching:
![[Pasted image 20250215131300.png]]
- Circuit Switching
- Packet Switching
	- Virtual Circuit Approach
	- Datagram Approach
- Message Switching
## Circuit-Switched Networked
A circuit-switched network consists of a set of switches connected by physical links, in which each link is divided in to n channels.
A connection between two stations is a dedicated path made of one or more links.
Each connection uses a dedicated channel o n each link. Each link is normally divided into n channels by using FDM or TDM
![[Pasted image 20250215131619.png]]
### Three Phases
The actual communication in a circuit-switched network requires three phases:
1. Connection setup
Before the entities can communicate, a dedicated circuit needs to be established. Note that end-to-end addressing (eg., telephone numbers) is required for creating a connectoin between the two and systems.
2. Data Transfer 
After the establishment of the dedicated circuit the two entities can transfer data.
1. Connection Teardown
2. When one of the entities needs to disconnect a signal is sent to each switch to release the resources
### Efficiency
It can be argued that circuit-switched networks are not as efficient as packet- or message- switched networks since resources are allocated for the entire duration of the connection; and unavailable to other connections. Let's consider the following 2 scenarios for comparison;
 - In a **telephone** network, people **normally terminate** the communication when they have finished their conversation.
 - In a **computer** network, a computer **can remain connected** to another computer even if there is no activity for a long time -> other connections are deprived.
 ![[Pasted image 20250215132203.png]]
## Packet-Switching
In data communications, we need to send messages from on end system to another. If the message is going to pass through a packet-switched network the message needs to be divided into packets of fixed or variable size (size of the packet is determined by the network and the governing protocol).

In packet switching, there is no resource reservation for a packet: **no reserved bandwidth** on the links, **no scheduled processing time** for each packet. **resources are allocated on -demand** on a **first-come, first servers** (FCFS) basis.

### Datagram Networks
We have two types of packet-switched networks: 
- **datagram networks**
- **virtual-circuit networks**

In a datagram network, each packet is treated independently of all others. Even if a packet is part of a multipacket transmission, the network treats it as though it existed alone. Packets in the this approach are referred to as datagrams.

Datagrams switching is normally done at the network layer
![[Pasted image 20250215133052.png]]
![[Pasted image 20250215135145.png]]
![[Pasted image 20250215135133.png]]
### Virtual-Circuit Networks
A virtual-circuit network is a cross between a circuit-switched network and a datagram network. It has some characteristics of both:
	1. There are **setup and teardown** phases in addition to the **data transfer phase** (circuit-switched)
	2. **Resources** can be **allocated** during the **setup** phase (circuit-switched) or **on-demand** (datagram)
	3. Data are **packetized** (datagram) but address in header only has **local jurisdiction**, ie, only knows next switch/channel, not end-to-end jurisdiction
	4. All **packets** follow the same path established during the connection (circuit-switched)
	5. Normally implemented in **data-link** layer. (Physical Layer; Circuit-switched; Network Layer: Datagram)
	![[Pasted image 20250215135519.png]]

# Overall Delays
### Delay in circuit-switched network
$\text{Total Delay} = \text{Setup time} + \text{Data Transfer Time} + \text{Teardown time}$
### Delay in datagram network
$\text{Total Delay}_{\text{Packet 1}} = 3 * \text{Transmission time} + 3 * \text{Propagation time} + 2*\text{Waiting Time}$
### Delay in a Virtual-Circuit Network
$\text{Total Delay} = \text{Setup Time} + 3 * \text{Transmission time} + 3 * \text{Propagation time} + \text{Teardown time}$


# Introduction to Data-Link Layer
The Internet is a combination of **networks** glued together by **connecting devices** (routers or switches)
If a **packet** is to travel from a **host to another host**, it needs to **pass through** these networks.
### Nodes and links
Communication at the data-link layer is **node-to-node**. A data unit from one point in the Internet needs to pass through many networks (LANs and WANs) to reach another point. These LANs and WANs are connected by routers.
It is customary to refer to the end hosts and the routers as noted and the networks in between as links.
### Services
The **data-link layer** is located between the **physical** and the **network** layers. Services provided by the data-link layer include:

**Framing** -  **Encapsulate** the **packet** received from the **network** in a **frame** before sending it to the next node. **Decapsulate** the packet from the frame received on the logical channel. **Different data-link layers have different formats for framing.**

**Flow Control** - If the **rate of produced frames** is **higher** than the **rate of processed frames**, frames at the receiving end need to **buffered** while waiting to be processed.
**Error Control** - **Frames are susceptible to error** in part due to electromagnetic signals being susceptible to error. There **error** needs to **detected** and then either **corrected** or **discarded and retransmitted** by the sending node.
**Congestion Control** - Some wide-area networks may use congestion control when a **link is congested wit frames.** Mainly handled by **network** and **transport layers.**
### Two Categories of Links
While two nodes are physically connected by a transmission medium such as cable or air, the data-link layer **controls** how the **medium is used.** A data-link layer can use:
- The **whole capacity** of the medium
	- the link is dedicated to the two device
	- point-to-point link
- Only part of the capacity of the medium
	- The link is shared between several pairs of devices
	- broadcast link
### Two Sublayers
To better understand the functionality of and the services provided by hte  link layer, the data-link layer is divided into two sublayers: **data link control** (DLC) and **media access control** (MAC)
![[Pasted image 20250215143234.png]]
## Link-Layer Addressing
	In a connectionless internetwork such as the internet, a packet cannot reach its destination using only IP addresses. The source and destination IP addresses define the two ends but does not define which links the packet should pass through. 

Each packet in the internet from the same source host to the same destination host, may take a different path.
### Address Resolution Protocol
When a node has an IP packet to send to another node in a link, it has the IP address of the receiving node. However, as discussed, the IP address of the receiving node is not helpful in moving a frame through a link. The link-layer address of the next node is required. 

The Address Resolution Protocol (ARP), an auxiliary protocol defined in the network layer, accepts an IP address from the IP protocol, maps the IP address to the corresponding link-layer address and passes the link-layer address to the data=link layer.
![[Pasted image 20250215143719.png]]