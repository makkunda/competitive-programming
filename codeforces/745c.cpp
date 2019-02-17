#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>
using namespace std;
#define fin cin

int main()
{
	//ifstream fin("385b-c.in");
	//ofstream fout("moocast.out");
	int n,m,k,i,j,a,b;
	vector<vector <int> > adj;
	vector<int> govt;
	fin>>n>>m>>k;
	adj.resize(n+1);
	govt.resize(k);
	for(i=0;i<k;i++)
		  fin>>govt[i];
	for(i=0;i<m;i++)
	{
		fin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int mark[1001];
	int count[1001];
	for(i=0;i<=n;i++)
	  {
	  	mark[i] = -1;
	  	count[i] = 0;
	  }  
	int ctr = -1;
	for(i=1;i<=n;i++)
	 {
	 	if(mark[i]==-1)
	 	{
	 		ctr++;
	 		queue<int> q;
	 		mark[i] = ctr;
	 		count[ctr]++;
	 		q.push(i);
	 		while(!q.empty())
	 		{
	 			int u = q.front();
	 			q.pop();
	 			for(j=0;j<adj[u].size();j++)
	 			{
	 				if(mark[adj[u][j]]!=-1)
	 				{
	 					mark[adj[u][j]] = ctr;
	 					count[ctr]++;
	 					q.push(adj[u][j]);
	 				}
	 			}
	 		}
	 	}
	 } 
	vector<int> govtnode;
	int total = 0;
	for(i=0;i<k;i++)
	  {
	  	govtnode.push_back(count[mark[govt[i]]]);
	  	total = total + count[mark[govt[i]]];
	  } 
	int a1 = n - total;
	sort(govtnode.begin(),govtnode.end());
	a1 = a1 + govtnode[k-1];
	long int ans = a1*(a1 - 1);
	for(i=0;i<(k-1);i++)
	  {
	  	ans = ans + govtnode[i]*(govtnode[i] - 1);
	  } 
	ans = ans/2;
	ans = ans - m;
	cout<<ans<<endl;   
	return 0;
}