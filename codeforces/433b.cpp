#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
	long int n,i;
	long long int a[100001];
	long long int v[100001],u[100001];
	a[0]=v[0]=u[0]=0;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		v[i] = v[i-1] + a[i];
	}
	sort(a,a+(n+1));
	for(i=1;i<=n;i++)
	{
		u[i] = u[i-1] + a[i];
	}
	long int m,l,r;
	int t;
	cin>>m;
	for(i=0;i<m;i++)
	{
		cin>>t>>l>>r;
		long long int ans;
		if(t==1)
			ans = v[r] - v[l-1];
		else
			ans = u[r] - u[l-1];
		cout<<ans<<"\n";
	}
	return 0;
}