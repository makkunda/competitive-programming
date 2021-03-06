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
	         lli n,c,num,ans,c1,c2,c3;
	         cin>>n>>c;
	         num = c;
	         c1 = modmult(modmult(modmult(num,num-1),modmult(num-2,num-3)),inv4);
	         c2 = modmult(2,modmult(num,num-1));
	         c3 = modmult(modmult(modmult(num,num-1),num-2),modmult(3,inv2));
	         ans = modsum(c1+c2,c3+num);
	    if(n%2==0)
	     {
	         ans = modpow(ans,(5*n/2));
	         ans = modpow(ans,n/2);
                
	     }
	    else
	    {
	         lli num1,num2;
	         num1 = modpow(ans,((n-1)/2));
	         num1 = modpow(num1,((n+1)/2));
	         num2 = modpow(ans,n);
	         num2 = modpow(num2,n);
	         ans = modmult(num1,num2);
	         ans = modmult(c,ans);
	    }
	    cout<<ans<<'\n';
	}
	return 0;
}
