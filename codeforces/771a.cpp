#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main()
{
	int n,m,i,j;
	cin>>n>>m;
	vector<vector<int> > adj;
	adj.resize(n+1);
	for(i=0;i<m;i++)
	{
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<long long int> ed;
	ed.resize(n+1);
	vector<long long int> nd;
	nd.resize(n+1);
	int mx = 0;
	vector<int> d;
	d.resize(n+1);
	for(i=1;i<=n;i++)
	{
		if(d[i]==0)
		{
			mx++;
			d[i] = mx;
			queue<int> q;
			q.push(i);
			while(!q.empty())
			{
				int x = q.front();
				q.pop();
				nd[mx]++;
				ed[mx]=ed[mx]+adj[x].size();
				for(j=0;j<adj[x].size();j++)
				{
					int v = adj[x][j];
					if(d[v]==0)
					{
						d[v]=mx;
						q.push(v);
					}
				}
			}
		}
	}
	bool done = true;
	for(i=1;i<=mx;i++)
	{
		//cout<<i<<" "<<ed[i]<<" "<<nd[i]<<'\n';
		long long int exp = nd[i]*(nd[i]-1);
		if(exp!=ed[i])
		{
			done = false;
			break;
		}
	}
	//cout<<mx<<endl;
	if(done)
		cout<<"YES\n";
	else
		cout<<"NO\n";
	return 0;
}