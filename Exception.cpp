/*
 * Exception.cpp
 *
 *  Created on: Jan 25, 2012
 *      Author: muthu
 */

#include "Exception.h"


Exception::Exception() {
       exception = NULL;
}

Exception::Exception(const char* const exception) {
	this->exception = new char[strlen(exception)+1];
	strcpy(this->exception , exception);
}


Exception::~Exception() {

}
