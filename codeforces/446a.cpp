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
	int n,i;
	vector<ll> a,inc,dec;
	cin>>n;
	a.resize(n+2);
	inc.resize(n+2);
	dec.resize(n+2);
	for(i=1;i<=n;i++)
		cin>>a[i];
	a[0]=-10;
	a[n+1]=1000000007;
	for(i=1;i<=n;i++)
	{
		if(a[i]>a[i-1])
			inc[i]=inc[i-1]+1;
		else
			inc[i]=1;
	}
	for(i=n;i>=1;i--)
	{
		if(a[i]<a[i+1])
			dec[i]=dec[i+1]+1;
		else
			dec[i]=1;
	}
	int ans = 0;
	for(i=1;i<=n;i++)
	{
		if((a[i+1]-a[i-1])>=2)
			ans = mx(ans,inc[i-1]+dec[i+1]+1);
		else 
			ans = mx(ans,mx(inc[i-1]+1,dec[i+1]+1));
	}
	cout<<ans<<endl;
	// for(i=0;i<=(n+1);i++)
	// 	cout<<a[i]<<" ";
	// cout<<endl;
	// for(i=0;i<=(n+1);i++)
	// 	cout<<inc[i]<<" ";
	// cout<<endl;
	// for(i=0;i<=(n+1);i++)
	// 	cout<<dec[i]<<" ";
	return 0;
}

//10
//424238336 649760493 681692778 714636916 719885387 804289384 846930887 957747794 596516650 189641422

