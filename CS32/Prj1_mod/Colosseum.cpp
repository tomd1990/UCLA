#include "globals.h"
#include "Player.h"
#include "Villain.h"
#include "Colosseum.h"
#include <iostream>
using namespace std;

///////////////////////////////////////////////////////////////////////////
//  Colosseum implementation
///////////////////////////////////////////////////////////////////////////

Colosseum::Colosseum(int nRows, int nCols)
	:m_hist(nRows, nCols)
{
    if (nRows <= 0  ||  nCols <= 0  ||  nRows > MAXROWS  ||  nCols > MAXCOLS)
    {
        cout << "***** Colosseum created with invalid size " << nRows << " by "
             << nCols << "!" << endl;
        exit(1);
    }
    m_rows = nRows;
    m_cols = nCols;
	
    m_player = NULL;
    m_nVillains = 0;
    m_turns = 0;
    for (int r = 1; r <= m_rows; r++)
        for (int c = 1; c <= m_cols; c++)
            setCellStatus(r, c, EMPTY);
}

Colosseum::~Colosseum()
{
    for (int k = 0; k < m_nVillains; k++)
        delete m_villains[k];
    delete m_player;
}

int Colosseum::rows() const
{
    return m_rows;
}

int Colosseum::cols() const
{
    return m_cols;
}

Player* Colosseum::player() const
{
    return m_player;
}

int Colosseum::villainCount() const
{
    return m_nVillains;
}

int Colosseum::getCellStatus(int r, int c) const
{
    checkPos(r, c);
    return m_grid[r-1][c-1];
}

int Colosseum::numberOfVillainsAt(int r, int c) const
{
    int count = 0;
    for (int k = 0; k < m_nVillains; k++)
    {
        Villain* vp = m_villains[k];
        if (vp->row() == r  &&  vp->col() == c)
            count++;
    }
    return count;
}

void Colosseum::display(string msg) const
{
    char displayGrid[MAXROWS][MAXCOLS];
    int r, c;
    
      // Fill displayGrid with dots (empty)
    for (r = 1; r <= rows(); r++)
        for (c = 1; c <= cols(); c++)
            displayGrid[r-1][c-1] = (getCellStatus(r,c) == EMPTY ? '.' : '*');

        // Indicate each villain's position
    for (int k = 0; k < m_nVillains; k++)
    {
        const Villain* vp = m_villains[k];
        char& gridChar = displayGrid[vp->row()-1][vp->col()-1];
        switch (gridChar)
        {
          case '.':  gridChar = 'V'; break;
          case 'V':  gridChar = '2'; break;
          case '9':  break;
          default:   gridChar++; break;  // '2' through '8'
        }
    }

      // Indicate player's position
    if (m_player != NULL)
        displayGrid[m_player->row()-1][m_player->col()-1] = (m_player->isDead() ? 'X' : '@');

      // Draw the grid
    clearScreen();
    for (r = 1; r <= rows(); r++)
    {
        for (c = 1; c <= cols(); c++)
            cout << displayGrid[r-1][c-1];
        cout << endl;
    }
    cout << endl;

      // Write message, villain, and player info
    if (msg != "")
        cout << msg << endl;
    cout << "There are " << villainCount() << " villains remaining." << endl;
    if (m_player == NULL)
        cout << "There is no player!" << endl;
    else if (m_player->isDead())
        cout << "The player is dead." << endl;
    cout << m_turns << " turns have been taken." << endl;
}

void Colosseum::setCellStatus(int r, int c, int status)
{
    checkPos(r, c);
    m_grid[r-1][c-1] = status;
}

bool Colosseum::addVillain(int r, int c)
{
    if (! isPosInBounds(r, c))
        return false;
    if (m_player != NULL  &&  m_player->row() == r  &&  m_player->col() == c)
        return false;
    if (m_nVillains == MAXVILLAINS)
        return false;
    m_villains[m_nVillains] = new Villain(this, r, c);
    m_nVillains++;
    return true;
}

bool Colosseum::addPlayer(int r, int c)
{
    if (m_player != NULL  ||  ! isPosInBounds(r, c))
        return false;
    if (numberOfVillainsAt(r, c) > 0)
        return false;
    m_player = new Player(this, r, c);
    return true;
}

void Colosseum::moveVillains()
{
      // Move all villains
    for (int k = m_nVillains-1; k >= 0; k--)
    {
        Villain* vp = m_villains[k];
        vp->move();

        if (m_player != NULL  &&
                vp->row() == m_player->row()  &&  vp->col() == m_player->col())
            m_player->setDead();

    }


      // Another turn has been taken
    m_turns++;
}

void Colosseum::pushAllVillains(int r, int c, int dir)
{
    // pushes all villains at [r,c] in the given direction
    // Note that if r,c isn't a valid location, this will 
    //      do nothing.  We could instead have checked
    //      to see if it's in range, and skipped the loop
    //      in that case.
    //	(or we could do bounds checking before calling, etc)
    for (int k = m_nVillains-1; k >= 0; k--)
    {
        Villain* vp = m_villains[k];
        if( vp->row() == r && vp->col() == c )
        {
            vp->push( dir );
            if (vp->isDead())
            {
                delete vp;

                // The order of Villain pointers in the m_villains array is
                // irrelevant, so it's easiest to move the last pointer to
                // replace the one pointing to the now-deleted villain.  Since
                // we are traversing the array from last to first, we know this
                // last pointer does not point to a dead villain.

                m_villains[k] = m_villains[m_nVillains-1];
                m_nVillains--;
            }
        }
    }
}


bool Colosseum::isPosInBounds(int r, int c) const
{
    return (r >= 1  &&  r <= m_rows  &&  c >= 1  &&  c <= m_cols);
}

void Colosseum::checkPos(int r, int c) const
{
    if (!isPosInBounds(r, c))
    {
        cout << "***** " << "Invalid colosseum position (" << r << ","
             << c << ")" << endl;
        exit(1);
    }
}

History& Colosseum::history()
{
	return m_hist;
}