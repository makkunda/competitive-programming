#include <vector>
#include <string>
#include <iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector<int> s_val;
	string s;
	cin>>s;
	int n = s.length();
	s_val.resize(n);
	int i,j,k;
	int triple[26][26][26];
	int dub[26][26];
	for(i=0;i<26;i++)
	{
		for(j=0;j<26;j++)
		{
			for(k=0;k<26;k++)
			{
				triple[i][j][k] = 0;
			}
			dub[i][j] = 0;
		}
	}
	for(i=0;i<n;i++)
	{
		int char_val = (int)s[i] - (int)'a';
		s_val[i] = char_val;
	}
	s_val.push_back(100);
	s_val.push_back(100);
	s_val.push_back(100);
	s_val.push_back(100);
	s_val.push_back(100);
	s_val.push_back(100);
	s_val.push_back(100);
	vector<bool> pos_2;
	vector<bool> pos_3;
	pos_2.resize(n+4);
	pos_3.resize(n+4);
	pos_2[n] = true;
	pos_3[n] = true;

	for(i=n-1;i>=5;i--)
	{
		if(pos_3[i+2])
			pos_2[i] = true;
		else if(pos_2[i+2])
		{
			if((s_val[i]!=s_val[i+2])||(s_val[i+1]!=s_val[i+3]))
				pos_2[i] = true;
		}

		if(pos_2[i+3])
			pos_3[i] = true;
		else if(pos_3[i+3])
		{
			if((s_val[i]!=s_val[i+3])||(s_val[i+1]!=s_val[i+4])||(s_val[i+2]!=s_val[i+5]))
				pos_3[i] = true;
		}
	}
	int ans = 0;
	for(i=5;(i+1)<n;i++)
	{
		if(pos_2[i])
		{
			int fs = s_val[i];
			int snd = s_val[i+1];
			if(dub[fs][snd]==0)
			{
				ans++;
				dub[fs][snd] = 1;
			}
		}
	}
	for(i=5;(i+2)<n;i++)
	{
		if(pos_3[i])
		{
			int fs = s_val[i];
			int snd = s_val[i+1];
			int thrd = s_val[i+2];
			if(triple[fs][snd][thrd]==0)
			{
				ans++;
				triple[fs][snd][thrd] = 1;
			}
		}
	}
	vector<char> rev;
	rev.resize(26);
	for(i=0;i<26;i++)
		rev[i] = (char)((int)'a' + i);
	cout<<ans<<'\n';
	for(i=0;i<26;i++)
	{
		for(j=0;j<26;j++)
		{
			if(dub[i][j]==1)
			{
				cout<<rev[i]<<rev[j]<<'\n';
			}
			for(k=0;k<26;k++)
			{
				if(triple[i][j][k]==1)
					cout<<rev[i]<<rev[j]<<rev[k]<<'\n';
			}
		}
	}
	return 0;
}
