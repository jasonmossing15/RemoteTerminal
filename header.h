/*
 * header.h
 *
 *  Created on: Apr 1, 2014
 *      Author: C15Jason.Mossing
 */

#ifndef HEADER_H_
#define HEADER_H_



unsigned char outputUpperled(unsigned char c);
unsigned char outputLowerled(unsigned char c);
int checkLED(unsigned char c1, unsigned char c2, unsigned char c3);
int checkSWT(unsigned char c1, unsigned char c2, unsigned char c3);
int checkVGA(unsigned char c1, unsigned char c2, unsigned char c3);
unsigned char getTopNibble(unsigned char ascii);
unsigned char getBtmNibble(unsigned char ascii);
unsigned char topNibbleToAscii(unsigned char nibble);
unsigned char btmNibbleToAscii(unsigned char nibble);
void outputSWT(unsigned char ascii);
unsigned char getLEDVal();


#endif /* HEADER_H_ */
