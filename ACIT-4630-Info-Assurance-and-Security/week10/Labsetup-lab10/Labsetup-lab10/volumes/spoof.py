#!/usr/bin/env python3
from scapy.all import *

#creating a new IP object
ip = IP() 
ip.src= ''
ip.dst = ''  
# creating a new ICMP object
icmp = ICMP() 
icmp.type = 'echo-request'
# layer stacking: add the ICMP packet as the payload of the IP packet
newpkt = ip/icmp 
send(newpkt)
