/*
 * Matrix.h
 *
 *  Created on: Jan 23, 2012
 *      Author: muthu
 */

#ifndef MATRIX_H_
#define MATRIX_H_


#include "Pos.h"
#include "Error.h"
#include "Cell.h"



class Matrix { /* \{([^\}]|[\n])*\}\n */


 class DynamicCellIterator{

		Matrix& outerRef;
	public:
		Cell* currentCellPtr;
	public:
		DynamicCellIterator(Matrix&);
		bool operator==(Matrix::DynamicCellIterator const&);
		DynamicCellIterator& operator=(Matrix::DynamicCellIterator const&);
		bool operator!=(Matrix::DynamicCellIterator const&);

		bool iterateForward();
	};


	Cell cell[9][9];
public:
	DynamicCellIterator dynIte;

	Error errmsg;
	bool  consistent;

public:
	Matrix();
	Matrix(const Matrix&);

	const Error* setMatrix(const int[9][9]);
	void MatrixToArray(int[9][9]);


	bool consistencyCheck(Pos);
	bool checkMatrixConsistency();

	Cell&  getCellAtPos(Pos const&);
	Cell* getCellPtrAtPos(Pos const&);

	Matrix& operator=(Matrix const&);
	bool operator==(Matrix const&);

	virtual ~Matrix() ;

	/*@ Replaced by new func.
	 * bool isFirstDynamicPosExist();
	 * */
	const Pos* getFirstDynamicPosPtr();

	/*@ Replaced by new func.
		*bool isLastDynamicPosExist();
	 * */

	const Pos* getLastDynamicPosPtr();

    friend bool DynamicCellIterator::iterateForward();

};

#endif /* MATRIX_H_ */


