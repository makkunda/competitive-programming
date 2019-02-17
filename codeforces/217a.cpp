#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
	int n,i,j;
	int x[100],y[100];
	cin>>n;
	for(i=0;i<n;i++)
		cin>>x[i]>>y[i];
	vector<vector<int> > adj;
	adj.resize(n);
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if((x[i]==x[j])||(y[i]==y[j]))
			{
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
		}
	}
	vector<int> col;
	col.resize(n);
	int mc = 0;
	for(i=0;i<n;i++)
	{
		if(col[i]==0)
		{
			mc++;
			col[i]=mc;
			queue<int> q;
			q.push(i);
			while(!q.empty())
			{
				int x = q.front();
				q.pop();
				for(j=0;j<adj[x].size();j++)
				{
					int v = adj[x][j];
					if(col[v]==0)
					{
						col[v]=mc;
						q.push(v);
					}
				}
			}
		}
	}
	cout<<mc-1<<'\n';
	return 0;
}