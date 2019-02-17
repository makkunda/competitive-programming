#include <iostream>
using namespace std;
#define ll long long int
ll gcd(ll a,ll b)
 {
 	ll a1 = max(a,b);
 	ll b1 = min(a,b);
 	if(b1==0)
 		return a1;
 	return gcd(a1%b1,b1);
 }
 ll lcm(ll a,ll b)
 {
 	ll ans = a*b;
 	ans = ans/gcd(a,b);
 	return ans;
 }
 int main()
 {
 	ll n,a,b,p,q;
 	cin>>n>>a>>b>>p>>q;
 	ll lc = lcm(a,b);
 	ll ans = (n/a)*p + (n/b)*q - (n/lc)*min(p,q);
 	cout<<ans<<endl;
 	return 0;
 }