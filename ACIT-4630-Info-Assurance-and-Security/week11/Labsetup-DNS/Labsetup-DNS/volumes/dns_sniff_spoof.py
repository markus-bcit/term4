#!/bin/env python3

from scapy.all import *

def spoof_dns(pkt):
 
  pkt.show()
  '''
  #qd is the question domain in the DNS layer
  if (DNS in pkt and 'www.bcit.ca' in pkt[DNS].qd.qname.decode('utf-8')):
  
    # To get access to each layer from the sniffed packet you can use pkt[layer_name], e.g. pkt[IP] give you access to the IP layer 
    sniffed_ip  = 
    sniffed_udp = 
    sniffed_dns = 

    #create a new IP object
    ip  = IP (dst = ,  src = )

    #create a new UDP object
    udp = UDP(dport = , sport = )

    #create a new DNS Answer Record to include in the DNS object
    # qd is the question record
    # enter the fake IP in the rdata field
    Anssec = DNSRR( rrname = sniffed_dns.qd.qname, 
                    rdata  = '',
                    ttl    = 259200)

    #create a new DNS object
    #A DNS reply has to have the same id as the query to be accepted
    #aa=1: authoritative answer
    #qr flag: 0 (question) or (1) answer?
    #qdcount: # of question records
    #qd: same question domain as the sniffed packet is used in the new DNS object
    #ancount: # of answer records
    #an: answer record
    
    dns = DNS( id = , aa=1, qr=, 
               qdcount=1, qd = ,                   
               ancount=1, an = Anssec )

    spoofpkt = ip/udp/dns
    send(spoofpkt)
    spoofpkt.show()
    '''
    


pkt=sniff(iface='', filter='', prn=spoof_dns)

