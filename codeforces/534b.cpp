#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long int v1,v2,d,t;

	cin>>v1>>v2>>t>>d;
	long long int i,j,k;
	vector<vector<long long int> > dp;
	dp.resize(t);
	for(i=0;i<t;i++)
		dp[i].resize(1200);
	for(i=0;i<t;i++)
	{
		for(j=0;j<1200;j++)
			dp[i][j]=-10000000;
	}
	dp[0][v1]=v1;
	for(i=1;i<t;i++)
	{
		for(j=0;j<1200;j++)
		{
			long long int ans = -10000000;
			for(k=max((long long int)0,j-d);k<=min((long long int)1199,j+d);k++)
				ans = max(ans,dp[i-1][k]);
			dp[i][j] = ans + j;
		}
	}
	cout<<dp[t-1][v2]<<endl;
	return 0;
}