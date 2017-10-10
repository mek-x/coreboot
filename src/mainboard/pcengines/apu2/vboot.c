/*
 * Copyright (C) 2016-2017 Intel Corporation
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but without any warranty; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include <assert.h>
#include <bootmode.h>
#include <console/console.h>
#include <delay.h>
#include <device/i2c_simple.h>
#include <lib.h>
#include <vboot/vboot_common.h>
#include <vboot/vbnv.h>

int clear_recovery_mode_switch(void)
{
	/* Nothing to do */
	return 0;
}

int get_recovery_mode_switch(void)
{
	return 0;
}

int get_write_protect_state(void)
{
	/* Not write protected */
	return 0;
}

void log_recovery_mode_switch(void)
{
}

void verstage_mainboard_init(void)
{

}

void __attribute__((weak)) vboot_platform_prepare_reboot(void)
{

}

int vbnv_cmos_failed(void)
{
	/* Indicate no failure until RTC failure bits are supported. */
	return 0;
}
