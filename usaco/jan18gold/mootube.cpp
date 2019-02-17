#include <iostream>
#include <fstream>
#include <vector>
#include <utility>

using namespace std;
long long int n,q;
vector<vector<pair<long long int,long long int> > > adj;
// vector<bool> vis;
long long int dfs(long long int k,long long int v,long long int per)
{
	// vis[v]=true;
	int cnt = 0;
	long long int ans = 1;
	long long int i;
	for(i=0;i<adj[v].size();i++)
	{
		long long int u,r;
		u=adj[v][i].first;
		r=adj[v][i].second;
		if(u!=per)
		{
			if(r>=k)
				ans = ans + dfs(k,u,v);
		}
	}
	return ans;
}
int main()
{
	freopen("mootube.in","r",stdin);
	freopen("mootube.out","w",stdout);
	cin>>n>>q;
	long long int i,u,v,r;
	adj.resize(n+1);
	for(i=0;i<(n-1);i++)
	{
		cin>>u>>v>>r;
		adj[u].push_back(make_pair(v,r));
		adj[v].push_back(make_pair(u,r));
	}
	long long int k;
	while(q--)
	{
		cin>>k>>v;
		// vis.resize(0);
		// vis.resize(n+1);
		// for(i=0;i<=n;i++)
		// 	vis[i]=false;
		cout<<(dfs(k,v,-1)-1)<<'\n';
	}
	return 0;
}