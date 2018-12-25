#pragma once

class Cgenerator
{
public:
	Cgenerator(void);
	int a[9][9],b[9][9],r[60][2];
	static int gen[9][9];
	int row, col, icount, mode;
	void generate(int choice);
	int solve();
	int checkmat(int m, int n);
	int checkrow(int m, int n);
	int checkcolumn(int m, int n);
	int check(int m,int n);
	int isfixed(int count, int m, int n);
	int i,j,error,lcount,gen_param;
	int lb_mainallot,lb_backadjust,lb_allot1,lb_allot,lb_generate,lb_choose,lb_algen;
	char c;

public:
	~Cgenerator(void);
};
