#include "Algorithm.cpp"
//g++ Average.cpp -o Average -std=c++11

int main() {
	srand( time(NULL) );
	Algorithm cube("WWWWWWWWWOOOOOOOOOGGGGGGGGGRRRRRRRRRBBBBBBBBBYYYYYYYYY");
	
	float move_sum = 0.0;
	int num_trials = 100000;
	int correct = 1;
	
	int min_moves = 0;
	int max_moves = 200;
	
	int one = 0;      // 31-35
	int two = 0;      // 36-40
	int three = 0;    // 41-45
	int four = 0;     // 46-50
	int five = 0;     // 51-55
	int six = 0;      // 56-60
	int seven = 0;    // 61-65
	int eight = 0;    // 66-70
	int nine = 0;     // 71-75
	int ten = 0;      // 76-80
	int eleven = 0;   // 81-85
	int twelve = 0;   // 86-90
	int thirteen = 0; // 91-95
	int fourteen = 0; // 96-100
	
	for (int i=0; i<num_trials; i++) {
		cube.scramble();
		printf("Moves to Scramble: ");
		for (int i=0; i<50; i++) { printf("%c", cube.scramble_seq[i]); }                  // scramble sequence
		printf("\n");
		
		for (int i=0; i<54; i++) { printf("%c", cube.cube[i]); }                          // scrambled cube
		printf(" --> ");
		
		cube.solve();
		cube.reverse_moves();
		cube.double_moves();
		
		for (int i=0; i<54; i++) { printf("%c", cube.cube[i]); }                          // solved cube
		
		move_sum += cube.final_moves_count;
		if (cube.final_moves_count > min_moves) { min_moves = cube.final_moves_count; }
		if (cube.final_moves_count < max_moves) { max_moves = cube.final_moves_count; }
		printf(": %d\n", cube.final_moves_count);                                         // final move count
		
		printf("Moves to Solve: ");
		for (int i=0; i<cube.original_count; i++) { printf("%c", cube.final_moves[i]); }  // solve sequence
		printf("\n\n");
		
		if (cube.final_moves_count >= 31 && cube.final_moves_count <= 35) {
			one++;
		} else if (cube.final_moves_count >= 36 && cube.final_moves_count <= 40) {
			two++;
		} else if (cube.final_moves_count >= 41 && cube.final_moves_count <= 45) {
			three++;
		} else if (cube.final_moves_count >= 46 && cube.final_moves_count <= 50) {
			four++;
		} else if (cube.final_moves_count >= 51 && cube.final_moves_count <= 55) {
			five++;
		} else if (cube.final_moves_count >= 56 && cube.final_moves_count <= 60) {
			six++;
		} else if (cube.final_moves_count >= 61 && cube.final_moves_count <= 65) {
			seven++;
		} else if (cube.final_moves_count >= 66 && cube.final_moves_count <= 70) {
			eight++;
		} else if (cube.final_moves_count >= 71 && cube.final_moves_count <= 75) {
			nine++;
		} else if (cube.final_moves_count >= 76 && cube.final_moves_count <= 80) {
			ten++;
		} else if (cube.final_moves_count >= 81 && cube.final_moves_count <= 85) {
			eleven++;
		} else if (cube.final_moves_count >= 86 && cube.final_moves_count <= 90) {
			twelve++;
		} else if (cube.final_moves_count >= 91 && cube.final_moves_count <= 95) {
			thirteen++;
		} else if (cube.final_moves_count >= 96 && cube.final_moves_count <= 100) {
			fourteen++;
		}
		
		if (cube.check_correct() != 1) { correct = 0; }
	}
	
	float move_average = move_sum / num_trials;
	printf("Average Number of Moves for %d Trials: %f", num_trials, move_average);
	printf("\nMinimum Number of Moves: %d", min_moves);
	printf("\nMaximum Number of Moves: %d", max_moves);
	
	printf("\n\n| 31-35 | 36-40 | 41-45 | 46-50 | 51-55 | 56-60 | 61-65 | 66-70 | 71-75 | 76-80 | 81-85 | 86-90 | 91-95 | 96-100 |");
	printf("\n| %d | %d | %d | %d | %d | %d | %d | %d | %d | %d | %d | %d | %d | %d |",
	       one, two, three, four, five, six, seven, eight, nine, ten, eleven, twelve, thirteen, fourteen);
	
	if (correct == 1) { printf("\n\nAll Correct\n\n"); }
	else { printf("\n\nERROR\n\n"); }

	return 0;
}
