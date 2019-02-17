#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
	int n,t,i;
	cin>>n>>t;
	vector<vector<int> > adj;
	adj.resize(n+1);
	vector<bool> visit;
	visit.resize(n+1);
	for(i=0;i<=n;i++)
		visit[i]=false;
	for(i=1;i<n;i++)
	{
		int a;
		cin>>a;
		adj[i].push_back(a+i);
	}
	queue<int> q;
	visit[1]=true;
	q.push(1);
	while(!q.empty())
	{
		int x = q.front();
		q.pop();
		for(i=0;i<adj[x].size();i++)
		{
			int v = adj[x][i];
			if(visit[v]==false)
			{
				visit[v]=true;
				q.push(v);
			}
		}
	}
	if(visit[t])
		cout<<"YES\n";
	else
		cout<<"NO\n";
	return 0;
}