/*
ID: makkund2
PROG: beads
LANG: C++                  
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
   ofstream fout ("beads.out");
   ifstream fin ("beads.in");
    string nc,check;
    int n,max=0,i,ct;
    fin >> n >> nc;
    check = nc + nc+ nc;
    int b=0,w=0,r=0;
    for(i=0;i<n;i++)
     {
        if(nc[i]=='b')
             b++;
        else if(nc[i]=='r')
             r++;
        else
             w++;
     }
     if(((r+w)==n)||((b+w)==n))
             max=n;
     else
       {
           for(i=n;i<2*n;i++)
            {
                ct = 0;
                int ct1=0,ct2=0;
                char x = check[i];
                int j= i;
                while(check[j]==x||check[j]=='w')
                       {
                           j++;
                           ct1++;
                       }
                x = check[i-1];
                j= i-1;
                while((check[j]==x||check[j]=='w')&&(ct2<=(n-ct1)))
                 {
                     j--;
                     ct2++;
                 }
                ct=ct1+ct2;
                if(ct>max)
                    max = ct;
            }
       }
    fout <<max<< endl;
    return 0;
}