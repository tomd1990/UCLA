
#include "History.h"
#include <iostream>
using namespace std;

History:: History(int nRows, int nCols)
{//Here we want to initialize a vecotr that checks the position of the player, so we set it to 0; its a two dimensional counter
	ROWS=nRows; COLS=nCols;
	int i; int j;
	for (i = 1; i <= ROWS; i++)
	{for (j = 1; j <=COLS; j++)
			{monitor[i-1][j-1]=0;}
	
	}


}

bool History::record(int r, int c)
{// next we record onto monitor
	//check to see if in bounds
if(r>=1 && r<=ROWS && c>=1 && c<=COLS)
{monitor[r-1][c-1]++; return true;}// incrementing the counter
else
return false; //false if out of bounds
}

 void History::display() const
{clearScreen();
 int i; int j; char mark;
for (i = 1; i <= ROWS; i++)
    { for (j = 1; j <= COLS; j++)
		{// initialize the point to be .
			mark='.';
			if(monitor[i-1][j-1]>=1 && monitor[i-1][j-1]<=26)
				{mark= 'A'+monitor[i-1][j-1]-1;}
			if(monitor[i-1][j-1]>26)
				{mark='Z';}

			cout<<mark;
			
		}
        cout << endl;
    }
cout << endl;
}

 