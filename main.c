/*
 * main.c
 *
 *  Created on: Mar 30, 2014
 *      Author: C15Jason.Mossing
 */

#include <xuartlite_l.h>
#include <xparameters.h>
#include <xil_io.h>
#include <header.h>

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
			unsigned char led = getLEDVal();
			Xil_Out8(0x83000000, led);
		}

		XUartLite_SendByte(0x84000000, NewLine);
		XUartLite_SendByte(0x84000000, CR);

	}
	return 0;
}

//this function is to be similar to the nibble to byte
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
