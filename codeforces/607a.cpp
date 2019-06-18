#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
int n;
vector<int> rev_a;
int limit(int power,int index)
{
	int lo = index;
	int hi = n;
	while(lo<hi)
	{
		int mid = lo + (hi-lo)/2;
		if((rev_a[index]-rev_a[mid])>power)
			hi = mid;
		else
			lo = mid + 1;
	}
	return lo;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector<int> a;
	vector<int> b;
	vector<int> dp;
	int i;
	cin>>n;
	a.resize(n);
	b.resize(n);
	dp.resize(n+1);
	rev_a.resize(n+1);
	vector<pair<int,int> > input;
	input.resize(n);
	for(i=0;i<n;i++)
		{
			int x,y;
			cin>>x>>y;
			input[i].first = x;
			input[i].second = y;
		}
	sort(input.begin(),input.end());
	for(i=0;i<n;i++)
	{
		a[i] = input[i].first;
		b[i] = input[i].second;
	}
	for(i=0;i<n;i++)
		rev_a[i] = a[n-1-i];
	rev_a[n] = -2000000;
	dp[0] = 0;
	for(i=1;i<=n;i++)
	{
		int boundary = limit(b[i-1],n-i);
		dp[i] = 1 + dp[n-boundary];
	}
	int ans = 1;
	for(i=0;i<=n;i++)
	{
		ans = max(ans,dp[i]);
		// cout<<i<<" "<<dp[i]<<endl;
	}
	cout<<n-ans<<endl;

	return 0;
}
