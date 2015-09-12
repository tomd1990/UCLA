#ifndef RANDPIECETYPE_INCLUDED
#define RANDPIECETYPE_INCLUDED

#include <cstdlib>

enum PieceType {
    PIECE_I, PIECE_L, PIECE_J, PIECE_T, PIECE_O, PIECE_S, PIECE_Z,PIECE_CRAZY, PIECE_FOAM,
    PIECE_VAPOR   /*NUM_PIECE_TYPES*/
};

static PieceType randPieceType()
{
    return(static_cast<PieceType>(std::rand() % 10));
}

#endif // RANDPIECETYPE_INCLUDED
