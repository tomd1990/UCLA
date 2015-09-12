#ifndef RET_STATEMENT_INCLUDED
#define RET_STATEMENT_INCLUDED

#include "Statement.h"
#include "ProgramState.h"
#include<iostream>
using namespace std;
class ReturnStatement: public Statement
{
public:
virtual void execute(ProgramState * state, std::ostream &outf);
};

void ReturnStatement::execute(ProgramState * state, std::ostream &outf)
{
	if(state->a.empty())
	{
		outf<<"Illegal return statement"<<endl;exit(1);
	}
	int x=state->a.top();
	state->a.pop();
	state->jump(x);

}
#endif
