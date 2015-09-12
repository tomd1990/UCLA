// LetStatement.cpp:
#include "LetStatement.h"
using namespace std;

LetStatement::LetStatement(char variableName, int value)
	: m_variableName( variableName ), m_value( value )
{}


// The LetStatement version of execute() should make two changes to the
// state of the program:
//
//    * set the value of the appropriate variable
//    * increment the program counter
void LetStatement::execute(ProgramState * state, std::ostream &outf)
{
	state->update(this->m_variableName, this->m_value);
	// TODO
	state->increment();

}

