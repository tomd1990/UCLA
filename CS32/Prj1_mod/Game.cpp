#include "globals.h"
#include "Player.h"
#include "Villain.h"
#include "Colosseum.h"
#include "Game.h"
#include <iostream>
using namespace std;
///////////////////////////////////////////////////////////////////////////
//  Game implementation
///////////////////////////////////////////////////////////////////////////

Game::Game(int rows, int cols, int nVillains)
{
    if (nVillains < 0  ||  nVillains > MAXVILLAINS)
    {
        cout << "***** Game created with invalid number of villains:  "
             << nVillains << endl;
        exit(1);
    }
    int nEmpty = rows * cols - nVillains - 1;  // 1 for Player
    if (nEmpty < 0)
    {
        cout << "***** Game created with a " << rows << " by "
             << cols << " colosseum, which is too small too hold a player and "
             << nVillains << " villains!" << endl;
        exit(1);
    }

      // Create Colosseum
    m_colosseum = new Colosseum(rows, cols);

      // Add player
    int rPlayer;
    int cPlayer;
    do
    {
        rPlayer = randInt(1, rows);
        cPlayer = randInt(1, cols);
    } while (m_colosseum->getCellStatus(rPlayer, cPlayer) != EMPTY);
    m_colosseum->addPlayer(rPlayer, cPlayer);

      // Populate with villains
    while (nVillains > 0)
    {
        int r = randInt(1, rows);
        int c = randInt(1, cols);
        if (r == rPlayer && c == cPlayer)
            continue;
        m_colosseum->addVillain(r, c);
        nVillains--;
    }
}

Game::~Game()
{
    delete m_colosseum;
}

string Game::takePlayerTurn()
{
    for (;;)
    {
        cout << "Your move (n/e/s/w/p/h or nothing): ";
        string playerMove;
        getline(cin, playerMove);
		if (playerMove=="h")
		{m_colosseum->history().display();
		   cout << "Press enter to continue.";
			    cin.ignore(10000,'\n');
		m_colosseum->display("");}
        Player* player = m_colosseum->player();
        int dir;

        if (playerMove.size() == 0)
        {
            if (recommendMove(*m_colosseum, player->row(), player->col(), dir))
                return player->move(dir);
            else
                return player->push();
        }
        else if (playerMove.size() == 1)
        {
            if (tolower(playerMove[0]) == 'p')
                return player->push();
            else if (charToDir(playerMove[0], dir))
                return player->move(dir);
        }
        cout << "Player move must be nothing, or 1 character n/e/s/w/p." << endl;
    }
}

void Game::play()
{
    m_colosseum->display("");
    while ( ! m_colosseum->player()->isDead()  &&  m_colosseum->villainCount() > 0)
    {
        string msg = takePlayerTurn();
        Player* player = m_colosseum->player();
        if (player->isDead())
            break;
        m_colosseum->moveVillains();
        m_colosseum->display(msg);
    }
    if (m_colosseum->player()->isDead())
        cout << "You lose." << endl;
    else
        cout << "You win." << endl;
}