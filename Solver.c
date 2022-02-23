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
/*turns
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
*/
char get_color(int);
void yellow_cross();

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
	
	//char input[100];
	//int done_flag = 0;
	
	/*while (done_flag != 1) {
		printf("\nEnter Movement: ");
		fgets(input, 100, stdin);
		
		for (int i=0; i<strlen(input)-1; i++) {
			if (input[i] == '1') { done_flag = 1; }
			
			perform_movement(input[i]);
		}
		
		display();
	}*/
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

//Solved - WWWWWWWWWOOOOOOOOOGGGGGGGGGRRRRRRRRRBBBBBBBBBYYYYYYYYY
//Mixed  - FRUBBDFLLfuFRRUL
//Mixed  - BYYOWWYRWWYGGOGRRROGGYGBBYORBOORWWWGBBOOBORRBYRGWYGWBY
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

/*turns
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
}*/

//Mixed  - FRUBBDFLLfuFRRUL
//Mixed  - BYYOWWYRWWYGGOGRRROGGYGBBYORBOORWWWGBBOOBORRBYRGWYGWBY
void yellow_cross()
{
	int check[24] = {1,3,5,7,10,12,14,16,19,21,23,25,28,30,32,34,37,39,41,43,46,48,50,52};
	int yellow_edges[4];
	int count = 0;
	
	int yellow_orange;
	int yellow_green;
	int yellow_red;
	int yellow_blue;
	
	char opposite_color;
	
	for (int i=0; i<24; i++) {
		if (get_color(check[i]) == 'Y') {
			yellow_edges[count] = check[i];
			count++;
		}
	}
	
	/*for (int i=0; i<4; i++) {
		printf("\nYellow Spot: %d", yellow_edges[i]);
	}*/
	
	for (int i=0; i<4; i++) {
		int yellow_spot = yellow_edges[i];
		switch (yellow_spot) {
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
	
	printf("\nYellow Orange: %d", yellow_orange);
	printf("\nYellow Green: %d", yellow_green);
	printf("\nYellow Red: %d", yellow_red);
	printf("\nYellow Blue: %d", yellow_blue);
}
