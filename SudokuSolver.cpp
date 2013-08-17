/*
 * SudokuSolver.cpp
 *
 *  Created on: Jan 23, 2012
 *      Author: muthu
 */


#include "SudokuSolver.h"

SudokuSolver::SudokuSolver() {

}

SudokuSolver::SudokuSolver(Matrix& temp) {
	setMatrix(temp);
	m_hasMoreSolution = false;
}

const Error* SudokuSolver::setMatrix(Matrix& temp){
	if(temp.checkMatrixConsistency()){
         solContainer = temp;
         srcOriginal = temp;
         return NULL;
	}
	else
		return &temp.errmsg;
}

void SudokuSolver::getOriginalArrayIn(int array[9][9]){
	srcOriginal.MatrixToArray(array);
}

Matrix SudokuSolver::getOriginalMatrix(){
  return srcOriginal;
}

void  SudokuSolver::reset(){
	  solContainer = srcOriginal;
}

SudokuSolver::~SudokuSolver() {
}


bool SudokuSolver::hasMoreSolution(){
					Matrix temp = solContainer;
					//Making the currentPtr to point the first dynamic Pos;
					temp.dynIte.currentCellPtr = temp.getCellPtrAtPos(*temp.getFirstDynamicPosPtr());

					if( cellWiseSolver(temp) )
						return true;
					else
						return m_hasMoreSolution = false;

}

Matrix  SudokuSolver::nextSolution(){
	if(m_hasMoreSolution){
	  depthTraversal = (solContainer == srcOriginal)?false:true;
	  cellWiseSolver(solContainer);
      return  solContainer;
	}
	else
	  throw new Exception("hasMoreSolution must be called first to prevent exceptions!!!!");

}

bool SudokuSolver::cellWiseSolver(Matrix& matrix){
	if(matrix.dynIte.currentCellPtr == NULL)
		return true; // Success...
	if(depthTraversal == true){ //if the depth first traversal is enabled!!
		if( matrix.dynIte.currentCellPtr->pos !=  *(solContainer.getLastDynamicPosPtr())){
			matrix.dynIte.iterateForward();
			if(cellWiseSolver(matrix))
				return true; //Success...
			else /*Do nothing*/; /*It will automatically fall into a while loop and continue the remaining iteration*/
		}
		else
			depthTraversal = false; //Making the depthTraversal false such that it will continue the normal iterations..
	}
   while(matrix.dynIte.currentCellPtr->getValue() < 9){
	   (matrix.dynIte.currentCellPtr)->setValue(matrix.dynIte.currentCellPtr->getValue() + 1);
	   if(matrix.consistencyCheck(matrix.dynIte.currentCellPtr->pos) == true){
			   //if the matrix is consistent
		   matrix.dynIte.iterateForward();
		   if(cellWiseSolver(matrix))
			   return true; //Success...
	   }
   }
	matrix.dynIte.currentCellPtr->setValue(0);
	return false; //failure...
}

