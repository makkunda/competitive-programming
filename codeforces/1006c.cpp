#include <iostream>
#include <vector>
using namespace std;
#define lli long long int
int n;
vector<lli> pre_a;
vector<lli> post_a;
lli get_ans(int q)
{
	lli ans = pre_a[q];
	lli req = pre_a[n] - 2*ans;
	if (req<0)
		return (-1);
	int lo = 1;
	int hi = n+1;
	int mid;
	while(lo<hi)
	{
		mid = lo + (hi-lo)/2;
		if(post_a[mid]<ans)
			lo = mid + 1;
		else
			hi = mid;
	}
	if(post_a[lo]==ans)
		return ans;
	return (-1);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector<lli> a;
	cin>>n;
	int i;
	a.resize(n);
	for(i=0;i<n;i++)
		cin>>a[i];
	pre_a.resize(n+1);
	pre_a[0] = 0;
	for(i=0;i<n;i++)
		pre_a[i+1]=pre_a[i] + a[i];
	post_a.resize(n+2);
	post_a[0]=0;
	post_a[n+1]=10000000000000000;
	for(i=1;i<=n;i++)
		post_a[i] = post_a[i-1] + a[n-i]; 
	lli ans = 0;
	for(i=1;i<=n;i++)
		ans = max(ans,get_ans(i));
	cout<<ans<<'\n';
	return 0;
}
