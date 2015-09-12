#ifndef _USERINTERFACE_H_
#define _USERINTERFACE_H_

#include <string>

const char ARROW_UP    = '8';
const char ARROW_DOWN  = '2';
const char ARROW_LEFT  = '4';
const char ARROW_RIGHT = '6';

///////////////////////////////////////////////////////////
// Screen -- Visual Output
///////////////////////////////////////////////////////////

class ScreenImpl;

class Screen
{
  public:
    Screen(int width, int height);
    ~Screen();
    void clear();
    void gotoXY(int x, int y);
    void printChar(char ch);
    void printString(std::string s);
    void printStringClearLine(std::string s);
    void refresh();

  private:
    ScreenImpl* m_impl;
};

///////////////////////////////////////////////////////////
// Functions for Keyboard Input
///////////////////////////////////////////////////////////

bool getCharIfAny(char& ch);
void waitForEnter();
void discardPendingKeys();

///////////////////////////////////////////////////////////
// Functions for Timing
///////////////////////////////////////////////////////////

int getMsecSinceStart();  //  milliseconds since program start

#endif // _USERINTERFACE_H
