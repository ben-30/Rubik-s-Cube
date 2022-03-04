
//On PC
//https://ruwix.com/the-rubiks-cube/notation/advanced/
//https://www.jaapsch.net/puzzles/compcube.htm

//WWWWWWWWWOOOOOOOOOGGGGGGGGGRRRRRRRRRBBBBBBBBBYYYYYYYYY

#include <stdio.h>
#include <string.h>

void display();
void reset();
void set(char[]);
//void perform_movement(char);
void make_copy();
void U();
void Ui();
void D();
void Di();
void L();
void Li();
void R();
void Ri();
void F();
void Fi();
void B();
void Bi();
void M();
void Mi();
void E();
void Ei();
void S();
void Si();
char get_color(int);
void yellow_cross();
void yellow_corners();

char cube[54];
char cube_copy[54];
char sequence[150];
int sequence_count = 0;

int main() {	
	//reset();
	//display();
	
	char input[54];
	printf("\nEnter Starting Cube Sequence: ");
		fgets(input, 55, stdin);
	
	set(input);
	display();
	
	yellow_cross();
	printf("\n");
	display();
	
	yellow_corners();
	printf("\n");
	display();
}

void display()
{
	printf("\nCube!!!\n\n          ");
	
	for (int i=0; i<9; i++) {
		if ( ((i+1)%3) == 0 ) {
			printf("%c\n          ", cube[i]);
		} else {
			printf("%c ", cube[i]);
		}
	}
	
	printf("\n  %c %c %c   %c %c %c   %c %c %c   %c %c %c\n", cube[9], cube[10], cube[11], cube[18], cube[19], cube[20], cube[27], cube[28], cube[29], cube[36], cube[37], cube[38]);
	printf("  %c %c %c   %c %c %c   %c %c %c   %c %c %c\n", cube[12], cube[13], cube[14], cube[21], cube[22], cube[23], cube[30], cube[31], cube[32], cube[39], cube[40], cube[41]);
	printf("  %c %c %c   %c %c %c   %c %c %c   %c %c %c\n\n          ", cube[15], cube[16], cube[17], cube[24], cube[25], cube[26], cube[33], cube[34], cube[35], cube[42], cube[43], cube[44]);
	
	for (int i=45; i<54; i++) {
		if ( ((i+1)%3) == 0 ) {
			printf("%c\n          ", cube[i]);
		} else {
			printf("%c ", cube[i]);
		}
	}
}

void reset()
{
	sequence_count = 0;
	
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

void set(char input_cube[])
{
	//printf("\nEntered Sequence: \n");
	int W_count = 0;
	int O_count = 0;
	int G_count = 0;
	int R_count = 0;
	int B_count = 0;
	int Y_count = 0;
	
	for (int i=0; i<54; i++) {
        switch (input_cube[i]) {
			case 'W':
				W_count++;
				break;
			case 'O':
				O_count++;
				break;
			case 'G':
				G_count++;
				break;
			case 'R':
				R_count++;
				break;
			case 'B':
				B_count++;
				break;
			case 'Y':
				Y_count++;
				break;
		}
    }
	
	if (W_count != 9 || O_count != 9 || G_count != 9 || R_count != 9 || B_count != 9 || Y_count != 9) {
		printf("\nInvalid Sequence!\n");
	} else {
		for (int i=0; i<54; i++) {
			cube[i] = input_cube[i];
		}
	}
}

/*perform movement
void perform_movement(char input_movement)
{
	sequence[sequence_count] = input_movement;
	sequence_count++;
	
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
		case 'u':
			Ui();
			break;
		case 'd':
			Di();
			break;
		case 'l':
			Li();
			break;
		case 'r':
			Ri();
			break;
		case 'f':
			Fi();
			break;
		case 'b':
			Bi();
			break;
		case 'M':
			M();
			break;
		case 'E':
			E();
			break;
		case 'S':
			S();
			break;
		case 'm':
			Mi();
			break;
		case 'e':
			Ei();
			break;
		case 's':
			Si();
			break;
		case ' ':
			sequence_count--;
			break;
		case '0':
			reset();
			break;
		case '1':
			sequence_count--;
			printf("\nDone");
			printf("\nPerformed Sequence: ");
			for (int i=0; i<sequence_count; i++) {
				printf("%c", sequence[i]);
			}
			printf("\n");
			break;
		default:
			sequence_count--;
			printf("\nInvalid Move: %c\n", input_movement);
	}
}*/

void make_copy()
{
	for (int i=0; i<54; i++) {
		cube_copy[i] = cube[i];
	}
}

char get_color(int spot)
{
	return cube[spot];
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

void Ui()
{
	U();
	U();
	U();
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

void Di()
{
	D();
	D();
	D();
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

void Li()
{
	L();
	L();
	L();
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

void Ri()
{
	R();
	R();
	R();
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

void Fi()
{
	F();
	F();
	F();
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

void Bi()
{
	B();
	B();
	B();
}

void M()
{
	make_copy();
	
	cube[1]  = cube_copy[43];
	cube[4]  = cube_copy[40];
	cube[7]  = cube_copy[37];
	cube[19] = cube_copy[1] ;
	cube[22] = cube_copy[4] ;
	cube[25] = cube_copy[7] ;
	cube[46] = cube_copy[19];
	cube[49] = cube_copy[22];
	cube[52] = cube_copy[25];
	cube[43] = cube_copy[46];
	cube[40] = cube_copy[49];
	cube[37] = cube_copy[52];
}

void Mi()
{
	M();
	M();
	M();
}

void E()
{
	make_copy();
	
	cube[21] = cube_copy[12];
	cube[22] = cube_copy[13];
	cube[23] = cube_copy[14];
	cube[12] = cube_copy[39];
	cube[13] = cube_copy[40];
	cube[14] = cube_copy[41];
	cube[39] = cube_copy[30];
	cube[40] = cube_copy[31];
	cube[41] = cube_copy[32];
	cube[30] = cube_copy[21];
	cube[31] = cube_copy[22];
	cube[32] = cube_copy[23];
}

void Ei()
{
	E();
	E();
	E();
}

void S()
{
	make_copy();
	
	cube[3]  = cube_copy[16];
	cube[4]  = cube_copy[13];
	cube[5]  = cube_copy[10];
	cube[16] = cube_copy[50];
	cube[13] = cube_copy[49];
	cube[10] = cube_copy[48];
	cube[50] = cube_copy[28];
	cube[49] = cube_copy[31];
	cube[48] = cube_copy[34];
	cube[28] = cube_copy[3] ;
	cube[31] = cube_copy[4] ;
	cube[34] = cube_copy[5] ;
}

void Si()
{
	S();
	S();
	S();
}

void yellow_cross()
{	
	int yellow_orange;
	int yellow_green;
	int yellow_red;
	int yellow_blue;
	
	for (int i=0; i<54; i++) {
		if (get_color(i) == 'Y') {
			switch (i) {
				case 1:
					if (get_color(37) == 'O')
						yellow_orange = 1;
					break;
				case 3:
					if (get_color(10) == 'O')
						yellow_orange = 3;
					break;
				case 5:
					if (get_color(28) == 'O')
						yellow_orange = 5;
					break;
				case 7:
					if (get_color(19) == 'O')
						yellow_orange = 7;
					break;
				case 10:
					if (get_color(3) == 'O')
						yellow_orange = 10;
					break;
				case 12:
					if (get_color(41) == 'O')
						yellow_orange = 12;
					break;
				case 14:
					if (get_color(21) == 'O')
						yellow_orange = 14;
					break;
				case 16:
					if (get_color(48) == 'O')
						yellow_orange = 16;
					break;
				case 19:
					if (get_color(7) == 'O')
						yellow_orange = 19;
					break;
				case 21:
					if (get_color(14) == 'O')
						yellow_orange = 21;
					break;
				case 23:
					if (get_color(30) == 'O')
						yellow_orange = 23;
					break;
				case 25:
					if (get_color(46) == 'O')
						yellow_orange = 25;
					break;
				case 28:
					if (get_color(5) == 'O')
						yellow_orange = 28;
					break;
				case 30:
					if (get_color(23) == 'O')
						yellow_orange = 30;
					break;
				case 32:
					if (get_color(39) == 'O')
						yellow_orange = 32;
					break;
				case 34:
					if (get_color(50) == 'O')
						yellow_orange = 34;
					break;
				case 37:
					if (get_color(1) == 'O')
						yellow_orange = 37;
					break;
				case 39:
					if (get_color(32) == 'O')
						yellow_orange = 39;
					break;
				case 41:
					if (get_color(12) == 'O')
						yellow_orange = 41;
					break;
				case 43:
					if (get_color(52) == 'O')
						yellow_orange = 43;
					break;
				case 46:
					if (get_color(25) == 'O')
						yellow_orange = 46;
					break;
				case 48:
					if (get_color(16) == 'O')
						yellow_orange = 48;
					break;
				case 50:
					if (get_color(34) == 'O')
						yellow_orange = 50;
					break;
				case 52:
					if (get_color(43) == 'O')
						yellow_orange = 52;
					break;
			}
		}
	}
	
	printf("\nYellow Orange: %d", yellow_orange);	
	printf("\nPlacing Yellow Orange: ");
	switch (yellow_orange) {
		case 1:
			printf("uLL");
			Ui();
			L();
			L();
			break;
		case 3:
			printf("LL");
			L();
			L();
			break;
		case 5:
			printf("UULL");
			U();
			U();
			L();
			L();
			break;
		case 7:
			printf("ULL");
			U();
			L();
			L();
			break;
		case 10:
			printf("ufL");
			Ui();
			Fi();
			L();
			break;
		case 12:
			printf("BD");
			B();
			D();
			break;
		case 14:
			printf("fd");
			Fi();
			Di();
			break;
		case 16:
			printf("lfd");
			Li();
			Fi();
			Di();
			break;
		case 19:
			printf("fL");
			Fi();
			L();
			break;
		case 21:
			printf("L");
			L();
			break;
		case 23:
			printf("FFL");
			F();
			F();
			L();
			break;
		case 25:
			printf("FL");
			F();
			L();
			break;
		case 28:
			printf("rFd");
			Ri();
			F();
			Di();
			break;
		case 30:
			printf("Fd");
			F();
			Di();
			break;
		case 32:
			printf("bD");
			Bi();
			D();
			break;
		case 34:
			printf("rbD");
			Ri();
			Bi();
			D();
			break;
		case 37:
			printf("Bl");
			B();
			Li();
			break;
		case 39:
			printf("RDD");
			R();
			D();
			D();
			break;
		case 41:
			printf("l");
			Li();
			break;
		case 43:
			printf("bl");
			Bi();
			Li();
			break;
		case 46:
			printf("d");
			Di();
			break;
		case 48:
			printf("Already in Place");
			break;
		case 50:			
			printf("DD");
			D();
			D();
			break;
		case 52:
			printf("D");
			D();
			break;
	}
	
	for (int i=0; i<54; i++) {
		if (get_color(i) == 'Y') {
			switch (i) {
				case 1:
					if (get_color(37) == 'G')
						yellow_green = 1;
					break;
				case 3:
					if (get_color(10) == 'G')
						yellow_green = 3;
					break;
				case 5:
					if (get_color(28) == 'G')
						yellow_green = 5;
					break;
				case 7:
					if (get_color(19) == 'G')
						yellow_green = 7;
					break;
				case 10:
					if (get_color(3) == 'G')
						yellow_green = 10;
					break;
				case 12:
					if (get_color(41) == 'G')
						yellow_green = 12;
					break;
				case 14:
					if (get_color(21) == 'G')
						yellow_green = 14;
					break;
				case 16:
					if (get_color(48) == 'G')
						yellow_green = 16;
					break;
				case 19:
					if (get_color(7) == 'G')
						yellow_green = 19;
					break;
				case 21:
					if (get_color(14) == 'G')
						yellow_green = 21;
					break;
				case 23:
					if (get_color(30) == 'G')
						yellow_green = 23;
					break;
				case 25:
					if (get_color(46) == 'G')
						yellow_green = 25;
					break;
				case 28:
					if (get_color(5) == 'G')
						yellow_green = 28;
					break;
				case 30:
					if (get_color(23) == 'G')
						yellow_green = 30;
					break;
				case 32:
					if (get_color(39) == 'G')
						yellow_green = 32;
					break;
				case 34:
					if (get_color(50) == 'G')
						yellow_green = 34;
					break;
				case 37:
					if (get_color(1) == 'G')
						yellow_green = 37;
					break;
				case 39:
					if (get_color(32) == 'G')
						yellow_green = 39;
					break;
				case 41:
					if (get_color(12) == 'G')
						yellow_green = 41;
					break;
				case 43:
					if (get_color(52) == 'G')
						yellow_green = 43;
					break;
				case 46:
					if (get_color(25) == 'G')
						yellow_green = 46;
					break;
				case 48:
					if (get_color(16) == 'G')
						yellow_green = 48;
					break;
				case 50:
					if (get_color(34) == 'G')
						yellow_green = 50;
					break;
				case 52:
					if (get_color(43) == 'G')
						yellow_green = 52;
					break;
			}
		}
	}
	
	printf("\nYellow Green: %d", yellow_green);	
	printf("\nPlacing Yellow Green: ");
	switch (yellow_green) {
		case 1:
			printf("UUFF");
			U();
			U();
			F();
			F();
			break;
		case 3:
			printf("uFF");
			Ui();
			F();
			F();
			break;
		case 5:
			printf("UFF");
			U();
			F();
			F();
			break;
		case 7:
			printf("FF");
			F();
			F();
			break;
		case 10:
			printf("Lfl");
			L();
			Fi();
			Li();
			break;
		case 12:
			printf("bUUFF");
			Bi();
			U();
			U();
			F();
			F();
			break;
		case 14:
			printf("f");
			Fi();
			break;
		case 16:
			printf("Should Never Be Here");
			break;
		case 19:
			printf("fdLD");
			Fi();
			Di();
			L();
			D();
			break;
		case 21:
			printf("dLD");
			Di();
			L();
			D();
			break;
		case 23:
			printf("Drd");
			D();
			Ri();
			Di();
			break;
		case 25:
			printf("FdLD");
			F();
			Di();
			L();
			D();
			break;
		case 28:
			printf("rFR");
			Ri();
			F();
			R();
			break;
		case 30:
			printf("F");
			F();
			break;
		case 32:
			printf("RRF");
			R();
			R();
			F();
			break;
		case 34:
			printf("RF");
			R();
			F();
			break;
		case 37:
			printf("UrFR");
			U();
			Ri();
			F();
			R();
			break;
		case 39:
			printf("DRd");
			D();
			R();
			Di();
			break;
		case 41:
			printf("BBDRd");
			B();
			B();
			D();
			R();
			Di();
			break;
		case 43:
			printf("BDRd");
			B();
			D();
			R();
			Di();
			break;
		case 46:
			printf("Already in Place");
			break;
		case 48:
			printf("Should Never Be Here");
			break;
		case 50:
			printf("RDrd");
			R();
			D();
			Ri();
			Di();
			break;
		case 52:
			printf("lDDL");
			Li();
			D();
			D();
			L();
			break;
	}
	
	for (int i=0; i<54; i++) {
		if (get_color(i) == 'Y') {
			switch (i) {
				case 1:
					if (get_color(37) == 'R')
						yellow_red = 1;
					break;
				case 3:
					if (get_color(10) == 'R')
						yellow_red = 3;
					break;
				case 5:
					if (get_color(28) == 'R')
						yellow_red = 5;
					break;
				case 7:
					if (get_color(19) == 'R')
						yellow_red = 7;
					break;
				case 10:
					if (get_color(3) == 'R')
						yellow_red = 10;
					break;
				case 12:
					if (get_color(41) == 'R')
						yellow_red = 12;
					break;
				case 14:
					if (get_color(21) == 'R')
						yellow_red = 14;
					break;
				case 16:
					if (get_color(48) == 'R')
						yellow_red = 16;
					break;
				case 19:
					if (get_color(7) == 'R')
						yellow_red = 19;
					break;
				case 21:
					if (get_color(14) == 'R')
						yellow_red = 21;
					break;
				case 23:
					if (get_color(30) == 'R')
						yellow_red = 23;
					break;
				case 25:
					if (get_color(46) == 'R')
						yellow_red = 25;
					break;
				case 28:
					if (get_color(5) == 'R')
						yellow_red = 28;
					break;
				case 30:
					if (get_color(23) == 'R')
						yellow_red = 30;
					break;
				case 32:
					if (get_color(39) == 'R')
						yellow_red = 32;
					break;
				case 34:
					if (get_color(50) == 'R')
						yellow_red = 34;
					break;
				case 37:
					if (get_color(1) == 'R')
						yellow_red = 37;
					break;
				case 39:
					if (get_color(32) == 'R')
						yellow_red = 39;
					break;
				case 41:
					if (get_color(12) == 'R')
						yellow_red = 41;
					break;
				case 43:
					if (get_color(52) == 'R')
						yellow_red = 43;
					break;
				case 46:
					if (get_color(25) == 'R')
						yellow_red = 46;
					break;
				case 48:
					if (get_color(16) == 'R')
						yellow_red = 48;
					break;
				case 50:
					if (get_color(34) == 'R')
						yellow_red = 50;
					break;
				case 52:
					if (get_color(43) == 'R')
						yellow_red = 52;
					break;
			}
		}
	}
	
	printf("\nYellow Red: %d", yellow_red);	
	printf("\nPlacing Yellow Red: ");
	switch (yellow_red) {
		case 1:
			printf("URR");
			U();
			R();
			R();
			break;
		case 3:
			printf("UURR");
			U();
			U();
			R();
			R();
			break;
		case 5:
			printf("RR");
			R();
			R();
			break;
		case 7:
			printf("uRR");
			Ui();
			R();
			R();
			break;
		case 10:
			printf("uFrf");
			Ui();
			F();
			Ri();
			Fi();
			break;
		case 12:
			printf("DBd");
			D();
			B();
			Di();
			break;
		case 14:
			printf("dfD");
			Di();
			Fi();
			D();
			break;
		case 16:
			printf("Should Never Be Here");
			break;
		case 19:
			printf("Frf");
			F();
			Ri();
			Fi();			
			break;
		case 21:
			printf("ddLDD");
			Di();
			Di();
			L();
			D();
			D();
			break;
		case 23:
			printf("r");
			Ri();
			break;
		case 25:
			printf("Should Never Be Here");
			break;
		case 28:
			printf("rdFD");
			Ri();
			Di();
			F();
			D();
			break;
		case 30:
			printf("dFD");
			Di();
			F();
			D();
			break;
		case 32:
			printf("Dbd");
			D();
			Bi();
			Di();
			break;
		case 34:
			printf("RdFD");
			R();
			Di();
			F();
			D();
			break;
		case 37:
			printf("bR");
			Bi();
			R();
			break;
		case 39:
			printf("R");
			R();
			break;
		case 41:
			printf("BBR");
			B();
			B();
			R();			
			break;
		case 43:
			printf("BR");
			B();
			R();			
			break;
		case 46:
			printf("Should Never Be Here");
			break;
		case 48:
			printf("Should Never Be Here");
			break;
		case 50:
			printf("Already in Place");
			break;
		case 52:
			printf("BDbd");
			B();
			D();
			Bi();
			Di();
			break;
	}
	
	for (int i=0; i<54; i++) {
		if (get_color(i) == 'Y') {
			switch (i) {
				case 1:
					if (get_color(37) == 'B')
						yellow_blue = 1;
					break;
				case 3:
					if (get_color(10) == 'B')
						yellow_blue = 3;
					break;
				case 5:
					if (get_color(28) == 'B')
						yellow_blue = 5;
					break;
				case 7:
					if (get_color(19) == 'B')
						yellow_blue = 7;
					break;
				case 10:
					if (get_color(3) == 'B')
						yellow_blue = 10;
					break;
				case 12:
					if (get_color(41) == 'B')
						yellow_blue = 12;
					break;
				case 14:
					if (get_color(21) == 'B')
						yellow_blue = 14;
					break;
				case 16:
					if (get_color(48) == 'B')
						yellow_blue = 16;
					break;
				case 19:
					if (get_color(7) == 'B')
						yellow_blue = 19;
					break;
				case 21:
					if (get_color(14) == 'B')
						yellow_blue = 21;
					break;
				case 23:
					if (get_color(30) == 'B')
						yellow_blue = 23;
					break;
				case 25:
					if (get_color(46) == 'B')
						yellow_blue = 25;
					break;
				case 28:
					if (get_color(5) == 'B')
						yellow_blue = 28;
					break;
				case 30:
					if (get_color(23) == 'B')
						yellow_blue = 30;
					break;
				case 32:
					if (get_color(39) == 'B')
						yellow_blue = 32;
					break;
				case 34:
					if (get_color(50) == 'B')
						yellow_blue = 34;
					break;
				case 37:
					if (get_color(1) == 'B')
						yellow_blue = 37;
					break;
				case 39:
					if (get_color(32) == 'B')
						yellow_blue = 39;
					break;
				case 41:
					if (get_color(12) == 'B')
						yellow_blue = 41;
					break;
				case 43:
					if (get_color(52) == 'B')
						yellow_blue = 43;
					break;
				case 46:
					if (get_color(25) == 'B')
						yellow_blue = 46;
					break;
				case 48:
					if (get_color(16) == 'B')
						yellow_blue = 48;
					break;
				case 50:
					if (get_color(34) == 'B')
						yellow_blue = 50;
					break;
				case 52:
					if (get_color(43) == 'B')
						yellow_blue = 52;
					break;
			}
		}
	}
	
	printf("\nYellow Blue: %d", yellow_blue);
	printf("\nPlacing Yellow Blue: ");
	switch (yellow_blue) {
		case 1:
			printf("BB");
			B();
			B();
			break;
		case 3:
			printf("UBB");
			U();
			B();
			B();
			break;
		case 5:
			printf("uBB");
			Ui();
			B();
			B();
			break;
		case 7:
			printf("UUBB");
			U();
			U();
			B();
			B();
			break;
		case 10:
			printf("lBL");
			Li();
			B();
			L();
			break;
		case 12:
			printf("B");
			B();
			break;
		case 14:
			printf("DDfdd");
			D();
			D();
			Fi();
			Di();
			Di();
			break;
		case 16:
			printf("Should Never Be Here");
			break;
		case 19:
			printf("uRbr");
			Ui();
			R();
			Bi();
			Ri();
			break;
		case 21:
			printf("DLd");
			D();
			L();
			Di();			
			break;
		case 23:
			printf("drD");
			Di();
			Ri();
			D();
			break;
		case 25:
			printf("Should Never Be Here");
			break;
		case 28:
			printf("Rbr");
			R();
			Bi();
			Ri();
			break;
		case 30:
			printf("RRbrr");
			R();
			R();
			Bi();
			Ri();
			Ri();
			break;
		case 32:
			printf("b");
			Bi();
			break;
		case 34:
			printf("Should Never Be Here");
			break;
		case 37:
			printf("BDld");
			B();
			D();
			Li();
			Di();
			break;
		case 39:
			printf("dRD");
			Di();
			R();
			D();			
			break;
		case 41:
			printf("BBdRD");
			B();
			B();
			Di();
			R();
			D();			
			break;
		case 43:
			printf("BdRD");
			B();
			Di();
			R();
			D();
			break;
		case 46:
			printf("Should Never Be Here");
			break;
		case 48:
			printf("Should Never Be Here");
			break;
		case 50:
			printf("Should Never Be Here");
			break;
		case 52:
			printf("Already in Place");
			break;
	}
}

void yellow_corners()
{
	int yellow_orange_green;
	int yellow_green_red;
	int yellow_red_blue;
	int yellow_blue_orange;
	
	for (int i=0; i<54; i++) {
		if (get_color(i) == 'Y') {
			switch (i) {
				case 0:
					if (get_color(9) == 'O' && get_color(38) == 'G') {
						yellow_orange_green = 0;
					}
					break;
				case 2:
					if (get_color(36) == 'O' && get_color(29) == 'G') {
						yellow_orange_green = 2;
					}
					break;
				case 6:
					if (get_color(18) == 'O' && get_color(11) == 'G') {
						yellow_orange_green = 6;
					}
					break;
				case 8:
					if (get_color(27) == 'O' && get_color(20) == 'G') {
						yellow_orange_green = 8;
					}
					break;
				case 9:
					if (get_color(38) == 'O' && get_color(0) == 'G') {
						yellow_orange_green = 9;
					}
					break;
				case 11:
					if (get_color(6) == 'O' && get_color(18) == 'G') {
						yellow_orange_green = 11;
					}
					break;
				case 15:
					if (get_color(51) == 'O' && get_color(44) == 'G') {
						yellow_orange_green = 15;
					}
					break;
				case 17:
					if (get_color(24) == 'O' && get_color(45) == 'G') {
						yellow_orange_green = 17;
					}
					break;
				case 18:
					if (get_color(11) == 'O' && get_color(6) == 'G') {
						yellow_orange_green = 18;
					}
					break;
				case 20:
					if (get_color(8) == 'O' && get_color(27) == 'G') {
						yellow_orange_green = 20;
					}
					break;
				case 24:
					if (get_color(45) == 'O' && get_color(17) == 'G') {
						yellow_orange_green = 24;
					}
					break;
				case 26:
					if (get_color(33) == 'O' && get_color(47) == 'G') {
						yellow_orange_green = 26;
					}
					break;
				case 27:
					if (get_color(20) == 'O' && get_color(8) == 'G') {
						yellow_orange_green = 27;
					}
					break;
				case 29:
					if (get_color(2) == 'O' && get_color(36) == 'G') {
						yellow_orange_green = 29;
					}
					break;
				case 33:
					if (get_color(47) == 'O' && get_color(26) == 'G') {
						yellow_orange_green = 33;
					}
					break;
				case 35:
					if (get_color(42) == 'O' && get_color(53) == 'G') {
						yellow_orange_green = 35;
					}
					break;
				case 36:
					if (get_color(29) == 'O' && get_color(2) == 'G') {
						yellow_orange_green = 36;
					}
					break;
				case 38:
					if (get_color(0) == 'O' && get_color(9) == 'G') {
						yellow_orange_green = 38;
					}
					break;
				case 42:
					if (get_color(53) == 'O' && get_color(35) == 'G') {
						yellow_orange_green = 42;
					}
					break;
				case 44:
					if (get_color(15) == 'O' && get_color(51) == 'G') {
						yellow_orange_green = 44;
					}
					break;
				case 45:
					if (get_color(17) == 'O' && get_color(24) == 'G') {
						yellow_orange_green = 45;
					}
					break;
				case 47:
					if (get_color(26) == 'O' && get_color(33) == 'G') {
						yellow_orange_green = 47;
					}
					break;
				case 51:
					if (get_color(44) == 'O' && get_color(15) == 'G') {
						yellow_orange_green = 51;
					}
					break;
				case 53:
					if (get_color(35) == 'O' && get_color(42) == 'G') {
						yellow_orange_green = 53;
					}
					break;
			}
		}
	}
	
	printf("\nYellow Orange Green: %d", yellow_orange_green);	
	printf("\nPlacing Yellow Orange Green: ");
	switch (yellow_orange_green) {
		case 0:
			printf("uFRUUrf");	
			Ui();
			F();
			R();
			U();
			U();
			Ri();
			Fi();				
			break;
		case 2:
			printf("UUFRUUrf");
			U();
			U();
			F();
			R();
			U();
			U();
			Ri();
			Fi();
			break;
		case 6:
			printf("FRUUrf");
			F();
			R();
			U();
			Ri();
			Fi();
			break;
		case 8:
			printf("UFRUUrf");
			U();
			F();
			R();
			U();
			U();
			Ri();
			Fi();
			break;
		case 9:
			printf("uFUf");
			Ui();
			F();
			U();
			Fi();
			break;
		case 11:
			printf("luL");
			Li();
			Ui();
			L();
			break;
		case 15:
			printf("buBFRUUrf");
			Bi();
			Ui();
			B();
			F();
			R();
			U();
			U();
			Ri();
			Fi();
			break;
		case 17:
			printf("luLUluL");
			Li();
			Ui();
			L();
			U();
			Li();
			Ui();
			L();
			break;
		case 18:
			printf("FUf");
			F();
			U();
			Fi();
			break;
		case 20:
			printf("UluL");
			U();
			Li();
			Ui();
			L();
			break;
		case 24:
			printf("lULFUf");
			Li();
			U();
			L();
			F();
			U();
			Fi();
			break;
		case 26:
			printf("fuFUUluL");
			Fi();
			Ui();
			F();
			U();
			U();
			Li();
			Ui();
			L();
			break;
		case 27:
			printf("UFUf");
			U();
			F();
			U();
			Fi();
			break;
		case 29:
			printf("UUluL");
			U();
			U();
			Li();
			Ui();
			L();
			break;
		case 33:
			printf("fUFlUL");
			Fi();
			U();
			F();
			Li();
			U();
			L();
			break;
		case 35:
			printf("BubUUluL");
			B();
			Ui();
			Bi();
			U();
			U();
			Li();
			Ui();
			L();
			break;
		case 36:
			printf("UUFUf");
			U();
			U();
			F();
			U();
			Fi();
			break;
		case 38:
			printf("uluL");
			Ui();
			Li();
			Ui();
			L();
			break;
		case 42:
			printf("BUblUL");
			B();
			U();
			Bi();
			Li();
			U();
			L();
			break;
		case 44:
			printf("buBluL");
			Bi();
			Ui();
			B();
			Li();
			Ui();
			L();
			break;
		case 45:
			printf("Already in Place");
			break;
		case 47:
			printf("fuFUlUL");
			Fi();
			Ui();
			F();
			U();
			Li();
			U();
			L();
			break;
		case 51:
			printf("bUUBlUL");
			Bi();
			U();
			U();
			B();
			Li();
			U();
			L();
			break;
		case 53:
			printf("BUUbluL");
			B();
			U();
			U();
			Bi();
			Li();
			Ui();
			L();
			break;
	}
	
	for (int i=0; i<54; i++) {
		if (get_color(i) == 'Y') {
			switch (i) {
				case 0:
					if (get_color(9) == 'G' && get_color(38) == 'R') {
						yellow_green_red = 0;
					}
					break;
				case 2:
					if (get_color(36) == 'G' && get_color(29) == 'R') {
						yellow_green_red = 2;
					}
					break;
				case 6:
					if (get_color(18) == 'G' && get_color(11) == 'R') {
						yellow_green_red = 6;
					}
					break;
				case 8:
					if (get_color(27) == 'G' && get_color(20) == 'R') {
						yellow_green_red = 8;
					}
					break;
				case 9:
					if (get_color(38) == 'G' && get_color(0) == 'R') {
						yellow_green_red = 9;
					}
					break;
				case 11:
					if (get_color(6) == 'G' && get_color(18) == 'R') {
						yellow_green_red = 11;
					}
					break;
				case 15:
					if (get_color(51) == 'G' && get_color(44) == 'R') {
						yellow_green_red = 15;
					}
					break;
				case 17:
					if (get_color(24) == 'G' && get_color(45) == 'R') {
						yellow_green_red = 17;
					}
					break;
				case 18:
					if (get_color(11) == 'G' && get_color(6) == 'R') {
						yellow_green_red = 18;
					}
					break;
				case 20:
					if (get_color(8) == 'G' && get_color(27) == 'R') {
						yellow_green_red = 20;
					}
					break;
				case 24:
					if (get_color(45) == 'G' && get_color(17) == 'R') {
						yellow_green_red = 24;
					}
					break;
				case 26:
					if (get_color(33) == 'G' && get_color(47) == 'R') {
						yellow_green_red = 26;
					}
					break;
				case 27:
					if (get_color(20) == 'G' && get_color(8) == 'R') {
						yellow_green_red = 27;
					}
					break;
				case 29:
					if (get_color(2) == 'G' && get_color(36) == 'R') {
						yellow_green_red = 29;
					}
					break;
				case 33:
					if (get_color(47) == 'G' && get_color(26) == 'R') {
						yellow_green_red = 33;
					}
					break;
				case 35:
					if (get_color(42) == 'G' && get_color(53) == 'R') {
						yellow_green_red = 35;
					}
					break;
				case 36:
					if (get_color(29) == 'G' && get_color(2) == 'R') {
						yellow_green_red = 36;
					}
					break;
				case 38:
					if (get_color(0) == 'G' && get_color(9) == 'R') {
						yellow_green_red = 38;
					}
					break;
				case 42:
					if (get_color(53) == 'G' && get_color(35) == 'R') {
						yellow_green_red = 42;
					}
					break;
				case 44:
					if (get_color(15) == 'G' && get_color(51) == 'R') {
						yellow_green_red = 44;
					}
					break;
				case 45:
					if (get_color(17) == 'G' && get_color(24) == 'R') {
						yellow_green_red = 45;
					}
					break;
				case 47:
					if (get_color(26) == 'G' && get_color(33) == 'R') {
						yellow_green_red = 47;
					}
					break;
				case 51:
					if (get_color(44) == 'G' && get_color(15) == 'R') {
						yellow_green_red = 51;
					}
					break;
				case 53:
					if (get_color(35) == 'G' && get_color(42) == 'R') {
						yellow_green_red = 53;
					}
					break;
			}
	}
		}

	printf("\nYellow Green Red: %d", yellow_green_red);	
	printf("\nPlacing Yellow Green Red: ");
	switch (yellow_green_red) {
		case 0:
			printf("");		
			break;
		case 2:
			printf("");
			break;
		case 6:
			printf("");
			break;
		case 8:
			printf("");
			break;
		case 9:
			printf("");
			break;
		case 11:
			printf("");
			break;
		case 15:
			printf("");
			break;
		case 17:
			printf("");
			break;
		case 18:
			printf("");
			break;
		case 20:
			printf("");
			break;
		case 24:
			printf("");
			break;
		case 26:
			printf("");
			break;
		case 27:
			printf("");
			break;
		case 29:
			printf("");
			break;
		case 33:
			printf("");
			break;
		case 35:
			printf("");
			break;
		case 36:
			printf("");
			break;
		case 38:
			printf("");
			break;
		case 42:
			printf("");
			break;
		case 44:
			printf("");
			break;
		case 45:
			printf("Should Never Be Here");
			break;
		case 47:
			printf("Already in Place");
			break;
		case 51:
			printf("LUUlfuF");
			L();
			U();
			U();
			Li();
			Fi();
			Ui();
			F();
			break;
		case 53:
			printf("BUbfuF");
			B();
			U();
			Bi();
			Fi();
			Ui();
			F();
			break;
	}
}
