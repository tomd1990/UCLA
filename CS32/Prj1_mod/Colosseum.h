
#include <string>
#include "History.h"
#ifndef COL_INCLUDED
#define COL_INCLUDED
class Player;
class Villain;
class Colosseum
{
  public:
      // Constructor/destructor
    Colosseum(int nRows, int nCols);
    ~Colosseum();
	
      // Accessors
    int     rows() const;
    int     cols() const;
    Player* player() const;
    int     villainCount() const;
    int     getCellStatus(int r, int c) const;
    int     numberOfVillainsAt(int r, int c) const;
    void    display(std::string msg) const;
		History& history();
      // Mutators
    void setCellStatus(int r, int c, int status);
    bool addVillain(int r, int c);
    bool addPlayer(int r, int c);
    void moveVillains();
    void pushAllVillains(int r, int c, int dir); // pushes all villains at [r,c] in the given direction

  private:
	History m_hist;
    int     m_grid[MAXROWS][MAXCOLS];
    int     m_rows;
    int     m_cols;
    Player* m_player;
    Villain* m_villains[MAXVILLAINS];
    int     m_nVillains;
    int     m_turns;

      // Helper functions
    void checkPos(int r, int c) const;
    bool isPosInBounds(int r, int c) const;
};
#endif 