
#include "StdAfx.h"
#include "Cgenerator.h"
#include <time.h>
using namespace std;
int Cgenerator::gen[9][9];
Cgenerator::Cgenerator(void)
{
	lcount=0;
}

Cgenerator::~Cgenerator(void)
{
}
int Cgenerator::isfixed(int count, int m, int n)
{
int i;
for(i=0;i<count;i++)
if(m==r[i][0] && n==r[i][1])
return(1);
return(0);
}
int Cgenerator::checkmat(int m, int n)
{
int x,y;
for(x=(m/3)*3;x<((m/3)*3+3);x++)
for(y=(n/3)*3;y<((n/3)*3+3);y++)
	{
	if(m!=x && n!=y)
	if(a[m][n]==a[x][y])
	return(0);
	}
return(1);
}
int Cgenerator::checkrow(int m, int n)
{
int x;
for(x=0;x<9;x++)
	{
	if(x!=n)
	if(a[m][n]==a[m][x])
	return(0);
	}
return(1);
}
int Cgenerator::checkcolumn(int m, int n)
{
int x;
for(x=0;x<9;x++)
	{
	if(x!=m)
	if(a[m][n]==a[x][n])
	return(0);
	}
return(1);
}
int Cgenerator::check(int m, int n)
{
lcount++;
int c;
c=checkmat(m,n);
if(c==1)
c=c*checkrow(m,n);
else
return(c);
if(c==1)
c=c*checkcolumn(m,n);
else
return(c);
return(c);
}
int Cgenerator::solve()
{
int i,m=0,n=0,number,c,fixed;
mainallot:
if(lb_mainallot>400000)
return 257;
lb_mainallot++;
for(m=row;m<9;m++)
	{
	n=col;
	while(n<9)
		{
			if(lcount>390000)
	        return 257;
			lcount++;
		number=1;
		fixed=isfixed(icount,m,n);
		if(fixed==0)
			{
			allot:
			if(lb_allot>400000)
               return 257;
			lb_allot++;
			a[m][n]=number;
			c=check(m,n);
			if(c==0)
				{
				number++;
				if(number>9)
					{
					a[m][n]=0;
					if(n==0)
						{
						row=m-1; col=8;
						if(row<0)
						return(0);
						goto backadjust;
						}
					else
						{
						row=m; col=n-1;
						if(row<0 || col<0)
						return(0);
						goto backadjust;
						}
					}
				goto allot;
				}
			}
		n++;
		if(n>8)
		col=0;
		}
	}
return(1);

backadjust:
if(lb_backadjust>400000)
return 257;
lb_backadjust++;
fixed=isfixed(icount,row,col);
if(fixed==0)
	{
	number=a[row][col];
	allot1:
	if(lb_allot1>400000)
     return 257;
	lb_allot++;
	number++;
	a[row][col]=number;
	if(number>9)
		{
		a[row][col]=0;
		if(col==0)
			{
			row--; col=8;
			if(row<0)
			return(0);
			goto backadjust;
			}
		else
			{
			col--;
			if(col<0)
			return(0);
			goto backadjust;
			}
		}
	c=check(row,col);
	if(c==0)
	goto allot1;
	else
		{
		if(col==8)
			{
			row++;
			if(row>8)
			return(0);
			col=0;
			goto mainallot;
			}
		else
			{
			col++;
			if(col>8)
			return(0);
			goto mainallot;
			}
		}
	}
else
	{
	if(col==0)
		{
		row--; col=8;
		if(row<0)
		return(0);
		goto backadjust;
		}
	else
		{
		col--;
		if(col<0)
		return(0);
		goto backadjust;
		}
	}

}
void Cgenerator::generate(int choice)
{
lb_mainallot=0;
lb_backadjust=0;
lb_allot1=0;
lb_allot=0;
lb_generate=0;
gen_param=choice;
lcount=0;
row=0;col=0;icount=0;
int c,i,m,n,count=1,fixed,error;
srand(time(NULL));
generate:
if(lb_generate>400000)
{
generate(gen_param+1);
}
lb_generate++;
for(m=0;m<9;m++)
for(n=0;n<9;n++)
a[m][n]=0;
for(i=0;i<60;i++)
	{
	r[i][0]=20; r[i][1]=20;
	}
switch(choice)
	{
	case 1: mode=45+rand()%4;
		  break;
	case 2: mode=40+rand()%4;
		  break;
	case 3: mode=35+rand()%4;
		  break;
	case 4: mode=35+rand()%4;
		  break;
	default : mode=50+rand()%2;
		  break;
	}
a[0][0]=1+rand()%8; r[0][0]=0; r[0][1]=0;
for(count=1;count<10;count++)
	{
	choose:
	if(lb_choose>200000)
	{
	generate(gen_param-1);
		}
	lb_choose++;
	m=rand()%9; n=rand()%9;
	fixed=isfixed(icount,m,n);
	if(fixed==1)
	goto choose;
	r[count][0]=m; r[count][1]=n;
	allot:
	if(lb_algen>400000)
	generate(gen_param+1);
	lb_algen++;
	a[m][n]=1+rand()%9;
	if(a[m][n]==0)
	goto allot;
	c=check(m,n);
	if(c==0)
	goto allot;
	}
icount=count;
error=solve();
if(error==257)
{generate(gen_param-1);
return;
}
for(m=0;m<9;m++)
for(n=0;n<9;n++)
b[m][n]=a[m][n];
row=0; col=0;
for(i=0;i<60;i++)
	{
	r[i][0]=20; r[i][1]=20;
	}
if(error==0)
goto generate;
for(count=0;count<mode/2;count++)
	{
	choose2:
	m=rand()%9; n=rand()%9;
	fixed=isfixed(count,m,n);
	if(fixed==1)
	goto choose2;
	r[count][0]=m; r[count][1]=n;
	r[count+mode/2][0]=8-m;
	r[count+mode/2][1]=8-n;
	}
for(m=0;m<9;m++)
for(n=0;n<9;n++)
	{
	fixed=isfixed(mode,m,n);
	if(fixed!=1)
	a[m][n]=0;
	}
icount=mode;
ajanth:
for(m=0;m<9;m++)
for(n=0;n<9;n++)
Cgenerator::gen[m][n]=a[m][n];

}