#include <iostream>
#define inf 1000000000
#define ll long long int
using namespace std;
ll mx(ll a,ll b)
 {
 	if(a>b)
 		return a;
 	return b;
 }
int main()
{
	int n,i,j;
	ll a[2501][2501],b[2501][2501];
	cin>>n;
	a[0][0] = -1*inf;
	b[0][0] = -1*inf;
	for(i=1;i<=n;i++)
		 { 
		 	a[0][i]=a[i][0] = -1*inf;
		 	b[0][i]=b[i][0] = -1*inf;
		 }
	b[1][0] = 0;	 
	for(i=1;i<=n;i++)
	  	{
	  		for(j=1;j<=n;j++)
	  			  cin>>a[i][j];
	  	}
	 for(i=1;i<=n;i++)
	  	{
	  		for(j=1;j<=n;j++)
	  			 { 
	  			 	ll x = mx(b[i-1][j],b[i][j-1]);
	  			 	b[i][j] = x + a[i][j] + a[j][n-i+1];
	  			 }	
	  	} 
	cout<<b[n][n]<<"\n";  		
	return 0;
}