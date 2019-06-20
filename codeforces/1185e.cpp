#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		vector<vector<char> > brd;
		brd.resize(n);
		int i,j;
		for(i=0;i<n;i++)
			brd[i].resize(m);
		vector<int> mn_i;
		vector<int> mx_i;
		vector<int> mn_j;
		vector<int> mx_j;
		mn_i.resize(26);
		mx_i.resize(26);
		mn_j.resize(26);
		mx_j.resize(26);
		for(i=0;i<26;i++)
		{
			mn_i[i] = 3000;
			mx_i[i] = -1;
			mn_j[i] = 3000;
			mx_j[i] = -1;
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				cin>>brd[i][j];
				if(brd[i][j]!='.')
				{
					int ind = (int)brd[i][j] - (int)'a';
					mn_i[ind] = min(mn_i[ind],i);
					mx_i[ind] = max(mx_i[ind],i);
					mn_j[ind] = min(mn_j[ind],j);
					mx_j[ind] = max(mx_j[ind],j);
				}
			}
		}
		bool pos = true;
		int mxcnt = 26;
		vector<int> next;
		// next.resize(26);
		// int j;
		for(i=0;i<26;i++)
		{
			// cout<<mn_i[i]+1<<" "<<mn_j[i]+1<<" "<<mx_i[i]+1<<" "<<mx_j[i]+1<<'\n';
			if(mx_i[i]==(-1)){
				if(mxcnt==26)
					mxcnt = i;
				continue;
			}
			else
			{
				if(mxcnt!=26){
					mxcnt = 26;
					// for(j=i-1;j>=0;j--)
					// {
					// 	if(mx_i[j]==(-1))
					// 		next[j] = i;
					// }
				}
			}
			if((mn_i[i]!=mx_i[i]) && (mn_j[i]!=mx_j[i]))
			{
				pos = false;
				// cout<<"DIAG "<<i<<'\n';
				break;
			}
			// if(i!=0)
			// {
			// 	if((mx_i[i]!=(-1)) && (mx_i[i-1]==(-1)))
			// 	{
			// 		pos = false;
			// 		// cout<<'wrong order\n';
			// 		break;
			// 	}
			// }
		}
		if(pos)
		{
			vector<vector<char> > brd_2;
			brd_2.resize(n);
			for(i=0;i<n;i++)
				brd_2[i].resize(m);
			for(i=0;i<n;i++)
			{
				for(j=0;j<m;j++)
				{
					brd_2[i][j] = '.';
				}
			}
			int k;
			for(k=0;k<26;k++)
			{
				char cur = (char)((int)'a' + k);
				if(mx_i[k]==(-1))
					continue;
				for(i=mn_i[k];i<=mx_i[k];i++)
				{
					for(j=mn_j[k];j<=mx_j[k];j++)
					{
						brd_2[i][j] = cur;
					}
				}
			}
			for(i=0;i<n;i++)
			{
				for(j=0;j<m;j++)
				{
					if(brd[i][j]!=brd_2[i][j])
					{
						pos = false;
						// cout<<i<<" "<<j<<endl;
						break;
					}
					// cout<<brd_2[i][j];
				}
				if(!pos)
					break;
				// cout<<'\n';
			}
		}
		if(!pos)
			cout<<"NO\n";
		else
		{
			cout<<"YES\n";
			cout<<mxcnt<<'\n';
			for(i=0;i<mxcnt;i++)
			{
				if(mx_i[i]!=(-1))
					cout<<mn_i[i]+1<<" "<<mn_j[i]+1<<" "<<mx_i[i]+1<<" "<<mx_j[i]+1<<'\n';
				else
					cout<<mn_i[mxcnt-1]+1<<" "<<mn_j[mxcnt-1]+1<<" "<<mx_i[mxcnt-1]+1<<" "<<mx_j[mxcnt-1]+1<<'\n';
			}
		}
	}
	return 0;
}
