#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <set>
using namespace std;
#define inf 1000000000000001
int main()
{
	long long int n,m,i;
	cin>>n>>m;
	vector<vector<pair<int,long long int> > > adj;
	adj.resize(n);
	for(i=0;i<m;i++)
	{
		int a,b;
		long long int w;
		cin>>a>>b>>w;
		adj[a-1].push_back(make_pair(b-1,w));
		adj[b-1].push_back(make_pair(a-1,w));
	}
	vector<long long int> d;
	d.resize(n);
	for(i=0;i<n;i++)
		d[i] = inf;
	d[0]=0;
	vector<int> p;
	p.resize(n);
	for(i=0;i<n;i++)
		p[i]=-1;
	set<pair<long long int,int> > s;
	s.insert(make_pair(0,0));
	while(!s.empty()) 
	{
		int u ;
		u = s.begin() -> second;
		s.erase(s.begin());
		for(i=0;i<adj[u].size();i++)
		{
			pair<int,long long int> p1 = adj[u][i];
			if(d[p1.first]>(d[u]+p1.second))
			{
				s.erase(make_pair(d[p1.first], p1.first));
				d[p1.first] = d[u] + p1.second;
				s.insert(make_pair(d[p1.first], p1.first));
				p[p1.first]=u;
			}

		}
	}
	if(d[n-1]==inf)
		cout<<-1;
	else
	{
		vector<int> path;
		int per = n-1;
		while(per!=0)
		{
			path.push_back(per);
			per = p[per];
		}
		path.push_back(0);
		int l = path.size();
		for(i=l-1;i>=0;i--)
			cout<<(path[i]+1)<<" ";
	}
	return 0;
}