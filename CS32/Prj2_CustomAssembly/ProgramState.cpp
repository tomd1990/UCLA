#include"ProgramState.h"
#include<iostream>
using namespace std;
//
void ProgramState::update(const char& name,const int& value)
{
	int i=name-'A';
	 val[i]=value;
	

}

bool ProgramState::increment()
{

if(counter>m_numLines)//possible error
	return false;
else
counter=counter+1;return true;
} 

int ProgramState::printer(const int& x)
{
	//if(x>=0 && x<26)
	 return val[x];

}

int ProgramState::numlines()
{
	return m_numLines;
}

void ProgramState::jump(int line)
{
	counter=line; //consider line ordering

}

ProgramState::ProgramState(int numLines)
{
	m_numLines=numLines; counter=1;

	for(int i=0; i<26; i++)
	{val[i]=0;}
}

int ProgramState::position()
{
	return counter;
}

