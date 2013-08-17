/*
 * Matrix.cpp
 *
 *  Created on: Jan 23, 2012
 *      Author: muthu
 */

#include "Matrix.h"

Matrix::Matrix() : dynIte(*this),consistent(true){

}

Matrix::Matrix(const Matrix& temp) : dynIte(*this) {
	*this = temp;
}



const Error* Matrix::setMatrix(const int src[9][9]){

	for(int i=0;i<9;i++)
		for(int j=0;j<9;j++){
			cell[i][j].setValue(src[i][j]);

			if(cell[i][j].getValue() != 0)
				cell[i][j].isDynamic = false;
			else
				cell[i][j].isDynamic = true;
			cell[i][j].pos.setPos(i,j);
		}

	if(checkMatrixConsistency() != false)
		return &errmsg;
	else
		return  NULL;
}

void Matrix::MatrixToArray(int array[9][9]){
	for(int i=0;i<9;i++)
		for(int j=0;j<9;j++)
			array[i][j] = cell[i][j].getValue();
}

bool Matrix::consistencyCheck(Pos p) {

	int row = p.getx();
	int col = p.gety();

	//Row check....
	for(int i=0;i<9;i++)
		if( i != col )
			if(cell[i][col].getValue() != 0)
				if(cell[i][col].getValue() == cell[row][col].getValue()){
					errmsg = Error("Row inconsistency",Pos(i,col),p);
					consistent = false;
					return false;
				}

	//Column check....
	for(int i=0;i<9;i++)
		if( i != row )
			if(cell[row][i].getValue() != 0)
				if(cell[row][i].getValue() == cell[row][col].getValue()){
					errmsg = Error("Row inconsistency",Pos(row,i),p);
					consistent = false;
					return false;
				}

   //Block check....
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++){
			Pos k((row/3)*3+i,(col/3)*3+j);
			if(k != cell[row][col].pos)
				if(getCellAtPos(k).getValue() != 0)
					if(getCellAtPos(k).getValue() == getCellAtPos(p).getValue()){
						errmsg = Error("Block inconsistency",k,p);
						consistent = false;
						return false;
					}
		}

		return true;
}

bool Matrix::checkMatrixConsistency(){
	for(int i=0;i<9;i++)
		for(int j=0;j<9;j++)
			if(cell[i][j].getValue() != 0)
				if( consistencyCheck(cell[i][j].pos) == false)
					return false;

    return true;
}


Cell& Matrix::getCellAtPos(Pos const& p){
	return cell[p.getx()][p.gety()];
}
Cell* Matrix::getCellPtrAtPos(Pos const& p){
	return &cell[p.getx()][p.gety()];
}

Matrix& Matrix::operator=(Matrix const& temp){
	for(int i=0;i<9;i++)
		for(int j=0;j<9;j++)
			cell[i][j] = temp.cell[i][j];
	dynIte = temp.dynIte;
	errmsg = temp.errmsg;
	consistent = temp.consistent;
	return *this;
}

bool Matrix::operator==(Matrix const& temp){
	for(int i=0;i<9;i++)
		for(int j=0;j<9;j++)
			if(cell[i][j] != temp.cell[i][j])
			  return false;

	if((dynIte != temp.dynIte) | (errmsg != temp.errmsg) | (consistent != temp.consistent))
		return false;

	return true;
}

Matrix::~Matrix() {
}



Matrix::DynamicCellIterator::DynamicCellIterator(Matrix& ref): outerRef(ref),currentCellPtr(NULL){

}

Matrix::DynamicCellIterator& Matrix::DynamicCellIterator::operator=(Matrix::DynamicCellIterator const& temp){
	this->currentCellPtr = temp.currentCellPtr;
	return *this;
}
bool Matrix::DynamicCellIterator::operator==(Matrix::DynamicCellIterator const& temp){
	return *(this->currentCellPtr) == *(temp.currentCellPtr);
}

bool Matrix::DynamicCellIterator::operator!=(Matrix::DynamicCellIterator const& temp){
	return *(this->currentCellPtr) != *(temp.currentCellPtr);
}


/*@Replaced by new func.
bool Matrix::isFirstDynamicPosExist(){
	for(int i=0; i<=8;i++)
		for(int j=0; j<=8;j++)
			if(cell[i][j].isDynamic)
				return true;
	return false;
}
*/
const Pos* Matrix::getFirstDynamicPosPtr(){
	for(int i=0; i<=8;i++)
		for(int j=0; j<=8;j++)
			if(cell[i][j].isDynamic)
				return &cell[i][j].pos;
	return NULL;
}

/*
 * @Replaced by new func
bool Matrix::isLastDynamicPosExist(){
	for(int i=8; i>=0;i--)
			for(int j=8; j>=0;j--)
				if(cell[i][j].isDynamic)
					return true;
	return false;
}
*/

const Pos*  Matrix::getLastDynamicPosPtr(){
	for(int i=8; i>=0;i--)
		for(int j=8; j>=0;j--)
			if(cell[i][j].isDynamic)
				return &cell[i][j].pos;
	return NULL;
}


bool Matrix::DynamicCellIterator::iterateForward(){
	for(int i= (currentCellPtr->pos).getx() ; i<=8 ;i++)
		for(int j= (currentCellPtr->pos).gety(); j<=8; j++)
			if(outerRef.cell[i][j].isDynamic){
				currentCellPtr = &(outerRef.cell[i][j]);
				return true;// successful iteration.
			}

	 currentCellPtr = NULL;
	 return false; //non successful iterations.
}

