#include "Player.h"
#include "Colosseum.h"
#include <iostream>
using namespace std;
///////////////////////////////////////////////////////////////////////////
//  Player implementation
///////////////////////////////////////////////////////////////////////////

Player::Player(Colosseum* colosseum, int r, int c)
{
    if (colosseum == NULL)
    {
        cout << "***** The player must be created in some Colosseum!" << endl;
        exit(1);
    }
    if (r < 1  ||  r > colosseum->rows()  ||  c < 1  ||  c > colosseum->cols())
    {
        cout << "**** Player created with invalid coordinates (" << r
             << "," << c << ")!" << endl;
        exit(1);
    }
    m_colosseum = colosseum;
    m_row = r;
    m_col = c;
    m_dead = false;
}

int Player::row() const
{
    return m_row;
}

int Player::col() const
{
    return m_col;
}

string Player::push()
{
    m_colosseum->pushAllVillains(m_row - 1, m_col, NORTH);
    m_colosseum->pushAllVillains(m_row + 1, m_col, SOUTH);
    m_colosseum->pushAllVillains(m_row, m_col + 1, EAST);
    m_colosseum->pushAllVillains(m_row, m_col - 1, WEST);
	m_colosseum->history().record(m_row,m_col);

    return "Player pushed.";
}

string Player::move(int dir)
{
    if (attemptMove(*m_colosseum, dir, m_row, m_col))
    {
        if (m_colosseum->numberOfVillainsAt(m_row, m_col) > 0)
        {
            setDead();
            return "Player walked into a villain and died.";
        }
        string msg = "Player moved ";
        switch (dir)
        {
          case NORTH: msg += "north"; break;
          case EAST:  msg += "east";  break;
          case SOUTH: msg += "south"; break;
          case WEST:  msg += "west";  break;
        }
		m_colosseum->history().record(m_row,m_col);
        msg += ".";
        return msg;
    }
    else
     m_colosseum->history().record(m_row,m_col);   return "Player couldn't move; player stands.";
}

bool Player::isDead() const
{
    return m_dead;
}

void Player::setDead()
{
    m_dead = true;
}