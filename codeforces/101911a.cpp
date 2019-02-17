#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define pb push_back
#define mp make_pair
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector<pair<long,long> > a;
	long n,m,d;
	long i,j,x;
	cin>>n>>m>>d;

	for(i=0;i<n;i++)
	{
		cin>>x;
		a.pb(mp(x,i));
	}
	sort(a.begin(),a.end());
	
	return 0;
}