/*
 * IS42S16400J-6TLI.c
 *
 *  Created on: Feb 6, 2024
 *      Author: parke
 */

#include "main.h"

void FMC_Init(SDRAM_HandleTypeDef* hsdram1){

	  FMC_SDRAM_CommandTypeDef Command;
	  /* Step 1 and Step 2 already done in HAL_SDRAM_Init() */
	  /* Step 3: Configure a clock configuration enable command */
	   Command.CommandMode            = FMC_SDRAM_CMD_CLK_ENABLE; /* Set MODE bits to "001" */
	   Command.CommandTarget          = FMC_SDRAM_CMD_TARGET_BANK2; /* configure the Target Bank bits */
	   Command.AutoRefreshNumber      = 1;
	   Command.ModeRegisterDefinition = 0;
	   HAL_SDRAM_SendCommand(hsdram1, &Command, 0xfff);
	   HAL_Delay(1); /* Step 4: Insert 100 us minimum delay - Min HAL Delay is 1ms */
	   /* Step 5: Configure a PALL (precharge all) command */
	   Command.CommandMode            = FMC_SDRAM_CMD_PALL; /* Set MODE bits to "010" */
	   HAL_SDRAM_SendCommand(hsdram1, &Command, 0xfff);
	   /* Step 6: Configure an Auto Refresh command */
	   Command.CommandMode            = FMC_SDRAM_CMD_AUTOREFRESH_MODE; /* Set MODE bits to "011" */
	   Command.AutoRefreshNumber      = 2;
	   HAL_SDRAM_SendCommand(hsdram1, &Command, 0xfff);
	   /* Step 7: Program the external memory mode register */
	   Command.CommandMode            = FMC_SDRAM_CMD_LOAD_MODE;/*set the MODE bits to "100" */
	   Command.ModeRegisterDefinition =  (uint32_t)0 | 0<<3 | 2<<4 | 0<<7 | 1<<9;
	   HAL_SDRAM_SendCommand(hsdram1, &Command, 0xfff);
	   /* Step 8: Set the refresh rate counter - refer to section SDRAM refresh timer register in RM0455 */
	   /* Set the device refresh rate
	    * COUNT = [(SDRAM self refresh time / number of row) x  SDRAM CLK] – 20
	            = [(64ms/4096) * 100MHz] - 20 = 1562.5 - 20 ~ 1542 */
	   HAL_SDRAM_ProgramRefreshRate(hsdram1, 1542);
}


