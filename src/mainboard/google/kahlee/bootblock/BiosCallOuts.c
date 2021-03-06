/*
 * This file is part of the coreboot project.
 *
 * Copyright (C) 2015-2016 Advanced Micro Devices, Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 2 of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include <AGESA.h>
#include <BiosCallOuts.h>
#include <FchPlatform.h>
#include <soc/southbridge.h>
#include <stdlib.h>

extern const GPIO_CONTROL oem_kahlee_gpio[];

static AGESA_STATUS fch_initreset(UINT32 Func, UINTN FchData, VOID *ConfigPtr)
{
	AMD_CONFIG_PARAMS *StdHeader = ConfigPtr;

	if (StdHeader->Func == AMD_INIT_RESET) {
		FCH_RESET_DATA_BLOCK *FchParams_reset;
		FchParams_reset = (FCH_RESET_DATA_BLOCK *)FchData;
		printk(BIOS_DEBUG, "Fch OEM config in INIT RESET ");
		FchParams_reset->FchReset.SataEnable = sb_sata_enable();
		FchParams_reset->FchReset.IdeEnable = sb_ide_enable();
		FchParams_reset->EarlyOemGpioTable = oem_kahlee_gpio;
		printk(BIOS_DEBUG, "Done\n");
	}

	return AGESA_SUCCESS;
}

const BIOS_CALLOUT_STRUCT BiosCallouts[] = {
	{AGESA_FCH_OEM_CALLOUT,          fch_initreset },
	{AGESA_GNB_PCIE_SLOT_RESET,      agesa_PcieSlotResetControl }
};

const int BiosCalloutsLen = ARRAY_SIZE(BiosCallouts);
