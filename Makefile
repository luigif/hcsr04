CC = gcc
CFLAGS = -Wall
PRU_ASM = pasm
DTC = dtc

all: hcsr04-00A0.dtbo hcsr04.bin hcsr04

hcsr04-00A0.dtbo: hcsr04.dts
	@echo "\n>> Compiling Driver"
	$(DTC) -O dtb -o hcsr04-00A0.dtbo -b 0 -@ hcsr04.dts

hcsr04.bin: hcsr04.p
	@echo "\n>> Generating PRU binary"
	$(PRU_ASM) -b hcsr04.p

hcsr04: hcsr04.c
	@echo "\n>> Compiling HC-SR04 example"
	$(CC) $(CFLAGS) -c -o hcsr04.o hcsr04.c
	$(CC) -lpthread -lprussdrv -o hcsr04 hcsr04.o

clean:
	rm -rf hcsr04 hcsr04.o hcsr04.bin hcsr04-00A0.dtbo 

install: hcsr04-00A0.dtbo hcsr04.bin hcsr04
	cp hcsr04-00A0.dtbo /lib/firmware
	echo hcsr04 > /sys/devices/bone_capemgr.9/slots
	cat /sys/devices/bone_capemgr.9/slots