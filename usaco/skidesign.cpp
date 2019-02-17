/*
ID: makkund2
PROG: skidesign
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
    ofstream fout ("skidesign.out");
    ifstream fin ("skidesign.in");
    int n,i,j;
    fin>>n;
    int hght[1000];

    for(i=0;i<n;i++)
    {
    	fin>>hght[i];
    }
    sort(hght,hght+n);
    if(hght[n-1] - hght[0] <= 17)
    	fout<<0<<"\n";
    else
    {
    	long long int cost = 1000000000;
    	long long int tcost=0;
    	for(i=0;i<=83;i++)
    	{
    		tcost = 0;
    		int hmax = i+17;
    		for(j=0;j<n;j++)
    		{
    			if(hght[j]<i)
    				tcost = tcost + (i-hght[j])*(i-hght[j]);
    			else if(hght[j]>hmax)
    				tcost = tcost + (hmax-hght[j])*(hmax-hght[j]);
    		}
    		if(tcost<cost)
    			cost = tcost;
    	}
    	fout<<cost<<"\n";
    }

    return 0;
}