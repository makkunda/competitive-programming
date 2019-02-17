#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int main()
{
	int n,m,i,j;
	vector<int> a;
	vector<int> b;
	cin>>n;
	a.resize(n);
	for(i=0;i<n;i++)
		cin>>a[i];
	cin>>m;
	b.resize(m);
	for(i=0;i<m;i++)
		cin>>b[i];
	int count = 0;
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	i=0;j=0;
	while((i<n)&&(j<m))
	{
		if(b[j]<(a[i]-1))
			j++;
		else if(b[j]>(a[i]+1))
			i++;
		else
		{
			i++;j++;count++;
		}
	}
	cout<<count<<'\n';
	return 0;
}