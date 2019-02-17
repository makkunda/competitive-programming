#include <iostream>
#include <algorithm>
#include <utility>
#include <set>
using namespace std;
int main()
{
	long int n,m,i;
	long int a[100000],b[100000];
	cin>>n>>m;
	for(i=0;i<n;i++)
		cin>>a[i];
	b[n-1]=1;
	set<long int> myset;
	pair<set<long int>::iterator,bool> ret;
	myset.insert(a[n-1]);
	for(i=n-2;i>=0;i--)
	{
		ret = myset.insert(a[i]);
		if(ret.second==false)
		{
			b[i]=b[i+1];
		}
		else
			b[i] = b[i+1] + 1;
	}
	long int x;
	for(i=0;i<m;i++)
	{
		cin>>x;
		cout<<b[x-1]<<"\n";
	}
	return 0;
}