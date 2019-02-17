#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	cin.tie(0);ios::sync_with_stdio(false);
	vector<bool> isp;
	long long int i,j;
	isp.resize(200001);
	for(i=0;i<=200000;i++)
		isp[i]=true;
	for(i=2;i<=200000;i++)
	{
		if(isp[i])
		{
			for(j=i*i;j<=200000;j=j+i)
				isp[j]=false;
		}
	}
	vector<int> prime;
	for(i=2;i<=200000;i++)
	{
		if(isp[i])
			prime.push_back(i);
	}
	vector<vector<int > > a;
	vector<vector<int > > diff;
	int n,m;
	cin>>n>>m;
	a.resize(n);diff.resize(n);
	for(i=0;i<n;i++)
	{
		a[i].resize(m);
		diff[i].resize(m);
	}
	vector<long long int> row,col;
	row.resize(n);col.resize(m);
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			cin>>a[i][j];
			if(binary_search(prime.begin(),prime.end(),a[i][j]))
				diff[i][j]=0;
			else
			{
				std::vector<int>::iterator up;
				up = upper_bound(prime.begin(), prime.end(),a[i][j]);
              	int loc = (int)(up - prime.begin()); 
              	diff[i][j]=prime[loc]-a[i][j];
			}
			row[i]=row[i] + diff[i][j];
			col[j]=col[j] + diff[i][j];
		}
	}
	long long int ans = row[0];
	for(i=1;i<n;i++)
		ans = min(ans,row[i]);
	for(i=0;i<m;i++)
		ans = min(ans,col[i]);
	cout<<ans<<endl;
	return 0;
}