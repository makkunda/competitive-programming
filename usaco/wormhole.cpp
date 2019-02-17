/*
ID: makkund2
PROG: wormhole
LANG: C++                  
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

int main() {
    ofstream fout ("wormhole.out");
    ifstream fin ("wormhole.in");
    int n,i,j,count = 0;
    long long int x[12],y[12];
    bool met[12];
    vector<int> parallel;
    fin>>n;
    for(i=0;i<n;i++)
    {
    	fin>>x[i]>>y[i];
    	met[i] = false;
    }
    for(i=0;i<n;i++)
    	 {
    	 	count = 1;
    	 	if(!met[i]){
    	 	for(j=i+1;j<n;j++)
    	 	{
    	 		if(y[i]==y[j])
    	 		{
    	 			count++;
    	 			met[j] = true;
    	 		}
    	 	}}
    	 	if(count>1)
    	 		parallel.push_back(count);
    	 }
    	 
    return 0;
}