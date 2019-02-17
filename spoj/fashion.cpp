#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	int n;
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		vector<int> a(n),b(n);
		int x,i;
		long int ans = 0;
		for(i=0;i<n;i++)
		   cin>>a[i];
		for(i=0;i<n;i++)
		 {
		 	cin>>b[i];
		 }   
		sort(a.begin(),a.end());
		sort(b.begin(),b.end());
		for(i=0;i<n;i++)
			  ans = ans + a[i]*b[i];
		cout<<ans<<"\n"; 
	}
	return 0;
}