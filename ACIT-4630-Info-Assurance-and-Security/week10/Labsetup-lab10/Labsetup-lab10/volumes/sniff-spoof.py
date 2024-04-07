#!/usr/bin/env python3
from scapy.all import *
def spoof_pkt(pkt):
	pkt.show()
	ip = IP()
	# To get info for each layer from the sniffed packet you can use pkt[layer_name], e.g. pkt[IP] give you access to the IP layer 
	ip.dst = 
	ip.src =
	icmp = ICMP()
	icmp.type = '' 	
	# id and seq number has to match with the original request for the spoofed reply to be accepted
	icmp.id = pkt[ICMP].id
	icmp.seq = pkt[ICMP].seq
	# if the original icmp request has data it needs to be included in the reply
	if pkt.haslayer(Raw):
		data = pkt[Raw].load
		newpkt = ip/icmp/data
	else:
		newpkt = ip/icmp
	send(newpkt)
pkt = sniff(iface='', filter='', prn=spoof_pkt)

