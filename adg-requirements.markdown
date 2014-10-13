**DRAFT**

== Overview ==

I've always wanted a system that enables direct feedback from students in a classroom. Such systems exist, but homebrewing one is awesome, especially for a project class like ECE411.

== Hardware overview == 

I imagine two pieces of hardware: the "transmitter" (TX) and the "receiver" (RX). 

- **Transmitters**: The TXs are absolutely minimal PCBs with a wireless microcontroller, coin cell battery, and some minimal UI, like 5 buttons. Maybe a slider.
- **Receiver**: A single receiver listens and gathers data from all the TXs. Maybe it has a display on it, which shows real time data from the TXs. Possibly it simply has a USB plug for a custom written Python interface (or whatever).

== User stories ==

- User asks students a multiple choice question on the projector with answers 1-5. Students press the button they think is the correct answer. User looks at PC screen and immediately sees how many students "get it".
- User asks students a multiple choice question about themselves, e.g., how many years they've been in school. Students press the button corresponding to a range of years. A GUI interface displays the questions asked, and the cumulative votes for each answer until the user resets the value or goes on to the next question.
- A "lecture speed" slider is constantly adjusted by students. The user can tell if they're going too slow or too fast based on the distribution of where the sliders are. Could also be done with buttons.
- A "boring" slider is constantly adjusted by students. The user can tell how bored (aka not engaged) the students are based on the distribuition of where the boring sliders are.

== Requirements ==

- Must
    - Transmitters
       - Be usable by (100,500,) students in a single classroom
       - Use the unlicensed ISM bands (400, 900 or 2400 MHz)
       - Have an on/off  switch to save battery life
       - Have some kind of indication that they are on, and that a vote has been sent
    - Receiver
       - Be able to receive up to (100,500,) transmitter "votes" at a time with < 0.001 losses of votes per transmission
       - Connect to a PC via USB for data display and logging.
- Should
    - Transmitter
       - Cost (,5,15)$ each
       - Have the antenna built into the PCB for cost savings.
       - Be as small as possible
       - User a cheaply available COTS battery, like a CR2032, or a CR1612, etc
       - Have some serial number so user can identify a particular unit (but not a particular student)
    - Receiver
       - TBD
- May
    - Transmitter
       - Be in a COTS package, like a remote control or other pre-existing package.
       - Have bidirectional communication, so that the user can light up an LED on a transmitter
    - Receiver
       - Be in the same form factor as a USB flash drive, but with an external antenna connector like SMA or RP-SMA.
       
