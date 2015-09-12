#include "Game.h"
#include <cstdlib>
#include <ctime>
using namespace std;

const int TANK_WIDTH  = 10;
const int TANK_HEIGHT = 18;

int main()
{
    srand(static_cast<unsigned int>(time(NULL)));

    Game g(TANK_WIDTH, TANK_HEIGHT);
    g.play();
}
