#include <stdio.h>
#include <stdlib.h>

int _SIZE = 2000;
int main() {
	char *arr = malloc(_SIZE* sizeof(char));
	int s;
	FILE *myFile;
	myFile = fopen("day2.txt", "r");
	if (myFile == NULL){
		printf("Error Reading File\n");
		exit (0);
	}
	char line [20];
	int val, x, y, aim;
	x = 0, y = 0, aim = 0;
	printf("X = %d    Y = %d \n", x, y);
	while (fscanf(myFile, "%s %d", &line, &val) > 0)
	{
		printf("String: %10s Value: %d\n", line, val);

		if (strcmp(line, "forward") == 0)
		{
			x += val;
			y += (aim * val);
		}
		else if (strcmp(line, "up") == 0)
		{
			//y -= val;
			aim -= val;
		}
		else if (strcmp(line, "down") == 0)
		{
			//y += val;
			aim += val;
		}
		else
		{
			printf("ERROR: UNKNOWN CASE %s", line);
			break;
		}
	
		printf("X = %d    Y = %d \n", x, y);
	}
	//printf("X = %d    Y = %d \n", x, y);
	printf("Answer to part 2: %d", (x * y));
	fclose(myFile);
	return 0;
}