#ifndef GAME_INCLUDED
#define GAME_INCLUDED
#include"Piece.h"
#include "Tank.h"
#include "UserInterface.h"
#include <string>
class Game
{ //more information can be found in the Game.cpp if the functions arent already explanatory
  public:
    Game(int width, int height);
    void play();
    void displayPrompt(std::string s);
    void displayStatus();
	void update();
	~Game(){delete next_piece; delete current_piece;}
	int score(int num);
	int level() const {return m_level;}
	void levelup() {m_level++;}
	void rowcleared() {m_numrows--;}
	void newrow() {m_numrows=5*m_level;}
	int numrow() const {return m_numrows;}
  private:
	bool  running;
    Tank    m_tank;
    Screen  m_screen;
    int     m_level;
	int		m_score;
	int		m_numrows;
	piece *current_piece;
	piece *next_piece; 
	
};

#endif // GAME_INCLUDED
