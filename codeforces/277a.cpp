#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
	int n,m,i,j,k;
	cin>>n>>m;
	vector<vector<int> > l;
	l.resize(n);
	for(i=0;i<n;i++)
		l[i].resize(m);
	int zcount = 0;
	for(i=0;i<n;i++)
	{
		cin>>k;
		if(k==0)
			zcount++;
		int x;
		for(j=0;j<k;j++)
		{
			cin>>x;
			l[i][x-1]=1;
		}
	}
	if(zcount==n)
		cout<<n<<'\n';
	else
	{
		vector<vector<int> > adj;
		adj.resize(n);
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
				for(k=0;k<m;k++)
				{
					if(l[i][k]==1 && l[j][k]==1)
					{
						adj[i].push_back(j);
						adj[j].push_back(i);
						break;
					}
				}
			}
		}
		int c = 0;
		vector<int> d;
		d.resize(n);
		for(i=0;i<n;i++)
		{
			if(d[i]==0)
			{
				c++;
				d[i]=c;
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
							d[v] = c;
							q.push(v);
						}
					}
				}
			}
		}
		cout<<c-1<<'\n';

	}
	return 0;
}