#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;
long int mx(long int a,long int b)
 {
 	if(a>b)
 		return a;
 	return b;
 }
 long int mn(long int a,long int b)
 {
 	if(a<b)
 		return a;
 	return b;
 }
int id[1000];
int root(int y)
  {
  	 int x = y;
  	while(id[x]!=x)
  	{
  		id[x] = id[id[x]];
  		x = id[x];
  	}
  	return x;
  } 
int main()
{
	ifstream fin("moocast.in");
	ofstream fout("moocast.out");
	int x[1000],y[1000];
	long int d[1000][1000];
	long int mnv[1000];
	int n,j,i;
	vector<pair<long int,pair<int,int> > > p;
	pair<long int,pair<int,int> > tmp;
	fin>>n;
	for(i=0;i<n;i++)
	{
		fin>>x[i]>>y[i];
		d[i][i] = 1250000001;
		mnv[i] = 1250000001;
		id[i] = i;
	}

	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			long int x1 = (x[i] - x[j])*(x[i] - x[j]) + (y[i]-y[j])*(y[i]-y[j]);
			d[i][j] = d[j][i] = x1;
			tmp.first = x1;
			tmp.second.first = i;
			tmp.second.second = j;
			p.push_back(tmp);
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			 mnv[i] = mn(mnv[i],d[i][j]);
	}
	sort(mnv,mnv+n);
	sort(p.begin(),p.end());
	long int ans,cost;
	int x2,y2,r1,r2;
	for(long int ij = 0;ij<p.size();ij++)
	{
		x2 = p[ij].second.first;
		y2 = p[ij].second.second;
		cost = p[ij].first;
		r1 = root(x2);
		r2 = root(y2);
		if(r1!=r2)
		{
			ans = cost;
			id[r1] = r2;
		}
	}
	//ans = mn(mnv[n-1],ans);
	fout<<ans<<"\n";
	return 0;
}