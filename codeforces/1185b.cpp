#include <iostream>
#include <vector>
#include <string>
#include <utility>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	while(n--)
	{
		string s1;
		string s2;
		cin>>s1>>s2;
		vector<pair<char,int> > sl1;
		vector<pair<char,int> > sl2;
		int i;
		char x;
		int curcnt;
		x = 'A';
		curcnt = 0;
		for(i=0;i<s1.length();i++)
		{
			if(s1[i]==x)
				curcnt++;
			else
			{
				if(i!=0)
				{
					sl1.push_back(make_pair(x,curcnt));
				}
				x = s1[i];
				curcnt = 1;
			}
		}
		sl1.push_back(make_pair(x,curcnt));

		x = 'A';
		curcnt = 0;
		for(i=0;i<s2.length();i++)
		{
			if(s2[i]==x)
				curcnt++;
			else
			{
				if(i!=0)
				{
					sl2.push_back(make_pair(x,curcnt));
				}
				x = s2[i];
				curcnt = 1;
			}
		}
		sl2.push_back(make_pair(x,curcnt));
		bool poss = true;
		if(sl1.size()!=sl2.size())
			poss = false;
		else
		{
			for(i=0;i<sl1.size();i++)
			{
				if(sl1[i].first!=sl2[i].first)
				{
					poss = false;
					break;
				}
				if(sl1[i].second>sl2[i].second)
				{
					poss = false;
					break;
				}
			}
		}
		if(poss)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}

	return 0;
}
