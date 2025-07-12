# Error Detection and Correction
## Introduction
Whenever bits flow from one point to another, they are subject to <u>unpredictable changes</u> because of <u> interference</u>. This interference can <u>change the shape</u> of the <u>signal</u>.

The <u>number of bits affected</u> depends on the <u>data rate</u> and the <u>duration of noise</u>.

### Types of Error
The term **single-bit error** means that only 1 bit of a given data unit (such as a byte, character or packet) is changed from 1 to 0 or from 0 to 1. The term **burst error** means that 2 or more bits in the data unit have changed form 1 to 0 or from 0 to 1.
![[Pasted image 20250222114426.png]]
A **burst error** is **more likely** to occur than a **single-bit error** because the **duration of the noise** is normally **longer** than the **duration of 1 bit** (data rates are in orders of Mbps, Gbps, and increasing).

For example:
- If data is being sent at 1 kbps, a noise of 1/100 sec can afffect 10 bits
- If data is being sent a 1 Mbps the smae noise of 1/100 sec can affect 10,000 bits
### Redundancy
The central concept in **detecting or correcting errors** is **redundancy**.

To be able to detect or correct errors, we need to send some **extra bits** with out data. These redundant bits are **addeed by the sender** and **removed by the receiver**. The presence of the redundant bits allows the **receiver** to **detect or correct corrupted bits**.
## Blocking Coding
In block coding, we **divide** our **message into blocks**, each of **k bits**, called **datawords**. We are **r redundant bits** to each block to make the length $n = k + r$
The resulting **n-bit blocks** are called **codewords**and the **code rate**is $\frac{k}{n}$

The **reciever** can **detect** a change in the original codeword if the following **two conditions are met**:
1. The **receiver** has or can find a **list of valid codewords**
2. The **original codeword** has changed to an **invalid** one.
![[Pasted image 20250222131314.png]]
![[Pasted image 20250222131400.png]]
### Linear Block Codes
An informal of Linear Block Code (LBC) is a code in which **XOR of two valid codewords creates**, another **valid codeword**.
![[Pasted image 20250222131503.png]]
The $d_{min}$ for a LBC is the **number of 1s** in the **nonzero valid codeword** with the **smallest number of 1s**. In the above code scheme, the number of 1s in the nonzero codewords are 2,2 and 2. Hence, $d_{min} =2$ 

### Parity-Check Code
In parity-check code, a LBC, a **k-bit dataword** is changed to an **n-bit codeword**  where n = k + 1. The extra bit, called the **parity bit**, is selected to make the total number of 1s in teh codeword **even or odd**.

#### Even parity-check code
n = 5
k = 4
$d_{min}$ = 2
Singlebit error detecting code.
![[Pasted image 20250222132209.png]]

## Cyclic Codes
Cyclic codes are special linear block codes with one extra property: in a **cyclic code**, if a codeword is **cyclically shifted**, the result is another code word

For example if **1**011000 is a code word and we cylically left-shift, then the result, 011000**1** is also a codeword.
![[Pasted image 20250222134241.png]]
![[Pasted image 20250222134248.png]]
## Check Sum
Checksum is an **error-detecting** technique that can be applied to a **message** of any length. In the internet the checksum technique is mostly used at the **network** and **transport** layer rather than the data-link layer.

If the sum overflows
we do **end-around carry** 
![[Pasted image 20250222141619.png]]
