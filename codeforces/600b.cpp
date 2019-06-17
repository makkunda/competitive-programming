#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define lli long long int
vector<lli> a;
int n;
lli get_ans(lli x)
{
	int hi = n;
	int lo = 0;
	int mid;
	while(lo<hi)
	{
		mid =lo + (hi-lo)/2;
		if(a[mid]<=x)
			lo=mid+1;
		else
			hi=mid;
	}
	return lo;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int m;
	vector<lli> b;
	int i;
	cin>>n>>m;
	a.resize(n);
	b.resize(m);
	for(i=0;i<n;i++)
		cin>>a[i];
	for(i=0;i<m;i++)
		cin>>b[i];
	a.push_back(2000000000);
	sort(a.begin(),a.end());
	for(i=0;i<m;i++)
		cout<<get_ans(b[i])<<" ";
	return 0;
}
