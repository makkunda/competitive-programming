#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	//ifstream cin("611c.in");
	char x[501][501];
	int h,w,i,j;
	long long int dp[501][501],row[501][501],col[501][501];
	long int q,k;
	long long int ans;
	int r1,c1,r2,c2;
    cin>>h>>w;
	for(i=0;i<=h;i++)
	{
		x[i][0]='#';
		dp[i][0]=0;
		row[i][0]=0;
	}
	for(i=0;i<=w;i++)
	{
		x[0][i]='#';
		dp[0][i]=0;
		col[0][i]=0;
	}
	for(i=1;i<=h;i++)
	{
		for(j=1;j<=w;j++)
			     cin>>x[i][j];
	}
	for(i=1;i<=h;i++)
			{
				for(j=1;j<=w;j++)
				{
					dp[i][j] = dp[i][j-1]+dp[i-1][j] - dp[i-1][j-1];
					row[i][j] = row[i][j-1];col[i][j]=col[i-1][j];
					if(x[i][j]!='#')
					{
						if(x[i-1][j]!='#')
							{dp[i][j]++;col[i][j]++;}
						if(x[i][j-1]!='#')
							{dp[i][j]++;row[i][j]++;}
					}
				}
			}
    cin>>q;	
	for(k=0;k<q;k++)
	  {
	      cin>>r1>>c1>>r2>>c2;
	  	ans = dp[r2][c2] + dp[r1][c1] - dp[r2][c1] - dp[r1][c2];
	  	ans = ans + row[r1][c2] - row[r1][c1] + col[r2][c1] - col[r1][c1];
	  	cout<<ans<<"\n";
	  }	
	/*for(i=0;i<=h;i++)
	{
		for(j=0;j<=w;j++)
			  cout<<x[i][j];
		cout<<"\n";	
	}
	for(i=0;i<=h;i++)
	{
		for(j=0;j<=w;j++)
			  cout<<dp[i][j]<<" ";
		cout<<"\n";	
	}  */
	return 0;
}