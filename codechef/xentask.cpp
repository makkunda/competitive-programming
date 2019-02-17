#include <iostream>
#include <vector>
#define lli long long int
using namespace std;
lli mn(lli a,lli b)
{
	if(a<b)
		return a;
	return b;
}
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		lli n,i;
		cin>>n;
		vector<lli> x,y;
		x.resize(n);y.resize(n);
		for(i=0;i<n;i++)
			cin>>x[i];
		for(i=0;i<n;i++)
			cin>>y[i];
		lli ans1 = 0,ans=0;
		for(i=0;i<n;i++)
		{
			if(i%2)
			{
				ans = ans + x[i];
				ans1 = ans1 + y[i];
			}
			else
			{
				ans1 = ans1 + x[i];
				ans = ans + y[i];				
			}
		}
		cout<<mn(ans,ans1)<<"\n";
	}
	return 0;
}