#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define MOD 100000000
int main()
{
	int n1,n2,k1,k2;
	cin>>n1>>n2>>k1>>k2;
	vector<vector<vector<int> > > foot;
	vector<vector<vector<int> > > horse;
	int i,j,k,l;
	for(i=0;i<=n1;i++)
	{
		vector<vector<int> > v;
		for(j=0;j<=n2;j++)
		{
			vector<int> v1;
			v1.resize(k1+1);
			v.push_back(v1);
		}
		foot.push_back(v);
	}
	for(i=0;i<=n1;i++)
	{
		vector<vector<int> > v;
		for(j=0;j<=n2;j++)
		{
			vector<int> v1;
			v1.resize(k2+1);
			v.push_back(v1);
		}
		horse.push_back(v);
	}
	for(i=1;i<=n1;i++)
	{
		for(j=1;j<=n2;j++)
		{
			k = 1;
			for(l=1;l<=k1;l++)
			{
				horse[i][j][k] = (horse[i][j][k] + foot[i-1][j][l])%MOD;
			}
			for(l=1;l<=k2;l++)
			{
				foot[i][j][k] = (foot[i][j][k] + horse[i][j-1][l])%MOD;
			}
		}
	}
	return 0;
}