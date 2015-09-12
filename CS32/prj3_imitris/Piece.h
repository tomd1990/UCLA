#include "UserInterface.h"
#ifndef PIECE_INCLUDED
#define PIECE_INCLUDED
class Screen;
class Tank;
class piece
{
public:
	piece(int inp):identifier(inp){}
	virtual void execute()=0;//what piece does once its at rest
	virtual void Oriented(int n)=0;
	void print(Screen& screen, int x, int y);// print function useful for the next piece display
	int Oriental() {return identifier;}
	char shape[4][4];
private:
	int identifier; //identifier answers what kind of piece is it
};

class classic_piece: public piece //classic pieces the ones that turn into dollar signs once at rest
{
public:
	classic_piece():piece(0){}
	classic_piece(int num):piece(num){}
	virtual void Oriented(int n)=0;
	virtual void execute()
	{
		for(int i=0; i<4; i++)
		{
		for(int j=0; j<4; j++)
		{
			if(shape[i][j]=='#')
			{shape[i][j]='$';}
		}
		}
	}

};

class I:public classic_piece
{public:
	virtual void Oriented(int n);
	
};

class T:public classic_piece
{public:
	virtual void Oriented(int n);
	
};

class L:public classic_piece
{public:
	virtual void Oriented(int n);
	
};

class J:public classic_piece
{public:

	virtual void Oriented(int n);
	
};

class O:public classic_piece
{public:
	
	virtual void Oriented(int n);
	
};

class S:public classic_piece
{public:
	virtual void Oriented(int n);
	
};

class Z:public classic_piece
{public:
	virtual void Oriented(int n);
	
};

class CRAZY:public classic_piece
{
public:
	CRAZY():classic_piece(1){}
	virtual void Oriented(int n);
};

class FOAM: public piece// execution is empty because we have defined action in the tank
{
public:
	FOAM(): piece(2){}
	virtual void Oriented(int n);
	virtual void execute(){};
	

};

class VAPOR: public piece// execution is empty because we have defined action in the tank
{
public:
	VAPOR(): piece(3){}
	virtual void Oriented(int n);
	virtual void execute(){}


};
#endif