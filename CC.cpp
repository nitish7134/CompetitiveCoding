#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
   int t;
   cin >> t;
   cin.ignore();
   for (int i = 0; i < t; i++)
   {
      string s;   

      getline(cin, s);
      int n = s.length();
      int a[n];
      for (int j = 0; j < n; j++)
      {
         if (isupper(s[j]))
            cout << (int(s[j]) - 64);
         else if (islower(s[j]))
            cout << (int(s[j]) - 96);
         else
            cout << '$';
      }
      cout << endl;
   }
   return 0;
}