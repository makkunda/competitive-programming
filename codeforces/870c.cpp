#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int q;
	cin>>q;
	vector<int> ans;
	ans.resize(16);
	int i;
	for(i=0;i<16;i++)
		ans[i]=-1;
	ans[4]=1;ans[6]=1;ans[8]=2;ans[9]=1;ans[10]=2;ans[12]=3;ans[13]=2;ans[14]=3;ans[15]=2;
	while(q--)
	{
		long long int n;
		cin>>n;
		if(n<16)
			cout<<ans[n]<<'\n';
		else
		{
			if(n%2)
				cout<<((n/4)-1)<<'\n';
			else
				cout<<(n/4)<<'\n';
		}
	}
	return 0;
}