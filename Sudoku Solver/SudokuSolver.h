/*
 * SudokuSolver.h
 *
 *  Created on: Jan 23, 2012
 *      Author: muthu
 */

#ifndef SUDOKUSOLVER_H_
#define SUDOKUSOLVER_H_

#include "Matrix.h"
#include "Error.h"

class SudokuSolver {
	Matrix srcOriginal;
	Matrix solContainer;


	bool depthTraversal;
	bool m_hasMoreSolution;
private:
	bool cellWiseSolver(Matrix& matrix);

public:
	SudokuSolver() ;
	SudokuSolver(Matrix&) ;

	const Error* setMatrix(Matrix&);

	void getOriginalArrayIn(int array[9][9]);
	Matrix getOriginalMatrix();

	void  reset();

	virtual ~SudokuSolver() ;

	bool hasMoreSolution();
	const Matrix&  nextSolution();


};

#endif /* SUDOKUSOLVER_H_ */
