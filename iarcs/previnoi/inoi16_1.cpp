#include <iostream>
#include <vector>
 using namespace std; 
#define inf 1000000000
#define lll long int
vector<long int> a;
vector<vector<long int> > adj;
vector<bool> vis;
vector<long int> mxc,mnc;
lll mx(lll a,lll b)
 {
 	if(a>b)
 		return a;
 	return b;
 }
 lll mn(lll a,lll b)
 {
 	if(a<b)
 		return a;
 	return b;
 }
 void dfs(lll root)
  {
  	 vis[root] = true;
  	 mxc[root] = a[root];
  	 mnc[root] = a[root];

  	 	for(lll i=0;i<adj[root].size();i++)
  	 	{
  	 		lll x = adj[root][i];
  	 		if(!vis[x])
  	 		{
  	 			dfs(x);
  	 		}
  	 		mxc[root] = mx(mxc[root],mxc[x]);
  	 		mnc[root] = mn(mnc[root],mnc[x]);
  	 	}
  }
int main()
{
	ios_base::sync_with_stdio(false) ;
	long int n,i,man,p;
	cin>>n;
	adj.resize(n+1);a.resize(n+1);
    vis.resize(n+1);
    mxc.resize(n+1);mnc.resize(n+1);
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		vis[i] = false;
		mxc[i] = -1*inf;mnc[i] = inf;
	}
	for(i=1;i<=n;i++)
	{
		cin>>p;
		if(p==-1)
			  man = i;
		else
		     adj[p].push_back(i);	
	}
	dfs(man);
	lll ans = 0;
	for(i=1;i<=n;i++)
	{
		//lll tmp = mx(mxc[i] - a[i],a[i] - mnc[i]);
		lll tmp = a[i] - mnc[i];
		ans = mx(ans,tmp);
	}
	cout<<ans<<"\n";
	return 0;
}