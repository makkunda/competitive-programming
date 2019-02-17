#include <iostream>
#include <vector>
#include <string>
#define ll long long int
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n;
	ll i;
	cin>>n;
	vector<ll> c;
	c.resize(n);
	for(i=0;i<n;i++)
		cin>>c[i];
	string prev,prevrev,cur,currev;
	cin>>prev;
	vector<vector<bool> > comp;
	comp.resize(n);
	for(i=0;i<n;i++)
		comp[i].resize(4);
	prevrev = prev;
	reverse(prevrev.begin(),prevrev.end());
	for(i=1;i<n;i++)
	{
		cin>>cur;
		currev = cur;
		reverse(currev.begin(),currev.end());
		
	}
	return 0;
}