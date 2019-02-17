#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#define mod 1000000007
#define ll long long int
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		int n,i,j;
		cin>>n;
		vector<int> a;
		a.resize(n);
		for(i=0;i<n;i++)
			cin>>a[i];
		sort(a.begin(),a.end());
		vector<ll> ans;
		ans.resize(n);
		for(i=0;i<n;i++)
			ans[i]=1;
		for(i=n-1;i>0;i--)
		{
			int x = (int)sqrt(a[i]) + 1;
			for(j=1;j<x;j++)
			{
				if(a[i]%j==0)
				{
					int l = a[i]/j;
					if((binary_search(a.begin(),a.end(),j))&&j!=a[i])
					{
						std::vector<int>::iterator up;
						up = find(a.begin(), a.end(),j);
              			ll xl = (ll)(up - a.begin()); 
              			ans[xl]=ans[xl]+ans[i];
              			ans[xl]=ans[xl]%mod;
					}
					if((binary_search(a.begin(),a.end(),l))&&l!=a[i] && l!=j)
					{
						std::vector<int>::iterator up;
						up = find(a.begin(), a.end(),l);
              			ll xl = (ll)(up - a.begin()); 
              			ans[xl]=ans[xl]+ans[i];
              			ans[xl]=ans[xl]%mod;
					}
				}
			}
		}
		ll sum = 0;
		for(i=0;i<n;i++)
		{
			sum = sum + ans[i];
			sum=sum%mod;
		}
		sum = sum + mod;
		sum = sum%mod;
		cout<<sum<<"\n";
	}
	return 0;
}