#include <iostream>
#include <vector>
#include <map>
#include <utility>
#define mp make_pair
#define pb push_back
using namespace std;
int main()
{
	int n,i,j,k;
	cin>>n;
	map<pair<int,int>,int> ourmap;
	int x[1000];
	int y[1000];
	int a[1000];
	int b[1000];
	for(i=0;i<n;i++)
		cin>>x[i]>>y[i];
	for(i=0;i<n;i++)
		cin>>a[i]>>b[i];
	map<pair<int,int>,int>::iterator it;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			int x1 = x[i] + a[j];
			int y1 = y[i] + b[j];
			pair<int,int> ky(x1,y1);
			it = ourmap.find(ky);
			if(it!=ourmap.end())
				ourmap[ky] = ourmap[ky] + 1;
			else
				ourmap[ky] = 1;
		}
	}
	for(it=ourmap.begin();it!=ourmap.end();it++)
	{
		if(it->second>=n)
		{
			cout<<it->first.first<<" "<<it->first.second<<endl;
			break;
		}
	}
	return 0;
}