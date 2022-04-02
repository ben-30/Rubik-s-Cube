#include <stdio.h>
#include <time.h>
#include <string>

class Algorithm {
	public:
		char cube[54];
		char cube_copy[54];
		char scramble_seq[30];
		char final_moves[200];
		int final_moves_count = 0;
		
		Algorithm(std::string);
		void solve();
		void display();
		void reset();
		int set(std::string);
		void move_and_print_string(std::string);
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
		void F2L();
		void OLL();
		void PLL();
		int check_correct();
		void end_display();
		void scramble();
};

Algorithm::Algorithm(std::string input_cube) {
	int valid_input = set(input_cube);
	if (!valid_input) { return; }
	
	/*//printf("\n---------------------------------------------START--------------------------------------------\n");
	display();
	
	//printf("\n-----------------------------------------YELLOW CROSS-----------------------------------------\n");
	yellow_cross();
	//printf("\n");
	display();
	
	//printf("\n----------------------------------------------F2L---------------------------------------------\n");
	F2L();
	//printf("\n");
	display();
	
	//printf("\n----------------------------------------------OLL---------------------------------------------\n");
	OLL();
	//printf("\n");
	display();
	
	//printf("\n----------------------------------------------PLL---------------------------------------------\n");
	PLL();
	//printf("\n");
	display();
	
	//printf("\n----------------------------------------------END---------------------------------------------\n");
	end_display();*/
	
	//solve();
}

void Algorithm::solve() {
	yellow_cross();
	F2L();
	OLL();
	PLL();
}

void Algorithm::display() {
	//printf("\n          ");
	
	for (int i=0; i<9; i++) {
		if ( ((i+1)%3) == 0 ) {
			//printf("%c\n          ", cube[i]);
		} else {
			//printf("%c ", cube[i]);
		}
	}
	
	//printf("\n  %c %c %c   %c %c %c   %c %c %c   %c %c %c\n", cube[9], cube[10], cube[11], cube[18], cube[19], cube[20], cube[27], cube[28], cube[29], cube[36], cube[37], cube[38]);
	//printf("  %c %c %c   %c %c %c   %c %c %c   %c %c %c\n", cube[12], cube[13], cube[14], cube[21], cube[22], cube[23], cube[30], cube[31], cube[32], cube[39], cube[40], cube[41]);
	//printf("  %c %c %c   %c %c %c   %c %c %c   %c %c %c\n\n          ", cube[15], cube[16], cube[17], cube[24], cube[25], cube[26], cube[33], cube[34], cube[35], cube[42], cube[43], cube[44]);
	
	for (int i=45; i<54; i++) {
		if ( ((i+1)%3) == 0 ) {
			//printf("%c\n          ", cube[i]);
		} else {
			//printf("%c ", cube[i]);
		}
	}
}

void Algorithm::reset() {
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

int Algorithm::set(std::string input_cube) {
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
		//printf("\nInvalid Sequence!\n");
		return 0;
	} else {
		for (int i=0; i<54; i++) {
			cube[i] = input_cube[i];
		}
		return 1;
	}
}

void Algorithm::move_and_print_string(std::string movement) {
	for (int i=0; i<movement.length(); i++) {
		switch (movement[i]) {
			case 'U':
				U();
				////printf("U");
				final_moves[final_moves_count] = 'U';
				break;
			case 'D':
				D();
				////printf("D");
				final_moves[final_moves_count] = 'D';
				break;
			case 'L':
				L();
				////printf("L");
				final_moves[final_moves_count] = 'L';
				break;
			case 'R':
				R();
				////printf("R");
				final_moves[final_moves_count] = 'R';
				break;
			case 'F':
				F();
				////printf("F");
				final_moves[final_moves_count] = 'F';
				break;
			case 'B':
				B();
				////printf("B");
				final_moves[final_moves_count] = 'B';
				break;
			case 'u':
				Ui();
				////printf("u");
				final_moves[final_moves_count] = 'u';
				break;
			case 'd':
				Di();
				////printf("d");
				final_moves[final_moves_count] = 'd';
				break;
			case 'l':
				Li();
				////printf("l");
				final_moves[final_moves_count] = 'l';
				break;
			case 'r':
				Ri();
				////printf("r");
				final_moves[final_moves_count] = 'r';
				break;
			case 'f':
				Fi();
				////printf("f");
				final_moves[final_moves_count] = 'f';
				break;
			case 'b':
				Bi();
				////printf("b");
				final_moves[final_moves_count] = 'b';
				break;
			case ' ':
				////printf(" ");
				final_moves_count--;
				break;
		}
		
		final_moves_count++;
	}
}

void Algorithm::make_copy() {
	for (int i=0; i<54; i++) {
		cube_copy[i] = cube[i];
	}
}

char Algorithm::get_color(int spot) {
	return cube[spot];
}

void Algorithm::U() {
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

void Algorithm::Ui() {
	U();
	U();
	U();
}

void Algorithm::D() {
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

void Algorithm::Di() {
	D();
	D();
	D();
}

void Algorithm::L() {
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

void Algorithm::Li() {
	L();
	L();
	L();
}

void Algorithm::R() {
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

void Algorithm::Ri() {
	R();
	R();
	R();
}

void Algorithm::F() {
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

void Algorithm::Fi() {
	F();
	F();
	F();
}

void Algorithm::B() {
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

void Algorithm::Bi() {
	B();
	B();
	B();
}

void Algorithm::yellow_cross() {	
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
	
	////printf("\nYellow Orange: %d", yellow_orange);	
	////printf("\nPlacing Yellow Orange: ");
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
			//printf("Already in Place");
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
	
	////printf("\nYellow Green: %d", yellow_green);	
	////printf("\nPlacing Yellow Green: ");
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
			//printf("Should Never Be Here");
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
			//printf("Already in Place");
			break;
		case 48:
			//printf("Should Never Be Here");
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
	
	////printf("\nYellow Red: %d", yellow_red);	
	////printf("\nPlacing Yellow Red: ");
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
			//printf("Should Never Be Here");
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
			//printf("Should Never Be Here");
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
			//printf("Should Never Be Here");
			break;
		case 48:
			//printf("Should Never Be Here");
			break;
		case 50:
			//printf("Already in Place");
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
	
	////printf("\nYellow Blue: %d", yellow_blue);
	////printf("\nPlacing Yellow Blue: ");
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
			//printf("Should Never Be Here");
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
			//printf("Should Never Be Here");
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
			//printf("Should Never Be Here");
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
			//printf("Should Never Be Here");
			break;
		case 48:
			//printf("Should Never Be Here");
			break;
		case 50:
			//printf("Should Never Be Here");
			break;
		case 52:
			//printf("Already in Place");
			break;
	}
}

void Algorithm::F2L() {
	int yellow_green_red;
	int yellow_red_blue;
	int yellow_blue_orange;
	int yellow_orange_green;
	
	int green_red;
	int red_blue;
	int blue_orange;
	int orange_green;
	
	int case_found_A = 0;
	int count_A = 0;
	
	while (case_found_A == 0 && count_A < 4) {
		case_found_A = 1;
			
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

		//printf("\nPlacing Yellow Green Red: ");
	
		// Basic Inserts
		if (yellow_green_red == 20 && green_red == 5) {
			//printf("1 - ");
			move_and_print_string("URur");
		}
		else if (yellow_green_red == 27 && green_red == 19) {
			//printf("2 - ");
			move_and_print_string("ufUF");
		}
		else if (yellow_green_red == 20 && green_red == 10) {
			//printf("3 - ");
			move_and_print_string("fuF");
		}
		else if (yellow_green_red == 27 && green_red == 1) {
			//printf("4 - ");
			move_and_print_string("RUr");
		}
		// Reposition Edge
		else if (yellow_green_red == 20 && green_red == 1) {
			//printf("5 - ");
			move_and_print_string("UfrfRF");
		}
		else if (yellow_green_red == 27 && green_red == 10) {
			//printf("6 - ");
			move_and_print_string("ufrFRF");
		}
		else if (yellow_green_red == 20 && green_red == 3) {
			//printf("7 - ");
			move_and_print_string("RUBUUbUr");
		}
		else if (yellow_green_red == 27 && green_red == 37) {
			//printf("8 - ");
			move_and_print_string("UfUUFUfUUF");
		}
		// Reposition Edge and Flip Corner
		else if (yellow_green_red == 20 && green_red == 37) {
			//printf("9 - ");
			move_and_print_string("ruRfuF");
		}
		else if (yellow_green_red == 27 && green_red == 3) {
			//printf("10 - ");
			move_and_print_string("FUfRUr");
		}
		else if (yellow_green_red == 20 && green_red == 28) {
			//printf("11 - ");
			move_and_print_string("uRUUrUfuF");
		}
		else if (yellow_green_red == 27 && green_red == 7) {
			//printf("12 - ");
			move_and_print_string("rUURRUr");
		}
		else if (yellow_green_red == 20 && green_red == 19) {
			//printf("13 - ");
			move_and_print_string("rURfuF");
		}
		else if (yellow_green_red == 27 && green_red == 5) {
			//printf("14 - ");
			move_and_print_string("uRurURUr");
		}
		// Split Pair by Going Over
		else if (yellow_green_red == 20 && green_red == 7) {
			//printf("15 - ");
			move_and_print_string("RFUfur");
		}
		else if (yellow_green_red == 27 && green_red == 28) {
			//printf("16 - ");
			move_and_print_string("fruRUF");
		}
		else if (yellow_green_red == 8 && green_red == 5) {
			//printf("17 - ");
			move_and_print_string("RUUruRUr");
		}
		else if (yellow_green_red == 8 && green_red == 19) {
			//printf("18 - ");
			move_and_print_string("fUUFUfuF");
		}
		// Pair Made on Side
		else if (yellow_green_red == 8 && green_red == 1) {
			//printf("19 - ");
			move_and_print_string("URUURRFRf");
		}
		else if (yellow_green_red == 8 && green_red == 10) {
			//printf("20 - ");
			move_and_print_string("ufUUFFrfR");
		}
		else if (yellow_green_red == 8 && green_red == 3) {
			//printf("21 - ");
			move_and_print_string("RBUUbr");
		}
		else if (yellow_green_red == 8 && green_red == 37) {
			//printf("22 - ");
			move_and_print_string("flUULF");
		}
		// Weird
		else if (yellow_green_red == 8 && green_red == 7) {
			//printf("23 - ");
			move_and_print_string("UFrfRURUr");
		}
		else if (yellow_green_red == 8 && green_red == 28) {
			//printf("24 - ");
			move_and_print_string("UflULFRUr");
		}
		// Corner in Place, Edge in U Face
		else if (yellow_green_red == 47 && green_red == 5) {
			//printf("25 - ");
			move_and_print_string("UdRurD");
		}
		else if (yellow_green_red == 47 && green_red == 19) {
			//printf("26 - ");
			move_and_print_string("URurufUF");
		}
		else if (yellow_green_red == 26 && green_red == 5) {
			//printf("27 - ");
			move_and_print_string("RurURur");
		}
		else if (yellow_green_red == 33 && green_red == 19) {
			//printf("28 - ");
			move_and_print_string("RUruFrfR");
		}
		else if (yellow_green_red == 26 && green_red == 19) {
			//printf("29 - ");
			move_and_print_string("rFRfrFRf");
		}
		else if (yellow_green_red == 33 && green_red == 5) {
			//printf("30 - ");
			move_and_print_string("RUruRUr");
		}
		// Edge in Place, Corner in U Face
		else if (yellow_green_red == 8 && green_red == 30) {
			//printf("31 - ");
			move_and_print_string("RurUfUF");
		}
		else if (yellow_green_red == 8 && green_red == 23) {
			//printf("32 - ");
			move_and_print_string("RUruRUruRUr");
		}
		else if (yellow_green_red == 20 && green_red == 23) {
			//printf("33 - ");
			move_and_print_string("uRurUURur");
		}
		else if (yellow_green_red == 27 && green_red == 23) {
			//printf("34 - ");
			move_and_print_string("UfUFUUfUF");
		}
		else if (yellow_green_red == 20 && green_red == 30) {
			//printf("35 - ");
			move_and_print_string("uRUrUfuF");
		}
		else if (yellow_green_red == 27 && green_red == 30) {
			//printf("36 - ");
			move_and_print_string("UfuFuRUr");
		}
		// Edge and Corner in Place
		else if (yellow_green_red == 47 && green_red == 23) {
			//printf("37 - ");
			//printf("Already in Place");
		}
		else if (yellow_green_red == 47 && green_red == 30) {
			//printf("38 - ");
			move_and_print_string("RuRRUURufUF");
		}
		else if (yellow_green_red == 26 && green_red == 23) {
			//printf("39 - ");
			move_and_print_string("RuruRUrUURur");
		}
		else if (yellow_green_red == 33 && green_red == 23) {
			//printf("40 - ");
			move_and_print_string("RurURUUrURur");
		}
		else if (yellow_green_red == 26 && green_red == 30) {
			//printf("41 - ");
			move_and_print_string("RFURurfur");
		}
		else if (yellow_green_red == 33 && green_red == 30) {
			//printf("42 - ");
			move_and_print_string("RUFRUrufr");
		}
		// Corner in Wrong Corner
		else if (yellow_green_red == 17 || yellow_green_red == 24 || yellow_green_red == 45) {
			//printf("Wrong Corner - ");
			move_and_print_string("lUL");
			case_found_A = 0; 
		}
		else if (yellow_green_red == 15 || yellow_green_red == 44 || yellow_green_red == 51) {
			//printf("Wrong Corner - ");
			move_and_print_string("buB");
			case_found_A = 0; 
		}
		else if (yellow_green_red == 35 || yellow_green_red == 42 || yellow_green_red == 53) {
			//printf("Wrong Corner - ");
			move_and_print_string("rUR");
			case_found_A = 0; 
		}
		// Edge in Wrong Edge
		else if (green_red == 14 || green_red == 21) {
			//printf("Wrong Edge - ");
			move_and_print_string("lUL");
			case_found_A = 0; 
		}
		else if (green_red == 12 || green_red == 41) {
			//printf("Wrong Edge - ");
			move_and_print_string("buB");
			case_found_A = 0; 
		}
		else if (green_red == 32 || green_red == 39) {
			//printf("Remove From Wrong Edge - ");
			move_and_print_string("rUR");
			case_found_A = 0; 
		}
		// Rotate to Find Case
		else {
			move_and_print_string("U");
			case_found_A = 0; 
			count_A++;
		}
	}

	//printf("\n");
	display();

	int case_found_B = 0;
	int count_B = 0;
	//printf("\n");
	
	while (case_found_B == 0 && count_B < 4) {
		case_found_B = 1;
		
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
	
		//printf("\nPlacing Yellow Red Blue: ");
	
		// Basic Inserts
		if (yellow_red_blue == 29 && red_blue == 1) {
			//printf("1 - ");
			move_and_print_string("UBub");
		}
		else if (yellow_red_blue == 36 && red_blue == 28) {
			//printf("2 - ");
			move_and_print_string("urUR");
		}
		else if (yellow_red_blue == 29 && red_blue == 19) {
			//printf("3 - ");
			move_and_print_string("ruR");
		}
		else if (yellow_red_blue == 36 && red_blue == 3) {
			//printf("4 - ");
			move_and_print_string("BUb");
		}
		// Reposition Edge
		else if (yellow_red_blue == 29 && red_blue == 3) {
			//printf("5 - ");
			move_and_print_string("uBUbUUBub");
		}
		else if (yellow_red_blue == 36 && red_blue == 19) {
			//printf("6 - ");
			move_and_print_string("BBLUluBB");
		}
		else if (yellow_red_blue == 29 && red_blue == 7) {
			//printf("7 - ");
			move_and_print_string("BULUUlUb");
		}
		else if (yellow_red_blue == 36 && red_blue == 10) {
			//printf("8 - ");
			move_and_print_string("UrUURUrUUR");
		}
		// Reposition Edge and Flip Corner
		else if (yellow_red_blue == 29 && red_blue == 10) {
			//printf("9 - ");
			move_and_print_string("uBubUruR");
		}
		else if (yellow_red_blue == 36 && red_blue == 7) {
			//printf("10 - ");
			move_and_print_string("uBUbUBUb");
		}
		else if (yellow_red_blue == 29 && red_blue == 37) {
			//printf("11 - ");
			move_and_print_string("uBUUbUruR");
		}
		else if (yellow_red_blue == 36 && red_blue == 5) {
			//printf("12 - ");
			move_and_print_string("bUUBBUBBUB");
		}
		else if (yellow_red_blue == 29 && red_blue == 28) {
			//printf("13 - ");
			move_and_print_string("UrURuruR");
		}
		else if (yellow_red_blue == 36 && red_blue == 1) {
			//printf("14 - ");
			move_and_print_string("uBubUBUb");
		}
		// Split Pair by Going Over
		else if (yellow_red_blue == 29 && red_blue == 5) {
			//printf("15 - ");
			move_and_print_string("BLFuflb");
		}
		else if (yellow_red_blue == 36 && red_blue == 37) {
			//printf("16 - ");
			move_and_print_string("BubUUruR");
		}
		else if (yellow_red_blue == 2 && red_blue == 1) {
			//printf("17 - ");
			move_and_print_string("BUUbuBUb");
		}
		else if (yellow_red_blue == 2 && red_blue == 28) {
			//printf("18 - ");
			move_and_print_string("rUURUruR");
		}
		// Pair Made on Side
		else if (yellow_red_blue == 2 && red_blue == 3) {
			//printf("19 - ");
			move_and_print_string("UBUUBBRBr");
		}
		else if (yellow_red_blue == 2 && red_blue == 19) {
			//printf("20 - ");
			move_and_print_string("urUURRbrB");
		}
		else if (yellow_red_blue == 2 && red_blue == 7) {
			//printf("21 - ");
			move_and_print_string("BLUUlb");
		}
		else if (yellow_red_blue == 2 && red_blue == 10) {
			//printf("22 - ");
			move_and_print_string("rfUUFR");
		}
		// Weird
		else if (yellow_red_blue == 2 && red_blue == 5) {
			//printf("23 - ");
			move_and_print_string("URbrBUBUb");
		}
		else if (yellow_red_blue == 2 && red_blue == 37) {
			//printf("24 - ");
			move_and_print_string("UrfUFRBUb");
		}
		// Corner in Place, Edge in U Face
		else if (yellow_red_blue == 53 && red_blue == 1) {
			//printf("25 - ");
			move_and_print_string("ubRBrBUb");
		}
		else if (yellow_red_blue == 53 && red_blue == 28) {
			//printf("26 - ");
			move_and_print_string("UBuburUR");
		}
		else if (yellow_red_blue == 35 && red_blue == 1) {
			//printf("27 - ");
			move_and_print_string("BubUBub");
		}
		else if (yellow_red_blue == 42 && red_blue == 28) {
			//printf("28 - ");
			move_and_print_string("BUbuRbrB");
		}
		else if (yellow_red_blue == 35 && red_blue == 28) {
			//printf("29 - ");
			move_and_print_string("bRBrbRBr");
		}
		else if (yellow_red_blue == 42 && red_blue == 1) {
			//printf("30 - ");
			move_and_print_string("BUbuBUb");
		}
		// Edge in Place, Corner in U Face
		else if (yellow_red_blue == 2 && red_blue == 39) {
			//printf("31 - ");
			move_and_print_string("BubUrUR");
		}
		else if (yellow_red_blue == 2 && red_blue == 32) {
			//printf("32 - ");
			move_and_print_string("BUbuBUbuBUb");
		}
		else if (yellow_red_blue == 29 && red_blue == 32) {
			//printf("33 - ");
			move_and_print_string("uBubUUBub");
		}
		else if (yellow_red_blue == 36 && red_blue == 32) {
			//printf("34 - ");
			move_and_print_string("UrURUUrUR");
		}
		else if (yellow_red_blue == 29 && red_blue == 39) {
			//printf("35 - ");
			move_and_print_string("uBUbUruR");
		}
		else if (yellow_red_blue == 36 && red_blue == 39) {
			//printf("36 - ");
			move_and_print_string("UruRuBUb");
		}
		// Edge and Corner in Place
		else if (yellow_red_blue == 53 && red_blue == 32) {
			//printf("37 - ");
			//printf("Already in Place");
		}
		else if (yellow_red_blue == 53 && red_blue == 39) {
			//printf("38 - ");
			move_and_print_string("BBUURBBrUUbUb");
		}
		else if (yellow_red_blue == 35 && red_blue == 32) {
			//printf("39 - ");
			move_and_print_string("BubuBUbUUBub");
		}
		else if (yellow_red_blue == 42 && red_blue == 32) {
			//printf("40 - ");
			move_and_print_string("BubUBUUbUBub");
		}
		else if (yellow_red_blue == 35 && red_blue == 39) {
			//printf("41 - ");
			move_and_print_string("BRUBubrub");
		}
		else if (yellow_red_blue == 42 && red_blue == 39) {
			//printf("42 - ");
			move_and_print_string("BURBUburb");
		}
		// Corner in Wrong Corner
		else if (yellow_red_blue == 17 || yellow_red_blue == 24 || yellow_red_blue == 45) {
			//printf("Wrong Corner - ");
			move_and_print_string("lUL");
			case_found_B = 0; 
		}
		else if (yellow_red_blue == 15 || yellow_red_blue == 44 || yellow_red_blue == 51) {
			//printf("Wrong Corner - ");
			move_and_print_string("buB");
			case_found_B = 0; 
		}
		// Edge in Wrong Edge
		else if (red_blue == 14 || red_blue == 21) {
			//printf("Wrong Edge - ");
			move_and_print_string("lUL");
			case_found_B = 0; 
		}
		else if (red_blue == 12 || red_blue == 41) {
			//printf("Wrong Edge - ");
			move_and_print_string("buB");
			case_found_B = 0; 
		}
		// Rotate to Find Case
		else {
			move_and_print_string("U");
			case_found_B = 0; 
			count_B++;
		}
	}

	//printf("\n");
	display();
	
	int case_found_C = 0;
	int count_C = 0;
	//printf("\n");
	
	while (case_found_C == 0 && count_C < 4) {
		case_found_C = 1;
		
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
	
		//printf("\nPlacing Yellow Blue Orange: ");
		
		// Basic Inserts
		if (yellow_blue_orange == 38 && blue_orange == 3) {
			//printf("1 - ");
			move_and_print_string("ULul");
		}
		else if (yellow_blue_orange == 9 && blue_orange == 37) {
			//printf("2 - ");
			move_and_print_string("ubUB");
		}
		else if (yellow_blue_orange == 38 && blue_orange == 28) {
			//printf("3 - ");
			move_and_print_string("buB");
		}
		else if (yellow_blue_orange == 9 && blue_orange == 7) {
			//printf("4 - ");
			move_and_print_string("LUl");
		}
		// Reposition Edge
		else if (yellow_blue_orange == 38 && blue_orange == 7) {
			//printf("5 - ");
			move_and_print_string("uLUlUULul");
		}
		else if (yellow_blue_orange == 9 && blue_orange == 28) {
			//printf("6 - ");
			move_and_print_string("LLFUfuLL");
		}
		else if (yellow_blue_orange == 38 && blue_orange == 5) {
			//printf("7 - ");
			move_and_print_string("LUFUUfUl");
		}
		else if (yellow_blue_orange == 9 && blue_orange == 19) {
			//printf("8 - ");
			move_and_print_string("UbUUBUbUUB");
		}
		// Reposition Edge and Flip Corner
		else if (yellow_blue_orange == 38 && blue_orange == 19) {
			//printf("9 - ");
			move_and_print_string("uLulUbuB");
		}
		else if (yellow_blue_orange == 9 && blue_orange == 5) {
			//printf("10 - ");
			move_and_print_string("uLUlULUl");
		}
		else if (yellow_blue_orange == 38 && blue_orange == 10) {
			//printf("11 - ");
			move_and_print_string("uLUUlUbuB");
		}
		else if (yellow_blue_orange == 9 && blue_orange == 1) {
			//printf("12 - ");
			move_and_print_string("lUULLULLUL");
		}
		else if (yellow_blue_orange == 38 && blue_orange == 37) {
			//printf("13 - ");
			move_and_print_string("UbUBubuB");
		}
		else if (yellow_blue_orange == 9 && blue_orange == 3) {
			//printf("14 - ");
			move_and_print_string("uLulULUl");
		}
		// Split Pair by Going Over
		else if (yellow_blue_orange == 38 && blue_orange == 1) {
			//printf("15 - ");
			move_and_print_string("LFRurfl");
		}
		else if (yellow_blue_orange == 9 && blue_orange == 10) {
			//printf("16 - ");
			move_and_print_string("LulUUbuB");
		}
		else if (yellow_blue_orange == 0 && blue_orange == 3) {
			//printf("17 - ");
			move_and_print_string("LUUluLUl");
		}
		else if (yellow_blue_orange == 0 && blue_orange == 37) {
			//printf("18 - ");
			move_and_print_string("bUUBUbuB");
		}
		// Pair Made on Side
		else if (yellow_blue_orange == 0 && blue_orange == 7) {
			//printf("19 - ");
			move_and_print_string("ULUULLBLb");
		}
		else if (yellow_blue_orange == 0 && blue_orange == 28) {
			//printf("20 - ");
			move_and_print_string("ubUUBBlbL");
		}
		else if (yellow_blue_orange == 0 && blue_orange == 5) {
			//printf("21 - ");
			move_and_print_string("LFUUfl");
		}
		else if (yellow_blue_orange == 0 && blue_orange == 19) {
			//printf("22 - ");
			move_and_print_string("brUURB");
		}
		// Weird
		else if (yellow_blue_orange == 0 && blue_orange == 1) {
			//printf("23 - ");
			move_and_print_string("UBlbLULUl");
		}
		else if (yellow_blue_orange == 0 && blue_orange == 10) {
			//printf("24 - ");
			move_and_print_string("UbrURBLUl");
		}
		// Corner in Place, Edge in U Face
		else if (yellow_blue_orange == 51 && blue_orange == 3) {
			//printf("25 - ");
			move_and_print_string("ulBLbLUl");
		}
		else if (yellow_blue_orange == 51 && blue_orange == 37) {
			//printf("26 - ");
			move_and_print_string("ULulubUB");
		}
		else if (yellow_blue_orange == 44 && blue_orange == 3) {
			//printf("27 - ");
			move_and_print_string("LulULul");
		}
		else if (yellow_blue_orange == 15 && blue_orange == 37) {
			//printf("28 - ");
			move_and_print_string("LUluBlbL");
		}
		else if (yellow_blue_orange == 44 && blue_orange == 37) {
			//printf("29 - ");
			move_and_print_string("lBLblBLb");
		}
		else if (yellow_blue_orange == 15 && blue_orange == 3) {
			//printf("30 - ");
			move_and_print_string("LUluLUl");
		}
		// Edge in Place, Corner in U Face
		else if (yellow_blue_orange == 0 && blue_orange == 12) {
			//printf("31 - ");
			move_and_print_string("LulUbUB");
		}
		else if (yellow_blue_orange == 0 && blue_orange == 41) {
			//printf("32 - ");
			move_and_print_string("LUluLUluLUl");
		}
		else if (yellow_blue_orange == 38 && blue_orange == 41) {
			//printf("33 - ");
			move_and_print_string("uLulUULul");
		}
		else if (yellow_blue_orange == 9 && blue_orange == 41) {
			//printf("34 - ");
			move_and_print_string("UbUBUUbUB");
		}
		else if (yellow_blue_orange == 38 && blue_orange == 12) {
			//printf("35 - ");
			move_and_print_string("uLUlUbuB");
		}
		else if (yellow_blue_orange == 9 && blue_orange == 12) {
			//printf("36 - ");
			move_and_print_string("UbuBuLUl");
		}
		// Edge and Corner in Place
		else if (yellow_blue_orange == 51 && blue_orange == 41) {
			//printf("37 - ");
			//printf("Already in Place");
		}
		else if (yellow_blue_orange == 51 && blue_orange == 12) {
			//printf("38 - ");
			move_and_print_string("LLUUBLLbUUlUl");
		}
		else if (yellow_blue_orange == 44 && blue_orange == 41) {
			//printf("39 - ");
			move_and_print_string("LuluLUlUULul");
		}
		else if (yellow_blue_orange == 15 && blue_orange == 41) {
			//printf("40 - ");
			move_and_print_string("LulULUUlULul");
		}
		else if (yellow_blue_orange == 44 && blue_orange == 12) {
			//printf("41 - ");
			move_and_print_string("LBULulbul");
		}
		else if (yellow_blue_orange == 15 && blue_orange == 12) {
			//printf("42 - ");
			move_and_print_string("LUBLUlubl");
		}
		// Corner in Wrong Corner
		else if (yellow_blue_orange == 17 || yellow_blue_orange == 24 || yellow_blue_orange == 45) {
			//printf("Wrong Corner - ");
			move_and_print_string("lUL");
			case_found_C = 0; 
		}
		// Edge in Wrong Edge
		else if (blue_orange == 14 || blue_orange == 21) {
			//printf("Wrong Edge - ");
			move_and_print_string("lUL");
			case_found_C = 0; 
		}
		// Rotate to Find Case
		else {
			move_and_print_string("U");
			case_found_C = 0; 
			count_C++;
		}
	}

	//printf("\n");
	display();
	
	int case_found_D = 0;
	int count_D = 0;
	//printf("\n");

	while (case_found_D == 0 && count_D < 4) {
		case_found_D = 1;
		
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
	
		//printf("\nPlacing Yellow Orange Green: ");
		
		// Basic Inserts
		if (yellow_orange_green == 11 && orange_green == 7) {
			//printf("1 - ");
			move_and_print_string("UFuf");
		}
		else if (yellow_orange_green == 18 && orange_green == 10) {
			//printf("2 - ");
			move_and_print_string("ulUL");
		}
		else if (yellow_orange_green == 11 && orange_green == 37) {
			//printf("3 - ");
			move_and_print_string("luL");
		}
		else if (yellow_orange_green == 18 && orange_green == 5) {
			//printf("4 - ");
			move_and_print_string("FUf");
		}
		// Reposition Edge
		else if (yellow_orange_green == 11 && orange_green == 5) {
			//printf("5 - ");
			move_and_print_string("uFUfUUFuf");
		}
		else if (yellow_orange_green == 18 && orange_green == 37) {
			//printf("6 - ");
			move_and_print_string("FFRUruFF");
		}
		else if (yellow_orange_green == 11 && orange_green == 1) {
			//printf("7 - ");
			move_and_print_string("FURUUrUf");
		}
		else if (yellow_orange_green == 18 && orange_green == 28) {
			//printf("8 - ");
			move_and_print_string("UlUULUlUUL");
		}
		// Reposition Edge and Flip Corner
		else if (yellow_orange_green == 11 && orange_green == 28) {
			//printf("9 - ");
			move_and_print_string("uFufUluL");
		}
		else if (yellow_orange_green == 18 && orange_green == 1) {
			//printf("10 - ");
			move_and_print_string("uFUfUFUf");
		}
		else if (yellow_orange_green == 11 && orange_green == 19) {
			//printf("11 - ");
			move_and_print_string("uFUUfUluL");
		}
		else if (yellow_orange_green == 18 && orange_green == 3) {
			//printf("12 - ");
			move_and_print_string("fUUFFUFFUF");
		}
		else if (yellow_orange_green == 11 && orange_green == 10) {
			//printf("13 - ");
			move_and_print_string("UlULuluL");
		}
		else if (yellow_orange_green == 18 && orange_green == 7) {
			//printf("14 - ");
			move_and_print_string("uFufUFUf");
		}
		// Split Pair by Going Over
		else if (yellow_orange_green == 11 && orange_green == 3) {
			//printf("15 - ");
			move_and_print_string("FRBubrf");
		}
		else if (yellow_orange_green == 18 && orange_green == 19) {
			//printf("16 - ");
			move_and_print_string("FufUUluL");
		}
		else if (yellow_orange_green == 6 && orange_green == 7) {
			//printf("17 - ");
			move_and_print_string("FUUfuFUf");
		}
		else if (yellow_orange_green == 6 && orange_green == 10) {
			//printf("18 - ");
			move_and_print_string("lUULUluL");
		}
		// Pair Made on Side
		else if (yellow_orange_green == 6 && orange_green == 5) {
			//printf("19 - ");
			move_and_print_string("UFUUFFLFl");
		}
		else if (yellow_orange_green == 6 && orange_green == 37) {
			//printf("20 - ");
			move_and_print_string("ulUULLflF");
		}
		else if (yellow_orange_green == 6 && orange_green == 1) {
			//printf("21 - ");
			move_and_print_string("FRUUrf");
		}
		else if (yellow_orange_green == 6 && orange_green == 28) {
			//printf("22 - ");
			move_and_print_string("lbUUBL");
		}
		// Weird
		else if (yellow_orange_green == 6 && orange_green == 3) {
			//printf("23 - ");
			move_and_print_string("ULflFUFUf");
		}
		else if (yellow_orange_green == 6 && orange_green == 19) {
			//printf("24 - ");
			move_and_print_string("UlbUBLFUf");
		}
		// Corner in Place, Edge in U Face
		else if (yellow_orange_green == 45 && orange_green == 7) {
			//printf("25 - ");
			move_and_print_string("ufLFlFUf");
		}
		else if (yellow_orange_green == 45 && orange_green == 10) {
			//printf("26 - ");
			move_and_print_string("UFufulUL");
		}
		else if (yellow_orange_green == 17 && orange_green == 7) {
			//printf("27 - ");
			move_and_print_string("FufUFuf");
		}
		else if (yellow_orange_green == 24 && orange_green == 10) {
			//printf("28 - ");
			move_and_print_string("FUfuLflF");
		}
		else if (yellow_orange_green == 17 && orange_green == 10) {
			//printf("29 - ");
			move_and_print_string("fLFlfLFl");
		}
		else if (yellow_orange_green == 24 && orange_green == 7) {
			//printf("30 - ");
			move_and_print_string("FUfuFUf");
		}
		// Edge in Place, Corner in U Face
		else if (yellow_orange_green == 6 && orange_green == 21) {
			//printf("31 - ");
			move_and_print_string("FufUlUL");
		}
		else if (yellow_orange_green == 6 && orange_green == 14) {
			//printf("32 - ");
			move_and_print_string("FUfuFUfuFUf");
		}
		else if (yellow_orange_green == 11 && orange_green == 14) {
			//printf("33 - ");
			move_and_print_string("uFufUUFuf");
		}
		else if (yellow_orange_green == 18 && orange_green == 14) {
			//printf("34 - ");
			move_and_print_string("UlULUUlUL");
		}
		else if (yellow_orange_green == 11 && orange_green == 21) {
			//printf("35 - ");
			move_and_print_string("uFUfUluL");
		}
		else if (yellow_orange_green == 18 && orange_green == 21) {
			//printf("36 - ");
			move_and_print_string("UluLuFUf");
		}
		// Edge and Corner in Place
		else if (yellow_orange_green == 45 && orange_green == 14) {
			//printf("37 - ");
			//printf("Already in Place");
		}
		else if (yellow_orange_green == 45 && orange_green == 21) {
			//printf("38 - ");
			move_and_print_string("FFUULFFlUUfUf");
		}
		else if (yellow_orange_green == 17 && orange_green == 14) {
			//printf("39 - ");
			move_and_print_string("FufuFUfUUFuf");
		}
		else if (yellow_orange_green == 24 && orange_green == 14) {
			//printf("40 - ");
			move_and_print_string("FufUFUUfUFuf");
		}
		else if (yellow_orange_green == 17 && orange_green == 21) {
			//printf("41 - ");
			move_and_print_string("FLUFufluf");
		}
		else if (yellow_orange_green == 24 && orange_green == 21) {
			//printf("42 - ");
			move_and_print_string("FULFUfulf");
		}
		// Rotate to Find Case
		else {
			move_and_print_string("U");
			case_found_D = 0; 
			count_D++;
		}
	}
}

void Algorithm::OLL() {	
	int case_found = 0;
	int count = 0;
	
	while (case_found == 0 && count < 4) {
		case_found = 1;
		////printf("\nOLL Case: ");
		
		if      (get_color(0)  == 'W' && get_color(1)  == 'W' && get_color(2)  == 'W' && 
			     get_color(3)  == 'W' && get_color(4)  == 'W' && get_color(5)  == 'W' && 
			     get_color(6)  == 'W' && get_color(7)  == 'W' && get_color(8)  == 'W') 
			     { 
					 ////printf("Already in Place"); 
				 }
		else if (get_color(4)  == 'W' && get_color(9)  == 'W' && get_color(10) == 'W' && 
			     get_color(11) == 'W' && get_color(19) == 'W' && get_color(27) == 'W' && 
			     get_color(28) == 'W' && get_color(29) == 'W' && get_color(37) == 'W') 
			     { 
					 ////printf("1 - ");
					 move_and_print_string("RUbRBRRurFRf");
				 }
		else if (get_color(4)  == 'W' && get_color(10) == 'W' && get_color(11) == 'W' && 
			     get_color(19) == 'W' && get_color(27) == 'W' && get_color(28) == 'W' && 
			     get_color(36) == 'W' && get_color(37) == 'W' && get_color(38) == 'W')
			     { 
					 ////printf("2 - ");
					 move_and_print_string("LFlUULFFrFFRfl");
				 }
		else if (get_color(0)  == 'W' && get_color(4)  == 'W' && get_color(10) == 'W' && 
			     get_color(11) == 'W' && get_color(19) == 'W' && get_color(20) == 'W' && 
			     get_color(28) == 'W' && get_color(29) == 'W' && get_color(37) == 'W')
			     { 
					 ////printf("3 - ");
					 move_and_print_string("FURurfUFRUruf");
				 }
		else if (get_color(4)  == 'W' && get_color(6)  == 'W' && get_color(9)  == 'W' && 
			     get_color(10) == 'W' && get_color(19) == 'W' && get_color(27) == 'W' && 
			     get_color(28) == 'W' && get_color(36) == 'W' && get_color(37) == 'W')
			     { 
					 ////printf("4 - ");
					 move_and_print_string("FURurfuFRUruf");
				 }
		else if (get_color(0)  == 'W' && get_color(1)  == 'W' && get_color(3)  == 'W' && 
			     get_color(4)  == 'W' && get_color(11) == 'W' && get_color(19) == 'W' && 
			     get_color(20) == 'W' && get_color(28) == 'W' && get_color(29) == 'W')
			     { 
					 ////printf("5 - ");
					 move_and_print_string("rFFLFlFR");
				 }
		else if (get_color(1)  == 'W' && get_color(2)  == 'W' && get_color(4)  == 'W' && 
			     get_color(5)  == 'W' && get_color(9)  == 'W' && get_color(10) == 'W' && 
			     get_color(18) == 'W' && get_color(19) == 'W' && get_color(27) == 'W')
			     { 
					 ////printf("6 - ");
					 move_and_print_string("LFFrfRfl");
				 }
		else if (get_color(1)  == 'W' && get_color(3)  == 'W' && get_color(4)  == 'W' && 
			     get_color(6)  == 'W' && get_color(19) == 'W' && get_color(20) == 'W' && 
			     get_color(28) == 'W' && get_color(29) == 'W' && get_color(38) == 'W')
			     { 
					 ////printf("7 - ");
					 move_and_print_string("LFrFRFFl");
				 }
		else if (get_color(1)  == 'W' && get_color(4)  == 'W' && get_color(5)  == 'W' && 
			     get_color(8)  == 'W' && get_color(9)  == 'W' && get_color(10) == 'W' && 
			     get_color(18) == 'W' && get_color(19) == 'W' && get_color(36) == 'W')
			     { 
					 ////printf("8 - ");
					 move_and_print_string("RUUrUUrFRf");
				 }
		else if (get_color(1)  == 'W' && get_color(3)  == 'W' && get_color(4)  == 'W' && 
			     get_color(8)  == 'W' && get_color(9)  == 'W' && get_color(18) == 'W' && 
			     get_color(19) == 'W' && get_color(28) == 'W' && get_color(36) == 'W')
			     { 
					 ////printf("9 - ");
					 move_and_print_string("RUrurFRRUruf");
				 }
		else if (get_color(2)  == 'W' && get_color(3)  == 'W' && get_color(4)  == 'W' && 
			     get_color(7)  == 'W' && get_color(11) == 'W' && get_color(20) == 'W' && 
			     get_color(28) == 'W' && get_color(37) == 'W' && get_color(38) == 'W')
			     { 
					 ////printf("10 - ");
					 move_and_print_string("RUrUrFRfRUUr");
				 }
		else if (get_color(1)  == 'W' && get_color(2)  == 'W' && get_color(3)  == 'W' && 
			     get_color(4)  == 'W' && get_color(11) == 'W' && get_color(19) == 'W' && 
			     get_color(20) == 'W' && get_color(28) == 'W' && get_color(38) == 'W')
			     { 
					 ////printf("11 - ");
					 move_and_print_string("LFrFrDRdRFFl");
				 }
		else if (get_color(0)  == 'W' && get_color(1)  == 'W' && get_color(4)  == 'W' && 
			     get_color(5)  == 'W' && get_color(10) == 'W' && get_color(18) == 'W' && 
			     get_color(19) == 'W' && get_color(27) == 'W' && get_color(36) == 'W')
			     { 
					 ////printf("12 - ");
					 move_and_print_string("LrrfRfrFFRfRl");
				 }
		else if (get_color(3)  == 'W' && get_color(4)  == 'W' && get_color(5)  == 'W' && 
			     get_color(6)  == 'W' && get_color(19) == 'W' && get_color(20) == 'W' && 
			     get_color(29) == 'W' && get_color(37) == 'W' && get_color(38) == 'W')
			     { 
					 ////printf("13 - ");
					 move_and_print_string("FURuRRfRURur");
				 }
		else if (get_color(3)  == 'W' && get_color(4)  == 'W' && get_color(5)  == 'W' && 
			     get_color(8)  == 'W' && get_color(9)  == 'W' && get_color(18) == 'W' && 
			     get_color(19) == 'W' && get_color(36) == 'W' && get_color(37) == 'W')
			     { 
					 ////printf("14 - ");
					 move_and_print_string("rFRUrfRFuf");
				 }
		else if (get_color(0)  == 'W' && get_color(3)  == 'W' && get_color(4)  == 'W' && 
			     get_color(5)  == 'W' && get_color(11) == 'W' && get_color(19) == 'W' && 
			     get_color(20) == 'W' && get_color(29) == 'W' && get_color(37) == 'W')
			     { 
					 ////printf("15 - ");
					 move_and_print_string("rfRluLUrFR");
				 }
		else if (get_color(2)  == 'W' && get_color(3)  == 'W' && get_color(4)  == 'W' && 
			     get_color(5)  == 'W' && get_color(9)  == 'W' && get_color(18) == 'W' && 
			     get_color(19) == 'W' && get_color(27) == 'W' && get_color(37) == 'W')
			     { 
					 ////printf("16 - ");
					 move_and_print_string("LFlRUruLfl");
				 }
		else if (get_color(0)  == 'W' && get_color(4)  == 'W' && get_color(8)  == 'W' && 
			     get_color(10) == 'W' && get_color(11) == 'W' && get_color(19) == 'W' && 
			     get_color(28) == 'W' && get_color(36) == 'W' && get_color(37) == 'W')
			     { 
					 ////printf("17 - ");
					 move_and_print_string("RUrUrFRfUUrFRf");
				 }
		else if (get_color(0)  == 'W' && get_color(2)  == 'W' && get_color(4)  == 'W' && 
			     get_color(10) == 'W' && get_color(18) == 'W' && get_color(19) == 'W' && 
			     get_color(20) == 'W' && get_color(28) == 'W' && get_color(37) == 'W')
			     { 
					 ////printf("18 - ");
					 move_and_print_string("LFrFRFFLLbRbrBBL");
				 }
		else if (get_color(0)  == 'W' && get_color(2)  == 'W' && get_color(4)  == 'W' && 
			     get_color(10) == 'W' && get_color(11) == 'W' && get_color(19) == 'W' && 
			     get_color(27) == 'W' && get_color(28) == 'W' && get_color(37) == 'W')
			     { 
					 ////printf("19 - ");
					 move_and_print_string("lRBRBrbLRRFRf");
				 }
		else if (get_color(0)  == 'W' && get_color(2)  == 'W' && get_color(4)  == 'W' && 
			     get_color(6)  == 'W' && get_color(8)  == 'W' && get_color(10) == 'W' && 
			     get_color(19) == 'W' && get_color(28) == 'W' && get_color(37) == 'W') 
			     { 
					 ////printf("20 - ");
					 move_and_print_string("RBUbrFFBdlDbFF");
				 }
		else if (get_color(1)  == 'W' && get_color(3)  == 'W' && get_color(4)  == 'W' && 
			     get_color(5)  == 'W' && get_color(7)  == 'W' && get_color(18) == 'W' && 
			     get_color(20) == 'W' && get_color(36) == 'W' && get_color(38) == 'W') 
			     { 
					 ////printf("21 - ");
					 move_and_print_string("RUUruRUruRur");
				 }
		else if (get_color(1)  == 'W' && get_color(3)  == 'W' && get_color(4)  == 'W' && 
			     get_color(5)  == 'W' && get_color(7)  == 'W' && get_color(9)  == 'W' && 
			     get_color(11) == 'W' && get_color(20) == 'W' && get_color(36) == 'W')
			     { 
					 ////printf("22 - ");
					 move_and_print_string("RUURRuRRuRRUUR");
				 }
		else if (get_color(1)  == 'W' && get_color(3)  == 'W' && get_color(4)  == 'W' && 
			     get_color(5)  == 'W' && get_color(6)  == 'W' && get_color(7)  == 'W' && 
			     get_color(8)  == 'W' && get_color(36) == 'W' && get_color(38) == 'W')
			     { 
					 ////printf("23 - ");
					 move_and_print_string("RRdRUUrDRUUR");
				 }
		else if (get_color(1)  == 'W' && get_color(3)  == 'W' && get_color(4)  == 'W' && 
			     get_color(5)  == 'W' && get_color(6)  == 'W' && get_color(7)  == 'W' && 
			     get_color(8)  == 'W' && get_color(9)  == 'W' && get_color(29) == 'W')
			     { 
					 ////printf("24 - ");
					 move_and_print_string("RURDruRdRR");
				 }
		else if (get_color(0)  == 'W' && get_color(1)  == 'W' && get_color(3)  == 'W' && 
			     get_color(4)  == 'W' && get_color(5)  == 'W' && get_color(7)  == 'W' && 
			     get_color(8)  == 'W' && get_color(18) == 'W' && get_color(29) == 'W')
			     { 
					 ////printf("25 - ");
					 move_and_print_string("rFRbrfRB");
				 }
		else if (get_color(1)  == 'W' && get_color(2)  == 'W' && get_color(3)  == 'W' && 
			     get_color(4)  == 'W' && get_color(5)  == 'W' && get_color(7)  == 'W' && 
			     get_color(9)  == 'W' && get_color(18) == 'W' && get_color(27) == 'W')
			     { 
					 ////printf("26 - ");
					 move_and_print_string("RUUruRur");
				 }
		else if (get_color(1)  == 'W' && get_color(3)  == 'W' && get_color(4)  == 'W' && 
			     get_color(5)  == 'W' && get_color(6)  == 'W' && get_color(7)  == 'W' && 
			     get_color(20) == 'W' && get_color(29) == 'W' && get_color(38) == 'W')
			     { 
					 ////printf("27 - ");
					 move_and_print_string("RUrURUUr");
				 }
		else if (get_color(0)  == 'W' && get_color(1)  == 'W' && get_color(2)  == 'W' && 
			     get_color(3)  == 'W' && get_color(4)  == 'W' && get_color(6)  == 'W' && 
			     get_color(8)  == 'W' && get_color(19) == 'W' && get_color(28) == 'W')
			     { 
					 ////printf("28 - ");
					 move_and_print_string("FRUruFFluLUF");
				 }
		else if (get_color(1)  == 'W' && get_color(2)  == 'W' && get_color(3)  == 'W' && 
			     get_color(4)  == 'W' && get_color(8)  == 'W' && get_color(18) == 'W' && 
			     get_color(19) == 'W' && get_color(28) == 'W' && get_color(38) == 'W')
			     { 
					 ////printf("29 - ");
					 move_and_print_string("RUruRurfuFRUr");
				 }
		else if (get_color(1)  == 'W' && get_color(3)  == 'W' && get_color(4)  == 'W' && 
			     get_color(6)  == 'W' && get_color(8)  == 'W' && get_color(9)  == 'W' && 
			     get_color(19) == 'W' && get_color(28) == 'W' && get_color(29) == 'W')
			     { 
					 ////printf("30 - ");
					 move_and_print_string("FrFRRuruRUrFF");
				 }
		else if (get_color(1)  == 'W' && get_color(2)  == 'W' && get_color(4)  == 'W' && 
			     get_color(5)  == 'W' && get_color(8)  == 'W' && get_color(10) == 'W' && 
			     get_color(18) == 'W' && get_color(19) == 'W' && get_color(38) == 'W')
			     { 
					 ////printf("31 - ");
					 move_and_print_string("ruFURurfR");
				 }
		else if (get_color(0)  == 'W' && get_color(1)  == 'W' && get_color(3)  == 'W' && 
			     get_color(4)  == 'W' && get_color(6)  == 'W' && get_color(19) == 'W' && 
			     get_color(20) == 'W' && get_color(28) == 'W' && get_color(36) == 'W')
			     { 
					 ////printf("32 - ");
					 move_and_print_string("LUfulULFl");
				 }
		else if (get_color(2)  == 'W' && get_color(3)  == 'W' && get_color(4)  == 'W' && 
			     get_color(5)  == 'W' && get_color(8)  == 'W' && get_color(18) == 'W' && 
			     get_color(19) == 'W' && get_color(37) == 'W' && get_color(38) == 'W')
			     { 
					 ////printf("33 - ");
					 move_and_print_string("RUrurFRf");
				 }
		else if (get_color(3)  == 'W' && get_color(4)  == 'W' && get_color(5)  == 'W' && 
			     get_color(6)  == 'W' && get_color(8)  == 'W' && get_color(9)  == 'W' && 
			     get_color(19) == 'W' && get_color(29) == 'W' && get_color(37) == 'W')
			     { 
					 ////printf("34 - ");
					 move_and_print_string("RURRurFRURuf");
				 }
		else if (get_color(0)  == 'W' && get_color(4)  == 'W' && get_color(5)  == 'W' && 
			     get_color(7)  == 'W' && get_color(8)  == 'W' && get_color(10) == 'W' && 
			     get_color(18) == 'W' && get_color(29) == 'W' && get_color(37) == 'W')
			     { 
					 ////printf("35 - ");
					 move_and_print_string("RUURRFRfRUUr");
				 }
		else if (get_color(0)  == 'W' && get_color(1)  == 'W' && get_color(4)  == 'W' && 
			     get_color(5)  == 'W' && get_color(8)  == 'W' && get_color(10) == 'W' && 
			     get_color(11) == 'W' && get_color(19) == 'W' && get_color(36) == 'W')
			     { 
					 ////printf("36 - ");
					 move_and_print_string("luLulULULflF");
				 }
		else if (get_color(0)  == 'W' && get_color(1)  == 'W' && get_color(3)  == 'W' && 
			     get_color(4)  == 'W' && get_color(8)  == 'W' && get_color(18) == 'W' && 
			     get_color(19) == 'W' && get_color(28) == 'W' && get_color(29) == 'W')
			     { 
					 ////printf("37 - ");
					 move_and_print_string("FrfRURur");
				 }
		else if (get_color(1)  == 'W' && get_color(2)  == 'W' && get_color(3)  == 'W' && 
			     get_color(4)  == 'W' && get_color(6)  == 'W' && get_color(19) == 'W' && 
			     get_color(27) == 'W' && get_color(28) == 'W' && get_color(38) == 'W')
			     { 
					 ////printf("38 - ");
					 move_and_print_string("RUrURururFRf");
				 }
		else if (get_color(2)  == 'W' && get_color(3)  == 'W' && get_color(4)  == 'W' && 
			     get_color(5)  == 'W' && get_color(6)  == 'W' && get_color(19) == 'W' && 
			     get_color(27) == 'W' && get_color(37) == 'W' && get_color(38) == 'W')
			     { 
					 ////printf("39 - ");
					 move_and_print_string("LfluLUFul");
				 }
		else if (get_color(0)  == 'W' && get_color(3)  == 'W' && get_color(4)  == 'W' && 
			     get_color(5)  == 'W' && get_color(8)  == 'W' && get_color(11) == 'W' && 
			     get_color(19) == 'W' && get_color(36) == 'W' && get_color(37) == 'W')
			     { 
					 ////printf("40 - ");
					 move_and_print_string("rFRUrufUR");
				 }
		else if (get_color(1)  == 'W' && get_color(3)  == 'W' && get_color(4)  == 'W' && 
			     get_color(6)  == 'W' && get_color(8)  == 'W' && get_color(19) == 'W' && 
			     get_color(28) == 'W' && get_color(36) == 'W' && get_color(38) == 'W')
			     { 
					 ////printf("41 - ");
					 move_and_print_string("RUrURUUrFRUruf");
				 }
		else if (get_color(0)  == 'W' && get_color(2)  == 'W' && get_color(3)  == 'W' && 
			     get_color(4)  == 'W' && get_color(7)  == 'W' && get_color(18) == 'W' && 
			     get_color(20) == 'W' && get_color(28) == 'W' && get_color(37) == 'W')
			     { 
					 ////printf("42 - ");
					 move_and_print_string("ruRurUURFRUruf");
				 }
		else if (get_color(1)  == 'W' && get_color(2)  == 'W' && get_color(4)  == 'W' && 
			     get_color(5)  == 'W' && get_color(8)  == 'W' && get_color(9)  == 'W' && 
			     get_color(10) == 'W' && get_color(11) == 'W' && get_color(19) == 'W') 
			     { 
					 ////printf("43 - ");
					 move_and_print_string("fulULF");
				 }
		else if (get_color(0)  == 'W' && get_color(1)  == 'W' && get_color(3)  == 'W' && 
			     get_color(4)  == 'W' && get_color(6)  == 'W' && get_color(19) == 'W' && 
			     get_color(27) == 'W' && get_color(28) == 'W' && get_color(29) == 'W')
			     { 
					 ////printf("44 - ");
					 move_and_print_string("FURurf");
				 }
		else if (get_color(2)  == 'W' && get_color(3)  == 'W' && get_color(4)  == 'W' && 
			     get_color(5)  == 'W' && get_color(8)  == 'W' && get_color(9)  == 'W' && 
			     get_color(11) == 'W' && get_color(19) == 'W' && get_color(37) == 'W')
			     { 
					 ////printf("45 - ");
					 move_and_print_string("FRUruf");
				 }
		else if (get_color(0)  == 'W' && get_color(1)  == 'W' && get_color(4)  == 'W' && 
			     get_color(6)  == 'W' && get_color(7)  == 'W' && get_color(10) == 'W' && 
			     get_color(27) == 'W' && get_color(28) == 'W' && get_color(29) == 'W')
			     { 
					 ////printf("46 - ");
					 move_and_print_string("rurFRfUR");
				 }
		else if (get_color(1)  == 'W' && get_color(4)  == 'W' && get_color(5)  == 'W' && 
			     get_color(10) == 'W' && get_color(18) == 'W' && get_color(19) == 'W' && 
			     get_color(27) == 'W' && get_color(29) == 'W' && get_color(38) == 'W')
			     { 
					 ////printf("47 - ");
					 move_and_print_string("rurFRfrFRfUR");
				 }
		else if (get_color(1)  == 'W' && get_color(3)  == 'W' && get_color(4)  == 'W' && 
			     get_color(9)  == 'W' && get_color(11) == 'W' && get_color(19) == 'W' && 
			     get_color(20) == 'W' && get_color(28) == 'W' && get_color(36) == 'W')
			     { 
					 ////printf("48 - ");
					 move_and_print_string("FRUruRUruf");
				 }
		else if (get_color(3)  == 'W' && get_color(4)  == 'W' && get_color(7)  == 'W' && 
			     get_color(18) == 'W' && get_color(27) == 'W' && get_color(28) == 'W' && 
			     get_color(29) == 'W' && get_color(37) == 'W' && get_color(38) == 'W')
			     { 
					 ////printf("49 - ");
					 move_and_print_string("RbRRFRRBRRfR");
				 }
		else if (get_color(4)  == 'W' && get_color(5)  == 'W' && get_color(7)  == 'W' && 
			     get_color(9)  == 'W' && get_color(10) == 'W' && get_color(11) == 'W' && 
			     get_color(20) == 'W' && get_color(36) == 'W' && get_color(37) == 'W')
			     { 
					 ////printf("50 - ");
					 move_and_print_string("RbRBRRUUFrfR");
				 }
		else if (get_color(3)  == 'W' && get_color(4)  == 'W' && get_color(5)  == 'W' && 
			     get_color(18) == 'W' && get_color(19) == 'W' && get_color(27) == 'W' && 
			     get_color(29) == 'W' && get_color(37) == 'W' && get_color(38) == 'W')
			     { 
					 ////printf("51 - ");
					 move_and_print_string("FURurURurf");
				 }
		else if (get_color(1)  == 'W' && get_color(4)  == 'W' && get_color(7)  == 'W' && 
			     get_color(10) == 'W' && get_color(18) == 'W' && get_color(27) == 'W' && 
			     get_color(28) == 'W' && get_color(29) == 'W' && get_color(38) == 'W')
			     { 
					 ////printf("52 - ");
					 move_and_print_string("RUrURuBubr");
				 }
		else if (get_color(1)  == 'W' && get_color(3)  == 'W' && get_color(4)  == 'W' && 
			     get_color(9)  == 'W' && get_color(11) == 'W' && get_color(19) == 'W' && 
			     get_color(27) == 'W' && get_color(28) == 'W' && get_color(29) == 'W')
			     { 
					 ////printf("53 - ");
					 move_and_print_string("FRUrufRUrurFRf");
				 }
		else if (get_color(1)  == 'W' && get_color(3)  == 'W' && get_color(4)  == 'W' && 
			     get_color(18) == 'W' && get_color(19) == 'W' && get_color(20) == 'W' && 
			     get_color(28) == 'W' && get_color(36) == 'W' && get_color(38) == 'W')
			     { 
					 ////printf("54 - ");
					 move_and_print_string("LFFrfRFrfRfl");
				 }
		else if (get_color(3)  == 'W' && get_color(4)  == 'W' && get_color(5)  == 'W' && 
			     get_color(18) == 'W' && get_color(19) == 'W' && get_color(20) == 'W' && 
			     get_color(36) == 'W' && get_color(37) == 'W' && get_color(38) == 'W')
			     { 
					 ////printf("55 - ");
					 move_and_print_string("rFRURuRRfRRurURUr");
				 }
		else if (get_color(3)  == 'W' && get_color(4)  == 'W' && get_color(5)  == 'W' && 
			     get_color(9)  == 'W' && get_color(11) == 'W' && get_color(19) == 'W' && 
			     get_color(27) == 'W' && get_color(29) == 'W' && get_color(37) == 'W')
			     { 
					 ////printf("56 - ");
					 move_and_print_string("LFlURurURurLfl");
				 }
		else if (get_color(0)  == 'W' && get_color(2)  == 'W' && get_color(3)  == 'W' && 
			     get_color(4)  == 'W' && get_color(5)  == 'W' && get_color(6)  == 'W' && 
			     get_color(8)  == 'W' && get_color(19) == 'W' && get_color(37) == 'W')
			     { 
					 ////printf("57 - ");
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

void Algorithm::PLL() {
	char last_layer[12] = {get_color(9) , get_color(10), get_color(11), 
						   get_color(18), get_color(19), get_color(20),  
						   get_color(27), get_color(28), get_color(29),  
						   get_color(36), get_color(37), get_color(38)};
						    
	int case_found = 0;
	int count = 0;
	
	while (case_found == 0 && count < 4) {
		case_found = 1;
		////printf("\nPLL Case: ");
		
		if      (get_color(9)  == 'O' && get_color(10) == 'O' && get_color(11) == 'O' && 
			     get_color(18) == 'G' && get_color(19) == 'G' && get_color(20) == 'G' && 
			     get_color(27) == 'R' && get_color(28) == 'R' && get_color(29) == 'R' && 
			     get_color(36) == 'B' && get_color(37) == 'B' && get_color(38) == 'B') 
			     { 
					 ////printf("Already in Place"); 
				 }
		// H
		else if (get_color(9)  == 'O' && get_color(10) == 'R' && get_color(11) == 'O' && 
			     get_color(18) == 'G' && get_color(19) == 'B' && get_color(20) == 'G' && 
			     get_color(27) == 'R' && get_color(28) == 'O' && get_color(29) == 'R' && 
			     get_color(36) == 'B' && get_color(37) == 'G' && get_color(38) == 'B') 
			     { 
					 ////printf("H - ");
					 move_and_print_string("LRUUlrfbUUFB");	
				 }
		// Ua
		else if (get_color(9)  == 'O' && get_color(10) == 'R' && get_color(11) == 'O' && 
			     get_color(18) == 'G' && get_color(19) == 'G' && get_color(20) == 'G' && 
			     get_color(27) == 'R' && get_color(28) == 'B' && get_color(29) == 'R' && 
			     get_color(36) == 'B' && get_color(37) == 'O' && get_color(38) == 'B') 
			     { 
					 ////printf("Ua - ");
					 move_and_print_string("RRuruRURURuR");
				 }
		else if (get_color(9)  == 'O' && get_color(10) == 'O' && get_color(11) == 'O' && 
			     get_color(18) == 'G' && get_color(19) == 'R' && get_color(20) == 'G' && 
			     get_color(27) == 'R' && get_color(28) == 'B' && get_color(29) == 'R' && 
			     get_color(36) == 'B' && get_color(37) == 'G' && get_color(38) == 'B') 
			     { 
					 ////printf("Ua - ");
					 move_and_print_string("FFufuFUFUFuF");
				 }
		else if (get_color(9)  == 'O' && get_color(10) == 'G' && get_color(11) == 'O' && 
			     get_color(18) == 'G' && get_color(19) == 'B' && get_color(20) == 'G' && 
			     get_color(27) == 'R' && get_color(28) == 'R' && get_color(29) == 'R' && 
			     get_color(36) == 'B' && get_color(37) == 'O' && get_color(38) == 'B') 
			     { 
					 ////printf("Ua - ");
					 move_and_print_string("BBubuBUBUBuB");
				 }
		else if (get_color(9)  == 'O' && get_color(10) == 'G' && get_color(11) == 'O' && 
			     get_color(18) == 'G' && get_color(19) == 'R' && get_color(20) == 'G' && 
			     get_color(27) == 'R' && get_color(28) == 'O' && get_color(29) == 'R' && 
			     get_color(36) == 'B' && get_color(37) == 'B' && get_color(38) == 'B') 
			     { 
					 ////printf("Ua - ");
					 move_and_print_string("LLuluLULULuL");
				 }
		// Ub
		else if (get_color(9)  == 'O' && get_color(10) == 'B' && get_color(11) == 'O' && 
			     get_color(18) == 'G' && get_color(19) == 'G' && get_color(20) == 'G' && 
			     get_color(27) == 'R' && get_color(28) == 'O' && get_color(29) == 'R' && 
			     get_color(36) == 'B' && get_color(37) == 'R' && get_color(38) == 'B') 
			     { 
					 ////printf("Ub - ");
					 move_and_print_string("rUrururURURR");
				 }
		else if (get_color(9)  == 'O' && get_color(10) == 'O' && get_color(11) == 'O' && 
			     get_color(18) == 'G' && get_color(19) == 'B' && get_color(20) == 'G' && 
			     get_color(27) == 'R' && get_color(28) == 'G' && get_color(29) == 'R' && 
			     get_color(36) == 'B' && get_color(37) == 'R' && get_color(38) == 'B') 
			     { 
					 ////printf("Ub - ");
					 move_and_print_string("fUfufufUFUFF");
				 }
		else if (get_color(9)  == 'O' && get_color(10) == 'B' && get_color(11) == 'O' && 
			     get_color(18) == 'G' && get_color(19) == 'O' && get_color(20) == 'G' && 
			     get_color(27) == 'R' && get_color(28) == 'R' && get_color(29) == 'R' && 
			     get_color(36) == 'B' && get_color(37) == 'G' && get_color(38) == 'B') 
			     { 
					 ////printf("Ub - ");
					 move_and_print_string("bUbububUBUBB");
				 }
		else if (get_color(9)  == 'O' && get_color(10) == 'R' && get_color(11) == 'O' && 
			     get_color(18) == 'G' && get_color(19) == 'O' && get_color(20) == 'G' && 
			     get_color(27) == 'R' && get_color(28) == 'G' && get_color(29) == 'R' && 
			     get_color(36) == 'B' && get_color(37) == 'B' && get_color(38) == 'B') 
			     { 
					 ////printf("Ub - ");
					 move_and_print_string("lUlululULULL");
				 }
		// Z
		else if (get_color(9)  == 'O' && get_color(10) == 'B' && get_color(11) == 'O' && 
			     get_color(18) == 'G' && get_color(19) == 'R' && get_color(20) == 'G' && 
			     get_color(27) == 'R' && get_color(28) == 'G' && get_color(29) == 'R' && 
			     get_color(36) == 'B' && get_color(37) == 'O' && get_color(38) == 'B') 
			     { 
					 ////printf("Z - ");
					 move_and_print_string("ruRRURUruRURuRurUU");
				 }
		else if (get_color(9)  == 'O' && get_color(10) == 'G' && get_color(11) == 'O' && 
			     get_color(18) == 'G' && get_color(19) == 'O' && get_color(20) == 'G' && 
			     get_color(27) == 'R' && get_color(28) == 'B' && get_color(29) == 'R' && 
			     get_color(36) == 'B' && get_color(37) == 'R' && get_color(38) == 'B') 
			     { 
					 ////printf("Z - ");
					 move_and_print_string("fuFFUFUfuFUFuFufUU");	
				 }
		// Aa
		else if (get_color(9)  == 'B' && get_color(10) == 'O' && get_color(11) == 'O' && 
			     get_color(18) == 'G' && get_color(19) == 'G' && get_color(20) == 'B' && 
			     get_color(27) == 'O' && get_color(28) == 'R' && get_color(29) == 'G' && 
			     get_color(36) == 'R' && get_color(37) == 'B' && get_color(38) == 'R') 
			     { 
					 ////printf("Aa - ");
					 move_and_print_string("rFrBBRfrBBRR");	
				 }
		else if (get_color(9)  == 'O' && get_color(10) == 'O' && get_color(11) == 'R' && 
			     get_color(18) == 'B' && get_color(19) == 'G' && get_color(20) == 'O' && 
			     get_color(27) == 'G' && get_color(28) == 'R' && get_color(29) == 'G' && 
			     get_color(36) == 'R' && get_color(37) == 'B' && get_color(38) == 'B') 
			     { 
					 ////printf("Aa - ");
					 move_and_print_string("fLfRRFlfRRFF");	
				 }
		else if (get_color(9)  == 'B' && get_color(10) == 'O' && get_color(11) == 'B' && 
			     get_color(18) == 'O' && get_color(19) == 'G' && get_color(20) == 'G' && 
			     get_color(27) == 'R' && get_color(28) == 'R' && get_color(29) == 'O' && 
			     get_color(36) == 'G' && get_color(37) == 'B' && get_color(38) == 'R') 
			     { 
					 ////printf("Aa - ");
					 move_and_print_string("bRbLLBrbLLBB");	
				 }
		else if (get_color(9)  == 'R' && get_color(10) == 'O' && get_color(11) == 'B' && 
			     get_color(18) == 'O' && get_color(19) == 'G' && get_color(20) == 'O' && 
			     get_color(27) == 'G' && get_color(28) == 'R' && get_color(29) == 'R' && 
			     get_color(36) == 'B' && get_color(37) == 'B' && get_color(38) == 'G') 
			     { 
					 ////printf("Aa - ");
					 move_and_print_string("lBlFFLblFFLL");	
				 }
		// Ab
		else if (get_color(9)  == 'O' && get_color(10) == 'O' && get_color(11) == 'G' && 
			     get_color(18) == 'R' && get_color(19) == 'G' && get_color(20) == 'R' && 
			     get_color(27) == 'B' && get_color(28) == 'R' && get_color(29) == 'O' && 
			     get_color(36) == 'G' && get_color(37) == 'B' && get_color(38) == 'B') 
			     { 
					 ////printf("Ab - ");
					 move_and_print_string("RbRFFrBRFFRR");
				 }
		else if (get_color(9)  == 'G' && get_color(10) == 'O' && get_color(11) == 'G' && 
			     get_color(18) == 'R' && get_color(19) == 'G' && get_color(20) == 'B' && 
			     get_color(27) == 'O' && get_color(28) == 'R' && get_color(29) == 'R' && 
			     get_color(36) == 'B' && get_color(37) == 'B' && get_color(38) == 'O') 
			     { 
					 ////printf("Ab - ");
					 move_and_print_string("FrFLLfRFLLFF");	
				 }
		else if (get_color(9)  == 'R' && get_color(10) == 'O' && get_color(11) == 'O' && 
			     get_color(18) == 'G' && get_color(19) == 'G' && get_color(20) == 'R' && 
			     get_color(27) == 'B' && get_color(28) == 'R' && get_color(29) == 'B' && 
			     get_color(36) == 'O' && get_color(37) == 'B' && get_color(38) == 'G') 
			     { 
					 ////printf("Ab - ");
					 move_and_print_string("BlBRRbLBRRBB");	
				 }
		else if (get_color(9)  == 'G' && get_color(10) == 'O' && get_color(11) == 'R' && 
			     get_color(18) == 'B' && get_color(19) == 'G' && get_color(20) == 'G' && 
			     get_color(27) == 'R' && get_color(28) == 'R' && get_color(29) == 'B' && 
			     get_color(36) == 'O' && get_color(37) == 'B' && get_color(38) == 'O') 
			     {
					 ////printf("Ab - ");
					 move_and_print_string("LfLBBlFLBBLL");	
				 }
		// E
		else if (get_color(9)  == 'B' && get_color(10) == 'O' && get_color(11) == 'G' && 
			     get_color(18) == 'R' && get_color(19) == 'G' && get_color(20) == 'O' && 
			     get_color(27) == 'G' && get_color(28) == 'R' && get_color(29) == 'B' && 
			     get_color(36) == 'O' && get_color(37) == 'B' && get_color(38) == 'R') 
			     {
					 ////printf("E - ");
					 move_and_print_string("rUlDDLuRlUrDDRuL");
				 }
		else if (get_color(9)  == 'G' && get_color(10) == 'O' && get_color(11) == 'B' && 
			     get_color(18) == 'O' && get_color(19) == 'G' && get_color(20) == 'R' && 
			     get_color(27) == 'B' && get_color(28) == 'R' && get_color(29) == 'G' && 
			     get_color(36) == 'R' && get_color(37) == 'B' && get_color(38) == 'O') 
			     {
					 ////printf("E - ");
					 move_and_print_string("fUbDDBuFbUfDDFuB");
				 }
		// F
		else if (get_color(9)  == 'B' && get_color(10) == 'R' && get_color(11) == 'O' && 
			     get_color(18) == 'G' && get_color(19) == 'G' && get_color(20) == 'G' && 
			     get_color(27) == 'R' && get_color(28) == 'O' && get_color(29) == 'B' && 
			     get_color(36) == 'O' && get_color(37) == 'B' && get_color(38) == 'R') 
			     {
					 ////printf("F - ");
					 move_and_print_string("rURuRRfuFURFrfRRu");
				 }
		else if (get_color(9)  == 'O' && get_color(10) == 'O' && get_color(11) == 'O' && 
			     get_color(18) == 'G' && get_color(19) == 'B' && get_color(20) == 'R' && 
			     get_color(27) == 'B' && get_color(28) == 'R' && get_color(29) == 'G' && 
			     get_color(36) == 'R' && get_color(37) == 'G' && get_color(38) == 'B') 
			     {
					 ////printf("F - ");
					 move_and_print_string("fUFuFFluLUFLflFFu");
				 }
		else if (get_color(9)  == 'G' && get_color(10) == 'O' && get_color(11) == 'B' && 
			     get_color(18) == 'O' && get_color(19) == 'B' && get_color(20) == 'G' && 
			     get_color(27) == 'R' && get_color(28) == 'R' && get_color(29) == 'R' && 
			     get_color(36) == 'B' && get_color(37) == 'G' && get_color(38) == 'O') 
			     {
					 ////printf("F - ");
					 move_and_print_string("bUBuBBruRUBRbrBBu");
				 }
		else if (get_color(9)  == 'O' && get_color(10) == 'R' && get_color(11) == 'G' && 
			     get_color(18) == 'R' && get_color(19) == 'G' && get_color(20) == 'O' && 
			     get_color(27) == 'G' && get_color(28) == 'O' && get_color(29) == 'R' && 
			     get_color(36) == 'B' && get_color(37) == 'B' && get_color(38) == 'B') 
			     {
					 ////printf("F - ");
					 move_and_print_string("lULuLLbuBULBlbLLu");
				 }
		// Ga
		else if (get_color(9)  == 'O' && get_color(10) == 'B' && get_color(11) == 'G' && 
			     get_color(18) == 'R' && get_color(19) == 'G' && get_color(20) == 'R' && 
			     get_color(27) == 'B' && get_color(28) == 'O' && get_color(29) == 'O' && 
			     get_color(36) == 'G' && get_color(37) == 'R' && get_color(38) == 'B') 
			     {
					 ////printf("Ga - ");
					 move_and_print_string("RUrurUFRURurfUrUUR");
				 }
		else if (get_color(9)  == 'G' && get_color(10) == 'O' && get_color(11) == 'G' && 
			     get_color(18) == 'R' && get_color(19) == 'B' && get_color(20) == 'B' && 
			     get_color(27) == 'O' && get_color(28) == 'G' && get_color(29) == 'R' && 
			     get_color(36) == 'B' && get_color(37) == 'R' && get_color(38) == 'O') 
			     {
					 ////printf("Ga - ");
					 move_and_print_string("FUfufULFUFuflUfUUF");
				 }
		else if (get_color(9)  == 'R' && get_color(10) == 'B' && get_color(11) == 'O' && 
			     get_color(18) == 'G' && get_color(19) == 'O' && get_color(20) == 'R' && 
			     get_color(27) == 'B' && get_color(28) == 'R' && get_color(29) == 'B' && 
			     get_color(36) == 'O' && get_color(37) == 'G' && get_color(38) == 'G') 
			     {
					 ////printf("Ga - ");
					 move_and_print_string("BUbubURBUBubrUbUUB");
				 }
		else if (get_color(9)  == 'G' && get_color(10) == 'R' && get_color(11) == 'R' && 
			     get_color(18) == 'B' && get_color(19) == 'O' && get_color(20) == 'G' && 
			     get_color(27) == 'R' && get_color(28) == 'G' && get_color(29) == 'B' && 
			     get_color(36) == 'O' && get_color(37) == 'B' && get_color(38) == 'O') 
			     {
					 ////printf("Ga - ");
					 move_and_print_string("LUlulUBLULulbUlUUL");
				 }
		// Gb
		else if (get_color(9)  == 'G' && get_color(10) == 'B' && get_color(11) == 'G' && 
			     get_color(18) == 'R' && get_color(19) == 'O' && get_color(20) == 'B' && 
			     get_color(27) == 'O' && get_color(28) == 'R' && get_color(29) == 'R' && 
			     get_color(36) == 'B' && get_color(37) == 'G' && get_color(38) == 'O') 
			     {
					 ////printf("Gb - ");
					 move_and_print_string("ruRBBDlULuLdBB");
				 }
		else if (get_color(9)  == 'G' && get_color(10) == 'B' && get_color(11) == 'R' && 
			     get_color(18) == 'B' && get_color(19) == 'G' && get_color(20) == 'G' && 
			     get_color(27) == 'R' && get_color(28) == 'O' && get_color(29) == 'B' && 
			     get_color(36) == 'O' && get_color(37) == 'R' && get_color(38) == 'O') 
			     {
					 ////printf("Gb - ");
					 move_and_print_string("fuFRRDbUBuBdRR");	
				 }
		else if (get_color(9)  == 'O' && get_color(10) == 'R' && get_color(11) == 'G' && 
			     get_color(18) == 'R' && get_color(19) == 'O' && get_color(20) == 'R' && 
			     get_color(27) == 'B' && get_color(28) == 'G' && get_color(29) == 'O' && 
			     get_color(36) == 'G' && get_color(37) == 'B' && get_color(38) == 'B') 
			     {
					 ////printf("Gb - ");
					 move_and_print_string("buBLLDfUFuFdLL");	
				 }
		else if (get_color(9)  == 'R' && get_color(10) == 'O' && get_color(11) == 'O' && 
			     get_color(18) == 'G' && get_color(19) == 'B' && get_color(20) == 'R' && 
			     get_color(27) == 'B' && get_color(28) == 'G' && get_color(29) == 'B' && 
			     get_color(36) == 'O' && get_color(37) == 'R' && get_color(38) == 'G') 
			     {
					 ////printf("Gb - ");
					 move_and_print_string("luLFFDrURuRdFF");	
				 }
		// Gc
		else if (get_color(9)  == 'R' && get_color(10) == 'R' && get_color(11) == 'B' && 
			     get_color(18) == 'O' && get_color(19) == 'G' && get_color(20) == 'O' && 
			     get_color(27) == 'G' && get_color(28) == 'B' && get_color(29) == 'R' && 
			     get_color(36) == 'B' && get_color(37) == 'O' && get_color(38) == 'G') 
			     {
					 ////printf("Gc - ");
					 move_and_print_string("luLULuflulULFuLUUl");
				 }
		else if (get_color(9)  == 'B' && get_color(10) == 'O' && get_color(11) == 'B' && 
			     get_color(18) == 'O' && get_color(19) == 'R' && get_color(20) == 'G' && 
			     get_color(27) == 'R' && get_color(28) == 'B' && get_color(29) == 'O' && 
			     get_color(36) == 'G' && get_color(37) == 'G' && get_color(38) == 'R') 
			     {
					 ////printf("Gc - ");
					 move_and_print_string("buBUBulbubUBLuBUUb");	
				 }
		else if (get_color(9)  == 'O' && get_color(10) == 'G' && get_color(11) == 'R' && 
			     get_color(18) == 'B' && get_color(19) == 'B' && get_color(20) == 'O' && 
			     get_color(27) == 'G' && get_color(28) == 'R' && get_color(29) == 'G' && 
			     get_color(36) == 'R' && get_color(37) == 'O' && get_color(38) == 'B') 
			     {
					 ////printf("Gc - ");
					 move_and_print_string("fuFUFurfufUFRuFUUf");
				 }
		else if (get_color(9)  == 'B' && get_color(10) == 'G' && get_color(11) == 'O' && 
			     get_color(18) == 'G' && get_color(19) == 'R' && get_color(20) == 'B' && 
			     get_color(27) == 'O' && get_color(28) == 'O' && get_color(29) == 'G' && 
			     get_color(36) == 'R' && get_color(37) == 'B' && get_color(38) == 'R') 
			     {
					 ////printf("Gc - ");
					 move_and_print_string("ruRURubrurURBuRUUr");
				 }
		// Gd
		else if (get_color(9)  == 'R' && get_color(10) == 'R' && get_color(11) == 'O' && 
			     get_color(18) == 'G' && get_color(19) == 'O' && get_color(20) == 'R' && 
			     get_color(27) == 'B' && get_color(28) == 'G' && get_color(29) == 'B' && 
			     get_color(36) == 'O' && get_color(37) == 'B' && get_color(38) == 'G') 
			     {
					 ////printf("Gd - ");
					 move_and_print_string("RUUrUbruRURBUrurUR");
				 }
		else if (get_color(9)  == 'O' && get_color(10) == 'B' && get_color(11) == 'G' && 
			     get_color(18) == 'R' && get_color(19) == 'O' && get_color(20) == 'R' && 
			     get_color(27) == 'B' && get_color(28) == 'R' && get_color(29) == 'O' && 
			     get_color(36) == 'G' && get_color(37) == 'G' && get_color(38) == 'B') 
			     {
					 ////printf("Gd - ");
					 move_and_print_string("FUUfUrfuFUFRUfufUF");	
				 }
		else if (get_color(9)  == 'G' && get_color(10) == 'O' && get_color(11) == 'R' && 
			     get_color(18) == 'B' && get_color(19) == 'B' && get_color(20) == 'G' && 
			     get_color(27) == 'R' && get_color(28) == 'G' && get_color(29) == 'B' && 
			     get_color(36) == 'O' && get_color(37) == 'R' && get_color(38) == 'O') 
			     {
					 ////printf("Gd - ");
					 move_and_print_string("BUUbUlbuBUBLUbubUB");
				 }
		else if (get_color(9)  == 'G' && get_color(10) == 'B' && get_color(11) == 'G' && 
			     get_color(18) == 'R' && get_color(19) == 'G' && get_color(20) == 'B' && 
			     get_color(27) == 'O' && get_color(28) == 'O' && get_color(29) == 'R' && 
			     get_color(36) == 'B' && get_color(37) == 'R' && get_color(38) == 'O') 
			     {
					 ////printf("Gd - ");
					 move_and_print_string("LUUlUfluLULFUlulUL");
				 }
		// Ja
		else if (get_color(9)  == 'G' && get_color(10) == 'G' && get_color(11) == 'B' && 
			     get_color(18) == 'O' && get_color(19) == 'O' && get_color(20) == 'G' && 
			     get_color(27) == 'R' && get_color(28) == 'R' && get_color(29) == 'R' && 
			     get_color(36) == 'B' && get_color(37) == 'B' && get_color(38) == 'O') 
			     {
					 ////printf("Ja - ");
					 move_and_print_string("rlUULUlUURuLU");
				 }
		else if (get_color(9)  == 'B' && get_color(10) == 'B' && get_color(11) == 'O' && 
			     get_color(18) == 'G' && get_color(19) == 'G' && get_color(20) == 'G' && 
			     get_color(27) == 'R' && get_color(28) == 'R' && get_color(29) == 'B' && 
			     get_color(36) == 'O' && get_color(37) == 'O' && get_color(38) == 'R') 
			     {
					 ////printf("Ja - ");
					 move_and_print_string("fbUUBUbUUFuBU");	
				 }
		else if (get_color(9)  == 'O' && get_color(10) == 'O' && get_color(11) == 'G' && 
			     get_color(18) == 'R' && get_color(19) == 'R' && get_color(20) == 'O' && 
			     get_color(27) == 'G' && get_color(28) == 'G' && get_color(29) == 'R' && 
			     get_color(36) == 'B' && get_color(37) == 'B' && get_color(38) == 'B') 
			     {
					 ////printf("Ja - ");
					 move_and_print_string("bfUUFUfUUBuFU");
				 }
		else if (get_color(9)  == 'O' && get_color(10) == 'O' && get_color(11) == 'O' && 
			     get_color(18) == 'G' && get_color(19) == 'G' && get_color(20) == 'R' && 
			     get_color(27) == 'B' && get_color(28) == 'B' && get_color(29) == 'G' && 
			     get_color(36) == 'R' && get_color(37) == 'R' && get_color(38) == 'B') 
			     {
					 ////printf("Ja - ");
					 move_and_print_string("lrUURUrUULuRU");
				 }
		// Jb
		else if (get_color(9)  == 'O' && get_color(10) == 'O' && get_color(11) == 'O' && 
			     get_color(18) == 'G' && get_color(19) == 'R' && get_color(20) == 'R' && 
			     get_color(27) == 'B' && get_color(28) == 'G' && get_color(29) == 'G' && 
			     get_color(36) == 'R' && get_color(37) == 'B' && get_color(38) == 'B') 
			     {
					 ////printf("Jb - ");
					 move_and_print_string("RUrfRUrurFRRuru");
				 }
		else if (get_color(9)  == 'O' && get_color(10) == 'G' && get_color(11) == 'G' && 
			     get_color(18) == 'R' && get_color(19) == 'O' && get_color(20) == 'O' && 
			     get_color(27) == 'G' && get_color(28) == 'R' && get_color(29) == 'R' && 
			     get_color(36) == 'B' && get_color(37) == 'B' && get_color(38) == 'B') 
			     {
					 ////printf("Jb - ");
					 move_and_print_string("FUflFUfufLFFufu");	
				 }
		else if (get_color(9)  == 'G' && get_color(10) == 'B' && get_color(11) == 'B' && 
			     get_color(18) == 'O' && get_color(19) == 'G' && get_color(20) == 'G' && 
			     get_color(27) == 'R' && get_color(28) == 'R' && get_color(29) == 'R' && 
			     get_color(36) == 'B' && get_color(37) == 'O' && get_color(38) == 'O') 
			     {
					 ////printf("Jb - ");
					 move_and_print_string("LUlbLUlulBLLulu");
				 }
		else if (get_color(9)  == 'B' && get_color(10) == 'O' && get_color(11) == 'O' && 
			     get_color(18) == 'G' && get_color(19) == 'G' && get_color(20) == 'G' && 
			     get_color(27) == 'R' && get_color(28) == 'B' && get_color(29) == 'B' && 
			     get_color(36) == 'O' && get_color(37) == 'R' && get_color(38) == 'R') 
			     {
					 ////printf("Jb - ");
					 move_and_print_string("BUbrBUbubRBBubu");
				 }
		// Na
		else if (get_color(9)  == 'O' && get_color(10) == 'R' && get_color(11) == 'R' && 
			     get_color(18) == 'B' && get_color(19) == 'G' && get_color(20) == 'G' && 
			     get_color(27) == 'R' && get_color(28) == 'O' && get_color(29) == 'O' && 
			     get_color(36) == 'G' && get_color(37) == 'B' && get_color(38) == 'B') 
			     {
					 ////printf("Na - ");
					 move_and_print_string("fRUrurFRRFuruRUfr");
				 }
		else if (get_color(9)  == 'R' && get_color(10) == 'O' && get_color(11) == 'O' && 
			     get_color(18) == 'G' && get_color(19) == 'B' && get_color(20) == 'B' && 
			     get_color(27) == 'O' && get_color(28) == 'R' && get_color(29) == 'R' && 
			     get_color(36) == 'B' && get_color(37) == 'G' && get_color(38) == 'G') 
			     {
					 ////printf("Na - ");
					 move_and_print_string("lFUfufLFFLufuFUlf");
				 }
		// Nb
		else if (get_color(9)  == 'R' && get_color(10) == 'R' && get_color(11) == 'O' && 
			     get_color(18) == 'G' && get_color(19) == 'G' && get_color(20) == 'B' && 
			     get_color(27) == 'O' && get_color(28) == 'O' && get_color(29) == 'R' && 
			     get_color(36) == 'B' && get_color(37) == 'B' && get_color(38) == 'G') 
			     {
					 ////printf("Nb - ");
					 move_and_print_string("BruRURbRRbURUruBR");
				 }
		else if (get_color(9)  == 'O' && get_color(10) == 'O' && get_color(11) == 'R' && 
			     get_color(18) == 'B' && get_color(19) == 'B' && get_color(20) == 'G' && 
			     get_color(27) == 'R' && get_color(28) == 'R' && get_color(29) == 'O' && 
			     get_color(36) == 'G' && get_color(37) == 'G' && get_color(38) == 'b') 
			     {
					 ////printf("Nb - ");
					 move_and_print_string("RfuFUFrFFrUFUfuRF");
				 }
		// Ra
		else if (get_color(9)  == 'O' && get_color(10) == 'O' && get_color(11) == 'G' && 
			     get_color(18) == 'R' && get_color(19) == 'G' && get_color(20) == 'O' && 
			     get_color(27) == 'G' && get_color(28) == 'B' && get_color(29) == 'R' && 
			     get_color(36) == 'B' && get_color(37) == 'R' && get_color(38) == 'B') 
			     {
					 ////printf("Ra - ");
					 move_and_print_string("RUUrUURbruRURBRRU");
				 }
		else if (get_color(9)  == 'G' && get_color(10) == 'O' && get_color(11) == 'B' && 
			     get_color(18) == 'O' && get_color(19) == 'R' && get_color(20) == 'G' && 
			     get_color(27) == 'R' && get_color(28) == 'G' && get_color(29) == 'R' && 
			     get_color(36) == 'B' && get_color(37) == 'B' && get_color(38) == 'O') 
			     {
					 ////printf("Ra - ");
					 move_and_print_string("FUUfUUFrfuFUFRFFU");	
				 }
		else if (get_color(9)  == 'O' && get_color(10) == 'B' && get_color(11) == 'O' && 
			     get_color(18) == 'G' && get_color(19) == 'G' && get_color(20) == 'R' && 
			     get_color(27) == 'B' && get_color(28) == 'R' && get_color(29) == 'G' && 
			     get_color(36) == 'R' && get_color(37) == 'O' && get_color(38) == 'B') 
			     {
					 ////printf("Ra - ");
					 move_and_print_string("BUUbUUBlbuBUBLBBU");
				 }
		else if (get_color(9)  == 'B' && get_color(10) == 'G' && get_color(11) == 'O' && 
			     get_color(18) == 'G' && get_color(19) == 'O' && get_color(20) == 'G' && 
			     get_color(27) == 'R' && get_color(28) == 'R' && get_color(29) == 'B' && 
			     get_color(36) == 'O' && get_color(37) == 'B' && get_color(38) == 'R') 
			     {
					 ////printf("Ra - ");
					 move_and_print_string("LUUlUULfluLULFLLU");
				 }
		// Rb
		else if (get_color(9)  == 'B' && get_color(10) == 'O' && get_color(11) == 'O' && 
			     get_color(18) == 'G' && get_color(19) == 'R' && get_color(20) == 'G' && 
			     get_color(27) == 'R' && get_color(28) == 'G' && get_color(29) == 'B' && 
			     get_color(36) == 'O' && get_color(37) == 'B' && get_color(38) == 'R') 
			     {
					 ////printf("Rb - ");
					 move_and_print_string("rUURUUrFRUrurfRRu");
				 }
		else if (get_color(9)  == 'O' && get_color(10) == 'G' && get_color(11) == 'O' && 
			     get_color(18) == 'G' && get_color(19) == 'O' && get_color(20) == 'R' && 
			     get_color(27) == 'B' && get_color(28) == 'R' && get_color(29) == 'G' && 
			     get_color(36) == 'R' && get_color(37) == 'B' && get_color(38) == 'B') 
			     {
					 ////printf("Rb - ");
					 move_and_print_string("fUUFUUfLFUfuflFFu");	
				 }
		else if (get_color(9)  == 'G' && get_color(10) == 'O' && get_color(11) == 'B' && 
			     get_color(18) == 'O' && get_color(19) == 'G' && get_color(20) == 'G' && 
			     get_color(27) == 'R' && get_color(28) == 'B' && get_color(29) == 'R' && 
			     get_color(36) == 'B' && get_color(37) == 'R' && get_color(38) == 'O') 
			     {
					 ////printf("Rb - ");
					 move_and_print_string("bUUBUUbRBUbubrBBu");
				 }
		else if (get_color(9)  == 'O' && get_color(10) == 'B' && get_color(11) == 'G' && 
			     get_color(18) == 'R' && get_color(19) == 'G' && get_color(20) == 'O' && 
			     get_color(27) == 'G' && get_color(28) == 'R' && get_color(29) == 'R' && 
			     get_color(36) == 'B' && get_color(37) == 'O' && get_color(38) == 'B') 
			     {
					 ////printf("Rb - ");
					 move_and_print_string("lUULUUlBLUlulbLLu");
				 }
		// T
		else if (get_color(9)  == 'O' && get_color(10) == 'R' && get_color(11) == 'O' && 
			     get_color(18) == 'G' && get_color(19) == 'G' && get_color(20) == 'R' && 
			     get_color(27) == 'B' && get_color(28) == 'O' && get_color(29) == 'G' && 
			     get_color(36) == 'R' && get_color(37) == 'B' && get_color(38) == 'B') 
			     {
					 ////printf("T - ");
					 move_and_print_string("RUrurFRRuruRUrf");
				 }
		else if (get_color(9)  == 'O' && get_color(10) == 'O' && get_color(11) == 'G' && 
			     get_color(18) == 'R' && get_color(19) == 'B' && get_color(20) == 'O' && 
			     get_color(27) == 'G' && get_color(28) == 'R' && get_color(29) == 'R' && 
			     get_color(36) == 'B' && get_color(37) == 'G' && get_color(38) == 'B') 
			     {
					 ////printf("T - ");
					 move_and_print_string("FUfufLFFufuFUfl");	
				 }
		else if (get_color(9)  == 'B' && get_color(10) == 'O' && get_color(11) == 'O' && 
			     get_color(18) == 'G' && get_color(19) == 'B' && get_color(20) == 'G' && 
			     get_color(27) == 'R' && get_color(28) == 'R' && get_color(29) == 'B' && 
			     get_color(36) == 'O' && get_color(37) == 'G' && get_color(38) == 'R') 
			     {
					 ////printf("T - ");
					 move_and_print_string("BUbubRBBubuBUbr");
				 }
		else if (get_color(9)  == 'G' && get_color(10) == 'R' && get_color(11) == 'B' && 
			     get_color(18) == 'O' && get_color(19) == 'G' && get_color(20) == 'G' && 
			     get_color(27) == 'R' && get_color(28) == 'O' && get_color(29) == 'R' && 
			     get_color(36) == 'B' && get_color(37) == 'B' && get_color(38) == 'O') 
			     {
					 ////printf("T - ");
					 move_and_print_string("LUlulBLLuluLUlb");
				 }
		// V
		else if (get_color(9)  == 'R' && get_color(10) == 'O' && get_color(11) == 'O' && 
			     get_color(18) == 'G' && get_color(19) == 'G' && get_color(20) == 'B' && 
			     get_color(27) == 'O' && get_color(28) == 'B' && get_color(29) == 'R' && 
			     get_color(36) == 'B' && get_color(37) == 'R' && get_color(38) == 'G') 
			     {
					 ////printf("V - ");
					 move_and_print_string("rUrubrBBubUbRBR");
				 }
		else if (get_color(9)  == 'O' && get_color(10) == 'O' && get_color(11) == 'R' && 
			     get_color(18) == 'B' && get_color(19) == 'R' && get_color(20) == 'G' && 
			     get_color(27) == 'R' && get_color(28) == 'G' && get_color(29) == 'O' && 
			     get_color(36) == 'G' && get_color(37) == 'B' && get_color(38) == 'B') 
			     {
					 ////printf("V - ");
					 move_and_print_string("fUfurfRRurUrFRF");	
				 }
		else if (get_color(9)  == 'O' && get_color(10) == 'B' && get_color(11) == 'R' && 
			     get_color(18) == 'B' && get_color(19) == 'G' && get_color(20) == 'G' && 
			     get_color(27) == 'R' && get_color(28) == 'R' && get_color(29) == 'O' && 
			     get_color(36) == 'G' && get_color(37) == 'O' && get_color(38) == 'B') 
			     {
					 ////printf("V - ");
					 move_and_print_string("bUbulbLLulUlBLB");
				 }
		else if (get_color(9)  == 'R' && get_color(10) == 'G' && get_color(11) == 'O' && 
			     get_color(18) == 'G' && get_color(19) == 'O' && get_color(20) == 'B' && 
			     get_color(27) == 'O' && get_color(28) == 'R' && get_color(29) == 'R' && 
			     get_color(36) == 'B' && get_color(37) == 'B' && get_color(38) == 'G') 
			     {
					 ////printf("V - ");
					 move_and_print_string("lUluflFFufUfLFL");
				 }
		// Y
		else if (get_color(9)  == 'R' && get_color(10) == 'B' && get_color(11) == 'O' && 
			     get_color(18) == 'G' && get_color(19) == 'G' && get_color(20) == 'B' && 
			     get_color(27) == 'O' && get_color(28) == 'R' && get_color(29) == 'R' && 
			     get_color(36) == 'B' && get_color(37) == 'O' && get_color(38) == 'G') 
			     {
					 ////printf("V - ");
					 move_and_print_string("ruRuLRUUruRUUlURRUR");
				 }
		else if (get_color(9)  == 'O' && get_color(10) == 'O' && get_color(11) == 'R' && 
			     get_color(18) == 'B' && get_color(19) == 'G' && get_color(20) == 'G' && 
			     get_color(27) == 'R' && get_color(28) == 'B' && get_color(29) == 'O' && 
			     get_color(36) == 'G' && get_color(37) == 'R' && get_color(38) == 'B') 
			     {
					 ////printf("V - ");
					 move_and_print_string("fuFuBFUUfuFUUbUFFUF");	
				 }
		else if (get_color(9)  == 'O' && get_color(10) == 'G' && get_color(11) == 'R' && 
			     get_color(18) == 'B' && get_color(19) == 'O' && get_color(20) == 'G' && 
			     get_color(27) == 'R' && get_color(28) == 'R' && get_color(29) == 'O' && 
			     get_color(36) == 'G' && get_color(37) == 'B' && get_color(38) == 'B') 
			     {
					 ////printf("V - ");
					 move_and_print_string("buBuFBUUbuBUUfUBBUB");
				 }
		else if (get_color(9)  == 'R' && get_color(10) == 'O' && get_color(11) == 'O' && 
			     get_color(18) == 'G' && get_color(19) == 'R' && get_color(20) == 'B' && 
			     get_color(27) == 'O' && get_color(28) == 'G' && get_color(29) == 'R' && 
			     get_color(36) == 'B' && get_color(37) == 'B' && get_color(38) == 'G') 
			     {
					 ////printf("V - ");
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

int Algorithm::check_correct() {
	int correct = 1;
	
	for (int i=0; i<9; i++) {
		if (cube[i] != 'W')
			correct = 0;
	}
	for (int i=9; i<18; i++) {
		if (cube[i] != 'O')
			correct = 0;
	}
	for (int i=18; i<27; i++) {
		if (cube[i] != 'G')
			correct = 0;
	}
	for (int i=27; i<36; i++) {
		if (cube[i] != 'R')
			correct = 0;
	}
	for (int i=36; i<45; i++) {
		if (cube[i] != 'B')
			correct = 0;
	}
	for (int i=45; i<54; i++) {
		if (cube[i] != 'Y')
			correct = 0;
	}
	
	return correct;
}

void Algorithm::end_display() {
	int correct = check_correct();
	if (correct == 1) {
		//printf("\nCorrectly Solved");
		//printf("\nTotal Move Count: %d", final_moves_count);
		//printf("\nMoves to Solve: ");
		for (int i=0; i<final_moves_count; i++) {
			//printf("%c", final_moves[i]);
			//if ((i+1)%10 == 0) { //printf(" "); }
			//if ((i+1)%50 == 0) { //printf("\n                "); }
		}
		//printf("\n\n");
	} else {
		//printf("\nIncorrectly Solved");
	}
}

void Algorithm::scramble() {
	memset(scramble_seq, 0, 30);
	memset(final_moves, 0, 200);
	final_moves_count = 0;
	
	for (int i=0; i<50; i++) {
		int random_move = rand() % 12;
		switch (random_move) {
			case 0:
				U();
				scramble_seq[i] = 'U';
				break;
			case 1:
				Ui();
				scramble_seq[i] = 'u';
				break;
			case 2:
				D();
				scramble_seq[i] = 'D';
				break;
			case 3:
				Di();
				scramble_seq[i] = 'd';
				break;
			case 4:
				L();
				scramble_seq[i] = 'L';
				break;
			case 5:
				Li();
				scramble_seq[i] = 'l';
				break;
			case 6:
				R();
				scramble_seq[i] = 'R';
				break;
			case 7:
				Ri();
				scramble_seq[i] = 'r';
				break;
			case 8:
				F();
				scramble_seq[i] = 'F';
				break;
			case 9:
				Fi();
				scramble_seq[i] = 'f';
				break;
			case 10:
				B();
				scramble_seq[i] = 'B';
				break;
			case 11:
				Bi();
				scramble_seq[i] = 'b';
				break;
		}
	}
}

