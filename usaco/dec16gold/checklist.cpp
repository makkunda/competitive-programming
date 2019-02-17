#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;
#define inf 3e9+1
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
long int dist(int x1,int y1,int x2,int y2)
  {
  	long int d = (x1 - x2)*(x1 - x2) + (y1-y2)*(y1-y2) ;
  	return d;
  } 
int main()
{
	ifstream fin("checklist.in");
	ofstream fout("checklist.out");
	int h,g,i,j;
	fin>>h>>g;
	int xh[1000],yh[1000],xg[1000],yg[1000];
	for(i=0;i<h;i++)
	{
		fin>>xh[i]>>yh[i];
	}
	for(i=0;i<g;i++)
	{
		fin>>xg[i]>>yg[i];
	}
	long int d1[1001][1001],d2[1001][1001];//d1[i][j] means i hols and g guerns have been reached with last hol and d2 last guern
	for(i=0;i<=g;i++)
		d2[0][i]=d1[0][i] = inf;
	d1[1][0] = 0;d2[1][0]=inf;d1[1][1] = inf;d2[1][1] = dist(xh[0],yh[0],xg[0],yg[0]);
	for(j=2;j<=g;j++)
	{
		d1[1][j] = inf;
		d2[1][j] = d2[1][j-1] + dist(xg[j-2],yg[j-2],xg[j-1],yg[j-1]);
	}
	for(i=2;i<=h;i++)
	{
		d1[i][0] = d1[i-1][0] + dist(xh[i-2],yh[i-2],xh[i-1],yh[i-1]);
		d2[i][0] = inf;
	}
	for(i=2;i<=h;i++)
	{
		for(j=1;j<=g;j++)
		{
			long int dh = d1[i-1][j] + dist(xh[i-1],yh[i-1],xh[i-2],yh[i-2]);
			long int dg = d2[i-1][j] + dist(xh[i-1],yh[i-1],xg[j-1],yg[j-1]);
			d1[i][j] = mn(dh,dg);
			if(j>1){
			dh = d1[i][j-1] + dist(xh[i-1],yh[i-1],xg[j-1],yg[j-1]);
			dg = d2[i][j-1] + dist(xg[j-2],yg[j-2],xg[j-1],yg[j-1]);
			d2[i][j] = mn(dh,dg);}
			else
			{
				d2[i][j] = d1[i][j-1] + dist(xh[i-1],yh[i-1],xg[j-1],yg[j-1]);
			}
		}
	}
	if(h!=1)
	 fout<<d1[h][g]<<"\n";
	else
		fout<<d2[h][g]<<"\n";
	return 0;
}