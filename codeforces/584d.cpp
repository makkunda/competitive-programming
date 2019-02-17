#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long int
using namespace std;
vector<ll> prime;
bool isprime(ll x)
 {
 	ll i;
 	for(i=0;i<prime.size();i++)
 	{
 		if(x==prime[i])
 			return true;
 		if(x%prime[i]==0)
 			return false;
 	}
 	return true;
 }
int main()
{
	vector<bool> isp;
	isp.resize(50001);
	ll i,j;
	for(i=0;i<=50000;i++)
		isp[i]=true;
	for(i=2;i<=50000;i++)
	{
		if(isp[i])
		{
			for(j=i*i;j<=50000;j=j+i)
				isp[j]=false;
		}
	}
	for(i=2;i<=50000;i++)
	{
		if(isp[i])
			prime.push_back(i);
	}
	ll n;
	cin>>n;
	if(isprime(n))
		cout<<1<<'\n'<<n<<endl;
	else
	{
		cout<<3<<'\n';
		cout<<3<<" ";
		ll n1 = n-3;
		for(i=0;i<prime.size();i++)
		{
			ll temp1 = n1 - prime[i];
			if(isprime(temp1))
			{
				cout<<temp1<<" "<<prime[i]<<endl;
				return 0;
			}
		}
	}
	return 0;
}