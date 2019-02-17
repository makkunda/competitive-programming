#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
	int n,m,i,j;
	cin>>n>>m;
	vector<vector<int> > adj;
	adj.resize(n+1);
	int u,v;
	for(i=0;i<m;i++)
	{
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<int> d;
	d.resize(n+1);
	for(i=0;i<=n;i++)
		d[i]=-1;
	bool np = false;
	for(i=1;i<=n;i++)
	{
		if(d[i]==-1)
		{
			queue<int> q;
			q.push(i);
			d[i]=0;
			while(!q.empty())
			{
				int x = q.front();
				q.pop();
				int temp = 1 - d[x];
				for(j=0;j<adj[x].size();j++)
				{
					int v = adj[x][j];
					if(d[v]==-1)
					{
						d[v]=temp;
						q.push(v);
					}
					else if(d[v]!=temp)
						np = true;
				}
			}
		}
	}
	if(np)
		cout<<-1<<'\n';
	else
	{
		int z = 0;
		int o = 0;
		for(i=1;i<=n;i++)
		{
			if(d[i]==1)
				o++;
			else
				z++;
		}
		cout<<o<<'\n';
		for(i=1;i<=n;i++)
		{
			if(d[i]==1)
				cout<<i<<" ";
		}
		cout<<'\n'<<z<<'\n';
		for(i=1;i<=n;i++)
		{
			if(d[i]==0)
				cout<<i<<" ";
		}
	}
	return 0;
}
