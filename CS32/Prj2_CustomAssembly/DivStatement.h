#ifndef DIV_STATEMENT_INCLUDED
#define DIV_STATEMENT_INCLUDED

#include "Statement.h"
#include "ProgramState.h"
#include<iostream>
using namespace std;
class DivStatement: public Statement
{
public:
DivStatement(char var, int amo);
virtual void execute(ProgramState * state, std::ostream &outf);

private:
char variable; int diver;

};

DivStatement::DivStatement(char var, int amo)
	:variable(var), diver(amo)
{
}

void DivStatement::execute(ProgramState * state, std::ostream &outf)
{	if(diver==0)
		{outf<<"Divide by zero exception"<<endl;exit(1);}
	int i=variable-'A';
	int x=state->printer(i)/diver;
	state->update(variable, x);
	state->increment();
}

#endif
