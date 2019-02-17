#include <iostream>
#include <bits/stdc++.h>
#define lli long long int
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
int main() {
	ios::sync_with_stdio(false);
	string s;
	cin>>s;
	lli n,i;
	n = s.size();
	lli zcount=0;
	for(i=0;i<n;i++)
	 {
	     if(s[i]=='Z')
	         zcount++;
	 }
	if(zcount==n)
	    cout<<0;
	else if(n==1)
	 {
	     cout<<(int)'Z' - (int)s[0] ;
	 }
	else if(zcount==(n-1))
	 {
	     for(i=0;i<n;i++)
	      {
	          if(s[i]!='Z')
	             {
	                 cout<<(int)'Z' - (int)s[i] ;
	                 break;
	             }
	      }
	 }
	else
	 {
	     vector<int> a;
	     a.resize(n);
	     for(i=0;i<n;i++)
	        a[i] = (int)'Z' - (int) s[i];
	     lli sum = 0;
	     long int start,end;
	     for(i=0;i<n;i++)
	      {
	          if(s[i]!='Z')
	             { start = i; break; }
	      }
	     for(i=n-1;i>=0;i--)
	      {
	          if(s[i]!='Z')
	           {
	               end = i;
	               break;
	           }
	      }
	    vector<long long int> mult;
	    mult.resize(end - start + 1);
	    mult[0] = a[start];
	    for(i=start+1;i<=end;i++)
	     {
	         mult[i-start] = (mult[i-1-start] + a[i]*modpow(26,i-start) )%MOD;
	     }
	     for(i=start;i<end;i++)
	      {
	          lli inv = modpow(modpow(26,i-start + 1),MOD-2);
	          sum =( sum + (a[i]*(mult[end-start]-mult[i-start])%MOD)*inv % MOD );
	      }
	     cout<<sum;
	 }
	return 0;
}
