#include <iostream>
#include <vector>
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
 bool ispal(ll x)
 	{
 		ll temp = x;
 		ll rev = 0;
 		while(temp>0)
 		{
 			rev = rev*10;
 			ll d = temp%10;
 			rev = rev + d;
 			temp = temp/10;
 		}
 		if(rev==x)
 			return true;
 		return false;
 	}
 int main()
 {
 	ll p,q;
 	cin>>p>>q;
 	ll g = gcd(p,q);
 	p = p/g;
 	q = q/g;
 	vector<bool> isp;
 	isp.resize(2000001);
 	ll i,j;
 	for(i=0;i<=2000000;i++)
 		isp[i]=true;
 	vector<ll> pr;
 	for(i=2;i<=2000000;i++)
 	{
 		if(isp[i])
 		{
 			pr.push_back(i);
 			for(j=i*i;j<=2000000;j=j+i)
 				isp[j]=false;
 		}
 	}
 	ll pi = 0;
 	ll pal = 0;
 	ll ans = 0;
 	bool dn = true;
 	for(i=1;i<=2000000;i++)
 	{
 		if(ispal(i))
 			pal++;
 		if(i==pr[pi])
 			pi++;
 		if((pi*q)>(pal*p) && dn)
 		{
 			ans = i-1;
 			dn = false;
 		}
 		if((pi*q)<=(pal*p))
 			dn = true;
 	}
 	cout<<ans<<endl;
 	return 0;
 }