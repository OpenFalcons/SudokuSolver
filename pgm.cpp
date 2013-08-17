/*
 * pgm.cpp
 *
 *  Created on: Jan 23, 2012
 *      Author: muthu
 */

#define    PAUSE(X)  printf("At %s,press any char to continue",X);\
					 getchar();

#include "SudokuSolver.h"
#include "stdio.h"



void printArray(int [9][9]);

int main(){
	int arr[9][9] =
	{		//sample input su-do-ku.
			{	3,0,0, 0,0,1, 0,0,5, },
			{	6,0,8, 0,2,3, 9,7,1, },
			{	9,0,0, 0,7,0, 0,3,0, },

			{	0,0,0, 2,0,0, 0,1,0, },
			{	0,0,9, 0,0,0, 2,0,0, },
			{	0,8,0, 0,0,6, 0,0,0, },

 			{	0,7,0, 0,3,0, 0,0,9, },
			{	8,9,3, 7,4,0, 1,0,2, },
			{	4,0,0, 6,0,0, 0,0,7  },
	};



	Matrix sudProblem;

	if(!sudProblem.setMatrix(arr))
		printf("All clear");
	else printf("There exists error");


	SudokuSolver sudoSolver(sudProblem);



	int ans[9][9];
    while(sudoSolver.hasMoreSolution()){

    	 Matrix tempAns = sudoSolver.nextSolution();

    	 tempAns.MatrixToArray(ans);
    	 printArray(ans);

    	 PAUSE("mid");
    }

    return EXIT_SUCCESS;
}

void printArray(int temp[9][9]){

	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++)
			printf("%d\t",temp[i][j]);
     printf("\n");
	}

}
