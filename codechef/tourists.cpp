#include <iostream>
#include <vector>
#include <utility>
#include <list>
using namespace std;
#define ii long int
vector<vector<pair<long int,int> > > adj;
//list<long int> cyc;
void EulerTour( long int u) 
{
   // cout<<u<<" ";
for (long int j = 0; j < (long int)adj[u].size(); j++) 
{
pair<long int,int> v = adj[u][j];
if (v.second==1) 
//cout<<v.first<<" "<<v.second<<" ";
{ // if this edge can still be used/not removed
adj[u][j].second = 2; // make the weight of this edge to be 0 (â��removedâ��)
 for (ii k = 0; k < (ii)adj[v.first].size(); k++) 
 {
pair<long int,int> uu = adj[v.first][k];
if (uu.first == u && uu.second==1) 
	{
	    //cout<<uu.first<<" "<<uu.second<<"\n";
        adj[v.first][k].second = 0;
        break; 
	}
	}
EulerTour(v.first);
 }
}
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
	//cyc.clear();
	long int n,e,i,a,b;
	cin>>n>>e;
	vector<long int> par(n+1,0);
	adj.resize(n+1);
	pair<long int,int> x;
	vector<long int> a1,b1;
	a1.resize(e);b1.resize(e);
	for(i=0;i<e;i++)
	{
		cin>>a>>b;
		x.first = a;
		x.second = 1;
		adj[b].push_back(x);
		x.first = b;
		adj[a].push_back(x);
		par[a]++;par[b]++;
		a1[i]=a;b1[i]=b;
	}
	bool ans = true;
	for(i=1;i<=n;i++)
	{
		if(par[i]%2==1)
		{
			ans = false;
			break;
		}
 
	}
	if(!ans)
		cout<<"NO\n";
	else
	{
		cout<<"YES"<<endl;
		EulerTour(1);
	   /*	long int y = *cyc.begin();
		vector<long int> aa;
		aa.push_back(y);
		for (list<long int>::iterator it = cyc.begin(); it != cyc.end(); it++)
            {
               // cout<<*it<<"\n";
               aa.push_back(*it);
            }
        long int m = aa.size();
        aa[0]=aa[m-1];
        for(i=m-1;i>0;i--)
              cout<<aa[i]<<" "<<aa[i-1]<<"\n";*/
        long int j;
        for(i=0;i<e;i++)
         {
             long int a=a1[i],b=b1[i];
             for(j=0;j<adj[a].size();j++)
                   {
                       if(adj[a][j].first==b)
                            {
                                if(adj[a][j].second==2)
                                     cout<<a<<" "<<b<<"\n";
                                else
                                     cout<<b<<" "<<a<<"\n";
                                break;     
                            }
                   }
         }
	}
	return 0;
} 