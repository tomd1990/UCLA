#include<iostream>
using namespace std;



// Return true if any of the chars in the array is lowercase, false
          // otherwise.
        bool anyLowercase(const char a[], int n)
        {
			if (n<=0)
			{return false;}
		
			if(isupper(*a)==0)
				return true;
			else
				 return anyLowercase(a+1, n-1); 

        }

          // Return the number of lowercase chars in the array.
        int countLowercase(const char a[], int n)
        { 

          if (n<=0)
			{return 0;}
		  
		  if(isupper(*a)==0)
		  {return 1+countLowercase(a+1, n-1);}
		
		  return countLowercase(a+1, n-1);
        }

          // Return the subscript of the first lowercase char in the array.
          // If no element is lowercase, return -1.
        int firstEmpty(const char a[], int n)
        {	
			
			if(n<=0)
			{return -1;}
				
			if(isupper(*a)==0)
			{return 0;}


		int x=firstEmpty(a+1,n-1); 
		if(x==-1)
		{return -1;}
		else
		return 1+firstEmpty(a+1,n-1);

        }

          // Return the subscript of the least char in the array (i.e.,
          // the smallest subscript m such that there is no k for which
          // a[k] < a[m].)  If the array has no elements to examine, return -1.
        int indexOfLeast(const char a[], int n)
        { 
           if(n<=0)
		   {return -1;}

			if(a==a+n-1)
			{return 0;}
		  

		   if(a[0]<=a[n-1])
		   {  return indexOfLeast(a,n-1);}
		   else
		   { return 1+indexOfLeast(a+1,n-1);}

   
        }

		