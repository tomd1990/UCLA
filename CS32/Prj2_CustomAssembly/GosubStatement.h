#ifndef GO_STATEMENT_INCLUDED
#define GO_STATEMENT_INCLUDED

#include "Statement.h"
#include "ProgramState.h"
#include<iostream>
using namespace std;
class GosubStatement: public Statement
{
public:
GosubStatement( int gosub);
virtual void execute(ProgramState * state, std::ostream &outf);

private:
int jumper;
};

GosubStatement::GosubStatement(int gosub)
	:jumper(gosub)
{}

void GosubStatement::execute(ProgramState * state, std::ostream &outf)
{
	if(jumper<1 || jumper>state->numlines())
	{	
		outf<<"Illegal jump instruction"<<endl; exit(1);
	}
	
	int x=state->position()+1;// this is the line thats going into the stack
	state->a.push(x);
	state->jump(jumper);// jumps to this line

}
#endif
