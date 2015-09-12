#ifndef TANK_INCLUDED
#define TANK_INCLUDED
#include <iostream>
#include <vector>
using namespace std;
class piece;
class Screen;
class Game;

class Tank
{ //more information will be in the cpp file
  public:
	  Tank( int x, int y);// needs to take ints
    void display(Screen& screen, int x, int y) const;// writing to the screen
	void drop(piece *shape, Screen& screen, Game& g);// starts to fall ned to call update/ display to update score immediately after function
	void print (piece *shape, int x, int y); // stores shape into our multidimensional vector
	void eraser(piece *shape, int x, int y); //erases the shape 
	bool checker() const;  // checks if there is anything immediately beneat the shape (whether its at rest or not
	bool checkerw() const; // checks if we can move the shape west
	bool checkere() const; // checks if we can move the shape east
	bool checkr(piece  *shape, int x , int y, int orient) const; //checks if we can rotate the shape
	void linerem(int num); // removes the lines
	int numoflin() const; // deterimines the number of complete lines
	void clear(); //cleans up the board to default settings
	bool quit; //lets us know when the game is over or when the player pressed q
	
	void fexplosion(int x, int y, int k, int z);// foam explosion
	void findtag(int &x, int &y) const; //finds where the # symbol is
	void vexplosion(int x, int y); //vapor explosion
	
private:
	const int width; //of tank
	const int height;// of tank
	vector< vector<char> >a; // represents the arena
	bool overlap;  //if there is overlap
	bool confirm; // confirmation that space/ hard drop has been executed 
	
	
};

#endif 
