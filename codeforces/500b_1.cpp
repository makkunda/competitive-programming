#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
	int n,i,j;
	cin>>n;
	vector<int> p;
	p.resize(n);
	for(i=0;i<n;i++)
		cin>>p[i];
	char mat[300][300];
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			cin>>mat[i][j];
	}
	vector<vector<int> > adj;
	adj.resize(n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(mat[i][j]=='1')
				adj[i].push_back(j);
		}
	}
	for(i=0;i<n;i++)
	{
		int mn = p[i];
		int pos = i;
		vector<int> d;
		d.resize(n);
		d[i]=1;
		queue<int> q;
		q.push(i);
		while(!q.empty())
		{
			int x = q.front();
			q.pop();
			int vl = p[x];
			if(vl<mn)
				pos = x;
			mn = min(mn,vl);
			for(j=0;j<adj[x].size();j++)
			{
				int v = adj[x][j];
				if(d[v]==0)
				{
					d[v]=1;
					q.push(v);
				}
			}
		}
		int temp = p[i];
		p[i] = mn;
		p[pos] = temp;
	}
	for(i=0;i<n;i++)
		cout<<p[i]<<" ";
	return 0;
}