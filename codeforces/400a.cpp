#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		int i;
		vector<int> ans;
		int j,k;
		for(i=1;i<=12;i++)
		{
			if((12%i)==0)
			{
				bool pos = false;
				for(j=0;j<(12/i);j++)
				{
					bool cur = true;
					for(k=0;k<i;k++)
					{
						if(s[k*(12/i)+j]!='X')
							cur = false;
					}
					pos = pos || cur;
				}
				if(pos)
					ans.push_back(i);
			}
		}
		cout<<ans.size()<<" ";
		for(i=0;i<ans.size();i++)
			cout<<ans[i]<<'x'<<(12/ans[i])<<' ';
		cout<<'\n';
	}
	return 0;
}