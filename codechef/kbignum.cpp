#include <iostream>
#include <vector>
#define ll long long int
#define matrix vector<vector< ll > >
using namespace std;
matrix mul(matrix a,matrix b,ll mod)
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
matrix pow(matrix a,ll n,ll mod)
  {
  	if(n==1)
  		return a;
  	if(n%2)
  		 return mul(a,pow(a,n-1,mod),mod);
  	matrix x = pow(a,n/2,mod);
  	return mul(x,x,mod);	
  }
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	long int t;
	cin>>t;
	do
	{
	    t--;
		long long int a,n,m;
		cin>>a>>n>>m;
		long long int temp = a;
		long long int p = 1;
		while(temp>0)
		{
			temp=temp/10;
			p=p*10;
		}
		if(n==1)
		{
			long long int ans = a%m;
			ans = ans + m;
			ans = ans%m;
			cout<<ans<<"\n";
		}
		else
		{
			long long int ans = a%m;
			matrix c(2,vector<ll>(2,0));
	        c[0][0] = p;
	        c[0][1] = 1;
	        c[1][0] = 0;
	        c[1][1] = 1;
	        matrix b(2,vector<ll>(2,0));
	   	    b = pow(c,n-1,m);
	   	    ll ans1 = b[0][0] + b[0][1];
	   	    ans1 = ans1%m;
	   	    ans = (ans*ans1)%m;
			ans = ans + m;
			ans = ans%m;
			cout<<ans<<"\n";
		}
	}while(t>0);
	return 0;
}