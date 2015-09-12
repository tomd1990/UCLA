#include <iostream>
#include <string>
using namespace std;

class Highlight
{
public:
	Highlight(string x):name(x){}
	 virtual string type ()const = 0;
	 void star() const {cout<< name;}
	 virtual void commentary() const =0;
private:
	string name;
};

class PassingPlay: public Highlight
{
public:
	PassingPlay(string name, int distance):Highlight(name), m_yards(distance) {}
	virtual string type()const {return "Passing Play";}
	virtual void commentary() const {cout<< "complete for "<<m_yards<<" yards!";}
private:
	int m_yards;
};

class RunningPlay: public Highlight
{
public:
	RunningPlay(string name): Highlight(name) {}
	virtual string type()const{return"Running Play";}
	virtual void commentary() const {cout<<"that will keep the defense honest!";}
};

class Interception: public Highlight
{
public:
	Interception(string name, bool x): Highlight(name), truth(x){}
	virtual string type()const{return "Interception";}
	void commentary() const
	{
		if(truth)
		{cout<<"Good for a score!";}
		else
		{cout<<"That will change the game!";}
	}
private:
	bool truth;
};

