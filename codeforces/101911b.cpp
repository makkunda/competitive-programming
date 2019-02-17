#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define pb push_back
#define mp make_pair
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	long n,h;
	cin>>n>>h;
	vector<long> s;
	vector<long> e;
	s.resize(n);
	e.resize(n);
	long i,j;
	for(i=0;i<n;i++)
		cin>>s[i]>>e[i];
	vector<long> pos;
	vector<long> neg;
	pos.resize(n);
	neg.resize(n);

	for(i=0;i<n;i++)
	{
		pos[i] = e[i] - s[i];
		if(i<(n-1))
			neg[i] = s[i+1] - e[i];
	}
	neg[n-1] = 1000000000 - e[n-1];

	long start_index = 0;
	long cur_gain = 0;
	long cur_neg = 0;
	long best_gain = 0;
	for(i=0;i<n;i++)
	{
		cur_gain = cur_gain + pos[i];
		while(cur_neg>=h)
		{
			cur_gain = cur_gain - pos[start_index];
			cur_neg = cur_neg - neg[start_index];
			start_index ++;
		}
		if(cur_gain>best_gain)
			best_gain = cur_gain;
		cur_neg = cur_neg + neg[i];
	}
	long ans = best_gain + h;
	cout<<ans<<endl;
	return 0;
}