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
	int n,m;
	char a[102][102];
	cin>>n>>m;
	int i,j;
	for(i=1;i<=n;i++)
	 {
	     for(j=1;j<=m;j++)
	       {
	           cin>>a[i][j];
	       }
	 }
	int x,y; 
	for(i=0;i<=(n+1);i++)
	    a[i][0]=a[i][m+1]='.';
	for(i=0;i<=(m+1);i++)
	    a[0][i]=a[n+1][i]='.';
	char l,r,u,d;
	l = 'L';
	r = 'R';
	u = 'U';
	d = 'D';
	if(n==1)
	{
	    cout<<r<<"\n";
	    int xx=1;
	      fflush(stdout);
	      cin>>x>>y;
	      if(x==1 && r==1)
	       {
	           r = 'L';
	           l = 'R';
	       }
	       else
	       {
	           if(a[1][2]=='F')
	              return 0;
	           else
	             xx = 2;
	       }
	       for(i = xx;i<=m;i++)
	        {
	            if(a[1][i]=='F')
	                return 0;
	            else 
	                cout<<r<<"\n";
	        }
	         
	}
	if(m==1)
	{
	    cout<<d<<"\n";
	    int xx=1;
	      fflush(stdout);
	      cin>>x>>y;
	      if(x==1 && r==1)
	       {
	           u = 'D';
	           d = 'U';
	       }
	       else
	       {
	           if(a[1][2]=='F')
	              return 0;
	           else
	             xx = 2;
	       }
	       for(i = xx;i<=n;i++)
	        {
	            if(a[i][1]=='F')
	                return 0;
	            else 
	                cout<<d<<"\n";
	        }
	         
	}
	if(a[1][2]!='*')
	  {
	      cout<<r<<"\n";
	      fflush(stdout);
	      cin>>x>>y;
	      if(x==1 && r==1)
	       {
	           r = 'L';
	           l = 'R';
	       }
	      else
	       {
	           if(a[1][2]=='F')
	              return 0;
	           else if(a[2][2]!='*')
	             {
	                 cout<<d<<"\n";
	                 fflush(stdout);
	                 cin>>x>>y;
	                 if(x==1&&y==1)
	                   {
	                        u = 'D';
	                        d = 'U';
	                        findpath(1,2);
	                        return 0;
	                   }
	                 else if(a[2][2]=='F')
	                    return 0;
	                 else
	                    //findpath(2,2); return 0;
	             }
	           else
	            {
	                if(a[2][1]!='*')
	                  {
	                      cout<<l<<"\n";
	                      fflush(stdout);
	                      cin>>x>>y;
	                      cout<<d<<"\n";
	                      fflush(stdout);
	                      cin>>x>>y;
	                      if(x==1 && y==1)
	                       {
	                        u = 'D';
	                        d = 'U';
	                        //findpath(1,1); return 0;
	                       }
	                      else if(a[2][1]=='F')
	                        return 0;
	                      else 
	                        //findpath(2,1); return 0;
	                  }
	                 else
	                  {
	                      for(i=)
	                  }
	            }
	       }
	  }
	return 0;
}
