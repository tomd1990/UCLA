#ifndef SUB_STATEMENT_INCLUDED
#define SUB_STATEMENT_INCLUDED

#include "Statement.h"
#include "ProgramState.h"
class SubStatement: public Statement
{
public:
SubStatement(char var, int amo);
virtual void execute(ProgramState * state, std::ostream &outf);

private:
char variable; int subber;

};

SubStatement::SubStatement(char var, int amo)
	:variable(var), subber(amo)
{
}

void SubStatement::execute(ProgramState * state, std::ostream &outf)
{
	int i=variable-'A';
	int x=state->printer(i)-subber;
	state->update(variable, x);
	state->increment();
}




#endif