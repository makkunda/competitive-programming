#include <iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		int n,i,j;
		int x;
		long long int count = 0;
		cin>>n;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				cin>>x;
				if(x)
					count++;
			}
		}
		long long int temp1 = n;
		int ans = 0;
		if(count<=n)
			cout<<0<<"\n";
		else
		{
			while(temp1<count)
			{
				ans++;
				temp1 = temp1 + 2*(n-ans);
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}
