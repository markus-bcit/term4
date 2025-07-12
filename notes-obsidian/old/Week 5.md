# Analog Transmission
## Digital-To-Analog Conversion
Digital To analog conversion is the process of changing one of the characteristics of analog signal based on the information in digital data.
The relationship between the digital data, the digital-to-analog modulating process and the resultant analog signal is shown below
![[Pasted image 20250208123825.png]]
### Sine Wave
Recall that the sine wave is the most fundamental form of a periodic analog signal. It is comprehensively defined by its **peak amplitude**, **frequency**, and **phase**. 

### Types of Digital to analog Conversion
![[Pasted image 20250208125043.png]]
### Amplitude Shift Key (ASK)
In amplitude Shift keying (ASK), the amplitude of the carrier signal is **varied** to create signaled elements. Both the frequency and phase remain content while the amplitude changes.
![[Pasted image 20250208125439.png]]
### Frequency Shift Keying (FSK)
In frequency shift keying (FSK), the **frequency** of the carrier signal is **varied** to represent data. Both the peak amplitude and phase remain constant for all signal elements.
![[Pasted image 20250208130448.png]]
### Phase Shift Keying (PSK)
In phase shift keying (PSK), the **phase** of the carrier is **varied** to represent two or more different signal elements. Both the peak amplitude and frequency remain constant as the phase changes.
![[Pasted image 20250208130953.png]]
### Quadrature Amplitude Modulation (QAM)
So far, we have been altering only one of the three characteristics of a sine wave at a time; but what if we **alter two** and combine ASK (amplitude) and PSK (phase)?

The idea of using **two carriers** (same frequency, 90 degrees out-of-phase with each other), one **in-phase** and the other **quadrature**, with different **amplitude levels** for each carrier is the concept behind **quadrature amplitude modulation (QAM)**
![[Pasted image 20250208131852.png]]
### Constellation Diagrams
Constellation diagrams define the **amplitude** and **phase** of a signal element, particularly when two carriers (in-phase nad quadrature) are used. The diagrams are useful when dealing with **multi-level** ASK,PSK,QAM.
![[Pasted image 20250208134041.png]]
## Analog-To-Analog Conversion

Analog-To-Analog conversion, or analog modulation is the **representation** of **analog data** by an **analog signal**

Modulation is needed if the medium is **bandpass** in nature or if only a bandpass channel is available.
### Amplitude Modulation (AM)
![[Pasted image 20250208141251.png]]
The **amplitude of the carrier signal** needs to be **changed** according to the **amplitude of the modulating signal**. The **modulating signal** is the **envelope** of the **carrier**.

AM is normally implemented using a simple multiplier.
### Frequency Modulation (FM)
In **FM transmission**, the **frequency** of the **carrier signal** is modulated to follow the **changing amplitude** of the **modulating signal**.
![[Pasted image 20250208141503.png]]
The peak amplitude and phase of the carrier remains the same.
### Phase Modulation (PM)
In **PM transmission** the **phase** of the **carrier signal** is modulated to follow the **changing amplitude** of the **modulating signal**. The peak amplitude and frequency of the carrier signal remain constant.

PM can be mathematically shown to be the same as FM with a difference: in PM, the instantaneous change in teh carrier frequency is proportional to the **derivative** of the amplitude of the modulating signal (as opposed to the amplitude of the modulating signal in FM).
![[Pasted image 20250208141849.png]]

As the **amplitude** of the information signal changes, the **phase** of the carrier changes correspondingly.
PM is normally implemented by using a voltage-controlled oscillator along with a derivative.