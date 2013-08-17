/*
 * Cell.h
 *
 *  Created on: Jan 23, 2012
 *      Author: muthu
 */

#ifndef CELL_H_
#define CELL_H_

#include "Pos.h"
#include "Exception.h"


class Cell {

	int value;

public:
	bool isDynamic;
	Pos pos;



public:
	Cell();

	void setValue(int);
	int getValue();

	Cell& operator =(Cell const&);
	bool operator ==(Cell const&);
	bool operator !=(Cell const&);

	virtual ~Cell();

};

#endif /* CELL_H_ */
