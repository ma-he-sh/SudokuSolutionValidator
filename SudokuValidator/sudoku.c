
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

typedef struct{
	int ROW;
	int COL;
	int (*matrix)[WIDTH];
} validate;

void *checkRows(void *validate){
	return (void*)5;
}

void *checkCols(void *validate){
	return (void*)1;
}

void *checkMatrix(void *validate){
	return (void*)1;
}


//open the file 
int main(){

	FILE *fp;
	char *mode = "r";
	int matrix[HEIGHT][WIDTH];

	fp = fopen(FILE_NAME, mode);

	if(fp == NULL){
		fprintf(stderr, "UNABLE TO OPEN THE FILE \n");
		exit(1);
	}
	else{
		for(int col=0; col < HEIGHT; col++){
			for(int row=0; row < WIDTH; row++){
				fscanf(fp, "%d", &matrix[col][row]);
			}
		}
	}
	fclose(fp);

	//display sudoku matrix
	printf("CURRENTLY SOLVING --\n");
	//print the sudoku matix
	for (int i=0; i<HEIGHT; i++){
		for(int j=0; j<WIDTH; j++){
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	validate *check0 = (validate *) malloc(sizeof(validate));
	check0->ROW = 0;
	check0->COL = 0;
	check0->matrix = matrix;

	//check 1st sub matrix
	validate *check1 = (validate *) malloc(sizeof(validate));
	check1->ROW = 0;
	check1->COL = 0;
	check1->matrix = matrix;

	//check 2st sub matrix
	validate *check2 = (validate *) malloc(sizeof(validate));
	check2->ROW = 0;
	check2->COL = 3;
	check2->matrix = matrix;

	//check 3rd sub matrix
	validate *check3 = (validate *) malloc(sizeof(validate));
	check3->ROW = 0;
	check3->COL = 6;
	check3->matrix = matrix;

	//check 4rth sub matrix
	validate *check4 = (validate *) malloc(sizeof(validate));
	check4->ROW = 3;
	check4->COL = 0;
	check4->matrix = matrix;

	//check 5th sub matrix
	validate *check5 = (validate *) malloc(sizeof(validate));
	check5->ROW = 3;
	check5->COL = 3;
	check5->matrix = matrix;

	//check 6th sub matrix
	validate *check6 = (validate *) malloc(sizeof(validate));
	check6->ROW = 3;
	check6->COL = 6;
	check6->matrix = matrix;

	//check 7th sub matrix
	validate *check7 = (validate *) malloc(sizeof(validate));
	check7->ROW = 6;
	check7->COL = 0;
	check7->matrix = matrix;

	//check 8th sub matrix
	validate *check8 = (validate *) malloc(sizeof(validate));
	check8->ROW = 6;
	check8->COL = 3;
	check8->matrix = matrix;

	//check 9th sub matrix
	validate *check9 = (validate *) malloc(sizeof(validate));
	check9->ROW = 6;
	check9->COL = 6;
	check9->matrix = matrix;

	pthread_t t_row, t_col, 
			  t_check1, t_check2, t_check3, 
			  t_check4, t_check5, t_check6,
			  t_check7, t_check8, t_check9;
	
	//Result pointers
	void *res_rows, *res_cols,
			  *res_m1, *res_m2, *res_m3, *res_m4,
			  *res_m5, *res_m6, *res_m7, *res_m8,
			  *res_m9;

	//Start the threads
	pthread_create(&t_row, NULL, checkRows, (void *)check0);
	pthread_create(&t_col, NULL, checkCols, (void *)check0);
	pthread_create(&t_check1, NULL, checkMatrix, (void *)check1);
	pthread_create(&t_check2, NULL, checkMatrix, (void *)check2);
	pthread_create(&t_check3, NULL, checkMatrix, (void *)check3);
	pthread_create(&t_check4, NULL, checkMatrix, (void *)check4);
	pthread_create(&t_check5, NULL, checkMatrix, (void *)check5);
	pthread_create(&t_check6, NULL, checkMatrix, (void *)check6);
	pthread_create(&t_check7, NULL, checkMatrix, (void *)check7);
	pthread_create(&t_check8, NULL, checkMatrix, (void *)check8);
	pthread_create(&t_check9, NULL, checkMatrix, (void *)check9);
	
	//Wait for the threads
	pthread_join(t_row, &res_rows);
	pthread_join(t_col, &res_cols);
	pthread_join(t_check1, &res_m1);
	pthread_join(t_check2, &res_m2);
	pthread_join(t_check3, &res_m3);
	pthread_join(t_check4, &res_m4);
	pthread_join(t_check5, &res_m5);
	pthread_join(t_check6, &res_m6);
	pthread_join(t_check7, &res_m7);
	pthread_join(t_check8, &res_m8);
	pthread_join(t_check9, &res_m9);

	//Check all the threads passed
	printf("Validation finished.\n");
	if((int)res_rows == 1 && (int)res_cols == 1 &&
		(int)res_m1 == 1 && (int)res_m2 == 1 && (int)res_m3 == 1 &&
		(int)res_m4 == 1 && (int)res_m5 == 1 && (int)res_m6 == 1 &&
		(int)res_m7 == 1 && (int)res_m8 == 1 && (int)res_m9 == 1){
		printf("The puzzle is solved.\n");
	}
	else {
		printf("The puzzle is not solved.\n");
	}
}
