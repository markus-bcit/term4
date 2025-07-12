# Data and Signals
## Analog and Digital Signals
Data can be **analog** or **digital**.
The term **analog data** refers to **information that is continuous**
The term **digital data** refers to **information that has discrete states**.

## Periodic and Non Periodic
A **periodic signal** completes a **pattern** within a measurable time frame, called a **period**, and repeats that pattern over subsequent identical periods. The completion of one full pattern is called a cycle.

A **nonperiodic signal** changes without exhibiting a pattern or cycle that repeats overtime.

A Period, T, in seconds refer to the amount of time a signal needs to complete 1 cycle. Frequency, $f$ in hertz (Hz)

Note that period and frequency are the **inverse of each other**
$T = \frac{1}{f}$

# Analog Signals
A Periodic Analog signals can be classified as **simple** or **composite**

A **simple** periodic analog signal, a sine wave, cannot be decomposed into simpler signals.

A **composite** periodic analog signal is composed of multiple sine waves
(Composite Orchestra)
## Sine Waves
![[Pasted image 20250118133327.png]]
>The Sine wave is the most fundamental form of a periodic analog signal. It is a simple oscillating curve and its change over the course of a cycle is smooth and consistent a continuous, rolling flow. Each cycle consist of a single arc above the time axis followed by a signle arc below it.

A sine wave $y(t) = A sin(2\pi ft+\theta)$ is comprehensively defined by its 
### Peak amplitude A (Volt)
![[Pasted image 20250118133640.png]]
Frequency, f (Hz)
![[Pasted image 20250118133649.png]]
Phase, $\theta$ (Radiants)
![[Pasted image 20250118133711.png]]
## Phase
The term **phase** or phase shift describes the position of the waveform relative to time 0.

## Wave length
Wave length is another characteristic of a signal traveling through a transmission medium

## Time and Frequency Domains
Previously, time-domain plot shows changes in signal amplitude with respect to time. To show the relationship between amplitude and frequency, we can use a frequency-domain plot
![[Pasted image 20250118135850.png]]
## Composite Signals
![[Pasted image 20250118141957.png]]
![[Pasted image 20250118142005.png]]
## Bandwidth
The range of frequencies contained in a composite signal is its bandwidth. The bandwidth is normally a difference between two numbers 
For example, if a composite signal contains frequencies between 1000 Hz and 5000 Hz, its bandwidth, B = $f_{h} - f_{p}$ where $f_{p} f_{h}$ respectively are the lowest and highest frequencies. Thus bandwidth is 5000-1000 = 4000 Hz
# Digital Signals
![[Pasted image 20250118144314.png]]
	requires $2^{x}$ levels for the to represent x bits 
## Bit Rate
>A page has an average of 24 lines with 80 characters in each line. If we assume that one character (a byte) requires 8 bits, the bit rate is 

 $100 * 24 * 80 * 8 = 1,536,000 bps$ otherwise 1.536 Mbps
## Bit Length
Bit length = propagation speed * bit duration

## Digital as Composite Analog
A **digital signal** is a **composite analog signal** and the bandwidth is **infinite**
![[IMG_5808.webp]]
![[Pasted image 20250118145500.png]]
It gets clipped 
Although the output signal is not a **exact replica** of the original data, the original data **can still be deduced** from the received signal

## Transmission of Digital Signals
### Baseband transmission (Starts from Zero)
Sending a digital signal over a channel without changing the digital signal to an analog signa. It requires a **low-pass** channel. 
### Broadband transmission (does not start from Zero)
means changing the digital signal to an analog signal for transmission. It requires a **band-pass** channels
