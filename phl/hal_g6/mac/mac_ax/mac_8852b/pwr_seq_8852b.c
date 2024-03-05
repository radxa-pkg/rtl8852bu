/******************************************************************************
 *
 * Copyright(c) 2019 Realtek Corporation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of version 2 of the GNU General Public License as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 ******************************************************************************/

#include "../pwr.h"
#if MAC_AX_8852B_SUPPORT

static struct mac_pwr_cfg mac_pwron_8852b[] = {
	{0x1086,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_SDIO,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, BIT(0), 0},
	{0x1086,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_SDIO,
	 PWR_BASE_MAC,
	 PWR_CMD_POLL, BIT(1), BIT(1)},
	{0x0005,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, BIT(4) | BIT(3), 0},
	{0x0005,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, BIT(7), 0},
	{0x0005,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, BIT(2), 0},
	{0x0006,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_POLL, BIT(1), BIT(1)},
	{0x0006,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, BIT(0), BIT(0)},
	{0x0005,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, BIT(0), BIT(0)},
	{0x0005,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_POLL, BIT(0), 0},
	{0x0088,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, BIT(0), BIT(0)},
	{0x0071,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_PCIE,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, BIT(4), 0},
	{0x0018,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, BIT(6), BIT(6)},
	{0x0270,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x90},
	{0x0271,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x40},
	{0x0272,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x40},
	{0x0273,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x80},
	{0x0273,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_POLL, BIT(7), 0},
	{0x0018,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, BIT(5), BIT(5)},
	{0x0270,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x90},
	{0x0271,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x20},
	{0x0272,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x20},
	{0x0273,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x80},
	{0x0273,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_POLL, BIT(7), 0},
	{0x0270,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x90},
	{0x0271,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x04},
	{0x0272,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x04},
	{0x0273,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x80},
	{0x0273,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_POLL, BIT(7), 0},
	{0x0270,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x90},
	{0x0271,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x08},
	{0x0272,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x08},
	{0x0273,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x80},
	{0x0273,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_POLL, BIT(7), 0},
	{0x0270,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x90},
	{0x0271,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x00},
	{0x0272,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x10},
	{0x0273,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x80},
	{0x0273,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_POLL, BIT(7), 0},
	{0x0270,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x90},
	{0x0271,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x01},
	{0x0272,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x01},
	{0x0273,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x80},
	{0x0273,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_POLL, BIT(7), 0},
	{0x0270,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x90},
	{0x0271,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x02},
	{0x0272,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x02},
	{0x0273,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x80},
	{0x0273,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_POLL, BIT(7), 0},
	{0x0270,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x90},
	{0x0271,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x00},
	{0x0272,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x80},
	{0x0273,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x80},
	{0x0273,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_POLL, BIT(7), 0},
	{0x0001,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, BIT(0), BIT(0)},
	{0x0001,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, BIT(7), 0},
	{0x0001,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, BIT(6), 0},
	{0xFFFF,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 0,
	 PWR_CMD_END, 0, 0},
};

static struct mac_pwr_cfg mac_pwroff_8852b[] = {
	{0x0270,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x90},
	{0x0271,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x10},
	{0x0272,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x10},
	{0x0273,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x80},
	{0x0273,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_POLL, BIT(7), 0},
	{0x0270,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x90},
	{0x0271,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x00},
	{0x0272,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x08},
	{0x0273,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x80},
	{0x0273,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_POLL, BIT(7), 0},
	{0x0270,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x90},
	{0x0271,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x00},
	{0x0272,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x04},
	{0x0273,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x80},
	{0x0273,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_POLL, BIT(7), 0},
	{0x0270,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x80},
	{0x0271,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x00},
	{0x0272,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x01},
	{0x0273,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x80},
	{0x0273,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_POLL, BIT(7), 0},
	{0x0270,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x81},
	{0x0271,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x00},
	{0x0272,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x01},
	{0x0273,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x80},
	{0x0273,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_POLL, BIT(7), 0},
	{0x0270,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x90},
	{0x0271,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x80},
	{0x0272,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x80},
	{0x0273,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x80},
	{0x0273,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_POLL, BIT(7), 0},
	{0x0270,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x90},
	{0x0271,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x00},
	{0x0272,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x02},
	{0x0273,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x80},
	{0x0273,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_POLL, BIT(7), 0},
	{0x0270,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x90},
	{0x0271,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x00},
	{0x0272,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x01},
	{0x0273,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x80},
	{0x0273,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_POLL, BIT(7), 0},
	{0x0006,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, BIT(0), BIT(0)},
	{0x0002,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, BIT(1), 0},
	{0x0018,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, BIT(5), 0},
	{0x0270,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x90},
	{0x0271,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x00},
	{0x0272,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x20},
	{0x0273,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x80},
	{0x0273,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_POLL, BIT(7), 0},
	{0x0018,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, BIT(6), 0},
	{0x0270,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x90},
	{0x0271,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x00},
	{0x0272,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x40},
	{0x0273,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x80},
	{0x0273,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_POLL, BIT(7), 0},
	{0x0005,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, BIT(1), BIT(1)},
	{0x0005,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_POLL, BIT(1), 0},
	{0x0091,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_PCIE,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, BIT(0), 0},
	{0x0005,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_PCIE,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, BIT(2), BIT(2)},
	{0x0007,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_USB,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, BIT(4), 0},
	{0x0007,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_SDIO,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, BIT(6) | BIT(4), 0},
	{0x0005,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_USB | PWR_INTF_MSK_SDIO,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, BIT(4) | BIT(3), BIT(3)},
	{0x1086,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_SDIO,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, BIT(0), BIT(0)},
	{0x1086,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_SDIO,
	 PWR_BASE_MAC,
	 PWR_CMD_POLL, BIT(1), 0},
	{0xFFFF,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 0,
	 PWR_CMD_END, 0, 0},
};

/* Power on sequence */
struct mac_pwr_cfg *pwr_on_seq_8852b[] = {
	mac_pwron_8852b,
	NULL
};

/* Power off sequence */
struct mac_pwr_cfg *pwr_off_seq_8852b[] = {
	mac_pwroff_8852b,
	NULL
};

#if MAC_AX_FEATURE_HV

static struct mac_pwr_cfg mac_carddisable_seq_8852b[] = {
	{0xFFFF,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 0,
	 PWR_CMD_END, 0, 0},
};

static struct mac_pwr_cfg mac_enterlps_seq_8852b[] = {
	{0x0068,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, BIT(6), 0},
	{0x8394,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, BIT(2), BIT(2)},
	{0x8398,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0xC4},
	{0x8399,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x04},
	{0x839A,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x40},
	{0x839B,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x80},
	{0x8398,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x00},
	{0x8399,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0xB4},
	{0x839A,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x41},
	{0x839B,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x80},
	{0x8398,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x04},
	{0x8399,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x00},
	{0x839A,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x42},
	{0x839B,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x80},
	{0x8398,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x00},
	{0x8399,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x00},
	{0x839A,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x43},
	{0x839B,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x80},
	{0x8398,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x00},
	{0x8399,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x7D},
	{0x839A,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x44},
	{0x839B,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x80},
	{0x8398,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x00},
	{0x8399,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x00},
	{0x839A,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x45},
	{0x839B,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x80},
	{0x8398,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x01},
	{0x8399,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x00},
	{0x839A,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x48},
	{0x839B,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x80},
	{0x8398,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_POLL, BIT(2), BIT(2)},
	{0x8398,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, BIT(1), BIT(1)},
	{0x8399,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x00},
	{0x839A,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x48},
	{0x839B,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x80},
	{0x8300,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, BIT(0), BIT(0)},
	{0x8322,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, BIT(0), BIT(0)},
	{0x8322,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_POLL, BIT(1), BIT(1)},
	{0x0270,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0xA1},
	{0x0271,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x02},
	{0x0272,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x02},
	{0x0273,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x80},
	{0x0273,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_POLL, BIT(7), 0},
	{0x0270,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x90},
	{0x0271,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x10},
	{0x0272,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x10},
	{0x0273,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x80},
	{0x0273,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_POLL, BIT(7), 0},
	{0x0270,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x90},
	{0x0271,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x00},
	{0x0272,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x08},
	{0x0273,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x80},
	{0x0273,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_POLL, BIT(7), 0},
	{0x0270,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x90},
	{0x0271,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x00},
	{0x0272,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x04},
	{0x0273,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x80},
	{0x0273,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_POLL, BIT(7), 0},
	{0x0270,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x80},
	{0x0271,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x00},
	{0x0272,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x01},
	{0x0273,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x80},
	{0x0273,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_POLL, BIT(7), 0},
	{0x0270,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x81},
	{0x0271,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x00},
	{0x0272,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x01},
	{0x0273,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x80},
	{0x0273,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_POLL, BIT(7), 0},
	{0x0018,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, BIT(5), 0},
	{0x0270,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x90},
	{0x0271,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x00},
	{0x0272,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x20},
	{0x0273,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x80},
	{0x0273,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_POLL, BIT(7), 0},
	{0x0018,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, BIT(6), 0},
	{0x0270,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x90},
	{0x0271,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x00},
	{0x0272,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x40},
	{0x0273,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x80},
	{0x0273,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_POLL, BIT(7), 0},
	{0x0090,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_SDIO,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0xB0},
	{0x0091,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_SDIO,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0xA1},
	{0x0092,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_SDIO,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x80},
	{0x0093,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_SDIO,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x04},
	{0x0090,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_PCIE | PWR_INTF_MSK_USB,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0xB0},
	{0x0091,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_PCIE | PWR_INTF_MSK_USB,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0xA1},
	{0x0092,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_PCIE | PWR_INTF_MSK_USB,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x81},
	{0x0093,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_PCIE | PWR_INTF_MSK_USB,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x04},
	{0x0090,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, BIT(0), BIT(0)},
	{0x0090,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_POLL, BIT(0), 0},
	{0xFFFF,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 0,
	 PWR_CMD_END, 0, 0},
};

static struct mac_pwr_cfg mac_leavelps_seq_8852b[] = {
	{0x1083,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_SDIO,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, BIT(7), BIT(7)},
	{0x10C1,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_PCIE,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, BIT(7), BIT(7)},
	{0x1203,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_USB,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, BIT(7), BIT(7)},
	{0x1E5,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_POLL, BIT(7), BIT(7)},
	{0x10,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_DELAY, PWR_DELAY_MS, PWR_DELAY_MS},
	{0x8322,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, BIT(0), 0},
	{0x8322,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_POLL, BIT(1), 0},
	{0x1083,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_SDIO,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, BIT(7), 0},
	{0x10C1,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_PCIE,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, BIT(7), 0},
	{0x1203,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_USB,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, BIT(7), 0},
	{0x8304,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, BIT(0), BIT(0)},
	{0x0018,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, BIT(6), BIT(6)},
	{0x0270,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x90},
	{0x0271,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x40},
	{0x0272,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x40},
	{0x0273,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x80},
	{0x0273,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_POLL, BIT(7), 0},
	{0x0018,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, BIT(5), BIT(5)},
	{0x0270,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x90},
	{0x0271,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x20},
	{0x0272,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x20},
	{0x0273,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x80},
	{0x0273,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_POLL, BIT(7), 0},
	{0x0270,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x90},
	{0x0271,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x04},
	{0x0272,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x04},
	{0x0273,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x80},
	{0x0273,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_POLL, BIT(7), 0},
	{0x0270,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x90},
	{0x0271,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x08},
	{0x0272,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x08},
	{0x0273,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x80},
	{0x0273,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_POLL, BIT(7), 0},
	{0x0270,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x90},
	{0x0271,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x00},
	{0x0272,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x10},
	{0x0273,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x80},
	{0x0273,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_POLL, BIT(7), 0},
	{0x0270,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x80},
	{0x0271,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x01},
	{0x0272,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x01},
	{0x0273,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x80},
	{0x0273,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_POLL, BIT(7), 0},
	{0x0270,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x81},
	{0x0271,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x01},
	{0x0272,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x01},
	{0x0273,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x80},
	{0x0273,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_POLL, BIT(7), 0},
	{0x0270,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0xA1},
	{0x0271,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x00},
	{0x0272,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x02},
	{0x0273,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x80},
	{0x0273,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_POLL, BIT(7), 0},
	{0x0270,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x90},
	{0x0271,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x80},
	{0x0272,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x80},
	{0x0273,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x80},
	{0x0273,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_POLL, BIT(7), 0},
	{0x0270,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x90},
	{0x0271,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x00},
	{0x0272,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x02},
	{0x0273,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x80},
	{0x0273,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_POLL, BIT(7), 0},
	{0x0270,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x90},
	{0x0271,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x00},
	{0x0272,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x01},
	{0x0273,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_WRITE, 0xFF, 0x80},
	{0x0273,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 PWR_BASE_MAC,
	 PWR_CMD_POLL, BIT(7), 0},
	{0xFFFF,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 0,
	 PWR_CMD_END, 0, 0},
};

static struct mac_pwr_cfg mac_ips_seq_8852b[] = {
	{0xFFFF,
	 PWR_CVALL_MSK,
	 PWR_INTF_MSK_ALL,
	 0,
	 PWR_CMD_END, 0, 0},
};

struct mac_pwr_cfg *card_disable_seq_8852b[] = {
	mac_carddisable_seq_8852b,
	NULL
};

struct mac_pwr_cfg *enter_lps_seq_8852b[] = {
	mac_enterlps_seq_8852b,
	NULL
};

struct mac_pwr_cfg *leave_lps_seq_8852b[] = {
	mac_leavelps_seq_8852b,
	NULL
};

struct mac_pwr_cfg *ips_seq_8852b[] = {
	mac_ips_seq_8852b,
	NULL
};

#endif

#endif /* #if MAC_AX_8852B_SUPPORT */
