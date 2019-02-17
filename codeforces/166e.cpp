#include <iostream>
#include <vector>
#define ll long long int
#define matrix vector<vector< ll > >
#define mod 1000000007
using namespace std;
matrix mul(matrix a,matrix b)
 {
 	matrix c(2,vector<ll>(2,0));
 	 int i,j,k;
 	 for(i=0;i<2;i++)
 	 	 {
 	 	 	for(j=0;j<2;j++)
 	 	 		{
 	 	 			for(k=0;k<2;k++)
 	 	 				  c[i][j] = (c[i][j] + a[i][k]*b[k][j])%mod;
 	 	 			c[i][j] = (c[i][j] + mod)%mod;	
 	 	 		}
 	 	 }
 	return c; 	 
 }
matrix pow(matrix a,ll n)
  {
  	if(n==1)
  		return a;
  	if(n%2)
  		 return mul(a,pow(a,n-1));
  	matrix x = pow(a,n/2);
  	return mul(x,x);	
  } 
int main()
{
	ll n;
	cin>>n;
	matrix a(2,vector<ll>(2,0));
	a[0][0] = 0;
	a[0][1] = 1;
	a[1][0] = 3;
	a[1][1] = 2;
	vector<ll> f(2);
	f[0] = 0;f[1] = 3;
	if(n==1)
		 cout<<0<<endl;
	else
	   {
	   	matrix b(2,vector<ll>(2,0));
	   	b = pow(a,n-1);
	   	ll ans = b[0][0]*f[0] + b[0][1]*f[1];
	   	ans = (ans + mod)%mod;
	   	ans = (ans + mod)%mod;
	   	cout<<ans<<endl;
	   }	
	return 0;
}