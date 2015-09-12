#include "newMultiset.h"
#include <iostream>
#include <string>
using namespace std;

Multiset::Multiset(const int& value)
{uniq=value;
length=value;
ptr=new ItemType[value];
checker= new bool[value]; //declared a boolean array that keeps track of empy/ filled states in our type def array
for(int i=0; i<length; i++)
{checker[i]=false;}
counter=0;

}

Multiset::Multiset()
{uniq=DEFAULT_MAX_ITEMS;
length=DEFAULT_MAX_ITEMS;
ptr=new ItemType[DEFAULT_MAX_ITEMS];
checker= new bool[DEFAULT_MAX_ITEMS];
for(int i=0; i<length; i++)
{checker[i]=false;}
counter=0;

}
 void Multiset::stringy()// for testing purposes
{for(int i=0; i<length; i++) 
{cout<<*(ptr+i)<<"";
	if(*(checker+i)==true)
	{cout<<"true";}
}
 }

 int Multiset::size() const //final
 {int i=0; int size=0;
  while(i<length) 
  {	if(*(checker+i)==true)
		{size++;}
  i++;
  }
  return size;
 }

  int Multiset::uniqueSize() const//GOOD
  { int N=0; int D=0; 
  for (int i=0; i<length; i++)
  {		if(*(checker+i)==true)
			{for( int j=0; j<i; j++)
				{if(*(ptr+i)==*(ptr+j))
					{D++;}
				
				}
		if(D==0)
		{N++;}
			}
  D=0;
  }
  return N;
  }
 
  bool Multiset::insert(const ItemType& value)
  {      int c=0; int d=0; 
	  for(int i=0; i<length; i++)
	      { if(*(ptr+i)==value)
	              {d++;}
		  }
	 
	  if(d==0)
	 {c++;}

if(uniqueSize()+c <=uniq)
{*(ptr+counter)=value; *(checker+counter)=true;counter++; 
if(counter==length)
{      
	
	ItemType *rep=new ItemType[2*length];
	bool *repcheck=new bool[2*length];
	for(int i=0; i<2*length; i++)
{repcheck[i]=false;}
	
	for(int j=0; j<counter; j++)
	{ *(rep+j)=*(ptr+j);
		*(repcheck+j)=*(checker+j); 
	}
	
	delete[]ptr;
	delete[]checker;

	ptr=rep;
	checker=repcheck;
	length*=2;
}
return true;
}

else
{;return false;}

 }
	
 int Multiset::erase(const ItemType& value)//good to go
  {int i=0; int j=0; 
  while(i<counter)
  {		 if(*(ptr+i)==value)
		{while(i+j+1<=counter)
			{*(ptr+i+j)=*(ptr+i+j+1); *(checker+i+j)=*(checker+i+j+1); j++;
			
			}
		*(checker+i+j+1)=false; counter--;return 1;
		}
  i++;
  }
  return 0;
  }

  int Multiset::eraseAll(const ItemType& value)
{int n=count(value); int c=0; 
 
	for(int i=0; i<n; i++)
		{c=c+erase(value);}
	return c;
 }

   bool Multiset:: contains(const ItemType& value) const
{int i=0;
	 while(i<length) 
	 {	if(*(checker+i)==true && *(ptr+i)==value)
	 {return true;}
	 i++;
	 }
	 return false;
 }

 int  Multiset::count(const ItemType& value) const		
{int i=0;int C=0;
while(i<length)
	{if(*(checker+i)==true && *(ptr+i)==value)
		{C++;}
i++;
	}
return C;
}

  int Multiset::get(int i, ItemType& value) const // int i is a unique item
{  int D=0; int N=0; int v=0; int k=0;
	if(uniqueSize()>i	&& i>=0)
	{	
		while (k<length)
       {	if(*(checker+k)==true)
			{for( int j=0; j<k; j++)
				{if(*(ptr+k)==*(ptr+j))
					{D++;}
				
				}

		if(D==0 && v==i)	
	   {	value=*(ptr+k);
		for(int r=0; r<length; r++)
			{if(*(ptr+r)==value)
				{N++;}
			}
		return N;
	   }
		if(D==0 && v!=i)
		{ v++;}
			}
  D=0; k++;
		}
		return 0;
	}
	else
		return 0;
}

 Multiset::Multiset(const Multiset& copy)
 {  length =copy.length; uniq=copy.uniq; counter=copy.counter;
 ptr=new ItemType[length];
 checker=new bool[length];
 for(int i=0; i<length; i++)
 {ptr[i]=copy.ptr[i];
 checker[i]=copy.checker[i];
 }
 }

 Multiset& Multiset ::operator=(const Multiset& other)
 {delete[] ptr; delete[] checker; counter=other.counter; uniq=other.uniq; length=other.length;
 ptr=new ItemType[length];
 checker=new bool[length];
  for(int i=0; i<length; i++)
 {ptr[i]=other.ptr[i];
 checker[i]=other.checker[i];
 }
  return *this;
 }

 void Multiset::swap(Multiset& other)
 { Multiset c=other;
 other=*this;
 *this=c;
 }



 Multiset::~Multiset()
 { delete[]ptr;
	delete []checker;
 }

