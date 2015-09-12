#ifndef MULT_STATEMENT_INCLUDED
#define MULT_STATEMENT_INCLUDED

#include "Statement.h"
#include "ProgramState.h"
class MultStatement: public Statement
{
public:
MultStatement(char var, int amo);
virtual void execute(ProgramState * state, std::ostream &outf);

private:
char variable; int multy;

};

MultStatement::MultStatement(char var, int amo)
	:variable(var), multy(amo)
{
}

void MultStatement::execute(ProgramState * state, std::ostream &outf)
{
	int i=variable-'A';
	int x=state->printer(i)*multy;
	state->update(variable, x);
	state->increment();
}

#endif

