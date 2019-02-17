#include <iostream>
#include <bits/stdc++.h>
#define lli long long int
#define MOD 1000000007
using namespace std;
lli mn(lli a,lli b)
{
    if(a>b)
       return b;
    return a;   
}
lli mx(lli a,lli b)
{
    if(a<b)
       return b;
    return a;   
}

lli modmult(lli a,lli b)
{
    lli ans = a*b;
    ans = ans % MOD;
    ans = ans + MOD;
    ans = ans % MOD;
    return ans;
}

lli modadd(lli a,lli b)
{
    lli ans = a+b;
    ans = ans % MOD;
    ans = ans + MOD;
    ans = ans % MOD;
    return ans;
}

long long int modpow(long long int  a, long long int b)
{
	long long int r = 1;
	while(b>0)
	{
		if((b%2)==1) 
		   r = (r*a)%MOD;
		a = (a*a)%MOD;
		b=b/2;
	}
	return r%MOD;
}

int main() {
	ios::sync_with_stdio(false);cin.tie(0);
	vector<lli> fact;
	fact.resize(2001);
	lli i;
	fact[0]=1;
	for(i=1;i<=2000;i++)
	{
	    fact[i]=modmult(fact[i-1],i);
	}
	vector<lli> invfact;
	invfact.resize(2001);
	for(i=0;i<=2000;i++)
	    invfact[i] = modpow(fact[i],MOD - 2);
	lli ans = 1;
	int k;
	vector<int> c;
	cin>>k;
	c.resize(k);
	for(i=0;i<k;i++)
		cin>>c[i];
	if(k>1)
	{
		lli cnt = c[0];
		for(i=1;i<k;i++)
		{
			lli c1 = cnt + c[i];
			lli temp = modmult(fact[c1-1],invfact[cnt]);
			temp = modmult(temp,invfact[c[i]-1]);
			ans = modmult(ans,temp);
			cnt = cnt + c[i];
		}
	}
	cout<<ans<<endl;
	return 0;
}
