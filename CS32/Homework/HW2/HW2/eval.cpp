#include<stack>
#include<string>
#include<iostream>
using namespace std;

bool balanced(std::string expr)
{stack<char> a; 
for(int i=0; i<expr.size(); i++)
{
	if(expr[i]=='(' ||expr[i]=='[' ||expr[i]=='{')
	{a.push(expr[i]);}
	
	if(a.empty() && (expr[i]==')' || expr[i]==']' || expr[i]=='}'))
	{return false;}

	if(!a.empty())
	{ char x=a.top();
	if(x=='(' && expr[i]==')')
	{a.pop(); }

	if(x=='[' && expr[i]==']')
	{a.pop(); }

	if(x=='{' && expr[i]=='}')
	{a.pop(); }
	}
}
if(a.empty())
	return true;
else
	return false;

}

int main()
{
	if(balanced("([)]"))
		cout<<"balanced"<<endl;
	else
		cout<<"NO"<<endl;

}