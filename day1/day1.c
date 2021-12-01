#include <stdio.h>
#include <stdlib.h>

int _SIZE = 2000;

int greater_count(int* arr)
{
	int i, count, last ;
	int three[3] = { 0, 0, 0 };
	count = 0, last = 0;
	for (i = 0; i < _SIZE; i++)
	{
		three[i % 3] = arr[i];
	//	printf("a1= %d a2= %d a3= %d\n", three[0], three[1], three[2]);
 		if (three[0] + three[1] + three[2] > last) count++;
		last = three[0] + three[1] + three[2];
		//printf("New Last = %d\n", last);
	}
	printf("Returning\n");
	return count - 3; // accounts for first three checks.
}


void makeArray(char *path, int *numberArray)
{
	_SIZE = 2000;
	FILE *myFile;
	myFile = fopen(path, "r");
	
	//read file into array
	//int numberArray[100];
	int i;
	
	if (myFile == NULL){
		printf("Error Reading File\n");
		exit (0);
	}
	
	for (i = 0; i < _SIZE; i++){
		fscanf(myFile, "%d,", &numberArray[i] );
	}
	
	for (i = 0; i < _SIZE; i++){
		printf("Number is: %d\n\n", numberArray[i]);
	}
	
	fclose(myFile);
	//return numberArray;
}


int main() {
	int arr[2000];
	int s;
	makeArray("day1.txt", arr);
	s = greater_count(arr);
	printf("Count is %d \n", s);
	return 0;
}