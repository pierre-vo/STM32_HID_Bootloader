/*
* STM32 HID Bootloader - USB HID bootloader for STM32F10X
* Copyright (c) 2018 Bruno Freitas - bruno@brunofreitas.com
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stm32f10x.h>
#include "config.h"
#include "led.h"

void pins_init(void)
{
	SET_BIT(RCC->APB2ENR,
		LED1_CLOCK | LED2_CLOCK | DISC_CLOCK | BOOT_CLOCK | AFIO_CLOCK);

#if defined DISABLE_DEBUG
	RCC->APB2ENR;
	AFIO->MAPR = DISABLE_DEBUG;
#endif

	LED1_BIT_0;
	LED1_BIT_1;
	LED1_MODE;

	LED2_BIT_0;
	LED2_BIT_1;
	LED2_MODE;

	DISC_BIT_0;
	DISC_BIT_1;
	DISC_MODE;
	DISC_LOW;


#if defined PB2_PULLDOWN
	INIT_REG(GPIOB->CRL, 2, GPIO_CRL_CNF2_1);
	WRITE_REG(GPIOB->BSRR, GPIO_BSRR_BR2);

#else

	BOOT_BIT_0;
	BOOT_BIT_1;
	BOOT_SETUP;
	/* PB2 is already in FLOATING mode by default. */
#endif

}
