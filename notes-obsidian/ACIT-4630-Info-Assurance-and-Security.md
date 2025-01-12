# Week 1

#outline 

| Type                 | %   | Desc.                                                                     |     |
| -------------------- | --- | ------------------------------------------------------------------------- | --- |
| Quizzes              | 20  | A quiz at the beginning of each class, including the midterm review quiz. |     |
| Labs and Assignments | 35  | Labs may be done with a partner.                                          |     |
| Presentation         | 10  | Group                                                                     |     |
| Final Exam           | 35  |                                                                           |     |
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

Final Notes

**Week 1 Review:**

●       Ideal security is done but not seen

●       CIA Triad:

○       Confidentiality: keep the data private

○       Integrity: keep the data safe accurate and untampered

○       Availability: keep the data accessible to those who need it

●       Risk assessments:

![](file:///C:/Users/Markus/AppData/Local/Packages/oice_16_974fa576_32c1d314_110/AC/Temp/msohtmlclip1/01/clip_image002.gif)

●       A vulnerability that poses a threat is a risk

●       Treat modelling:

○       STRIDE:

■        Spoofing:

●       Sending data from a different source

■       Tampering

■       Repudiation:

●       Proof that you sent something or the lack thereof

■       Information disclosure

■       Denial of service

■       Elevation of privilege

●       Our Linux distros:

○       Kali:

■       Common for pen testing

■       Often used in combination with metasploitable

■       Typically runs as a vm on virtual box

○       Metasploit:

■       Metasploitable is deliberately exploitable and can be used for testing and learning about cybersecurity

●       Nmap:

○       Base Syntax:

■       nmap [scan type] [options] {target(s)}

○       Target Specifications:

■       IPv4 addresses: example 10.01.0.1

■       IPv6 addresses: BP:HAAI:2PDS:2

■       Hostname: www.name.com

■       IP address range: 10.0.2-255.0-255

■       CIDR block: 192.168.0.0/16

■       Use file with lists of targets: -il <file name>

○       Target Ports:

■       No port range specified will scan 1000 most popular ports

■       -F: scan 100 most popular ports

■       -P<port1>-<port2>: will take a port range

■       -P<port1>,<port2>: will take a port list

■       -pU:53,U:110,T20-445: Mix TCP and UDP

■       -r: Scan linearly (do not randomize ports)

■       --top-ports <n>: scan n most popular ports

■       -p-65535: Leaving off initial port makes Nmap scan start at port 1

■       -p0: leaving off end port makes Nmap scan up to port 65535

■       -p leaving off start and end port makes Nmap scan ports 1-65535

○       Probing Options:

■       -Pn: Don’t Prode (assume all hosts are up)

■       -PB: Default probe (TCP 80, 445 & ICMP)

■       -PS<portlist>: Check whether targets are up by probing TCP ports

■       -PE: Use ICMP Echo Request

■       -PP: Use ICMP Timestamp Request

■       -PM: Use ICMP netmask Request

○       Scan Types:

■       -sn: Probe only (Host discovery, not port scan)

■       -sS: SYN Scan

■       -sT: TCP Connect Scan

■       -sU: UDP Scan

■       -sV: Version Scan

■       -O: os Detection

■       --scanflag: set custom list of TCP using URGACKPSHRSTSYNFIN in any order

○       Aggregate Timing Options:

■       -T0: Paranoid - very slow used for IDS evasion

■       -T1: Sneaky - Quite slow used for IDS evasion

■       -T2: Polite - Slows down to consume less bandwidth runs 10 times slower than default

■       -T3: Normal - Default, a dynamic timing model based on target responsiveness

■       -T4: Aggressive - Assumes a fast and reliable network and may overwhelm targets

■       -T5: Insane: Very aggressive will likely overwhelm targets or miss open ports

○       Output Formats:

■       -oN: standard Nmap output

■       -oG: Greppable format

■       -oX: XML format

■       -oA <basename>: Generate Nmap, Greppable and XML output files using basename for files

○       Misc Options:

■       -n: Disable reverse IP address lookups

■       -6: Use IPv6 only

■       -A: Use several features, including OS detection, Version Detection, Script Scanning (default), and traceroute

■       --reason: display reason Nmap thinks port is open closed or filtered

**Week 2 Review:**

●       CIA Triad for security considerations:

○       Confidentiality:

■       Protects information and systems from unauthorized access

■       Keeps security away from prying eyes

■       The act of attacking this side is called a disclosure attack

■       **Disclosure attacks** seek to undermine confidentiality without the owner's consent

■       We use access controls and encryption to protect confidentiality

○       Integrity:

■       Protect the information and systems from unauthorized modifications

■       **Alteration attacks** seek to undermine integrity

■       There could also be accidental service interruptions or issues that cause integrity concerns

○       Availability:

■       Ensures that information and systems are available for authorized users when needed

■       If users can’t access what they need it can hurt the company

■       Attacks on this side are known as denial of service attacks

■       **Denial of service** (DOS) attacks seek to cause a system to crash or be overwhelmed so that standard users no longer have access

●       Steganography is hiding information in usually places that can’t be seen with the naked eye

●       As a security professional we must consider the needs of the business as well as the need for improved security at all times

○       Security professionals must understand the mission, goals, and objectives of the broader company

●       Justify new security in the following contexts:

○       The money and time investment for the company

○       Balance the security and business concerns

○       Present how it will help meet the CIA goals

●       Administration is also commonly done by system admins and applies to business contexts:

○       Create a budget

○       Conduct performance reviews

○       Council employees

○       Contribute to the planning processes

Different types of attacks:

●       External vs Internal:

○       Internal is less considered but more dangerous

●       Script kiddies:

○       These are the lowest level of attacks

○       They typically reuse hacking tools developed by others

○       Not very sophisticated

○       Easy to patch and set up systems to protect against

●       Hacktivists:

○       Seek to use hacking for a political or social agenda

○       May have lower or high talents

○       Motivated by activist things (not money like a lot of the others)

●       Organized crime:

○       Usually motivated by money

○       Often ransomware attacks or other harmful exploits

○       Not only limited to cyber companies

●       Nation-state (APT):

○       The most advanced and resource-heavy group of attackers

○       Often have access to the most sophisticated technology and personal

○       APT or advanced persistent threat groups

○       Often have military training and motivation

○       May go after companies that have government interest or other governments

●       The hats:

○       White hat:

■       Do good things with the permissions of the target and with good intent

○       Grey hat:

■       Operate illegally but with good intent to help others improve security

■       Frowned upon despite trying to do good

○       Black hat:

■       Operate illegally and with malicious intent

Risk assessment:

●       Based on impact and likelihood

○       The likelihood of a risk is the probability it will occur

○       The impact of the risk is the damage it could do

●       Threats:

○       An external force

○       Puts the system at risk

○       May be natural like an earthquake or man-made like a DOS

○       The threat vector is the method that the attacker used to get to the target

■       Could be a phishing email or a physical server access

●       Risks:

○       When a threat and vulnerability are present

○       Threats will only exist if a vulnerability is not maintained

○       Likeliness is a big factor in assesing these risks

●       Vulnerabilities:

○       Weaknesses in security controls

○       Often out of date software or something like poor firewall rules

○       Can and should be controlled by you

●       Qualitative Risk Assessment

○       Uses subjective ratings of low, medium, and high to estimate

○       Example:

![](file:///C:/Users/Markus/AppData/Local/Packages/oice_16_974fa576_32c1d314_110/AC/Temp/msohtmlclip1/01/clip_image004.gif)

●       Qualitative Risk assessment:

○       Uses objective numerical ratings

●       Security controls:

○       Based on the risk assessment results

○       A set of procedures and mechanisms that an organization puts in place to manage risks

○       Can reduce the likelihood or the impact, or detect potential risks

○       More than one control is best

○       Defence in-depth principle: the act of overlapping controls

●       Categories of controls:

○       Detect:

■       Find security issues that have taken place

■       Example: Monitoring traffic for malicious users

○       Prevent:

■       Stop issues from happening in the first place

■       Example: A firewall

○       Correct:

■       Remediates security issues that have happened

■       Example: Restoring from a backup

●       Mechanism of actions:

○       Technical:

■       Use of technology to achieve security control objectives

■       Maybe anti-virus software or data firewalls

■       Remember that operational controls are carried out by people

■       Technical controls are done by technology automatically

○       Management:

■       Focused on the mechanics of risk management process

■       Considers what needs to be assessed and what might be missed

○       Operational:

■       Controls human-driven processes to manage technology

■       Such as user access systems and manual log monitoring

●       Ways a control can fail:

○       False positive errors:

■       Tiggers an issue when none is present

■       This may cause people to ignore important error in the future

○       False negative eros:

■       Fails to report an issue

Identifying threats/vulnerabilities:

●       Use threat monitoring techniques

●       Asset focused approach:

○       Look at all assets and consider the threats to each

●       Threat focused approach:

○       Consider each threat and what it might do

○       Look at if from the eyes of the attacker

●       Service focused approach:

○       Identify the impact of various threats on a specific service

○       Important for companies that sell digital services

●       STRIDE model of categorizing attacks (week 1)

●       Reduction analysis:

○       Break the system down into parts and perform assessments for each

○       Good for larger systems

●       Total attack surface:

○       The services that could present potential points of entry for an attacker

○       Reading the complexity of a system will limit the attack surface risk potential

●       Attack vector:

○       The means that attack will use to gain access to the system

○       Examples: an SQL injection, an SSH connection

●       Common server issues:

○       Unpatched servers

○       Buffer overflow

○       Heap overflow (a type of buffer overflow in the heap)

○       Privilege escalation

○       Insecure protocols

○       Debugging mode (maybe outputting sensitive in

○       formation)

●       Common endpoint issues:

○       These are user machines (often employees laptops and such)

○       May also need system updates/patches

○       Users may try to install their own software which can come with viruses

●       Supply chain vulnerabilities:

○       Staying current with patches is important if using third-party software

○       End of life is a big deal

■       End of sale:

●       Can no longer buy the product, the end is nigh

●       Still supported

■       End of support:

●       May be the end of all support or just minor support ending

●       Should be considered a bad sign

■       End of life:

●       No vendor support

○       Vendors can struggle to provide support in general before these points

○       You may not be able to fix the issues they introduce to your system so be careful

●       Configuration vulnerabilities:

○       Using template configurations that do not reflect security concerns can be an issue

○       Default configurations for security tools may not check your system properly

○       Cryptographic Protocol Vulnerabilities:

■       Weak cipher suites

■       Weak cryptographic protocol implementations

■       Poor key management

○       Patch Management:

■       OS patches

■       Application updates

■       Firmware

○       Account management:

■       Accounts may have too high privileges - follow the principle of least privilege

●       Architectural vulnerabilities:

○       Should design the architecture to incorporate security early

○       Adding it later can result in poor security with vulnerabilities

○       Users and staff are often big security risks that we need to consider - sometimes they do dumb things :/

○       System sprawl:

■       As the system grows more risks will be introduced

■       More risky if the system is undocumented

Vulnerability scan engine:

●       Vulnerability scan engineers consider:

○       Commercial software

○       NVD: National vulnerability Database

○       CVE: Common Vulnerabilities and Exposures

●       Scans can check a single computer, a group of them, or even a whole network

○       This may include things like printers or TVs as well

●       There are two levels of security scans:

○       Unauthenticated scans:

■       Have no system access

■       Good for getting an outside view of the system vulnerabilities

○       Authenticated scans:

■       Allows it to run with access to the system

■       They have local admin rights and can look at files

■       Considers:

●       Administrator rights

●       Installed applications

●       Configuration files

■       Often more in-depth

●       Can be generic or consider things like PSI compliance

●       Timing is important as it can slow down the system to run a security check

●       When looking at the results of a scan, consider:

○       Vulnerability severity

○       System criticality

○       Information sensitivity

○       Remediation difficulty

○       System exposure

●       It is ok to ignore false positives but try to confirm they are false positives first

●       Types of outcomes

○       If the scanner reports a finding and it does exist it is a true positive

○       If the scanner reports a finding and it does not exist it is a false positive

○       If the scanner does not exist and it is not reported then yay, true negative

○       The scariest one of all is if a vulnerability does exist and it is not reported which would be a false negative

●       It is not possible to fix every vulnerability all the time so prioritize

**Week 3 review:**

CVSS:

●       Common vulnerability scoring system

●       Uses a 10 point scale and 8 different metrics

●       Attack Vector (AV) metric:

○       This defines the type of access the attacker must have to exploit a vulnerability

○       This can be:

■       Physical (P): physical touch or manipulation required

■       Local (L): physical or local console access is required

■       Adjacent Network (A): Local network access required

■       Network (N): Remotely exploitable over the internet - BAD :(

●       Attack complexity (AC) metric:

○       This defines the difficult of exploiting the vulnerability

○       High (H): Requires specialized conditions to exploit

○       Low (L): does not require specialized conditions to utilize the exploit

●       Privileges Required (PR)

○       This metric considers what user-level access the attacker must have

○       Levels:

■       High (H): requires administrative control

■       Low (L): requires basic user privileges

■       None (N): requires no prior privileges

●       User Interaction (UI):

○       This metric specifies the level of human interaction needed

○       Levels:

■       Required (R): requires that an authorized user take some sort of action

■       None (N): can be carried out by the attacker alone

●       These metrics (AV, AC, PR, and UI) combine to describe the exploitability of a vulnerability

●       We also need to consider the CIA triad to incorporate the impact into the risk analysis

○       (C) Confidentiality:

■       None (N): No confidentiality impact

■       Low (L): Access to some information possible

■       High (H): All information would be compromised

○       (I) Integrity:

■       None (N): No integrity impact

■       Low (L): Some integrity could be impacted

■       High (H): All information is compromised

○       (A) Accessibility:

■       None (N): No availability impact

■       Low (L): Performance would be degraded

■       High (H): System would shut down and be unusable

●       These three metrics describe the impact of a vulnerability

●       The 8th metric Scope (S):

○       Captures whether a vulnerability in one system would have an impact on another

○       The levels are:

■       Changed (C): Exploiting the vulnerability can affect other components

■       Unchanged (U): Exploiting the vulnerability only affects resources managed by the same security authority

Malware:

●       Every malware has two components:

○       A propagation mechanism (how it spreads)

○       A payload (what it does)

■       Adware:

●       instead of generating money for the content owner, it generates money for the malware distributor

●       It might try to change the default search engine

●       Display pop-up advertisements

●       Replace the legitimate ads with other ads that benefit the adware distributor

●       This is more of an issue for the person who is trying to show legitimate ads rather than the end user

■       Spyware:

●       Spyware gathers information and reports it back to the malware author

●       Can be used for identity thief or security compromization

●       Might log keystrokes for usernames and passwords

●       May monitor web browsing

●       Search hard drives and cloud storage for private information

■       Ransomware:

●       Blocks user's access to the data

●       Often involves encrypting all of the user's data and then ransoming off the encryption key to get it back

●       Should you pay?

○       Over 40% of those who are infected pay

○       Malware authors have been paid millions to date

■       Scareware:

●       This acts like ransomware but is a bluff

●       This offers to sell them a solution to fix a fake issue with security on the computer

●       Viruses:

○       These take their name from natural viruses

○       They spread through human action

○       This might be opening a link or inserting a compromised USB drive

○       Education is important for stopping them

●       Worms:

○       Spead by themselves

○       They reach out to other computers often on a network and spread from device to device

○       They have been around for a while

○       It is important to keep things up to date and patch networks

■       The first major worm outbreak was in 1988

■       The RTM work spread rapidly due to poor network security

○       Stuxnet:

■       Created in 2010

■       An APT worm that Infected an Iranian nuclear plant

■       The first worm to cross the virtual/physical boundary

●       Trojans:

○       spread through the installation of what appears to be beneficial software

○       These appear to be one thing but are actually malicious

○       When they run they perform as expected but have a hidden payload

○       Application control is used to limit the software that runs on a computer

○       RATs (Remote access Trojans):

■       They provide hackers with the ability to remotely access infected computers

●       How to prevent Malware:

○       Anti-malware

○       Applying security patches and updates regularly

○       Education

●       Backdoors:

○       Malware is an independent program written by a developer to deliver a malicious payload

○       Some malware may not be an independent program but rather a malicious code piece that is added to another application

○       A backdoor occurs when someone wants to provide a workaround to access a system

○       They might be simply making it easier to get into the system

○       However, they may fall into the wrong hands or be injected maliciously

○       This can occur for many different reasons

○       Backdoor Mechanisms:

■       Hardcoded accounts

■       Default passwords that users do not remember to change

■       Unknown access channels

○       Accidental backdoors are common and bad

●       Logic bombs:

○       Set to execute a payload when certain conditions are met

■       This might be a certain date or time

■       A file containing certain information

■       An API call

○       These date back to early computing (Friday the 13th bomb)

Advance Malware:

●       Rootkits:

○       The ultimate goal of most hackers is root access

○       Rootkits were (originally) a tool that escalates normal user privileges to root

○       However, this term has changed over the years

○       It is now used to define software techniques that are used to hide other software on the system

○       They deliver a variety of payloads:

■       Backdoors

■       Botnet agents

■       adware/spyware

○       Rootkits are not always malicious and some are used as anti-theif mechanisms for copyrighted content

●       Ring protection mode:

○       Most programs run with only an outer layer user access mode:

![](file:///C:/Users/Markus/AppData/Local/Packages/oice_16_974fa576_32c1d314_110/AC/Temp/msohtmlclip1/01/clip_image006.gif)

○       The OS runs with kernel mode access

 ![](file:///C:/Users/Markus/AppData/Local/Packages/oice_16_974fa576_32c1d314_110/AC/Temp/msohtmlclip1/01/clip_image008.gif)

○       Rootkits can run in either of these modes:

■       Usermode rootkits:

●       Run with normal user privileges

●       Are easy to write and difficult to detect

■       Kernal mode rootkits:

●       Hard to write

●       Easy to detect

●       Have a lot of advanced abilities

●       Polymorphic Viruses:

○       Viruses that change to avoid detection

○       Most anti-virus software looks for known virus patterns

○       Polymorphic virus techniques change their signatures consistently

○       They do this usually through encryption

■       They encrypt themselves with a different key on each infected system

■       This means the file will look completely different

■       The virus loader then has the encryption key on each infected system

●       Armored Viruses:

○       When viruses use polymorphism they need to be picked apart and analyzed for a way to be protected from

○       Armour viruses prevent reverse engineering by implementing techniques that are more low-level

■       Such as writing the virus in obfuscated assembly language

■       Blocking the use of system debuggers

■       Reducing the ability to be sandboxed

Botnets:

●       Botnets are a group of compromised computers that can be used for malicious purposes

●       A network of infected zombies controlled by a botmaster

●       Computers will need to be infected by some sort of malware typically

●       Most hackers will rent out the computing power to others

●       These other individuals may use them to:

○       Deliver span

○       Engaging in DDos attacks

○       Mine bitcoin

○       Perform password brute force attacks

●       Any situation where computing, storage, or network is valuable

●       How to command and control the botnet:

○       Uses command and control networks

○       You can not talk directly to the infected device or security professionals would be able to sever those connections

○       Communication must be indirect and redundant to a network to hide your involvement

○       This can be done with:

■       Internet Relay Chat (IRC)

■       Twitter

■       Peer to peer with the actual botnet

○       It needs to be built with redundancy because most security analysts will shut down the communication channels

●       Botnet steps:

○       The hacker starts by infecting systems with malware

○       The infected systems are converted to bots that the hacker can exploit the resources of

○       These bots may spread the infection to other devices

○       These bots form a network and reach out to a command and control network point

○       These bots get instructions

○       These bots then deliver their payload

Malware Prevention:

●       Antimalware software can protect against malware using techniques such as:

○       Signature detections

■       Watches the known patterns of malware

■       Needs to be kept up to date with known malware patterns

○       Behavior Detection

■       Reports when a system is not behaving normally

○       Endpoint detection and response (EDR)

■       These are advanced tools

■       Gather deep endpoint information on a lower level

■       They offer advanced real-time protection on endpoint devices

■       Can trigger automated defences

○       Sandboxing:

■       Isolates malicious content

■       Will scan the software in an isolated environment and see if it performs maliciously

Impersonation/Email attacks:

●       Spam: unsolicited commercial email (UCE)

●       phishing attacks:

○       Typically sent in the form of an email

○       Lets the attacker get control of the user’s account

○       Credential harvesting

■       your password and username may work on other systems

■       Hackers can then get into your bank account with your Facebook credentials for example

○       Spear Phishing:

■       Uses a targeted attack with known user information

■       Invoice sent to a company, that are not real but hoping to be paid

○       Whaling:

■       Targeted attacks on executives

■       An attempt to get the good stuff from a senior representative

■       One example is a legal-looking email that has a fraudulent link

○       Pharming:

■       These are like fishing but go to greater lengths to seem legitimate

■       The attacker sets up a fake website that looks like the real one

■       Copies the look and feel of the fake site

■       Takes the results of usernames and passwords entered in the site

○       Vishing:

■       Voice phishing

■       Calling people as a help desk agent asking for the users information

○       Smishing and SPIM:

■       SMS and IM span

■       Started via AOL but now are more of a texting feature

○       Spoofing:

■       Faking the identity of the sender

Attack Vectors:

●       Attack Vectors: the method the attacker uses

●       Email:

○       One of the most common attack vectors

○       Will often be done on mass in hopes of getting access to the larger system

●       Social media:

○       May spread malware online

○       Could be done over an influence campaign

●       Removable media:

○       Attackers may leave inexpensive USB drives in public in order to compromise and spread a virus

○       These attacks can also be spread through charging chips

●       Card skimmers:

○       Used to read magnetic stripes which may be used in card cloning attacks

●       Cloud services:

○       Attackers will scan for security flaws and check for security issues

●       Network Connections:

○       Accessing a network from the inside out through the building

○       Don’t let attackers touch anything

●       Tampering with devices in the supply chain allows attackers to insert backdoors

●       Wireless networks allow attackers to remotely attack an organization

○       Can sit in the parking lot and connect to the system

Protecting virtual machines:

●       VMs are still at risk

●       Reduce the attack surface

○       Stop unnecessary services

■       Avoid nonpersistent disks

■       Remove unnecessary devices

■       Disable VMware tools auto-install

■       Create a secure template so all new VMs have proper security

●       Protect your VMs with antivirus

○       vShield Endpoint - supported on vSphere 6

○       Offload virus scanning to the ESXi host

Cloud Computing threats:

●       Cloud computing is generally secure but you need to do a lot of work for it as well

●       Cloud services can use public internet accessibility

○       There should be reduced access

●       There needs to be encryption for network communion

○       This is often not the default so it should be enabled

●       There is an ease of self-service so both attackers and developers can create new resources that the company has to pay for

●       Deletions and data remnants:

○       There may be specific remnants of data that need to be deleted

●       On-premises breaches for hybrid configurations

○       One user can compromise the whole system

●       Social engineering and malware

○       Social engineering is the tricking of people into devolving critical information

●       Single points of failure

○       No replication or backups

○       Make sure you make your own backups and replication, even storing them yourself if needed

●       Lack of IT personnel training

○       IT professionals need to know the security best practices

●       Lack of periodic vulnerability and penetration testing

●       You need centralized monitoring and alerting

Zero-day exploits:

●       Come before there is even a known issue

●       There is no patch against them

●       Be ethical when you discover a vulnerability

○       Notify the vendor

○       Provide the vendor with a reasonable amount of time to create a patch

○       Don’t disclose the vulnerability publicly until after the organization has had time to respond

○       DON’T exploit the vulnerability yourself (however much you want to :)

●       What if the vulnerability is kept a secret?

○       This is known as a zero-day vulnerability

○       This is a powerful weapon

○       It can be used and may not even be detected yet

●       Window of Vulnerability:

○       The time between the discovery of a zero-day vulnerability and the release of the security patch that blocks it

○       Finding a zero-day is difficult

○       Most little script kiddys won’t know about them

APTs:

●       Advanced Persistent Threats (APTs)

●       Highly skilled and well-funded hackers

●       Typically government-sponsored

●       Usually associated with the military

○       Directed at political and military targets

●       Have access to zero days and other sophisticated weapons

●       Have targets

●       Defending against APTs is difficult

○       Build a strong security foundation

○       Implementing strong encryption

○       Set up good monitoring

●       Characteristics:

○       Customized code to the target

○       They are designed with a target in mind

○       Often used zero-day or multi-threat capabilities

○       Are usually done by humans (not fully automated)

○       Have a low and slow style to remain unnoticed

●       APT objectives:

○       Against the state:

■       Espionage

■       Sabotage

■       Disrute other countries

●       Anatomy of APT malware:

○       APT will implant malware silently

○       They have the following anatomy to do this:

■       Command and control

■       Process injection

■       Cloaking system

■       Exfiltration:

●       Used to send the information it collects back to the attackers

●       Should use encryption and normal network behaviour to send these out

■       Resignation:

●       The APT malware needs to restart when the system loads

●       This will often have multiple means of re-igniting

●       Stuxnet is also one that was designed to target the Iranian nuclear plant

○       It had multiple zero-day exploits contained inside of it for windows computers

○       It took advantage of the Siemens industrial plant system

**Week 4 Review:**

Code execution attacks:

●       occur when an attacker exploits a vulnerability in the system that allows the attacker to run commands on that system

●       is normally done through openings on the internet

●       most webservers have 80 and 443 open, but sometimes attackers can get in through these or open new server ports

●       Arbitrary code execution:

○       Code execution attacks where the attacker runs commands of his or her choice

●       Remote code execution:

○       Code execution attacks that take place over a network connection

●       Code Execution Objective:

○       Some of the actions an attacker might perform once they have access are:

■       Installing malicious code

■       Joining the system to a botnet

■       Stealing sensitive information

■       Creating accounts for later access to the system

●       To protect against these:

○       Limit administrative access

■       Set the principle of least privilege to externally accessed systems like a database

■       Patch systems and applications

Identifying and classifying incidents:

●       A security event:

○       Any activity that takes place on a system, network, or application that may have security implications

○       There is no requirement that this sort of even be malicious or dangerous to the system

○       If the user attempts to log in that is a security event

■       Even if it was authentic

○       If a firewall accepts or denies a request - that is a security event

○       If a user accesses anything on the server - yet a security event

○       Every organization experiences thousands of these things every day

●       Adverse Security Events:

○       Any specific event that has a negative consequence for the organization

○       a user logging into someone else’s account is an adverse security event

○       These might include infection by malware, a loss of data, maybe system data being compromised

●       Security Incident:

○       Any adverse security event that either caused or threatened to cause a violation of the organization's security policies

○       If an attacker gets say a passcode and provides it to a competitor that is a security incident

○       It needs to not only be a malicious thing but a thing that hurt the organization

○       Some adverse advents may not rise to the level of a security incident

○       If someone creates a botnet to attack your server then there might not even be a security incident as long as you can stabilize everything and deal with it

●       Nested definitions:

![](file:///C:/Users/Markus/AppData/Local/Packages/oice_16_974fa576_32c1d314_110/AC/Temp/msohtmlclip1/01/clip_image010.gif)

●       Security incidents are those that actually cause issues - so we mostly only care about them

●       Just because an adverse event does not rise to the level of a security incident, does not mean it is not dangerous or should not be dealt with though

Incident response programs:

●       There is an official publication called NIST that outlines a response plan

●       Incident Response Plan:

○       Provides structure during cybersecurity incidents

○       Provides policies, procedures, and guidelines for what to do when things happen

●       Things to include in an Incident Response Plan

○       Statment of purpose

○       Strategies and goals for incident response

○       Approach to incident response

○       Should cover communication with other groups (such as the team and affected parties)

○       Should be approved by senior leadership for the authority levels

●       Not all plans are the same for every organization

Incident Identification:

●       You have the responsibility to monitor the system for crucial to effective incident identification

○       Collect analyze and retain this information

●       Indecent data sources:

○       Intrusion Detection and Prevention Systems (IDS/IPS)

○       Firewalls

○       Authentication systems

○       Integrity monitors

○       Vulnerability scanners

○       System event logs

○       NetFlow records

○       Antimalware packages

●       Its systems tend to generate massive amounts of log information from these sources

●       Security professionals are in charge of going through this information and identifying the security incidents

●       This would normally be hard but there are Security Incident and Event Management (SIEM) to help

○       A security solution that collects information from diverse sources, analyzes it for signs of security incidents, and retains it for later use

○       Can use rules and algorithms to filter out the unimportant stuff

●       There are certain first responder activities

○       The highest priority is to cut off the system and isolate it!!

○       Just as in a medical emergency, the first responders can make a difference

○       If they notice something then they should isolate the system

○       They may quarantine the system by removing it from the network

■       This is nice as it keeps it running and preserves the evidence of the incident but also cuts it off from the attack

●       Often times people might be spying on you as well

●       Counterintelligence hinders adversaries' abilities to gather intelligence

○       Feed them misinformation

○       Deny them access

Security and data sources:

●       Security Events:

○       Intrusion Detection Systems

○       Endpoint Security (antivirus, antimalware)

○       Data loss Prevention

○       VPN Concentrators

○       Web Filters

○       Honeypots

○       Firewalls

●       Network logs:

○       Routers

○       Switches

○       DNS Servers

○       Wireless Access Points

○       WAN

○       Data Transfers

○       Private Cloud Networks (VPC)

●       Applications and Devices:

○       Application servers

○       Databases

○       Intranet Applications

○       Web Applications

○       SaaS Applications

○       Cloud-Hosted Servers

○       End-User Laptops or Desktops

○       Mobile Devices

●       IT Infrastructure:

○       Configuration

○       Locations

○       Owners

○       Network Maps

○       Vulnerability Reports

○       Software Inventory

Montiroing log files:

●       Security controls that administrators can put in place to prevent vulnerabilities:

○       Log monitoring:

■       This is usually pretty dull

■       The newest member often has to do this :)

■       They often contain critical information about what has already taken place

○       You can access windows logs with a tool called event viewer

●       On a linux server go into /var/log

○       This contains many of the same logs

○       For example, the messages file contains similar stuff to the system log on Windows such as DHCP information

○       Secure contains security information

○       httpd file contains system logs from apache

●       Reporting automation:

○       Can be used to set alarms when certain events occur

○       These might not be compromised situations but just important events

○       You might also use it to set up trend analysis to point out unusual activity on the system

Correlating security and event information:

●       Systems generate far too many long records for a manual analysis

●       Security information and event management (SIEM)

●       We often us AI to read out logs

●       SIEMS have two purposes:

○       Central, Secure collection point for logs:

■       All systems send log entries directly to the SIEM

○       Source of artificial intelligence ai

■       SIEMs detect patterns that other systems might miss

●       SIEMs have access to all of the log entries from across the organization

●       SIEMs put all the information together for an organization and its many systems

●       SIEMS come for the manufacture with a large set of predefined rules

○       These rules cover common issues

○       But they will not be able to go very deep into your system so you will need to customize it

○       Rule modification:

■       Delete or disable predefined rules that do not fit your situation

■       Or change things like ports or expected load data

○       Rule writing

■       Add your own rules to target unique parts of your applications

●       SIEMs provide real-time monitoring dashboards so that we can see all of the information at once

Syslog:

●       System monitoring creates a whole lotta data

●       There are tools that let us automate this work

●       Syslog:

○       Provides a logging standard

○       Dates back to the 80s but is still in practice today

○       Syslog is composed of messages that contain 4 components:

■       Header:

●       Timestamp

●       Source (IP and Process IP for the log)

■       Facility:

●       A 24 bit code that describes where the message came from

●       0 = kernel

●       1 = user level

●       2 = mail service

●       Source of message on the sending system

■       Severity:

●       Importance value from 0 to 7

○       0: emergency

○       1: Alert

○       2: Critical

○       3: Error

○       4: Warning

○       5: Notice

○       6: Informational

○       7: Debug

○       Has a descending order of severity

○       It’s common to use severity as filters

■       Such as send a notification if a 0-3 is found

○       Linux supports syslog natively

○       Third party tools, such as a Kiwi syslog

○       Windows systems do not support it by default but Kiwi can be used in its place

○       SIEMs serve as Syslog message repositories

■       Message:

●       The details of the situation

●       Has text

●       Common SIEM Tools:

○       ArcSight

○       QRadar

○       Splunk

Querying logs:

●       Sometimes you will need to search through those logs

●       There are a lot of different ways to write queries against logs:

○       SIEM interface

■       They often allow you to have an interface to parse through the data

○       Structured Query Language:

■       SQL can be used for these

○       Scripts

■       You can write a script on the command line that does processing for you

■       May vary by operating system

■       Example with Linux:

●       Use **grep**

●       Takes a string and the name of the file

●       Use **grep wp-admin access_log**

●       This will show lines that have the first input (wp-admin) and the file (access_log)

■       We can also use the output redirection for grep and store it to a file with **>**

■       Pipe can also be used to pass one command to another

●       Example grep thing file | wc -l

Determining Incident Severity:

●       To triage these incidents we need to assess their severity levels

●       Think about the Confidentiality, Integrity, and Availability triad

●       Data Classification Guides Severity

○       Look out for PII (personal identifiable information)

○       Protected health information (PHI)

○       Sensitive personal information (SPI)

■       Gender

■       Sexual orientation

■       Union membership

○       Payment card information (PCI) data

○       Other high-value assets

■       Such as insider trading style information

●       Incident Severity:

○       When considering Integrity think about the damage that unauthorized changes could do and where they may come from

○       Availability Can also play a role in assessing the severity of the impact

■       Consider what would happen if your servers all crashed :0

●       Apply consistent criteria

○       This will help you know what resources to use and how to respond

●       Consider the following:

○       Will the incident cause downtime?

■       If so how much time will it take to recover?

○       Will the incident cause a breach of integrity?

○       Will there be economic damage?

●       Is the affected system critical?

Mitigation:

●       As the team assembles they move from first responder mode to a damage control mode

●       They perform a full range of incident containment activities

●       The nature of the activities will vary

●       Containment strategy evaluation:

○       Look at the potential for damage

○       Evidence preservation

○       Service availability

○       Resource required to implement the strategy

○       Expected effectiveness

○       The solution timeframe

●       The goal is to balance and select the one that balances the business need and the security concerns

●        Once an organization implements the actions - be aware that the attacker may notice them being pushed back

○       They may start acting hostile at this stage

○       Mitigation ends with stability

■       Business functioning without danger

■       At the end of the containment process the organization should be a semi-stable state

■       Everything is generally ok at the end of this stage

●       Then move on to recovery and reconstitution

Containment techniques:

●       The first minutes and hours of a security incident are the most important

●       At this point steps taken matter the most

●       The more work done in the preparation phase the better the containment and eradication will be

![](file:///C:/Users/Markus/AppData/Local/Packages/oice_16_974fa576_32c1d314_110/AC/Temp/msohtmlclip1/01/clip_image012.gif)

●       The difference between the early phases and this one is that it moves from passive checks to action

●       We need to prioritize containing the actor

○       We need to consider the confidentiality, integrity, and availability of the system

●       Techniques to limit the damage:

○       Segmentation:

■       A common security technique

■       Used to divide networks into logical segments and group users based on them

■       If one or more systems are compromised cut them off from the others

■       Make a quarantine zone and isolate the systems there

○       Isolation:

■       Next level segmentation

■       Instead of just moving them to a new network you isolate the system

■       May still be able to talk to other things on the network

■       And may still be on the internet

○       Removal

■       Completely remove them from the internet altogether

■       Will alert the attacker but means they can’t cause any more damage

●       When responding use professional judgment and consider the larger business

Incident eradication and recovery:

●       Eradication:

○       Secure accounts and compromised data

○       Go through the network and check everything

●       Recovery:

○       Restore normal business operations

●       Even though they are described as two separate things they are hard to distinguish most of the time

●       Its is hard to tell what might have happened in the attack

●       May have to go back to factory settings

○       It sucks but it will fix everything

○       Consider what needs to be changed so that the issues doe s no happen again

○       Make sure you patch any vulnerabilities:

●       Fixing a fresh system:

○       Set up application white and blacklisting

○       Have quarantine technologies

○       Put effort into strengthening access controls

■       Don’t let the same thing happen again

●       Examine improvements to security rules

○       Firewall rules

○       Mobile device management (MDM)

○       Data loss prevention (DLP)

○       URL and content filtering

○       Update or revoke digital certificates

●       Sanitization and secure disposal prevent confidential information leaking:

○       Sanitation techniques:

■       Clearing:

●       Overwrite sensitive information to frustrated causal analysis

■       Purging:

●       Uses more advanced techniques to frustrate laboratory analysis

■       Destroying:

●       Completely obliterate the media through shredding, melting, burning

●       Just obliterate it

Validation:

●       Eradication and recovery is hard

●       We need to validate it before claiming the issue is solved

●       Validation process:

○       Verify the secure configuration of every system

○       Run a vulnerability scan

○       Perform account and permission reviews

■       Make sure no back door accounts exist or permissions are off

○       Verify that the systems are logging and communicating security information to the SIEM

■       Make sure information is hitting the SIEM correctly

●       Validate that the system is in the same state as before

●       Move on to post-incident activities after this

Backups:

●       Backups are probably the most important things when it comes to disaster recovery

●       Data is extremely important for the business

●       Backups:

○       Provide a fail-safe way to backup safely data

○       They are critical

●       Ways of doing it:

○       Traditionally done on taps

○       Disk-to-disk backups

■       Uses special backup disks

■       Use cloud computing backups

■       Cloud providers usually store backups

●       There are 3 primary types:

○       Full backups:

■       have a complete copy of the system and the data

■       Snapshots and images are types of full backups

○       Differential backups store only what has changed since the last backup

■       These do not stand alone and require a past full backup

○       Incremental backups:

■       Include all data modified since the last full or incremental backup

●       Scenario:

○       A full backup every week

○       A differential backup every weekday

■       Now if something happens we can restore the full backup, and then add the differential backup for the previous day

○       However, if the incremental backup was used then it would have to apply the full backup and then every single incremental backup since then

○        Tales a longer time to restore this data but the data stored is often smaller

●       Best practices:

○       Label your data:

■       Everyone should know what it is and what it does

■       Add a date

○       Integrity:

■       Make sure that everything on the backup is working and not corrupted

■       Most utilities do this for you

○       Testing:

■       Try to do a restore and make sure it works

■       Pretend you have a disaster and do the recovery

○       Tape rotation and retention:

■       Avoid doing it randomly

■       Do it often - have a system

■       Have a monthly weekly and daily backup at least

■       Store more

■       Grandfather = monthly, father = weekly, and son = daily

Executing attacks:

●       Bind shell:

○       Say we are attacking a target with an attacking host

■       Going for port 6667

○       Here we do the exploit and send something to this payload

○       This payload is what is used to open the port and then be able to access some better port to get into the system:

■       Say some shell port like 51742 and connecting to the shell

○       A firewall will block this type of port attack

■       Even if the target has an open port the firewall can still stop us

●       Reverse style shell:

○       We upload the payload and instead of opening the port, the target connects back to us

○       We encrypt this connection

■       Seeing that a shell is being connected will be flagged

●       Brute forcing:

○       Used to cycle through combinations in a range of characters to get in without knowing the password

Logging:

●       Logging laws:

○       Law of collections:

■       Do not collect/generate log data that you never plan to use

○       Law of retention:

■       Retain log data for as long as it is conceivable that it can be used - or longer if prescribed by regulations

○       Law of Monitoring:

■       Log all you can (which is as much as possible), but alert only on what you must respond (which is as little as possible)

○       Law of availability:

■       Don’t pay to make your logging or monitoring system more available than your business systems

○       Law of security:

■       Don’t pay to make your logging or monitoring system more available than your business systems

○       Laws of constant changes:

■       Logs sources log types and log message change

●       Log tampering:

○       Malicious users can tamper with logs

○       Event viewer on Windows shows details of each event including an Event ID

■       From this list look up some Event IDs that might indicate log-tempering

○       MITRE ATT&CK

■       A knowledge base of adversary tactics and techniques based on real-world observations

■       ATT&CK is a website that shows a bunch of attacks on the system

**Week 5 review:**

Encryption:

●       Protects information an authorization disclosure

●        Works in many situations

●       Cryptogrophy depends on two basic operations:

○       Encryption

■       Converts plain text to ciphertext

○       Decryption

■       Converts ciphertext messages back into plaintext

●       Uses algorithms to compute

●       Encryption algorithms take two parameters:

○       The plain text

○       The encryption key

■       They then transform the text with the key

○       The output is the cipher text

●       Decryption takes two inputs:

○       Ciphertext

○       The key

■       Outputs the plain text

●       Symmetric Encryption:

○       Will use the same key to encrypt as they do to output

○       Good for only a couple of people

■       Larger groups mean more keys for symmetric cryptography

●       Asymmetric Encryption:

○       Will use a keypair where each party has a different key

○       The public key is distributed to other partners freely

○       The private key is kept secret

○       If Bob encrypts something for Alice he uses Alice's public key and then Alice decrypts it with her private key

○       Can scale better

○       But it takes longer to encrypt and decrypt with

![](file:///C:/Users/Markus/AppData/Local/Packages/oice_16_974fa576_32c1d314_110/AC/Temp/msohtmlclip1/01/clip_image014.gif)

Goal of cryptography:

●       Provides confidentiality

●       There are 3 different ways that data can be stored and therefore compromised

○       Data at rest:

■       Stored on a harddrive or other storage drives

○       Data in Transit:

■       Transmitted over a network connection

○       Data in Use:

■       In memory data

■       Currently in use

●       The other goal of encryption is Integrity

○       Being able to encrypt and decrypt means that people can’t tamper with the data since only the private or public key can make changes

●       Another goal is authentication

○       Can use encryption to prove identity

●       Obfuscation:

○       Sometimes we want to hide sensitive data

○       Such as hiding sensitive data

●       Non-Repudiation:

○       Proof of verification of origin

○       Digital signatures are used to provide non-repudiation

○       Non-repudiation is only possible with asymmetric cryptography

●       Cryptography takes time and needs a trade-off between resources and the level of encryption

○       The stronger the algorithms the more time/resources it takes to use them

○       Long keys = long encryption

Codes and ciphers:

●       codes:

○       A code substitutes one word or phrase for another

○       Intended to provide secrecy and/or efficiency

○       For example the 10-code system

●       Ciphers:

○       A system that uses mathematical algorithms to encrypt and decrypt messages

○       Pretty much everything in this course is a cipher not a code

○       Stream Ciphers:

■       Work on one at a time (such as each letter or bit at a time)

○       Block Ciphers:

■       Operate on large segments of the message at the same time

●       Cipers perform encryption and decryption using two basic building blocks

○       Substitution Ciphers:

■       Change the characters in a message

![](file:///C:/Users/Markus/AppData/Local/Packages/oice_16_974fa576_32c1d314_110/AC/Temp/msohtmlclip1/01/clip_image016.gif)

■       For example, it might shift all the letter two positions

■       If someone wants to decrypt this just shift the letters back

■       This is an example of a rotation ciphers (ROT)

●       Shifted letters that can be rotated back

●       For example, ROT13 would shift letters 13 places

○       Transposition Ciphers:

■       Don’t change the characters in the message

■       Instead they re-arrange them

■       Scramble up the letters

●       We don’t actually use these - they are too easy to crack

○       But they are a strong and easy-to-understand basic to learn about

Selecting an algorithm:

●       If a vendor says they are using a proprietary encryption algorithm be skeptical

●       The best algorithms everyone knows about and no one knows how to crack

●       Security through obscurity:

○       The security of an algorithm depends upon the secrecy of its approach

○       This is a slanderous term! Look at those bad little security people they have to hide their algorithms because they are so trash!! :)

●       Use encryption algorithms that are proven, published, and accessible

○       Don’t write your own, you are human and dumb and will probably mess it up

●       Choosing your key length:

○       The longer the key the more secure the information will be

○       But the performance of the service goes down

![](file:///C:/Users/Markus/AppData/Local/Packages/oice_16_974fa576_32c1d314_110/AC/Temp/msohtmlclip1/01/clip_image018.gif)

The Cryptographic Life cycle:

●       manages the use of encryption materials over time

●       As cryptographic algorithms age, they often become insecure

○       Algorithms are also just getting more and more good

●       There is a five-stage life cycle

![](file:///C:/Users/Markus/AppData/Local/Packages/oice_16_974fa576_32c1d314_110/AC/Temp/msohtmlclip1/01/clip_image020.gif)

●       Initiation:

○       Gather the requirements for the new cryptographic system

○       Have some goal that you want to reach

○       Have an objective for the level of keys, the availability, and the validation

●       Development or Acquisition:

○       Acquisition is preferred (since making your own is not)

○       Looks for the combination of software, hardware, and algorithms that meet their objectives

●       Implementation and assessment:

○       Configure and test the cryptographic system

●       Operations and Maintenance:

○       Use from day to day

●       Sunset:

○       When the system is no longer good for use

○       During this phase, the system and it’s keys should be safely destroyed and all the encrypted information should be moved over to something new

Data Encryption Standard (DES):

●       DES is a historic encryption algorithm

●       Made by IBM in the 1970s - intended to serve as federal encryption standards

●       Some key facts about DES:

○       Symetric

○       Block cipher operating on 64-bit blocks

○       Key length of 56 bits

○       Now considered **insecure**

3DES:

●       When DES was discovered to be insecure security professionals had a dilemma

●       Lots of stuff was made for DES and had to be changes

●       3DES is three rounds of DES

●       This is sometimes written as 3DES

○       We start with one des key and run through it once

○       then takes this output and feeds it into another round with a new key

○       We then take a final output and feed it through with a third key

○       We then can reverse this with key 3 → 2 → 1 to get back the plain data

●       We could theoretically reuse different keys like 1 and 3 being the same but this is less effective

●       Facts about 3DES:

○       Symmetric encryption algorithm

○       A block cipher operating on 64-bit blocks

○       Has a key length of 112 bit (when used with 3 keys)

○       Being phased out

AES:

●       Advanced encryption standard (AES)

●       Came from a competition led by the National Institute of Standards and Technology

●       Key facts about AES:

○       Symmetric

○       Block cipher operating system

■       128-bit blocks

○       Can have a 128, 192, or 256 bit key

Blowfish

●       Public domain

●       A potential replacement for DES

●       Uses a Feistel network

●       Combines substatution and transposition

●       Facts about blowfish:

○       Symmetric encryption algorithm

○       Block cipher operation on 64-bit blocks

○       Key length anywhere between 32 and 448 bits

○       **NOT secure** - there are known attacks

○       The creator does not like using it

○       Use Twofish instead

Twofish:

●       One of the AES competitions

●       Made by the same person who made blowfish

●       Also uses a Feistek network

●       Combines substitution and transposition

●       Facts about twofish:

○       Symmetric encryption algorithm

○       Block cipher operation on 128-bit blocks

○       Can have 128, 192, and 256 bits

○       Considered secure!

RSA:

●       It is somewhat slow - will only be slower if you make the key longer too

○       Not used for long messages

●       RSA is often used for setting up an initial secure channel for them to exchange a symmetric key that will work fast

●       RSA had a patent but it expired

●       Key facts about RSA:

○       Asymmetric encryption

○       Between 1024 and 4096 bits

○       Recent implementations are considered secure, use at least 1024 bit keys though

Hash functions:

●       important for the use of public key cryptography

●       Hashes are a one-way function that transforms a variable length input into a unique fixed length output

●       Hash function characteristics:

○       One way and can’t be reversed

○       You can not get the content from the hash but you can make sure the content maps to the text

○       The output of a hash function will always be the same length

■       Any length can go in there though

○       Hash functions also produce a unique output

○       Two different inputs should not output the same hash output

●       If the hash is reversible it is NOT secure

●       Must be collision resistant!

●       MD5:

○       is no longer considered totally secure but it is still in use

○       This is bad and dumb

●       SHA:

○       SHA-1:

■       is not in use and not secure

○       SHA-2:

■       has replaced it and is actually 6 different functions in a trench coat

■       Produce output of 224, 256, 384, and 512 bits

■       Uses a mathematically similar approach of SHA-1 and MD5

○       SHA-3:

■        was made to keep up with underlying issues in SHA-1 that got brought over to SHA-2

■       Designed to replace SHA-2

■       Produces a hash of user-selected fixed-length

■       Can be any fixed-length output

■       Some people don’t trust it since the national security agency had a lot of involvement

○       RIPEMD:

■       Created as an alternative to government-sponsored hash functions

■       Produces 128, 160, 256, and 320 bit hashes

■       The 128 is not considered secure

■       But the larger ones are

■       This is actually used in Bitcoin transitions ← Cringe

○       HMAC:

■       Hash-based message Authentication code

■       Combines symmetric cryptography and hashing

●       When using HMAC, the sender of a message provides a secret key

●       Create a verify message authentication code by using a secret key in conjunction with a hash function

●       Hash functions are used with asymmetric cryptography for digital signatures and digital certificates

Digital signatures:

●       provide an electronic equivalent to physical signatures

●       provide integrity, authentication, and non-repudiation

●       When the recipient get the message they know 3 things:

○       Authentication: The owner of the public key is the person who signed the message

○       Integrity: The message was not altered after being signed

○       Non-repudiation: The recipient can provide these facts to a third party

●       Digital signatures depend upon:

○       Collision resistance

○       Asymmetric cryptography

○       We actually use the private key for encryption and the public key for decryption here rather than how we do it normally

○       This is so we can prove who sent it

○       Example:

■       You can only get the correct result when using Alices public key

![](file:///C:/Users/Markus/AppData/Local/Packages/oice_16_974fa576_32c1d314_110/AC/Temp/msohtmlclip1/01/clip_image022.gif)

○       Digitally signing a message does not provide confidentiality

○       We would need to encrypt it with Bob’s public key to do this

**Week 6 Review:**

Trust Models:

●       The two people communicating must be sure that they are talking to the right person

●       We can use the Diffie-Hellman key exchange protocol

○       This prevents eavesdropping

○       But we still need some way to make sure we are not talking to the imposter upfront

●       We use asymmetric cryptography for this

○       Since every user has a secret key they can share their public key freely

○       That way there is no eavesdropping

○       These two factors combine to eliminate the need for eavesdropping protection during key exchange

○       We still need to worry about imposters

●       The web of trust

○       PGP encryption

○       You cannot personally meet everyone you know

○       It depends on indirect relationships

○       If someone knows someone who knows someone then we can use that connection to vouch for each other

○       If we all trust one another then we can connect most people with each other

○       There are problems:

■       There is a decentralized approach

■       High barrier of entry

■       The is a high technical knowledge needed to use it

■       Requires tech knowledge

PKI and Digtial Certficates:

●       Public Key Infrastructure

●       Builds upon web of trust

●       Public Key Infrastructure - PKI solves many issues with the web of trust

○       We use certificate authorities

●       We trust highly trusted centralized Certificate Authorities (CA) to vouch for many others at once

●       Certificate Authorities (CA):

○       Trusted third-party authentication organizations or individuals

○       Issue digital certificates containing both identity information and a copy of the subjects public key

●       Digital certificates are the digital implementation of this

○       The level of authentication depends on the CA

■       Some can be high and some can be very low

○        If the CA is satisfied, you give them your public key over a secure channel

○       The CA uses this to create the digital certificate to create and signs the certificate

○       You can then provide this certificate to anyone you would like to securely

■       You do not need to worry about encryption when sending it

■       It does not contain sensitive information

■       The other party just checks if it is valid

○       If anyone else gets a copy of the certificate it won’t be a problem because you still have the private key

■       Since the other party is using your public key to talk to that other party they won’t understand what they are trying to say to them since they will not have your private key

Creating a Digital Cerificate:

●       The process for creating digital certificates follows the X.509 standard

○        Digital certificates are sometimes called X.509 certificates

●       A certificate authority creates a digital certificate that associates a public key with an individual or organization

![](file:///C:/Users/Markus/AppData/Local/Packages/oice_16_974fa576_32c1d314_110/AC/Temp/msohtmlclip1/01/clip_image024.gif)

●       How it works:

○       Alice first creates a public-private key pair

○       She then takes the public key and makes a CSR

■       This contains the public key and name, email address, or other identifying information

○       She then sends this to a CA of her choice

■       If the CA is a third party it is also known as the registration authority (RA)

○       When the CA receives the CSR it takes some action to validate the requester

■       They need to make sure that the person is legit for their own credibility to be maintained

○       Once satisfied they take the CSR, remove the information from it, and puts it in the format of an x.509 certificate

○       The CA then takes their private key and puts it’s digital signature on the certificate

○       It then sends the certificate back to the requester

■       The request can now use that certificate and provide it to others who want to communicate with them

●       Others can verify that it is valid as long as the certificate is encrypted through the private key of the CA

●       The certificate includes:

○       The certificate subject’s public key

○       An expiration date for the certificate

○       The common name attribute - the identity name of the certificate (eg www.linkdin.com)

■       We can use a certificate to secure more than one version of an identity

■       For example the Subject Alternative Name or SAN attribute lists the alternative DNS names

■       These are other domain names with the same certificate

●       Example of doing this on the command like

○       openssl req -new -newkey rsa:2048

○       This will walk you through the set up process

Revoking digital certificates:

●       If the key gets compromised then it needs to be revoked

●       This is both up to the certificate authority and the requester to report and deal with this

○       Though the CA is the one that needs to take the action to revoke it

●       Two ways of doing this:

○       Certificate Revocation List (CRL):

■       Places the serial number of the certificate on the CRL

■       All the certificates on the CRL are invalid

●       However this requires everyone to download a list of the current CRL and check if the one they are trying to access is on that list

○       This is a little wacky

●       Everyone would have to download this from everywhere every day

○       Online Certificate status protocol (OCSP):

■       The browser makes a request to the CA for you

■       The CA then checks it’s serial number against the list of revoked certificates

■       Most modern web browsers support this and do it for you

●       An exception is Google Chrome which has a priority way of doing things - oooh secrets secrets

●       The primary issue with OCSP is that it places a burden on the OCSP servers operated by certificate authorities

●       These servers must process requests from every single visitor from a website or other user

●       Certificate stapling:

○       An extension to the online certificate status protocol

○       Relieves some of the burden placed on the certificate authorities

●       How certificate stapling works:

○       When the user requests a website the certificate gets sent to the user's browser

■       The user’s browser would normally be responsible for talking to the certificate authorities OCSP

■       And making sure the certificate is valid

○       However, with certificate stapling the CA OCSP gives proof of validation with the OCSP

■       The web server connects the OCSP server itself and then provides both the signed and timestamped response with the server

■       When the user requests a secure connection the user gets both the certificate and stapled OCSP response

●       While this does not make a big difference on a small scale, it is nice for lots of user requests

○       The OCSP can re-use the stapled certificate for a period of time without re-contacting the server

○       The valid range is typically 24 hours

■       This is amazing for lots of users since what could be 1 million users making 1 million requests in a day is reduced to just one request per day per certificate subject

Certificate Authoritites:

●       The trusted organizations

●       Issue digital certificates to:

○       Individuals

○       Systems

○       Organizations

●       A certificate subject creates a CSR (certificate signing request)

●       This is then passed to a certificate authority, along with proof of their identity

●       The certificate authority checks to make sure the identity is right, creates the digital certificate, and signs the certificate with their private key, and then send it back to the client

●       The certificate subject then can present the certificate to those they want to communicate with

●       People who get this key then verify it by decrypting it with the certificate authorities' public key

●       Certificates often cost money

○       We can use lets encrypt for free though

●       We can use self-signed certificate to not pay for a CA

○       These are NOT trusted by the outside world

○       But they can be used internally

■       There are often systems in place to configure it so that the system will trust the internal CA even if the outside world would not

■       There is also a way to have your system trusted by a third party using certificate chaining

●       This lets the organization issue it’s own certificates that are then trusted by external users

●       The internal CA in this case is then known as an intermediate CA

○       This process is certificate chaining

■       When the user goes to verify the certificate it checks each certificate in the chain to verify the integrity

●       Offline CAs

○       A very sensitive root key

○       The root certificate of a CA is sensitive

■       The private key is usually not kept on a network

■       It is stored on an offline CA that is used as a system for signing only intermediate CAs belonging to the same organization

●       These ones are called online CAs

●       These are what issue the real certificates to customers

●       We can look at the intermediate certificates to view these hierarchies

Certificate Subjects:

●       These are the target for the digital certificate

●       The certificate subject is the entity that owns the public key contained within the certificate

●       The most common use of certificates is to protect web servers

○       But they can also be used to protect

■       Servers

■       Individuals

■       Email addresses

●       We can trace back certificates with a keychain access tool

○       We can then look at root certificate authorities to see the default validation for CAs

●       Certificate object identities (OIDs)

●       Certificate subjects:

○       Any computer or machine (not just a webserver) can be the subject

■       Web, ssh, file servers, email, etc

○       Devices:

■       SANs, routers, switches, VPNs, access points, etc

○       Individuals:

■       Name, email address

○       Developers:

■       Code signing

●       The goal is to securely identify a public key with the subject

●       Certificate Pinning:

○       Used to defend certificates against fraud

○       Tells a user they should not expect a certificate to change

■       Can say “keep this for an extended period of time”

Certificate Types:

●       There a several types:

○       Root certificates:

■       The core of the CA

●       Private key

○       Wildcard certificates:

■       Can match many different subjects

■       Cover an entire domain

■       *.name.com

●       They must be carefully secured

■       Uses a regex style system

■       Wildcard only goes one level deep!

●       www.secure.name.com is not valid

●       www.name.com would be valid

●       They are common for load balancers without a lot of individual certificates

●       There are three different levels of trust (in order of worst to best):

○       Domain validation:

■       The CA only validates the domain ownership

○       Organization Validation (OV):

■       Verifies the business name

○       Extended validation:

■       Requires extensive investigation

■       The highest level

■       Checks the legitimacy of several different components

**Week 7 notes:**

Identification, Authentication, and Authorization:

●       One of the most important things security professionals do is authorize users

●       This has three steps

●       Identification:

○       The user makes a claim about their identity

○       No proof has been presented yet

○       Only a claim, can be false

●       Authentication:

○       This is when the proof is presented

●       Authorization

○       This is what you can do with the authentication you have

●       Note that in the digital world this might look like:

○       Identification: the username

○       Authentication: the password (for the user)

○       Authorization: usually permissions on an access control list for the user or user’s group

●       In addition to this process access control systems provide accounting functionality

○       This lets us track user activity

●       The AAA:

○       Authentication

○       Authorization

○       Accounting

●       Consider the mechanism used to perform these tasks

○       May need something for cloud and on-premise

Authentication factors:

●       Something you know:

○       This could be a password the user remembers

○       Choose strong passwords

○       Password keys are another form:

■       Encryption keys that manage access

●       Something you are

○       Biometrics

○       Like your eye or fingerprint

●       Something you have

○       Possession of a device

○       A keyfab or a phone is often used

●       There are other approaches but they are considered weaker and should only be used in combination:

○       Somewhere you are

■       location

○       Something you can do

■       Typing patterns

○       Something you exhibit:

■       Personality trait

○       Someone you know:

■       Like a second party that vouches

●       These are not generally considered common authentication systems

○       Generally, the 3 main factors are common

●       There are two basic types of errors:

○       False Acceptance:

■       The system misidentifies an individual as an authorized user

■       Measured by the false acceptance rate (FAR)

○       False Rejection:

■       The system fails to recognize an authorized user

■       Measured by the false rejection rate (FRR)

○       FAR and FRR are not good measures of the effectiveness of a system

■       FAR is worst then FRR

○       It should not be too easy or too hard to get into an account

![](file:///C:/Users/Markus/AppData/Local/Packages/oice_16_974fa576_32c1d314_110/AC/Temp/msohtmlclip1/01/clip_image026.gif)

●       MFA:

○       Remember the authentication factors

■       Something you know, are, or have

○       One of these might be compromised

○       So we should consider multifactor authentication

○       Something you know is often combined with something you have

■       Passwords and sms texts to a phone

■       Or a fingerprint and a pin

○       Not multifactor:

■       The techniques must come from different factors

■       A password and a security question don’t count since it is testing something you know twice

Single Sign-on Services:

●       The user logs in with a single set of credentials to access several related but independent systems

●       Many services and libraries for SSO

●       Positives:

○       User can move fast without authenticating

○       Fewer passwords

○       Passwords don’t need to be stored with related sites

■       The user talks to the third-party

○       Consolidates credential management for admins

■       Can deactivate one user from many places easily

●       Negatives:

○       Credentials become more valuable - more likely to be attacked

○       Network availability becomes a failure point

○       Makes the primary SSO source a strong dependency

■       Giving up one account to a third-party means losing access to the other service account

○       The third-party gets to see what you are doing

○       It makes it essential to log out of an account

Brute Force Attacks:

●       When software systematically generates rapid-fire input in an attempt to guess the value of a password

●       Often done systematically with increments

●       Search keyspace:

○       Keyspace = possibilities key length

○       So a wheel with 3 places and 0 to 9 on it would be 103 or 1000

●       We can make passwords stronger with larger varieties of input or longer passwords

○       If we consider letter cases, numbers, and 10 symbols, even on a 3-character length password that is 723 or 373,248

●       A longer key length is also really really good

○       103 = 1000

○       104 = 10000

○       There is an exponential increase in the numbers with the character limit is increased

![](file:///C:/Users/Markus/AppData/Local/Packages/oice_16_974fa576_32c1d314_110/AC/Temp/msohtmlclip1/01/clip_image028.gif)

Speed and Throttling:

●       There is more to passwords than complexity and length

○       The formula is (Possibilities Key Length) / (time per attempt)

●       Time per attempt is getting faster and faster

○       These are similar to bitcoin mining clusters

●       Some computers can do 350 BILLION attempts every SECOND (wtf)

○       This is only increasing and getting faster every year

●       Example:

○       Lets say we have a password that is 8 characters long

■       728 / 100 billion/seconds = 2 hours

○       However if we made this even 2 characters longer:

■       7210 / 100 billion/second = 1.19 years

●       Would it actually take this long?

○       We actually don’t know since it could be the first test or the last or somewhere in the middle

○       But we assume it will take the full amount of the password space

○       This is theoretical time

○       Theoretical time is used to compare:

■       Password strength

■       Algorithms

■       Cracking techniques

●       Brute force attacks:

○       Most are not over the web

■       Web requests are too slow

○       Usually, there is a data breach and there is the encrypted hashed password that needs to be found

●       To better defend, consider speed and throttling:

○       Encourage users to pick stronger passwords

○       Use slow password-hashing algorithms

○       Implement timing and throttling

○       Logging

○       Deny list to spamming ip addresses

Dictionary Attacks:

●       Often times people use words in their passwords

○       Brute force does not really care about real words

●       Dictionary attacks are a brute force attack that prioritize words in the dictionary over common words

●       It is actually the same total time, but it can greatly decrease the actual time

●       What is considered part of the dictionary?

○       Words:

■       Password, dragon

○       Patterns:

■       123456, qwerty

○       Common passwords:

■       Letmein, trustno1, ncc1701

○       Other common ones in password leaks

●       Remember this decreases the actual time only, the total time is the same

Salted:

●       Rainbow tables:

○       Precomputed tables of password hashed for each hashing algorithm

○       Then they get the hash for the password

○       They can look up the hash in the rainbow table

○       This was a big problem with MD5 and SHA1

●       One defence is the salt

○       You put a string in front of the password

○       This is added before hashing

○       Knowing the password requires also knowing the salt string

○       Rainbow tables could be used but they would be almost impossibly large

●       We can improve this further and make it unique for each user

○       By say, adding the username

○       Knowing the password requires knowing the salt string and the user string

○       Rainbow tables are even more impossibly large and only work for one user!

●       Random salt:

○       Create a salt using a pseudo-random string

○       Knowing the password requires also knowing the random string

○       Rainbow tables are useless as each user’s hash is unique and random

●       Store salt in the database:

○       When using user data for salt user data could change

■       Consider that the username might change!

○       When using a random salt

○       Blowfish and bcrypt have a built in salt value

○       The salt is appended to the hash automatically and stored together

■       The salt does not need to be secret it just needs to be unique

Password Spraying:

●       Exploits common passwords

●       Uses them to attack many different accounts at the same time

●       Chances are at least one will probably work

●       The best defence:

○       Prohibit the use of common passwords

Credential Stuffing:

●       Exploits reused passwords

●       Takes already exploited usernames and passwords and tries them on many different sites

●       Defence:

○       So avoid re-using passwords

○       MFA is also a good defence

Password Best Practices:

●       Length > complexity

●       Eliminate periodic resets

●       Enable show password while typing (it actually encourages people to make them longer)

●       Allow password paste in

●       Use breached password protection

●       Don’t use password hints

●       Use MFA

●       Storing guidelines:

○       Secure your databases

○       Hash users’ passwords

Certificate-Based Authentication:

●       Digital certificates may be used to:

○       Connect to servers via SSH

○       Power smart cards

○       Restrict network access

●       These are similar to the ones that are used for websites

●       Key-based authentication:

○       First, create a public-private key pair

○       Share the public key

■       The server will generate a random challenge message

●       You take that and encrypt it with your private key

●       Then send it back

■       If the server can then decrypt it with it’s public key for you then the connection is authenticated

○       This basically provides the same level of protection but it can be automated

![](file:///C:/Users/Markus/AppData/Local/Packages/oice_16_974fa576_32c1d314_110/AC/Temp/msohtmlclip1/01/clip_image030.gif)

○       For example, we can get the key-pair from an EC2 and connect with it

○       We can also use a certificate authority

■       This gives the remote system assurance that you have the private key and you are who you say you are

○       Certificate authentication uses

■       SSH connections

■       Smart cards (CAC/PIV)

●       Common access card

●       Personal identity verification card

■       Network access (802.1x)

Authorization:

●       Two general principles:

○       Least privilege:

■       And the individual should only have the minimum needed to do their job

■       This minimizes the potential damage of an inside attack

■       Limits the ability of an external attack compromising a standard employees account

○       Separation of duties:

■       Performing critical business functions should require the involvement of two or more individuals

●       Maybe separate events and give different employees responsibilities to perform different actions for the system

●       Privilege Creep:

○       Occurs when a user accumulates excess permissions after shifting job responsibilities one or more times

■       Make sure that an employee who moves around loses privileges as they gain new ones

○       Separation of duties and least privileges are both important to consider here

●       Perform account reviews to limit privilege creep

○       Supplement these with quarterly access reviews

Discretionary Access Control Systems:

●       Aka DAC

●       Flexible approach to authentication

●       Users can apply permissions to other users

●       Most common form of access control

●       For example changing file write permissions

○       Makes it so the IT departments does not need to always be involved

●       A user with advanced permissions on resources can grant others permission to the resource for external users

○       There should still be a consideration for the least privilege

●       The NTFS on windows is an example of this

Account types:

●       Different account types require different access controls

●       Most user accounts are standard, they have standard permissions and standard monitoring

○       They may have drastically different rights through

○       Tied to a person

●       Privileged accounts:

○       Made to make changes to the system

○       Log everything they do and consider them very precious

○       It is easy for them to make big mistakes that break things

○       People who use these accounts should only elevate their accounts when they absolutely intend to

■       This is a sudo

●       Guest accounts:

○       Provide temporary access

○       Should be tied to a person

○       Should expire after some time

●       Shared account:

○       Reduces accountability and should not be used

○       These are generally not great

○       Everyone who uses the account has plausible deniability if something happens to it

●       Service accounts:

○       Provided access to internal server processes

○       Should be configured to not login interactively

○       Should not be used by any person

●       Warning:

○       They should be assigned for a specific purpose

○       Shared and generic accounts pose a risk

**Week 8 notes:**

TLS:

●       Confidentiality:

○       Use symmetric encryption (both ways)

●       Integrity:

○       HMAC / AEAD - through digital signatures (both ways)

●       Authentication:

○       The client authenticates the server

○       (the server will accept any client)

○       Uses PKI and X509 certificates

●       The server contains the server certificate and the client has the client certificate - but TLS has no requirements on the client’s side

●       Having a client authentication system does require a set up

●       If both parties use a certificate then it is neutral authentication

○       VPNs tend to use these to lock down the system for external access

Updated protocols:

●       Nothing changes within the protocol it is just more secure

●       HTTP + TLS = HTTPS

●       FTP + TLS = FTPS

●       SMTP + TLS = SMTPS

●       RTP + TLS = SRTP

●       DNS for TLS does exist but has a massive overhead

AES:

●       Standard symmetric cipher

●       There are modes such as CBC and ECB

●       AES GCM and AES CCM are updated modes

●       In the latest version of TLS we stopped allowing CBC and ECB in favour of GCM and CCM

●       GCM and CCM are both AEAS ciphers

○       Using these actually makes the negotiation stages much easier

●       The diiffy helmen (idk how to spell their names) is used to exchange asymmetric keys

●       Ephemeral DH Key exchange:

○       This is used for session keys since the old key exchange had issues where keys could be record

○       Ephemeral keys will be short-lived

○       The session key should be unique and short-term

■       It can not be re-created from the long-term secret

■       Which is the private key in most cases

○       This is called perfect forward secrecy

●       ECDHE is the standard ephemeral DH key exchange system

Video 1: Securing Common Protocols

●       Many protocols were not built with security in mind (TCP for example)

●       These have typically been modified to work better with security:

○       Such as https being made from http

●       Some websites run both http and https

●       But best practice is to redirect an http site to the https site

●       HTTPS is very similar to http but adds TLS to web browsing

○       This adds transport level security to the connection

○       This creates a session key for communication

●       Admins of linux system often need to insure secure connections between ssh

●       Telnet was originally used but it was all unencrypted and showed things like names and passwords in the command line

●       Ssh is a secure alternative (exchanges an ephemeral session key over port 22)

●       Example ssh command (with a set key that the instance is already using)

○       **ssh -i ohio.pem ec2-user@112.12.12.2**

●       FTP:

○       Lets file transfer happen but it is insecure

○       So instead we cna use:

■       FTP Secure (FTPS) which adds TLS to FTP

■       Secure FTP (SFPT) transfers files over SSH

■       Secure Copy (SCP) provides secure command line file transfer over SSH

○       There is another version known as the trivial file transfer (TFTP) but it is insecure and not commonly used

●       Video and voice communication should use TLS encryption

●       RTP-based VoIP (voice over IP communications) services should use the Secure RTP (Real Time Protocol) use SRTP instead

●       Network time protocol:

○       This used to be used to synchronize system clocks

○       Use NTPsec instead

●       Email Protocols:

![](file:///C:/Users/Markus/AppData/Local/Packages/oice_16_974fa576_32c1d314_110/AC/Temp/msohtmlclip1/01/clip_image032.gif)

○       Encrypt email messages and attachments at the application layer (rather than the typical network layer) with S/MIME

●       Network communications depend on DNS (domain name resolution) false dns records may attempt to be inserted

●       DNSSEC lets digital signatures be mapped to DNS

●       Limited authorization DHCP servers

○       Can prevent rogue DHCP on windows

●       LDAPS offers a secure alternative to LDAP

Video 2: TLS and SSL:

●       Digital certificates provide a secure exchange system for public encryption keys over insecure networks

●       TLS (transport layer security) uses these certificates to perform secure communications over a public network

●       Stages of TLS:

○       Client to Server: makes a request

■       asks for a secure session

■       contains cipher suites supported by the client

○       Server: receives request

■       Once the server gets the request to compares the list of cipher suites to it’s own list of supported algorithms

○       Server to client: Response to client:

■       Sends a message to the client with two pieces of information:

●       The servers digital certificate

●       The type of algorithm it would like to use

○       Client: receives the request:

■       Checks which certificate authority issued the certificate and if it is valid

●       Consider if the DNS name and time on the certificate is correct

■       If satisfied the client will create a random symmetric encryption key

■       The client then uses the server’s public key to encrypt this session key and sends it back to the server

○       Client to server: response:

■       The client then sends the publicly encrypted session key to the server

○       Server: receives the key:

■       It then uses it’s private key to decrypt the session key

■       The two systems may then communicate as long as they would like

■       When the session breaks the key is destroyed

●       Session keys are also known as ephemeral keys

●       Side note, TLS depends upon the pairing of encryption and hash functions known as cipher suites

●       TLS is NOT a cryptographic algorithm, you need to use it to apply other cryptographic algorithms

●       Cipher suites are only as strong as the algorithms it contains

○       TLS can be insecure if the cipher suite is insecure

●       Secure sockets layer - SSL

○       Insure predecessor to TLS

○       Should not be used but is often used to refer to TLS

●       OpenSSL:

○       The most popular version of open-source TLS

○       Has it’s own history of vulnerability:

■       Heartbleed allowed attacks to read information over vulnerable servers to read data from other communications

●       SSL inspections:

○       Performed a friendly main in the middle attack to inspect network traffic

○       Since SSL makes it hard to see what is going on

Video 3: How to decrypt HTTPS Traffic with Wireshark:

●       Capturing session keys:

○       Windows 10 > system properties

○       Add an environment variable for SSLKEYLOGFILE with a value of where you want the session keys to be stored

●       We can use Wireshark to capture the packets going out to the web servers

○       In wireshark start the connection for Wi-Fi

○       Go to a website on a browser

■       Now you can go into the wireshark and see the captured session keys

●       Search for frame contains <websitename>

■       Now you can see the packet transfer for the TLS traffic

○       Go to preferences and edit preferences:

■       Find TLS and give it a keyload file that we specified earlier

○       Now we can actually see the encrypted parts of the communication

○       We are not only dealing with encryption but also compression

Video 4: Network vulnerabilities

●       It has become URGENT that web developers use HTTPS

●       HTTPS was created in 1994 for secure e-commerce transactions

●       Around 2005 we used HTTPS for protected account pages

●       In 2010 we had to protect sites that contained login requests for the whole site 

○       That way we always encrypted logins

●       2015 we used it as the default for all sites

●       Usage statistics:

○       In 2014 it was 26% and in 2018 it was 68%

○       Of the top 100 websites 81 used HTTPS by default

●       Let's encrypt:

○       Created by the Internet Security Research Group (ISRG)

○       Launched in April 2016

○       The project goal is for all web servers to use HTTPS

○       Offers free and simplified certificates

○       Over 50 million active certificates

●       Google Chrome:

○       In January 2017 they started marking all http pages with a password or credit card field as Not Secure

○       In October 2017 they started marking incognito mode sites with http as Not Secure

○       July 2018 all http pages were labeled not secure

●       Normally an http page would look like this:

![](file:///C:/Users/Markus/AppData/Local/Packages/oice_16_974fa576_32c1d314_110/AC/Temp/msohtmlclip1/01/clip_image034.gif)

●       Other browsers are catching on

●       Https will slowly become the default standard for websites

![](file:///C:/Users/Markus/AppData/Local/Packages/oice_16_974fa576_32c1d314_110/AC/Temp/msohtmlclip1/01/clip_image036.gif)

●       You should just Expect that the web is secure and get a big nasty warning if it is not

●       It is urgent that you implement https fast

○       It is the best practice for web security

○       The web is moving that way

○       Setting it up is easier than ever

○       It will alarm users if you do not have it

Video 5: Redirect requests to HTTPS

●       We want to redirect http to https for clients

●       By default if you use http:// it will go to port 80

●       Https is on 443

●       We want to redirect all requests to port 80 to go to port 443

●       Certbot or lets encrypt can configure this for your automatically

●       If you have a purchased certificate you will need to add it to your server

●       Example in apache

![](file:///C:/Users/Markus/AppData/Local/Packages/oice_16_974fa576_32c1d314_110/AC/Temp/msohtmlclip1/01/clip_image038.gif)

●       This means all traffic to port 80 should go to https

●       Example with nginx:

![](file:///C:/Users/Markus/AppData/Local/Packages/oice_16_974fa576_32c1d314_110/AC/Temp/msohtmlclip1/01/clip_image040.gif)

●       Now http or https will be sent to https

Video 6: HTTP Strict transport security:

●       HTTP Strict Transport Security: HSTS

○       Instructs web browsers to only interact with a website using HTTPS

○       Web browser remembers

○       We browser automatically redirects to HTTPS

●       Previously we had the webserver do the redirect but this starts with an initial insecure connection which is bad

●       With the browser knowing we can avoid the initial insecure connection

○       This protects us from downgrade attacks

○       And man in the middle attacks when hackers can catch that insecure request and may redirect you to their own evil site on https

●       We do this by adding a directive to the HTTP header

●       The initial connection will be http but once that has happened once the web brower will know in the future to always try https

●       The header is **Strict-Transport-Security**

●       Sets a max age and some standard information

●       For example:

○       **max-age=300; includeSubdomains;**

●       Most common way in apache is to add it to the secure virtual host file in https 

![](file:///C:/Users/Markus/AppData/Local/Packages/oice_16_974fa576_32c1d314_110/AC/Temp/msohtmlclip1/01/clip_image042.gif)

●       Nginx example

![](file:///C:/Users/Markus/AppData/Local/Packages/oice_16_974fa576_32c1d314_110/AC/Temp/msohtmlclip1/01/clip_image044.gif)

●       From then on browsers will remember to set https

●       It is a good idea to start with a small number like 300 seconds = 5 minute

●       Then up it to something like 63072000 seconds (2 years)

●       Once we get to 2 years we can start HSPS preloading

Video 7: HSPS preloading

●       HSPS example:

○       Use makes an insecure http request

○       The request is sent to http

○       The web server says go to port https and also gives the header saying use HSTS directive in the future

○       The browser goes to 443

●       If the user starts out with the insecure connection then there is still one weak point

●       HSTS Preloading:

○       A long list of HTTPS-only sites

○       Available on chrome and most major browsers

■       Maintained by chrome

○       The header is still useful for other browser

●       To get this working we must set it to at least 1 year but 2 years is preferred

●       We should add includeSubdomains and add preload; to our strict transport security

●       You must go to [https://hstspreload.org](https://hstspreload.org) and request that you be added to the list

●       Then the next time the user updates their brower you will be on https by default

●       Requirements from video:

![](file:///C:/Users/Markus/AppData/Local/Packages/oice_16_974fa576_32c1d314_110/AC/Temp/msohtmlclip1/01/clip_image046.gif)

●       You can build up the previous steps and slowly become more secure

**Week 9 notes:**

Video 1: Public and Private Addressing:

●       IP addresses are used to send packets from one node to another

●       Public IP Addresses:

○       Assigned by a central authority and are routable over the internet

○       Centrally managed by ICANN (Internet Corporation for Assigned Names and Numbers)

○       North america is LACNIC, africa is AfriNIC, asure and europe is RIPE NCC and oceana is APNIC

○       ICANN distributes large blocks of addresses to regional authorities for distribution

○       For example the American Registry for International Numbers (ARIN) governs the distribution of IP addresses in the US and Canada

○       IPv4 is a scarce resource

○       There are no large blocks of public IP addresses available

○       The only way to get them is to purchase or rent one from another organization

○       In the early days of networking an organization would get a large block of public IP addresses and use them on everything

○       The scarcity combined with security concerns makes this impractical today

○       There are only 4.3 billion possible addresses so we technically don’t have enough to assign every address a unique one

●       Private IP Addresses:

○       Available for anyone’s use but not routable over the internet

○       They are the solution to the limited IP address space

○       There are 3 different addresses that can be used as private IP ranges

■       10.*.*.*

■       172.16.0.1-172.31.255.255

■       192.168.*.*

○       The only catch is that they are reserved for private use and cannot be used on the internet (alone)

○       There is usually a mix of mostly private IPs and a router that has a public address that internal nodes traffic their information over

○       This is NAT or network address translation

○       Networks and firewalls perform Network Address Translation for us

○       The NAT router will keep a table of private and pubic address so that it can route traffic to private devices on it’s network

○       NAT has security concerns as well:

■       It does help hide internal addresses from the public internet

■       It limits direct access to systems

■       However, it makes it difficult to identify the true origin of traffic

●       Because of this most organizations maintain logs of their nat translations to see which device was using certain public IP addresses at any given time

■       NAT requires a large loop of public IP addresses for every system on the network that needs to communicate with the internet

○       Port Address Translation (PAT)

■       Allows multiple systems to share the same public address

■       Instead of recording translations between IP address, each one gets a different port on a public IP address

■       This way more than one device can use the same address at any given time

Video 2: Subnetting

●       It is common for organizations to want to subnet their IP addresses

●       It helps break a large network address space into smaller more manageable address spaces

●       Instead of haphazardly using the same CIDR for all addresses, you may choose to start chopping

●       This lets us shift the cut between network and device

●       This will give us more network spaces but less overall hosts

●       But these smaller networks are much more usable

●       It makes sense to divide up teams of users with their subnet

●       Once you start shifting around these network and host spaces, we will need to alter the subnet mask

●       Remember that IP addresses are actually just binary

![](file:///C:/Users/Markus/AppData/Local/Packages/oice_16_974fa576_32c1d314_110/AC/Temp/msohtmlclip1/01/clip_image048.gif) 

●       Subnet masks use the same dotted quad notation

●       For example:

●       ![](file:///C:/Users/Markus/AppData/Local/Packages/oice_16_974fa576_32c1d314_110/AC/Temp/msohtmlclip1/01/clip_image050.gif)

●       A subnet mask can be written in two different forms:

○       As a sort of IP address that only specifies the network space such as 255.255.255.0

○       Or we can use the number of 1s that the network addresses uses with a / for the cidr notation such as 192.168.1.0/24

Video 3: VLAN and network segmentation

●       Virtual LANs (VLANs) separate systems on a network into logical groups based upon functions, regardless of physical location

●       Most network diagrams look something like this:

![](file:///C:/Users/Markus/AppData/Local/Packages/oice_16_974fa576_32c1d314_110/AC/Temp/msohtmlclip1/01/clip_image052.gif)

●       With separate networks

●       We can use VLANs to connect sepmented users who want to be on the same network but are in different locations

●       VLANs extend the broadcast domain

○       This all happens at layer 2 of the network stack and does not use routers or firewalls

●       To set them up they must do 2 things:

○       Enable VLAN trucking

○       Assign switchports to VLANs

●       Switchport technology will take care of the rest and inforce network separation

Video 4: firewalls:

●       Firewalls are the security guards of the network

●       Uses a security policy to control inbound and outbound traffic

●       It does not effect internal network traffic

●       They often connect to 3 networks:

○       The internet

○       The internal network

○       The demilarized zone (DMZ)

●       The Demilitarized Zone:

○       Contains systems that must accept direct external connection

○       Isolates those systems due to risk of compromise

○       Protects internal networks from compromised DMZ systems

●       If someone manages to hack into the DMZ they still will not have access to the internal network

●       Older firewalls used something called stateless inspection (Stateless Firewalls)

○       Evaluated each connection independently

●       Modern firewalls use stateful inspection

○       This tracks open connections

○       For example if a user request a webpage the firewall will note the request and allow the webserver to respond

○       The firewall will not re-evaluate the request each time

○       When the firewall encounters a new request it evaluates it based on rules defined by system administrators

○       These rules describe network connections the firewall should act apon

○       Firewall rule contents:

■       The source system address effected by the rule

■       The destination system address

■       The destination port and protocol affected by the rule

■       The action the firewall should take when encountering the rule

●       Allow or deny the traffic

●       Example:

![](file:///C:/Users/Markus/AppData/Local/Packages/oice_16_974fa576_32c1d314_110/AC/Temp/msohtmlclip1/01/clip_image054.gif)

○       Implicit Deny:

■       Typically any traffic that is not allowed explicitly should be denied

■       This principle is known as the default deny or implicit deny rule

○       Current generation firewalls are known as Next-genration firewalls or NGFW

○       The devices can incorporate a large amount of contextual information

■       Can even consider the type of user or the time of day in the quest

○       Firewalls can also perform more extensive roles such as:

■       NAT gateway operations

●       They can translate public and private IP address

●       Normally configured as part of the firewall rules that permit access

■       Content/URL filtering

■       Web application firewalls:

●       They understand how the http protocol works and can look for things like cross site scripting or SQL injections

○       When you select a firewall technology you face several choices:

■       You may choose the deployment methodology:

●       Network hardware firewall

○       Physical network devices

●       Host based software firewalls

○       Software that sits on a server

●       Most organziations use both

■       Open source or proprietary firewalls:

●       Hardware firewalls are almost always proprietary

●       Software firewalls may be either open source or proprietary

○       Deployment mechanisms:

■       Hardware appliance vs virtual appliance:

●       Hardware appliances ship from the manulafacture with firewall firmware installed

●       Virtual appliances may be loaded directly into a virtualization platform

Video 5: Zero Trust Networks

●       Zero-trust approaches mean zero trust in the network

●       It places trust in individuals rather than the network

●       It does not mean that nobody is trusted but it means that individuals are trusted not the networks

●       Zero trust shifts the focus away from perimeter protection and instead on strong identity and authentication of individual users regardless of their location

●       When an organization moves the trust off the network security, identity management becomes critical

●       Zero trusts also require strong SIEM and SOAR platforms to facilitate monitoring

●       SIEM systems use aggregate logging systems

●       Security Orchestration Automation and Response (SOAR) deploys automated responses to security threats from a playbook

●       The combination of both provides deep visibility into network activity

●        And instantaneous response to threats

●       Cloud access security brokers (CASBs) enforce security policies in the cloud

●       These will let centralized security rules be deployed to the cloud

●       Endpoint detection and response (EDR) platforms remediate endpoint security issues

●       The risk remains that a compromised endpoint will lead to a compromised user account

○       This is a serious issue

●       Endpoint detection and response (EDR) platforms remediate endpoint security issues

●       EDR compliments the use of other endpoint controls

Video 6: Network Intrusion Detection and Prevention

●       Intrusion detection systems (IDS) monitor network traffic for signs of malicious activity

●       For example an IDS may notice a:

○       SQL injection

○       Malformed Packets

○       Unusual logins (time or user)

○       Botnet Traffic forming on the network

●       Intrusion detection systems (IDS)

○       Alert administrators to suspicious activity

○       Require someone to monitor and take appropriate action 

○       Sometimes administrators are busy, which is why we use intrusion presentation systems (IPS)

●        intrusion prevention systems (IPS):

○       Block malicious activity automatically

○       Just like IDS systems but they also take actions

○       There are two different types of IPS errors:

■       False positive errors

●       When an IDS/IPS triggers an alert when an attack does no take place

■       False negative errors:

●       When the IDS/IPS does not report something it should have

●       IPS and IDS use two different technologies to identify suspicious traffic:

○       Signature Detection Systems:

■       Most common and most effective

■       Similar to other antivirus software

■       Contain databases with rules describing malicious activity

■       Alerts administrators to traffic matching signatures

■       Fails to detect brand new attacks

■       However, if the signatures are well-defined it reduces the false rate

○       Anomaly Detection Systems:

■       This model takes a different approach to intrusion detection

■       It tries to develop a model of normal activity and reports deviations from it

■       For example, if a user normally connects from north America in the day and suddenly connecting from Asia it could trigger the anomaly detection system

■       Can detect previously unknown attacks

■       Has a higher false positive error rate

○       Note that Anomaly detection, behaviour-based detection, and heuristic detection are the same thing

●       IPS deployment modes

○       Inband and out-of-band approaches

○       In-band (inline) deployments

■       The device sits in the path of network communications

■       The device can block suspicious traffic from entering the network

■       It has a single point of failure!

○       Out-of-band (passive) deployments:

■       Not in the network path but sits outside of network traffic

■       Connected to a SPAN port on a switch

■       Can read and react to traffic but does not interfere with it

■       It can not stop the initial attack but it can block future ones like it

Video 8: unified threat management:

●       UTM or Unified threat management combines many network security systems on one device

●       They start by providing many basic functions such as a firewall

●       Basic features of UTM:

○       Protecting network against attacks

○       Blocking unsolicited traffic

○       Routing traffic to and from the internet

●       Addition security features:

○       VPN connectivity

○       Intrusion detection

○       Intrusion prevention

●       Small business features:

○       URL filtering

○       Content inspection

○       Malware inspection features

○       If you host your own email server - it can provide email and spam filtering

●       UTM devices still require regular monitoring

●       Each of the functions needs to be managed

●       The same security analytics that you preform on the devices that it is functioning as

●       UTM devices still require regular monitoring

●       UTMs are NOT good for big companies, they should use individual devices most of the time

●       Ideal for smaller companies where it is harder to afford a lot of infrastructure

Video 9: Restricting Network Access:

●       Security professionals must restrict access to networks

●       When controlling access there are usually two main objectives:

○       Perimeter security:

■       Keeps out unwanted remote users from the network

■       Uses ACL or Access Control Lists

■       Through the use of firewalls and other controls

●       Some common firewall vendors are cisco, Powell alto, and checkpoint

○       Network Access Control:

■       Limit physical network access to authorized individuals and devices

●       To enforce security policies, we must be able to express them in technical terms

●       When need to explain what we don’t want on our network in technical terms before we can express them

●       Ways to express a security policy:

○       Rules Based:

■       Restrict access based upon business logic

■       Explicitly list all the types of activity that are or are not allowed on the network

○       Role Based:

■       Restrict access based on the identity of an individual user

■       For example limit access to only people in the human resources department

○       Time-based:

■       Based on the time of day

○       Location Based:

■       Restrict access based on physical locations

●       After we have these rules, we can translate them into security policies

Video 10: Network access control

●       Network admins need to restrict network access to authorized users and devices

●       This is where Network Access Control comes in

●       This intercepts network traffic coming from unknown devices and verifies that the system and users are authorized before allowing further communication

●       NAC uses 802.1x authentication to preform these actions

●       There are 3 systems involved with any 802.1x transaction

○       The device that wants to connect to the network

■       This device needs to be running a type of software called a supplicant

■       The supplicant is responsible for preforming all the NAC related tasks for the user

○       The switch:

■       The device that is connected to

■       The authenticator

■       In a wireless network, this is the wireless controller

○       Authentication server:

■       A backend centralized server that performs authentication for all of the authenticators on the network

■       Often performs authentication for many different services

●       NAC is just one of those services

●       How they work together

○       First the user attempts to connect to the authenticator

○       The authenticator takes those user’s credentials and passes them along to the authentication server

○       The authentication server takes the credentials over a radius connection

○       If they are authentic then the authentication server passes the credentials to the authenticator and then the authenticator will allow the user to connect to the desired target network

○       If the credentials don’t validate correctly the authentication server sends a radius reject message and the user is prompted to try again

![](file:///C:/Users/Markus/AppData/Local/Packages/oice_16_974fa576_32c1d314_110/AC/Temp/msohtmlclip1/01/clip_image056.gif)

●       NAC roles:

○       User and device authentication:

■       Role-based access

●       Once the authenticator learns the identity of the user from the authentication server it also makes a decision about where to send that user

●       The authentication server provides addition user information

●       Authenticator places user on a role-appropriate network based upon that information

●       For example, professors and students may go to different networks

●       This is normally done through the use of VLAN assignments

●       This separates different types of network users from each other

■       Posture checking:

●       Also known as health checking

●       This verifies that devices connecting to the network comply with security policies

●       Such as:

○       Verifying antivirus software presence

○       Validation current signatures

○       Ensuring proper firewall configuration

○       Verifying the presence of security patches

●       If the device fails the posture check it might go into a quarantine VLAN

●       Where it will have limited access to internal resources

●       The device may then use this limited access to meet the posture check requirements

●       Implementations of posture checking:

○       Agent-based

○       Agentless (scanning for compromise)

○       Inline (the NAC is involved)

○       Out of band approach (NAC makes the decisions but it is up to the network components to enforce this decision)

Video 11: Firewall rules management

●       Firewalls block undesirable network access attempts

○       Anything that is not explicitly authorized

●       The basic function is that every time someone from outside of the network tries to connect to the network it tries to identify the request, look up what to do with it, and apply those rules

○       If there is no rules for the request then it will block it

●       For example:

![](file:///C:/Users/Markus/AppData/Local/Packages/oice_16_974fa576_32c1d314_110/AC/Temp/msohtmlclip1/01/clip_image058.gif)

●       When a packet arrives it will checked against these rules (top to bottom)

●       The firewall then carries out the specified action

●       Firewall administrators must watch for rule configuration errors

○       Some firewalls may contain hundreds if not thousands of rules

●       Common configuration rule errors:

○       Shadowed rules:

■       Occur when a rule base contains a rule that will never be executed because of its placement in the rule base

![](file:///C:/Users/Markus/AppData/Local/Packages/oice_16_974fa576_32c1d314_110/AC/Temp/msohtmlclip1/01/clip_image060.gif)

■       Unfortunately, this rule will never be executed

■       Since the more specific rule comes after it will be ignored

■       We can fix this but re-arranging the rule base

○       Promiscuous rules:

■       This allows too much access

■       They may be the result of laziness, a lack of understanding, or a typo

■       They violate the principle of least privilege

○       Orphaned rules:

■       When the system or services are decommissioned but the rules for it are never removed

■       They present a security change since even if the rules are set to only one IP address, that IP may be re-assigned to someone else and re-activate permissions

■       This can unintentionally allow external access to an internal system

Video 12: Router configuration security:

●       Routers perform basic filtering

●       They often sit in front of network firewalls and can reduce the load for a firewall

●       They can do basic screening for packets

●       All routers can perform the same basic functionality - regardless of the syntax (so don’t memorize the syntax lol)

●       Just know about router filtering and how it differs from a firewall

●       Router access control lists:

○       Restrict network traffic

■       While ACL are most often used in a file management system they can also be used for networks in this case

○       Cisco devices support 2 types of access control lists:

■       Standard:

●       Perform filtering based upon source IP addresses

●       To create one use the access-list command

●       Syntax is access-list[number] [permit/deny]  [source ip][ip mask]

●       Example: access-list 1            deny                10.3.1.0.00.0.0.0.255

●       Standard lists are limiting because they only alow blunt source IP address blocking

■       Extended ACLs:

●       These allow for more complex filtering

●       They can block based on source and destination addresses, protocols, and ports

●       Router VS. Firewall:

○       Firewalls are purpose-specific and efficient at what they do

○       They have advanced rule capabilities with conditional and precise rules

○       Firewalls have more advanced security functionality and integration

●       Placing ACLs on routers reduces the burden on firewalls

●       Quality of service (QoS) controls prioritize critical network traffic

○       Such as live video traffic over routine file transfers 

Video 13: Switch configuration security:

●       Network administrators need to be concerned with switches

●       Maintaining the physical security of switches and other network gear is important

●       Routers are normally generally located in secure data centers or network rooms but switches can be all over the place

●       This is a big issue for security

●       An attack that gains physical access to a switch can take physical control of that portion of the network

●       VLAN security:

○       Can be used to increase security

○       Disable automatic trunk negotiation to prevent VLAN hopping attacks

○       Helps to isolate users from each other

○       Some good implementations for VLANs:

■       VLAN pruning:

●       Limit the unnecessary exposure of VANs by limiting the number of switches where they are trucked

●       Especially for sensitive VLANs

●       Implement the least privilege rule and only trunk VLANs to switches if the VLAN is needed

●       This is more work but reduces the impact of a compromised switch

■       VLAN Trunk Negotiation:

●       Some users may try to do VLAN hopping

○       An attack to switch from an authorized VLAN to an unauthorized one they would like to attack

○       mostly rely upon pretending to be a switch and asking the other switch to trunk vlans to the malicious users device

○       The counter for this depends on the device but by default, you should configure switches to deny the use of automatic VLAN trunk negotiation to limit the effectiveness of VLAN hopping attacks

■       Port security:

●       Sometimes attacks may try to disconnect an authorized device and replace it with an unauthorized malicious one

●       This will defend against that by limiting the mac addresses that are allowed on a switch port and requiring administrators to change out a device 

●       There are two different modes for this:

○       Static Port Security:

■       Administrators manually configure valid MAC addresses for each port

■       The most secure way to do it but also more time-consuming

○       Dynamic Port Security:

■       Also known as sticky mode

■       The switch memorizes the first MAC address they see on each port and limits access to that address

■       This makes the configuration much faster but can be risky if you have existing but unused active switch ports

■       DHCP Snooping:

●       Blocks malicious DHCP traffic

●       The switch will read the messages and make sure that they are properly formatted

●       Can block unauthorized or malformed packages 

Video 14: Communication and Networking Security:

●       Firewalls and network logs offer a rich source of security information

●       Since they are on the front lines they see suspicious traffic first

●       Firewall logs contain information on if each log was allowed or denied

●       The log entries contain details about attempted connections

●       They include timestamps and the relevant firewall rule that allowed or denied the connection

●       Uses for firewall logs:

○       Security incident investigation

■       These likely include the connections used by the attacker

■       Can be used to find out the method of attack and who the attacker was

○       Network issue troubleshooting

■       Can see denied logs

○       Anomalous activity detections:

●       Firewalls let you see the traffic that crosses the perimeter in both directions

○       Ingress filtering:

■       The traffic entering the network

○       Egress filtering:

■       The traffic exiting the network

■       This is important for bad activity from within our network

●       Full packet capture requires a large storage capacity

○       This is the most comprehensive approach but requires massive amounts of storage

○       Instead admins usually use Netflow data

●        Network flow data:

○       Captures connection details

○       Keeps records of network traffic but without the full contents

○       Contains the:

■       Source and destination systems

■       Source and destination ports

■       Timestamps

■       Amount of data transferred

■       Netflow data is quite useful but it doesn’t tell administrators what the communication does but it does identify who, when and how much

●       This is good for identifying security incidences

●       Security Information and Event Management (SIEM)

○       Log monitoring is boring :(

○       SIEM systems can automate a lot of it

○       They compile logs from:

■       Firewalls

■       Network devices

■       Servers

■       Applications

○       They preform detailed log analysis to identity possible security issues

○       SIEMs facilitate rapid analysis

■       For example if a user is suspected to be compromised you can pull all records of that user’s activity

■       This would be very difficult normally since these logs would be on several different devices normally

**Week 10 notes:**

**In-class notes:**

Review of the in class information since we missed week 9 in class:

●       We use public and private subnets

○       We use the private ones because we are running out of the public ones

●       We used to have class A, B, and C addresses

○       Originally the idea was that we would have parts for large and small consumers

○       With classful networking:

■       A:

●       is in the first half 0.0.0.0 to 127.255.255.255 space

●       Had a /8 CIDR

●       There were only 128 networks available in this range

●       Most went to the government or military

■       B:

●       From 128.0.0.0 to 191.255.255.255.255 with a /16 CIDR

●       For smaller but still large networks

●       There were 16,384 available networks

■       C:

●       These were for individual use

●       In the range of 192.0.0.0 to 223.255.255.255 with a /24 CIDR

■       The remainder were

●       class D (multicast):

○       Range of 224.0.0.0 to 239.255.255.255

○       /4 CIDR

●       class E (reserved)

○       240.0.0.0 to 255.255.255.255 with an undefined CIDR

●       We use ARP to send packets

○       A transitional protocol that translates IP address to MAC addresses

○       The MAC address comes from the manufacturer

■       Can be changed but should almost never be

○       The IP address is typically more in flux and is set by a system administrator or a DHCP

○       In the same subnet and we don’t know where to send a package we send out an ARP broadcast

■       The broadcast goes to everyone on the network and only one of them responds

■       The response will contain the mac

■       It will be remembered in the future

○       No routing happens here since we are staying in the same subnet

●       We can use the common ipcalc <address/CIDR> | grep ‘’

○       This will show the network configuration for the ip

●       The broadcast domain is the subnet

●       ip route

○       Shows the route table

○       In a traceroute it will show you each of the ip addresses it was passed through

○       The first will be the default route if going over the internet

●       The standard is to make the last address on the network the default route address

●       A router will have one more interface to get out of the network

○       A public IP

○       And a private IP

○       It also has a routing table and a default route and a mac address - all that

○       Complexity if often passed up to other servers for routing

●       The router is NOT the final destination it is the system that sends you off to the wider internet

●       Packet forwarding is essentially the act of routing

●       Firewalls:

○       Do not route needs to look at all packets

○       Needs to be in a place where they can see the packets

○       Usually very close to the router

○       Usually between the router and the network or the firewall is built into the router

○       If not in the router it is often in transparent mode as a bridge in the network

○       Should be able to see all traffic and be a participant in it

○       Can block or modify packets

○       Ingress:

■       Always interested in

■       The incoming traffic

■       Most attacks come from here

■       Default deny this

○       Egress

■       What is going out

■       Typically you can allow almost all or all

■       Typically don’t care about this as much

■       May want to block certain websites like at a school blocking social media

○       Stateless:

■       No memory - does not look beyond layer three

■       Only has:

●       Source address

●       Destination address

■       Network ACL is stateless

■       This one can first because we did not have the compute available to track complex communication

■       Faster

○       Stateful

■       Remembers traffic

■       Can consider TCP connections

■       So you could do something like block SYN and only accept SYN + ACK

■       This means no external connection requests only acknowledgements of your internal outbound requests

■       More processing

○       Firewalls may need actually computing power where routers are typically a little more basic

○       A firewall that operates at layer 4 is known as a packet filter

■       Only knows source and dest

○       Looking at the actual payload means a next-generation firewall

■       Has visibility into the application layer

■       Can see the content and consider that as well

■       Works at layer 7 - application layer

○       What does a firewall do when it sees bad packets

■       Blocking:

●       To drop the packet

●       Or to send a TCP reset or ICMP response to say the connection has been distributed

■       May also send notifications/emails to system admins if something big happens

■       Big routers that are accessed often typically silently discard packets to work fast

■       Options:

●       Drop

●       Block

●       Allow

○       Host Firewalls:

■       Installed on individual systems

■       Have different visibility into the traffic

■       Since we might not know things like the user that made the rest at the time then these can be useful since they keep the firewall on the device

■       Good for a device that may use a public network like a coffee shop

■       A host firewall is always there

○       Proxy servers:

■       Operates at a higher level of the OSI model

■       Can’t put all traffic through it for everything

■       Often for browsers or SSH clients

■       Instead of going directly to one sever it is forced through another

■       Can be coupled with a firewall so that nothing is allowed through the router directly

■       Can allow better logging for traffic

■       Can let you really dig into traffic

Zero trust:

●       We are trying to get away from the idea that we have one big barrier that defends everything

●       Instead of having access to the whole network once you get past the intrusion protection the internal network is harder to navigate

●       This protects against internal and external threats

●       This means that every single service is authenticated and protected

●       Can only really be achieved with TLS and HTTP connections

○       More often with HTTP

○       May be something like mfa or signed request requirements

●       Everything should be logged and seen

●       We still have firewalls but we don’t trust them

●       We don’t trust anything

NAT:

●       We are running out of IPs

●       Not everyone can have a public IP

●       Too many people - too many devices

●       There are public and private address space

●       There are 3 private addresses:

○       10.*

○       192.168.*

○       172.16.* to 17.31.*

●       When nat is enabled the internal network is the same but once it goes out the source IP address is replaced with the new source IP address

●       On the way back data will hit the route and the router will change it to the private IP

DNAT:

●       You have a rule that everything coming to a certain port gets forwarded to a certain private IP

●       This lets multiple private systems hide behind a public IP

●       What gets changed first in the DNAT process?

○       The destination address

●       Source NAT is different it changes the source address

●       Both are in use for different applications

Sniffing and Spoofing:

●       What is the main goal of sniffing (eavesdropping)?

○       Is it only done by attackers?

■       No it can be useful for system administrators who want to look through traffic

○       What are some points used for sniffing?

■       Wireshark, tcpdump, scapy

○       A hub is purely electrical but does not do anything but send out everything it receives on one port to all the ports

■       They look almost the same as a router

○       Unmanaged switches cannot be changed

○       Managed can be configured

■       These may have some layer 3 control

○       Switches track mac address

○        

●       A switch keeps track of what systems are connected to which ports

○       The switch has a table with the port and client

●       What is the main goal of Spoofing?

○       To fake information

○       How is spoofing used in a smurf attack?

■       The requesters return address for a request is replaced with the victims

Sniffing:

●       Not inherently malicious

●       Just reading packets

Spoofing:

●       Forging or changing data in packets

●       There is not a lot of protection for these

●       Smurf attacks spoof the source IP

○       Dones with pings

○       Changes the source to the victims IP as the source address

TCP:

![](file:///C:/Users/Markus/AppData/Local/Packages/oice_16_974fa576_32c1d314_110/AC/Temp/msohtmlclip1/01/clip_image062.gif)

The header:

●       ![](file:///C:/Users/Markus/AppData/Local/Packages/oice_16_974fa576_32c1d314_110/AC/Temp/msohtmlclip1/01/clip_image064.gif)

Flags:

●       SYN:

○       Request to connect

●       ACK

○       Understood request

●       FIN:

○       Request to disconnect

●       RST:

○       Request to resend

Nothing about tcp is secure :) this sucks

●       Examples of the numbers:

![](file:///C:/Users/Markus/AppData/Local/Packages/oice_16_974fa576_32c1d314_110/AC/Temp/msohtmlclip1/01/clip_image066.gif)

●       ← SEQ=1, ACK=377

●       → SEQ=377, ACK=271

●       We start at a different sequence number but it is not guessable or predictable

●       SYN Flood Attack:

○       A server can handle only so many connections

○       For example an attacker can send a SYN

○       The server sends SYN + ACK

○       The client sends nothing back

■       There may be a timeout but even then it will need to hold the connection

○       This will slow down the server but send no data

○       Does not require any effort on our end

○       This will fill up the server at some point

○       We use SYN cookies to defend against this:

■       Once the TCP queue is full it stores the half-open connections and stores them somewhere else

●       SYN Reset Attack

○       If we have enough information about a TCP connection we can use spoofing to pretend that we are part of the TCP connection

○       We can interrupt the connection with this

○       We need to know the IP on both sides and then the port

■       Then we bombard one of the sides with the RST and FIN to cut them off

![](file:///C:/Users/Markus/AppData/Local/Packages/oice_16_974fa576_32c1d314_110/AC/Temp/msohtmlclip1/01/clip_image068.gif)

TCP session Hijacking Attack:

●       What is keeping us from sending our own traffic in the connection

○       We need to sniff the connection

○       But then you can just send out a spoofed packet and continue the conversation

○       With TLS we can still hijack but everything is encrypted so you can’t send anything of use

●       Telnet communication is unsafe because of this

●       ![](file:///C:/Users/Markus/AppData/Local/Packages/oice_16_974fa576_32c1d314_110/AC/Temp/msohtmlclip1/01/clip_image070.gif)

●       IPsec can help with this

●       This lets us build a secure network

**Pre-class readings**

Video 1: Introducing TCP/IP

●       The TCP/IP protocol suite is at the heart of networking

●       They help make our networks function

●       TCP IP stands for Transmission Control Protocol / Internet Protocol

●       They are the main protocols that make up the network

●       The Internet Protocol:

○       Routes information across networks

○       A network layer protocol

○       Provide an addressing scheme

○       Deliver packets from source to destination

○       Serve as a network layer protocol - which supports other higher level protocols

●       The two main transport layer protocols are Transmission Control Protocol (TCP) and User Datagram protocol (UDP)

●       TCP:

○       Is a connection-oriented protocol

○       Guarantees delivery through acknowledgements from the destination system

○       Is widely used for critical applications

○       TCP goes through a three-way handshake

○       Certain flags mean certain things

○       TCP Flags:

■       SYN: opens a connection

■       FIN: closes a connection

■       ACK: used to acknowledge a syn or fin packet

○       TCP Handshake

■       Client sends a SYN to the thing they want to connect to (the server)

●       This says “hello please open a connection for me :)”

■       The server then sends back a SYN/ACK package to the client

●       This says “I understand, you can connect :)”

■       The client then sends back an ACK packet

●       This means “yayy hello :D”

■       Now the systems may begin exchanging data

●       UDP

○       does not use a connection protocol system

○       Lightweight

○       Doesn’t send acknowledgements or guarantee delivery

○       Is used for voice and video applications

○       When guaranteed is less than the speed

●       OSI model

○       Open Systems Interconnection

○       Describes 7 different layers that we use to communicate at

■       Layer 1: Physical Layer

●       Involves the use of sending bits

●       Uses Wires, radios, fiber optics

■       Layer 2: Data Link Layer

●       Transfers data between two nodes on the same physical network

■       Layer 3: Network layer

●       Expands outside to many different nodes

●       Internet Protocol (IP)

■       Layer 4: Transport Layer

●       TCP and UDP

●       Creates the connections and transfers data between nodes

■       Layer 5: Session layer

●       Manages the exchange between systems

■       Layer 6: Presentation Layer

●       Data translation and encryption

●       How to represent characters and perform encryption/decryption

■       Layer 7: Application layer

●       How users interact with data

●       Often over web browsers or other applications

○       The TCP network model:

■       An alternative implementation based on the TCP/IP stack development of the implementation of the OSI model

■       Comparisons between the TCP network model and the OSI model:

●       Layer 1 (Physical) and 2 (Data Link) of OSI are combined into the Network Interface Layer in the TCP model

●       The network layer is the Internet layer in TCP

●       The transport layer is the same in both

●       The top three layers of the OSI model (application, presentation, session) are a single application layer in the TCP model

![](file:///C:/Users/Markus/AppData/Local/Packages/oice_16_974fa576_32c1d314_110/AC/Temp/msohtmlclip1/01/clip_image072.gif)

●       We do not use these models very often in practice but they are useful in theory

Video 2: How TCP Works - Sequence Numbers

●        First a connection needs to be made

●       Look at the sequence number

●       Wireshark zeros out the first number with relative sequence numbers

○       Instead of showing the true value it will just start at zero

●       If we want the original number back right-click Transmission Control Protocol, then go to protocol preferences

○       Uncheck relative sequence numbers

●       The sequence number is used to track bits in each direction of the connection

●       This is the way the client or the server keeps track of what has been sent and acknowledged

○       A sequence of 1 + the length is the next starting sequence number

●       If you look at the following packet the following sequence number will be something larger like 446

○       These sequence numbers are based on the user and not shared

○       So the first packet from both is one, the second packet from both will increment that one individually

○       Each side only increments their own data

●       If there is an issue the next sequence packet will let us know to flag that

●       There are Dup ACK packets to help us recover from this

Video 3: How TCP Works - Acknowledgement Numbers

●       The Ack number will be the packet next sequence on the server

○       Example:

■       Say the client sends sequence 1 with 465 bits len - their ack number will be 1

■       Then the server will send back an ack number of 466, saying “hey I am good I got up to this point of the data you sent”

●       The sever will also sends it’s data here

■       The client will then get this data and send back an ACK with the acknowledgement number of the next sequence number for the packet the server just sent

○       When looking at an acknowledgement packet in wireshark you can see which packet is acknowledging a previous packet with a little check next to it

![](file:///C:/Users/Markus/AppData/Local/Packages/oice_16_974fa576_32c1d314_110/AC/Temp/msohtmlclip1/01/clip_image074.gif)

Video 4: Maintaining Network Availability

●       Maintaining network availability is a critical security goal

●       Flooding Attack:

○       Many denial of service attack flood the network until they are overwhelmed

■       SYN Floods

●       Fill connection state tables on firewalls with half-open connection entries

○       The attacker creates thousands of partially open TCP connections to a device by sending SYN packets but never sending the SYN ACK packet to complete the handshake

■       MAC Flooding:

●       Attackers fill switches MAC address table with many entires

●       Causing it to flood traffic on all ports as it forgets where packets are

●       Flood Guard Protection:

○       Can be used to protect network devices against these attacks and watch for them

○       Flood guard controls the number of open connections a source system can have

●       Port Security:

○       Enabling port security protects switches against MAC flooding attacks

●       Routing Loops:

○       Occur when there are multiple physical paths between network devices

○       And they mistakenly route in a redundant fashion (such as back and forth)

○       This will fill up the network

○       This condition is known as a broadcast storm

○       The solution to this is to use protocols that include route protection

■       Such as Spanning Tree Protocol (STP):

●       Allow only strict logical connections

●       The network still benefits from redundant links since if the default link breaks it can fall over to another

●       Uses routing status messages called Bridge Protocol Data Units or BPDU

●       If an attacker is able to spoof bpdus they can cripple the network

●       BPDU Guard protects against these attacks

Video 5: Denial of service attacks

●       Remidner of CIA triad:

○       Confidentiality

○       Integrity

○       Availability

●       The most common motivation of an attack

○       data theft (such as credit card numbers) - Confidentiality

○       Website Defacement in an unauthorized way - Integrity

○       Denial of service (DoS) - Availability

●       Denial of service attacks:

○       Makes it unavailable to real users

○       Sends a large number of requests to a server that overwhelm the system

○       It is difficult to distinguish from real traffic (if done well)

●       Limitations of a DoS attack:

○       Requires a massive amount of bandwidth

○       Easy to block (if it is coming from one IP address)

●       Distributed Denial of Service (DDoS)

○       A denial of service attack that leverages a botnet to overwhelm a target

○       Since the attacks come from all over - and often from real computers - they are hard to block

●       Example:

○       Ping Command:

■       Sends an echo request to and from a system over ICMP

○       Smurf Attack:

■       An attacker sends a ping to the broadcast address of third-party servers with a forged source address

■       The source address is the IP of the Victim’s server

■       The then send the victim the echo reply

![](file:///C:/Users/Markus/AppData/Local/Packages/oice_16_974fa576_32c1d314_110/AC/Temp/msohtmlclip1/01/clip_image076.gif)

●       The victim then becomes overwhelmed with traffic from all over the place

●       This is known as an amplified attack

●       In a basic DDoS attack bandwidth is a limiting factor

●       In an application attack, the attacker deliberately chooses requests that have very large responses

○       This way the attackers requests are small but the victims replies are large

![](file:///C:/Users/Markus/AppData/Local/Packages/oice_16_974fa576_32c1d314_110/AC/Temp/msohtmlclip1/01/clip_image078.gif)

○       Variations on the smurf attack have well-crafted requests that have very large responses

●       Amplification Factor

○       The degree to which the attacker increase in size

○       Reply / Request = Amplification

○       For example 512 / 64 = 8

■       8 times as much traffic goes to the victims then was used from the attacker

●       DoS Variants:

○       Network attacks

○       Application attacks

●       Defending against DDoS attacks is often done by service providers

●       Defending means understanding them

●       There should be background checks for suspicious traffic

Video 6: Eavesdropping Attacks

●       If an attack gains physical or logical access to a network it may be able to alter or listen to communications on the network

●       Rely on a compromised communication path

○       Network device tapping

○       DNS poisoning

○       ARP poisoning

●       Can trick a system into sending information to an attacker rather than the intended target

●       Rember that network traffic over the web travels far and every node it passes through is a point that an attack may get access to the data that is being sent

●       Encryption - such as with HTTPS protects these communications from being listened to

●       Since simple eavesdropping can be blocked - a man in the middle can be used

○       In this attack, the attack tricks the sending system into accessing its resource

■       This can be done with DNS and APR poisoning

○       Now instead of establishing a connection with a real site, the user connects to the attack

○       The attacker then connects to the real server

○       The attacker then authenticates to the real server and the attacker acts as a rely to the client

○       Now the attacker can view all the communications between the user and the server

●       Man-in-the-browser attacks

○       exploit flaws in browsers and browser plugins

●       Man in the middle and man in the browser are also called on path attacks

○       Since they are on the path between the user and the service

●       Reply Attacks:

○       Uses previously captured data - such as an encrypted authentication token - to create a separate connection to a server that is authenticated but does not involve the real end user

○       If the attack can resend the authentication sequence without noticing that it is being replayed the attacker can use those credentials for their own purposes

○       In a replay attack, the attacker actually can’t see the credentials but has the encoded version of them available

●       Preventing Replay Attacks

○       Include unique characteristics in the communication:

■       A session token

■       Timestamps

○       Each session should have a limited lifespan token

○       When the attack tries to replay it - it should be invalid

■       Replay attacks will still succeed during the time window but they will be limited in time

●       SSL stripping

○       A variation on eavesdropping

○       Tricks the user's browser into defaulting to unencrypted communications

○       This lets the data be spied on

Video 7: Network Sniffing

●       Uses a packet sniffer, network monitor, or analyzer

●       The sniffer captures the packets and deciphers the bits

●       Then displays the field values in the packet

●       Can help with troubleshooting but can be used for evil

●       Reconnaissance technique:

○       This can be done on a wired or wireless network

○       If the traffic is in plaintext and not encrypted while in transit the contents can be read

○       If the attacker has physical access they can tap into the data stream to see even more of the traffic

●       Examples of packet sniffing for unencrypted data:

○       Can be used to read SQL commands between the user and server DB

○       Can be used to see search requests that have broadcast network ids

■       Disable SSID broadcasting

○       A telnet is a remote access system, if unencrypted we could follow the TCP stream and you can see the username and password in the telnet request

●       All connections or transitions should be encrypted

●       packet/network sniffing can be used to leak data

●       To reduce this thread encrypt the data and secure your devices

Video 8: Network Sniffing:

●       The most time-consuming part is going through the data

●       Going through an hour’s worth of traffic or at a certain time can be inaccurate

●       Sniffing results can be impacted by the network segment

○       Limited visibility

○       Is the customer has implemented traffic all over in different places you may miss important results

■       Confirm the sniffer location

●       Before you sniff:

○       Review the network diagrams

○       Determine appropriate locations to sniff

○       Discuss what normal activity would be

○       Determine start and stop times for most interesting traffic

●       Analyzing your results

○       Active device and identifying information

■       Such as services or protocols - especially banded or insecure services

■       Look for unencrypted data transmissions

●       Sniffer locations:

○       At the perimeter of the network

■       What is going in and coming out?

○       Behind firewalls

○       Behind IDSs/IPSs

○       In front of sensitive systems/apps

○       Encrypt network segments (required by policy)

Video 9: the OSI model:

●       Sniffing or Packet Analysis

○       Requires a solid understanding of encapsulation

○       Protocols such as TCP, IP, and DNS

●       OSI Model

○       Standardizes the functions of data transformation

○       Breaks down into layers

○       Outlines how data is encapsulated over the network by the network card

●       OSI Model:

●       ![](file:///C:/Users/Markus/AppData/Local/Packages/oice_16_974fa576_32c1d314_110/AC/Temp/msohtmlclip1/01/clip_image080.gif)

○       7: the application layer

■       Use protocols like HTTP, FTP, and SMTP

■       Initiate contact with the network

■       (Protocol Data Unit) PDU: Data

○       6: Presentation

■       About formats, optics, compression, and encapsulation

■       PDU: Data

○       5: Session

■       Initiates, maintains, and tears down sessions

■       PDU: Data

○       4: Transport

■       Transports data

■       Protocols: TCP, UDP

■       PDU: Segment

■       Address: Port - associated with an application in use

○       3: Network

■       Addressing and routing

■       Protocols: IP, ICMP

■       PDU: Packet

■       Address: IP

○       2: Data Link

■       Frame formation

■       Protocols: Ethernet II

■       PDU: Frame

■       Address IP

○       Note that the ARP protocol is sort of between layer

○       1: Physical

■       Data is transmitted on the physical media

■       Uses bits

●       Frame:

●       ![](file:///C:/Users/Markus/AppData/Local/Packages/oice_16_974fa576_32c1d314_110/AC/Temp/msohtmlclip1/01/clip_image082.gif)

○       FCS: Frame check sequence

○       Data

○       TCP/UDP Header

■       Segment with PORT address

○       IP Header

■       Packet with IP address

○       Frame Header

■       Frame with MAC Address

![](file:///C:/Users/Markus/AppData/Local/Packages/oice_16_974fa576_32c1d314_110/AC/Temp/msohtmlclip1/01/clip_image084.gif)

Video 10: Network Symptoms

●       Monitor your network for symptoms of security incidents

●       Network traffic is a common source of valuable information

●       Perform automated and manual reviews of the network data sources

●       Network-related indicators of compromise

○       Network consumptions:

■       Look for traffic spikes

■       Or heavy or extremely low bandwidth

■       Bandwidth records can help rule out data exfiltration

●       For example look for stolen packets that might indicate data being taken

○       Irregular Peer-to-Peer Traffic

■       This may indicate a compromised system attacked another system

●       This is known as lateral traffic

○       Beaconing:

■       May indicate malware command and control traffic

■       The results of an infected computer reporting back their compromised data

■       Look for evil ips or malware-style packets

○       Scanning:

■       May indicate a compromised system searching for other targets

■       Scanning for many ports or IPs at once this may be the sign of that

○       Watch out for common protocols over non-standard ports

■       Someone may be trying to bypass port scanning rules

●       Monitor your network from the presence of rogue devices

**Week 11 notes:**

In class notes:

VPNs:

●       Can be used to access

●       Topologies:

○       Host to host:

■       One host talks to another host over the VPN

○       Host to network:

■       Allows hosts to talk to a private network

○       Network to network

■       Networks connect to all resources

●       All connections are encrypted

●       This lets you get internal access to systems

●       This will let you connect from outside of the network

●       When a packet goes through a VPN we can add another IP header in front of this packet

○       The original data will have a new header and also encrypt the data and provide authenticated data

■       It is singed for authentication

●       VPN steps:

○       authenticate

■       Both sides authenticate each other

■       This could be a key exchange, passphrase

●       All we see in wireshare we see the TCP type packets

●       This is the original data

●       Weaknesses in the transferring protocol can be covered up by a VPN

●       When connecting to a VPN there is an IP that the client will have access to

○       Network configuration where a virtual adapter is configured and routing rules are set up

●       Things are encrypted on one side and the decrypted on the other

●       Two common protocols:

○       IPSec

■       The headers that were mentioned before have to do with this

■       All layer 3

■       Encryption is at layer 3

●       Could be a ping, DHCP request, etc

■       IP/TCP/payload all get encrypted and you can’t actually see packet details when listening in

■       The protocol used for key exchange is ISAKMP

■       Since it is all in TCP packets it can sometimes be blocked

○       TLS based

■       A newer alternative

■       Instead of using IP/ESP packets we send the data packets and wrap them in another TLS packet

■       It will look very similar to a normal TLS packet but it is full of secrets

■       These are x509 certs

■       The payload will be in an IP TCP packet

■       In IP sec there isn’t really a client server concept

■       There are peers with both sides

●       There is the same configuration for both clients

●       Transport mode is the most efficient way of transferring data between two hosts

●       The goal for any mode is the same, keep data safe and obscure where you are

●       We can also use a VPN to get out of a network that we use to get in one

●       But the VPN needs to be able to get out

DNS:

●       DNS does not have one centralized source

●       Authoritative means that a DNS server is responsible for that information

○       Other DNS servers may also have this information but they are not responsible for maintaining it

●       DNS needs to fast, which makes it complicated

○       Some store the information - authoriatively

○       Other store responses and requests in cache so they can respond faster

●       Lots of caching in DNS so we don’t waste time

●       But because DNS is so distributed it is hard to be fast

●       You start at the root server and work down to the authoritative servers

○       The root domain goes to the .com server

○       The .com server goes to the google server

○       The google.com will point you to [www.google.com](http://www.google.com)

○       The final zone would be an A record (an IP) a zone for www.google.com

○       This is an iterative request

●       A recursive request means it does not really care where the data comes from but asks each other for the DNS and accepts the first one without going through the whole DNS resolution, just accepts the cache

●       If there is not another DNS server that is non-authoritative, then we need to do the iterative response

DNS Spoofing:

●       We can spoof all day long >:)

●       There are two types

○       The basic level is just dns spoofing

■       We refer request against the server

■       So the client makes a request

■       And we send a response with an IP address that we choose

■       We re-direct them to any other IP address that we want

■       We are only effecting one client in this case but we can sniff the requests

■       We need a little information for this

●       Which is reflected in the original request

●       We need to copy some data from the request to the response

○       Cache poisoning:

■       You are not sending the requests to the clients but rather to the server

■       This affects the traffic going from the client to the server

■       Cache poisoning can be used to change the content of the cache

■       This is very effective for interrupting normal traffic to a new site

■       Cache is server-side

■       Linux does not really have a cache on the client side but windows does

●       Linux uses a cache for servers though

●       DNS Denial of service:

○       If we didn’t have root DNS servers everything would fail

○       So these are common targets

○       But is not one system behind these IPs

○       It is almost impossible to block denial of service attacks on these systems

●       DNS amplification DoS attack

○       The request is smaller than the response

○       We can spoof the IP of the DNS and change where traffic will go

●       DNS spoofing countermeasures:

○       We use DNSSEC

■       Mostly used higher up on the hierarchy

■       Essentially DNSSEC by signing each zone with a digital signature

■       We get the record and a signature for the record

○       We use UDP because it is fast to run DNS over

○       We can use TLS but it is not common

○        

Video 1: DNS

●       Computers use IP addresses to communicate over the network - humans have trouble with them

●       They are hard to memorize

●       DNS allows people to use easily recognizable names online for servers

○       Such as [www.linkdin.com](http://www.linkdin.com) → 108.174.11.1

●       DNS operates over UDP port 53

●       DNS Resolution

○       User types of the name of the website into the browser

○       Computer sends a DNS query to the local DNS server asking it for the IP associated with that name

○       If the DNS server knows the name, it will respond with that IP address

○       The computer contacts the website using that IP address

●       DNS is a hierarchical system and if the DNS server does not know the IP it will ask another to determine the correct

○       Organizations designate servers that are authoritative for their domains

●       When a local DNS server needs to perform a lookup it asks a series of questions to determine the answer from an authoritative search

●       We can use the dig command to lookup the IP address for a website and see the process for finding the IP

○       In the Answer section, we can see the ip

○       In the query time, we can see the server that answered this question

●       We can also do **dig @8.8.8.8 linkedin.com**

○       What this command will do is ask the google server for the IP address for linkedin.com

○       You can see in the answer it will be the same results

○       But the 8.8.8.8 server will respond

●       Some content filters alter the DNS query results

○       This can protect users from accessing undesirable websites

○       But you will need also to block outbound DNS requests to other servers

●       DNSSEC

○       Adds digital signatures to DNS

○       Networks depend on proper DNS records and we need to keep them secure

○       They are often a point of attack (called DNS poising attacks)

■       The DNSSEC adds digital signatures to DNS

■       This shows that they are authentic records

Video 2: DNS Attack:

●       Domain Name System (DNS)

○       A service that translates common domain names into IP addresses for the purpose of network routing

●       DNS uses a Hierarchical DNS lookup system

○       The initial request goes to the server on the clients network

○       It then asks a series of other servers until it finds the one with the correct answer

○       For example if you look up [www.wikipedia.org](http://www.wikipedia.org)

■       It will first look up the root nameserver, that server may say “go ask the .org server”

■       The .org nameserver will then say “go ask the wikipedia.org server”

■       This server will then know the name and send back the reply

■       ![](file:///C:/Users/Markus/AppData/Local/Packages/oice_16_974fa576_32c1d314_110/AC/Temp/msohtmlclip1/01/clip_image086.gif)

●       DNS poising will disrupt this process by inserting incorrect DNS records at any point along the hierarchy

●       The attacker redirects traffic to the attackers system

●       The system will make it look like they have the right address and capture victims in their server

●       Well-executed attacks will capture all traffic between the system

●       Preventing the system from noticing the man in the middle attack

●       Typosquatting:

○       An attack that depends upon people making simple typing mistakes

○       Attacks will register 100s of variations of common sites and capture those requests

○       Examples:

■       ![](file:///C:/Users/Markus/AppData/Local/Packages/oice_16_974fa576_32c1d314_110/AC/Temp/msohtmlclip1/01/clip_image088.gif)

●       Domain hijacking

○       An attack where the attacker gains control of an organization’s domain registration

○       This may be done with social engineering

○       Conducting a pre-texting attack

○       Or obtaining the account information (username/password) for the administrator

●       URL redirection:

○       Attackers place redirects on a trusted site to the content hosted on a malicious site

○       Or by compromising a legitimate server

●       Domain reputation

○       Threat intelligence capability that scores domains as either benign or malicious

○       Many organizations integrate it into intrusion prevention and other security controls

Video 3: Caching

●       Caching is typically great

●       Often done by servers to keep things moving fast and not need stuff to be re-downloaded once they have been downloaded once

●       Save bandwidth

●       Proxy servers are also caching

○       The images movies and data come through the proxy and the proxy also holds on to it

○       If someone else needs the data it will be faster to transmit it

○       This saves bandwidth for the proxy

●       DNS uses something similar

○       Caching examples:

■       OS X server caching

■       Proxy server caching

○       DNS Caching server

■       Asking for say, [www.apple.com](http://www.apple.com)

■       The resolver proceeds as usual and makes a request for the dns name to IP

■       If the DNS server has a cache it will send that and be very fast

●       If it does not it will do a recursive query for the name, which may take time

●       When a recursive request goes out from the name server the responses are also called referral

●       This come back and saved by the server that made that request in the first place

●       The name server holds the location of everything it encounters along the way

●       It also saves everything that helped it come to the answer

○       That means that asking for [www.apple.com](http://www.apple.com) will mean the server learned where the com and apple name servers as well as the www server within that domain

○       It can easily provide another client the exact location of the [www.apple.com](http://www.apple.come) server and shortcut the apple.com name (like store.apple.com now)

●       Caching only DNS servers can be configured to contain

○       No local zone information

○       Recursion enabled

○       Caching (storing) results for later locally

Video 4: Caching and Forgery:

●       Networks rely on DNS to provide accurate information on hostname to IP resolution

●       Otherwise, we might end up on the wrong site

●       Same goes for email - if you try to send an email to the wrong site you will get a bounce back saying it can not be found

●       When configuring a DNS server:

○       Correct configuration is essential

○       Misconfiguration can lead to devastating problems

●       DNS can be compromised by poisoning the cache

○       The cache is the temporary holding area for data

○       Designed to speed up common requests and responses

○       Websites use them

○       Each system has a cache (most of the time)

■       Use the command **ipconfig /displaydns** to view them

■       Time to live in a cache is the amount of seconds it is valid for

●       This is usually about 7 to 1 day

○       Cache poisoning

■       Inserting bogus information into a DNS server’s cache

■       Achieved by sending a spoofed IP address

■       Places results in the cache

■       Used until TTL expires

■       All local users will be affected

■       ISP cache poisoning will have widespread effects

Video 5: Deception Technologies

●       Deception technologies fool intruders

●       They allow analysts to stay one step ahead of attackers

●       It can be difficult to distinguish attacks from legitimate activity

●       Darknets:

○       are designed to help with distinguishing attacks

○       Some of the normal IP address space may be set aside for the darknet space

○       No legitimate services use those addresses

○       Therefore if a monitoring system detects any traffic headed to those addresses it is very likely that it is an attack

■       Or maybe a miss configured system

●       Honeyfiles:

○       False stores of sensitive information

○       They are made to look like real data but instead contain garbage data

○       Or intentional misinformation

●       Honeypots:

○       Systems designed to attract and trap attackers

○       May have names that indicate they are valuable or even contain honeyfiles

○       They are created to fool an attacker into accessing them but will really alert admins and may even trigger an immediate security response

●       Honeynets:

○       Large scale deployments of honeypots on the same network

●       DNS sinkhole

○       When systems are compromised by malware and joined to a botnet they are configured with command and control servers

○       When security analysis identifies these command and control servers they can make sinkholes for those addresses

○       To do this they feed false information to their own DNS servers and tell them that it is authoritative for the malicious domain and re-routing traffic handing to it to alert others that the system was compromised

■       These are actually the same conditions as a DNS poisoning attack but for the greater good on their own users

Video 6: Attack layer 2

●       Attacks can also come from layer 2 of the OSI model (the data layer)

●       ARP works at this layer and works kinda similar to DNS

●       Only instead of translating common domain names it translates IP to MAC on a local network

●       These hardware MAC addresses are built to the machine

●       ARP poisoning:

○       Provides false information in response to arp requests

○       However it is contained on one local network

○       ![](file:///C:/Users/Markus/AppData/Local/Packages/oice_16_974fa576_32c1d314_110/AC/Temp/msohtmlclip1/01/clip_image090.gif)

○       Normally a system sends all traffic to a gateway device

○       If the ARP is compromised all traffic may be sent to a different device

■       This could be a malicious user who is engaging in a man-in-the-middle attack 

●       MAC flooding

○       Switches maintain MAC address tables in memory

○       Also at layer 2

○       One of the responsibilities of a network switch is to keep track of the mac addresses of the systems connected to each port on that switch

■       This is stored on a mac address table on the switch in memory

○       MAC flooding attacks attempt to overwhelm this table so it will discard old entities in exchange for new ones

○       Attackers do this by rapidly cycling through addresses on a single system

○       Once flooded the switch then receives traffic bound for a new mac port but will not have the address stored anymore

■       The switch will then broadcast the traffic on all ports

■       This will let an eavesdropper listen in on this communication

■       Port security limits the number of mac addresses that can be used on a single switch port and will block mac flooding attacks

Video 7: VPNs and VPN concentrators

●       VPNs provide 2 imporatint security functions to IT infrastructure

○       Site-to-site VPNs

■       Connect remote offices to each other and headquarters

○       Remote access VPNs

■       Provide remote workers with a way to connect back to the organizations network

●       VPNs work by creating a virtual tunnel between two systems over the internet

●       Everything is encrypted on one end and decrypted on the other

●       From the users perspective the traffic is normal but anyone eaves dropping on it would not be able to read it (even on http!)

●       VPN requires an endpoint to accept the connections

●       These devices can actually server as endpoints for connection:

○       Firewalls

○       Routers

○       Server

○       Or a dedicated VPN concentrator (these devices are very efficient for managing connections)

○       If you don’t have a high volume of VPN traffic you can use one of the others but it will effect those systems

●       VPN traffic requires resource-intensive encryption

●       This may need specialized hardware

●       VPN protocols:

○       IPsec:

■       One of the OGs

■       Short for Internet Protocol security

■       Used to create the encrypted tunnels

■       Works at the network layer of the OSI model (Layer 3)

■       You can also run the layer 2 tunnelling protocol (L2TP) over an IPsec connection

■       These provide secure transport

■       But they are difficult to configure and may be blocked by firewalls

■       Because of this IPsec is often saved for static site to site VPN tunnels

●       Remote user VPNs now often rely on SSL or TLS that works at the application layer

●       These VPNs work on any system over the web browser and use port 443 for communications

○       This is typically allowed on most firewalls

●       HTML5 VPNs work entirely within the web browser without a presence on the internal network

●       Instead of using the web server in a proxying role

●       When implementing a remote access VPN administrators must choose two different tunneling approaches

○       Full-tunnel VPN

■       All network traffic leaving the connected device is routed through the VPN tunnel regardless of its final destination

■       This includes all traffic even browsing not just organizational traffic

○       Split-tunneling VPN

■       Only traffic destined for the corporate network is sent through the VPN tunnel

■       Other traffic is routed directly over the internet

■       The routing policy is set by the VPN administrator

■       In most cases the routing policy is set by the VPN administer

■       Then something like corporate traffic will travel over the vpn while normal internet traffic will go to the normal destination directly

■       This reduces the burden on VPNs

■       Split tunnel VPN is NOT recommended

■       It has a false sense of security

■       Users have trouble understanding the difference and think they are safe

●       Always on VPN

○       This is a newer system where all cooperate devices are configured to connect automatically

○       This means it is harder to not be connected and traffic is safer

Video 8: How VPNs work

●       IP networking lets information travel from networks

●       If we need to access resources on a protected network where the hosts are not exposed to the internet then we need a different approach

○       By definition, private networks cannot talk over the internet unless there is a router

●       It is a pretty bad idea to make resources directly accessible in most cases

●       To access these hosts the traffic needs to come from the same protected network

●       To do this we need to cheat a little bit and set up a connection that is attached to both public and private networks and let traffic travel through it

●       This is a virtual network that is private over the public internet

○       That’s a VPN baby

●       “Private” in VPN refers to the network topology

●       It is not a public network that other clients can join 

●       Private does not refer to data privacy or security

○       Just to the topology of the virtual network

●       In fact you can have a vpn with no data security

○       Don’t do that though :P

●       VPNs work on the principles of routing, bridging, and encapsulation

○       Routing:

■       Can be used to send network packets and determine where they go

■       Usually, we have a default route so anything not intended for the internal system will go there by default

■       This will send it out to the internet in general

■       Using a VPN is like plugging in a network adapter on your computer to the VPN server you are connecting to, only across the internet

■       A layer 3 VPN creates a new route for a virtual network adapter each time a new client is added

○       Bridging:

■       Other types of VPNs use layer 2

■       Instead of routing data over network devices is behaves as though the devices are physically connected to the same network

○       Encapsulation:

■       Information is wrapped inside of packets that can travel between networks

■       That means network traffic that would normally not be able to travel over two networks get wrapped in packets that can travel between networks

■       Local traffic is encapsulated to travel between client and server

■       Those packets are then sent though the tunnel

■       The VPN software then unwrapped and sets them free on the other side

Video 9: SSH

●       While not generally thought of as a VPN protocol, SSH forwarding allows you to do similar things

○       Allows you to create a secure connection between server and client

○       Allows for port forwarding

○       Uses TCP 22 but can use other ports

●       Can forward a local port to a remote port (connect localhost:8080 to server:80)

●       Or they can set up a local port that uses a proxy that lets them send traffic through that

○       Either case, SSH provides a safe way to communicate the traffic

●       SSH does not create network interfaces

●       The endpoint it provides is port on the machine not a separate IP

●       Even though people see using an SSH connection as a “poor mans vpn” there is nothing at all wrong with using it this way

●       Though it can be disabled - SSH forwarding is available pretty much anywhere SSH is

●       It is very widespread

●       It can also be difficult to block without blocking regular SSH

●       So if you have an SSH connection and only need access to specific ports on specific machines - an SSH tunnel may be faster and easier than an VPN with less setup

Video 10: Forwarding an SSH connection

●       SSH is commonly used for many clients on different OSs

●       Example of SSH Forwarding

○       A webserver runs on port 80 on a private network but a firewall is blocking it

○       So we SSH to the server and then forward a port on the protected machine to the system

○       Then we can make a tunnel that will send the traffic back and forth from that port to the remote server port

![](file:///C:/Users/Markus/AppData/Local/Packages/oice_16_974fa576_32c1d314_110/AC/Temp/msohtmlclip1/01/clip_image092.gif)

○       We can set this up with the -L option for ssh

○       Example:

■       **ssh -L 8080:10.3.1.4:80 user@12.34.56.78**

■       The syntax is ssh -L <localport>:<remote forward ip address>:<remote port> username@<remote access ip>

○       This opens up port 8080 locally and connects it to 80 on the remote forward system

○       Note that the forwarded system is NOT the one you are connected to

○       The one you connect to is the middleman that handles the traffic between the two

○       Now as long as the tunnel is open you can go to localhost:8080 and see the stuff hosted on the remote port 80

○       You can open another tunnel as well on another port but you can’t run commands on the forwarded system

○       You can also tell SSH to run in the background for things like this with the command **ssh -f -N -L 8080:10.3.1.4:80 user@host**

■       -f: fork into the background

■       -N: says not to run a command

○       Now you will not be but on a new command prompt and the forwarding will still be there

○       When done with the tunnel find the process and kill it

■       **ps -x | grep ssh**

●       Find the one without the controlling terminal

■       **kill <process id>**

○       Now the connection will be closed and dead :D

**Previous Quizzes:**

**Quiz 1:**

What is the main objective of information security? (select the three that best apply)

●       Availability

●       Confidentiality

●       Integrity

Encryption protects ____, whereas hashing helps protect ____.

●       Confidentiality, integrity

What cybersecurity goal protects data in an organization from unauthorized modification?

●       Integrity

Which one of the following security controls provides the best ability to detect integrity issues?

●       Hashing

Denial of service threats compromises ____ whereas tampering threats compromise ____ of a system

●       Availability, integrity

Applying access controls to ensure that employees in an organization are not able to read files that are not directly related to their job functions enforces which component of the CIA triad?

●       Confidentiality

__white__ hat attackers attempt to uncover system vulnerabilities in order to improve the security level of these systems

Data breaches violate which principle of cybersecurity?

●       Confidentiality

One challenge facing security professionals is that they must design a control environment that manages the risks facing the organization, but balances security against other business considerations

●       True

While searching for security vulnerabilities, Adam gained unauthorized access to a company’s network and left the message, “Your security is flawed”. Adam is a ____.

●       Gray hat hacker

Which type of threat actor is normally the most sophisticated?

●       APT

**Quiz 2:**

What type of malware delivers its payload only after certain conditions are met, such as a specific date and time occurring?

●       Logic bombs

Who runs the command and control systems over legitimate systems the are compromised?

●       The botmaster

Your computer has been infected and is sending out traffic to a targeted system upon receiving a command from a botmaster. What condition is your computer currently in?

●       It has become a zombie

Why does a malware have the ability to change its binary file as it propagates?

●       So the malware can defeat traditional signature-based detection

Cryptolocker, which encrypts valuable data and prevents user’s access until a payment in cryptocurrency format is made, is an example of _____.

●        Ransomware

What type of phishing attack focuses specifically on senior executives of a targeted organization?

●       Whaling

What type of malware presentation is most effective against known malware?

●       Signature detection

A ____ virus implements techniques designed to prevent disassembly and debugging while a ____ virus can change form or signature each time it is executed to avoid detection

●       Armoured, polymorphic

Which one of the following types of malware can spread without any user interaction?

●       Worm

Which of the following statements is true about a zero-day exploit?

●       It is code written to take advantage of a software flaw unknown to its vendor

Botnets could be used in situations where computing power, storage, or network connectivity is a key resource e.g. performing brute force attacks against passwords

●       True

Ransomware, infiltrates a system and uses a distributed network to create a DDoS attack

●       False

Which type of malware propagates itself through a network, without requiring any user action to move from one target to the next

●       Worm

How can you recover the encryption key of a malware and decrypt it to reveal the code?

●       Through reverse engineering

A malicious program that might be disguised as free software, videos, or music, or seemingly legitimate advertisements is called a

●       trojan

**Quiz 3:**

To prioritize security incidents, organizations should develop and assign severity ratings based on the nature and scope of an incident's potential impact

●       True

What type of backup includes only those files that have changed since the most recent full backup?

●       Differential

What type of backup contains only those files that have changed since the most recent full or incremental backup:

●       Incremental

Which component of a syslog message contains the timestamp?

●       Header

Differential backups use more storage than an incremental backup, however it is faster to recover since it only needs 2 files: the full backup, and the more recent differential backup

●       True

You should rebuild any system that may have been compromised during a security incident

●       True

What is the first responder’s highest priority after noticing a security incident?

●       Containing the damage by isolating affected systems

What are some suggested criteria for evaluating containment strategies?

●       Damage potential

●       Evidence preservation

●       Service availability

●       Expected effectiveness

It is always useful to have a rule on the security indecent and event management (SIEM) system that detects large outbound data flowing from your organization to any destination.

●       False

SIEMs correlate security information received from other devices

●       True

SIEMs act as a central secure collection point for all log entries and also correlate security information received from other devices to detect patterns of potential malicious activity

●       True

All adverse security events are considered security incidents

●       False

What are some sources network analysts can find data to identify and analyze a potential security incident?

●       IDS/IPS

●       Authentication systems

●       Firewalls

●       Vulnerability scanners

●       Integrity monitors

It takes a longer time to restore from incremental backups since the “chain” of backup files must be merged together, but the trade-off is that incremental backups consume less space than differential backups

●       True

When assessing impacts of an incident on data availability, it is important to consider recovery time from a potential downtime

●       True

**Quiz 4:**

Encryption protects ____, whereas hashing helps protect _____.

●       Confidentiality, integrity

In __symmetric__ cryptography we need a key for each two people that want to communicate

In __asymmetric__ cryptography we only need two keys for each user

In __symmetric__ cryptography algorithms, the encryption and decryption operations use the same key

How are public and private key of a key pair used in asymmetric cryptography?

●       Anything that is encrypted with one key from a key pair can be decrypted with the other key from that same pair

What is used to create a digital signature?

●       Encrypting the hash value of the message with the sender’s private key

Which hash function is not considered secure? (select all that applies)

●       SHA1

●       MD5

Increasing the length of the encryption key is the simplest way to take an existing cipher and make it stronger

●       True

Select all that’s true about RSA

●       To generate an encryption message, the recipient’s public key is used

●       RSA keys are made using prime numbers

Select all that is true about a secure cryptography hash function:

●       It is collision-resistant

●       It’s one way

●       Output is fixed-length, regardless of the input’s size

__asymmetric__ cryptography is slower, but it solves our problem of creating keys for larger organizations

In an encryption algorithm, the input(s) will be ___ and the outputs will be ____.

●       Plaintext and encryption key - ciphertext

Hash functions are used with asymmetric cryptography for both digital signatures and technologies that depend upon digital signatures, such as digital certificates

●       True

It is important to have a life cycle approach to cryptography since as cryptographic algorithms age, they often become insecure

●       True

As the encryption key gets longer the information will be more secure, however, the performance of the algorithm goes down

●       True

Hashing uses a cryptographic key to covert plaintext into ciphertext:

●       False

What should the receiver of a digital signature do to confirm the integrity and authentication of the received message?

●       Decrypt the digital signature with the sender’s public key and compare the results with hash of received message

Many file download websites publish hash values for each file. After you have downloaded the file you can re-compute the hash and compare the result with the published hash. This is using hash functions for ____.

●       Integrity verification

**Quiz 5:**

Assume that a common name of a certificate is *.linkdin.com which domain can not use this certificate?

●       www.mail.linkedin.com

What is needed to verify a certificate issued by a CA?

●       CA’s public key

Which certificate provides the lowest level of trust?

●       Domain validation (DV)

What’s the first step Alice needs to do to get a new digital certificate?

●       Generate a certificate signing request

How can you verify a digital certificate you received from Alice?

●       Checking that the CA’s digital signature is on the certificate is valid

What standard governs the structure and content of digital certificates?

●       X.509

What is the most effective method of revoking digital certificates?

●       Online Certificate Status Protocol

What is not true about certificate pinning?

●       It is used to create a false certificate for a site

Who provides the digital signature on a digital certificate?

●       Certificate authority

If Alice wants to obtain a new digital certificate, what should be included in her certificate signing request (CSR)?

●       Alice’s public key, as well as Alice’s name and other identifying information

__wildcard__ certificates are commonly used for load balancers and other devices that must match many different domain names

If the certificate owner’s private key is compromised, the owner needs a way to revoke the digital certificate, so that it can’t be used to impersonate the owner later on

●       True

What technology allows web servers to attach an OCSP validation to the certificate they send to users?

●       Certificate stapling

The Subject Alternative Name or SAN attribute on an X.509 certificate lists all other domain names that are covered by the same certificate

●       True

Digital certificates are used to vouch for the certificate subject’s identity and the public key associated with them:

●       True

What’s the first step that a certificate authority (CA) should do when they receive a new certificate signing request (CSR)?

●       Validate the identity of the requester

To protect the private key of a root CA, these CAs are usually offline and only occasionally sign the certificates of intermediate CAs that actually issue certificates to customers

●       True

Digital certificates have to be sent securely because they contain sensitive information

●       False

Self-signed certificates signed by internal CAs in an organization are trusted by the outside world and can also be used for internal purposes in the organization

●       False

Eavesdropping protection is needed during asymmetric cryptography key exchange

●       False

Instead of relying upon the peer-to-peer trust relationships which is the basis of the web of trust model, the public key infrastructure relies upon the trust that participants have in high trusted centralized service providers, known as certificate authorities.

●       True

Is it easy for someone else to get a copy of your digital certificate and provide it to a third party claiming to be you? What could they do with your certificate?

●       Yes because your certificate is meant to be shared publicly - They could encrypt a message with your public key

**Quiz 6:**

Rather than trying all possible combinations over the web, brute force attacks are usually done by getting access to a set of hashed passwords and trying to find a password that, when hashed, matches the same hashed result

●       True

False acceptance errors are more serious errors than false rejection errors because it allows unauthorized access to the system and jeopardize confidentiality or integrity of the system

●       True

Which of the following would be most resistant to a dictionary attack?

●       A random password

Brute force theoretical time, is the exact time to find a possible password in a key space

●       False

During what phase of the access control process does a user prove his or her identity

●       Authentication

A dictionary attack decreases the total time to search the full keyspace

●       False

An approach that combines a password with the answer to a security question is considered multifactor authentication

●       False

As the sensitivity of an authentication system is increased, its false __acceptance__ rate will decrease

As the sensitivity of an authentication system is increased, its false __rejection__ rate will increase

The reuse of passwords across multiple sites makes an individual susceptible to ___ attacks.

●       Credential stuffing

Salting the password with a random sting will protect against a rainbow table attack

●       True

A __brute force__ attack uses software to try every possible combination of characters to generate a massive amount of consecutive guesses in order to get the password

If a user submits an invalid username to reset their password on a website, they should receive a message saying the username is not found

●       False

Which one of the following is an example of multifactor authentication

●       ID card and PIN

Brute force theoretical time, the time required to search the total key space, can be used to compare different password strengths and different crashing techniques

●       True

The _____ gives a balanced measure of strength of an authentication system.

●       Crossover error rate

The false rejection rate is the characteristic of an authentication factor that measures the frequency at which legitimate users are denied access to a system or facility

●       True

Which of the following best describes a rainbow table?

●       A table of precomputed password hashes

Shared accounts, where more than one individual has access to use the account, pose a security risk. It makes it difficult to trace who performed an action and every user has plausible deniability when several people have access to an account

●       True

**Midterm quiz:**

Which of the following types of Security Controls is used to reduce vulnerabilities on a system?

●       Preventative

True or False: Security Controls are countermeasures that organizations can use to minimize risks

●       True

A hacker that gains unauthorized access to a system specifically for political or socially motivated reasons is called a

●       Hacktivist

Tampering in the STRIDE model refers to any type of attack where data is modified by unauthorized users. Which of the following security controls is most closely related to the detection of tampering?

●       Hashing

Which of the following attacks can compromise the Availability of a system?

●       Gaining unauthorized access to a system and installing ransomware

True or False: an attack vector is the sum total of all vulnerable points on a system

●       False

System support for an insecure protocol (e.g. FTP) is an example of a(n) ________ vulnerability

●       Server

The practice of performing security checks as early as possible in the software development lifecycle is known as ________

●       Shift-left

Unauthenticated vulnerability scanning of a network is most appropriate for:         

●       trying to detect major security flaws in the parts of the network that are exposed to the public internet

A CVSS vector string is a text representation of the metric values used to calculate the severity score of a vulnerability.

Which of the following is not one of the metrics used to determine a vulnerability's numeric score?

●       Authentication (AU)

Which of the following are ways in which viruses and worms are different?

●       Viruses and worms have different propagation methods

Which of the following types of hackers is least likely to be able to exploit a zero-day vulnerability?

●       Script Kiddie

True or False: Worms are a form of malware that is self-replicating

●       True

Social Engineering attacks are said to be successful due to the Six Principles of Influence.

If a user is more likely to click a malicious link sent from the account of a friend that has been hacked, which principle is being used by the attacker to increase the likelihood their attack is successful?

●       Familiarity/Liking

The window of vulnerability for a zero-day vulnerability is the time between ________ and ________

●       when the vulnerability is discovered, when the vendor releases a patch

Which type of backup uses the least storage space?

●       Incremental

Which of the following is a network-based protocol that computer systems use to send event logs to a central location for storage?

●       Syslog

True or False: Your logging system should be more available than your business systems

●       False

Which type of backup has the fastest recovery speed?

●       Full

What is the primary reason attackers tamper with logs after gaining unauthorized access to a system?

●       Repudiation

If two different messages m1 and m2 result in hash(m1) = hash(m2), what is the cause?

●       An insecure hashing algorithm

True or False: Asymmetric cryptography requires secure key distribution

●       False

In the process of digitally signing a document, a plaintext message is hashed before being encrypted. What does hashing the message provide?

●       Proof that the message was not altered in transit

Which of the following is a secure hashing algorithm?

●       SHA256

Which of the following is not an example of communication that uses asymmetric cryptography?

●       All of the above use asymmetric cryptography

Research the following vulnerability and answer the follow-up questions below: CVE-2017-11882

1) Find the CVSS base vector and note it in your answer

2) List two CVSS vector elements that increase the CVSS score by at least 1.0 points

3) Suggest an action that would mitigate this vulnerability

1) Vector: CVSS:3.1/AV:L/AC:L/PR:N/UI:R/S:U/C:H/I:H/A:H

2)C:H (Confidentiality High Impact) and I:H (Integrity Impact High) are both increasing the score by 1.0 point.

3) To mitigate this vulnerability, it would be best to apply recent patches to the system. According to this website:

https://www.kaspersky.com/blog/cve-2017-11882-exploitation-on-the-rise/48768/#:~:text=And%20that%20is%20despite%20the,for%20more%20than%20five%20years.

a patch was released in November 2017 that resolves the issue and should be applied immediately to impacted systems.

This malware was spread through an e-mail (with attachment) sent to individuals that looked like a "Mail Delivery Failure" message. When a recipient opened the e-mail, most would ignore it as spam. But for those who clicked on the attachment, it would perform two actions (without the user knowing):

Resend the e-mail with attachment to all e-mails in the recipients address book in an attempt to spread itself

Install a payload on the host system that would perform a denial of service attack on a controversial website.

Identify the type(s) of malware described in this scenario and describe why you chose it?

I would identify this malware as a worm for the following reasons:

It appears to be self-replicating across the system

Uses built-in automatic propagation to infect other systems, which differentiates it from a typical virus

It does not seem to be attached to an executable software or file like a trojan typically would be

**Quiz 6:**

Rather than trying all possible combinations over the web, brute force attacks are usually done by getting access to a set of hashed passwords and trying to find a password that, when hashed, matches the same hashed result.

●       True

Which of the following would be most resistant to dictionary attack?

●       A random password

Brute force theoretical time, is the exact time to find a possible password in a key space.

●       False

During what phase of the access control process does a user prove his or her identity?

●       Authentication

A dictionary attack decreases the total time to search the full key space.

●       False

An approach that combines a password with the answer to a security question is considered multifactor authentication.

●       False

As the sensitivity of an authentication system is increased, its false

____acceptance____ rate will decrease.

The reuse of passwords across multiple sites makes an individual susceptible to _____ attacks.

●       Credential stuffing

Salting the password with a random string will protect against a rainbow table attack.

●       True

A ___brute force___ attack uses software to try every possible combination of characters and generate a massive amount of consecutive guesses in order to get the password.

If a user submits an invalid username to reset their password  on a website, they should receive a message saying the username is not found.

●       False

Which one of the following is an example of multifactor authentication?

●       ID card and PIN

Brute force theoretical time, the time required to search the total key space, can be used to compare different password strengths, and different cracking techniques.

●       True

**Quiz 8:**

What's true about TLS? (Select all that applies)

●       It can be used insecurely based on the chosen cipher suite

●       It has evolved from its predecessors SSL

●       It’s a protocol for providing secure communication channel

What is true about SSH?

●       It uses public key cryptography to exchange an ephemeral session key

Telnet was an extremely insecure protocol because the communication between the client and the server was unencrypted, and anyone eavesdropping on a Telnet session can steal the data.

●       True

In a communication protected by TLS, encryption on the data is done using __________

●       Session key

What's the first step to initiate a secure session protected by TLS between two systems?

●       Client sends a request including a list of the cipher suite supported by the client

Which one of the following is the most secure way for web servers and web browsers to communicate with each other?

●       TLS

What’s true about the ephemeral key used in TLS connection?

●       It is used only for one communication session

●       It is decrypted using server’s private key

●       It is encrypted using server’s public key

●       It is also referred to as session key

SSL inspection technology performs a “friendly” man-in-the-middle attack against an organization’s own users to examine the contents of network traffic.

●       True

**Quiz 8:**

DMZ zone on a firewall protects internal network by isolating systems such as web server or email server that must accept direct external connection

●       True

What information is not found in network flow data?

●       Packet content

Systems that must accept direct connections from the outside world, such as public web servers, are at higher risk of compromise. Therefore, they should be placed on __________

●       DMZ

__________ filtering watches for threats entering your network, while __________ filtering monitors traffic leaving your network, which may alert you to compromise systems or other malicious activity that's happening on your network.

●       ingress - egress

NAT makes it difficult to identify the true origin of traffic by associating a temporary public IP address to a system with private IP address that wants to communicate on the internet.

●       True

Why would you use stateful packet inspection instead of stateless packet filtering?

●       stateful inspection provides higher security because it makes a decision based on the state of existing connections

What router technology can be used to perform basic firewall functionality?

●       Access control lists

_____ is responsible for user authentication, security posture check, and role-based access.

●       NAC

Private IP addresses are not internet routable.

●       True

A zero-trust network security approach is based on identity authentication instead of trusting users based on their position relative to your network.

●       True

In which deployment mode, the IPS sits directly on a network path and can block suspicious traffic from entering the network?

●       In-band

Systems that are connected to private networks, may use private IP addresses that are reusable on other networks.

●       True

**Quiz 9:**

Network sniffing can only be done for malicious reasons.

●       False

Select all controls that can protect a network against eavesdropping attacks:

●       VPNs

●       Encryption at application layer

●       Segmentation with VLANs

●       Network access controls

Select all that's true about Smurf attack

●       It is an example of denial of service attack

●       The attacker sends large numbers of forged Echo Requests (IP address of the victim used as the source address) to the broadcast addresses of third party servers

●       The victim machine gets overwhelmed by receiving a large amount of Echo Replies

●       It is an example of amplified DDoS attack

Any sample of data gathered by sniffing a network at any time would be an accurate representation of the actual normal traffic on the network.

●       False

What term is used to refer when a compromised system is used to try to compromise other systems on the network?

●       Lateral traffic

Network sniffing results are impacted by the network segment on which your sniffer is running.

●       True

A distributed denial of service (DDoS) attack that uses botnet solves two problems that attackers would have with a basic denial of service attack: provide large amounts of bandwidth, and makes it harder to distinguish the requests from legitimate traffic.

●       True

In a replay attack, the attacker typically can capture and see the actual credentials and resend it to misdirect the receiver into doing what the hacker wants

●       False

What term is used to refer to connections from compromised systems to command and control servers?

●       Beaconing

Which principle of cybersecurity is violated in TCP SYN flood attack ?

●       Availability

What technology can help prevent denial of service attacks on a network?

●       Flood guard

What security incidents can unusual bandwidth consumption indicate?

●       Denial of service attack

●       Exfiltration of information

Select all that is true about TCP:

●       It is a reliable protocol.

●       Establishes connection between two systems before transferring data.

●       It is widely used for applications that require a guaranteed delivery, such as email and websites.

At what layer in the OSI model does the Internet Protocol work?

●       Network layer

Both TCP and UDP performs three-way handshake before transmitting data.

●       False

What is job of a DNS server?

●       Maps domain names to IP addresses

In a(n) ___split___ -tunnel VPN, the traffic specifically intended for the protected network is sent through the VPN tunnel, while general web browsing is routed directly over the internet.

When a DNS name server gets the response for a recursive query, it will cache not only the IP address of the domain in the query but also the location of all the nameservers it encounters along the way. This way it doesn't have to traverse the entire hierarchy from the root level down as long as the data lives in the cache.

●       True

Placing content on a legitimate site that automatically forwards a user from that legitimate site to a malicious site is an example of __________ attack

●       URL redirection

When you use dig command to find the IP address of a website, the DNS server that answers the query is always on your local network

●       False

ARP poisoning is an example of  __________ attacks.

●       Spoofing

ARP poisoning only works on a local network

●       True

A VPN is a solution developed to provide access to the private network services of an organization over a public network infrastructure.

●       True

Imagine that your network has suffered a botnet infestation. Which one of the following deception technologies would be helpful in limiting the ability of botnets to reach their command-and-control servers?

●       DNS sinkhole

If a local DNS server doesn't know the answer to a DNS query, it contacts other DNS servers to determine the correct answer and then responds to you.

●       True

Which server always has the definitive answer to a DNS query (without the need to query other servers)?

●       The authoritative DNS server for the domain in query

There is only one DNS publicly available server, maintained by google at IP 8.8.8.8

●       False

DNSSEC protocol is used as a countermeasure against DNS poisoning attack by adding digital signatures to DNS records to prove their authenticity.

●       True

In what type of attack does the attacker steal a domain registration from the true owner?

●       Domain hijacking

When logged in to a(n) ___full___ -tunnel VPN, if the user decides to stream a video from Netflix, that video traffic is sent through the VPN and can cause bandwidth problem.