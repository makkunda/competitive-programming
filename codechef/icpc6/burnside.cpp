#include <iostream>
#include <bits/stdc++.h>
#define lli long long int
#define vi vector<int>
#define vlli vector<long long int>
using namespace std;
#define MOD 1000000007
 
 
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
     return ((((a*b)%MOD) + MOD)%MOD);
 }
lli modsum(lli a,lli b)
{
    return ((((a+b)%MOD) + MOD)%MOD);
}
int main() {
	ios::sync_with_stdio(false);
	int t;
	lli inv2 ,inv4;
    inv2 = modpow(2,MOD - 2);
	inv4 = modpow(4,MOD - 2);
	cin>>t;
	while(t--)
	{
	    lli n,c,num,ans,num1,num2,num3;
	    cin>>n>>c;
	    if(n%2==0)
	     {
	        num1 = modpow(c,5*n);
	        num1 = modpow(num1,n);
	        num2 = modpow(c,(5*n/2));
	        num2 = modpow(num2,n);
	        num3 = modpow(c,(5*n/2));
	        num3 = modpow(num3,(n/2));
	        ans = modsum(num1 + num2,2*num3);
	        ans = modmult(ans,inv4);
	     }
	    else
	    {
	         lli num11,num12,num21,num22,num31,num32;
	         lli x = (n-1)/2;
	         lli y = (n+1)/2;
	         num11 = modpow(c,2*n);
	         num11 = modpow(num11,2*n);
	         num21 = modpow(c,2*n);
	         num21 = modpow(num21,n);
	         num31 = modpow(c,n);
	         num31 = modpow(num31,n);
	         num12 = modpow(c,2*x);
	         num12 = modpow(num12,2*y);
	         num22 = modpow(c,2*x);
	         num22 = modpow(num22,y);
	         num32 = modpow(c,x);
	         num32 = modpow(num32,y);
	         num1 = modmult(num11,num12);
	         num2 = modmult(num21,num22);
	         num3 = modmult(num31,num32);
	         ans = modsum(num1 + num2,2*num3);
	         ans = modmult(ans,inv4);
	         ans = modmult(ans,c);
	    }
	    cout<<ans<<'\n';
	}
	return 0;
}
