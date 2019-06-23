#include <iostream>
using namespace std;
#define lli long long int 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		lli g,l,r;
		cin>>l>>r>>g;
		lli pre_cnt = (l-1)/g;
		lli post_cnt = r/g;
		lli ans = post_cnt - pre_cnt ;
		if(ans==1)
		{
			if(g>=l)
				ans = 1;
			else
				ans  = 0;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
