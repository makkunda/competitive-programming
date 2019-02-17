
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstdio>
//#include <bits/stdc++.h>
#define inf 1e15+1
using namespace std;

int main() {
    long int n,m,i,j,u;
    long int a,b,v,k,w;
    long long int x;
    cin>>n>>m;
    vector< vector <long int> > adj1;
    adj1.resize(n+1);
    for(i=1;i<n;i++)
    {
        cin>>a>>b;
        adj1[a].push_back(b);
    }
    vector< vector <pair<long int,long long int> > > adj2;
    adj2.resize(n+1);
  //  vector<vector<long int> > d;
  //  d.resize(m);
  //  for(i=0;i<m;i++)
  //  	d[i].resize(n+1);
  long int d[100001];
    for(i=0;i<m;i++)
    {
     //  fill(d,d+(n+1),0);
     for(j=0;j<n+1;j++)
          d[j]=0;
        cin>>v>>k>>w;
        {
            d[v] = 1;
            queue<long int> q;
            q.push(v);
            while(!q.empty())
            {
                u = q.front();
                q.pop();
                for(j=0;j<adj1[u].size();j++)
                 {
                     
                     if(d[adj1[u][j]]==0)
                         {
                             q.push(adj1[u][j]);
                             d[adj1[u][w]] = d[u] + 1;
                         }
                 }
            }
        }
        for(j=1;j<=n;j++)
        {
            if(j!=v)
             {
                 if(d[j]<=(k+1))
                   {
                       pair <long int,long long int> ab(v,w);
                       adj2[j].push_back(ab);
                   }
             }
        }
        
    }
    long long int d1[100001] ;
    bool mark[100001] ;
    for(j=0;j<=n;j++)
             d1[j]=inf;
    for(j=0;j<=n;j++)
             mark[j]=false;
    d1[1] = 0;
    cout<<d1[1]<<" ";
    while(true)
    {
        x = inf;
        u = -1;
        for(i=1;i<=n;i++)
          {
              if(!mark[i]&&(x>=d1[i]))
                {
                    x=d1[i];
                    u=i;
                }
          }
         if(u==-1)
           break;
         mark[u] = true;  
         for(long int y = 0;y<adj2[u].size();y++)
          {
              if(d1[adj2[u][y].first]>(d1[u] + adj2[u][y].second))
                {  d1[adj2[u][y].first] = d1[u] + adj2[u][y].second ;
                   cout<<d1[u] + adj2[u][y].second<<" ";
                }
          }
           
    }
    
    long int q,h;
    cin>>q;
    cout<<endl;
    for(i=0;i<q;i++)
     {
         cin>>h;
         cout<<d1[h]<<endl;
     }
    return 0;
}
