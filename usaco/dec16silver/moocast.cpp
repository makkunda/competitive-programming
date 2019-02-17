#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;
long int dist(int x1,int y1,int x2,int y2)
  {
  	long int x = (x1 - x2)*(x1 - x2);
  	long int y = (y1 - y2)*(y1 - y2);
  	long int d = (long int)(ceil(sqrt(x+y)));
  	return d;
  }
int main()
{
	ifstream fin("moocast.in");
	ofstream fout("moocast.out");
	int n,i,j;
	long int x[200],y[200],p[200];
	vector<vector <int> > adj;
	fin>>n;
	adj.resize(n);
	for(i=0;i<n;i++)
	{
		fin>>x[i]>>y[i]>>p[i];
	}
	for(i=0;i<n;i++)
	  {
	  	for(j=0;j<n;j++)
	  	{
	  		long int d = dist(x[i],y[i],x[j],y[j]);
	  		if(d<=p[i] && i!=j)
	  			{
	  				adj[i].push_back(j);
	  				//adj[j].push_back(i);
	  			}
	  	}
	  }
	int mark[200];
	int count[200];
	for(i=0;i<n;i++)
	  {
	  	mark[i] = -1;
	  	count[i] = 0;
	  }  
	int ctr = -1;
	int ans = 0;
	for(i=0;i<n;i++)
	 {
	 	if(1)
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
	 				if(mark[adj[u][j]]!=ctr)
	 				{
	 					mark[adj[u][j]] = ctr;
	 					count[ctr]++;
	 					q.push(adj[u][j]);
	 				}
	 			}
	 		}
	 		if(count[ctr]>ans)
	 			  ans = count[ctr];
	 	}
	 } 
	fout<<ans<<"\n";  	 
	return 0;
}