/*
ID: makkund2
PROG: milk
LANG: C++                  
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

int main() {
    ofstream fout ("milk.out");
    ifstream fin ("milk.in");
    int m,i,j;
    long long int n;
    long int x,y;
    long long int cost = 0;
    long long int temp;
    int price[5000],ptemp;
    long int amount[5000],atemp;
    fin>>n>>m;
    for(i=0;i<m;i++)
    	{ fin>>price[i]>>amount[i];
    	}	
    for(i=0;i<m;i++)
        {
        	for(j=0;j<(m-1);j++)
        	{
        		if(price[j]>price[j+1])
        		{
        			ptemp = price[j];atemp = amount[j];
        			price[j] = price[j+1];amount[j] = amount[j+1];
        			price[j+1] = ptemp;amount[j+1] = atemp;
        		}
        	}
        }
    if(n==0 || m==0)
        fout<<0<<"\n";
    else
      {
      	temp = n;
      	for(i=0;i<m;i++)
      	{
      		if(temp>=amount[i])
      		{
      			cost = cost + amount[i]*price[i];
      			temp = temp - amount[i];
      		}
      		else
      		{
      			cost = cost + temp*price[i];
      			break;
      		}
      	}
      	fout<<cost<<"\n";
      }        	
    return 0;
}