#ifndef ADD_STATEMENT_INCLUDED
#define ADD_STATEMENT_INCLUDED

#include "Statement.h"
#include "ProgramState.h"
class AddStatement: public Statement
{
public:
AddStatement(char var, int amo);
virtual void execute(ProgramState * state, std::ostream &outf);

private:
char variable; int adder;

};

AddStatement::AddStatement(char var, int amo)
	:variable(var), adder(amo)
{
}

void AddStatement::execute(ProgramState * state, std::ostream &outf)
{
	int i=variable-'A';
	int x=state->printer(i)+adder;
	state->update(variable, x);
	state->increment();
}



#endif