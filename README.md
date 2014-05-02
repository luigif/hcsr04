
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
	
	Make sure there is a 1Ko resistor between ECHO pin and your beaglebone
	as input pins are 3.3V while sensor emits 5V

### To build:

	make
	
### To install:

	make install
	
	Will copy device tree driver to /lib/firmware and add it to the cape manager
	
### To run

	./hcsr04

### Example output:

	>> Initializing PRU
	>> Executing HCSR-04 code
	  1: Distance = 181.52 cm
	  2: Distance = 181.50 cm
	  3: Distance = 181.50 cm
	  4: Distance = 181.52 cm
	  5: Distance = 181.93 cm
	  6: Distance = 181.52 cm
	  7: Distance = 180.64 cm
	  8: Distance = 181.50 cm
	  9: Distance = 181.06 cm
	 10: Distance = 181.49 cm
	 11: Distance = 181.04 cm
	 12: Distance = 181.93 cm
	 13: Distance = 181.47 cm
	 14: Distance = 181.47 cm
	 15: Distance = 181.91 cm
	 16: Distance = 181.91 cm
	 17: Distance = 181.47 cm
	 18: Distance = 182.35 cm
	 19: Distance = 181.49 cm
	 20: Distance = 181.06 cm
	>> PRU Disabled.

