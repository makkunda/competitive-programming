#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	vector<int> t;
	cin>>n>>m;
	t.resize(n);
	int i,j;
	vector<vector<int> > freq;
	freq.resize(n);
	for(i=0;i<n;i++)
		freq[i].resize(101);
	for(i=0;i<n;i++)
	{
		cin>>t[i];
		
		if(i!=0)
		{
			for(j=0;j<=100;j++)
				freq[i][j] = freq[i-1][j];
			freq[i][t[i-1]] = freq[i][t[i-1]] + 1;
		}

	}
	cout<<0<<" ";
	for(i=1;i<n;i++)
	{
		int diff = m - t[i];
		int cursum = 0;
		int ans = 0;
		int break_point = 101;
		for(j=0;j<=100;j++)
		{
			cursum = cursum + freq[i][j]*j;
			if(cursum>diff)
			{
				break_point = j;
				cursum = cursum - freq[i][j]*j;
				break;
			}
			else
				ans = ans + freq[i][j];
		}
		if(break_point==101)
			ans = i;
		else
		{
			int extra = diff - cursum;
			int extra_pep = extra/break_point;
			ans = ans + extra_pep;

		}
		cout<<i-ans<<" ";
	}
	return 0;
}
