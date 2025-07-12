# Digital To Digital Conversion
In the previous chapter we discussed that data can be a digital or analog signal.
## Line Coding
Line Coding is the process of converting **digital data** into **digital signals**. It converts a sequence of bits to a digital signal.

At the sender, digital data are encoded into a digital signal; at the receiver, the digital data are  recreated by decoding the digital signal.
### Line Coding Schemes
We can roughly divide line coding schemes into 5 categories:
![[Pasted image 20250205153156.png]]
We will only look into 3 categories
#### Unipolar (NRZ)
In a **unipolar** scheme, all voltage levels are on on side of the time axis (above or below)
A positive voltage defines a bit 1 and a zero voltage defines a bit 0 
![[Pasted image 20250205153312.png]]
#### Polar (NRZ-L, NRZ-I)
In a **polar** scheme, the voltage level are on both sides of the time axis.
A positive voltage can define bit 0 and a negative voltage can define bit 1.
![[Pasted image 20250205153414.png]]
##### Clock Synchronization
![[Pasted image 20250205153857.png]]
This requires that both the sender and receivers clocks to be synchronized other wise it is easy to lose when the first bit arrives.
#### Solution to Clock Synchronization Issue
RZ (Return to Zero)
Manchester (RZ + NRZ-L)
Differential Manchester (RZ + NRZ-I)
![[Pasted image 20250205154022.png]]

#### Bipolar
Bipolar schems have 3 voltage levels
- Positive
- Negative
- Zero

The voltage for one data element is at zero, while the voltage level for the other elements alternates between positive and negative.
![[Pasted image 20250205154204.png]]
# Analog to Digital Conversion
## Pulse Code Modulation (PCM)
The most common technique to convert an analog signal to digital data (digitization) is called **pulse code modulation** (PCM). A PCM encoder has three process
![[Pasted image 20250205160254.png]]
## Step 1: Sampling
Based on the **Nyquist Theorem** to reproduce the original analog signal, the sampling rate must **be at least 2 times** the **highest frequency** $f_{\text{max}}$ contained in the signal
![[Pasted image 20250205160454.png]]
Nyquist Rate
	$f_{s} = 2*f_{\text{max}}$
$f_{\text{max}} \neq B$

![[Pasted image 20250205160640.png]]
## Step 2 & 3: Quantizing and Encoding
![[Pasted image 20250205160804.png]]
### Quantization Error 
Quantization is an **approximation** process an important issue is the errors created. The **quantization error** changes the signal-to-noise-ratio (SNR) of the signal, which reduces the limit of the Shannon Capacity.

The **Signal Strength in relation to quantization Error**
$\text{SNR}_{\text{Q}}$ in dB is estimated by

$\text{SNR}_{\text{Q}} = 6.02\text{n}_{\text{b}} + 1.76$
$\text{n}_{\text{b}} = log_{2}\text{L}$ the number of bits per sample

## Step 3: Encoding and Bit Rate
The last step of PCM is encoding. After each sample is quantized and the number of bits per sample is determined. each sample is represented by an n-bit code word

The bit rate can be found as 
$\text{Bitrate} = f_{s} * n_{b}$

