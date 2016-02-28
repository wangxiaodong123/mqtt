/*******************************************************************************
 * Copyright (c) 2014 IBM Corp.
 *
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * and Eclipse Distribution License v1.0 which accompany this distribution.
 *
 * The Eclipse Public License is available at
 *    http://www.eclipse.org/legal/epl-v10.html
 * and the Eclipse Distribution License is available at
 *   http://www.eclipse.org/org/documents/edl-v10.php.
 *
 * Contributors:
 *    Ian Craggs - initial implementation
 *    Sam Grove  - added mehtod to check the status of the Ethernet cable
 *******************************************************************************/

#if !defined(LPC1768_H)
#define LPC1768_H

C12832 lcd(p5, p7, p6, p8, p11);
DigitalOut led2(LED2);
PwmOut r(p23);
PwmOut g(p24);
PwmOut b(p25);
DigitalIn Down(p12);
DigitalIn Left(p13);
DigitalIn Click(p14);
DigitalIn Up(p15);
DigitalIn Right(p16);
AnalogIn ain1(p19);
AnalogIn ain2(p20);

#define LED2_OFF 0
#define LED2_ON 1

#define DEFAULT_TYPE_NAME "iotsample-mbed-lpc1768"

#include "lpc_phy.h"
// need a wrapper since K64F and LPC1768 wont have the same name for mii read methods
static uint32_t linkStatus(void)
{
    return (lpc_mii_read_data() & 1);
}

#endif