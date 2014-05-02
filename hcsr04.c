#include <stdio.h>
#include <unistd.h>

#include <prussdrv.h>
#include <pruss_intc_mapping.h>

int main(void) {

	/* Initialize the PRU */
	printf(">> Initializing PRU\n");
	tpruss_intc_initdata pruss_intc_initdata = PRUSS_INTC_INITDATA;
	prussdrv_init();

	/* Open PRU Interrupt */
	if (prussdrv_open (PRU_EVTOUT_0)) {
		// Handle failure
		fprintf(stderr, ">> PRU open failed\n");
		return 1;
	}

	/* Get the interrupt initialized */
	prussdrv_pruintc_init(&pruss_intc_initdata);

	/* Get pointers to PRU local memory */
	void *pruDataMem;
	prussdrv_map_prumem(PRUSS0_PRU0_DATARAM, &pruDataMem);
	unsigned int *pruData = (unsigned int *) pruDataMem;

	/* Execute code on PRU */
	printf(">> Executing HCSR-04 code\n");
	prussdrv_exec_program(0, "hcsr04.bin");

	/* Get measurements */
	int i = 0;
	while (i++ < 20) {
		
		// Wait for the PRU interrupt
		prussdrv_pru_wait_event (PRU_EVTOUT_0);
		prussdrv_pru_clear_event(PRU_EVTOUT_0, PRU0_ARM_INTERRUPT);
		
		// Print the distance received from the sonar
		// At 20 degrees in dry air the speed of sound is 342.2 cm/sec
		// so it takes 29.12 us to make 1 cm, i.e. 58.44 us for a roundtrip of 1 cm
		printf("%3d: Distance = %.2f cm\n", i, (float) pruData[0] / 58.44);
		sleep(1);
	}

	/* Disable PRU and close memory mapping*/
	prussdrv_pru_disable(0);
	prussdrv_exit();
	printf(">> PRU Disabled.\r\n");
	
	return (0);

}
