#include "Tank.h"
#include "UserInterface.h"
#include "Piece.h"
#include "Game.h"
#include<vector>
#include<iostream>
#include<stack>
using namespace std;
using namespace std;
Tank::Tank( int x, int y):width(x),height(y)// here we set the width/ height of our tank 
{  overlap=true; //initialize 

for (int i = 0; i < height+1; i++) // initializeing the multidimensional vector add 1 to height / 2 to width for the border (@ symbols)
{
    a.push_back(vector<char>()); // Add an empty row
}

for (int j = 0; j < width+2; j++)
{
    for (int i = 0; i < a.size(); i++) 
	{
        a[i].push_back(i * j); // Add column to all rows
    }
}
		for(int i=0; i<height+1; i++)
	{
		for(int j=0; j<width+2; j++)
		{a[i][j]=' ';}

	}


	for(int i=0; i<height+1; i++)
	{
		 a[i][0]='@';
	}

	for(int i=0; i<width+2;i++)
	{
		a[height][i]='@';
	}

	for(int i=0; i<height+1; i++)
	{
		 a[i][width+1]='@';
	}
}

void Tank::display(Screen& screen, int x, int y) const //simply printing the multidemensional array
{	
	
		for(int i=0; i<height+1; i++)
	{	screen.gotoXY(0,y+i);
		for(int j=0; j<width+2; j++)
		{ screen.printChar(a[i][j]);}

	}
	
}

bool Tank::checker() const //checking if there is a dollar sign * or @ beneath our shape so that we can come to a rest
{
	for(int i=0; i<height+1; i++)
	{
		for(int j=0; j<width+2; j++)
		{
		if(a[i][j]=='#' && (a[i+1][j]=='$' ||a[i+1][j]=='@'||a[i+1][j]=='*'))
		{ return true;}
		}
	}
	return false;
}

bool Tank::checkerw() const
{
	for(int i=0; i<height+1; i++)
	{
		for(int j=0; j<width+2; j++)
		{
		if(a[i][j]=='#' && (a[i][j-1]=='$' ||a[i][j-1]=='@'||a[i][j-1]=='*'))
		{ return true;}
		}

	}
	return false;
}

bool Tank::checkere() const
{
for(int i=0; i<height+1; i++)
	{
		for(int j=0; j<width+2; j++)
		{
		if(a[i][j]=='#' && (a[i][j+1]=='$' ||a[i][j+1]=='@'||a[i][j+1]=='*'))
		{ return true;}
		}

	}
	return false;

}

bool Tank::checkr(piece *shape,int x, int y, int orient) const
{	shape->Oriented(orient);
	for(int i=0; i<4; i++)
	{
			for(int j=0;j<4; j++)
			{	
				if(y+i<0|| x+j<0 || x+j>width+1 ||y+i>height+1)
				{}
				else
				{if((a[y+i][x+j]=='$' || a[y+i][x+j]=='@'|| a[y+i][x+j]=='*') &&shape->shape[i][j]=='#')
					{return true;}	
				}
			 
			}
	}
	return false;
}

void Tank::print(piece *shape, int x, int y)
{	
	
	for(int i=0; i<4; i++)
	{
		for(int j=0; j<4; j++)
		{	
			if(y+i<0|| x+j<0 || x+j>width ||y+i>height)
			{}
			else
			{
			if(a[y+i][x+j]==' ' || a[y+i][x+j]=='#')
			a[y+i][x+j]=shape->shape[i][j];
			}
		
		}
	}
}

void Tank::eraser(piece *shape, int x, int y)// erases strip above while dropping
{	
	for(int i=0; i<4; i++)
	{
			for(int j=0;j<4; j++)
			{	
				if(y+i<0|| x+j<0 || x+j>width ||y+i>height)
				{}
				else
				{if(a[y+i][x+j]!='$' && a[y+i][x+j]!='@' &&a[y+i][x+j]!='*')
					{a[y+i][x+j]=' ';}
				}
			 
			}
	}

}

void Tank::linerem(int num)//not ready worried about when it hits the top
{	
	if(num==0)
	{return;}

	
		for(int j=num;j<=height-1; j++)
		{
			for(int i=1; i<width+1; i++)
			{a[height-1-j+1][i]=a[height-1-j][i];
			}
		}

		for(int k=1; k<width+1; k++)//the top row should always be empty since after every removal all the blocks that were there fall down
			{a[0][k]=' ';}
}

int Tank::numoflin() const
{ 
	for(int j=1; j<=height-1; j++)
	{
		for(int i=1; i<width+1; i++)
		{
			if(a[height-1-j+1][i]==' ')
			{break;}
			if(i==10)
			{return j;}
		}

		
	}
	return 0;

}

void Tank::drop(piece *shape, Screen& screen, Game& g)// first we check that there are no overlaps;
{	 confirm =false; quit=false;
	shape->Oriented(0);
	for (int i=0; i<4; i++)
		{
			for(int j=0; j<4; j++)
			{if(shape->shape[i][j]=='#' && a[i][3+j]!=' ')
				{overlap=false;}
			}

		}
	

	
	
	if(!overlap)
	{
		for(int i=0; i<4; i++)
		{
			for(int j=0; j<4; j++)
			{	if(shape->shape[i][j]=='#')
				{a[i][3+j]=shape->shape[i][j];}
			}
		}
		display(screen,0,0);

		quit=true; return;
	
	}
	print(shape, 3, 0);display(screen,0,0); 
	char dir; int d=0; int w=0; int e=0; int num=0; int z; int start =0;//we begin our decent down the tank w represents steps west , e represents steps eas, num and z are both used in deteriming the proper rotation of the object
	//start is to give enough time for the user to enter a command before the object drops (we dont want it to initially drop before command)
	for(;;)
	{	if(start!=0)
		{eraser(shape, 3-w+e, 0+d); d++; print(shape, 3-w+e, 0+d); display(screen,0,0); }
		
	int endTime = getMsecSinceStart() + max(1000-(100*(g.level()-1)),100);
	while(getMsecSinceStart()<endTime)// time window to input command
	{
		if(getCharIfAny(dir))
		{
			if(dir=='8')
			{ num++; z=num % 4;
				

				
				if(checkr(shape, 3-w+e, 0+d,z))
				{num--; z=num % 4; shape->Oriented(z);
				}
				else
				{shape->Oriented(z); eraser(shape, 3-w+e, 0+d);print(shape, 3-w+e, 0+d); display(screen,0,0);}

			
				
			}
			
			if(dir=='2')
			{
			break;
			}
			
			if(dir=='4')
			{	
				if(shape->Oriental()==1)
				{
				if(!checkere())
				{
				eraser(shape, 3-w+e, 0+d);

				e++;
			
				print(shape, 3-w+e, 0+d); display(screen,0,0);
				}
				}
				
				if(shape->Oriental()!=1)
				{
				if(!checkerw())
				{
				eraser(shape, 3-w+e, 0+d);
				
				w++;
				
				print(shape, 3-w+e, 0+d); display(screen,0,0);
				}
				}
			}
			if(dir=='6')
			{
				if(shape->Oriental()==1)
				{
				if(!checkerw())
				{
				eraser(shape, 3-w+e, 0+d);

				w++;
			
				print(shape, 3-w+e, 0+d); display(screen,0,0);
				}
				}
				
				if(shape->Oriental()!=1)
				{
				if(!checkere())
				{
				eraser(shape, 3-w+e, 0+d);

				e++;
			
				print(shape, 3-w+e, 0+d); display(screen,0,0);
				}
				}
			}
			if(dir=='q' ||dir=='Q')
			{
				quit=true; return;
			}

			if(dir==' ')
			{
				
				while(d<height+1)// determines the where the hard drop will land
				{	
					if(checker())
					{print(shape, 3-w+e, 0+d); /*display(screen,0,0);*/confirm =true;break;}
					eraser(shape, 3-w+e, 0+d);
					d++;print(shape, 3-w+e, 0+d);
				}
			}
			if(confirm)
			{break;}
		}
	}
	start++;
	int q=0;
	if(checker()||confirm) //execution stage 
	{	int c=0; int v=0;
		if(shape->Oriental()==2)//the Oriental function returns the shapes unique identifier 2 represents foam bomb 3 represents vapor bomb
		{ 
		findtag(c, v);
		fexplosion(c,v,c,v);
		display(screen,0,0);
		}

		if(shape->Oriental()==3)
		{
			findtag(c, v);
			vexplosion(c,v);
			display(screen,0,0);
		}
		
		if(shape->Oriental()!=2 && shape->Oriental()!=3)
		{shape->execute();print(shape, 3-w+e, 0+d); display(screen,0,0);}
	
	for(int i=0; i<=4; i++)// clearing lines if they're filled scetion
	{int x=0;   x=numoflin();  
		if(x!=0)
		{q++;
		if(g.numrow()!=0)
		{g.rowcleared();}
		}
		linerem(x);
	}
	g.score(q);//updating the score based on the number of lines , q tracks the number of lines deleted

	
	display(screen,0,0);
	
	break;
	
	}

	}
}

void Tank::fexplosion(int x, int y, int k, int z) //implementation for the action of the foam bomb is put here and designed recursively, justification is in the report
{ 
if(abs(x-k)<=2 && abs(y-z)<=2)	
{a[y][x]='*'; } 


	if(a[y][x+1]==' ' && abs(x+1-k)<=2 && x+1<=width)
	{
		
		fexplosion(x+1, y,k,z);
	}
	
	if(a[y][x-1]==' '&& abs(x-1-k)<=2 && x-1>=0)
	{
		
		fexplosion(x-1,y,k,z);

	}

	if(a[y+1][x]==' '&& abs(y+1-z)<=2 && y+1<=height)
	{
		
		fexplosion(x,y+1,k,z);
	
	}

	if(a[y-1][x]==' '&& abs(y-1-z)<=2 && y-1>=0)
	{
		
		fexplosion(x,y-1,k,z);
	}
	return;

	
}

void Tank::findtag(int &x, int &y) const //finds the poisiton of the #, used for vapor and foam bomb execution
{	
	for(int t=y; y<height+1; t++)
	{
		for(int g=x; g<width+2; g++)
		{	if (a[t][g]=='#')
			{x=g; y=t;return;}
		
		}
		
		
	}
		
}

void Tank::clear() //simply resets the tank to default settings (useful when we go to the next level)
{

	overlap=true;
	for(int i=0; i<height+1; i++)
	{
		for(int j=0; j<width+2; j++)
		{a[i][j]=' ';}

	}

	for(int i=0; i<height+1; i++)
	{
		 a[i][0]='@';
	}

	for(int i=0; i<width+2;i++)
	{
		a[height][i]='@';
	}

	for(int i=0; i<height+1; i++)
	{
		 a[i][width+1]='@';
	}

}

void Tank::vexplosion(int x, int y) //implementation of the vapor bomb action, justification in the report
{
	for(int i=y-2; i<=y+2; i++)
	{
		for( int j=x; j<x+2; j++)
		{
			if(i<=height && i>=0 && a[i][j]!='@')
			{a[i][j]=' ';}
		}

	}
}
