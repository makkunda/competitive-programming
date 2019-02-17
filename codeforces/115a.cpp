#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	vector<vector<int> > adj;
	cin>>n;
	adj.resize(n);
	int p;
	vector<int> root;
	int i,j;
	vector<int> d;
	d.resize(n);
	for(i=0;i<n;i++)
		d[i]=-1;
	for(i=0;i<n;i++)
	{
		cin>>p;
		if(p==-1)
			root.push_back(i);
		else
			adj[p-1].push_back(i);
	}
	for(i=0;i<root.size();i++)
	{
		int r = root[i];
		d[r]=0;
		queue<int> q;
		q.push(r);
		while(!q.empty())
		{
			int x = q.front();
			q.pop();
			for(j=0;j<adj[x].size();j++)
			{
				int v = adj[x][j];
				d[v]=d[x]+1;
				q.push(v);
			}
		}
	}
	int mx = 1;
	for(i=0;i<n;i++)
		mx = max(mx,d[i]+1);
	cout<<mx<<'\n';
	return 0;
}