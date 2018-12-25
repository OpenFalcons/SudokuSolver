/*
 * SudokuSolver.cpp
 *
 *  Created on: Jan 23, 2012
 *      Author: muthu
 */

#include "stdafx.h"
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

					if(!solContainer.checkMatrixConsistency())
						return m_hasMoreSolution = false;

					Matrix tempSolutionContainer = solContainer;

					depthTraversal = (solContainer == srcOriginal)?false:true;

					if(!depthTraversal){ // for the depthTraversal = true case, iterationForward will take care of first iteration.
					//Making the currentPtr to point the first dynamic Pos before passing tempSolutionContainer.
					tempSolutionContainer.dynIte.currentCellPtr = tempSolutionContainer.getCellPtrAtPos(*tempSolutionContainer.getFirstDynamicPosPtr());
					}

					if( cellWiseSolver(tempSolutionContainer) )
						return m_hasMoreSolution = true;
					else
						return m_hasMoreSolution = false;

}

const Matrix&  SudokuSolver::nextSolution(){
	if(m_hasMoreSolution){

	depthTraversal = (solContainer == srcOriginal)?false:true;

     if(!depthTraversal){
     //Making the currentPtr to point the first dynamic Position before passing solContainer;
	  solContainer.dynIte.currentCellPtr = solContainer.getCellPtrAtPos(*solContainer.getFirstDynamicPosPtr());
     }

	  cellWiseSolver(solContainer);
      return  solContainer;
	}
	else
	  throw new Exception("hasMoreSolution must be called first to prevent exceptions!!!!");

}


bool SudokuSolver::cellWiseSolver(Matrix& matrix){

	if(depthTraversal == false)
		if(matrix.dynIte.currentCellPtr == NULL)
			return true; // Success...

	if(depthTraversal == true){ //if the depth first traversal is enabled!!
		if(matrix.dynIte.currentCellPtr == NULL){
			matrix.dynIte.currentCellPtr  =  matrix.getCellPtrAtPos(*matrix.getFirstDynamicPosPtr());
		}

		if( matrix.dynIte.currentCellPtr->pos !=  *(matrix.getLastDynamicPosPtr()) ){

			matrix.dynIte.iterateForward();
			if(cellWiseSolver(matrix)){
				return true; //Success...
			}

			/*If function does not return then the control will automatically fall into a while loop and continue the remaining iteration*/

		}
		else /*This too  will automatically fall into a while loop and continue the remaining iteration as if to find the next solution*/
			depthTraversal = false; //Making the depthTraversal false such that it will continue the normal iterations..
	}

   while(matrix.dynIte.currentCellPtr->getValue() < 9){ //The bounding value is... 1-9. But after checking only we are incrementing. Thats why limiting to 9.
	   (matrix.dynIte.currentCellPtr)->setValue(matrix.dynIte.currentCellPtr->getValue() + 1);
	   if(matrix.consistencyCheck(matrix.dynIte.currentCellPtr->pos) == true){
			   //if the matrix is consistent

		   matrix.dynIte.iterateForward();

		   if(cellWiseSolver(matrix))
			   return true; //Success...
	   }
   }
	matrix.dynIte.currentCellPtr->setValue(0);
	matrix.dynIte.iterateBackward();
	return false; //failure...
}


