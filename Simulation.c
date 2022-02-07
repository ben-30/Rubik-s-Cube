//On PC

#include <stdio.h>

//void display(char[]);
void display();
void reset();
//void initialize(char *, int);

char cube[54] = {'W','W','W','W','W','W','W','W','W',
		     	 'O','O','O','O','O','O','O','O','O',
		         'G','G','G','G','G','G','G','G','G',
                 'R','R','R','R','R','R','R','R','R',
		     	 'B','B','B','B','B','B','B','B','B',
		     	 'Y','Y','Y','Y','Y','Y','Y','Y','Y'};

int main() {
	//char *cube;
	//cube = NULL;
	
	display();
	cube[0] = 'P';
	display();
	reset();
	display();
}

void display() {
	/*printf("\nColors!\n");
	printf("W = White\n");
	printf("O = Orange\n");
	printf("G = Green\n");
	printf("R = Red\n");
	printf("B = Blue\n");
	printf("Y = Yellow\n");*/
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

/*void U(char **cube)
{
	char temp[54] = *cube;
	
	/*for (int i = 0 ; i < 54 ; i++)
        (*cube)[i] = 1;
}*/

