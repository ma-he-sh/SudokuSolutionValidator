
/*
Idea of sudoku:

No column or row can have repeating numbers 
The numbers should go from 1-9
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

#define BUFFER_LEN 256
#define FILE_NAME "puzzle.txt"

#define MATRIX_SIZE 81 // size of sudoku
#define HEIGHT 9
#define WIDTH 9
#define SUB_HEIGHT 3
#define SUB_WIDTh 3

#define SUM 45

#define IGNORE 0

//open the file
int main(){

	FILE *fp;
	char *mode = "r";
	int num[HEIGHT][WIDTH];

	fp = fopen(FILE_NAME, mode);

	if(fp == NULL){
		fprintf(stderr, "UNABLE TO OPEN THE FILE \n");
		exit(1);
	}
	else{
		for(int col=0; col < HEIGHT; col++){
			for(int row=0; row < WIDTH; row++){
				fscanf(fp, "%d", &num[col][row]);
			}
		}
	}

	//print the sudoku matix
	for (int i=0; i<HEIGHT; i++){
		for(int j=0; j<WIDTH; j++){
			printf("%d ", num[i][j]);
		}
		printf("\n");
	}

}