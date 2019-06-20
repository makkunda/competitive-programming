#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	vector<int> t;
	cin>>n>>m;
	t.resize(n);
	int i;
	for(i=0;i<n;i++)
		cin>>t[i];
	cout<<0<<" ";
	for(i=1;i<n;i++)
	{
		vector<int> sub;
		sub.resize(i);
		int j;
		for(j=0;j<i;j++)
			sub[j] = t[j];
		sort(sub.begin(),sub.end());
		int diff = m - t[i];
		int cursum = 0;
		int ans = -1;
		for(j=0;j<i;j++)
		{
			cursum = cursum + sub[j];
			if(cursum>diff)
			{
				ans = j;
				break;
			}
		}
		if(ans==-1)
			ans = i;
		cout<<i-ans<<" ";
	}
	return 0;
}
