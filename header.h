/*
 * header.h
 *
 *  Created on: Apr 1, 2014
 *      Author: C15Jason.Mossing
 */

#ifndef HEADER_H_
#define HEADER_H_

unsigned char space = 0x20;
unsigned char NewLine = 0x0A;
unsigned char CR = 0x0D;

unsigned char outputUpperled(unsigned char c);
unsigned char outputLowerled(unsigned char c);
int checkLED(unsigned char c1, unsigned char c2, unsigned char c3);
unsigned char getLEDVal();


#endif /* HEADER_H_ */
