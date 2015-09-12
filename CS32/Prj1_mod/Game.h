#ifndef GAME_INCLUDED
#define GAME_INCLUDED
#include <string>
class Colosseum; 
class Game
{
  public:
      // Constructor/destructor
    Game(int rows, int cols, int nVillains);
    ~Game();

      // Mutators
    void play();

  private:
    Colosseum* m_colosseum;

      // Helper functions
    std::string takePlayerTurn();
};
#endif