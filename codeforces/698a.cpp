#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n;
	vector<int> a;
	cin>>n;
	a.resize(n+1);
	int i;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	vector<int> dp1,dp2,dp3;
	dp1.resize(n+1);
	dp2.resize(n+1);
	dp3.resize(n+1);
	

	// for(i=1;i<=n;i++)
	// {
	// 	if(a[i]==0)
	// 	{
	// 		dp1[i]=dp1[i-1]+1;
	// 		dp2[i]=dp2[i-1]+1;
	// 		dp3[i]=dp3[i-1]+1;
	// 	}
	// 	if(a[i]==1)
	// 	{
	// 		dp1[i]=min(dp2[i-1],dp3[i-1]);
	// 		dp2[i]=min(min(dp1[i-1],dp2[i-1]),dp3[i-1])+1;
	// 		dp3[i]=min(min(dp1[i-1],dp2[i-1]),dp3[i-1])+1;
	// 	}
	// 	if(a[i]==2)
	// 	{
	// 		dp2[i]=min(dp1[i-1],dp3[i-1]);
	// 		dp1[i]=min(min(dp1[i-1],dp2[i-1]),dp3[i-1])+1;
	// 		dp3[i]=min(min(dp1[i-1],dp2[i-1]),dp3[i-1])+1;
	// 	}
	// 	if(a[i]==3)
	// 	{
	// 		dp1[i]=min(dp2[i-1],dp3[i-1]);
	// 		dp2[i]=min(dp1[i-1],dp3[i-1]);
	// 		dp3[i]=min(min(dp1[i-1],dp2[i-1]),dp3[i-1])+1;
	// 	}
	// 	cout<<a[i]<<" "<<dp1[i]<<" "<<dp2[i]<<" "<<dp3[i]<<endl;
	// }
	// cout<<min(min(dp1[n],dp2[n]),dp3[n])<<endl;


	for(i=1;i<=n;i++)
	{
		dp3[i]=max(dp1[i-1],max(dp2[i-1],dp3[i-1]));
		if(a[i]==1||a[i]==3)
			dp1[i]=max(dp2[i-1],dp3[i-1])+1;
		else
			dp1[i]=dp1[i-1];
		if(a[i]==2||a[i]==3)
			dp2[i]=max(dp1[i-1],dp3[i-1])+1;
		else
			dp2[i]=dp2[i-1];
	}
	int ans = n - max(dp1[n],max(dp2[n],dp3[n]));
	// cout<<min(min(dp1[n],dp2[n]),dp3[n])<<endl;
	cout<<ans<<endl;
	return 0;
}