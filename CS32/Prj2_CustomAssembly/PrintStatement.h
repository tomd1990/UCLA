#ifndef Print_STATEMENT_INCLUDED
#define Print_STATEMENT_INCLUDED

#include "Statement.h"
#include "ProgramState.h"
#include <iostream>
using namespace std;
class PrintStatement: public Statement
{
public:
PrintStatement(const char& cha);
virtual void execute(ProgramState * state, std::ostream &outf); // cout/ writing to other files
private:
char prin;

};

PrintStatement::PrintStatement(const char& cha)
	:prin( cha )
{}
void PrintStatement::execute(ProgramState * state, std::ostream &outf)
{
	int i= prin-'A';
	outf<<state->printer(i)<<endl; //this is writing to cout need to use outf!! dont know how
	state->increment();
}

#endif