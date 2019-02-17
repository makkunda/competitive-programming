#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		long long int n,i;
		cin>>n;
		vector<long long int>a;
		a.resize(n);
		for(i=0;i<n;i++)
			cin>>a[i];
		sort(a.begin(),a.end());
		bool check = true;
		for(i=0;i<(n-1);i++)
		{
			if(a[i]==a[i+1])
			{
				cout<<a[i]<<"\n";
				check = false;
				break;
			}
		}
		if(check){
	    if(a[0]==(a[1]-1))
			cout<<a[n-1]<<"\n";
		else
			cout<<a[0]<<"\n";}
	}
	return 0;
}