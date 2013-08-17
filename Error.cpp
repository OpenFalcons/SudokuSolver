/*
 * Error.cpp
 *
 *  Created on: Jan 23, 2012
 *      Author: muthu
 */

#include "Error.h"

/*
 * #include "string.h"
#include "stdlib.h"
#include "Pos.cpp"
#include "Error.h"
 * */

Error::Error() {
      errmsg = NULL;
      //pos1.Pos();
        //    pos2.Pos();
}

Error :: Error(const char* const errmsg,Pos const& p1,Pos const& p2){
	this->errmsg = new  char[strlen(errmsg)+1];
	strcpy(this->errmsg,errmsg);
	pos1 = p1;
	pos2 = p2;
}

Error :: Error(Error const& temp){
		this->errmsg = new char[strlen(errmsg)+1];
		strcpy(this->errmsg,errmsg);
		pos1 = temp.pos1;
		pos2 = temp.pos2;
}

Error& Error::operator=(Error const& temp){
		this->errmsg = new char[strlen(errmsg)+1];
		strcpy(this->errmsg,errmsg);
		pos1 = temp.pos1;
		pos2 = temp.pos2;
	return *this;
}

bool Error::operator==(Error const& temp){
		if((!strcmp(this->errmsg,temp.errmsg)) & (pos1 == temp.pos1) & (pos2 == temp.pos2))
			return true;
		else
			return false;
}

bool Error::operator!=(Error const& temp){
		if((strcmp(this->errmsg,temp.errmsg)) & (pos1 != temp.pos1) & (pos2 != temp.pos2))
			return true;
		else
			return false;
}



Error::~Error() {

}
