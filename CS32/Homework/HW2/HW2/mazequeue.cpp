#include<queue>
#include<iostream>
using namespace std;
class Coord
        {
          public:
            Coord(int rr, int cc) : m_r(rr), m_c(cc) {}
            int r() const { return m_r; }
            int c() const { return m_c; }
          private:
            int m_r;
            int m_c;
        };

 bool findsMinotaur(char maze[10][10], int er, int ec)
 {	 queue<Coord> coordStack;  // condidtion for er ec to be within bounds
	 maze[er][ec]='@'; Coord a(er, ec); coordStack.push(a);// @ will be the symbol used to mean that element has been inspected
	 while(!coordStack.empty())
	 {   int x=coordStack.front().r(); int y=coordStack.front().c(); coordStack.pop(); cout<<x<<','<<y<<endl;
		
	 if(maze[x][y]=='M')
	 {return true;}

	 if(x-1>=0)
	 {
		 if(maze[x-1][y]!='X' && maze[x-1][y]!='@')
		 {		Coord N (x-1,y); coordStack.push(N);
			 if(maze[x-1][y]=='M')
			 {}
			 else
			 { maze[x-1][y]='@';}
		 }
	 }
	
	 if(y+1<10)
	 {
		 if(maze[x][y+1]!='X' && maze[x][y+1]!='@')
			  {Coord E (x,y+1); coordStack.push(E);
				  if(maze[x][y+1]=='M')
					{}
				  else
				  {maze[x][y+1]='@';}
		 
			  }
	 
	 }

	 if(x+1<10)
	 {
		  if(maze[x+1][y]!='X' && maze[x+1][y]!='@')
		  { Coord S (x+1,y); coordStack.push(S);
			  if(maze[x+1][y]=='M')
			 {}
			  else
			  {maze[x+1][y]='@';}
		  
		  }
	 }

	 if(y-1>=0)
	 {
		 if(maze[x][y-1]!='X' && maze[x][y-1]!='@')
			 { Coord W (x,y-1); coordStack.push(W);
				 if(maze[x][y-1]=='M')
				 {}
				 else
				 {maze[x][y-1]='@';}
		 
		      }
	 }

	 
	 }

	 return false;

 }
       


int main()
{
	 char maze[10][10] = {
                { 'X','X','X','X','X','X','X','X','X','X'},
                { 'X','M','.','.','.','.','.','.','.','X'},
                { 'X','X','.','X','.','X','X','X','X','X'},
                { 'X','.','.','X','.','X','.','.','.','X'},
                { 'X','.','.','X','.','.','.','X','.','X'},
                { 'X','X','X','X','.','X','X','X','.','X'},
                { 'X','.','.','X','.','.','.','X','X','X'},
                { 'X','.','.','X','X','.','X','X','.','X'},
                { 'X','.','.','.','X','.','.','.','.','X'},
                { 'X','X','X','X','X','X','X','X','X','X'}
            };
	   if (findsMinotaur(maze, 6,4))
                cout << "Solvable!" << endl;
            else
                cout << "Out of luck!" << endl;
        
}