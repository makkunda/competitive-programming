#include <iostream>
#include <vector>
#include <utility>
using namespace std;
#define lli long long int
vector<lli> pre_a;
int n;
pair<lli,lli> get_ans(lli q)
{
	pair<lli,lli> ans;
	lli lo = 0;
	lli hi = n+1;
	lli mid;
	while(lo<hi)
	{
		mid = lo + (hi-lo)/2;
		if(pre_a[mid]<q)
			lo = mid + 1;
		else
			hi = mid;
	}
	ans.first = lo;
	ans.second = q - pre_a[lo-1]; 
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int m;
	vector<lli> a;
	cin>>n>>m;
	int i;
	a.resize(n);
	for(i=0;i<n;i++)
		cin>>a[i];
	pre_a.resize(n+2);
	pre_a[0]=0;
	pre_a[n+1]=30000000000000000;
	for(i=1;i<=n;i++)
		pre_a[i]=pre_a[i-1]+a[i-1];
	while(m--)
	{
		lli q;
		cin>>q;
		pair<lli,lli> ans = get_ans(q);
		cout<<ans.first<<" "<<ans.second<<'\n';
	}
	return 0;
}
