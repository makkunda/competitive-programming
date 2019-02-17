/*
ID: makkund2
PROG: dualpal
LANG: C++                  
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream fout ("dualpal.out");
    ifstream fin ("dualpal.in");
    long int n, s;
    long int i;
    fin >>n>>s;
    i=s+1;
    int ct=0;
    while(ct<n)
     {
        int ct1=0;
        for(int j=2;j<=10;j++)
         {
             long long int m = i;
             string num;
             while(m>0)
              {
                  int x = m%j;
                  m =m/j;
                  num = num + (char)(x+48);
              }
              int len = num.length();
              bool ch = true; 
              for(int g = 0;g<len;g++)
                {
                    if(num[g]!=num[len-1-g])
                         {
                             ch = false;
                             break;
                         }
                }
              if(ch)
                 ct1++;
          }
        if(ct1>=2)
         {
             fout<<i<<endl;
             ct++;
         }     
        i++;  
     }
    return 0;
}