/*
 * Cell.cpp
 *
 *  Created on: Jan 23, 2012
 *      Author: muthu
 */


#include "Cell.h"


Cell::Cell() {
	isDynamic = true;
	value = 0;
}
Cell::~Cell() {

}

void Cell::setValue(int value){
    if((value<10) & (value >= 0))
	 this->value = value;
    else
    throw Exception("Invalid Value");

}

int Cell::getValue(){
	return value;
}

Cell& Cell::operator =(Cell const& temp){
	this->pos = temp.pos;
	this->isDynamic = temp.isDynamic;
	setValue(temp.value);
	return *this;
}

bool Cell::operator ==(Cell const& temp){
	if((this->pos == temp.pos) | (this->isDynamic == temp.isDynamic) | (this->value == temp.value))
		return true;

		return false;
}

bool Cell::operator !=(Cell const& temp){
	if((this->pos != temp.pos) | (this->isDynamic != temp.isDynamic) | (this->value != temp.value))
		return true;

		return false;
}
