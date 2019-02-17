#include <iostream>
#include <vector>
#define ll long long int
using namespace std;
ll mx(ll a,ll b)
 {
 	if(a>b)
 		return a;
 	return b;
 }
int main()
{
	int n,m,k,i,j;
	cin>>n>>m>>k;
	vector<ll> p;
	p.resize(n);
	for(i=0;i<n;i++)
		cin>>p[i];
	vector<ll> prefix;
	prefix.resize(n+1);
	//prefix[0]=p[0];
	for(i=1;i<=n;i++)
		prefix[i]=prefix[i-1] + p[i-1];
	vector<vector<ll> > dp;
	dp.resize(n+1);
	for(i=0;i<=n;i++)
		dp[i].resize(k+1);
	for(i=1;i<=k;i++)
	{
		for(j=i*m;j<=n;j++)
			dp[j][i] = mx(dp[j-1][i],dp[j-m][i-1]+prefix[j]-prefix[j-m]);
	}
	cout<<dp[n][k];
	return 0;
} 