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
 *    Sam Grove  - added method to check the status of the Ethernet cable 
 *******************************************************************************/

#if !defined(K64F_H)
#define K64F_H

C12832 lcd(D11, D13, D12, D7, D10);
BusOut led2 (LED_BLUE);
BusOut r (D5);
BusOut g (D9);
BusOut b (D8);
DigitalIn Up(A2); DigitalIn Down(A3); DigitalIn Right(A4); DigitalIn Left(A5); DigitalIn Click(D4);
AnalogIn ain1(A0); AnalogIn ain2(A1);

#define LED2_OFF 1
#define LED2_ON 0

#define DEFAULT_TYPE_NAME "iotsample-mbed-k64f"

//#include "lpc_phy.h"
// need a wrapper since K64F and LPC1768 wont have the same name for mii read methods
static uint32_t linkStatus(void)
{
    return (1);
}

#endif