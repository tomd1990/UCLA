#include "Game.h"
#include "randPieceType.h"
#include <string>
#include <sstream>
#include<iostream>
using namespace std;
const int SCREEN_WIDTH = 80;
const int SCREEN_HEIGHT = 25;

const int TANK_X = 0;
const int TANK_Y = 0;

const int PROMPT_Y = 20;
const int PROMPT_X = 0;

const int SCORE_X = 16;
const int SCORE_Y = 8;

const int ROWS_LEFT_X = 16;
const int ROWS_LEFT_Y = 9;

const int LEVEL_X = 16;
const int LEVEL_Y = 10;

const int NEXT_PIECE_TITLE_X = 16;
const int NEXT_PIECE_TITLE_Y = 3;

const int NEXT_PIECE_X = 16;
const int NEXT_PIECE_Y = 4;
//Here we simply initialize the variables 
Game::Game(int width, int height)
 : m_screen(SCREEN_WIDTH, SCREEN_HEIGHT),m_tank(width, height), m_level(1),m_score(0),m_numrows(5),next_piece(nullptr), current_piece(nullptr)
{
}
//Ive implemented a recursive function that implements the doubling of the score (100 pts) with each line
int Game::score(int num)
{
	if(num==0)
	{return 0;}
	if(num==1)
	{m_score+=100; return 100;}

	
	return score(num-1)+score(num-1);
}

//Didnt implement the play one level function, instead I added the same functionality within the tank class  in the drop function
void Game::play()
{	running=false; // THis lets us know that we havent yet started playing
    m_tank.display(m_screen, TANK_X, TANK_Y);// display the empty tank; the border(@ signs)
    displayStatus(); // here we display just the score,0, the level,1, and the number of rows left,5,
    displayPrompt("Press the Enter key to begin playing Imitris!");
    waitForEnter();  // [in UserInterface.h]
	running=true; //this lets us know that we've begun the game
	update();	// selects the pieces
	displayStatus();// because running is true we can display the next piece shape and select a piece for the one thats dropped into the tank
	
    for(;;)
    {	
		m_tank.drop(current_piece, m_screen, *this);// this function handles the blocks thats being dropped into the tank and updates/ notifies the game when an aciton takes place
		if(m_tank.quit)// bool quit is a varaible defined in the tank class that lets us know whether the player pressed q
	   {break;}
		update();// after the piece has come to rest its time to update the next piece
		displayStatus();
		if(m_numrows==0) // once we have vaporised the required number of rows we clear the tank, (m_tank.clear) delete the pointers then redefine them increase the level, and proceed to the next
        {	displayPrompt("Good job!  Press the Enter key to start next level!");
			 waitForEnter(); delete current_piece;  delete next_piece; current_piece=nullptr; next_piece=nullptr; m_tank.clear(); m_tank.display(m_screen,TANK_X, TANK_Y); update(); 
			m_level++; newrow(); displayStatus();
		}
    }
    displayPrompt("Game Over!  Press the Enter key to exit!");
    waitForEnter();
	
}

void Game::displayPrompt(std::string s)     
{
    m_screen.gotoXY(PROMPT_X, PROMPT_Y);
    m_screen.printStringClearLine(s);   // overwrites previous text
    m_screen.refresh();
}

void Game::displayStatus() 
{	
	//only happens when running is true/ when we decided to play the game
	if(running)
	{ next_piece->Oriented(0);
	m_screen.gotoXY(NEXT_PIECE_TITLE_X, NEXT_PIECE_TITLE_Y);
    m_screen.printString("Next piece:" ); 
    m_screen.refresh();

	m_screen.gotoXY(NEXT_PIECE_X, NEXT_PIECE_Y);
	next_piece->print(m_screen,NEXT_PIECE_X, NEXT_PIECE_Y);
    m_screen.refresh();

	}
// to display the numerical values we convert them to the string and append them to score, etc.	
int a = m_score;
string str;
stringstream ss;
ss.width(7);
ss << a;
str=ss.str();


	m_screen.gotoXY(SCORE_X, SCORE_Y);
    m_screen.printString("Score:     "+str); 
    m_screen.refresh();

int b = m_numrows;
string strb;
stringstream sb;
sb.width(7);
sb<<b;
strb = sb.str();


	m_screen.gotoXY(ROWS_LEFT_X, ROWS_LEFT_Y);
    m_screen.printString("Rows left: "+strb);   
    m_screen.refresh();

int c = m_level;
string strc;
stringstream sc;
sc.width(7);
sc<<c;
strc = sc.str();

	m_screen.gotoXY(LEVEL_X, LEVEL_Y);
    m_screen.printString("Level:     "+strc);   
    m_screen.refresh();

}

// we have two pointers that dictate what the next piece and what the current piece are
void Game::update()
{ 
if(current_piece==nullptr && next_piece==nullptr)//if the start of the game when both are null
	{
	switch (randPieceType())
	{
	  case PIECE_I:
	    current_piece=new I();// make the next piece an I piece
	    break;
	  case PIECE_L:
	   current_piece=new L(); // make the next piece an L piece
	    break;
	 case PIECE_J:
	   current_piece=new J(); // make the next piece an J piece
	    break;
		case PIECE_T:
	   current_piece=new T(); // make the next piece an T piece
	    break;
		case PIECE_O:
	   current_piece=new O(); // make the next piece an O piece
	    break;
		case PIECE_S:
	   current_piece=new S(); // make the next piece an S piece
	    break;
		case PIECE_Z:
	   current_piece=new Z(); // make the next piece an Z piece
	    break;
		case PIECE_CRAZY:
	   current_piece=new CRAZY(); // make the next piece an Crazy piece
	    break;
		case PIECE_FOAM:
	   current_piece=new FOAM(); // make the next piece an foam bomb piece
	    break;
		case PIECE_VAPOR:
	   current_piece=new VAPOR(); // make the next piece an vapor bomb piece
	    break;
	}

	}
else//if not start of the game current will then equal the next piece once the current has been processed
	{	delete current_piece;
		current_piece=next_piece;
	}
if(!next_piece)// if next is something already we need to clear it and define it to another shape as we drop piece by piece
{
delete next_piece;
}
switch (randPieceType())
	{
	  case PIECE_I:
	    next_piece=new I();
	    break;
	  case PIECE_L:
	   next_piece=new L(); 
	    break;
	 case PIECE_J:
	   next_piece=new J(); 
	    break;
		case PIECE_T:
	   next_piece=new T(); 
	    break;
		case PIECE_O:
	   next_piece=new O(); 
	    break;
		case PIECE_S:
	   next_piece=new S(); 
	    break;
		case PIECE_Z:
	   next_piece=new Z(); 
	    break;
		case PIECE_CRAZY:
	   next_piece=new CRAZY();
	    break;
		case PIECE_FOAM:
	   next_piece=new FOAM(); 
	    break;
		case PIECE_VAPOR:
	   next_piece=new VAPOR(); 
	    break;
	}



}
