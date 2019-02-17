#include <algorithm>
#include <iostream>
#include <vector>
#define ll long long int
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long int n,q,i;
		cin>>n>>q;
		vector<ll> len;
		len.resize(n);
		for(i=0;i<n;i++)
			cin>>len[i];
		vector<pair<ll,ll> > k;
		for(i=0;i<q;i++)
		{
			ll tmp ;
			cin>>tmp;
			k.push_back(make_pair(tmp,i));
		}
		sort(len.begin(),len.end());
		sort(k.begin(),k.end());

		/* do something  */
		for(i=0;i<q;i++)
		{
			ll k1 = k[i].first;
			
		}
		sort(k.begin(),k.end());
		for(i=0;i<q;i++)
		{
			cout<<k[i].second<<"\n";
		}
	}
	return 0;
}