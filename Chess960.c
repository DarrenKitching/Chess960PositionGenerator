#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void placeBlackBishop (char position[]) {
	int random = (rand() % 4) +1;	
	switch (random) {
		case 1:
			position[0] = 'B';
			break;
		case 2:
			position[2] = 'B';
			break;
		case 3:
			position[4] = 'B';
			break;
		case 4:
			position[6] = 'B';
			break;
		default:
			printf("Mistake in program");
			break;
	}
}

void placeWhiteBishop (char position[]) {
	int random = (rand() % 4) +1;	
	switch (random) {
		case 1:
			position[1] = 'B';
			break;
		case 2:
			position[3] = 'B';
			break;
		case 3:
			position[5] = 'B';
			break;
		case 4:
			position[7] = 'B';
			break;
		default:
			printf("Mistake in program");
			break;
	}
}

void placeQueen (char position[]) {
	int random = (rand() % 6) +1;
	int empty = 0;
	for (int i = 0; i < 8; i++) {
		if (empty == random - 1) {
			if (position[i] == '0') {
				position[i] = 'Q';
				break;
			}
		}
		else if (position[i] == '0') {
			empty++;
		}
	}
}

void placeFirstKnight (char position[]) {
	int random = (rand() % 5) +1;
	int empty = 0;
	for (int i = 0; i < 8; i++) {
		if (empty == random - 1) {
			if (position[i] == '0') {
				position[i] = 'N';
				break;
			}
		}
		else if (position[i] == '0') {
			empty++;
		}
	}
	
}

void placeSecondKnight (char position[]) {
	int random = (rand() % 4) +1;
	int empty = 0;
	for (int i = 0; i < 8; i++) {
		if (empty == random - 1) {
			if (position[i] == '0') {
				position[i] = 'N';
				break;
			}
		}
		else if (position[i] == '0') {
			empty++;
		}
	}
}

void placeRooksAndKing (char position[]) {
	int emptySquare = 0;
	for (int i = 0; i < 8; i++) {
		if (position[i] == '0') {
			if (emptySquare == 0) {
				position[i] = 'R';
				emptySquare++;
			}
			else if (emptySquare == 1) {
				position[i] = 'K';
				emptySquare++;
			}
			else if (emptySquare == 2) {
				position[i] = 'R';
				emptySquare++;
			}
		}
	}
}

int main () {
	FILE * file;
	srand ( time(NULL) );
	char positions[960][8];
	int numberOfPositions = 0;
	int found = 0;
	char * str = "output.txt";
	file = fopen(str, "w");
	while (numberOfPositions < 960) {
		found = 0;
		char position[8];
		for (int i = 0; i < 8; i++)
			position[i] = '0';
		
		placeBlackBishop(position);
		//printf("%s\n", position);
		placeWhiteBishop(position);
		//printf("%s\n", position);
		placeQueen(position);
		//printf("%s\n", position);
		placeFirstKnight(position);
		//printf("%s\n", position);
		placeSecondKnight(position);
		//printf("%s\n", position);
		placeRooksAndKing(position);
		
		for (int i = 0; i < numberOfPositions; i++) {
			for (int j = 0; j < 8; j++) {
				if (position[j] != positions[i][j])
					break;
				else if (j == 7) {
					found = 1;
				}
			}
		}
		
		if (found == 0) {
			for (int i = 0; i < 8; i++) {
				positions[numberOfPositions][i] = position[i];
			}
			printf("%s%d%s%s\n", "Position number: ", numberOfPositions + 1, " Board: ", position);
			fprintf(file, "%s%d%s%s\n", "Position number: ", numberOfPositions + 1, " Board: ", position);
			numberOfPositions++;
		}
	}
	fclose(file);
}