#ifndef END_STATEMENT_INCLUDED
#define END_STATEMENT_INCLUDED

#include "Statement.h"
#include "ProgramState.h"
#include <vector>
#include <iostream>
using namespace std;
class EndStatement: public Statement
{

public:	
	EndStatement(vector<Statement *> & program, ProgramState *state);
	virtual void execute(ProgramState * state, std::ostream &outf)
	{exit(1);}
};

EndStatement::EndStatement(vector<Statement *> & program, ProgramState *state)
{for(int i=1; i<program.size(); i++)
	{	if(program[i]==nullptr)
	{}
	else
	{ delete program[i];}
	}
delete state;
}
#endif
