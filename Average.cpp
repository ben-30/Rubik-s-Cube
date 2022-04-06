#include "Algorithm.cpp"
//g++ Average.cpp -o Average -std=c++11

int main() {
	srand( time(NULL) );
	Algorithm cube("WWWWWWWWWOOOOOOOOOGGGGGGGGGRRRRRRRRRBBBBBBBBBYYYYYYYYY");
	
	float move_sum = 0.0;
	int num_trials = 1000;
	int correct = 1;
	
	for (int i=0; i<num_trials; i++) {
		cube.scramble();
		for (int i=0; i<54; i++) { printf("%c", cube.cube[i]); }
		printf(" --> ");
		
		cube.solve();
		cube.reverse_moves();
		cube.double_moves();
		for (int i=0; i<54; i++) { printf("%c", cube.cube[i]); }
		
		move_sum += cube.final_moves_count;
		printf(": %d", cube.final_moves_count);
		printf("\n");
		
		if (cube.check_correct() != 1) { correct = 0; }
	}
	
	float move_average = move_sum / num_trials;
	printf("\nAverage Number of Moves for %d Trials: %f\n", num_trials, move_average);
	if (correct == 1) { printf("All Correct\n\n"); }
	else { printf("ERROR\n\n"); }

	return 0;
}
