///////////////////////////////////////////////////////////////////////////
//  Villain implementation
///////////////////////////////////////////////////////////////////////////
#include "Villain.h"
#include "Colosseum.h"
#include <iostream>
using namespace std;
Villain::Villain(Colosseum* colosseum, int r, int c)
{
    if (colosseum == NULL)
    {
        cout << "***** A villain must be created in some Colosseum!" << endl;
        exit(1);
    }
    if (r < 1  ||  r > colosseum->rows()  ||  c < 1  ||  c > colosseum->cols())
    {
        cout << "***** Villain created with invalid coordinates (" << r << ","
             << c << ")!" << endl;
        exit(1);
    }
    m_colosseum = colosseum;
    m_row = r;
    m_col = c;
    m_dead = false;
}

int Villain::row() const
{
    return m_row;
}

int Villain::col() const
{
    return m_col;
}

bool Villain::isDead() const
{
    return m_dead;
}

void Villain::move()
{
      // Attempt to move in a random direction; if we can't move, don't move
    attemptMove(*m_colosseum, randInt(0, NUMDIRS-1), m_row, m_col);
}

void Villain::setDead()
{
    m_dead = true;
}

void Villain::push(int dir)
{
    // pushes this villain in this direction.
    switch(dir)
    {
    	case NORTH: m_row--; break;
    	case SOUTH: m_row++; break;
    	case EAST:  m_col++; break;
    	case WEST:  m_col--; break;
    }
    if (m_row < 1 || m_row > m_colosseum->rows() || m_col < 1 || m_col > m_colosseum->cols() )
    {
    	setDead();
    }
}