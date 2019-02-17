#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
	int n;
	cin>>n;
	vector<vector<int> > adj;
	adj.resize(n+1);
	int i,j,u,v;
	for(i=0;i<(n-1);i++)
	{
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<int> col;
	col.resize(n+1);
	queue<int> q;
	q.push(1);
	col[1]=1;
	while(!q.empty())
	{
		int x = q.front();
		q.pop();
		int cl = col[x];
		int cl1;
		if(cl==1)
			cl1=2;
		else
			cl1=1;

		for(i=0;i<adj[x].size();i++)
		{
			int v = adj[x][i];
			if(col[v]==0)
			{
				col[v]=cl1;
				q.push(v);
			}
		}
	}
	long long int on=0,tw=0;
	for(i=1;i<=n;i++)
	{
		if(col[i]==1)
			on++;
		else
			tw++;
	}
	long long int ans = on*tw - (n-1);

	cout<<ans;
	return 0;
}