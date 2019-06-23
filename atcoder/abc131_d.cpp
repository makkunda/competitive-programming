#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#define lli long long int
#define pb push_back
using namespace std;

int main()
{

	vector<pair<lli,lli> > jobs;
	int n;
	cin>>n;
	int i;
	int a,b;
	bool poss = true;
	for(i=0;i<n;i++)
	{
		cin>>a>>b;
		jobs.pb(make_pair(b,a));
	}
	sort(jobs.begin(),jobs.end());
	lli cursum = 0;
	for(i=0;i<n;i++)
	{
		cursum = cursum + jobs[i].second;
		if(cursum>jobs[i].first)
		{
			poss = false;
			break;
		}
	}
	if(poss)
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;

	return 0;
}
