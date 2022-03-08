#include <stdio.h>
#include <string.h>

void display();
void reset();
int set(char[]);
void move_and_print_string(char[]);
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
char get_color(int);
void yellow_cross();
void yellow_corners();
void second_layer();
void OLL();
void PLL();
void end_display();

char cube[54];
char cube_copy[54];

char final_moves[200];
int final_moves_count = 0;

int main() {
	char input[54];
	printf("\nEnter Starting Cube Sequence: ");
		fgets(input, 55, stdin);
	
	int valid_input = set(input);
	if (valid_input == 0) { return -1; }
	
	printf("\n---------------------------------------------START--------------------------------------------\n");
	display();
	
	printf("\n-----------------------------------------YELLOW CROSS-----------------------------------------\n");
	yellow_cross();
	printf("\n");
	display();
	
	printf("\n----------------------------------------YELLOW CORNERS----------------------------------------\n");
	yellow_corners();
	printf("\n");
	display();
	
	printf("\n-----------------------------------------SECOND LAYER-----------------------------------------\n");
	second_layer();
	printf("\n");
	display();
	
	printf("\n----------------------------------------------OLL---------------------------------------------\n");
	OLL();
	printf("\n");
	display();
	
	printf("\n----------------------------------------------PLL---------------------------------------------\n");
	PLL();
	printf("\n");
	display();
	
	printf("\n----------------------------------------------END---------------------------------------------\n");
	end_display();
}

void display()
{
	//printf("\nCube!!!\n\n          ");
	printf("\n          ");
	
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

int set(char input_cube[])
{
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
		return 0;
	} else {
		for (int i=0; i<54; i++) {
			cube[i] = input_cube[i];
		}
		return 1;
	}
}

void move_and_print_string(char movement[])
{
	for (int i=0; i<strlen(movement); i++) {
		switch (movement[i]) {
			case 'U':
				U();
				printf("U");
				final_moves[final_moves_count] = 'U';
				break;
			case 'D':
				D();
				printf("D");
				final_moves[final_moves_count] = 'D';
				break;
			case 'L':
				L();
				printf("L");
				final_moves[final_moves_count] = 'L';
				break;
			case 'R':
				R();
				printf("R");
				final_moves[final_moves_count] = 'R';
				break;
			case 'F':
				F();
				printf("F");
				final_moves[final_moves_count] = 'F';
				break;
			case 'B':
				B();
				printf("B");
				final_moves[final_moves_count] = 'B';
				break;
			case 'u':
				Ui();
				printf("u");
				final_moves[final_moves_count] = 'u';
				break;
			case 'd':
				Di();
				printf("d");
				final_moves[final_moves_count] = 'd';
				break;
			case 'l':
				Li();
				printf("l");
				final_moves[final_moves_count] = 'l';
				break;
			case 'r':
				Ri();
				printf("r");
				final_moves[final_moves_count] = 'r';
				break;
			case 'f':
				Fi();
				printf("f");
				final_moves[final_moves_count] = 'f';
				break;
			case 'b':
				Bi();
				printf("b");
				final_moves[final_moves_count] = 'b';
				break;
			case ' ':
				printf(" ");
				final_moves_count--;
				break;
		}
		
		final_moves_count++;
	}
}

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
	
	//printf("\nYellow Orange: %d", yellow_orange);	
	printf("\nPlacing Yellow Orange: ");
	switch (yellow_orange) {
		case 1:
			move_and_print_string("uLL");
			break;
		case 3:
			move_and_print_string("LL");
			break;
		case 5:
			move_and_print_string("UULL");
			break;
		case 7:
			move_and_print_string("ULL");
			break;
		case 10:
			move_and_print_string("ufL");
			break;
		case 12:
			move_and_print_string("BD");
			break;
		case 14:
			move_and_print_string("fd");
			break;
		case 16:
			move_and_print_string("lfd");
			break;
		case 19:
			move_and_print_string("fL");
			break;
		case 21:
			move_and_print_string("L");
			break;
		case 23:
			move_and_print_string("FFL");
			break;
		case 25:
			move_and_print_string("FL");
			break;
		case 28:
			move_and_print_string("rFd");
			break;
		case 30:
			move_and_print_string("Fd");
			break;
		case 32:
			move_and_print_string("bD");
			break;
		case 34:
			move_and_print_string("rbD");
			break;
		case 37:
			move_and_print_string("Bl");
			break;
		case 39:
			move_and_print_string("RDD");
			break;
		case 41:
			move_and_print_string("l");
			break;
		case 43:
			move_and_print_string("bl");
			break;
		case 46:
			move_and_print_string("d");
			break;
		case 48:
			printf("Already in Place");
			break;
		case 50:			
			move_and_print_string("DD");
			break;
		case 52:
			move_and_print_string("D");
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
	
	//printf("\nYellow Green: %d", yellow_green);	
	printf("\nPlacing Yellow Green: ");
	switch (yellow_green) {
		case 1:
			move_and_print_string("UUFF");
			break;
		case 3:
			move_and_print_string("uFF");
			break;
		case 5:
			move_and_print_string("UFF");
			break;
		case 7:
			move_and_print_string("FF");
			break;
		case 10:
			move_and_print_string("Lfl");
			break;
		case 12:
			move_and_print_string("bUUFF");
			break;
		case 14:
			move_and_print_string("f");
			break;
		case 16:
			printf("Should Never Be Here");
			break;
		case 19:
			move_and_print_string("fdLD");
			break;
		case 21:
			move_and_print_string("dLD");
			break;
		case 23:
			move_and_print_string("Drd");
			break;
		case 25:
			move_and_print_string("FdLD");
			break;
		case 28:
			move_and_print_string("rFR");
			break;
		case 30:
			move_and_print_string("F");
			break;
		case 32:
			move_and_print_string("RRF");
			break;
		case 34:
			move_and_print_string("RF");
			break;
		case 37:
			move_and_print_string("UrFR");
			break;
		case 39:
			move_and_print_string("DRd");
			break;
		case 41:
			move_and_print_string("BBDRd");
			break;
		case 43:
			move_and_print_string("BDRd");
			break;
		case 46:
			printf("Already in Place");
			break;
		case 48:
			printf("Should Never Be Here");
			break;
		case 50:
			move_and_print_string("RDrd");
			break;
		case 52:
			move_and_print_string("lDDL");
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
	
	//printf("\nYellow Red: %d", yellow_red);	
	printf("\nPlacing Yellow Red: ");
	switch (yellow_red) {
		case 1:
			move_and_print_string("URR");
			break;
		case 3:
			move_and_print_string("UURR");
			break;
		case 5:
			move_and_print_string("RR");
			break;
		case 7:
			move_and_print_string("uRR");
			break;
		case 10:
			move_and_print_string("uFrf");
			break;
		case 12:
			move_and_print_string("DBd");
			break;
		case 14:
			move_and_print_string("dfD");
			break;
		case 16:
			printf("Should Never Be Here");
			break;
		case 19:
			move_and_print_string("Frf");		
			break;
		case 21:
			move_and_print_string("ddLDD");
			break;
		case 23:
			move_and_print_string("r");
			break;
		case 25:
			printf("Should Never Be Here");
			break;
		case 28:
			move_and_print_string("rdFD");
			break;
		case 30:
			move_and_print_string("dFD");
			break;
		case 32:
			move_and_print_string("Dbd");
			break;
		case 34:
			move_and_print_string("RdFD");
			break;
		case 37:
			move_and_print_string("bR");
			break;
		case 39:
			move_and_print_string("R");
			break;
		case 41:
			move_and_print_string("BBR");
			break;
		case 43:
			move_and_print_string("BR");
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
			move_and_print_string("BDbd");
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
	
	//printf("\nYellow Blue: %d", yellow_blue);
	printf("\nPlacing Yellow Blue: ");
	switch (yellow_blue) {
		case 1:
			move_and_print_string("BB");
			break;
		case 3:
			move_and_print_string("UBB");
			break;
		case 5:
			move_and_print_string("uBB");
			break;
		case 7:
			move_and_print_string("UUBB");
			break;
		case 10:
			move_and_print_string("lBL");
			break;
		case 12:
			move_and_print_string("B");
			break;
		case 14:
			move_and_print_string("DDfdd");
			break;
		case 16:
			printf("Should Never Be Here");
			break;
		case 19:
			move_and_print_string("uRbr");
			break;
		case 21:
			move_and_print_string("DLd");
			break;
		case 23:
			move_and_print_string("drD");
			break;
		case 25:
			printf("Should Never Be Here");
			break;
		case 28:
			move_and_print_string("Rbr");
			break;
		case 30:
			move_and_print_string("RRbrr");
			break;
		case 32:
			move_and_print_string("b");
			break;
		case 34:
			printf("Should Never Be Here");
			break;
		case 37:
			move_and_print_string("BDld");
			break;
		case 39:
			move_and_print_string("dRD");
			break;
		case 41:
			move_and_print_string("BBdRD");		
			break;
		case 43:
			move_and_print_string("BdRD");
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
	
	//printf("\nYellow Orange Green: %d", yellow_orange_green);	
	printf("\nPlacing Yellow Orange Green: ");
	switch (yellow_orange_green) {
		case 0:
			move_and_print_string("uFRUUrf");
			break;
		case 2:
			move_and_print_string("UUFRUUrf");
			break;
		case 6:
			move_and_print_string("FRUUrf");
			break;
		case 8:
			move_and_print_string("UFRUUrf");
			break;
		case 9:
			move_and_print_string("uFUf");
			break;
		case 11:
			move_and_print_string("luL");
			break;
		case 15:
			move_and_print_string("LUlUUFUf");
			break;
		case 17:
			move_and_print_string("luLUluL");
			break;
		case 18:
			move_and_print_string("FUf");
			break;
		case 20:
			move_and_print_string("UluL");
			break;
		case 24:
			move_and_print_string("lULFUf");
			break;
		case 26:
			move_and_print_string("RurUluL");
			break;
		case 27:
			move_and_print_string("UFUf");
			break;
		case 29:
			move_and_print_string("UUluL");
			break;
		case 33:
			move_and_print_string("fUFlUL");
			break;
		case 35:
			move_and_print_string("ruRuluL");
			break;
		case 36:
			move_and_print_string("UUFUf");
			break;
		case 38:
			move_and_print_string("uluL");
			break;
		case 42:
			move_and_print_string("BUblUL");
			break;
		case 44:
			move_and_print_string("buBluL");
			break;
		case 45:
			printf("Already in Place");
			break;
		case 47:
			move_and_print_string("fuFUlUL");
			break;
		case 51:
			move_and_print_string("bUUBlUL");
			break;
		case 53:
			move_and_print_string("BUUbluL");
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

	//printf("\nYellow Green Red: %d", yellow_green_red);	
	printf("\nPlacing Yellow Green Red: ");
	switch (yellow_green_red) {
		case 0:
			move_and_print_string("UURBUUbr");
			break;
		case 2:
			move_and_print_string("URBUUbr");
			break;
		case 6:
			move_and_print_string("uRBUUbr");
			break;
		case 8:
			move_and_print_string("RBUUbr");
			break;
		case 9:
			move_and_print_string("UfUF");
			break;
		case 11:
			move_and_print_string("ufuF");
			break;
		case 15:
			move_and_print_string("LUlfUF");		
			break;
		case 17:
			printf("Should Never Be Here");
			break;
		case 18:
			move_and_print_string("uRUr");
			break;
		case 20:
			move_and_print_string("fuF");
			break;
		case 24:
			printf("Should Never Be Here");
			break;
		case 26:
			move_and_print_string("fuFUfuF");
			break;
		case 27:
			move_and_print_string("ufUF");
			break;
		case 29:
			move_and_print_string("UfuF");
			break;
		case 33:
			move_and_print_string("fUFufUF");
			break;
		case 35:
			move_and_print_string("BubUfuF");
			break;
		case 36:
			move_and_print_string("fUF");
			break;
		case 38:
			move_and_print_string("UUfuF");
			break;
		case 42:
			move_and_print_string("rURfUF");
			break;
		case 44:
			move_and_print_string("bUUfuF");
			break;
		case 45:
			printf("Should Never Be Here");
			break;
		case 47:
			printf("Already in Place");
			break;
		case 51:
			move_and_print_string("LUUlfuF");
			break;
		case 53:
			move_and_print_string("BUbfuF");
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

	//printf("\nYellow Red Blue: %d", yellow_red_blue);	
	printf("\nPlacing Yellow Red Blue: ");
	switch (yellow_red_blue) {
		case 0:
			move_and_print_string("UBLUUlb");
			break;
		case 2:
			move_and_print_string("BLUUlb");
			break;
		case 6:
			move_and_print_string("UUBLUUlb");
			break;
		case 8:
			move_and_print_string("uBLUUlb");
			break;
		case 9:
			move_and_print_string("rUR");
			break;
		case 11:
			move_and_print_string("uBub");
			break;
		case 15:
			move_and_print_string("LUlBUb");
			break;
		case 17:
			printf("Should Never Be Here");
			break;
		case 18:
			move_and_print_string("UrUR");
			break;
		case 20:
			move_and_print_string("Bub");
			break;
		case 24:
			printf("Should Never Be Here");
			break;
		case 26:
			printf("Should Never Be Here");
			break;
		case 27:
			move_and_print_string("UUrUR");
			break;
		case 29:
			move_and_print_string("ruR");
			break;
		case 33:
			printf("Should Never Be Here");
			break;
		case 35:
			move_and_print_string("BubruR");
			break;
		case 36:
			move_and_print_string("BUb");
			break;
		case 38:
			move_and_print_string("UruR");
			break;
		case 42:
			move_and_print_string("rURBUb");
			break;
		case 44:
			move_and_print_string("LulUruR");
			break;
		case 45:
			printf("Should Never Be Here");
			break;
		case 47:
			printf("Should Never Be Here");
			break;
		case 51:
			move_and_print_string("LUlruR");
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

	//printf("\nYellow Blue Orange: %d", yellow_blue_orange);	
	printf("\nPlacing Yellow Blue Orange: ");
	switch (yellow_blue_orange) {
		case 0:
			move_and_print_string("LFUUfl");
			break;
		case 2:
			move_and_print_string("uLFUUfl");
			break;
		case 6:
			move_and_print_string("ULFUUfl");
			break;
		case 8:
			move_and_print_string("UULFUUfl");
			break;
		case 9:
			move_and_print_string("LUl");
			break;
		case 11:
			move_and_print_string("UbuB");
			break;
		case 15:
			move_and_print_string("LUUlUbUB");
			break;
		case 17:
			printf("Should Never Be Here");
			break;
		case 18:
			move_and_print_string("ULUl");
			break;
		case 20:
			move_and_print_string("UUbuB");
			break;
		case 24:
			printf("Should Never Be Here");
			break;
		case 26:
			printf("Should Never Be Here");
			break;
		case 27:
			move_and_print_string("UULUl");
			break;
		case 29:
			move_and_print_string("ubuB");
			break;
		case 33:
			printf("Should Never Be Here");
			break;
		case 35:
			printf("Should Never Be Here");
			break;
		case 36:
			move_and_print_string("uLUl");
			break;
		case 38:
			move_and_print_string("buB");
			break;
		case 42:
			printf("Should Never Be Here");
			break;
		case 44:
			move_and_print_string("LulbuB");
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

	//printf("\nOrange Green: %d", orange_green);	
	printf("\nPlacing Orange Green: ");
	switch (orange_green) {
		case 1:
			move_and_print_string("UlULUFuf");
			break;
		case 3:
			move_and_print_string("UUlULUFuf");
			break;
		case 5:
			move_and_print_string("lULUFuf");
			break;
		case 7:
			move_and_print_string("ulULUFuf");
			break;
		case 10:
			move_and_print_string("UFufulUL");
			break;
		case 12:
			move_and_print_string("bUBULul lULUFuf");
			break;
		case 14:
			printf("Already in Place");
			break;
		case 19:
			move_and_print_string("UUFufulUL");
			break;
		case 21:
			move_and_print_string("lULUFuf UlULUFuf");
			break;
		case 23:
			move_and_print_string("RurufUF UlULUFuf");
			break;
		case 28:
			move_and_print_string("uFufulUL");
			break;
		case 30:
			move_and_print_string("RurufUF FufulUL");
			break;
		case 32:
			move_and_print_string("BuburUR UUlULUFuf");
			break;
		case 37:
			move_and_print_string("FufulUL");
			break;
		case 39:
			move_and_print_string("rURUBub ulULUFuf");
			break;
		case 41:
			move_and_print_string("LulubUB ulULUFuf");
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

	//printf("\nGreen Red: %d", green_red);	
	printf("\nPlacing Green Red: ");
	switch (green_red) {
		case 1:
			move_and_print_string("fUFURur");
			break;
		case 3:
			move_and_print_string("UfUFURur");
			break;
		case 5:
			move_and_print_string("ufUFURur");
			break;
		case 7:
			move_and_print_string("UUfUFURur");
			break;
		case 10:
			move_and_print_string("RurufUF");
			break;
		case 12:
			move_and_print_string("bUBULul ufUFURur");
			break;
		case 14:
			printf("Should Never Be Here");
			break;
		case 19:
			move_and_print_string("URurufUF");
			break;
		case 21:
			printf("Should Never Be Here");
			break;
		case 23:
			printf("Already in Place");
			break;
		case 28:
			move_and_print_string("UURurufUF");
			break;
		case 30:
			move_and_print_string("RurufUF uRurufUF");
			break;
		case 32:
			move_and_print_string("BuburUR UfUFURur");
			break;
		case 37:
			move_and_print_string("uRurufUF");
			break;
		case 39:
			move_and_print_string("BuburUR RurufUF");
			break;
		case 41:
			move_and_print_string("LulubUB UUfUFURur");
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
	
	//printf("\nRed Blue: %d", red_blue);	
	printf("\nPlacing Red Blue: ");
	switch (red_blue) {
		case 1:
			move_and_print_string("urURUBub");
			break;
		case 3:
			move_and_print_string("rURUBub");
			break;
		case 5:
			move_and_print_string("UUrURUBub");
			break;
		case 7:
			move_and_print_string("UrURUBub");
			break;
		case 10:
			move_and_print_string("uBuburUR");
			break;
		case 12:
			move_and_print_string("bUBULul UUrURUBub");
			break;
		case 14:
			printf("Should Never Be Here");
			break;
		case 19:
			move_and_print_string("BuburUR");
			break;
		case 21:
			printf("Should Never Be Here");
			break;
		case 23:
			printf("Should Never Be Here");
			break;
		case 28:
			move_and_print_string("UBuburUR");
			break;
		case 30:
			printf("Should Never Be Here");
			break;
		case 32:
			printf("Already in Place");
			break;
		case 37:
			move_and_print_string("UUBuburUR");
			break;
		case 39:
			move_and_print_string("BuburUR uBuburUR");
			break;
		case 41:
			move_and_print_string("bUBULul UBuburUR");
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
	
	//printf("\nBlue Orange: %d", blue_orange);	
	printf("\nPlacing Blue Orange: ");
	switch (blue_orange) {
		case 1:
			move_and_print_string("UUbUBULul");
			break;
		case 3:
			move_and_print_string("ubUBULul");
			break;
		case 5:
			move_and_print_string("UbUBULul");
			break;
		case 7:
			move_and_print_string("bUBULul");
			break;
		case 10:
			move_and_print_string("UULulubUB");
			break;
		case 12:
			move_and_print_string("bUBULul UbUBULul");
			break;
		case 14:
			printf("Should Never Be Here");
			break;
		case 19:
			move_and_print_string("uLulubUB");
			break;
		case 21:
			printf("Should Never Be Here");
			break;
		case 23:
			printf("Should Never Be Here");
			break;
		case 28:
			move_and_print_string("LulubUB");
			break;
		case 30:
			printf("Should Never Be Here");
			break;
		case 32:
			printf("Should Never Be Here");
			break;
		case 37:
			move_and_print_string("ULulubUB");
			break;
		case 39:
			printf("Should Never Be Here");
			break;
		case 41:
			printf("Already in Place");
			break;
	}
}

void OLL()
{	
	int case_found = 0;
	int count = 0;
	
	while (case_found == 0 && count < 4) {
		case_found = 1;
		printf("\nOLL Case: ");
		
		if      (get_color(0)  == 'W' && get_color(1)  == 'W' && get_color(2)  == 'W' && 
			     get_color(3)  == 'W' && get_color(4)  == 'W' && get_color(5)  == 'W' && 
			     get_color(6)  == 'W' && get_color(7)  == 'W' && get_color(8)  == 'W') 
			     { 
					 printf("Already in Place"); 
				 }
		else if (get_color(4)  == 'W' && get_color(9)  == 'W' && get_color(10) == 'W' && 
			     get_color(11) == 'W' && get_color(19) == 'W' && get_color(27) == 'W' && 
			     get_color(28) == 'W' && get_color(29) == 'W' && get_color(37) == 'W') 
			     { 
					 printf("1 - ");
					 move_and_print_string("RUbRBRRurFRf");
				 }
		else if (get_color(4)  == 'W' && get_color(10) == 'W' && get_color(11) == 'W' && 
			     get_color(19) == 'W' && get_color(27) == 'W' && get_color(28) == 'W' && 
			     get_color(36) == 'W' && get_color(37) == 'W' && get_color(38) == 'W')
			     { 
					 printf("2 - ");
					 move_and_print_string("LFlUULFFrFFRfl");
				 }
		else if (get_color(0)  == 'W' && get_color(4)  == 'W' && get_color(10) == 'W' && 
			     get_color(11) == 'W' && get_color(19) == 'W' && get_color(20) == 'W' && 
			     get_color(28) == 'W' && get_color(29) == 'W' && get_color(37) == 'W')
			     { 
					 printf("3 - ");
					 move_and_print_string("FURurfUFRUruf");
				 }
		else if (get_color(4)  == 'W' && get_color(6)  == 'W' && get_color(9)  == 'W' && 
			     get_color(10) == 'W' && get_color(19) == 'W' && get_color(27) == 'W' && 
			     get_color(28) == 'W' && get_color(36) == 'W' && get_color(37) == 'W')
			     { 
					 printf("4 - ");
					 move_and_print_string("FURurfuFRUruf");
				 }
		else if (get_color(0)  == 'W' && get_color(1)  == 'W' && get_color(3)  == 'W' && 
			     get_color(4)  == 'W' && get_color(11) == 'W' && get_color(19) == 'W' && 
			     get_color(20) == 'W' && get_color(28) == 'W' && get_color(29) == 'W')
			     { 
					 printf("5 - ");
					 move_and_print_string("rFFLFlFR");
				 }
		else if (get_color(1)  == 'W' && get_color(2)  == 'W' && get_color(4)  == 'W' && 
			     get_color(5)  == 'W' && get_color(9)  == 'W' && get_color(10) == 'W' && 
			     get_color(18) == 'W' && get_color(19) == 'W' && get_color(27) == 'W')
			     { 
					 printf("6 - ");
					 move_and_print_string("LFFrfRfl");
				 }
		else if (get_color(1)  == 'W' && get_color(3)  == 'W' && get_color(4)  == 'W' && 
			     get_color(6)  == 'W' && get_color(19) == 'W' && get_color(20) == 'W' && 
			     get_color(28) == 'W' && get_color(29) == 'W' && get_color(38) == 'W')
			     { 
					 printf("7 - ");
					 move_and_print_string("LFrFRFFl");
				 }
		else if (get_color(1)  == 'W' && get_color(4)  == 'W' && get_color(5)  == 'W' && 
			     get_color(8)  == 'W' && get_color(9)  == 'W' && get_color(10) == 'W' && 
			     get_color(18) == 'W' && get_color(19) == 'W' && get_color(36) == 'W')
			     { 
					 printf("8 - ");
					 move_and_print_string("RUUrUUrFRf");
				 }
		else if (get_color(1)  == 'W' && get_color(3)  == 'W' && get_color(4)  == 'W' && 
			     get_color(8)  == 'W' && get_color(9)  == 'W' && get_color(18) == 'W' && 
			     get_color(19) == 'W' && get_color(28) == 'W' && get_color(36) == 'W')
			     { 
					 printf("9 - ");
					 move_and_print_string("RUrurFRRUruf");
				 }
		else if (get_color(2)  == 'W' && get_color(3)  == 'W' && get_color(4)  == 'W' && 
			     get_color(7)  == 'W' && get_color(11) == 'W' && get_color(20) == 'W' && 
			     get_color(28) == 'W' && get_color(37) == 'W' && get_color(38) == 'W')
			     { 
					 printf("10 - ");
					 move_and_print_string("RUrUrFRfRUUr");
				 }
		else if (get_color(1)  == 'W' && get_color(2)  == 'W' && get_color(3)  == 'W' && 
			     get_color(4)  == 'W' && get_color(11) == 'W' && get_color(19) == 'W' && 
			     get_color(20) == 'W' && get_color(28) == 'W' && get_color(38) == 'W')
			     { 
					 printf("11 - ");
					 move_and_print_string("LFrFrDRdRFFl");
				 }
		else if (get_color(0)  == 'W' && get_color(1)  == 'W' && get_color(4)  == 'W' && 
			     get_color(5)  == 'W' && get_color(10) == 'W' && get_color(18) == 'W' && 
			     get_color(19) == 'W' && get_color(27) == 'W' && get_color(36) == 'W')
			     { 
					 printf("12 - ");
					 move_and_print_string("LrrfRfrFFRfRl");
				 }
		else if (get_color(3)  == 'W' && get_color(4)  == 'W' && get_color(5)  == 'W' && 
			     get_color(6)  == 'W' && get_color(19) == 'W' && get_color(20) == 'W' && 
			     get_color(29) == 'W' && get_color(37) == 'W' && get_color(38) == 'W')
			     { 
					 printf("13 - ");
					 move_and_print_string("FURuRRfRURur");
				 }
		else if (get_color(3)  == 'W' && get_color(4)  == 'W' && get_color(5)  == 'W' && 
			     get_color(8)  == 'W' && get_color(9)  == 'W' && get_color(18) == 'W' && 
			     get_color(19) == 'W' && get_color(36) == 'W' && get_color(37) == 'W')
			     { 
					 printf("14 - ");
					 move_and_print_string("rFRUrfRFuf");
				 }
		else if (get_color(0)  == 'W' && get_color(3)  == 'W' && get_color(4)  == 'W' && 
			     get_color(5)  == 'W' && get_color(11) == 'W' && get_color(19) == 'W' && 
			     get_color(20) == 'W' && get_color(29) == 'W' && get_color(37) == 'W')
			     { 
					 printf("15 - ");
					 move_and_print_string("rfRluLUrFR");
				 }
		else if (get_color(2)  == 'W' && get_color(3)  == 'W' && get_color(4)  == 'W' && 
			     get_color(5)  == 'W' && get_color(9)  == 'W' && get_color(18) == 'W' && 
			     get_color(19) == 'W' && get_color(27) == 'W' && get_color(37) == 'W')
			     { 
					 printf("16 - ");
					 move_and_print_string("LFlRUruLfl");
				 }
		else if (get_color(0)  == 'W' && get_color(4)  == 'W' && get_color(8)  == 'W' && 
			     get_color(10) == 'W' && get_color(11) == 'W' && get_color(19) == 'W' && 
			     get_color(28) == 'W' && get_color(36) == 'W' && get_color(37) == 'W')
			     { 
					 printf("17 - ");
					 move_and_print_string("RUrUrFRfUUrFRf");
				 }
		else if (get_color(0)  == 'W' && get_color(2)  == 'W' && get_color(4)  == 'W' && 
			     get_color(10) == 'W' && get_color(18) == 'W' && get_color(19) == 'W' && 
			     get_color(20) == 'W' && get_color(28) == 'W' && get_color(37) == 'W')
			     { 
					 printf("18 - ");
					 move_and_print_string("LFrFRFFLLbRbrBBL");
				 }
		else if (get_color(0)  == 'W' && get_color(2)  == 'W' && get_color(4)  == 'W' && 
			     get_color(10) == 'W' && get_color(11) == 'W' && get_color(19) == 'W' && 
			     get_color(27) == 'W' && get_color(28) == 'W' && get_color(37) == 'W')
			     { 
					 printf("19 - ");
					 move_and_print_string("lRBRBrbLRRFRf");
				 }
		else if (get_color(0)  == 'W' && get_color(2)  == 'W' && get_color(4)  == 'W' && 
			     get_color(6)  == 'W' && get_color(8)  == 'W' && get_color(10) == 'W' && 
			     get_color(19) == 'W' && get_color(28) == 'W' && get_color(37) == 'W') 
			     { 
					 printf("20 - ");
					 move_and_print_string("RBUbrFFBdlDbFF");
				 }
		else if (get_color(1)  == 'W' && get_color(3)  == 'W' && get_color(4)  == 'W' && 
			     get_color(5)  == 'W' && get_color(7)  == 'W' && get_color(18) == 'W' && 
			     get_color(20) == 'W' && get_color(36) == 'W' && get_color(38) == 'W') 
			     { 
					 printf("21 - ");
					 move_and_print_string("RUUruRUruRur");
				 }
		else if (get_color(1)  == 'W' && get_color(3)  == 'W' && get_color(4)  == 'W' && 
			     get_color(5)  == 'W' && get_color(7)  == 'W' && get_color(9)  == 'W' && 
			     get_color(11) == 'W' && get_color(20) == 'W' && get_color(36) == 'W')
			     { 
					 printf("22 - ");
					 move_and_print_string("RUURRuRRuRRUUR");
				 }
		else if (get_color(1)  == 'W' && get_color(3)  == 'W' && get_color(4)  == 'W' && 
			     get_color(5)  == 'W' && get_color(6)  == 'W' && get_color(7)  == 'W' && 
			     get_color(8)  == 'W' && get_color(36) == 'W' && get_color(38) == 'W')
			     { 
					 printf("23 - ");
					 move_and_print_string("RRdRUUrDRUUR");
				 }
		else if (get_color(1)  == 'W' && get_color(3)  == 'W' && get_color(4)  == 'W' && 
			     get_color(5)  == 'W' && get_color(6)  == 'W' && get_color(7)  == 'W' && 
			     get_color(8)  == 'W' && get_color(9)  == 'W' && get_color(29) == 'W')
			     { 
					 printf("24 - ");
					 move_and_print_string("RURDruRdRR");
				 }
		else if (get_color(0)  == 'W' && get_color(1)  == 'W' && get_color(3)  == 'W' && 
			     get_color(4)  == 'W' && get_color(5)  == 'W' && get_color(7)  == 'W' && 
			     get_color(8)  == 'W' && get_color(18) == 'W' && get_color(29) == 'W')
			     { 
					 printf("25 - ");
					 move_and_print_string("rFRbrfRB");
				 }
		else if (get_color(1)  == 'W' && get_color(2)  == 'W' && get_color(3)  == 'W' && 
			     get_color(4)  == 'W' && get_color(5)  == 'W' && get_color(7)  == 'W' && 
			     get_color(9)  == 'W' && get_color(18) == 'W' && get_color(27) == 'W')
			     { 
					 printf("26 - ");
					 move_and_print_string("RUUruRur");
				 }
		else if (get_color(1)  == 'W' && get_color(3)  == 'W' && get_color(4)  == 'W' && 
			     get_color(5)  == 'W' && get_color(6)  == 'W' && get_color(7)  == 'W' && 
			     get_color(20) == 'W' && get_color(29) == 'W' && get_color(38) == 'W')
			     { 
					 printf("27 - ");
					 move_and_print_string("RUrURUUr");
				 }
		else if (get_color(0)  == 'W' && get_color(1)  == 'W' && get_color(2)  == 'W' && 
			     get_color(3)  == 'W' && get_color(4)  == 'W' && get_color(6)  == 'W' && 
			     get_color(8)  == 'W' && get_color(19) == 'W' && get_color(28) == 'W')
			     { 
					 printf("28 - ");
					 move_and_print_string("FRUruFFluLUF");
				 }
		else if (get_color(1)  == 'W' && get_color(2)  == 'W' && get_color(3)  == 'W' && 
			     get_color(4)  == 'W' && get_color(8)  == 'W' && get_color(18) == 'W' && 
			     get_color(19) == 'W' && get_color(28) == 'W' && get_color(38) == 'W')
			     { 
					 printf("29 - ");
					 move_and_print_string("RUruRurfuFRUr");
				 }
		else if (get_color(1)  == 'W' && get_color(3)  == 'W' && get_color(4)  == 'W' && 
			     get_color(6)  == 'W' && get_color(8)  == 'W' && get_color(9)  == 'W' && 
			     get_color(19) == 'W' && get_color(28) == 'W' && get_color(29) == 'W')
			     { 
					 printf("30 - ");
					 move_and_print_string("FrFRRuruRUrFF");
				 }
		else if (get_color(1)  == 'W' && get_color(2)  == 'W' && get_color(4)  == 'W' && 
			     get_color(5)  == 'W' && get_color(8)  == 'W' && get_color(10) == 'W' && 
			     get_color(18) == 'W' && get_color(19) == 'W' && get_color(38) == 'W')
			     { 
					 printf("31 - ");
					 move_and_print_string("ruFURurfR");
				 }
		else if (get_color(0)  == 'W' && get_color(1)  == 'W' && get_color(3)  == 'W' && 
			     get_color(4)  == 'W' && get_color(6)  == 'W' && get_color(19) == 'W' && 
			     get_color(20) == 'W' && get_color(28) == 'W' && get_color(36) == 'W')
			     { 
					 printf("32 - ");
					 move_and_print_string("LUfulULFl");
				 }
		else if (get_color(2)  == 'W' && get_color(3)  == 'W' && get_color(4)  == 'W' && 
			     get_color(5)  == 'W' && get_color(8)  == 'W' && get_color(18) == 'W' && 
			     get_color(19) == 'W' && get_color(37) == 'W' && get_color(38) == 'W')
			     { 
					 printf("33 - ");
					 move_and_print_string("RUrurFRf");
				 }
		else if (get_color(3)  == 'W' && get_color(4)  == 'W' && get_color(5)  == 'W' && 
			     get_color(6)  == 'W' && get_color(8)  == 'W' && get_color(9)  == 'W' && 
			     get_color(19) == 'W' && get_color(29) == 'W' && get_color(37) == 'W')
			     { 
					 printf("34 - ");
					 move_and_print_string("RURRurFRURuf");
				 }
		else if (get_color(0)  == 'W' && get_color(4)  == 'W' && get_color(5)  == 'W' && 
			     get_color(7)  == 'W' && get_color(8)  == 'W' && get_color(10) == 'W' && 
			     get_color(18) == 'W' && get_color(29) == 'W' && get_color(37) == 'W')
			     { 
					 printf("35 - ");
					 move_and_print_string("RUURRFRfRUUr");
				 }
		else if (get_color(0)  == 'W' && get_color(1)  == 'W' && get_color(4)  == 'W' && 
			     get_color(5)  == 'W' && get_color(8)  == 'W' && get_color(10) == 'W' && 
			     get_color(11) == 'W' && get_color(19) == 'W' && get_color(36) == 'W')
			     { 
					 printf("36 - ");
					 move_and_print_string("luLulULULflF");
				 }
		else if (get_color(0)  == 'W' && get_color(1)  == 'W' && get_color(3)  == 'W' && 
			     get_color(4)  == 'W' && get_color(8)  == 'W' && get_color(18) == 'W' && 
			     get_color(19) == 'W' && get_color(28) == 'W' && get_color(29) == 'W')
			     { 
					 printf("37 - ");
					 move_and_print_string("FrfRURur");
				 }
		else if (get_color(1)  == 'W' && get_color(2)  == 'W' && get_color(3)  == 'W' && 
			     get_color(4)  == 'W' && get_color(6)  == 'W' && get_color(19) == 'W' && 
			     get_color(27) == 'W' && get_color(28) == 'W' && get_color(38) == 'W')
			     { 
					 printf("38 - ");
					 move_and_print_string("RUrURururFRf");
				 }
		else if (get_color(2)  == 'W' && get_color(3)  == 'W' && get_color(4)  == 'W' && 
			     get_color(5)  == 'W' && get_color(6)  == 'W' && get_color(19) == 'W' && 
			     get_color(27) == 'W' && get_color(37) == 'W' && get_color(38) == 'W')
			     { 
					 printf("39 - ");
					 move_and_print_string("LfluLUFul");
				 }
		else if (get_color(0)  == 'W' && get_color(3)  == 'W' && get_color(4)  == 'W' && 
			     get_color(5)  == 'W' && get_color(8)  == 'W' && get_color(11) == 'W' && 
			     get_color(19) == 'W' && get_color(36) == 'W' && get_color(37) == 'W')
			     { 
					 printf("40 - ");
					 move_and_print_string("rFRUrufUR");
				 }
		else if (get_color(1)  == 'W' && get_color(3)  == 'W' && get_color(4)  == 'W' && 
			     get_color(6)  == 'W' && get_color(8)  == 'W' && get_color(19) == 'W' && 
			     get_color(28) == 'W' && get_color(36) == 'W' && get_color(38) == 'W')
			     { 
					 printf("41 - ");
					 move_and_print_string("RUrURUUrFRUruf");
				 }
		else if (get_color(0)  == 'W' && get_color(2)  == 'W' && get_color(3)  == 'W' && 
			     get_color(4)  == 'W' && get_color(7)  == 'W' && get_color(18) == 'W' && 
			     get_color(20) == 'W' && get_color(28) == 'W' && get_color(37) == 'W')
			     { 
					 printf("42 - ");
					 move_and_print_string("ruRurUURFRUruf");
				 }
		else if (get_color(1)  == 'W' && get_color(2)  == 'W' && get_color(4)  == 'W' && 
			     get_color(5)  == 'W' && get_color(8)  == 'W' && get_color(9)  == 'W' && 
			     get_color(10) == 'W' && get_color(11) == 'W' && get_color(19) == 'W') 
			     { 
					 printf("43 - ");
					 move_and_print_string("fulULF");
				 }
		else if (get_color(0)  == 'W' && get_color(1)  == 'W' && get_color(3)  == 'W' && 
			     get_color(4)  == 'W' && get_color(6)  == 'W' && get_color(19) == 'W' && 
			     get_color(27) == 'W' && get_color(28) == 'W' && get_color(29) == 'W')
			     { 
					 printf("44 - ");
					 move_and_print_string("FURurf");
				 }
		else if (get_color(2)  == 'W' && get_color(3)  == 'W' && get_color(4)  == 'W' && 
			     get_color(5)  == 'W' && get_color(8)  == 'W' && get_color(9)  == 'W' && 
			     get_color(11) == 'W' && get_color(19) == 'W' && get_color(37) == 'W')
			     { 
					 printf("45 - ");
					 move_and_print_string("FRUruf");
				 }
		else if (get_color(0)  == 'W' && get_color(1)  == 'W' && get_color(4)  == 'W' && 
			     get_color(6)  == 'W' && get_color(7)  == 'W' && get_color(10) == 'W' && 
			     get_color(27) == 'W' && get_color(28) == 'W' && get_color(29) == 'W')
			     { 
					 printf("46 - ");
					 move_and_print_string("rurFRfUR");
				 }
		else if (get_color(1)  == 'W' && get_color(4)  == 'W' && get_color(5)  == 'W' && 
			     get_color(10) == 'W' && get_color(18) == 'W' && get_color(19) == 'W' && 
			     get_color(27) == 'W' && get_color(29) == 'W' && get_color(38) == 'W')
			     { 
					 printf("47 - ");
					 move_and_print_string("rurFRfrFRfUR");
				 }
		else if (get_color(1)  == 'W' && get_color(3)  == 'W' && get_color(4)  == 'W' && 
			     get_color(9)  == 'W' && get_color(11) == 'W' && get_color(19) == 'W' && 
			     get_color(20) == 'W' && get_color(28) == 'W' && get_color(36) == 'W')
			     { 
					 printf("48 - ");
					 move_and_print_string("FRUruRUruf");
				 }
		else if (get_color(3)  == 'W' && get_color(4)  == 'W' && get_color(7)  == 'W' && 
			     get_color(18) == 'W' && get_color(27) == 'W' && get_color(28) == 'W' && 
			     get_color(29) == 'W' && get_color(37) == 'W' && get_color(38) == 'W')
			     { 
					 printf("49 - ");
					 move_and_print_string("RbRRFRRBRRfR");
				 }
		else if (get_color(4)  == 'W' && get_color(5)  == 'W' && get_color(7)  == 'W' && 
			     get_color(9)  == 'W' && get_color(10) == 'W' && get_color(11) == 'W' && 
			     get_color(20) == 'W' && get_color(36) == 'W' && get_color(37) == 'W')
			     { 
					 printf("50 - ");
					 move_and_print_string("RbRBRRUUFrfR");
				 }
		else if (get_color(3)  == 'W' && get_color(4)  == 'W' && get_color(5)  == 'W' && 
			     get_color(18) == 'W' && get_color(19) == 'W' && get_color(27) == 'W' && 
			     get_color(29) == 'W' && get_color(37) == 'W' && get_color(38) == 'W')
			     { 
					 printf("51 - ");
					 move_and_print_string("FURurURurf");
				 }
		else if (get_color(1)  == 'W' && get_color(4)  == 'W' && get_color(7)  == 'W' && 
			     get_color(10) == 'W' && get_color(18) == 'W' && get_color(27) == 'W' && 
			     get_color(28) == 'W' && get_color(29) == 'W' && get_color(38) == 'W')
			     { 
					 printf("52 - ");
					 move_and_print_string("RUrURuBubr");
				 }
		else if (get_color(1)  == 'W' && get_color(3)  == 'W' && get_color(4)  == 'W' && 
			     get_color(9)  == 'W' && get_color(11) == 'W' && get_color(19) == 'W' && 
			     get_color(27) == 'W' && get_color(28) == 'W' && get_color(29) == 'W')
			     { 
					 printf("53 - ");
					 move_and_print_string("FRUrufRUrurFRf");
				 }
		else if (get_color(1)  == 'W' && get_color(3)  == 'W' && get_color(4)  == 'W' && 
			     get_color(18) == 'W' && get_color(19) == 'W' && get_color(20) == 'W' && 
			     get_color(28) == 'W' && get_color(36) == 'W' && get_color(38) == 'W')
			     { 
					 printf("54 - ");
					 move_and_print_string("LFFrfRFrfRfl");
				 }
		else if (get_color(3)  == 'W' && get_color(4)  == 'W' && get_color(5)  == 'W' && 
			     get_color(18) == 'W' && get_color(19) == 'W' && get_color(20) == 'W' && 
			     get_color(36) == 'W' && get_color(37) == 'W' && get_color(38) == 'W')
			     { 
					 printf("55 - ");
					 move_and_print_string("rFRURuRRfRRurURUr");
				 }
		else if (get_color(3)  == 'W' && get_color(4)  == 'W' && get_color(5)  == 'W' && 
			     get_color(9)  == 'W' && get_color(11) == 'W' && get_color(19) == 'W' && 
			     get_color(27) == 'W' && get_color(29) == 'W' && get_color(37) == 'W')
			     { 
					 printf("56 - ");
					 move_and_print_string("LFlURurURurLfl");
				 }
		else if (get_color(0)  == 'W' && get_color(2)  == 'W' && get_color(3)  == 'W' && 
			     get_color(4)  == 'W' && get_color(5)  == 'W' && get_color(6)  == 'W' && 
			     get_color(8)  == 'W' && get_color(19) == 'W' && get_color(37) == 'W')
			     { 
					 printf("57 - ");
					 move_and_print_string("RUruLrFRfl");
				 }
		else 
				 { 
					 move_and_print_string("U");
				 	 case_found = 0; 
				 	 count++;
				 }
	}
}

void PLL()
{
	char last_layer[12] = {get_color(9) , get_color(10), get_color(11), 
						   get_color(18), get_color(19), get_color(20),  
						   get_color(27), get_color(28), get_color(29),  
						   get_color(36), get_color(37), get_color(38)};
						    
	int case_found = 0;
	int count = 0;
	
	while (case_found == 0 && count < 4) {
		case_found = 1;
		printf("\nPLL Case: ");
		
		if      (get_color(9)  == 'O' && get_color(10) == 'O' && get_color(11) == 'O' && 
			     get_color(18) == 'G' && get_color(19) == 'G' && get_color(20) == 'G' && 
			     get_color(27) == 'R' && get_color(28) == 'R' && get_color(29) == 'R' && 
			     get_color(36) == 'B' && get_color(37) == 'B' && get_color(38) == 'B') 
			     { 
					 printf("Already in Place"); 
				 }
		// H
		else if (get_color(9)  == 'O' && get_color(10) == 'R' && get_color(11) == 'O' && 
			     get_color(18) == 'G' && get_color(19) == 'B' && get_color(20) == 'G' && 
			     get_color(27) == 'R' && get_color(28) == 'O' && get_color(29) == 'R' && 
			     get_color(36) == 'B' && get_color(37) == 'G' && get_color(38) == 'B') 
			     { 
					 printf("H - ");
					 move_and_print_string("LRUUlrfbUUFB");	
				 }
		// Ua
		else if (get_color(9)  == 'O' && get_color(10) == 'R' && get_color(11) == 'O' && 
			     get_color(18) == 'G' && get_color(19) == 'G' && get_color(20) == 'G' && 
			     get_color(27) == 'R' && get_color(28) == 'B' && get_color(29) == 'R' && 
			     get_color(36) == 'B' && get_color(37) == 'O' && get_color(38) == 'B') 
			     { 
					 printf("Ua - ");
					 move_and_print_string("RRuruRURURuR");
				 }
		else if (get_color(9)  == 'O' && get_color(10) == 'O' && get_color(11) == 'O' && 
			     get_color(18) == 'G' && get_color(19) == 'R' && get_color(20) == 'G' && 
			     get_color(27) == 'R' && get_color(28) == 'B' && get_color(29) == 'R' && 
			     get_color(36) == 'B' && get_color(37) == 'G' && get_color(38) == 'B') 
			     { 
					 printf("Ua - ");
					 move_and_print_string("FFufuFUFUFuF");
				 }
		else if (get_color(9)  == 'O' && get_color(10) == 'G' && get_color(11) == 'O' && 
			     get_color(18) == 'G' && get_color(19) == 'B' && get_color(20) == 'G' && 
			     get_color(27) == 'R' && get_color(28) == 'R' && get_color(29) == 'R' && 
			     get_color(36) == 'B' && get_color(37) == 'O' && get_color(38) == 'B') 
			     { 
					 printf("Ua - ");
					 move_and_print_string("BBubuBUBUBuB");
				 }
		else if (get_color(9)  == 'O' && get_color(10) == 'G' && get_color(11) == 'O' && 
			     get_color(18) == 'G' && get_color(19) == 'R' && get_color(20) == 'G' && 
			     get_color(27) == 'R' && get_color(28) == 'O' && get_color(29) == 'R' && 
			     get_color(36) == 'B' && get_color(37) == 'B' && get_color(38) == 'B') 
			     { 
					 printf("Ua - ");
					 move_and_print_string("LLuluLULULuL");
				 }
		// Ub
		else if (get_color(9)  == 'O' && get_color(10) == 'B' && get_color(11) == 'O' && 
			     get_color(18) == 'G' && get_color(19) == 'G' && get_color(20) == 'G' && 
			     get_color(27) == 'R' && get_color(28) == 'O' && get_color(29) == 'R' && 
			     get_color(36) == 'B' && get_color(37) == 'R' && get_color(38) == 'B') 
			     { 
					 printf("Ub - ");
					 move_and_print_string("rUrururURURR");
				 }
		else if (get_color(9)  == 'O' && get_color(10) == 'O' && get_color(11) == 'O' && 
			     get_color(18) == 'G' && get_color(19) == 'B' && get_color(20) == 'G' && 
			     get_color(27) == 'R' && get_color(28) == 'G' && get_color(29) == 'R' && 
			     get_color(36) == 'B' && get_color(37) == 'R' && get_color(38) == 'B') 
			     { 
					 printf("Ub - ");
					 move_and_print_string("fUfufufUFUFF");
				 }
		else if (get_color(9)  == 'O' && get_color(10) == 'B' && get_color(11) == 'O' && 
			     get_color(18) == 'G' && get_color(19) == 'O' && get_color(20) == 'G' && 
			     get_color(27) == 'R' && get_color(28) == 'R' && get_color(29) == 'R' && 
			     get_color(36) == 'B' && get_color(37) == 'G' && get_color(38) == 'B') 
			     { 
					 printf("Ub - ");
					 move_and_print_string("bUbububUBUBB");
				 }
		else if (get_color(9)  == 'O' && get_color(10) == 'R' && get_color(11) == 'O' && 
			     get_color(18) == 'G' && get_color(19) == 'O' && get_color(20) == 'G' && 
			     get_color(27) == 'R' && get_color(28) == 'G' && get_color(29) == 'R' && 
			     get_color(36) == 'B' && get_color(37) == 'B' && get_color(38) == 'B') 
			     { 
					 printf("Ub - ");
					 move_and_print_string("lUlululULULL");
				 }
		// Z
		else if (get_color(9)  == 'O' && get_color(10) == 'B' && get_color(11) == 'O' && 
			     get_color(18) == 'G' && get_color(19) == 'R' && get_color(20) == 'G' && 
			     get_color(27) == 'R' && get_color(28) == 'G' && get_color(29) == 'R' && 
			     get_color(36) == 'B' && get_color(37) == 'O' && get_color(38) == 'B') 
			     { 
					 printf("Z - ");
					 move_and_print_string("ruRRURUruRURuRurUU");
				 }
		else if (get_color(9)  == 'O' && get_color(10) == 'G' && get_color(11) == 'O' && 
			     get_color(18) == 'G' && get_color(19) == 'O' && get_color(20) == 'G' && 
			     get_color(27) == 'R' && get_color(28) == 'B' && get_color(29) == 'R' && 
			     get_color(36) == 'B' && get_color(37) == 'R' && get_color(38) == 'B') 
			     { 
					 printf("Z - ");
					 move_and_print_string("fuFFUFUfuFUFuFufUU");	
				 }
		// Aa
		else if (get_color(9)  == 'B' && get_color(10) == 'O' && get_color(11) == 'O' && 
			     get_color(18) == 'G' && get_color(19) == 'G' && get_color(20) == 'B' && 
			     get_color(27) == 'O' && get_color(28) == 'R' && get_color(29) == 'G' && 
			     get_color(36) == 'R' && get_color(37) == 'B' && get_color(38) == 'R') 
			     { 
					 printf("Aa - ");
					 move_and_print_string("rFrBBRfrBBRR");	
				 }
		else if (get_color(9)  == 'O' && get_color(10) == 'O' && get_color(11) == 'R' && 
			     get_color(18) == 'B' && get_color(19) == 'G' && get_color(20) == 'O' && 
			     get_color(27) == 'G' && get_color(28) == 'R' && get_color(29) == 'G' && 
			     get_color(36) == 'R' && get_color(37) == 'B' && get_color(38) == 'B') 
			     { 
					 printf("Aa - ");
					 move_and_print_string("fLfRRFlfRRFF");	
				 }
		else if (get_color(9)  == 'B' && get_color(10) == 'O' && get_color(11) == 'B' && 
			     get_color(18) == 'O' && get_color(19) == 'G' && get_color(20) == 'G' && 
			     get_color(27) == 'R' && get_color(28) == 'R' && get_color(29) == 'O' && 
			     get_color(36) == 'G' && get_color(37) == 'B' && get_color(38) == 'R') 
			     { 
					 printf("Aa - ");
					 move_and_print_string("bRbLLBrbLLBB");	
				 }
		else if (get_color(9)  == 'R' && get_color(10) == 'O' && get_color(11) == 'B' && 
			     get_color(18) == 'O' && get_color(19) == 'G' && get_color(20) == 'O' && 
			     get_color(27) == 'G' && get_color(28) == 'R' && get_color(29) == 'R' && 
			     get_color(36) == 'B' && get_color(37) == 'B' && get_color(38) == 'G') 
			     { 
					 printf("Aa - ");
					 move_and_print_string("lBlFFLblFFLL");	
				 }
		// Ab
		else if (get_color(9)  == 'O' && get_color(10) == 'O' && get_color(11) == 'G' && 
			     get_color(18) == 'R' && get_color(19) == 'G' && get_color(20) == 'R' && 
			     get_color(27) == 'B' && get_color(28) == 'R' && get_color(29) == 'O' && 
			     get_color(36) == 'G' && get_color(37) == 'B' && get_color(38) == 'B') 
			     { 
					 printf("Ab - ");
					 move_and_print_string("RbRFFrBRFFRR");
				 }
		else if (get_color(9)  == 'G' && get_color(10) == 'O' && get_color(11) == 'G' && 
			     get_color(18) == 'R' && get_color(19) == 'G' && get_color(20) == 'B' && 
			     get_color(27) == 'O' && get_color(28) == 'R' && get_color(29) == 'R' && 
			     get_color(36) == 'B' && get_color(37) == 'B' && get_color(38) == 'O') 
			     { 
					 printf("Ab - ");
					 move_and_print_string("FrFLLfRFLLFF");	
				 }
		else if (get_color(9)  == 'R' && get_color(10) == 'O' && get_color(11) == 'O' && 
			     get_color(18) == 'G' && get_color(19) == 'G' && get_color(20) == 'R' && 
			     get_color(27) == 'B' && get_color(28) == 'R' && get_color(29) == 'B' && 
			     get_color(36) == 'O' && get_color(37) == 'B' && get_color(38) == 'G') 
			     { 
					 printf("Ab - ");
					 move_and_print_string("BlBRRbLBRRBB");	
				 }
		else if (get_color(9)  == 'G' && get_color(10) == 'O' && get_color(11) == 'R' && 
			     get_color(18) == 'B' && get_color(19) == 'G' && get_color(20) == 'G' && 
			     get_color(27) == 'R' && get_color(28) == 'R' && get_color(29) == 'B' && 
			     get_color(36) == 'O' && get_color(37) == 'B' && get_color(38) == 'O') 
			     {
					 printf("Ab - ");
					 move_and_print_string("LfLBBlFLBBLL");	
				 }
		// E
		else if (get_color(9)  == 'B' && get_color(10) == 'O' && get_color(11) == 'G' && 
			     get_color(18) == 'R' && get_color(19) == 'G' && get_color(20) == 'O' && 
			     get_color(27) == 'G' && get_color(28) == 'R' && get_color(29) == 'B' && 
			     get_color(36) == 'O' && get_color(37) == 'B' && get_color(38) == 'R') 
			     {
					 printf("E - ");
					 move_and_print_string("rUlDDLuRlUrDDRuL");
				 }
		else if (get_color(9)  == 'G' && get_color(10) == 'O' && get_color(11) == 'B' && 
			     get_color(18) == 'O' && get_color(19) == 'G' && get_color(20) == 'R' && 
			     get_color(27) == 'B' && get_color(28) == 'R' && get_color(29) == 'G' && 
			     get_color(36) == 'R' && get_color(37) == 'B' && get_color(38) == 'O') 
			     {
					 printf("E - ");
					 move_and_print_string("fUbDDBuFbUfDDFuB");
				 }
		// F
		else if (get_color(9)  == 'B' && get_color(10) == 'R' && get_color(11) == 'O' && 
			     get_color(18) == 'G' && get_color(19) == 'G' && get_color(20) == 'G' && 
			     get_color(27) == 'R' && get_color(28) == 'O' && get_color(29) == 'B' && 
			     get_color(36) == 'O' && get_color(37) == 'B' && get_color(38) == 'R') 
			     {
					 printf("F - ");
					 move_and_print_string("rURuRRfuFURFrfRRu");
				 }
		else if (get_color(9)  == 'O' && get_color(10) == 'O' && get_color(11) == 'O' && 
			     get_color(18) == 'G' && get_color(19) == 'B' && get_color(20) == 'R' && 
			     get_color(27) == 'B' && get_color(28) == 'R' && get_color(29) == 'G' && 
			     get_color(36) == 'R' && get_color(37) == 'G' && get_color(38) == 'B') 
			     {
					 printf("F - ");
					 move_and_print_string("fUFuFFluLUFLflFFu");
				 }
		else if (get_color(9)  == 'G' && get_color(10) == 'O' && get_color(11) == 'B' && 
			     get_color(18) == 'O' && get_color(19) == 'B' && get_color(20) == 'G' && 
			     get_color(27) == 'R' && get_color(28) == 'R' && get_color(29) == 'R' && 
			     get_color(36) == 'B' && get_color(37) == 'G' && get_color(38) == 'O') 
			     {
					 printf("F - ");
					 move_and_print_string("bUBuBBruRUBRbrBBu");
				 }
		else if (get_color(9)  == 'O' && get_color(10) == 'R' && get_color(11) == 'G' && 
			     get_color(18) == 'R' && get_color(19) == 'G' && get_color(20) == 'O' && 
			     get_color(27) == 'G' && get_color(28) == 'O' && get_color(29) == 'R' && 
			     get_color(36) == 'B' && get_color(37) == 'B' && get_color(38) == 'B') 
			     {
					 printf("F - ");
					 move_and_print_string("lULuLLbuBULBlbLLu");
				 }
		// Ga
		else if (get_color(9)  == 'O' && get_color(10) == 'B' && get_color(11) == 'G' && 
			     get_color(18) == 'R' && get_color(19) == 'G' && get_color(20) == 'R' && 
			     get_color(27) == 'B' && get_color(28) == 'O' && get_color(29) == 'O' && 
			     get_color(36) == 'G' && get_color(37) == 'R' && get_color(38) == 'B') 
			     {
					 printf("Ga - ");
					 move_and_print_string("RUrurUFRURurfUrUUR");
				 }
		else if (get_color(9)  == 'G' && get_color(10) == 'O' && get_color(11) == 'G' && 
			     get_color(18) == 'R' && get_color(19) == 'B' && get_color(20) == 'B' && 
			     get_color(27) == 'O' && get_color(28) == 'G' && get_color(29) == 'R' && 
			     get_color(36) == 'B' && get_color(37) == 'R' && get_color(38) == 'O') 
			     {
					 printf("Ga - ");
					 move_and_print_string("FUfufULFUFuflUfUUF");
				 }
		else if (get_color(9)  == 'R' && get_color(10) == 'B' && get_color(11) == 'O' && 
			     get_color(18) == 'G' && get_color(19) == 'O' && get_color(20) == 'R' && 
			     get_color(27) == 'B' && get_color(28) == 'R' && get_color(29) == 'B' && 
			     get_color(36) == 'O' && get_color(37) == 'G' && get_color(38) == 'G') 
			     {
					 printf("Ga - ");
					 move_and_print_string("BUbubURBUBubrUbUUB");
				 }
		else if (get_color(9)  == 'G' && get_color(10) == 'R' && get_color(11) == 'R' && 
			     get_color(18) == 'B' && get_color(19) == 'O' && get_color(20) == 'G' && 
			     get_color(27) == 'R' && get_color(28) == 'G' && get_color(29) == 'B' && 
			     get_color(36) == 'O' && get_color(37) == 'B' && get_color(38) == 'O') 
			     {
					 printf("Ga - ");
					 move_and_print_string("LUlulUBLULulbUlUUL");
				 }
		// Gb
		else if (get_color(9)  == 'G' && get_color(10) == 'B' && get_color(11) == 'G' && 
			     get_color(18) == 'R' && get_color(19) == 'O' && get_color(20) == 'B' && 
			     get_color(27) == 'O' && get_color(28) == 'R' && get_color(29) == 'R' && 
			     get_color(36) == 'B' && get_color(37) == 'G' && get_color(38) == 'O') 
			     {
					 printf("Gb - ");
					 move_and_print_string("ruRBBDlULuLdBB");
				 }
		else if (get_color(9)  == 'G' && get_color(10) == 'B' && get_color(11) == 'R' && 
			     get_color(18) == 'B' && get_color(19) == 'G' && get_color(20) == 'G' && 
			     get_color(27) == 'R' && get_color(28) == 'O' && get_color(29) == 'B' && 
			     get_color(36) == 'O' && get_color(37) == 'R' && get_color(38) == 'O') 
			     {
					 printf("Gb - ");
					 move_and_print_string("fuFRRDbUBuBdRR");	
				 }
		else if (get_color(9)  == 'O' && get_color(10) == 'R' && get_color(11) == 'G' && 
			     get_color(18) == 'R' && get_color(19) == 'O' && get_color(20) == 'R' && 
			     get_color(27) == 'B' && get_color(28) == 'G' && get_color(29) == 'O' && 
			     get_color(36) == 'G' && get_color(37) == 'B' && get_color(38) == 'B') 
			     {
					 printf("Gb - ");
					 move_and_print_string("buBLLDfUFuFdLL");	
				 }
		else if (get_color(9)  == 'R' && get_color(10) == 'O' && get_color(11) == 'O' && 
			     get_color(18) == 'G' && get_color(19) == 'B' && get_color(20) == 'R' && 
			     get_color(27) == 'B' && get_color(28) == 'G' && get_color(29) == 'B' && 
			     get_color(36) == 'O' && get_color(37) == 'R' && get_color(38) == 'G') 
			     {
					 printf("Gb - ");
					 move_and_print_string("luLFFDrURuRdFF");	
				 }
		// Gc
		else if (get_color(9)  == 'R' && get_color(10) == 'R' && get_color(11) == 'B' && 
			     get_color(18) == 'O' && get_color(19) == 'G' && get_color(20) == 'O' && 
			     get_color(27) == 'G' && get_color(28) == 'B' && get_color(29) == 'R' && 
			     get_color(36) == 'B' && get_color(37) == 'O' && get_color(38) == 'G') 
			     {
					 printf("Gc - ");
					 move_and_print_string("luLULuflulULFuLUUl");
				 }
		else if (get_color(9)  == 'B' && get_color(10) == 'O' && get_color(11) == 'B' && 
			     get_color(18) == 'O' && get_color(19) == 'R' && get_color(20) == 'G' && 
			     get_color(27) == 'R' && get_color(28) == 'B' && get_color(29) == 'O' && 
			     get_color(36) == 'G' && get_color(37) == 'G' && get_color(38) == 'R') 
			     {
					 printf("Gc - ");
					 move_and_print_string("buBUBulbubUBLuBUUb");	
				 }
		else if (get_color(9)  == 'O' && get_color(10) == 'G' && get_color(11) == 'R' && 
			     get_color(18) == 'B' && get_color(19) == 'B' && get_color(20) == 'O' && 
			     get_color(27) == 'G' && get_color(28) == 'R' && get_color(29) == 'G' && 
			     get_color(36) == 'R' && get_color(37) == 'O' && get_color(38) == 'B') 
			     {
					 printf("Gc - ");
					 move_and_print_string("fuFUFurfufUFRuFUUf");
				 }
		else if (get_color(9)  == 'B' && get_color(10) == 'G' && get_color(11) == 'O' && 
			     get_color(18) == 'G' && get_color(19) == 'R' && get_color(20) == 'B' && 
			     get_color(27) == 'O' && get_color(28) == 'O' && get_color(29) == 'G' && 
			     get_color(36) == 'R' && get_color(37) == 'B' && get_color(38) == 'R') 
			     {
					 printf("Gc - ");
					 move_and_print_string("ruRURubrurURBuRUUr");
				 }
		// Gd
		else if (get_color(9)  == 'R' && get_color(10) == 'R' && get_color(11) == 'O' && 
			     get_color(18) == 'G' && get_color(19) == 'O' && get_color(20) == 'R' && 
			     get_color(27) == 'B' && get_color(28) == 'G' && get_color(29) == 'B' && 
			     get_color(36) == 'O' && get_color(37) == 'B' && get_color(38) == 'G') 
			     {
					 printf("Gd - ");
					 move_and_print_string("RUUrUbruRURBUrurUR");
				 }
		else if (get_color(9)  == 'O' && get_color(10) == 'B' && get_color(11) == 'G' && 
			     get_color(18) == 'R' && get_color(19) == 'O' && get_color(20) == 'R' && 
			     get_color(27) == 'B' && get_color(28) == 'R' && get_color(29) == 'O' && 
			     get_color(36) == 'G' && get_color(37) == 'G' && get_color(38) == 'B') 
			     {
					 printf("Gd - ");
					 move_and_print_string("FUUfUrfuFUFRUfufUF");	
				 }
		else if (get_color(9)  == 'G' && get_color(10) == 'O' && get_color(11) == 'R' && 
			     get_color(18) == 'B' && get_color(19) == 'B' && get_color(20) == 'G' && 
			     get_color(27) == 'R' && get_color(28) == 'G' && get_color(29) == 'B' && 
			     get_color(36) == 'O' && get_color(37) == 'R' && get_color(38) == 'O') 
			     {
					 printf("Gd - ");
					 move_and_print_string("BUUbUlbuBUBLUbubUB");
				 }
		else if (get_color(9)  == 'G' && get_color(10) == 'B' && get_color(11) == 'G' && 
			     get_color(18) == 'R' && get_color(19) == 'G' && get_color(20) == 'B' && 
			     get_color(27) == 'O' && get_color(28) == 'O' && get_color(29) == 'R' && 
			     get_color(36) == 'B' && get_color(37) == 'R' && get_color(38) == 'O') 
			     {
					 printf("Gd - ");
					 move_and_print_string("LUUlUfluLULFUlulUL");
				 }
		// Ja
		else if (get_color(9)  == 'G' && get_color(10) == 'G' && get_color(11) == 'B' && 
			     get_color(18) == 'O' && get_color(19) == 'O' && get_color(20) == 'G' && 
			     get_color(27) == 'R' && get_color(28) == 'R' && get_color(29) == 'R' && 
			     get_color(36) == 'B' && get_color(37) == 'B' && get_color(38) == 'O') 
			     {
					 printf("Ja - ");
					 move_and_print_string("rlUULUlUURuLU");
				 }
		else if (get_color(9)  == 'B' && get_color(10) == 'B' && get_color(11) == 'O' && 
			     get_color(18) == 'G' && get_color(19) == 'G' && get_color(20) == 'G' && 
			     get_color(27) == 'R' && get_color(28) == 'R' && get_color(29) == 'B' && 
			     get_color(36) == 'O' && get_color(37) == 'O' && get_color(38) == 'R') 
			     {
					 printf("Ja - ");
					 move_and_print_string("fbUUBUbUUFuBU");	
				 }
		else if (get_color(9)  == 'O' && get_color(10) == 'O' && get_color(11) == 'G' && 
			     get_color(18) == 'R' && get_color(19) == 'R' && get_color(20) == 'O' && 
			     get_color(27) == 'G' && get_color(28) == 'G' && get_color(29) == 'R' && 
			     get_color(36) == 'B' && get_color(37) == 'B' && get_color(38) == 'B') 
			     {
					 printf("Ja - ");
					 move_and_print_string("bfUUFUfUUBuFU");
				 }
		else if (get_color(9)  == 'O' && get_color(10) == 'O' && get_color(11) == 'O' && 
			     get_color(18) == 'G' && get_color(19) == 'G' && get_color(20) == 'R' && 
			     get_color(27) == 'B' && get_color(28) == 'B' && get_color(29) == 'G' && 
			     get_color(36) == 'R' && get_color(37) == 'R' && get_color(38) == 'B') 
			     {
					 printf("Ja - ");
					 move_and_print_string("lrUURUrUULuRU");
				 }
		// Jb
		else if (get_color(9)  == 'O' && get_color(10) == 'O' && get_color(11) == 'O' && 
			     get_color(18) == 'G' && get_color(19) == 'R' && get_color(20) == 'R' && 
			     get_color(27) == 'B' && get_color(28) == 'G' && get_color(29) == 'G' && 
			     get_color(36) == 'R' && get_color(37) == 'B' && get_color(38) == 'B') 
			     {
					 printf("Jb - ");
					 move_and_print_string("RUrfRUrurFRRuru");
				 }
		else if (get_color(9)  == 'O' && get_color(10) == 'G' && get_color(11) == 'G' && 
			     get_color(18) == 'R' && get_color(19) == 'O' && get_color(20) == 'O' && 
			     get_color(27) == 'G' && get_color(28) == 'R' && get_color(29) == 'R' && 
			     get_color(36) == 'B' && get_color(37) == 'B' && get_color(38) == 'B') 
			     {
					 printf("Jb - ");
					 move_and_print_string("FUflFUfufLFFufu");	
				 }
		else if (get_color(9)  == 'G' && get_color(10) == 'B' && get_color(11) == 'B' && 
			     get_color(18) == 'O' && get_color(19) == 'G' && get_color(20) == 'G' && 
			     get_color(27) == 'R' && get_color(28) == 'R' && get_color(29) == 'R' && 
			     get_color(36) == 'B' && get_color(37) == 'O' && get_color(38) == 'O') 
			     {
					 printf("Jb - ");
					 move_and_print_string("LUlbLUlulBLLulu");
				 }
		else if (get_color(9)  == 'B' && get_color(10) == 'O' && get_color(11) == 'O' && 
			     get_color(18) == 'G' && get_color(19) == 'G' && get_color(20) == 'G' && 
			     get_color(27) == 'R' && get_color(28) == 'B' && get_color(29) == 'B' && 
			     get_color(36) == 'O' && get_color(37) == 'R' && get_color(38) == 'R') 
			     {
					 printf("Jb - ");
					 move_and_print_string("BUbrBUbubRBBubu");
				 }
		// Na
		else if (get_color(9)  == 'O' && get_color(10) == 'R' && get_color(11) == 'R' && 
			     get_color(18) == 'B' && get_color(19) == 'G' && get_color(20) == 'G' && 
			     get_color(27) == 'R' && get_color(28) == 'O' && get_color(29) == 'O' && 
			     get_color(36) == 'G' && get_color(37) == 'B' && get_color(38) == 'B') 
			     {
					 printf("Na - ");
					 move_and_print_string("fRUrurFRRFuruRUfr");
				 }
		else if (get_color(9)  == 'R' && get_color(10) == 'O' && get_color(11) == 'O' && 
			     get_color(18) == 'G' && get_color(19) == 'B' && get_color(20) == 'B' && 
			     get_color(27) == 'O' && get_color(28) == 'R' && get_color(29) == 'R' && 
			     get_color(36) == 'B' && get_color(37) == 'G' && get_color(38) == 'G') 
			     {
					 printf("Na - ");
					 move_and_print_string("lFUfufLFFLufuFUlf");
				 }
		// Nb
		else if (get_color(9)  == 'R' && get_color(10) == 'R' && get_color(11) == 'O' && 
			     get_color(18) == 'G' && get_color(19) == 'G' && get_color(20) == 'B' && 
			     get_color(27) == 'O' && get_color(28) == 'O' && get_color(29) == 'R' && 
			     get_color(36) == 'B' && get_color(37) == 'B' && get_color(38) == 'G') 
			     {
					 printf("Nb - ");
					 move_and_print_string("BruRURbRRbURUruBR");
				 }
		else if (get_color(9)  == 'O' && get_color(10) == 'O' && get_color(11) == 'R' && 
			     get_color(18) == 'B' && get_color(19) == 'B' && get_color(20) == 'G' && 
			     get_color(27) == 'R' && get_color(28) == 'R' && get_color(29) == 'O' && 
			     get_color(36) == 'G' && get_color(37) == 'G' && get_color(38) == 'b') 
			     {
					 printf("Nb - ");
					 move_and_print_string("RfuFUFrFFrUFUfuRF");
				 }
		// Ra
		else if (get_color(9)  == 'O' && get_color(10) == 'O' && get_color(11) == 'G' && 
			     get_color(18) == 'R' && get_color(19) == 'G' && get_color(20) == 'O' && 
			     get_color(27) == 'G' && get_color(28) == 'B' && get_color(29) == 'R' && 
			     get_color(36) == 'B' && get_color(37) == 'R' && get_color(38) == 'B') 
			     {
					 printf("Ra - ");
					 move_and_print_string("RUUrUURbruRURBRRU");
				 }
		else if (get_color(9)  == 'G' && get_color(10) == 'O' && get_color(11) == 'B' && 
			     get_color(18) == 'O' && get_color(19) == 'R' && get_color(20) == 'G' && 
			     get_color(27) == 'R' && get_color(28) == 'G' && get_color(29) == 'R' && 
			     get_color(36) == 'B' && get_color(37) == 'B' && get_color(38) == 'O') 
			     {
					 printf("Ra - ");
					 move_and_print_string("FUUfUUFrfuFUFRFFU");	
				 }
		else if (get_color(9)  == 'O' && get_color(10) == 'B' && get_color(11) == 'O' && 
			     get_color(18) == 'G' && get_color(19) == 'G' && get_color(20) == 'R' && 
			     get_color(27) == 'B' && get_color(28) == 'R' && get_color(29) == 'G' && 
			     get_color(36) == 'R' && get_color(37) == 'O' && get_color(38) == 'B') 
			     {
					 printf("Ra - ");
					 move_and_print_string("BUUbUUBlbuBUBLBBU");
				 }
		else if (get_color(9)  == 'B' && get_color(10) == 'G' && get_color(11) == 'O' && 
			     get_color(18) == 'G' && get_color(19) == 'O' && get_color(20) == 'G' && 
			     get_color(27) == 'R' && get_color(28) == 'R' && get_color(29) == 'B' && 
			     get_color(36) == 'O' && get_color(37) == 'B' && get_color(38) == 'R') 
			     {
					 printf("Ra - ");
					 move_and_print_string("LUUlUULfluLULFLLU");
				 }
		// Rb
		else if (get_color(9)  == 'B' && get_color(10) == 'O' && get_color(11) == 'O' && 
			     get_color(18) == 'G' && get_color(19) == 'R' && get_color(20) == 'G' && 
			     get_color(27) == 'R' && get_color(28) == 'G' && get_color(29) == 'B' && 
			     get_color(36) == 'O' && get_color(37) == 'B' && get_color(38) == 'R') 
			     {
					 printf("Rb - ");
					 move_and_print_string("rUURUUrFRUrurfRRu");
				 }
		else if (get_color(9)  == 'O' && get_color(10) == 'G' && get_color(11) == 'O' && 
			     get_color(18) == 'G' && get_color(19) == 'O' && get_color(20) == 'R' && 
			     get_color(27) == 'B' && get_color(28) == 'R' && get_color(29) == 'G' && 
			     get_color(36) == 'R' && get_color(37) == 'B' && get_color(38) == 'B') 
			     {
					 printf("Rb - ");
					 move_and_print_string("fUUFUUfLFUfuflFFu");	
				 }
		else if (get_color(9)  == 'G' && get_color(10) == 'O' && get_color(11) == 'B' && 
			     get_color(18) == 'O' && get_color(19) == 'G' && get_color(20) == 'G' && 
			     get_color(27) == 'R' && get_color(28) == 'B' && get_color(29) == 'R' && 
			     get_color(36) == 'B' && get_color(37) == 'R' && get_color(38) == 'O') 
			     {
					 printf("Rb - ");
					 move_and_print_string("bUUBUUbRBUbubrBBu");
				 }
		else if (get_color(9)  == 'O' && get_color(10) == 'B' && get_color(11) == 'G' && 
			     get_color(18) == 'R' && get_color(19) == 'G' && get_color(20) == 'O' && 
			     get_color(27) == 'G' && get_color(28) == 'R' && get_color(29) == 'R' && 
			     get_color(36) == 'B' && get_color(37) == 'O' && get_color(38) == 'B') 
			     {
					 printf("Rb - ");
					 move_and_print_string("lUULUUlBLUlulbLLu");
				 }
		// T
		else if (get_color(9)  == 'O' && get_color(10) == 'R' && get_color(11) == 'O' && 
			     get_color(18) == 'G' && get_color(19) == 'G' && get_color(20) == 'R' && 
			     get_color(27) == 'B' && get_color(28) == 'O' && get_color(29) == 'G' && 
			     get_color(36) == 'R' && get_color(37) == 'B' && get_color(38) == 'B') 
			     {
					 printf("T - ");
					 move_and_print_string("RUrurFRRuruRUrf");
				 }
		else if (get_color(9)  == 'O' && get_color(10) == 'O' && get_color(11) == 'G' && 
			     get_color(18) == 'R' && get_color(19) == 'B' && get_color(20) == 'O' && 
			     get_color(27) == 'G' && get_color(28) == 'R' && get_color(29) == 'R' && 
			     get_color(36) == 'B' && get_color(37) == 'G' && get_color(38) == 'B') 
			     {
					 printf("T - ");
					 move_and_print_string("FUfufLFFufuFUfl");	
				 }
		else if (get_color(9)  == 'B' && get_color(10) == 'O' && get_color(11) == 'O' && 
			     get_color(18) == 'G' && get_color(19) == 'B' && get_color(20) == 'G' && 
			     get_color(27) == 'R' && get_color(28) == 'R' && get_color(29) == 'B' && 
			     get_color(36) == 'O' && get_color(37) == 'G' && get_color(38) == 'R') 
			     {
					 printf("T - ");
					 move_and_print_string("BUbubRBBubuBUbr");
				 }
		else if (get_color(9)  == 'G' && get_color(10) == 'R' && get_color(11) == 'B' && 
			     get_color(18) == 'O' && get_color(19) == 'G' && get_color(20) == 'G' && 
			     get_color(27) == 'R' && get_color(28) == 'O' && get_color(29) == 'R' && 
			     get_color(36) == 'B' && get_color(37) == 'B' && get_color(38) == 'O') 
			     {
					 printf("T - ");
					 move_and_print_string("LUlulBLLuluLUlb");
				 }
		// V
		else if (get_color(9)  == 'R' && get_color(10) == 'O' && get_color(11) == 'O' && 
			     get_color(18) == 'G' && get_color(19) == 'G' && get_color(20) == 'B' && 
			     get_color(27) == 'O' && get_color(28) == 'B' && get_color(29) == 'R' && 
			     get_color(36) == 'B' && get_color(37) == 'R' && get_color(38) == 'G') 
			     {
					 printf("V - ");
					 move_and_print_string("rUrubrBBubUbRBR");
				 }
		else if (get_color(9)  == 'O' && get_color(10) == 'O' && get_color(11) == 'R' && 
			     get_color(18) == 'B' && get_color(19) == 'R' && get_color(20) == 'G' && 
			     get_color(27) == 'R' && get_color(28) == 'G' && get_color(29) == 'O' && 
			     get_color(36) == 'G' && get_color(37) == 'B' && get_color(38) == 'B') 
			     {
					 printf("V - ");
					 move_and_print_string("fUfurfRRurUrFRF");	
				 }
		else if (get_color(9)  == 'O' && get_color(10) == 'B' && get_color(11) == 'R' && 
			     get_color(18) == 'B' && get_color(19) == 'G' && get_color(20) == 'G' && 
			     get_color(27) == 'R' && get_color(28) == 'R' && get_color(29) == 'O' && 
			     get_color(36) == 'G' && get_color(37) == 'O' && get_color(38) == 'B') 
			     {
					 printf("V - ");
					 move_and_print_string("bUbulbLLulUlBLB");
				 }
		else if (get_color(9)  == 'R' && get_color(10) == 'G' && get_color(11) == 'O' && 
			     get_color(18) == 'G' && get_color(19) == 'O' && get_color(20) == 'B' && 
			     get_color(27) == 'O' && get_color(28) == 'R' && get_color(29) == 'R' && 
			     get_color(36) == 'B' && get_color(37) == 'B' && get_color(38) == 'G') 
			     {
					 printf("V - ");
					 move_and_print_string("lUluflFFufUfLFL");
				 }
		// Y
		else if (get_color(9)  == 'R' && get_color(10) == 'B' && get_color(11) == 'O' && 
			     get_color(18) == 'G' && get_color(19) == 'G' && get_color(20) == 'B' && 
			     get_color(27) == 'O' && get_color(28) == 'R' && get_color(29) == 'R' && 
			     get_color(36) == 'B' && get_color(37) == 'O' && get_color(38) == 'G') 
			     {
					 printf("V - ");
					 move_and_print_string("ruRuLRUUruRUUlURRUR");
				 }
		else if (get_color(9)  == 'O' && get_color(10) == 'O' && get_color(11) == 'R' && 
			     get_color(18) == 'B' && get_color(19) == 'G' && get_color(20) == 'G' && 
			     get_color(27) == 'R' && get_color(28) == 'B' && get_color(29) == 'O' && 
			     get_color(36) == 'G' && get_color(37) == 'R' && get_color(38) == 'B') 
			     {
					 printf("V - ");
					 move_and_print_string("fuFuBFUUfuFUUbUFFUF");	
				 }
		else if (get_color(9)  == 'O' && get_color(10) == 'G' && get_color(11) == 'R' && 
			     get_color(18) == 'B' && get_color(19) == 'O' && get_color(20) == 'G' && 
			     get_color(27) == 'R' && get_color(28) == 'R' && get_color(29) == 'O' && 
			     get_color(36) == 'G' && get_color(37) == 'B' && get_color(38) == 'B') 
			     {
					 printf("V - ");
					 move_and_print_string("buBuFBUUbuBUUfUBBUB");
				 }
		else if (get_color(9)  == 'R' && get_color(10) == 'O' && get_color(11) == 'O' && 
			     get_color(18) == 'G' && get_color(19) == 'R' && get_color(20) == 'B' && 
			     get_color(27) == 'O' && get_color(28) == 'G' && get_color(29) == 'R' && 
			     get_color(36) == 'B' && get_color(37) == 'B' && get_color(38) == 'G') 
			     {
					 printf("V - ");
					 move_and_print_string("luLuRLUUluLUUrULLUL");
				 }
		else 
				 { 
					 move_and_print_string("U");
				 	 case_found = 0; 
				 	 count++;
				 }
	}
}

void end_display()
{
	printf("\nTotal Move Count: %d", final_moves_count);
	printf("\nMoves to Solve: ");
	for (int i=0; i<final_moves_count; i++) {
		printf("%c", final_moves[i]);
		if ((i+1)%10 == 0) { printf(" "); }
		if ((i+1)%50 == 0) { printf("\n                "); }
	}
}
