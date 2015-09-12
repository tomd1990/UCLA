// LetStatement.h
//
// CS 32 / Summer 2014
// Project #2: What's Simple Is True
//
// The LetStatement class encapsulates a LET statement in a Facile program.
// A LET statement looks like this:
//
//     LET A 3
//
// Primarily, it consists of two things: a variable name (denoted by a single
// character) and an integer value.  So, a LetStatement object contains a
// character and an integer, which is the important information contained in
// a LET statement.
//
// You'll need to similarly define subclasses for each of the other kinds of
// statements in a Facile program.


#ifndef LET_STATEMENT_INCLUDED
#define LET_STATEMENT_INCLUDED

#include "Statement.h"
#include "ProgramState.h"

class LetStatement: public Statement
{
private:
	char m_variableName;
	int m_value;


public:
	LetStatement(char variableName, int value);
	
	virtual void execute(ProgramState * state, std::ostream &outf);
};

#endif



