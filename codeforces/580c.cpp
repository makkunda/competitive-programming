#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;
int main()
{
	int n,m,i;
	cin>>n>>m;
	vector<int> iscat;
	iscat.resize(n+1);
	for(i=1;i<=n;i++)
		cin>>iscat[i];
	vector<vector<int> > adj;
	adj.resize(n+1);
	vector<pair<int,int> > e;
	e.resize(n-1);
	for(i=0;i<(n-1);i++)
	{
		cin>>e[i].first>>e[i].second;
		adj[e[i].first].push_back(e[i].second);
		adj[e[i].second].push_back(e[i].first);
	}
	vector<int> d;
	d.resize(n+1);
	for(i=0;i<=n;i++)
		d[i]=-1;
	d[1]=0;
	queue<int> q;
	q.push(1);
	while(!q.empty())
	{
		int x = q.front();
		q.pop();
		for(i=0;i<adj[x].size();i++)
		{
			int v = adj[x][i];
			if(d[v]==-1)
			{
				// cout<<"hello world "<<x<<" "<<v<<"\n";
				d[v]=d[x]+1;
				q.push(v);
			}
		}
	}
	vector<bool> isleaf;
	isleaf.resize(n+1);
	for(i=0;i<=n;i++)
		isleaf[i]=true;
	vector<vector<int> > adj1;
	adj1.resize(n+1);
	for(i=0;i<(n-1);i++)
	{
		if(d[e[i].first]<d[e[i].second])
		{
			adj1[e[i].first].push_back(e[i].second);
			isleaf[e[i].first]=false;
			// cout<<e[i].second<<" is deeper than "<<e[i].first<<'\n';
		}
		else
		{
			// cout<<e[i].first<<" is deeper than "<<e[i].second<<'\n';
			adj1[e[i].second].push_back(e[i].first);
			isleaf[e[i].second]=false;
		}
	}
	vector<pair<int,int> > cat;
	cat.resize(n+1);
	if(iscat[1]==1)
	{
		cat[1].first = 1;
		cat[1].second = 1;
	}
	else
	{
		cat[1].first = 0;
		cat[1].second = 0;
	}
	queue<int> q1;
	vector<int> d1;
	d1.resize(n+1);
	for(i=0;i<=n;i++)
		d1[i]=-1;
	d1[1]=0;
	q1.push(1);
	while(!q1.empty())
	{
		int x = q1.front();
		q1.pop();
		for(i=0;i<adj1[x].size();i++)
		{
			int v = adj1[x][i];
			// cout<<x<<" is parent of "<<v<<"\n";
			d[v]=d[x]+1;
			if(iscat[v]==1)
				cat[v].first = cat[x].first+1;
			else
				cat[v].first =0;
			cat[v].second = max(cat[v].first,cat[x].second);
			q1.push(v);
		}
	}
	int ans = 0;
	for(i=1;i<=n;i++)
	{
		// cout<<i<<" "<<iscat[i]<<" ";
		// cout<<cat[i].first<<" "<<cat[i].second<<"\n";
		if(isleaf[i])
		{
			if(cat[i].second<=m)
				ans++;
		}
	}
	cout<<ans<<'\n';
	return 0;
}