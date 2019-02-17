#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long int
using namespace std;
ll gcd(ll a,ll b)
{
	ll a1,b1;
	a1 = max(a,b);
	b1 = min(a,b);
	if(b1==0)
		return a1;
	return gcd(b1,a1%b1);
}
int main()
{
	int n,i;
	cin>>n;
	vector<ll> a;
	a.resize(n);
	for(i=0;i<n;i++)
		cin>>a[i];
	sort(a.begin(),a.end());
	ll g = a[0];
	for(i=1;i<n;i++)
		g = gcd(g,a[i]);
	ll a1 = a[n-1]/g;
	ll ans = a1 - n;
	if(ans%2)
		cout<<"Alice\n";
	else
		cout<<"Bob\n";
	return 0;
}