
Beaglebone black PRU code to use HCSR-04 proximity sensor.
===

Prerequisites:

	* Beaglebone black with debian 3.8.13 bone47
	* HCSR-04 sensor

Hardware configuration:

	* TRIGGER		P8_12 gpio1[12] GPIO44	out	pulldown		Mode: 7 
	* ECHO			P8_11 gpio1[13] GPIO45	in		pulldown		Mode: 7 *** with R 1ko
	* GND			P9-1 o P9-2 GND
	* VCC			P9-5 o P9-6 VDD_5V
	
	Make sure there is a 1Ko resistor between ECHO pin and your beaglebone as input pins are 3.3V while sensor emits 5V

### To build:

	make
	
### To install:

	make install
	
	Will copy device tree driver to lib firmware and add it to the cape manager
	
### To run

	./hcsr04
	
