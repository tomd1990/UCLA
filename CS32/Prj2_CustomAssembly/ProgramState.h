// ProgramState.h
//
// CS 32 / Summer 2014
// Project #2: What's Simple Is True
//
// The ProgramState class encapsulates the state of an executing Facile
// program.  The state of a Facile program consists of three parts:
//
//    * The program counter, which specifies the line number of the
//      statement that will execute next.
//    * An array of 26 integers, holding the current values of the 26
//      variables.
//    * A stack of integers, which is used to hold return lines for GOSUB
//      statements.
//
// I've provided you a start on this class, but you'll need to add methods
// to it as you go along.  In particular, you'll need methods to access and
// modify the state; these methods will be called primarily by the various
// execute() methods in the Statement subclasses, to allow the execution of
// a statement to change the state of a program.  For example, executing a
// GOTO statement will cause the program counter to be changed.

#ifndef PROGRAM_STATE_INCLUDED
#define PROGRAM_STATE_INCLUDED

#include "Stack.h"

class ProgramState
{
public:
	ProgramState(int numLines);
	void update(const char& name,const int& value);//updates value in array
	bool increment();// increments counter
	int numlines();
	void jump(int line);//changes poition of counter
	int position();// returns the position/ counter
	int printer(const int& x);
	 Stack<int> a;

private:
	int m_numLines; int val[26]; int counter;
};

#endif



