#include <stdio.h>
#include <stdlib.h>
//AUTHOR ap-em 12/31/21
int _SIZE = 2000;

int main() {
	FILE *myFile;
	myFile = fopen("day5.txt", "r");
	if (myFile == NULL){
		printf("Error Reading File\n");
		exit (0);
	}

	int *val = malloc(4*sizeof(int));


	int (*map)[1000]; 
	map = calloc(1000, sizeof(*map)); //calloc to init map to 0

	int dx, dy, i, j, delta, count, neg, negx, negy, sum;
	dx = 0, dy = 0, delta = 0, j = 0;
	
	while (fscanf(myFile, "%d, %d -> %d, %d", &val[0], &val[1], &val[2], &val[3]) > 0)
	{
		printf("%d, %d -> %d, %d\n", val[0], val[1], val[2], val[3]);
		if (val[0] == val[2] || val[1] == val[3]) // if strictly vertical or hz
		{
			neg = 0;
			dx = val[2] - val[0];
			dy = val[3] - val[1];
			if (dx == 0) delta = dy;
			else delta = dx;

			if (delta < 0) 
			{
				delta = -delta;
				neg = 1;
			}

			printf("dx: %d dy: %d\n", dx, dy);
			for (i = 0; i <= delta; i++)
			{
				if (dx != 0)
				{
					if (!neg) map[val[1]][val[0] + i]++; // y,x grid
					else map[val[1]][val[0] - i]++;
						
				}
				else if (dy != 0)
				{
					if (!neg) map[val[1] + i][val[0]]++;
					else map[val[1] - i][val[0]]++;
					
				}
			}
		} else { // if diagonal
			negx = 0, negy = 0;
			dx = val[2] - val[0];
			dy = val[3] - val[1];
			if (dx < 0)
			{
				negx = 1;
				dx = -dx;
			}
			if (dy < 0) 
			{
				negy = 1;
				dy = -dy;
			}
			sum = dx + dy;
			for (i = 0; i <= dx; i++)
			{
				if (!negx && !negy) map[val[1]+i][val[0] + i]++; 
				else if (!negx && negy) map[val[1]-i][val[0] + i]++;
				else if (negx && !negy) map[val[1]+i][val[0] - i]++;
				else if (negx && negy) map[val[1]-i][val[0] - i]++;
				
				//else map[val[1]][val[0] - i]++;
			}
		}
	}
	count = 0;
	// Counts overlapping spots
	for (i = 0; i < 1000; i++) {
		for (j = 0; j < 1000; j++) 
		{
		//	printf("%d ", map[i][j]);
			if (map[i][j] >= 2) count++; 
		}
		//printf("\n");
	}
	
	printf("Final count is: %d\n", count);
	free(val);
	free(map);
	fclose(myFile);
	return 0;
}