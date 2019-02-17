// ans is 31626

#include <iostream>
using namespace std;
int main()
{
	long int dsum[10001];
	int i,j;
	for(i=0;i<=10000;i++)
		dsum[i] = 0;
	for(i=1;i<=10000;i++)
	{
		for(j=1;j<i;j++)
		{
			if(i%j==0)
				dsum[i] = dsum[i] + j;
		}
	}
	long long int ans = 0;
	for(i=2;i<=10000;i++)
	{
		for(j=1;j<i;j++)
		{
			if((dsum[i]==j)&&(dsum[j]==i))
				ans = ans + i + j;
		}
	}
	cout<<ans<<endl;
	return 0;
}