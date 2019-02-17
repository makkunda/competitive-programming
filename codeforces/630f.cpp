#include <iostream>
using namespace std;
int main()
{
	long long int c[778][778];
	int i,j;
	for(i=0;i<=777;i++)
		c[i][0]=c[i][i]=1;
	//cout<<"hello world"<<endl;
	for(i=2;i<=777;i++)
	{
		for(j=1;j<=min(i-1,7);j++)
			c[i][j]=c[i-1][j] + c[i-1][j-1];
	}
	
	int n;
	cin>>n;
	long long int ans = c[n][5] + c[n][6] + c[n][7];
	cout<<ans<<endl;
	return 0;
}