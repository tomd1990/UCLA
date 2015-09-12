#ifndef IF_STATEMENT_INCLUDED
#define IF_STATEMENT_INCLUDED
#include <string>
#include "Statement.h"
#include "ProgramState.h"
#include<iostream>
using namespace std;
class IfStatement: public Statement
{
public:
IfStatement(char var, std::string oper, int compare, int linenum);
virtual void execute(ProgramState * state, std::ostream &outf);

private:
char variable; int comparing; int linenumber; string operator1;

};

IfStatement::IfStatement(char var, std::string oper, int compare, int linenum)
	:variable(var), operator1(oper),comparing(compare), linenumber(linenum)
{
}

void IfStatement::execute(ProgramState * state, std::ostream &outf)
{//=, <>, <, <=, >, >= account for case where operator is none of these **line numbering
	if(linenumber<1 || linenumber>state->numlines())
	{	
		outf<<"Illegal jump instruction"<<endl; exit(1);
	}
	
	
	int i=variable-'A';
	int x=state->printer(i);
	if(operator1=="<>")
	{
		if(x!=comparing)
		{state->jump(linenumber);return;}//change incremen
	}

	if(operator1=="=")
	{
		if(x==comparing)
		{state->jump(linenumber);return;}
	}

	if(operator1=="<")
	{
		if(x<comparing)
		{state->jump(linenumber);return;}
	
	}

	if(operator1=="<=")
	{
		if(x<=comparing)
		{state->jump(linenumber);return;}

	}

	if(operator1==">")
	{
		if(x>comparing)
		{state->jump(linenumber);return;}
	}

	if(operator1==">=")
	{
		if(x>=comparing)
		{state->jump(linenumber);return;}
	}
	state->increment();
}



#endif