#ifndef PLAYER_INCLUDED
#define PLAYER_INCLUDED
#include <string>
using namespace std;
class Colosseum;
class Player
{
  public:
      // Constructor
    Player(Colosseum *colosseum, int r, int c);

      // Accessors
    int  row() const;
    int  col() const;
    bool isDead() const;

      // Mutators
    string move(int dir);
    string push();
    void   setDead();

  private:
    Colosseum* m_colosseum;
    int    m_row;
    int    m_col;
    bool   m_dead;
};
#endif