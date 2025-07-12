# Transmission Impairment
Signals travel through transmission media, which are not perfect

The imperfection causes signal impairment. This means that the signal at the end of the medium.

Impairments are caused by
- Attenuation - A loss of energy
- Distortion  - The signal changes its form or shape
- Noise - an impairment on the signal
## Attenuation
Attenuation means loss of energy. When a signal simple or composite travels through a medium it loses some for its energy in overcoming the resistance of the medium. To compensate for this loss **amplifiers** may be used to amplify the signal. ![[Pasted image 20250125125527.png]]

## Distortion
Distortion means that the signal changes its shape or form. Distortion can occur in a **composite signal** made of different frequencies. Each signal component has its own propagation speed through a medium and, therefore, its own delay in arriving at the final destination. differences in delay may create a difference in phase if the delay is not exactly the same as the period duratio
![[Pasted image 20250125125600.png]]
## Noise
Noise is another cause of impairment. Several types of noises, such as **thermal noise**, **induced noise**, **crosstalk**, and **impulse noise** etc. 

Thermal noise -  is the random motion of electrons in a wire which creates an extra signal not originally sent by the transmitter
Induced Noise -  comes from the sources such as motors and appliances
Cross Talk -  is the effect of one wire on the other
Impulse Noise - is a spike (a signal with high energy in a very short time) that comes from power lines and lightning
![[Pasted image 20250125125849.png]]
## Decibel
The decibel (dB) measures the **relative strengths** of **two signals** or **one signal at two different points** to show whether a signal has lost or gained strength 

$\text{dB} = 10\log_{10}\frac{P_{2}}{P_{1}}$

Where $P_{1}$ and $P_{2}$ are the powers of a signal at points 1 and 2 respectively.

Note* If the decibel is negative it is **attenuated** and if its positive its **amplified**
## Signal-to-Noise Ratio (SNR)
The Signal to noise ratio is a ratio explaining how corrupted the original signal is from noise
$\text{SNR} = \frac{\text{average signal power}}{\text{average noise power}}$
Note* SNR higher means less corrupted and low is more corrupted
$SNR_{dB} = 10\log_{10}SNR$
![[Pasted image 20250125132303.png]]
# Data Rate Limits
A very important consideration in data communications is how fast we can send data, in **bits per second**, over a channel. The data rate depends on three factors: 
1. Bandwidth availability
2. Signal levels Used
3. Channel Quality
## Noiseless Channels: Nyquist Rate
For a **noiseless channel**, the **Nyquist** bit rate formula defines the theoretical maximum bit rate
$\text{BitRate} = 2*\text{bandwidth}*log_{2}\text{L}$
Bandwidth is the bandwidth of the channel
L is the number of **signal levels** used to represent the data, BitRate is bits per second


## Noisy Channel: Shannon Capacity
In **reality** we cannot have a noiseless channel; The channel is always noisy. The **Shannon Capacity Formula** determines the theoretical highest data rate for a noisy channel.
$\text{Capacity} = \text{bandwidth}*log_2(1+\text{SNR})$
# Performance
One of the imporant issues of netowrking is the **performance** of the network
## Bandwidth
One characteristics that measure network performance is **bandwidth** However this term can be used in two contexts
bandwidth in hertz (Hz): refers to the range of frequencies

Bandwidth in bits per second (bps) refers to the speed of bit transmissions in a channel or link

## Throughput
The throughput is a measure of how fast we can actually send data through a network
At a first glance **bandwidth** B, and **throughput** T may seems the same. However Bandwidth is how many bps we can send but we only send T bps
## Latency (Delay)
The latency or delay defines how long it takes for a an entire message to completely arrive at the destination from the time the first bit is sent out from the source.
Latency is made of 4 components
- propagation time - Time for the signal to travel through the medium
$\text{Propagation Time} = \frac{\text{Distance}}{\text{Propagation Speed}}$

- transmission time - Time to push all the bits of the message onto the network
$\text{Tranmission Time} = \frac{\text{Message Size}}{\text{Transmission Rate}}$
- queueing time - Time the message waits in queue before being processed
- processing delay - time taken to process the message at the source, intermedia nodes, and the destination