//On PC

#include <stdio.h>
#include <string.h>

void display();
void reset();
void perform_movement(char);
void make_copy();
void U();
void D();
void L();
void R();
void F();
void B();

char cube[54];
char cube_copy[54];

int main() {	
	reset();
	
	char input[100];
	printf("Enter Movement: ");
	fgets(input, 100, stdin);
	
	for (int i=0; i<strlen(input)-1; i++) {
		perform_movement(input[i]);
	}
	
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

void perform_movement(char input_movement)
{
	switch (input_movement) {
		case 'U':
			U();
			break;
		case 'D':
			D();
			break;
		case 'L':
			L();
			break;
		case 'R':
			R();
			break;
		case 'F':
			F();
			break;
		case 'B':
			B();
			break;
		case ' ':
			break;
		default:
			printf("\nInvalid Move: %c", input_movement);
	}
}

void make_copy()
{
	for (int i=0; i<54; i++) {
		cube_copy[i] = cube[i];
	}
}

void U()
{
	make_copy();
	
	cube[9]  = cube_copy[18];
	cube[10] = cube_copy[19];
	cube[11] = cube_copy[20];
	cube[18] = cube_copy[27];
	cube[19] = cube_copy[28];
	cube[20] = cube_copy[29];
	cube[27] = cube_copy[36];
	cube[28] = cube_copy[37];
	cube[29] = cube_copy[38];
	cube[36] = cube_copy[9] ;
	cube[37] = cube_copy[10];
	cube[38] = cube_copy[11];
	
	cube[0]  = cube_copy[6] ;
	cube[1]  = cube_copy[3] ;
	cube[2]  = cube_copy[0] ;
	cube[3]  = cube_copy[7] ;
	cube[4]  = cube_copy[4] ;
	cube[5]  = cube_copy[1] ;
	cube[6]  = cube_copy[8] ;
	cube[7]  = cube_copy[5] ;
	cube[8]  = cube_copy[2] ;
}

void D()
{
	make_copy();
	
	cube[15] = cube_copy[42];
	cube[16] = cube_copy[43];
	cube[17] = cube_copy[44];
	cube[24] = cube_copy[15];
	cube[25] = cube_copy[16];
	cube[26] = cube_copy[17];
	cube[33] = cube_copy[24];
	cube[34] = cube_copy[25];
	cube[35] = cube_copy[26];
	cube[42] = cube_copy[33];
	cube[43] = cube_copy[34];
	cube[44] = cube_copy[35];
	
	cube[45] = cube_copy[51];
	cube[46] = cube_copy[48];
	cube[47] = cube_copy[45];
	cube[48] = cube_copy[52];
	cube[49] = cube_copy[49];
	cube[50] = cube_copy[46];
	cube[51] = cube_copy[53];
	cube[52] = cube_copy[50];
	cube[53] = cube_copy[47];
}

void L()
{
	make_copy();
	
	cube[0]  = cube_copy[44];
	cube[3]  = cube_copy[41];
	cube[6]  = cube_copy[38];
	cube[18] = cube_copy[0] ;
	cube[21] = cube_copy[3] ;
	cube[24] = cube_copy[6] ;
	cube[45] = cube_copy[18];
	cube[48] = cube_copy[21];
	cube[51] = cube_copy[24];
	cube[44] = cube_copy[45];
	cube[41] = cube_copy[48];
	cube[38] = cube_copy[51];
	
	cube[9]  = cube_copy[15];
	cube[10] = cube_copy[12];
	cube[11] = cube_copy[9] ;
	cube[12] = cube_copy[16];
	cube[13] = cube_copy[13];
	cube[14] = cube_copy[10];
	cube[15] = cube_copy[17];
	cube[16] = cube_copy[14];
	cube[17] = cube_copy[11];
}

void R()
{
	make_copy();
	
	cube[2]  = cube_copy[20];
	cube[5]  = cube_copy[23];
	cube[8]  = cube_copy[26];
	cube[20] = cube_copy[47];
	cube[23] = cube_copy[50];
	cube[26] = cube_copy[53];
	cube[47] = cube_copy[42];
	cube[50] = cube_copy[39];
	cube[53] = cube_copy[36];
	cube[42] = cube_copy[2] ;
	cube[39] = cube_copy[5] ;
	cube[36] = cube_copy[8] ;
	
	cube[27] = cube_copy[33];
	cube[28] = cube_copy[30];
	cube[29] = cube_copy[27];
	cube[30] = cube_copy[34];
	cube[31] = cube_copy[31];
	cube[32] = cube_copy[28];
	cube[33] = cube_copy[35];
	cube[34] = cube_copy[32];
	cube[35] = cube_copy[29];
}

void F()
{
	make_copy();
	
	cube[6]  = cube_copy[17];
	cube[7]  = cube_copy[14];
	cube[8]  = cube_copy[11];
	cube[17] = cube_copy[47];
	cube[14] = cube_copy[46];
	cube[11] = cube_copy[45];
	cube[47] = cube_copy[27];
	cube[46] = cube_copy[30];
	cube[45] = cube_copy[33];
	cube[27] = cube_copy[6] ;
	cube[30] = cube_copy[7] ;
	cube[33] = cube_copy[8] ;
	
	cube[18] = cube_copy[24];
	cube[19] = cube_copy[21];
	cube[20] = cube_copy[18];
	cube[21] = cube_copy[25];
	cube[22] = cube_copy[22];
	cube[23] = cube_copy[19];
	cube[24] = cube_copy[26];
	cube[25] = cube_copy[23];
	cube[26] = cube_copy[20];
}

void B()
{
	make_copy();
	
	cube[0]  = cube_copy[29];
	cube[1]  = cube_copy[32];
	cube[2]  = cube_copy[35];
	cube[29] = cube_copy[53];
	cube[32] = cube_copy[52];
	cube[35] = cube_copy[51];
	cube[53] = cube_copy[15];
	cube[52] = cube_copy[12];
	cube[51] = cube_copy[9] ;
	cube[15] = cube_copy[0] ;
	cube[12] = cube_copy[1] ;
	cube[9]  = cube_copy[2] ;
	
	cube[36] = cube_copy[42];
	cube[37] = cube_copy[39];
	cube[38] = cube_copy[36];
	cube[39] = cube_copy[43];
	cube[40] = cube_copy[40];
	cube[41] = cube_copy[37];
	cube[42] = cube_copy[44];
	cube[43] = cube_copy[41];
	cube[44] = cube_copy[38];
}
