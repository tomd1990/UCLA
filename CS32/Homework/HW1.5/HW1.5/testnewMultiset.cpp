#include "newMultiset.h"
        #include <string>
        #include <iostream>
        #include <cassert>
        using namespace std;

   

        int main()
        {
         
        Multiset a(4);
 a.insert(56);a.insert(56);a.insert(54);a.insert(54);a.insert(54);a.insert(1);a.insert(2);a.insert(3);a.insert(2);a.insert(2);
 Multiset b(4); b.insert(1); b.insert(8);
 for (int k = 0; k < a.uniqueSize(); k++)
    {
        unsigned long x;
        int n = a.get(k, x);
        cout << x << " occurs " << n << " times." << endl;
  }

 
 b.swap(a);
 for (int k = 0; k < a.uniqueSize(); k++)
    {
        unsigned long y;
        int m = a.get(k, y);
        cout << y << " occurs " << m << " times." << endl;
  }
 b.eraseAll(2);

 for (int k = 0; k < b.uniqueSize(); k++)
    {
        unsigned long z;
        int p = b.get(k, z);
        cout << z << " occurs " << p << " times." << endl;
  }
 cout<<"size is "<<b.size()<<'\n';
cout<<"unique size is "<<b.uniqueSize()<<'\n';



        
        }