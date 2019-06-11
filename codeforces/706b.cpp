#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> x;
int bin_srch(int q)
{
	int high = x.size();
	int low = 0;
	int mid;
	while(high>low)
	{
		mid = (high+low)/2;
		if(x[mid]<=q)
			low = mid+1;
		else
			high = mid;
	}
	return low;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	
	x.resize(n+2);
	int i,j;
	x[0] = -1;
	for(i=1;i<=n;i++)
		cin>>x[i];
	x[n+1] = 100001;
	sort(x.begin(),x.end());
	int query;
	int q;
	cin>>q;
	
	for(i=0;i<q;i++)
	{
		cin>>query;
		query = min(query,100000);
		int ans = bin_srch(query);
		cout<<ans-1<<'\n';
	}
	return 0;
}
