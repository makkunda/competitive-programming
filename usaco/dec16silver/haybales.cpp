#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	ifstream fin("haybales.in");
	ofstream fout("haybales.out");
	long long int a,b;
	vector<long long int > x;
	vector<long long int>:: iterator low,up;
	long int n,q,i;
	fin>>n>>q;
	x.resize(n+2);
	x[0]=-1;x[n+1]=1e9 + 1;
	for(i=0;i<n;i++)
	     fin>>x[i+1];
	sort(x.begin(),x.end());
	for(i=0;i<q;i++)
	  {
	  	fin>>a>>b;
	  	low = lower_bound(x.begin(),x.end(),a);
	  	up = upper_bound(x.begin(),x.end(),b);
	  	long int ans = (long int)(up - low) ;
	  	fout<<ans<<"\n";
	  }      
	return 0;
}