/*
 * main.c
 *
 *  Created on: Mar 30, 2014
 *      Author: C15Jason.Mossing
 */

#include <xuartlite_l.h>
#include <xparameters.h>
#include <xil_io.h>
#include "header.h"

unsigned char space = 0x20;
unsigned char NewLine = 0x0A;
unsigned char CR = 0x0D;

int main(void){
	while(1){
		unsigned char c1, c2, c3;
		c1 = XUartLite_RecvByte(0x84000000);
		XUartLite_SendByte(0x84000000, c1);

		c2 = XUartLite_RecvByte(0x84000000);
		XUartLite_SendByte(0x84000000, c2);

		c3 = XUartLite_RecvByte(0x84000000);
		XUartLite_SendByte(0x84000000, c3);

		if(checkLED(c1, c2, c3)){
			XUartLite_SendByte(0x84000000, space);
			unsigned char led = getLEDVal();
			Xil_Out8(0x83000000, led);
		}
		if(checkSWT(c1, c2, c3)){
			XUartLite_SendByte(0x84000000, space);
			unsigned char swt = Xil_In8(0x82000000);
			outputSWT(swt);
		}
		if(checkVGA(c1, c2, c3)){
			XUartLite_SendByte(0x84000000, space);
			unsigned char color = XUartLite_RecvByte(0x84000000);
			XUartLite_SendByte(0x84000000, color);
		}

		XUartLite_SendByte(0x84000000, NewLine);
		XUartLite_SendByte(0x84000000, CR);

	}
	return 0;
}

unsigned char getLEDVal(){
	unsigned char upper, lower;
	upper = XUartLite_RecvByte(0x84000000);
	XUartLite_SendByte(0x84000000, upper);
	lower = XUartLite_RecvByte(0x84000000);
	XUartLite_SendByte(0x84000000, lower);
	upper = outputUpperled(upper);
	lower = outputLowerled(lower);
	return upper & lower;
}

unsigned char outputUpperled(unsigned char c){
	unsigned char out;
	if(c == '0'){
		out = 0b00001111;
	}
	else if(c == '1'){
		out = 0b00011111;
	}
	else if(c == '2'){
		out = 0b00101111;
	}
	else if(c == '3'){
		out = 0b00111111;
	}
	else if(c == '4'){
		out = 0b01001111;
	}
	else if(c == '5'){
		out = 0b01011111;
	}
	else if(c == '6'){
		out = 0b01101111;
	}
	else if(c == '7'){
		out = 0b01111111;
	}
	else if(c == '8'){
		out = 0b10001111;
	}
	else if(c == '9'){
		out = 0b10011111;
	}
	else if(c == 'A'){
		out = 0b10101111;
	}
	else if(c == 'B'){
		out = 0b10111111;
	}
	else if(c == 'C'){
		out = 0b11001111;
	}
	else if(c == 'D'){
		out = 0b11011111;
	}
	else if(c == 'E'){
		out = 0b11101111;
	}
	else{
		out = 0b11111111;
	}

	return out;
}

unsigned char outputLowerled(unsigned char c){
	unsigned char out;
	if(c == '0'){
		out = 0b11110000;
	}
	else if(c == '1'){
		out = 0b11110001;
	}
	else if(c == '2'){
		out = 0b11110010;
	}
	else if(c == '3'){
		out = 0b11110011;
	}
	else if(c == '4'){
		out = 0b11110100;
	}
	else if(c == '5'){
		out = 0b11110101;
	}
	else if(c == '6'){
		out = 0b11110110;
	}
	else if(c == '7'){
		out = 0b11110111;
	}
	else if(c == '8'){
		out = 0b11111000;
	}
	else if(c == '9'){
		out = 0b11111001;
	}
	else if(c == 'A'){
		out = 0b11111010;
	}
	else if(c == 'B'){
		out = 0b11111011;
	}
	else if(c == 'C'){
		out = 0b11111100;
	}
	else if(c == 'D'){
		out = 0b11111101;
	}
	else if(c == 'E'){
		out = 0b11111110;
	}
	else{
		out = 0b11111111;
	}

	return out;
}

int checkLED(unsigned char c1, unsigned char c2, unsigned char c3){
	if((c1 == 'l') && (c2 == 'e') && (c3 == 'd')){
		return 1;
	}
	else{
		return 0;
	}
}

int checkSWT(unsigned char c1, unsigned char c2, unsigned char c3){
	if((c1 == 's') && (c2 == 'w') && (c3 == 't')){
		return 1;
	}
	else{
		return 0;
	}
}


int checkVGA(unsigned char c1, unsigned char c2, unsigned char c3){
	if((c1 == 'v') && (c2 == 'g') && (c3 == 'a')){
		return 1;
	}
	else{
		return 0;
	}
}

unsigned char getTopNibble(unsigned char ascii){
	unsigned char top;
	top = ascii & 0b11110000;
	return top;
}

unsigned char getBtmNibble(unsigned char ascii){
	unsigned char btm;
	btm = ascii & 0b00001111;
	return btm;
}

void outputSWT(unsigned char ascii){
	unsigned char top, btm;
	top = getTopNibble(ascii);
	btm = getBtmNibble(ascii);
	top = topNibbleToAscii(top);
	btm = btmNibbleToAscii(btm);
	XUartLite_SendByte(0x84000000, top);
	XUartLite_SendByte(0x84000000, btm);
}

unsigned char topNibbleToAscii(unsigned char nibble){
	unsigned char out;
		if(nibble == 0b00000000){
			out = '0';
		}
		else if(nibble == 0b00010000){
			out = '1';
		}
		else if(nibble == 0b00100000){
			out = '2';
		}
		else if(nibble == 0b00110000){
			out = '3';
		}
		else if(nibble == 0b01000000){
			out = '4';
		}
		else if(nibble == 0b01010000){
			out = '5';
		}
		else if(nibble == 0b01100000){
			out = '6';
		}
		else if(nibble == 0b01110000){
			out = '7';
		}
		else if(nibble == 0b10000000){
			out = '8';
		}
		else if(nibble == 0b10010000){
			out = '9';
		}
		else if(nibble == 0b10100000){
			out = 'A';
		}
		else if(nibble == 0b10110000){
			out = 'B';
		}
		else if(nibble == 0b11000000){
			out = 'C';
		}
		else if(nibble == 0b11010000){
			out = 'D';
		}
		else if(nibble == 0b11100000){
			out = 'E';
		}
		else{
			out = 'F';
		}

		return out;
}

unsigned char btmNibbleToAscii(unsigned char nibble){
	unsigned char out;
		if(nibble == 0b00000000){
			out = '0';
		}
		else if(nibble == 0b00000001){
			out = '1';
		}
		else if(nibble== 0b00000010){
			out = '2';
		}
		else if(nibble == 0b00000011){
			out = '3';
		}
		else if(nibble == 0b00000100){
			out = '4';
		}
		else if(nibble == 0b00000101){
			out = '5';
		}
		else if(nibble == 0b00000110){
			out = '6';
		}
		else if(nibble == 0b00000111){
			out = '7';
		}
		else if(nibble == 0b00001000){
			out = '8';
		}
		else if(nibble == 0b00001001){
			out = '9';
		}
		else if(nibble == 0b00001010){
			out = 'A';
		}
		else if(nibble == 0b00001011){
			out = 'B';
		}
		else if(nibble == 0b00001100){
			out = 'C';
		}
		else if(nibble == 0b00001101){
			out = 'D';
		}
		else if(nibble == 0b00001110){
			out = 'E';
		}
		else{
			out = 'F';
		}

		return out;
}
