#include <iostream>
using namespace std;
#define inf 1000000000
#define ll long long int
ll mx(ll a,ll b)
  {
  	if(a>b)
  		return a;
  	return b;
  }
int main()
{
	int c,f;
	long long int e[231][231];
	int x,y,i,j,k;
	long int p;
	long long int mxi = 0;
	cin>>c>>f;
	for(i=0;i<=c;i++)
	{
		for(j=0;j<=c;j++)
			  e[i][j] = inf;
		e[i][i] = 0;	
	}
	for(i=0;i<f;i++)
	{
		cin>>x>>y>>p;
		e[x][y] = e[y][x] = p;
	}
	for(k=1;k<=c;k++)
		 {
		 	for(i=1;i<=c;i++)
		 	{
		 		for(j=1;j<=c;j++)
		 		{
		 			if(e[i][j]>(e[i][k] + e[k][j]))
		 				      e[i][j] = e[i][k] + e[k][j];
		 		}
		 	}
		 }
	for(i=1;i<=c;i++)
	  {
	  	for(j=1;j<=c;j++)
	  		  {
	  		  	if(e[i][j]<inf)
	  		  		   mxi = mx(mxi,e[i][j]);
	  		  }
	  }	 
	cout<<mxi<<"\n";  
	return 0;
}