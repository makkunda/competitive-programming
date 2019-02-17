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
lli ab (lli a)
 {
     if(a>0)
       return a;
     return -1*a;  
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
	int t;
	cin>>t;
	while(t--)
	 {
	     int n,m,i;
	     lli e;
	     vector<lli>c,d;
	     cin>>n>>m>>e;
	     c.resize(n);
	     d.resize(m);
	     for(i=0;i<n;i++)
	        cin>>c[i];
	     for(i=0;i<m;i++)
	        cin>>d[i];
	     sort(c.begin(),c.end());
	     sort(d.begin(),d.end());
	     int ans = 0;
	     
	     
	     
	      {
	          vector<lli> diff;
	          for(i=0;i<(m);i++)
	           {
	               lli sz = mn(m-i,n);
	               diff.resize(sz);
	               int j;
	               for(j=0;j<sz;j++)
	                {
	                    diff[j]=c[j]-d[i+j];
	                }
	                sort(diff.begin(),diff.end());
	                for(j=0;j<sz;j++)
	                 {
	                     lli x=0;
	                     int acnt = 0;
	                     if(diff[j]>e)
	                         x = e - diff[j];
	                     else if(diff[j]<-1*e)
	                         x = -1*e - diff[j];
	                     int k ;
	                     for(k=0;k<sz;k++)
	                      {
	                          if(ab(diff[k]+x)<=e)
	                            acnt++;
	                      }
	                     ans = mx(ans,acnt); 
	                 }
	           }
	      }
	      {
	         vector<lli> diff;
	          for(i=0;i<=(n-1);i++)
	           {
	               int sz = mn(n-i,m);
	               diff.resize(sz);
	               int j;
	               for(j=0;j<sz;j++)
	                {
	                    diff[j]=c[i+j]-d[j];
	                }
	                sort(diff.begin(),diff.end());
	                for(j=0;j<sz;j++)
	                 {
	                     lli x=0;
	                     int acnt = 0;
	                     if(diff[j]>e)
	                         x = e - diff[j];
	                     else if(diff[j]<-1*e)
	                         x = -1*e - diff[j];
	                     int k ;
	                     for(k=0;k<sz;k++)
	                      {
	                          if(ab(diff[k]+x)<=e)
	                            acnt++;
	                      }
	                     ans = mx(ans,acnt); 
	                 }
	           } 
	      }
	      
	      vector<lli> cr;
	      cr.resize(n);
	      for(i=0;i<n;i++)
	       cr[i]=c[n-1-i];
	      for(i=0;i<n;i++)
	        c[i]=cr[i];
	      
	      {
	          vector<lli> diff;
	          for(i=0;i<(m);i++)
	           {
	               lli sz = mn(m-i,n);
	               diff.resize(sz);
	               int j;
	               for(j=0;j<sz;j++)
	                {
	                    diff[j]=c[j]-d[i+j];
	                }
	                sort(diff.begin(),diff.end());
	                for(j=0;j<sz;j++)
	                 {
	                     lli x=0;
	                     int acnt = 0;
	                     if(diff[j]>e)
	                         x = e - diff[j];
	                     else if(diff[j]<-1*e)
	                         x = -1*e - diff[j];
	                     int k ;
	                     for(k=0;k<sz;k++)
	                      {
	                          if(ab(diff[k]+x)<=e)
	                            acnt++;
	                      }
	                     ans = mx(ans,acnt); 
	                 }
	           }
	      }
	      {
	         vector<lli> diff;
	          for(i=0;i<=(n-1);i++)
	           {
	               int sz = mn(n-i,m);
	               diff.resize(sz);
	               int j;
	               for(j=0;j<sz;j++)
	                {
	                    diff[j]=c[i+j]-d[j];
	                }
	                sort(diff.begin(),diff.end());
	                for(j=0;j<sz;j++)
	                 {
	                     lli x=0;
	                     int acnt = 0;
	                     if(diff[j]>e)
	                         x = e - diff[j];
	                     else if(diff[j]<-1*e)
	                         x = -1*e - diff[j];
	                     int k ;
	                     for(k=0;k<sz;k++)
	                      {
	                          if(ab(diff[k]+x)<=e)
	                            acnt++;
	                      }
	                     ans = mx(ans,acnt); 
	                 }
	           } 
	      }
	      cout<<ans<<"\n";
	     
	 }
	return 0;
}
