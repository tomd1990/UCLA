
#include "Piece.h"
#include"UserInterface.h"

void piece::print(Screen& screen, int x, int y)//print function
{
	for(int i=0; i<4; i++)
	{screen.gotoXY(x, y+i);
		for(int j=0; j<4; j++)
		{ screen.printChar(shape[i][j]);}
	}
}

//various positions of the shapes
void  I::Oriented(int n)
	{ 

		if(n==0)
		{
			 shape[0][0] =' ';shape[0][1] =' ';shape[0][2] =' ';shape[0][3] =' ';
			 shape[1][0] ='#';shape[1][1] ='#';shape[1][2] ='#';shape[1][3] ='#';
			 shape[2][0] =' ';shape[2][1] =' ';shape[2][2] =' ';shape[2][3] =' ';
			 shape[3][0] =' ';shape[3][1] =' ';shape[3][2] =' ';shape[3][3] =' ';
		}
		
		if(n==1)
		{

			 shape[0][0] =' ';shape[0][1] ='#';shape[0][2] =' ';shape[0][3] =' ';
			 shape[1][0] =' ';shape[1][1] ='#';shape[1][2] =' ';shape[1][3] =' ';
			 shape[2][0] =' ';shape[2][1] ='#';shape[2][2] =' ';shape[2][3] =' ';
			 shape[3][0] =' ';shape[3][1] ='#';shape[3][2] =' ';shape[3][3] =' ';

		}

		if(n==2)
		{
			 shape[0][0] =' ';shape[0][1] =' ';shape[0][2] =' ';shape[0][3] =' ';
			 shape[1][0] ='#';shape[1][1] ='#';shape[1][2] ='#';shape[1][3] ='#';
			 shape[2][0] =' ';shape[2][1] =' ';shape[2][2] =' ';shape[2][3] =' ';
			 shape[3][0] =' ';shape[3][1] =' ';shape[3][2] =' ';shape[3][3] =' ';
		}

		if(n==3)
		{
			 shape[0][0] =' ';shape[0][1] ='#';shape[0][2] =' ';shape[0][3] =' ';
			 shape[1][0] =' ';shape[1][1] ='#';shape[1][2] =' ';shape[1][3] =' ';
			 shape[2][0] =' ';shape[2][1] ='#';shape[2][2] =' ';shape[2][3] =' ';
			 shape[3][0] =' ';shape[3][1] ='#';shape[3][2] =' ';shape[3][3] =' ';
		}
		
		
	}

void  T::Oriented(int n)
{

	if(n==0)
		{
			 shape[0][0] =' ';shape[0][1] ='#';shape[0][2] =' ';shape[0][3] =' ';
			 shape[1][0] ='#';shape[1][1] ='#';shape[1][2] ='#';shape[1][3] =' ';
			 shape[2][0] =' ';shape[2][1] =' ';shape[2][2] =' ';shape[2][3] =' ';
			 shape[3][0] =' ';shape[3][1] =' ';shape[3][2] =' ';shape[3][3] =' ';
		}
		
		if(n==1)
		{

			 shape[0][0] =' ';shape[0][1] ='#';shape[0][2] =' ';shape[0][3] =' ';
			 shape[1][0] =' ';shape[1][1] ='#';shape[1][2] ='#';shape[1][3] =' ';
			 shape[2][0] =' ';shape[2][1] ='#';shape[2][2] =' ';shape[2][3] =' ';
			 shape[3][0] =' ';shape[3][1] =' ';shape[3][2] =' ';shape[3][3] =' ';

		}

		if(n==2)
		{
			 shape[0][0] =' ';shape[0][1] =' ';shape[0][2] =' ';shape[0][3] =' ';
			 shape[1][0] ='#';shape[1][1] ='#';shape[1][2] ='#';shape[1][3] =' ';
			 shape[2][0] =' ';shape[2][1] ='#';shape[2][2] =' ';shape[2][3] =' ';
			 shape[3][0] =' ';shape[3][1] =' ';shape[3][2] =' ';shape[3][3] =' ';
		}

		if(n==3)
		{
			 shape[0][0] =' ';shape[0][1] ='#';shape[0][2] =' ';shape[0][3] =' ';
			 shape[1][0] ='#';shape[1][1] ='#';shape[1][2] =' ';shape[1][3] =' ';
			 shape[2][0] =' ';shape[2][1] ='#';shape[2][2] =' ';shape[2][3] =' ';
			 shape[3][0] =' ';shape[3][1] =' ';shape[3][2] =' ';shape[3][3] =' ';
		}
		

}


void  L::Oriented(int n)
{

	if(n==0)
		{
			 shape[0][0] =' ';shape[0][1] =' ';shape[0][2] =' ';shape[0][3] =' ';
			 shape[1][0] ='#';shape[1][1] ='#';shape[1][2] ='#';shape[1][3] =' ';
			 shape[2][0] ='#';shape[2][1] =' ';shape[2][2] =' ';shape[2][3] =' ';
			 shape[3][0] =' ';shape[3][1] =' ';shape[3][2] =' ';shape[3][3] =' ';
		}
		
		if(n==1)
		{

			 shape[0][0] =' ';shape[0][1] ='#';shape[0][2] ='#';shape[0][3] =' ';
			 shape[1][0] =' ';shape[1][1] =' ';shape[1][2] ='#';shape[1][3] =' ';
			 shape[2][0] =' ';shape[2][1] =' ';shape[2][2] ='#';shape[2][3] =' ';
			 shape[3][0] =' ';shape[3][1] =' ';shape[3][2] =' ';shape[3][3] =' ';

		}

		if(n==2)
		{
			 shape[0][0] =' ';shape[0][1] =' ';shape[0][2] =' ';shape[0][3] =' ';
			 shape[1][0] =' ';shape[1][1] =' ';shape[1][2] ='#';shape[1][3] =' ';
			 shape[2][0] ='#';shape[2][1] ='#';shape[2][2] ='#';shape[2][3] =' ';
			 shape[3][0] =' ';shape[3][1] =' ';shape[3][2] =' ';shape[3][3] =' ';
		}

		if(n==3)
		{
			 shape[0][0] =' ';shape[0][1] =' ';shape[0][2] =' ';shape[0][3] =' ';
			 shape[1][0] =' ';shape[1][1] ='#';shape[1][2] =' ';shape[1][3] =' ';
			 shape[2][0] =' ';shape[2][1] ='#';shape[2][2] =' ';shape[2][3] =' ';
			 shape[3][0] =' ';shape[3][1] ='#';shape[3][2] ='#';shape[3][3] =' ';
		}
		

}


void  J::Oriented(int n)
{

	if(n==0)
		{
			 shape[0][0] =' ';shape[0][1] =' ';shape[0][2] =' ';shape[0][3] =' ';
			 shape[1][0] =' ';shape[1][1] ='#';shape[1][2] ='#';shape[1][3] ='#';
			 shape[2][0] =' ';shape[2][1] =' ';shape[2][2] =' ';shape[2][3] ='#';
			 shape[3][0] =' ';shape[3][1] =' ';shape[3][2] =' ';shape[3][3] =' ';
		}
		
		if(n==1)
		{

			 shape[0][0] =' ';shape[0][1] =' ';shape[0][2] =' ';shape[0][3] =' ';
			 shape[1][0] =' ';shape[1][1] =' ';shape[1][2] ='#';shape[1][3] =' ';
			 shape[2][0] =' ';shape[2][1] =' ';shape[2][2] ='#';shape[2][3] =' ';
			 shape[3][0] =' ';shape[3][1] ='#';shape[3][2] ='#';shape[3][3] =' ';

		}

		if(n==2)
		{
			 shape[0][0] =' ';shape[0][1] =' ';shape[0][2] =' ';shape[0][3] =' ';
			 shape[1][0] =' ';shape[1][1] ='#';shape[1][2] =' ';shape[1][3] =' ';
			 shape[2][0] =' ';shape[2][1] ='#';shape[2][2] ='#';shape[2][3] ='#';
			 shape[3][0] =' ';shape[3][1] =' ';shape[3][2] =' ';shape[3][3] =' ';
		}

		if(n==3)
		{
			 shape[0][0] =' ';shape[0][1] ='#';shape[0][2] ='#';shape[0][3] =' ';
			 shape[1][0] =' ';shape[1][1] ='#';shape[1][2] =' ';shape[1][3] =' ';
			 shape[2][0] =' ';shape[2][1] ='#';shape[2][2] =' ';shape[2][3] =' ';
			 shape[3][0] =' ';shape[3][1] =' ';shape[3][2] =' ';shape[3][3] =' ';
		}
		

}

void  O::Oriented(int n)
{

	if(n==0)
		{
			 shape[0][0] ='#';shape[0][1] ='#';shape[0][2] =' ';shape[0][3] =' ';
			 shape[1][0] ='#';shape[1][1] ='#';shape[1][2] =' ';shape[1][3] =' ';
			 shape[2][0] =' ';shape[2][1] =' ';shape[2][2] =' ';shape[2][3] =' ';
			 shape[3][0] =' ';shape[3][1] =' ';shape[3][2] =' ';shape[3][3] =' ';
		}
		
		if(n==1)
		{

			 shape[0][0] ='#';shape[0][1] ='#';shape[0][2] =' ';shape[0][3] =' ';
			 shape[1][0] ='#';shape[1][1] ='#';shape[1][2] =' ';shape[1][3] =' ';
			 shape[2][0] =' ';shape[2][1] =' ';shape[2][2] =' ';shape[2][3] =' ';
			 shape[3][0] =' ';shape[3][1] =' ';shape[3][2] =' ';shape[3][3] =' ';

		}

		if(n==2)
		{
			 shape[0][0] ='#';shape[0][1] ='#';shape[0][2] =' ';shape[0][3] =' ';
			 shape[1][0] ='#';shape[1][1] ='#';shape[1][2] =' ';shape[1][3] =' ';
			 shape[2][0] =' ';shape[2][1] =' ';shape[2][2] =' ';shape[2][3] =' ';
			 shape[3][0] =' ';shape[3][1] =' ';shape[3][2] =' ';shape[3][3] =' ';
		}

		if(n==3)
		{
			 shape[0][0] ='#';shape[0][1] ='#';shape[0][2] =' ';shape[0][3] =' ';
			 shape[1][0] ='#';shape[1][1] ='#';shape[1][2] =' ';shape[1][3] =' ';
			 shape[2][0] =' ';shape[2][1] =' ';shape[2][2] =' ';shape[2][3] =' ';
			 shape[3][0] =' ';shape[3][1] =' ';shape[3][2] =' ';shape[3][3] =' ';
		}
		

}

void  S::Oriented(int n)
{

	if(n==0)
		{
			 shape[0][0] =' ';shape[0][1] =' ';shape[0][2] =' ';shape[0][3] =' ';
			 shape[1][0] =' ';shape[1][1] ='#';shape[1][2] ='#';shape[1][3] =' ';
			 shape[2][0] ='#';shape[2][1] ='#';shape[2][2] =' ';shape[2][3] =' ';
			 shape[3][0] =' ';shape[3][1] =' ';shape[3][2] =' ';shape[3][3] =' ';
		}
		
		if(n==1)
		{

			 shape[0][0] =' ';shape[0][1] ='#';shape[0][2] =' ';shape[0][3] =' ';
			 shape[1][0] =' ';shape[1][1] ='#';shape[1][2] ='#';shape[1][3] =' ';
			 shape[2][0] =' ';shape[2][1] =' ';shape[2][2] ='#';shape[2][3] =' ';
			 shape[3][0] =' ';shape[3][1] =' ';shape[3][2] =' ';shape[3][3] =' ';

		}

		if(n==2)
		{
			 shape[0][0] =' ';shape[0][1] =' ';shape[0][2] =' ';shape[0][3] =' ';
			 shape[1][0] =' ';shape[1][1] ='#';shape[1][2] ='#';shape[1][3] =' ';
			 shape[2][0] ='#';shape[2][1] ='#';shape[2][2] =' ';shape[2][3] =' ';
			 shape[3][0] =' ';shape[3][1] =' ';shape[3][2] =' ';shape[3][3] =' ';
		}

		if(n==3)
		{
			 shape[0][0] =' ';shape[0][1] ='#';shape[0][2] =' ';shape[0][3] =' ';
			 shape[1][0] =' ';shape[1][1] ='#';shape[1][2] ='#';shape[1][3] =' ';
			 shape[2][0] =' ';shape[2][1] =' ';shape[2][2] ='#';shape[2][3] =' ';
			 shape[3][0] =' ';shape[3][1] =' ';shape[3][2] =' ';shape[3][3] =' ';
		}
		

}

void  Z::Oriented(int n)
{

	if(n==0)
		{
			 shape[0][0] =' ';shape[0][1] =' ';shape[0][2] =' ';shape[0][3] =' ';
			 shape[1][0] ='#';shape[1][1] ='#';shape[1][2] =' ';shape[1][3] =' ';
			 shape[2][0] =' ';shape[2][1] ='#';shape[2][2] ='#';shape[2][3] =' ';
			 shape[3][0] =' ';shape[3][1] =' ';shape[3][2] =' ';shape[3][3] =' ';
		}
		
		if(n==1)
		{

			 shape[0][0] =' ';shape[0][1] =' ';shape[0][2] ='#';shape[0][3] =' ';
			 shape[1][0] =' ';shape[1][1] ='#';shape[1][2] ='#';shape[1][3] =' ';
			 shape[2][0] =' ';shape[2][1] ='#';shape[2][2] =' ';shape[2][3] =' ';
			 shape[3][0] =' ';shape[3][1] =' ';shape[3][2] =' ';shape[3][3] =' ';

		}

		if(n==2)
		{
			 shape[0][0] =' ';shape[0][1] =' ';shape[0][2] =' ';shape[0][3] =' ';
			 shape[1][0] ='#';shape[1][1] ='#';shape[1][2] =' ';shape[1][3] =' ';
			 shape[2][0] =' ';shape[2][1] ='#';shape[2][2] ='#';shape[2][3] =' ';
			 shape[3][0] =' ';shape[3][1] =' ';shape[3][2] =' ';shape[3][3] =' ';
		}

		if(n==3)
		{
			 shape[0][0] =' ';shape[0][1] =' ';shape[0][2] ='#';shape[0][3] =' ';
			 shape[1][0] =' ';shape[1][1] ='#';shape[1][2] ='#';shape[1][3] =' ';
			 shape[2][0] =' ';shape[2][1] ='#';shape[2][2] =' ';shape[2][3] =' ';
			 shape[3][0] =' ';shape[3][1] =' ';shape[3][2] =' ';shape[3][3] =' ';
		}
		

}

void CRAZY::Oriented(int n)
{
	if(n==0)
		{
			 shape[0][0] ='#';shape[0][1] =' ';shape[0][2] =' ';shape[0][3] ='#';
			 shape[1][0] =' ';shape[1][1] ='#';shape[1][2] ='#';shape[1][3] =' ';
			 shape[2][0] =' ';shape[2][1] =' ';shape[2][2] =' ';shape[2][3] =' ';
			 shape[3][0] =' ';shape[3][1] =' ';shape[3][2] =' ';shape[3][3] =' ';
		}
		
		if(n==1)
		{

			 shape[0][0] =' ';shape[0][1] =' ';shape[0][2] =' ';shape[0][3] ='#';
			 shape[1][0] =' ';shape[1][1] =' ';shape[1][2] ='#';shape[1][3] =' ';
			 shape[2][0] =' ';shape[2][1] =' ';shape[2][2] ='#';shape[2][3] =' ';
			 shape[3][0] =' ';shape[3][1] =' ';shape[3][2] =' ';shape[3][3] ='#';

		}

		if(n==2)
		{
			 shape[0][0] =' ';shape[0][1] =' ';shape[0][2] =' ';shape[0][3] =' ';
			 shape[1][0] =' ';shape[1][1] =' ';shape[1][2] =' ';shape[1][3] =' ';
			 shape[2][0] =' ';shape[2][1] ='#';shape[2][2] ='#';shape[2][3] =' ';
			 shape[3][0] ='#';shape[3][1] =' ';shape[3][2] =' ';shape[3][3] ='#';
		}

		if(n==3)
		{
			 shape[0][0] ='#';shape[0][1] =' ';shape[0][2] =' ';shape[0][3] =' ';
			 shape[1][0] =' ';shape[1][1] ='#';shape[1][2] =' ';shape[1][3] =' ';
			 shape[2][0] =' ';shape[2][1] ='#';shape[2][2] =' ';shape[2][3] =' ';
			 shape[3][0] ='#';shape[3][1] =' ';shape[3][2] =' ';shape[3][3] =' ';
		}

}

void FOAM::Oriented(int n)
{
	if(n==0)
		{
			 shape[0][0] =' ';shape[0][1] =' ';shape[0][2] =' ';shape[0][3] =' ';
			 shape[1][0] =' ';shape[1][1] ='#';shape[1][2] =' ';shape[1][3] =' ';
			 shape[2][0] =' ';shape[2][1] =' ';shape[2][2] =' ';shape[2][3] =' ';
			 shape[3][0] =' ';shape[3][1] =' ';shape[3][2] =' ';shape[3][3] =' ';
		}
		
		if(n==1)
		{

			 shape[0][0] =' ';shape[0][1] =' ';shape[0][2] =' ';shape[0][3] =' ';
			 shape[1][0] =' ';shape[1][1] ='#';shape[1][2] =' ';shape[1][3] =' ';
			 shape[2][0] =' ';shape[2][1] =' ';shape[2][2] =' ';shape[2][3] =' ';
			 shape[3][0] =' ';shape[3][1] =' ';shape[3][2] =' ';shape[3][3] =' ';

		}

		if(n==2)
		{
			 shape[0][0] =' ';shape[0][1] =' ';shape[0][2] =' ';shape[0][3] =' ';
			 shape[1][0] =' ';shape[1][1] ='#';shape[1][2] =' ';shape[1][3] =' ';
			 shape[2][0] =' ';shape[2][1] =' ';shape[2][2] =' ';shape[2][3] =' ';
			 shape[3][0] =' ';shape[3][1] =' ';shape[3][2] =' ';shape[3][3] =' ';
		}

		if(n==3)
		{
			 shape[0][0] =' ';shape[0][1] =' ';shape[0][2] =' ';shape[0][3] =' ';
			 shape[1][0] =' ';shape[1][1] ='#';shape[1][2] =' ';shape[1][3] =' ';
			 shape[2][0] =' ';shape[2][1] =' ';shape[2][2] =' ';shape[2][3] =' ';
			 shape[3][0] =' ';shape[3][1] =' ';shape[3][2] =' ';shape[3][3] =' ';
		}
}

void VAPOR::Oriented(int n)
{
if(n==0)
		{
			 shape[0][0] =' ';shape[0][1] ='#';shape[0][2] ='#';shape[0][3] =' ';
			 shape[1][0] =' ';shape[1][1] =' ';shape[1][2] =' ';shape[1][3] =' ';
			 shape[2][0] =' ';shape[2][1] =' ';shape[2][2] =' ';shape[2][3] =' ';
			 shape[3][0] =' ';shape[3][1] =' ';shape[3][2] =' ';shape[3][3] =' ';
		}
		
		if(n==1)
		{

			 shape[0][0] =' ';shape[0][1] ='#';shape[0][2] ='#';shape[0][3] =' ';
			 shape[1][0] =' ';shape[1][1] =' ';shape[1][2] =' ';shape[1][3] =' ';
			 shape[2][0] =' ';shape[2][1] =' ';shape[2][2] =' ';shape[2][3] =' ';
			 shape[3][0] =' ';shape[3][1] =' ';shape[3][2] =' ';shape[3][3] =' ';

		}

		if(n==2)
		{
			 shape[0][0] =' ';shape[0][1] ='#';shape[0][2] ='#';shape[0][3] =' ';
			 shape[1][0] =' ';shape[1][1] =' ';shape[1][2] =' ';shape[1][3] =' ';
			 shape[2][0] =' ';shape[2][1] =' ';shape[2][2] =' ';shape[2][3] =' ';
			 shape[3][0] =' ';shape[3][1] =' ';shape[3][2] =' ';shape[3][3] =' ';
		}

		if(n==3)
		{
			 shape[0][0] =' ';shape[0][1] ='#';shape[0][2] ='#';shape[0][3] =' ';
			 shape[1][0] =' ';shape[1][1] =' ';shape[1][2] =' ';shape[1][3] =' ';
			 shape[2][0] =' ';shape[2][1] =' ';shape[2][2] =' ';shape[2][3] =' ';
			 shape[3][0] =' ';shape[3][1] =' ';shape[3][2] =' ';shape[3][3] =' ';
		}
}
















