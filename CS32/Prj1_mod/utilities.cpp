
#include "Colosseum.h"
#include<iostream>
using namespace std;
///////////////////////////////////////////////////////////////////////////
//  Auxiliary function implementation
///////////////////////////////////////////////////////////////////////////

  // Return a uniformly distributed random int from lowest to highest, inclusive
int randInt(int lowest, int highest)
{
    if (highest < lowest)
        swap(highest, lowest);
    return lowest + (rand() % (highest - lowest + 1));
}

bool charToDir(char ch, int& dir)
{
    switch (tolower(ch))
    {
      default:  return false;
      case 'n': dir = NORTH; break;
      case 'e': dir = EAST;  break;
      case 's': dir = SOUTH; break;
      case 'w': dir = WEST;  break;
    }
    return true;
}

  // Return false without changing anything if moving one step from (r,c)
  // in the indicated direction would hit a run off the edge of the colosseum.
  // Otherwise, update r and c to the position resulting from the move and
  // return true.
bool attemptMove(const Colosseum& colosseum, int dir, int& r, int& c)
{
    int rnew = r;
    int cnew = c;
    switch (dir)
    {
      case NORTH:  if (r <= 1)        return false; else rnew--; break;
      case EAST:   if (c >= colosseum.cols()) return false; else cnew++; break;
      case SOUTH:  if (r >= colosseum.rows()) return false; else rnew++; break;
      case WEST:   if (c <= 1)        return false; else cnew--; break;
    }
    r = rnew;
    c = cnew;
    return true;
}

  // Recommend a move for a player at (r,c):  A false return means the
  // recommendation is that the player should push and not move;
  // otherwise, this function sets bestDir to the recommended direction
  // to move and returns true.
bool recommendMove(const Colosseum& colosseum, int r, int c, int& bestDir)
{
      // How dangerous is it to stand?
    int standDanger = computeDanger(colosseum, r, c);

      // if it's not safe, see if moving is safer
    if (standDanger > 0)
    {
        int bestMoveDanger = standDanger;
        int bestMoveDir = NORTH;  // arbitrary initialization

          // check the four directions to see if any move is
          // better than standing, and if so, record the best
        for (int dir = 0; dir < NUMDIRS; dir++)
        {
            int rnew = r;
            int cnew = c;
            if (attemptMove(colosseum, dir, rnew, cnew))
            {
                int danger = computeDanger(colosseum, rnew, cnew);
                if (danger < bestMoveDanger)
                {
                    bestMoveDanger = danger;
                    bestMoveDir = dir;
                }
            }
        }

          // if moving is better than standing, recommend move
        if (bestMoveDanger < standDanger)
        {
            bestDir = bestMoveDir;
            return true;
        }
    }
    return false;  // recommend standing
}

int computeDanger(const Colosseum& colosseum, int r, int c)
{
      // Our measure of danger will be the number of villains that might move
      // to position r,c.  If a villain is at that position, it is fatal,
      // so a large value is returned.

    if (colosseum.numberOfVillainsAt(r,c) > 0)
        return MAXVILLAINS+1;

    int danger = 0;
    if (r > 1)
        danger += colosseum.numberOfVillainsAt(r-1,c);
    if (r < colosseum.rows())
        danger += colosseum.numberOfVillainsAt(r+1,c);
    if (c > 1)
        danger += colosseum.numberOfVillainsAt(r,c-1);
    if (c < colosseum.cols())
        danger += colosseum.numberOfVillainsAt(r,c+1);

    return danger;
}
// DO NOT MODIFY THE CODE BETWEEN HERE AND THE MAIN ROUTINE
#ifdef _MSC_VER  //  Microsoft Visual C++

#include <windows.h>

void clearScreen()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    DWORD dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
    COORD upperLeft = { 0, 0 };
    DWORD dwCharsWritten;
    FillConsoleOutputCharacter(hConsole, TCHAR(' '), dwConSize, upperLeft,
                                                        &dwCharsWritten);
    SetConsoleCursorPosition(hConsole, upperLeft);
}

#else  // not Microsoft Visual C++, so assume UNIX interface

#include <cstring>

void clearScreen()
{
    static const char* term = getenv("TERM");
    static const char* ESC_SEQ = "\x1B[";  // ANSI Terminal esc seq:  ESC [
    if (term == NULL  ||  strcmp(term, "dumb") == 0)
        cout << endl;
     else
        cout << ESC_SEQ << "2J" << ESC_SEQ << "H" << flush;
}

#endif