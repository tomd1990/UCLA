#include<iostream>
using namespace std;


   // Return the number of ways that all n2 elements of a2 appear
          // in the n1 element array a1 in the same order (though not
          // necessarily consecutively).  The empty sequence appears in a
          // sequence of length n1 in 1 way, even if n1 is 0.
          // For example, if a1 is the 7 element array
          //    's' 'k' 'c' 'e' 'k' 'c' 'b'
          // then for this value of a2            the function must return
          //    's' 'e' 'c'  		                      1
          //    's' 'c' 'b'                    		      2
          //    'e' 's' 'c'                      	      0
          //    'k' 'c' 'b'                    		      3
        int countIncludes(const char a1[], int n1, const char a2[], int n2)
        {
            if(n2<=0)
				return 1;
			if(n1<=0)
				return 0;
			if(n2!=0 &&n1<=0)
				return 0;

			if(a1[0]==a2[0])
			{
			
				return countIncludes(a1+1,n1-1,a2,n2)+countIncludes(a1+1,n1-1,a2+1,n2-1);
			
			}
			else
				return countIncludes(a1+1,n1-1,a2,n2);

			
        }

		