/*
ID: makkund2
PROG: namenum
LANG: C++                  
*/
#include <iostream>
#include <fstream>
#include <string>
int d(char a)
 {
     if(a=='A'||a=='B'||a=='C')
          return 2;
     else if(a=='D'||a=='E'||a=='F')
          return 3;
     else if(a=='G'||a=='H'||a=='I')
          return 4; 
     else if(a=='J'||a=='K'||a=='L')
          return 5; 
     else if(a=='M'||a=='N'||a=='O')
          return 6; 
     else if(a=='P'||a=='R'||a=='S')
          return 7;   
     else if(a=='T'||a=='U'||a=='V')
          return 8; 
     else if(a=='W'||a=='X'||a=='Y')
          return 9;           
 }
using namespace std;

int main() {
    ofstream fout ("namenum.out");
    ifstream fin ("namenum.in");
    ifstream fn("dict.txt");
    long long int ln;
    fin >>ln;
    string lname[5000];
    long long int lnum[5000],ct=0;
    int n=0,i,j;
    while(fn>>lname[n++]);
    for(i=0;i<n;i++)
     {
         int x = lname[i].length();
         long long int y = 0;
         for(j=0;j<x;j++)
          {
              y =y*10;
              y = y + d(lname[i][j]);
          }
          lnum[i]=y;
     }
    for(i=0;i<n;i++)
     {
         if(lnum[i]==ln)
            {
                fout<<lname[i]<<endl;
                ct++;
            }
     }
     if(ct==0)
        fout<<"NONE"<<endl;
    
    return 0;
}