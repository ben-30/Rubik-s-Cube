//On PC

#include <stdio.h>
#include <string.h>

void display();
void reset();
void U();

char cube[54];

int main() {	
	reset();
	U();
	display();
}

void display() {
	printf("\nCube!!!\n");
	
	printf("\nU: ");
	for (int i=0; i<9; i++) {
		if ( ((i+1)%3) == 0 ) {
			printf("%c\n   ", cube[i]);
		} else {
			printf("%c ", cube[i]);
		}
	}
	printf("\nL: ");
	for (int i=9; i<18; i++) {
		if ( ((i+1)%3) == 0 ) {
			printf("%c\n   ", cube[i]);
		} else {
			printf("%c ", cube[i]);
		}
	}
	printf("\nF: ");
	for (int i=18; i<27; i++) {
		if ( ((i+1)%3) == 0 ) {
			printf("%c\n   ", cube[i]);
		} else {
			printf("%c ", cube[i]);
		}
	}
	printf("\nR: ");
	for (int i=27; i<36; i++) {
		if ( ((i+1)%3) == 0 ) {
			printf("%c\n   ", cube[i]);
		} else {
			printf("%c ", cube[i]);
		}
	}
	printf("\nB: ");
	for (int i=36; i<45; i++) {
		if ( ((i+1)%3) == 0 ) {
			printf("%c\n   ", cube[i]);
		} else {
			printf("%c ", cube[i]);
		}
	}
	printf("\nD: ");
	for (int i=45; i<54; i++) {
		if ( ((i+1)%3) == 0 ) {
			printf("%c\n   ", cube[i]);
		} else {
			printf("%c ", cube[i]);
		}
	}
}

void reset() {
	for (int i=0; i<9; i++) {
		cube[i] = 'W';
	}
	for (int i=9; i<18; i++) {
		cube[i] = 'O';
	}
	for (int i=18; i<27; i++) {
		cube[i] = 'G';
	}
	for (int i=27; i<36; i++) {
		cube[i] = 'R';
	}
	for (int i=36; i<45; i++) {
		cube[i] = 'B';
	}
	for (int i=45; i<54; i++) {
		cube[i] = 'Y';
	}
}

void U()
{
	char temp[54];
	memcpy(temp, cube, sizeof cube);
	
	cube[9]  = temp[18];
	cube[10] = temp[19];
	cube[11] = temp[20];
	cube[18] = temp[27];
	cube[19] = temp[28];
	cube[20] = temp[29];
	cube[27] = temp[36];
	cube[28] = temp[37];
	cube[29] = temp[38];
	cube[36] = temp[9] ;
	cube[37] = temp[10];
	cube[38] = temp[11];
}

