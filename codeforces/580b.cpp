#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#define lli long long int
using namespace std;
long long int n,d;
vector<lli> money;
vector<lli> prefix_friendship;
lli include_friend_i(int q)
{
	int hi = n+1;
	int lo = q;
	int mid;
	while(lo<hi)
	{
		mid = lo + (hi-lo)/2;
		if((money[mid]-money[q])<d)
			lo = mid + 1;
		else
			hi = mid;
	}
	lli ans = prefix_friendship[lo-1]-prefix_friendship[q-1];
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>d;
	lli fs,snd;
	vector<pair<lli,lli> > data;
	int i;
	for(i=0;i<n;i++)
	{
		cin>>fs>>snd;
		data.push_back(make_pair(fs,snd));
	}
	data.push_back(make_pair(2000000001,0));
	sort(data.begin(),data.end());
	money.push_back(0);
	prefix_friendship.push_back(0);
	for(i=0;i<=n;i++)
	{
		lli cur_pre = prefix_friendship[i] + data[i].second;
		prefix_friendship.push_back(cur_pre);
		money.push_back(data[i].first);
	}
	lli ans = 0;
	for(i=1;i<=n;i++)
		ans = max(ans,include_friend_i(i));
	cout<<ans<<'\n';
	return 0;
}
