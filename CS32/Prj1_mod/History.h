#ifndef HIS_INCLUDED
#define HIS_INCLUDED
#include "globals.h"
class History
	{
	  public:
	    History(int nRows, int nCols);
	    bool record(int r, int c);
	    void display() const;
	private:
		int monitor[MAXROWS][MAXCOLS]; int ROWS; int COLS;
	};
#endif 