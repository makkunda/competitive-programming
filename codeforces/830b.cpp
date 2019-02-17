#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long int
using namespace std;
bool comp(const pair<int,int> &a,const pair<int,int> &b)
 {
 	if(a.first<b.first)
 		return true;
 	else if(a.first==b.first && a.second<b.second)
 		return true;
 	else
 		return false;
 }
 vector<long long int> ar;
 long long int n;
 void update(long long int loc,long long int val)
 {
 	while(loc<=n)
 	{
 		ar[loc]=ar[loc]+val;
 		loc = loc + (loc&(-loc));
 	}
 }
long long int sum(long long int loc)
{
	long long int ans = 0;
	while(loc>=1)
	{
		ans = ans + ar[loc];
		loc = loc - (loc&(-loc));
	}
	return ans;
}
long long int rangesum(long long int start,long long int end)
{
	return (sum(end) - sum(start-1));
}
int main()
{
	vector<pair<long long int,long long int> > a;
	long long int i;
	cin>>n;
	a.resize(n+1);
	for(i=1;i<=n;i++)
	{
		cin>>a[i].first;
		a[i].second = i;
	}
	sort(a.begin()+1,a.end());
	ll ans = a[1].second;
	int prev_loc = a[1].second;
	ar.resize(n+1);
	for(i=1;i<=n;i++)
		{update(i,1);cout<<i<<" "<<a[i].first<<" "<<a[i].second<<"\n";}
	update(prev_loc,-1);
	for(i=2;i<=n;i++)
	{
		int cur = a[i].second;
		if(cur<prev_loc)
			ans = ans + rangesum(prev_loc+1,n) + rangesum(1,cur);
		else
			ans = ans + rangesum(prev_loc+1,cur);
		prev_loc = cur;
		update(cur,-1);
		cout<<i<<" "<<a[i].first<<" "<<a[i].second<<" "<<ans<<"\n";
	}
	cout<<ans<<endl;
}