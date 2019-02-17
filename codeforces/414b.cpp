#include <iostream>
#include <Vector>
#define mod 1000000007
using namespace std;

int main()
{
	int n,k,i,j;
	cin>>n>>k;
	vector<vector<long long int> > a;
	a.resize(n+1);
	for(i=0;i<=n;i++)
		a[i].resize(k);
	for(i=1;i<=n;i++)
		a[i][0]=1;
	for(i=n;i>0;i--)
	{
		for(j=1;j<k;j++)
		{
			int t;
			long long int sum=0;
			for(t=1;i*t<=n;t++)
			{
				sum = sum + a[i*t][j-1];
				sum = sum%mod;
			}
			a[i][j]=sum;
		}
	}
	long long int ans = 0;
	for(i=1;i<=n;i++)
	{
		ans = ans + a[i][k-1];
		ans = ans%mod;
	}
	ans = ans + mod;
	ans = ans%mod;
	cout<<ans<<"\n";
	return 0;
}