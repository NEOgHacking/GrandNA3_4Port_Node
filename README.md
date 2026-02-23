# GrandNA3_4Port_Node
GrandNA3_4Port_Node is a DMX network node based on the official grandMA3 onPC 4Port Node 4k. My version also has 4DMX outputs with RDM support, a EtherCON connector for sturdy Ethernet connections and a display with a knob for configuration. It also uses the Neutrik halo connectors with adressable rgb leds to show the status of the connection. But it also has some differences. First it doesn't unlock any parameters in the GrandMA onPC software, second its 20x cheaper. About $100 instead of $2000.

# Features
This specific DMX node has some really usefull features.
1. 4DMX outputs with RDM support.
2. Neutrik EtherCON connector for a sturdy and lasting connection. Also support for ARTNET and sACN
3. Color display with a rotary encoder for configuration straigt from the unit itself.
4. UPS (uniteruptable power supply) For when the power cuts out but you still need it or just for battery operation.
5. Wifi card slot for wireless operation with the battery.
6. Powered by a rp2350 for its PIO modules so DMX is correctly implemented and not via a hacked uart or bitbanging a pin.
7. PoE (Power over Ethernet) For easy setup and as little wires as possible.
8. USB-C port for power and data to program the rp2350 or configure it.
9. Cheap PCB. The PCB is 100x72mm 4 layer so its cost is low only $7.

# Motivation
I started on making this DMX network node for a few reasons. First i was using a raspberry pi with a usb DMX dongle, this worked but was hard to set up and only got me 1 DMX universe without RDM. It also wasn't the cheapest setup. I wanted it to be cheaper and have more functionallity. Second I once had the opurtunity to use a grandMA3 onPC 4Port Node 4k at school once and realized how usefull it would be. Then my dumb brain said the same sentence it always says: "I can build that myself for cheaper right?" Next thing you know you are 100 hours deep into the project.

# Design
The design process was a heck of a ride, at first i started with the simple DMX part but then got to the ethernet. I really wanted PoE so started with the ride. It was a heck of a long ride, i think it took up 1/3 of the projects time its really complex. Also the most complex schematic from the whole project. The rest went pretty smooth. I had recently done another big project my 3D Printer mainboard and learned allot from that! So the rest was pretty straight forward, always some small chip changes here and there but apart from that it went well. The case design also went quick didn't have to high of standards for that but still wanted it to look good. After a whole day that was done. 
I used KiCad for PCB design, Onshape for 3D design and VScode for Firmware.

# Schematic
This is a very long schematic. You can find the whole schematics in .PDF format in the individual PCB design folders. But here are some important ones.
