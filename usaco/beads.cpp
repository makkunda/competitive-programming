/*
ID: makkund2
PROG: beads
LANG: C++                  
*/
#include <iostream>
#include <fstream>
#include <string>
int mx(int a,int b)
 {
     if(a>b)
        return a;
     else
        return b;
 }
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
                if(x=='w')
                  {
                      int ct3=0,ct4=0;
                      int j= i;
                      x='r';
                      while(check[j]==x||check[j]=='w')
                       {
                           j++;
                           ct3++;
                       }
                       j=i;
                       x='b';
                       while(check[j]==x||check[j]=='w')
                       {
                           j++;
                           ct4++;
                       }
                       ct1=mx(ct3,ct4);
                  }
               else
               { int j= i;
                while(check[j]==x||check[j]=='w')
                       {
                           j++;
                           ct1++;
                       }
               }       
                x = check[i-1];
                if(x=='w')
                 {
                int ct5=0,ct6=0;
                int j= i-1;
                 x='r';
                while((check[j]==x||check[j]=='w')&&(ct2<(n-ct1)))
                 {
                     j--;
                     ct5++;
                 }
                 j= i-1;
                 x='b';
                while((check[j]==x||check[j]=='w')&&(ct2<(n-ct1)))
                 {
                     j--;
                     ct6++;
                 }
                 ct2=mx(ct5,ct6);
                 }
                else {
                int j= i-1;
                while((check[j]==x||check[j]=='w')&&(ct2<(n-ct1)))
                 {
                     j--;
                     ct2++;
                 }
                } 
                ct=ct1+ct2;
                if(ct>max)
                    max = ct;
            }
       }
    fout <<max<< endl;
    return 0;
}