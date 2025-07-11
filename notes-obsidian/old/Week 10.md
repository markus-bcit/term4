# Multiplexing
## Introduction
As data and telecommunications use increases, so does traffic. We cac n accommodate this increase by
- **adding individual links** each time a new channel is needed, or
- **installing higher-bandwidth links** and use them to carry multiple signals.

>General idea: when the link bandwidth of a medium linking two devices is greater than the bandwidth requirements of the devices, the link can be shared.

**Multiplexing** is a set of techniques that allow the **simultaneous transmission of multiple signals** across a **single data link**.
![[Pasted image 20250321192641.png]]

![[Pasted image 20250321192647.png]]

## Frequency-division Multiplexing
Frequency-division multiplexing (FDM) is a an **analog multiplexing technique** that can be applied when the **bandwidth of a link** is **greater** than the **combined bandwidths of the signals** to be transmitted.

In FDM, **signals generated by each sending device** are **modulated** to **different carrier frequencies.** The carrier frequencies are **separated** by sufficient bandwidth (also known as **guard bands**) to **prevent signals from overlapping**. It is important that the carrier frequencies **do not interfere** with the original frequencies.
![[Pasted image 20250321192904.png]]
## Wavelength-division multiplexing
Wavelength-division multiplexing (WDM) is an **analog multiplexing technique** used to **combine optical signals** to take advantage of the high data rate capability of **fiber optic cable**.

WDM is a complex technology, but the basic idea is simple: **combine multiple light sources** (ie **different wavelengths**) into **one single light** at the multiplexer and do the reverse at the demultiplexer.![[Pasted image 20250321194154.png]]

The implementation of **combining and splitting of light sources** can be handled by **prisms**: a multiplexing prism combines several input beams of light into one output beam and demultiplexing prism reverses the process:
![[Pasted image 20250321194234.png]]
## Time-division multiplexing
Time-division multiplexing (TDM), **synchronous** or **statistical**, is a **digital multiplexing technique** that allows **several connections** to share the high bandwidth of a link. Instead of sharing a portion of the frequency spectrum as in FDM, **time is shared**. Each connection occupies a portion of time in the link.
![[Pasted image 20250321194335.png]]

In **synchronous** TDM, each input connection has an **allotment** in the output frame **even if it's not sending data**.
![[Pasted image 20250321195015.png]]

Framing **bits are added** to each frame to allow the demultiplexer to **separate** the **time slots** accurately in the implementation of **synchronous** TDM.
![[Pasted image 20250321195124.png]]
If the **multiplexer** and **demultiplexer** are not **synchronized**, a bit belonging to one channel may be received by the wrong channel.

Synchronized TDM can be **inefficient**. If a source does not have data to send, the corresponding slot in the output frame is empty.
![[Pasted image 20250321203949.png]]
In **statistical** TDM, slots are **dynamically allocated** to improve bandwidth efficiency. Only when an input line has data to send it is it given a slot in the output frame. Note that the **number of slots** in each frame may be **less** than the **number of input lines**.
![[Pasted image 20250321204049.png]]