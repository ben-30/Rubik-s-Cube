#include "Algorithm.cpp"

int main() {
	//std::string OWEN = "YGYWWRWOYBOOWOYGGRGBBGGGYRWRWGRRBOOBOWOYBBRRRGYBOYYWBW";
	std::string OWEN = "OBRWWORGBBGGWOWGBOYYWBGWYRRRYWOROBRGGRWBBRYOWBGYYYYOGO";
	Algorithm a(OWEN);
	a.solve();

	int original = a.final_moves_count;

	printf("\nFinal Count: %d", a.final_moves_count);
	printf("\nMoves to Solve: ");
	std::string ERIC(a.final_moves);
	for (int i=0; i<a.original_count; i++) { printf("%c", ERIC[i]); }
	printf("\n");
	
	a.reverse_moves();
	printf("\nRemove Reverse Moves! --> Final Count: %d", a.final_moves_count);
	printf("\nMoves to Solve: ");
	std::string ERIC_2(a.final_moves);
	for (int i=0; i<a.original_count; i++) {	printf("%c", ERIC_2[i]); }
	printf("\n");
	
	a.double_moves();
	printf("\nRemove Double Moves! -->  Final Count: %d", a.final_moves_count);
	printf("\nMoves to Solve: ");
	std::string ERIC_3(a.final_moves);
	for (int i=0; i<a.original_count; i++) {	printf("%c", ERIC_3[i]); }
	printf("\n");

	return 0;
}
