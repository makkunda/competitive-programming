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
	int n;
	cin>>n;
	vector<pair<int,int> > b;
	b.resize(n);
	int i;
	for(i=0;i<n;i++){
		cin>>b[i].first;
		b[i].second = i;
	}
	sort(b.begin(), b.end());
	if(n<4)
		cout<<1<<endl;
	else
	{
		// case 1
		int diff = b[1].first - b[0].first;
		bool case1 = true;
		for(i=2;i<(n-1);i++)
		{
			if((b[i].first-b[i-1].first)!=diff)
			{
				case1 = false;
				break;
			}
		}
		if(case1)
		{
			cout<<b[n-1].second + 1<<endl;
			return 0;
		}
		// case 2
		diff = b[2].first - b[1].first;
		bool case2 = true;
		for(i=3;i<n;i++)
		{
			if((b[i].first-b[i-1].first)!=diff)
			{
				case2 = false;
				break;
			}
		}
		if(case2)
		{
			cout<<b[0].second + 1<<endl;
			return 0;
		}
		//case 3 
		diff = (b[n-1].first - b[0].first)/(n-2);
		if((diff*(n-2))!=(b[n-1].first - b[0].first))
		{
			cout<<-1<<endl;
			return 0;
		}
		int errcnt = 0;
		int ans = -1;
		for(i=1;i<n;i++)
		{
			int expt;
			if(errcnt==0)
			{
				expt = b[0].first + i*diff;
			}
			else
			{
				expt = b[0].first + (i-1)*diff;
			}
			if(b[i].first!=expt)
			{
				ans = b[i].second;
				errcnt++;
			}
		}
		if(errcnt==1)
			cout<<ans+1<<endl;
		else
			cout<<-1<<endl;
	}
	return 0;
}
