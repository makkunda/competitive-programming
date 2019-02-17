#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>
using namespace std;
vector<vector<int> > adj;
vector<bool> vis;
long double dfs(int a)
 {
 	vis[a]=true;
 	if(adj[a].size()<1)
 		return (long double)0.0;
 	long double ans = 0.0;
 	int cnt = 0;
 	for(int i=0;i<adj[a].size();i++)
 	{
 		if(!vis[adj[a][i]])
 		{
 			cnt++;
 			ans = ans + dfs(adj[a][i]);
 		}
 	}
 	if(cnt==0)
 		return (long double)0.0;
 	ans = ans/((long double)cnt);
 	ans = ans + (long double)1.0;
 	return ans; 
 }
int main()
{
	int n;
	cin>>n;
	adj.resize(n+1);
	vis.resize(n+1);
	int u,v,i;
	for(i=0;i<=n;i++)
		vis[i]=false;
	for(i=1;i<n;i++)
	{
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	long double ans = dfs(1);
	// ans = 1.23456789;
	cout<<setprecision(20)<<ans<<endl;
	return 0;
}