
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
void second_layer();
void white_cross();

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
	
	second_layer();
	printf("\n");
	display();
	
	white_cross();
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
			printf("LUlUUFUf");
			L();
			U();
			Li();
			U();
			U();
			F();
			U();
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
			printf("RurUluL");
			R();
			Ui();
			Ri();
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
			printf("ruRuluL");
			Ri();
			Ui();
			R();
			Ui();
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
			printf("UURBUUbr");
			U();
			U();
			R();
			B();
			U();
			U();
			Bi();
			Ri();
			break;
		case 2:
			printf("URBUUbr");
			U();
			R();
			B();
			U();
			U();
			Bi();
			Ri();			
			break;
		case 6:
			printf("uRBUUbr");
			Ui();
			R();
			B();
			U();
			U();
			Bi();
			Ri();	
			break;
		case 8:
			printf("RBUUbr");
			R();
			B();
			U();
			U();
			Bi();
			Ri();	
			break;
		case 9:
			printf("UfUF");
			U();
			Fi();
			U();
			F();
			break;
		case 11:
			printf("ufuF");
			Ui();
			Fi();
			Ui();
			F();
			break;
		case 15:
			printf("LUlfUF");
			L();
			U();
			Li();
			Fi();
			U();
			F();			
			break;
		case 17:
			printf("Should Never Be Here");
			break;
		case 18:
			printf("uRUr");
			Ui();
			R();
			U();
			Ri();
			break;
		case 20:
			printf("fuF");
			Fi();
			Ui();
			F();
			break;
		case 24:
			printf("Should Never Be Here");
			break;
		case 26:
			printf("fuFUfuF");
			Fi();
			U();
			F();
			U();
			Fi();
			Ui();
			F();
			break;
		case 27:
			printf("ufUF");
			Ui();
			Fi();
			U();
			F();
			break;
		case 29:
			printf("UfuF");
			U();
			Fi();
			Ui();
			F();
			break;
		case 33:
			printf("fUFufUF");
			Fi();
			U();
			F();
			Ui();
			Fi();
			U();
			F();
			break;
		case 35:
			printf("BubUfuF");
			B();
			Ui();
			Bi();
			U();
			Fi();
			Ui();
			F();
			break;
		case 36:
			printf("fUF");
			Fi();
			U();
			F();
			break;
		case 38:
			printf("UUfuF");
			U();
			U();
			Fi();
			Ui();
			F();
			break;
		case 42:
			printf("rURfUF");
			Ri();
			U();
			R();
			Fi();
			U();
			F();
			break;
		case 44:
			printf("bUUfuF");
			Bi();
			U();
			U();
			Fi();
			Ui();
			F();
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
	
	for (int i=0; i<54; i++) {
		if (get_color(i) == 'Y') {
			switch (i) {
				case 0:
					if (get_color(9) == 'R' && get_color(38) == 'B') {
						yellow_red_blue = 0;
					}
					break;
				case 2:
					if (get_color(36) == 'R' && get_color(29) == 'B') {
						yellow_red_blue = 2;
					}
					break;
				case 6:
					if (get_color(18) == 'R' && get_color(11) == 'B') {
						yellow_red_blue = 6;
					}
					break;
				case 8:
					if (get_color(27) == 'R' && get_color(20) == 'B') {
						yellow_red_blue = 8;
					}
					break;
				case 9:
					if (get_color(38) == 'R' && get_color(0) == 'B') {
						yellow_red_blue = 9;
					}
					break;
				case 11:
					if (get_color(6) == 'R' && get_color(18) == 'B') {
						yellow_red_blue = 11;
					}
					break;
				case 15:
					if (get_color(51) == 'R' && get_color(44) == 'B') {
						yellow_red_blue = 15;
					}
					break;
				case 17:
					if (get_color(24) == 'R' && get_color(45) == 'B') {
						yellow_red_blue = 17;
					}
					break;
				case 18:
					if (get_color(11) == 'R' && get_color(6) == 'B') {
						yellow_red_blue = 18;
					}
					break;
				case 20:
					if (get_color(8) == 'R' && get_color(27) == 'B') {
						yellow_red_blue = 20;
					}
					break;
				case 24:
					if (get_color(45) == 'R' && get_color(17) == 'B') {
						yellow_red_blue = 24;
					}
					break;
				case 26:
					if (get_color(33) == 'R' && get_color(47) == 'B') {
						yellow_red_blue = 26;
					}
					break;
				case 27:
					if (get_color(20) == 'R' && get_color(8) == 'B') {
						yellow_red_blue = 27;
					}
					break;
				case 29:
					if (get_color(2) == 'R' && get_color(36) == 'B') {
						yellow_red_blue = 29;
					}
					break;
				case 33:
					if (get_color(47) == 'R' && get_color(26) == 'B') {
						yellow_red_blue = 33;
					}
					break;
				case 35:
					if (get_color(42) == 'R' && get_color(53) == 'B') {
						yellow_red_blue = 35;
					}
					break;
				case 36:
					if (get_color(29) == 'R' && get_color(2) == 'B') {
						yellow_red_blue = 36;
					}
					break;
				case 38:
					if (get_color(0) == 'R' && get_color(9) == 'B') {
						yellow_red_blue = 38;
					}
					break;
				case 42:
					if (get_color(53) == 'R' && get_color(35) == 'B') {
						yellow_red_blue = 42;
					}
					break;
				case 44:
					if (get_color(15) == 'R' && get_color(51) == 'B') {
						yellow_red_blue = 44;
					}
					break;
				case 45:
					if (get_color(17) == 'R' && get_color(24) == 'B') {
						yellow_red_blue = 45;
					}
					break;
				case 47:
					if (get_color(26) == 'R' && get_color(33) == 'B') {
						yellow_red_blue = 47;
					}
					break;
				case 51:
					if (get_color(44) == 'R' && get_color(15) == 'B') {
						yellow_red_blue = 51;
					}
					break;
				case 53:
					if (get_color(35) == 'R' && get_color(42) == 'B') {
						yellow_red_blue = 53;
					}
					break;
			}
		}
	}

	printf("\nYellow Red Blue: %d", yellow_red_blue);	
	printf("\nPlacing Yellow Red Blue: ");
	switch (yellow_red_blue) {
		case 0:
			printf("UBLUUlb");
			U();
			B();
			L();
			U();
			U();
			Li();
			Bi();
			break;
		case 2:
			printf("BLUUlb");		
			B();
			L();
			U();
			U();
			Li();
			Bi();
			break;
		case 6:
			printf("UUBLUUlb");
			U();
			U();
			B();
			L();
			U();
			U();
			Li();
			Bi();
			break;
		case 8:
			printf("uBLUUlb");
			Ui();
			B();
			L();
			U();
			U();
			Li();
			Bi();
			break;
		case 9:
			printf("rUR");
			Ri();
			U();
			R();
			break;
		case 11:
			printf("uBub");
			Ui();
			B();
			Ui();
			Bi();
			break;
		case 15:
			printf("LUlBUb");		
			L();
			U();
			Li();
			B();
			U();
			Bi();
			break;
		case 17:
			printf("Should Never Be Here");
			break;
		case 18:
			printf("UrUR");
			U();
			Ri();
			U();
			R();
			break;
		case 20:
			printf("Bub");
			B();
			Ui();
			Bi();
			break;
		case 24:
			printf("Should Never Be Here");
			break;
		case 26:
			printf("Should Never Be Here");
			break;
		case 27:
			printf("UUrUR");
			U();
			U();
			Ri();
			U();
			R();
			break;
		case 29:
			printf("ruR");
			Ri();
			Ui();
			R();
			break;
		case 33:
			printf("Should Never Be Here");
			break;
		case 35:
			printf("BubruR");
			B();
			Ui();
			Bi();
			Ri();
			Ui();
			R();
			break;
		case 36:
			printf("BUb");
			B();
			U();
			Bi();
			break;
		case 38:
			printf("UruR");
			U();
			Ri();
			Ui();
			R();
			break;
		case 42:
			printf("rURBUb");
			Ri();
			U();
			R();
			B();
			U();
			Bi();
			break;
		case 44:
			printf("LulUruR");
			L();
			Ui();
			Li();
			U();
			Ri();
			U();
			R();
			break;
		case 45:
			printf("Should Never Be Here");
			break;
		case 47:
			printf("Should Never Be Here");
			break;
		case 51:
			printf("LUlruR");
			L();
			U();
			Li();
			Ri();
			Ui();
			R();
			break;
		case 53:
			printf("Already in Place");
			break;
	}

	for (int i=0; i<54; i++) {
		if (get_color(i) == 'Y') {
			switch (i) {
				case 0:
					if (get_color(9) == 'B' && get_color(38) == 'O') {
						yellow_blue_orange = 0;
					}
					break;
				case 2:
					if (get_color(36) == 'B' && get_color(29) == 'O') {
						yellow_blue_orange = 2;
					}
					break;
				case 6:
					if (get_color(18) == 'B' && get_color(11) == 'O') {
						yellow_blue_orange = 6;
					}
					break;
				case 8:
					if (get_color(27) == 'B' && get_color(20) == 'O') {
						yellow_blue_orange = 8;
					}
					break;
				case 9:
					if (get_color(38) == 'B' && get_color(0) == 'O') {
						yellow_blue_orange = 9;
					}
					break;
				case 11:
					if (get_color(6) == 'B' && get_color(18) == 'O') {
						yellow_blue_orange = 11;
					}
					break;
				case 15:
					if (get_color(51) == 'B' && get_color(44) == 'O') {
						yellow_blue_orange = 15;
					}
					break;
				case 17:
					if (get_color(24) == 'B' && get_color(45) == 'O') {
						yellow_blue_orange = 17;
					}
					break;
				case 18:
					if (get_color(11) == 'B' && get_color(6) == 'O') {
						yellow_blue_orange = 18;
					}
					break;
				case 20:
					if (get_color(8) == 'B' && get_color(27) == 'O') {
						yellow_blue_orange = 20;
					}
					break;
				case 24:
					if (get_color(45) == 'B' && get_color(17) == 'O') {
						yellow_blue_orange = 24;
					}
					break;
				case 26:
					if (get_color(33) == 'B' && get_color(47) == 'O') {
						yellow_blue_orange = 26;
					}
					break;
				case 27:
					if (get_color(20) == 'B' && get_color(8) == 'O') {
						yellow_blue_orange = 27;
					}
					break;
				case 29:
					if (get_color(2) == 'B' && get_color(36) == 'O') {
						yellow_blue_orange = 29;
					}
					break;
				case 33:
					if (get_color(47) == 'B' && get_color(26) == 'O') {
						yellow_blue_orange = 33;
					}
					break;
				case 35:
					if (get_color(42) == 'B' && get_color(53) == 'O') {
						yellow_blue_orange = 35;
					}
					break;
				case 36:
					if (get_color(29) == 'B' && get_color(2) == 'O') {
						yellow_blue_orange = 36;
					}
					break;
				case 38:
					if (get_color(0) == 'B' && get_color(9) == 'O') {
						yellow_blue_orange = 38;
					}
					break;
				case 42:
					if (get_color(53) == 'B' && get_color(35) == 'O') {
						yellow_blue_orange = 42;
					}
					break;
				case 44:
					if (get_color(15) == 'B' && get_color(51) == 'O') {
						yellow_blue_orange = 44;
					}
					break;
				case 45:
					if (get_color(17) == 'B' && get_color(24) == 'O') {
						yellow_blue_orange = 45;
					}
					break;
				case 47:
					if (get_color(26) == 'B' && get_color(33) == 'O') {
						yellow_blue_orange = 47;
					}
					break;
				case 51:
					if (get_color(44) == 'B' && get_color(15) == 'O') {
						yellow_blue_orange = 51;
					}
					break;
				case 53:
					if (get_color(35) == 'B' && get_color(42) == 'O') {
						yellow_blue_orange = 53;
					}
					break;
			}
		}
	}

	printf("\nYellow Blue Orange: %d", yellow_blue_orange);	
	printf("\nPlacing Yellow Blue Orange: ");
	switch (yellow_blue_orange) {
		case 0:
			printf("LFUUfl");
			L();
			F();
			U();
			U();
			Fi();
			Li();
			break;
		case 2:
			printf("uLFUUfl");
			Ui();
			L();
			F();
			U();
			U();
			Fi();
			Li();
			break;
		case 6:
			printf("ULFUUfl");
			U();
			L();
			F();
			U();
			U();
			Fi();
			Li();
			break;
		case 8:
			printf("UULFUUfl");
			U();
			U();
			L();
			F();
			U();
			U();
			Fi();
			Li();
			break;
		case 9:
			printf("LUl");
			L();
			U();
			Li();
			break;
		case 11:
			printf("UbuB");
			U();
			Bi();
			Ui();
			B();
			break;
		case 15:
			printf("LUUlUbUB");
			L();
			U();
			U();
			Li();
			U();
			Bi();
			U();
			B();
			break;
		case 17:
			printf("Should Never Be Here");
			break;
		case 18:
			printf("ULUl");
			U();
			L();
			U();
			Li();
			break;
		case 20:
			printf("UUbuB");
			U();
			U();
			Bi();
			Ui();
			B();
			break;
		case 24:
			printf("Should Never Be Here");
			break;
		case 26:
			printf("Should Never Be Here");
			break;
		case 27:
			printf("UULUl");
			U();
			U();
			L();
			U();
			Li();
			break;
		case 29:
			printf("ubuB");
			Ui();
			Bi();
			Ui();
			B();
			break;
		case 33:
			printf("Should Never Be Here");
			break;
		case 35:
			printf("Should Never Be Here");
			break;
		case 36:
			printf("uLUl");
			Ui();
			L();
			U();
			Li();
			break;
		case 38:
			printf("buB");
			Bi();
			Ui();
			B();
			break;
		case 42:
			printf("Should Never Be Here");
			break;
		case 44:
			printf("LulbuB");
			L();
			Ui();
			Li();
			Bi();
			Ui();
			B();
			break;
		case 45:
			printf("Should Never Be Here");
			break;
		case 47:
			printf("Should Never Be Here");
			break;
		case 51:
			printf("Already in Place");
			break;
		case 53:
			printf("Should Never Be Here");
			break;
	}
}

void second_layer()
{
	int orange_green;
	int green_red;
	int red_blue;
	int blue_orange;
	
	for (int i=0; i<42; i++) {
		if (get_color(i) == 'O') {
			switch (i) {
				case 1:
					if (get_color(37) == 'G')
						orange_green = 1;
					break;
				case 3:
					if (get_color(10) == 'G')
						orange_green = 3;
					break;
				case 5:
					if (get_color(28) == 'G')
						orange_green = 5;
					break;
				case 7:
					if (get_color(19) == 'G')
						orange_green = 7;
					break;
				case 10:
					if (get_color(3) == 'G')
						orange_green = 10;
					break;
				case 12:
					if (get_color(41) == 'G')
						orange_green = 12;
					break;
				case 14:
					if (get_color(21) == 'G')
						orange_green = 14;
					break;
				case 19:
					if (get_color(7) == 'G')
						orange_green = 19;
					break;
				case 21:
					if (get_color(14) == 'G')
						orange_green = 21;
					break;
				case 23:
					if (get_color(30) == 'G')
						orange_green = 23;
					break;
				case 28:
					if (get_color(5) == 'G')
						orange_green = 28;
					break;
				case 30:
					if (get_color(23) == 'G')
						orange_green = 30;
					break;
				case 32:
					if (get_color(39) == 'G')
						orange_green = 32;
					break;
				case 37:
					if (get_color(1) == 'G')
						orange_green = 37;
					break;
				case 39:
					if (get_color(32) == 'G')
						orange_green = 39;
					break;
				case 41:
					if (get_color(12) == 'G')
						orange_green = 41;
					break;
			}
		}
	}

	printf("\nOrange Green: %d", orange_green);	
	printf("\nPlacing Orange Green: ");
	switch (orange_green) {
		case 1:
			printf("UlULUFuf");
			U();
			Li();
			U();
			L();
			U();
			F();
			Ui();
			Fi();
			break;
		case 3:
			printf("UUlULUFuf");
			U();
			U();
			Li();
			U();
			L();
			U();
			F();
			Ui();
			Fi();
			break;
		case 5:
			printf("lULUFuf");
			Li();
			U();
			L();
			U();
			F();
			Ui();
			Fi();
			break;
		case 7:
			printf("ulULUFuf");
			Ui();
			Li();
			U();
			L();
			U();
			F();
			Ui();
			Fi();
			break;
		case 10:
			printf("UFufulUL");
			U();
			F();
			Ui();
			Fi();
			Ui();
			Li();
			U();
			L();
			break;
		case 12:
			printf("bUBULul lULUFuf");
			Bi();
			U();
			B();
			U();
			L();
			Ui();
			Li();
			Li();
			U();
			L();
			U();
			F();
			Ui();
			Fi();
			break;
		case 14:
			printf("Already in Place");
			break;
		case 19:
			printf("UUFufulUL");
			U();
			U();
			F();
			Ui();
			Fi();
			Ui();
			Li();
			U();
			L();
			break;
		case 21:
			printf("lULUFuf UlULUFuf");
			Li();
			U();
			L();
			U();
			F();
			Ui();
			Fi();
			U();
			Li();
			U();
			L();
			U();
			F();
			Ui();
			Fi();			
			break;
		case 23:
			printf("RurufUF UlULUFuf");
			R();
			Ui();
			Ri();
			Ui();
			Fi();
			U();
			F();
			U();
			Li();
			U();
			L();
			U();
			F();
			Ui();
			Fi();
			break;
		case 28:
			printf("uFufulUL");
			Ui();
			F();
			Ui();
			Fi();
			Ui();
			Li();
			U();
			L();
			break;
		case 30:
			printf("RurufUF FufulUL");
			R();
			Ui();
			Ri();
			Ui();
			Fi();
			U();
			F();
			F();
			Ui();
			Fi();
			Ui();
			Li();
			U();
			L();			
			break;
		case 32:
			printf("BuburUR UUlULUFuf");
			B();
			Ui();
			Bi();
			Ui();
			Ri();
			U();
			R();
			U();
			U();
			Li();
			U();
			L();
			U();
			F();
			Ui();
			Fi();
			break;
		case 37:
			printf("FufulUL");
			F();
			Ui();
			Fi();
			Ui();
			Li();
			U();
			L();
			break;
		case 39:
			printf("rURUBub ulULUFuf");
			Ri();
			U();
			R();
			U();
			B();
			Ui();
			Bi();
			Ui();
			Li();
			U();
			L();
			U();
			F();
			Ui();
			Fi();
			break;
		case 41:
			printf("LulubUB ulULUFuf");
			L();
			Ui();
			Li();
			Ui();
			Bi();
			U();
			B();
			Ui();
			Li();
			U();
			L();
			U();
			F();
			Ui();
			Fi();
			break;
	}

	for (int i=0; i<42; i++) {
		if (get_color(i) == 'G') {
			switch (i) {
				case 1:
					if (get_color(37) == 'R')
						green_red = 1;
					break;
				case 3:
					if (get_color(10) == 'R')
						green_red = 3;
					break;
				case 5:
					if (get_color(28) == 'R')
						green_red = 5;
					break;
				case 7:
					if (get_color(19) == 'R')
						green_red = 7;
					break;
				case 10:
					if (get_color(3) == 'R')
						green_red = 10;
					break;
				case 12:
					if (get_color(41) == 'R')
						green_red = 12;
					break;
				case 14:
					if (get_color(21) == 'R')
						green_red = 14;
					break;
				case 19:
					if (get_color(7) == 'R')
						green_red = 19;
					break;
				case 21:
					if (get_color(14) == 'R')
						green_red = 21;
					break;
				case 23:
					if (get_color(30) == 'R')
						green_red = 23;
					break;
				case 28:
					if (get_color(5) == 'R')
						green_red = 28;
					break;
				case 30:
					if (get_color(23) == 'R')
						green_red = 30;
					break;
				case 32:
					if (get_color(39) == 'R')
						green_red = 32;
					break;
				case 37:
					if (get_color(1) == 'R')
						green_red = 37;
					break;
				case 39:
					if (get_color(32) == 'R')
						green_red = 39;
					break;
				case 41:
					if (get_color(12) == 'R')
						green_red = 41;
					break;
			}
		}
	}

	printf("\nGreen Red: %d", green_red);	
	printf("\nPlacing Green Red: ");
	switch (green_red) {
		case 1:
			printf("fUFURur");
			Fi();
			U();
			F();
			U();
			R();
			Ui();
			Ri();
			break;
		case 3:
			printf("UfUFURur");
			U();
			Fi();
			U();
			F();
			U();
			R();
			Ui();
			Ri();
			break;
		case 5:
			printf("ufUFURur");
			Ui();
			Fi();
			U();
			F();
			U();
			R();
			Ui();
			Ri();
			break;
		case 7:
			printf("UUfUFURur");
			U();
			U();
			Fi();
			U();
			F();
			U();
			R();
			Ui();
			Ri();
			break;
		case 10:
			printf("RurufUF");
			R();
			Ui();
			Ri();
			Ui();
			Fi();
			U();
			F();
			break;
		case 12:
			printf("bUBULul ufUFURur");
			Bi();
			U();
			B();
			U();
			L();
			Ui();
			Li();
			Ui();
			Fi();
			U();
			F();
			U();
			R();
			Ui();
			Ri();
			break;
		case 14:
			printf("Should Never Be Here");
			break;
		case 19:
			printf("URurufUF");
			U();
			R();
			Ui();
			Ri();
			Ui();
			Fi();
			U();
			F();
			break;
		case 21:
			printf("Should Never Be Here");
			break;
		case 23:
			printf("Already in Place");
			break;
		case 28:
			printf("UURurufUF");
			U();
			U();
			R();
			Ui();
			Ri();
			Ui();
			Fi();
			U();
			F();
			break;
		case 30:
			printf("RurufUF uRurufUF");
			R();
			Ui();
			Ri();
			Ui();
			Fi();
			U();
			F();
			Ui();
			R();
			Ui();
			Ri();
			Ui();
			Fi();
			U();
			F();
			break;
		case 32:
			printf("BuburUR UfUFURur");
			B();
			Ui();
			Bi();
			Ui();
			Ri();
			U();
			R();
			U();
			Fi();
			U();
			F();
			U();
			R();
			Ui();
			Ri();
			break;
		case 37:
			printf("uRurufUF");
			Ui();
			R();
			Ui();
			Ri();
			Ui();
			Fi();
			U();
			F();
			break;
		case 39:
			printf("BuburUR RurufUF");
			B();
			Ui();
			Bi();
			Ui();
			Ri();
			U();
			R();
			R();
			Ui();
			Ri();
			Ui();
			Fi();
			U();
			F();
			break;
		case 41:
			printf("LulubUB UUfUFURur");
			L();
			Ui();
			Li();
			Ui();
			Bi();
			U();
			B();
			U();
			U();
			Fi();
			U();
			F();
			U();
			R();
			Ui();
			Ri();
			break;
	}

	for (int i=0; i<42; i++) {
		if (get_color(i) == 'R') {
			switch (i) {
				case 1:
					if (get_color(37) == 'B')
						red_blue = 1;
					break;
				case 3:
					if (get_color(10) == 'B')
						red_blue = 3;
					break;
				case 5:
					if (get_color(28) == 'B')
						red_blue = 5;
					break;
				case 7:
					if (get_color(19) == 'B')
						red_blue = 7;
					break;
				case 10:
					if (get_color(3) == 'B')
						red_blue = 10;
					break;
				case 12:
					if (get_color(41) == 'B')
						red_blue = 12;
					break;
				case 14:
					if (get_color(21) == 'B')
						red_blue = 14;
					break;
				case 19:
					if (get_color(7) == 'B')
						red_blue = 19;
					break;
				case 21:
					if (get_color(14) == 'B')
						red_blue = 21;
					break;
				case 23:
					if (get_color(30) == 'B')
						red_blue = 23;
					break;
				case 28:
					if (get_color(5) == 'B')
						red_blue = 28;
					break;
				case 30:
					if (get_color(23) == 'B')
						red_blue = 30;
					break;
				case 32:
					if (get_color(39) == 'B')
						red_blue = 32;
					break;
				case 37:
					if (get_color(1) == 'B')
						red_blue = 37;
					break;
				case 39:
					if (get_color(32) == 'B')
						red_blue = 39;
					break;
				case 41:
					if (get_color(12) == 'B')
						red_blue = 41;
					break;
			}
		}
	}
	
	printf("\nRed Blue: %d", red_blue);	
	printf("\nPlacing Red Blue: ");
	switch (red_blue) {
		case 1:
			printf("urURUBub");
			Ui();
			Ri();
			U();
			R();
			U();
			B();
			Ui();
			Bi();
			break;
		case 3:
			printf("rURUBub");
			Ri();
			U();
			R();
			U();
			B();
			Ui();
			Bi();
			break;
		case 5:
			printf("UUrURUBub");
			U();
			U();
			Ri();
			U();
			R();
			U();
			B();
			Ui();
			Bi();
			break;
		case 7:
			printf("UrURUBub");
			U();
			Ri();
			U();
			R();
			U();
			B();
			Ui();
			Bi();
			break;
		case 10:
			printf("uBuburUR");
			Ui();
			B();
			Ui();
			Bi();
			Ui();
			Ri();
			U();
			R();
			break;
		case 12:
			printf("bUBULul UUrURUBub");
			Bi();
			U();
			B();
			U();
			L();
			Ui();
			Li();
			U();
			U();
			Ri();
			U();
			R();
			U();
			B();
			Ui();
			Bi();
			break;
		case 14:
			printf("Should Never Be Here");
			break;
		case 19:
			printf("BuburUR");
			B();
			Ui();
			Bi();
			Ui();
			Ri();
			U();
			R();
			break;
		case 21:
			printf("Should Never Be Here");
			break;
		case 23:
			printf("Should Never Be Here");
			break;
		case 28:
			printf("UBuburUR");
			U();
			B();
			Ui();
			Bi();
			Ui();
			Ri();
			U();
			R();
			break;
		case 30:
			printf("Should Never Be Here");
			break;
		case 32:
			printf("Already in Place");
			break;
		case 37:
			printf("UUBuburUR");
			U();
			U();
			B();
			Ui();
			Bi();
			Ui();
			Ri();
			U();
			R();
			break;
		case 39:
			printf("BuburUR uBuburUR");
			B();
			Ui();
			Bi();
			Ui();
			Ri();
			U();
			R();
			Ui();
			B();
			Ui();
			Bi();
			Ui();
			Ri();
			U();
			R();
			break;
		case 41:
			printf("bUBULul UBuburUR");
			Bi();
			U();
			B();
			U();
			L();
			Ui();
			Li();
			U();
			B();
			Ui();
			Bi();
			Ui();
			Ri();
			U();
			R();
			break;
	}

	for (int i=0; i<42; i++) {
		if (get_color(i) == 'B') {
			switch (i) {
				case 1:
					if (get_color(37) == 'O')
						blue_orange = 1;
					break;
				case 3:
					if (get_color(10) == 'O')
						blue_orange = 3;
					break;
				case 5:
					if (get_color(28) == 'O')
						blue_orange = 5;
					break;
				case 7:
					if (get_color(19) == 'O')
						blue_orange = 7;
					break;
				case 10:
					if (get_color(3) == 'O')
						blue_orange = 10;
					break;
				case 12:
					if (get_color(41) == 'O')
						blue_orange = 12;
					break;
				case 14:
					if (get_color(21) == 'O')
						blue_orange = 14;
					break;
				case 19:
					if (get_color(7) == 'O')
						blue_orange = 19;
					break;
				case 21:
					if (get_color(14) == 'O')
						blue_orange = 21;
					break;
				case 23:
					if (get_color(30) == 'O')
						blue_orange = 23;
					break;
				case 28:
					if (get_color(5) == 'O')
						blue_orange = 28;
					break;
				case 30:
					if (get_color(23) == 'O')
						blue_orange = 30;
					break;
				case 32:
					if (get_color(39) == 'O')
						blue_orange = 32;
					break;
				case 37:
					if (get_color(1) == 'O')
						blue_orange = 37;
					break;
				case 39:
					if (get_color(32) == 'O')
						blue_orange = 39;
					break;
				case 41:
					if (get_color(12) == 'O')
						blue_orange = 41;
					break;
			}
		}
	}
	
	printf("\nBlue Orange: %d", blue_orange);	
	printf("\nPlacing Blue Orange: ");
	switch (blue_orange) {
		case 1:
			printf("UUbUBULul");
			U();
			U();
			Bi();
			U();
			B();
			U();
			L();
			Ui();
			Li();
			break;
		case 3:
			printf("ubUBULul");
			Ui();
			Bi();
			U();
			B();
			U();
			L();
			Ui();
			Li();
			break;
		case 5:
			printf("UbUBULul");
			U();
			Bi();
			U();
			B();
			U();
			L();
			Ui();
			Li();
			break;
		case 7:
			printf("bUBULul");
			Bi();
			U();
			B();
			U();
			L();
			Ui();
			Li();
			break;
		case 10:
			printf("UULulubUB");
			U();
			U();
			L();
			Ui();
			Li();
			Ui();
			Bi();
			U();
			B();
			break;
		case 12:
			printf("bUBULul UbUBULul");
			Bi();
			U();
			B();
			U();
			L();
			Ui();
			Li();
			U();
			Bi();
			U();
			B();
			U();
			L();
			Ui();
			Li();
			break;
		case 14:
			printf("Should Never Be Here");
			break;
		case 19:
			printf("uLulubUB");
			Ui();
			L();
			Ui();
			Li();
			Ui();
			Bi();
			U();
			B();
			break;
		case 21:
			printf("Should Never Be Here");
			break;
		case 23:
			printf("Should Never Be Here");
			break;
		case 28:
			printf("LulubUB");
			L();
			Ui();
			Li();
			Ui();
			Bi();
			U();
			B();
			break;
		case 30:
			printf("Should Never Be Here");
			break;
		case 32:
			printf("Should Never Be Here");
			break;
		case 37:
			printf("ULulubUB");
			U();
			L();
			Ui();
			Li();
			Ui();
			Bi();
			U();
			B();
			break;
		case 39:
			printf("Should Never Be Here");
			break;
		case 41:
			printf("Already in Place");
			break;
	}
}

void white_cross()
{
	int top = 0;
	int left = 0;
	int middle = 0;
	int right = 0;
	int bottom = 0;
	
	for (int i=0; i<9; i++) {
		if (get_color(i) == 'W') {
			switch (i) {
				case 1:
					top = 1;
					break;
				case 3:
					left = 1;
					break;
				case 4:
					middle = 1;
					break;
				case 5:
					right = 1;
					break;
				case 7:
					bottom = 1;
					break;
			}
		}
	}
	
	if (top == 0 && left == 0 && middle == 1 && right == 0 && bottom == 0) {
		printf("\nYellow Spots: 4");
		printf("\nSolving Yellow Cross: BLUlub FRUru RUruf");
		B();
		L();
		U();
		Li();
		Ui();
		Bi();
		F();
		R();
		U();
		Ri();
		Ui();
		R();
		U();
		Ri();
		Ui();
		Fi();
	} else if (top == 1 && left == 1 && middle == 1 && right == 0 && bottom == 0) {
		printf("\nYellow Spots: 1, 3, 4");
		printf("\nSolving Yellow Cross: FRUru RUruf");
		F();
		R();
		U();
		Ri();
		Ui();
		R();
		U();
		Ri();
		Ui();
		Fi();
	} else if (top == 0 && left == 1 && middle == 1 && right == 0 && bottom == 1) {
		printf("\nYellow Spots: 3, 4, 7");
		printf("\nSolving Yellow Cross: RBUbu BUbur");
		R();
		B();
		U();
		Bi();
		Ui();
		B();
		U();
		Bi();
		Ui();
		Ri();
	} else if (top == 0 && left == 0 && middle == 1 && right == 1 && bottom == 1) {
		printf("\nYellow Spots: 4, 5, 7");
		printf("\nSolving Yellow Cross: BLUlu LUlub");
		B();
		L();
		U();
		Li();
		Ui();
		L();
		U();
		Li();
		Ui();
		Bi();
	} else if (top == 1 && left == 0 && middle == 1 && right == 1 && bottom == 0) {
		printf("\nYellow Spots: 1, 4, 5");
		printf("\nSolving Yellow Cross: LFUfu FUful");
		L();
		F();
		U();
		Fi();
		Ui();
		F();
		U();
		Fi();
		Ui();
		Li();
	} else if (top == 0 && left == 1 && middle == 1 && right == 1 && bottom == 0) {
		printf("\nYellow Spots: 3, 4, 5");
		printf("\nSolving Yellow Cross: FRUruf");
		F();
		R();
		U();
		Ri();
		Ui();
		Fi();
	} else if (top == 1 && left == 0 && middle == 1 && right == 0 && bottom == 1) {
		printf("\nYellow Spots: 1, 4, 7");
		printf("\nSolving Yellow Cross: LFUful");
		L();
		F();
		U();
		Fi();
		Ui();
		Li();
	} else if (top == 1 && left == 1 && middle == 1 && right == 1 && bottom == 1) {
		printf("\nYellow Spots: 1, 3, 4, 5, 7");
		printf("\nSolving Yellow Cross: Already in Place");
	}
}
