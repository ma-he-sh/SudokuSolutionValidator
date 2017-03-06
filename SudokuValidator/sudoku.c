
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

struct validate{
	int ROW;
	int COL;
	int (*matrix)[WIDTH];
};


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
	printf("CURRENTLY SOLVING --");
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

	void * checkrow, * checkcol, 
		 * sq3x3_1, * sq3x3_2, * sq3x3_3, 
		 * sq3x3_4, * sq3x3_5, * sq3x3_6,
		 * sq3x3_7, * sq3x3_8, * sq3x3_9;

	pthread_t t_row, t_col, 
			  t_check1, t_check2, t_check_3, 
			  t_check4, t_check5, t_check_6,
			  t_check7, t_chech8, t_check_9;

	

	//create the pthreads
	//pthread_create(t_row, NULL, checkRows, )
}

//check rows for 1-9
void checkRows(int data[][]){
	for (int i=s_row; i < HEIGHT; i++){
		int row[10] = {0};

		for(int j = s_col; j < WIDTH; j++){
			int cell = data[i][j];
			if(row[cell] != 0){
				return 0;
			}
			else{
				row[cell] = 1;
			}
		} 
	}
	return 1;
}

//check columns for 1-9
void checkCols(int data[][]){
	for (int i=s_col; i < WIDTH; i++){
		int col[10] = {0};

		for(int j = s_row; j < HEIGHT; j++){
			int cell = data[i][j];
			if(col[cell] != 0){
				return 0;
			}
			else{
				col[cell] = 1;
			}
		} 
	}
	return 1;
}

//check sub matrix
void checkCols(int data[][]){
	for (int i=s_row; i < s_row+3; i++){
		int subm[10] = {0};

		for(int j = s_col; j < s_col+3; j++){
			int cell = data[i][j];
			if(subm[cell] != 0){
				return 0;
			}
			else{
				subm[cell] = 1;
			}
		} 
	}
	return 1;
}