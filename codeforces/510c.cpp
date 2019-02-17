#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<vector<int> > adj;
vector<int> topol;
vector<int> mark;
bool np ;
void dfs(int x)
{
	if(mark[x]==2)
		return;
	if(mark[x]==1)
	{
		np = true;
		return ;
	}
	mark[x]=1;
	for(int i = 0;i<adj[x].size();i++)
		dfs(adj[x][i]);
	mark[x]=2;
	topol.push_back(x);
	return ;
}
int main()
{
	int n,i,j,k;
	vector<string> x;
	cin>>n;
	x.resize(n);
	for(i=0;i<n;i++)
		cin>>x[i];
	adj.resize(26);
	np = false;
	for(i=0;i<(n-1);i++)
	{
		int l1,l2;
		l1=x[i].length();
		l2 = x[i+1].length();
		int l = min(l1,l2);
		bool done = false;
		for(j=0;j<l;j++)
		{
			int n1,n2;
			n1 = (int)x[i][j] - (int)'a';
			n2 = (int)x[i+1][j] - (int)'a';
			if(n1!=n2)
			{
				adj[n1].push_back(n2);
				//cout<<x[i][j]<<"->"<<x[i+1][j]<<'\n';
				done = true;
				break;
			}
		}
		if(!done)
		{
			if(l1>l2)
				{
					np = true;
					break;
				}
				
		}
	}
	if(np)
		cout<<"Impossible\n";
	else
	{
		mark.resize(26);
		for(i=0;i<26;i++)
			dfs(i);
		if(np)
			cout<<"Impossible\n";
		else
		{
			for(i=25;i>=0;i--)
				cout<<((char)(topol[i]+(int)'a'));
			cout<<'\n';
		}
	}
	return 0;
}
