# Week 1

#outline 

| Type | % | Desc. |
| --- | --- | --- |
| Quizzes | 20 | A quiz at the beginning of each class, including the midterm review quiz. | 
| Labs and Assignments | 35 | Labs may be done with a partner. | 
| Presentation | 10 | Group | 
| Final Exam | 35 |  | 
- Passing Criteria::
	- 50% overall in the course
	- Students must complete a minimum of 80% of the Labs.

Assurance #assurance
CIA Triad #ciatriad

![[Pasted image 20240109085510.png]]

Opposing forces #opposingforces

![[Pasted image 20240109085610.png]]
# week 2

#vulnerability 
- Server 
- Endpoint 
- Supply chain 
- Configuration 
- Architectural 

Vulnerabilities on a server #vulnerability 
- Outdated software / unsupported OS 
- Buffer Overflow Vulnerabilities 
- Privilege Escalation Threats 
- Insecure Protocols (e.g., FTP, Telnet, POP3) 
- Servers configured for debugging modes

Endpoint vulnerabilities #vulnerability 

> Weaknesses associated with individual devices connected to a network.

- Like servers but with stricter configuration 
- Common issues:  
	- Missing Patches and Outdated Signatures 
	- User Reluctance to Update Software

Configuration #vulnerability 

|  |  |
| ---- | ---- |
| Avoid | default configurations |
| Verify | device security before network integration |
| Follow | documented security standards and best practices |
| Choose | secure cryptographic protocols and strong ciphers |
| Apply | the principle of least privilege |

STRIDE #stride

| Property | Threat | Definition |
| ---- | ---- | ---- |
| Authentication | **S**poofing | Impersonating something or someone else. |
| Integrity  | **T**ampering | Modifying data or code |
| Non-repudiation   | **R**epudiation | Claiming to have not performed an action. |
| Confidentiality | **I**nformation Disclosure | Exposing information to someone not authorized to see it |
| Availability | **D**enial of Service | Deny or degrade service to users |
| Authorization | **E**levation of Privilege | Gain capabilities without proper authorization |
Data Flow Diagram

![[Pasted image 20240116093157.png]]

Vulnerability Management

![[Pasted image 20240116093228.png]]

Standards #standards
- Security Content Automation Protocol (SCAP)
- [CVE](https://cve.mitre.org/) and [NVD](https://nvd.nist.gov/) databases
- Common Vulnerability Scoring System [CVSS](https://nvd.nist.gov/vuln-metrics/cvss)
	- ![[Pasted image 20240116093417.png]]
-   

of 18

                     Automatic Zoom                     Actual Size                     Page Fit                     Page Width                                          50%                     75%                     100%                     125%                     150%                     200%                     300%                     400%                   

1  
Information Assurance and  
Security – ACIT 4630  
Hesam Alizadeh  
Week 3 – Winter 2024

3  
▪ CVSS calculation  
▪ Malware types and prevention  
▪ Social engineering attacks’ success  
▪ Zero-day vulnerabilities importance  
▪ Advanced Persistent Threats  
▪ Stuxnet malware attack characteristics  
Learning Outcomes

4  
▪ Imagine you received the following brief description  
of a vulnerability in your system:  
“This vulnerability allow a remote unauthenticated user to execute  
arbitrary code on the target system, potentially gaining access to  
system components in the context of the current user”  
▪ Analyze this vulnerability and apply CVSS 3.1 assessment  
methodology to generate a base score and a vector string:  
▪ Common Vulnerability Scoring System Version 3.1 Calculator (first.org)  
CVSS calculation

[](https://www.first.org/cvss/calculator/3.1 "https://www.first.org/cvss/calculator/3.1")

5  
▪ Virus: Spreads by attaching to  
legitimate programs.  
▪ Worm: Self-replicates and  
spreads independently.  
▪ Trojan: Disguises itself as a  
legitimate program.  
▪ Remote Access Trojan (RAT)  
Malwares propagation  
Image Source: Differences Between Viruses, Worms and Trojans

[](https://www.baeldung.com/cs/virus-vs-worm-vs-trojan "https://www.baeldung.com/cs/virus-vs-worm-vs-trojan")

6  
Malware Payloads  
Spyware: gathers  
user's information Adware: displays  
unwanted advertisements  
Ransomware: encrypts  
user's data for ransom  
3 steps to prevent and recover from ransomware

[](https://www.microsoft.com/en-us/security/blog/2021/09/07/3-steps-to-prevent-and-recover-from-ransomware/ "https://www.microsoft.com/en-us/security/blog/2021/09/07/3-steps-to-prevent-and-recover-from-ransomware/")

7  
Logic Bombs  
Image source: Logic bombs

[](https://www.baeldung.com/cs/logic-bombs "https://www.baeldung.com/cs/logic-bombs")

