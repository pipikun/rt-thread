/*
 * Copyright (c) 2006-2018, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2021-02-24     carson       first version
 */

#include <rtthread.h>
#include <rtdevice.h>
#include "gd32vf103_gpio.h"

#define LED_GREEN_CLK	RCU_GPIOA
#define LED_GREEN_PORT	GPIOA
#define LED_GREEN_PIN	GPIO_PIN_1

void led_init(void)
{
	rcu_periph_clock_enable(LED_GREEN_CLK);
	gpio_init(LED_GREEN_PORT, GPIO_MODE_OUT_PP, GPIO_OSPEED_50MHZ, LED_GREEN_PIN);
	GPIO_BOP(LED_GREEN_PORT) = LED_GREEN_PIN;
}

void led_on(void)
{
	GPIO_BC(LED_GREEN_PORT) = LED_GREEN_PIN;
}

void led_off(void)
{
	GPIO_BOP(LED_GREEN_PORT) = LED_GREEN_PIN;
}

int main(int argc, char *argv[])
{
	led_init();
	while(1) {
		led_on();
		rt_thread_mdelay(500);
		led_off();
		rt_thread_mdelay(500);

	}
	return 0;
}

/******************** end of file *******************/

