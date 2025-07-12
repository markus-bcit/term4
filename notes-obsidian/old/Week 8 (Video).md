# Data Link Control
Recall that the **data-link layer** is divided into two sublayers: **data link control** (DLC) and **media access control** (MAC)

**DLC** deals with procedures for communication between two adjacent nodes, ie **node-to-node communication**, regardless whether the link is point-to-point or broadcast. DLC **functions** include **framing** and **flow and error control**
## Framing
The data-link layer **pack bits** into **frames**, so that each frame is **distinguishable** from another. Framing (**fixed-size** or **variable-size**) separates messages from one source to a destination by adding a sender address and a destination address. The destination address defines where the packet is to go and the sender address helps recipient acknowledge the receipt.

In **variable-size framing**, the **end** of one frame and the **beginning** of the next **frame** needs to be **defined**. We look at **character-oriented** framing and **bit-oriented** framing

### Character Oriented framing
Data is to be carried is 8-bit characters from a coding system such as ASCII. To be **separate** one frame from the next, an 8-bit (1 character) **flag** composed of protocol-dependant special characters is added at the beginning and the end ** of a frame to signal the start or end of a **frame**.
![[Pasted image 20250303213617.png]]
Character-oriented framing was popular when only **text** was exchanged by the data-link layers. However, for information types such as **audio or video**, **any character** used for the **flag** could also be part of the **information**.
### Byte Stuffing and Unstuffing
A **byte-stuffing** (or character-stuffing) strategy was added to character-oriented framing: a **special character** (e.g., ESC) is **added** to the **data portion** of the frame when there is a **character** with the **same pattern** as the **flag**. Whenever the **receiver encounters** the **special character**, it **removes** it from the data portion and treats the **next character as data**.
![[Pasted image 20250303214040.png]]
#### A frame in a bit-oriented protocol
However, universal coding systems, such as **Unicode** have 16-bit and 32-bit characters that **conflict** with **8-bit characters** used in byte-stuffing, hence, the tendency is moving toward **bit-oriented framing**.
### Bit oriented framing
In bit-oriented framing, the **data** section of a frame is a **sequence of bits**. Most protocols use a special 8-bit pattern **flag** such as **0111 1110** as a **delimiter** to define the beginning and the end of the frame
![[Pasted image 20250303221504.png]]
to **prevent** the issue where the **flag** pattern also **appears** in the **data**, bit stuffingn **adds a single bit to the data** to prevent the data from looking like a flag, 
eg if delimiter  **0111 1110** is used an extra 0 is added whenever five consecutive 1s follow a 0 in the data. 
![[Pasted image 20250303221623.png]]
## Data-Link Layer Protocols
The behaviour of a data-link layer protocol can be shown as a finite state machine (FSM)
### Stop-and-Wait Protocol
A DLC protocol that uses both flow wand error control is called the **Stop and Wait** protocol.

In this protocol, the sender sends **one frame at a time** and **waits for an acknowledgement** before **sending the next one**. To **detect corrupted frames**, a **CRC** is added to each data frame. Every time the sender **sends a frame**, it starts a **timer**:

if an **acknowledgement** arrives before the timer expires, it **sends the next frame** (if it has one to send).

If the **timer expires**, the sender **resends the previous frame** assuming the frame was either lost or corrupted
![[Pasted image 20250303222012.png]]
![[Pasted image 20250303222025.png]]![[Pasted image 20250303222025 1.png]]
# Media Access Control
## Random Access
In random-access or contention methods, no station is **superior** to another station and **none is assigned control** over another. At each instance, a **station** that ahs **data to send** uses a **procedure** defined by the protocol to make a **decision** on whether or not to send. This decision may depend on whether the **state of the medium** is idle or busy.

Two features give this methods its name:
1. **Transmission is random** among the stations and
2. **stations compete** with one another to the access the medium
### CSMA
To **minimize** the change of **collision** and, therefore increase the performance, the CSMA method was developed. The change of collision can be reduced if a station **senses the medium before trying to use it**. Carrier sense multiple access (CSMA) requires that each station **first listen** ot the medium (or check the state of the medium) before sending

>In other words, CSMA is based on the principle "sense before transmit" or "listen before talk."

CSMA can **reduce** the **possibility of collision**, but it **cannot eliminate** it. The possibility of collision still exists because of **propagation delay**: when a station sends a frame, it still takes time for the **first bit** to **reach every station** and for **every station to sense it**.
![[Pasted image 20250303230920.png]]
#### Vulnerable time
The **vulnerable time** for CSMA is the maximum **propagation time**, $T_{p}$, the time needed for a signal to propagate from one end of the medium to the other. When a station sends a frame and any other station tires to send a frame during this time, a collision will result. However, if the **first bit of the frame reaches the end of the medium, ever station will have heard the bit** and will **refrain from sending**.
![[Pasted image 20250303231146.png]]
### CSMA/CD
The **CSMA** method **does not specify** the **procedure following a collision**. Carrier sense multiple access with collision detection (**CSMA/CD**) **augments the algorithm** to **handle the collision**.

In this method, a station **monitors the medium** after it sends a frame **to see if the transmission was successful**. If it was **successful**, the station is **done**. If, however, there was a **collision**, the frame is **sent again**.
![[Pasted image 20250303231345.png]]
In CSMA/CD a station monitors the medium after it sends a frame to see if the transmission was successful. Lets look at the **first bits transmitted** by the two stations **involved in the collision**: 
![[Pasted image 20250303231440.png]]

Note that on retransmission A and C will probably collide again.
### CSMA/CA
Carrier sense multiple access with collision avoidance (CSMA/CA) was invented for **wireless networks**. Collisions are avoided through the use of CSMA/CA's three strategies: the **interframe space (IFS),** the **contention window** and **acknowledgments** along the **Ready to Sends (RTS)** and **Clear to Send (CTS)**:

Interframe Space: **Collisions are avoided by deferring transmission even if the channel is idle.** It waits for IFS period of time as the channel may appear idle even though a **distant station** may have started transmission.

Content Window: A station that is ready to send chooses a **random** (binary exponential) number of slots as its wait time.

![[Pasted image 20250303232041.png]]

Acknowledgment: The use of positive acknowledgment and time-out timers helps guarantee that the receiver has received the frame.
![[Pasted image 20250303232127.png]]
## Virtual LANs
A **station** is considered part of a **local area network** (LAN) if it **physically** belongs to that LAN. The criterion of memberships is **geographic**.
![[Pasted image 20250303232814.png]]
What would happen if the administrator needed to **move** two **stations** from **Group 1 to Group 3**?

A **virtual local area network** (VLAN) is a local area network **configured by software**, not by physcial wiring
![[Pasted image 20250303232946.png]]
These figures show the **same switched LAN** divided into **VLANs**. The **idea of VLAN** technology is to divide a **LAN** into **logical**, **instead of physical**, segments.
Each VLAN is a **work group** in the organization and **any station can be **logically moved** to another VLAN.
## Memberships
What **characteristic** can be used to **group stations** together in a **VLAN**?

#### Interface Numbers:
Some VLANS vendors use **switch interface numbers** as membership characteristics.
(eg. stations connection to ports 1 and e belong to VLAN 1; stations connecting to ports 4 and 10 belong to VLAN2)
#### MAC Addresses
Some VLAN vendors use 48-bit **MAC addresses** as a membership characteristic.
#### Combination
Some VLAN vendors allow all these **characteristics** to be **combined**.
### Advantages
There are several **advantages** to using VLAN
#### Cost and Time Reduction 
VLANs can **reduce** the **migration cost** of station going from one group to another.
(Physical reconfiguration takes time and is costly, it is much easier and quicker ot move it by software)
#### Creating Virtual Work Groups
VLANs can be used to **create virtual work groups**. 
(eg. in a campus environment, individuals working on the same project can send broadcast messages to one another without the necessity of belonging to the same department)
#### Security
VLANs provide an extra measure of **security**. 
(Individuals belonging to the same group can send broadcast messages with the assurance that users in other groups will not receive these messages)

# Introduction to Network Layer
## Network-Layer Services
Before discussing the network layer inteh Internet today
The Network layer services 3 things
#### Packetizing
**encapsulating the payload** (data received from upper layer) in a network-layer packet at the source and **decapsulating the payload** from the network-layer packet at the destination. Note that the network layer carries a payload form the **source to the destination without changing or using** it.

#### Routing
There is **more than one route** from the **source to the destination**. The network layer is responsible for **applying strategies and running routing protocols** to find the **best one** among these possible routes and **create routing tables** for each router.
#### Forwarding
Forwarding is the **action applied** by each router when **a packet arrives** at one of its **interfaces**, ie to **forward the packet** to **another** (unicast) or **some** (multicast) attached network(s).
![[Pasted image 20250303233919.png]]
## Packet Switching
From the discussion of routing and forwarding, we infer that a kind of switching occurs at the network layer.

A **router**, in fact, is a **switch** that **creates a connection** between an **input port** and an **output port** (or a set of output ports), just as a an electrical switch connects the input to the output to let electricity flow.
![[Pasted image 20250303234027.png]]
## IPv4 Addresses
The **identifier** used in the **network layer** of the TCP/IP protocol suite to identify the connection of each device to the Internet is called the Internet Address or **IP address**. An IPv4 address is a **32-bit address** that **uniquely and universally** defines the **connection** of a host or a router to the Internet.

The IP address is the address of the **connection**, **not the host or the router.**
### Address Space
A protocol like IPv4 that defines addresses has an **address space**.
An address space is the **total number of addresses used by the protocol**. IPv4 uses **32-bit addresses**, which means the that the space is $2^{32}$. If there was no restrictions, more than 4 billion devices could be connected to the Internet. A 32-bit IPv4 address can be notated using **binary, dotted decimal, and hexadecimal**.
A 32-bit IPv4 address is **hierarchical** and **divided into two parts**: the first part of the address is called the **prefix** (fixed- or variable lenght) and **defines the network**; the second part of the address is called the **suffix** and **defines the connection to the node**. 
![[Pasted image 20250303234537.png]]
### Classless Addressing (CIDR)
![[Pasted image 20250303234550.png]]![[Pasted image 20250303234653.png]]