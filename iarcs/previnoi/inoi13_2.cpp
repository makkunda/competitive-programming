#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int main()
{
	int n,k,i,j,p,x;
	vector<int> a[300];
	cin>>n>>k;
	//vector<int> fam;
	//fam.resize(n);
	int fam[300];
	for(i=0;i<n;i++)
	{
		fam[i] = 0;	
	}
	for(i=0;i<n;i++)
	{
		cin>>p;
		for(j=0;j<p;j++)
		{
			cin>>x;
			a[i].push_back(x);
		}
		sort(a[i].begin(),a[i].end());
	}
	vector<vector<int> > adj;
	adj.resize(n);
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			int ct = 0;
			int l;
			for(l=0;l<a[i].size();l++)
			{
				int xy = a[i][l];
				if(binary_search(a[j].begin(),a[j].end(),xy))
				     ct++;		
			}
			if(ct>=k)
				  {
				  	adj[i].push_back(j);
				  	adj[j].push_back(i);
				  }
		}
	}
	fam[0] = 1;
	queue<int> q;
	q.push(0);
	int cntr = 1;
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		for(i=0;i<adj[u].size();i++)
			  {
			  	int xy = adj[u][i];
			  	if(fam[xy]==0)
			  	{
			  		fam[xy]=1;
			  		cntr++;
			  		q.push(xy);
			  	}
			  }
	}
	cout<<cntr<<"\n";
	return 0;
} 