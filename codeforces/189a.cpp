#include <iostream>
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
int dp[4001];
int a1,a2,a3;
int fun(int a)
  {
    if(a<0)
       return -8000;
    else if(a==0)
       return 0;
    else if(dp[a]==-1)
       dp[a] =  mx(mx(fun(a-a1),fun(a-a2)),fun(a-a3))+1;
   //cout<<a<<" "<<dp[a]<<endl;   
    return dp[a];   
  }
int main() {
	int a,b,c,n;
	cin>>n>>a1>>a2>>a3;
	for (int i=0;i<=4000;i++)
	  {
	      dp[i]=-1;
	  }
	dp[0]=0;  
	int x = mn(mn(a1,a2),a3);
	for(int j = 1;j<x;j++)
	{
		dp[j] = -8000;
	}
	cout<<fun(n)<<endl;
	return 0;
}
