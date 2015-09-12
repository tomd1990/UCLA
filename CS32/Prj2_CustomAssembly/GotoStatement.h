#ifndef GOT_STATEMENT_INCLUDED
#define GOT_STATEMENT_INCLUDED

#include "Statement.h"
#include "ProgramState.h"
#include<iostream>
using namespace std;
class GotoStatement: public Statement
{
public:
GotoStatement( int gosub);
virtual void execute(ProgramState * state, std::ostream &outf);

private:
int jumper;
};

GotoStatement::GotoStatement(int gosub)
	:jumper(gosub)
{}

void GotoStatement::execute(ProgramState * state, std::ostream &outf)
{
	if(jumper<1 || jumper>state->numlines())
	{	
		outf<<"Illegal jump instruction"<<endl; exit(1);
	}
	
	
	state->jump(jumper);// jumps to this line

}
#endif
