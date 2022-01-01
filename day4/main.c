#include <stdio.h>
#include <stdlib.h>

// AUTHOR: ap-em 12/30/21
int _SIZE = 2000;

int checkRows(int boards[5][5])
{
	int i;
	for (i = 0; i < 4; i++)
	{
		if (boards[i][0] < 0 && boards[i][1] < 0 && boards[i][2] < 0 && boards[i][3] < 0 && boards[i][4] < 0) return 1;
	}
	return 0;
}

int checkColumns(int boards[5][5])
{
	int i;
	for (i = 0; i < 4; i++)
	{
		if (boards[0][i] < 0 && boards[1][i] < 0 && boards[2][i] < 0 && boards[3][i] < 0 && boards[4][i] < 0) return 1;
	}
	return 0;
}

int checkBingo(int boards[5][5])
{
	int i, j, bingo, bingo2;
	bingo = 0;

	if (boards[0][0] < 0 && boards[1][1] < 0 && boards[2][2] < 0 && boards[3][3] < 0 && boards[4][4] < 0) bingo = 1;
	else if (boards[4][0] < 0 && boards[3][1] < 0 && boards[2][2] < 0 && boards[1][3] < 0 && boards[0][4] < 0) bingo = 1;
	else 
	{
		bingo = checkRows(boards);
		bingo2  = checkColumns(boards);
		
	}
	return bingo || bingo2;

}

void printBoard(int boards[5][5]) 
{
	int a, b;
	for (a = 0; a < 5; a++) {
		for (b= 0; b < 5; b++) {
			printf("%d ", boards[a][b]);
		}
		printf("\n");
	}
}

int checkBoard(int boards[100][5][5], int val, int *won)
{
	int i, j, k, bingo, a, b;
	i = 0, j = 0, k = 0, bingo = 0;

	for (i = 0; i < 100; i++) {
		//printf("Board %d:\n", i);
		for (j = 0; j < 5; j++) {
			for (k = 0; k < 5; k++) {
				if (boards[i][j][k] == val)
				{
					boards[i][j][k] = -boards[i][j][k];
					if (boards[i][j][k] == 0) boards[i][j][k] = -99; //arbitrary val
					if (won[i] == 0) bingo = checkBingo(boards[i]);
					if (bingo)
					{
						printf("FIRST BINGO AT BOARD %d AND VAL %d\n", i, val);
						won[i] = 1;
						printBoard(boards[i]);
					}
					bingo = 0; //Reset value
				}
				//printf("%d ", boards[i][j][k]);
			}
		//	printf("\n");
		}
	}
	return bingo;
}

int main() {
	FILE *myFile;
	myFile = fopen("day4.txt", "r");
	if (myFile == NULL){
		printf("Error Reading File\n");
		exit (0);
	}

	int i, j, bingo, val;
	int board[100][5][5];
	int *order = malloc(100*sizeof(int));

	for (i = 0; i < 100; i++)
	{
		fscanf(myFile, "%d,", &order[i]);
		printf("Val %d: %d\n", i, order[i]);
	}
	// Read + prints 5x5 grids
	for (i = 0; i < 100; i++) {
		printf("Board #%d: \n", i);
		for (j = 0; j < 5; j++) {

			fscanf(myFile, "%d %d %d %d %d", &board[i][j][0], &board[i][j][1], &board[i][j][2], &board[i][j][3], &board[i][j][4]);
			printf("%d %d %d %d %d\n", board[i][j][0], board[i][j][1], board[i][j][2], board[i][j][3], board[i][j][4]);
		}
	}
	bingo = 0, val = 0;
	int *won = malloc(100*sizeof(int));
	for (i = 0; i < 100; i++)
	{
		// array of won boards
		val = order[i];
		bingo = checkBoard(board, val, won);
	}

	fclose(myFile);
	return 0;
}