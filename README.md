# Visitor Counter
Energy Saving using PIC<br/>
![alt tag](VisitorCounter.BMP)<br/>
# Logic
Detects the absence of people in a room and turns off the electrical equipments.
# Implementation
It is assumed that the entrance and exit are through separate doors.
A counter is initialized and it is incremented when an interrupt is generated and decremented when another interrupt is generated.
The interrupts are produced using phototransistors.
If counter = 0, the relay is turned off and if counter > 0, the relay is turned on to turn off and on the electrical equipements respectively.
