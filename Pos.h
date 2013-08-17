/*
 * Pos.h
 *
 *  Created on: Jan 23, 2012
 *      Author: muthu
 */

#ifndef POS_H_
#define POS_H_




#include "Exception.h"


class Pos {
	int x;
	int y;
public:
	Pos();
	Pos(Pos const&);
	Pos(int,int);

	Pos&     operator=(Pos const&);
	bool    operator==(Pos const&);
	bool    operator!=(Pos const&);

	void    setPos(Pos const&);
	void    setPos(int,int);

	void    setx(int);
	void    sety(int);

	int    getx() const ;
	int    gety() const ;

	virtual ~Pos();
};

#endif /* POS_H_ */
