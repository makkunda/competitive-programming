#include <iostream>
#include <bits/stdc++.h>
#define lli long long int
#define MOD 10
using namespace std;

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
	int t;
	cin>>t;
	while(t--)
	{
	    int a;
	    lli b;
	    cin>>a>>b;
	    a=a%10;
	    lli ans = modpow(a,b);
	    cout<<ans<<"\n";
	}
	return 0;
}
