#include <iostream>
#define inf 2000000000
using namespace std;
#define ll long long int
ll mx(ll a,ll b)
 {
 	if(a>b)
 		return a;
 	return b;
 }
int main()
{
	ios_base::sync_with_stdio(false) ;
	long long int a[1000000],forw[1000002],rev[1000002];
	long int n,i,k;
	cin>>n>>k;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		if(i<(k-1))
			 forw[i] = -1*inf;
	}
	rev[n] = -1*inf;rev[n+1] = -1*inf;
	forw[k-1] = 0;
	if(k<n)
		forw[k] = forw[k-1] + a[k];
	for(i=k+1;i<n;i++)
	{
		forw[i] = mx(forw[i-1],forw[i-2])+a[i];
	}
	for(i=n-1;i>=0;i--)
	{
		if(forw[i]>(rev[i+1]+a[i])&&forw[i]>(rev[i+2]+a[i]))
			   rev[i] = forw[i];
		else
		      rev[i] = mx(rev[i+1],rev[i+2])+a[i];	
	}
	cout<<rev[0]<<"\n";
	return 0;
}