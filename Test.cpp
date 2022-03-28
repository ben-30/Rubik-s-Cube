#include "Algorithm.cpp"

int main() {
	std::string OWEN = "GYWBWGROYYRGYOWGYYYGOGGWRWWBROBROOORGROBBGWWRBRBBYYWOB";
	Algorithm a(OWEN);

	printf("Final Count: %d", a.final_moves_count);
	printf("\nMoves to Solve: ");
	std::string ERIC(a.final_moves);
	for (int i=0; i<a.final_moves_count; i++) {
		printf("%c", ERIC[i]);
		if ((i+1)%10 == 0) { printf(" "); }
		if ((i+1)%50 == 0) { printf("\n                "); }
	}
	printf("\n");

	return 0;
}