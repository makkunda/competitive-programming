#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int main()
{
	int n,m;
	vector<vector<int> >adj;
	adj.resize(20001);
	int i,j;
	for(i=1;i<=20000;i++)
		adj[i].push_back(i-1);
	for(i=1;i<=10000;i++)
		adj[i].push_back(2*i);
	cin>>n>>m;
	vector<int> d;
	d.resize(20001);
	for(i=0;i<=20000;i++)
		d[i]=-1;
	queue<int> q;
	q.push(n);
	d[n]=0;
	while(!q.empty())
	{
		int x = q.front();
		q.pop();
		int cur = d[x];
		for(i=0;i<adj[x].size();i++)
		{
			int v = adj[x][i];
			if(d[v]==-1)
			{
				d[v]=cur+1;
				q.push(v);
			}
		}
	}
	cout<<d[m]<<'\n';
	return 0;
}