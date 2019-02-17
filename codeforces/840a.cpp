#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;
int main()
{
	long long int m,i,x;
	vector<long long int> a;
	vector<long long int> aprime;
	vector<pair<long long int,long long int> > b;
	cin>>m;
	a.resize(m);
	aprime.resize(m);
	for(i=0;i<m;i++)
		cin>>a[i];
	sort(a.begin(),a.end());
	for(i=0;i<m;i++)
	{
		cin>>x;
		b.push_back(make_pair(x,i));
	}
	sort(b.begin(),b.end());
	for(i=0;i<m;i++)
		aprime[b[i].second] = a[m-1-i];
	for(i=0;i<m;i++)
		cout<<aprime[i]<<" ";
	return 0;
}