/*
 * Exception.h
 *
 *  Created on: Jan 25, 2012
 *      Author: muthu
 */

#ifndef EXCEPTION_H_
#define EXCEPTION_H_

#include "stdlib.h"
#include "string.h"

class Exception {
      char* exception;
public:
	Exception();
	Exception(const char* const);
	virtual ~Exception();
};

#endif /* EXCEPTION_H_ */
