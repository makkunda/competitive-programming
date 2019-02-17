#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int n,d;
	vector<long long int> x;
	cin>>n>>d;
	int i;
	x.resize(n+1);
	for(i=0;i<n;i++)
		cin>>x[i];
	x[n] = 1000000000000;
	sort(x.begin(),x.end());
	long long int ans = 0;
	for(i=0;i<n;i++)
	{
		long long int temp = x[i]+d;
		int diff = (long long int)(upper_bound(x.begin(),x.end(),temp) - x.begin());
		long long int cnt ;
		if(x[diff]>temp)
		{
			cnt = diff-1-i;
		}
		else
			cnt = diff-i;
		ans = ans + cnt*(cnt-1);
	}
	ans = ans/2;
	cout<<ans<<endl;
	return 0;
}