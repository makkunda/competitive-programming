#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	long long int n,k,d,i,j;
	cin>>n>>k>>d;
	double lh = d*log(k);
	double rh = log(n);
	bool solve = false;
	if(lh>=rh)
	{
		solve = true;
	}
	else
	{
		int i;
		int tmp = 1;
		for(i=0;i<d;i++)
			tmp = tmp*k;
		if(tmp>=n)
			solve = true;
	}
	if(solve)
	{
		int ans[1000][1000];
		if(k>=n)
		{
			int i,j;
			for(i=0;i<d;i++)
			{
				for(j=0;j<n;j++)
					ans[i][j] = j+1;
			}
		}
		else
		{
			for(i=0;i<n;i++)
			{
				vector<int> dig;
				int tmp = i;
				while(tmp>0)
				{
					int dd = tmp%k;
					dig.push_back(dd);
					tmp = tmp/k;
				}
				while(dig.size()<d)
					dig.push_back(0);

				for(j=0;j<d;j++)
					ans[j][i] = dig[j]+1;
			}
		}
		for(i=0;i<d;i++)
		{
			for(j=0;j<n;j++)
				cout<<ans[i][j]<<" ";
			cout<<endl;
		}
	}
	else
		cout<<-1<<endl;
	return 0;
}