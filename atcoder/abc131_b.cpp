#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define lli long long int
#define pb push_back
using namespace std;
int ab(int x)
{
	if(x>0)
		return x;
	return -1*x;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	int l;
	cin>>n>>l;
	int minval = 10000;
	int i;
	int ind=i;
	for(i=1;i<=n;i++)
	{
		int val = l + i - 1;
		val = ab(val);
		if(val < minval)
		{
			minval = val;
			ind = i;
		}
	}
	int ans = 0;
	for(i=1;i<=n;i++)
	{
		if(i!=ind)
		{
			ans = ans + l + i - 1;
		}
	}
	cout<<ans<<endl;


	return 0;
}
