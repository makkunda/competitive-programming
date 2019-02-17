/*
ID: makkund2
PROG: barn1
LANG: C++                  
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int main() {
    ofstream fout ("barn1.out");
    ifstream fin ("barn1.in");
    int m,s,c,i,x;
   	int stall[200],gap[199];
    fin>>m>>s>>c;
    for(i=0;i<200;i++)
    	stall[i]=0;
    for(i=0;i<c;i++)
    {
    	fin>>stall[i];
    }
    sort(stall,stall+c);
    if(m>=c)
    	fout<<c<<"\n";
    else
    {
    	for(i=0;i<(c-1);i++)
    		 {
    		 	gap[i] = stall[i+1]- stall[i] - 1;
    		 }
    	sort(gap,gap+(c-1));
    	int count = c;
    	int diff = c - m;
    	for(i=0;i<diff;i++)
    	  {
    	  	count = count + gap[i];
    	  }	
    	fout<<count<<"\n";   
    }
    return 0;
}