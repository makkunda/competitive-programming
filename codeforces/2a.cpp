#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
	vector<string> hist_name;
	vector<int> hist_score;
	int i,j,n;
	string x;
	int sc;

	cin>>n;

	for(i=0;i<n;i++)
	{
		cin>>x>>sc;
		hist_name.push_back(x);
		hist_score.push_back(sc);
	}
	vector<string> name;
	vector<int> score;
	for(i=0;i<n;i++)
	{
		bool found = false;
		int pos = -1;
		for(j=0;j<name.size();j++)
		{
			if(hist_name[i]==name[j])
			{
				pos = j;
				found = true;
				break;
			}
		}
		if(found)
			score[pos] = score[pos] + hist_score[i];
		else
		{
			name.push_back(hist_name[i]);
			score.push_back(hist_score[i]);
		}
	}
	int mx = score[0];
	string ans ;
	for(i=0;i<name.size();i++)
	{
		mx = max(mx,score[i]);
	}
	vector<string> name1;
	vector<int> score1;
	bool maxhit = false;
	for(i=0;i<n;i++)
	{
		bool found = false;
		int pos = -1;
		for(j=0;j<name1.size();j++)
		{
			if(hist_name[i]==name1[j])
			{
				pos = j;
				found = true;
				break;
			}
		}
		if(found)
		{
			score1[pos] = score1[pos] + hist_score[i];
			if(!maxhit)
			{
				if(score1[pos]>=mx && score[pos]==mx)
				{
					maxhit = true;
					ans = name1[pos];
				}
			}
		}
		else
		{
			name1.push_back(hist_name[i]);
			score1.push_back(hist_score[i]);
			if(!maxhit)
			{
				if(hist_score[i]>=mx && score[score1.size()-1]==mx)
				{
					maxhit = true;
					ans = hist_name[i];
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}