/*
ID: makkund2
PROG: transform
LANG: C++                  
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
bool comp(char a[][10],char b[][10],int n)
 {
     int i ,j;
     for(i=0;i<n;i++)
      {
          for(j=0;j<n;j++)
           {
               if(a[i][j]!=b[i][j])
                    return false;
           }
      }
      return true;
 }
int main() {
    ofstream fout ("transform.out");
    ifstream fin ("transform.in");
    int n,i,j;
    fin>>n;
    char a[10][10],b[10][10],c1[10][10],c2[10][10],c3[10][10],c4[10][10],c5[10][10],c6[10][10],c7[10][10];
    for(i=0;i<n;i++)
      {
          for(j=0;j<n;j++)
           {
               fin>>a[i][j];
           }
      }
    for(i=0;i<n;i++)
      {
          for(j=0;j<n;j++)
           {
               fin>>b[i][j];
           }
      }  
    for(i=0;i<n;i++)
     {
         for(j=0;j<n;j++)
          {
              c1[i][j] = a[n-j-1][i];
              c2[i][j] = a[n-1-i][n-1-j];
          }
     }
    for(i=0;i<n;i++)
     {
         for(j=0;j<n;j++)
          {
              c3[i][j] = c2[n-j-1][i];
          }
     }
    for(i=0;i<n;i++)
     {
         for(j=0;j<n;j++)
          {
              c4[i][j] = a[i][n-j-1];
          }
     }
     for(i=0;i<n;i++)
     {
         for(j=0;j<n;j++)
          {
              c5[i][j] = c4[n-j-1][i];
              c6[i][j] = c4[n-1-i][n-1-j];
          }
     }
    for(i=0;i<n;i++)
     {
         for(j=0;j<n;j++)
          {
              c7[i][j] = c6[n-j-1][i];
          }
     }
    if(comp(b,c1,n))
        fout<<1;
    else if(comp(b,c2,n))
        fout<<2;
    else if(comp(b,c3,n))   
        fout<<3;
    else if(comp(b,c4,n))    
        fout<<4;
    else if(comp(b,c5,n))    
        fout<<5;
    else if(comp(b,c6,n))    
        fout<<5;
    else if(comp(b,c7,n))    
        fout<<5;
    else if(comp(b,a,n))    
        fout<<6;
    else
        fout<<7;
    fout<<"\n";    
    return 0;
}