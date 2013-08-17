/*
 * Error.h
 *
 *  Created on: Jan 23, 2012
 *      Author: muthu
 */

#ifndef ERROR_H_
#define ERROR_H_

#include "Pos.h"
#include "stdlib.h"
#include "string.h"

class Pos;

class Error {


	 char* errmsg;
	 Pos pos1,pos2;
public:
	Error();
	Error(Error const&);
	Error(const char* const,Pos const&,Pos const&);

	virtual ~Error();

	Error& operator=(Error const&);
	bool operator==(Error const&);
	bool operator!=(Error const&);



};

#endif /* ERROR_H_ */
