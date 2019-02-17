#include <iostream>
#include <vector>
using namespace std;
long long int pow2(int x)
{
	long long int ans = 1;
	for(int i=1;i<=x;i++)
		ans = ans*2;
	return ans;
}
int main()
{
	int n,m;
	int a[50][50];
	cin>>n>>m;
	int i,j;
	long long int ans = 0;
	for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
				cin>>a[i][j];
		}
	for(i=0;i<n;i++)
	{
		int zcount = 0;
		int ocount = 0;
		for(j=0;j<m;j++)
		{
			if(a[i][j]==0)
				ocount++;
			else
				zcount++;
		}
		ans = ans + pow2(zcount) + pow2(ocount) - 2;
	}
	for(i=0;i<m;i++)
	{
		int zcount = 0;
		int ocount = 0;
		for(j=0;j<n;j++)
		{
			if(a[j][i]==0)
				ocount++;
			else
				zcount++;
		}
		ans = ans + pow2(zcount) + pow2(ocount) - 2;
	}
	ans = ans - m*n;
	cout<<ans<<endl;
	return 0;
}