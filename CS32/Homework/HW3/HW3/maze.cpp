
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
 {	   Coord a(er, ec); // @ will be the symbol used to mean that element has been inspected
	 int x=a.r(); int y=a.c(); 
	 if(maze[x][y]=='M')
	 { return true;}
	 maze[er][ec]='@';
	
	  if(maze[x-1][y]!='X' && maze[x-1][y]!='@')
		 {	
			 if(maze[x-1][y]=='M')
			 { return findsMinotaur(maze,  x-1,  y);
		
			 }
			 else
			 { 
				 
				 if(findsMinotaur(maze,  x-1,  y))
				 {return true;}
				 
				 maze[x-1][y]='@'; findsMinotaur(maze,  x-1,  y);
			 }
			 	 
		 }
	
		 if(maze[x][y+1]!='X' && maze[x][y+1]!='@')
			  {
				  if(maze[x][y+1]=='M')
					{ return findsMinotaur(maze,  x,  y+1);  }
				  else
				  {
					   if(findsMinotaur(maze,  x,  y+1))
						{return true;}
		 
					  maze[x][y+1]='@'; findsMinotaur(maze,  x,  y+1);

				 
				  }

			  }
	 

	 
		  if(maze[x+1][y]!='X' && maze[x+1][y]!='@')
		  { 
			  if(maze[x+1][y]=='M')
			 {return findsMinotaur(maze,  x+1,  y); }
			  else
				  {
					   if(findsMinotaur(maze,  x+1,  y))
						{return true;}
					  
					  maze[x+1][y]='@'; findsMinotaur(maze,  x+1,  y); 
			 }

			
		  }
	
		 if(maze[x][y-1]!='X' && maze[x][y-1]!='@')
			 { 
				 if(maze[x][y-1]=='M')
				 { return findsMinotaur(maze,  x,  y-1);}
				 else
				 {
					 if(findsMinotaur(maze,  x,  y-1))
						{return true;}
					 
					 maze[x][y-1]='@'; findsMinotaur(maze,  x,  y-1);}

				 

		      }

		return false;
	 }

	 
	
    