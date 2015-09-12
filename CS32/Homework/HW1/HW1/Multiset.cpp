#include "Multiset.h"
#include <string>
#include <iostream>
#include <cassert>

   using namespace std;
   
	Multiset::Multiset()
		
	{ 
		for(int i=0; i<DEFAULT_MAX_ITEMS; i++)
		{check[i]=false;}
		ptr=inv;counter=0; checker=check;
	}

 int  Multiset::count(const ItemType& value) const		
{int i=0;int C=0;
while(i<DEFAULT_MAX_ITEMS)
	{if(*(checker+i)==true && *(ptr+i)==value)
		{C++;}
i++;
	}
return C;
}


  bool Multiset::empty() const//final
 { int i=0;
	 while(i<DEFAULT_MAX_ITEMS) 
	 {	if(*(checker+i)==true)
			{return false;}
	 i++;
	 }
	 return true;
 }

  int Multiset::size() const//final
 {int i=0; int size=0;
  while(i<DEFAULT_MAX_ITEMS) //declared a boolean array that keeps track of empy/ filled states in our type def array
  {	if(*(checker+i)==true)
		{size++;}
  i++;
  }
  return size;
 }

   int Multiset::uniqueSize() const//GOOD
  { int N=0; int D=0; 
  for (int i=0; i<DEFAULT_MAX_ITEMS; i++)
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

  bool Multiset::insert(const ItemType& value)//works
  { if(counter<DEFAULT_MAX_ITEMS)
  {*(ptr+counter)=value; *(checker+counter)=true;counter++; return true;}
  else
	{return false;}
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
	 while(i<DEFAULT_MAX_ITEMS) 
	 {	if(*(checker+i)==true && *(ptr+i)==value)
	 {return true;}
	 i++;
	 }
	 return false;
 }

 int Multiset::get(int i, ItemType& value) const // int i is a unique item
{  int D=0; int N=0; int v=0; int k=0;
	if(uniqueSize()>i	&& i>=0)
	{	
		while (k<DEFAULT_MAX_ITEMS)
       {	if(*(checker+k)==true)
			{for( int j=0; j<k; j++)
				{if(*(ptr+k)==*(ptr+j))
					{D++;}
				
				}

		if(D==0 && v==i)	
	   {	value=*(ptr+k);
		for(int r=0; r<DEFAULT_MAX_ITEMS; r++)
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

void Multiset::swap(Multiset& other)// Im assuming the have the same Default Maximum size
{ ItemType temp[DEFAULT_MAX_ITEMS]; bool tempchek[DEFAULT_MAX_ITEMS]; 
for(int i=0; i<DEFAULT_MAX_ITEMS; i++)
{temp[i]=other.inv[i]; tempchek[i]=other.check[i];}

for(int i=0; i<DEFAULT_MAX_ITEMS; i++)
{other.inv[i]=inv[i]; other.check[i]=check[i];

inv[i]=temp[i]; check[i]=tempchek[i];
}
}