#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
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
	int cntr = 0;
	vector<int> d;
	d.resize(n);
	for(i=0;i<n;i++)
	{
		if(d[i]==0)
		{
		cntr++;
		d[i]=cntr;
		queue<int> q;
		q.push(i);
		while(!q.empty())
		{
			int x = q.front();
			q.pop();
			for(j=0;j<adj[x].size();j++)
			{
				int v = adj[x][j];
				if(d[v]==0)
				{
					d[v]=cntr;
					q.push(v);
				}
			}
		}
		vector<int> pos;
		vector<int> val;
		for(j=0;j<n;j++)
		{
			if(d[j]==cntr)
			{
				pos.push_back(j);
				val.push_back(p[j]);
			}
		}
		sort(val.begin(),val.end());
		for(j=0;j<pos.size();j++)
			p[pos[j]]=val[j];

	}
	}
	for(i=0;i<n;i++)
		cout<<p[i]<<" ";
	return 0;
}