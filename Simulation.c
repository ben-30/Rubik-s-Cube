//On PC

#include <stdio.h>
#include <string.h>

void display();
void reset();
void U();
void D();
void L();
void R();
void F();
void B();

char cube[54];

int main() {	
	reset();
	//U();
	//D();
	//L();
	//R();
	//F();
	//B();
	display();
}

void display()
{
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

void reset()
{
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

void D()
{
	char temp[54];
	memcpy(temp, cube, sizeof cube);
	
	cube[15] = temp[42];
	cube[16] = temp[43];
	cube[17] = temp[44];
	cube[24] = temp[15];
	cube[25] = temp[16];
	cube[26] = temp[17];
	cube[33] = temp[24];
	cube[34] = temp[25];
	cube[35] = temp[26];
	cube[42] = temp[33];
	cube[43] = temp[34];
	cube[44] = temp[35];
}

void L()
{
	char temp[54];
	memcpy(temp, cube, sizeof cube);
	
	cube[0]  = temp[44];
	cube[3]  = temp[41];
	cube[6]  = temp[38];
	cube[18] = temp[0] ;
	cube[21] = temp[3] ;
	cube[24] = temp[6] ;
	cube[45] = temp[18];
	cube[48] = temp[21];
	cube[51] = temp[24];
	cube[44] = temp[45];
	cube[41] = temp[48];
	cube[38] = temp[51];
}

void R()
{
	char temp[54];
	memcpy(temp, cube, sizeof cube);
	
	cube[2]  = temp[20];
	cube[5]  = temp[23];
	cube[8]  = temp[26];
	cube[20] = temp[47];
	cube[23] = temp[50];
	cube[26] = temp[53];
	cube[47] = temp[42];
	cube[50] = temp[39];
	cube[53] = temp[36];
	cube[42] = temp[2] ;
	cube[39] = temp[5] ;
	cube[36] = temp[8] ;
}

void F()
{
	char temp[54];
	memcpy(temp, cube, sizeof cube);
	
	cube[6]  = temp[17];
	cube[7]  = temp[14];
	cube[8]  = temp[11];
	cube[17] = temp[47];
	cube[14] = temp[46];
	cube[11] = temp[45];
	cube[47] = temp[27];
	cube[46] = temp[30];
	cube[45] = temp[33];
	cube[27] = temp[6] ;
	cube[30] = temp[7] ;
	cube[33] = temp[8] ;
}

void B()
{
	char temp[54];
	memcpy(temp, cube, sizeof cube);
	
	cube[0]  = temp[29];
	cube[1]  = temp[32];
	cube[2]  = temp[35];
	cube[29] = temp[53];
	cube[32] = temp[52];
	cube[35] = temp[51];
	cube[53] = temp[15];
	cube[52] = temp[12];
	cube[51] = temp[9] ;
	cube[15] = temp[0] ;
	cube[12] = temp[1] ;
	cube[9]  = temp[2] ;
}
