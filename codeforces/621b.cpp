#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int x,y;
	int i;
	vector<long long int> ad;
	vector<long long int> sb;
	ad.resize(2001);
	sb.resize(2001);
	for(i=0;i<n;i++)
	{
		cin>>x>>y;
		int t1 = x+y;
		int t2 = x-y+1000;
		ad[t1]++;
		sb[t2]++;
	}
	long long int ans = 0;
	for(i=0;i<=2000;i++)
		ans = ans + ad[i]*(ad[i]-1) + sb[i]*(sb[i]-1);
	ans = ans/2;
	cout<<ans<<endl;
	return 0;
}