#include <iostream>
using namespace std;
 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		int i;
		int mn = 100000001;
		int mx = 0;
		int cur;
		for(i=0;i<n;i++)
		{
			cin>>cur;
			mn = min(mn,cur);
			mx = max(mx,cur);
		}
		int b = mn + k;
		if((b+k)<mx)
			b = -1;
		cout<<b<<'\n';
 
	}
	return 0;
}
