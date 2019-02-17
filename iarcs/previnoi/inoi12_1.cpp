#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;
int main()
{
	long int n,i,j;
	cin>>n;
	vector<pair<int,int> > a;
	a.resize(n);
	int x,y,z;
	for(i=0;i<n;i++)
	{
		cin>>x>>y>>z;
		pair<int,int> b(z+y,x);
		a.push_back(b);
		a[i].first = -1*(z+y);a[i].second = x;
		//cout<<a[i].first<<" "<<a[i].second<<"\n";
	}
	sort(a.begin(),a.end());
	vector<int> cob;
	vector<long int>cobpre;
	vector<int>other;
	cob.resize(n);
	cobpre.resize(n);
	other.resize(n);
	cob[0] = a[0].second;
	other[0] = -1*a[0].first;
	cobpre[0] = cob[0];
	long int mx = cob[0] + other[0];
	long int tmp=mx;
	//cout<<tmp<<"\n";
	for(i=1;i<n;i++)
	{
		other[i] = -1*a[i].first;
		cob[i] = a[i].second;
		cobpre[i] = cobpre[i-1]+cob[i];
		tmp = other[i] + cobpre[i];
		if(tmp>mx)
			 mx = tmp;
		//cout<<tmp<<"\n";	
	}
	cout<<mx<<"\n";
	return 0;
}