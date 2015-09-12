#ifndef GLOB_INCLUDED
#define GLOB_INCLUDED
class Colosseum;
///////////////////////////////////////////////////////////////////////////
// Manifest constants
///////////////////////////////////////////////////////////////////////////

const int MAXROWS = 20;              // max number of rows in the colosseum
const int MAXCOLS = 20;              // max number of columns in the colosseum
const int MAXVILLAINS = 100;          // max number of villains allowed

const int NORTH = 0;
const int EAST  = 1;
const int SOUTH = 2;
const int WEST  = 3;
const int NUMDIRS = 4;

const int EMPTY      = 0;
int randInt(int lowest, int highest);
bool charToDir(char ch, int& dir);
bool attemptMove(const Colosseum& colosseum, int dir, int& r, int& c);
bool recommendMove(const Colosseum& colosseum, int r, int c, int& bestDir);
int computeDanger(const Colosseum& colosseum, int r, int c);
void clearScreen();
#endif