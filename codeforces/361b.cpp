#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int n,k,i;
	cin>>n>>k;
	if(k==n)
		cout<<"-1\n";
	else if(k==(n-1))
	{
		for(i=1;i<=n;i++)
			cout<<i<<" ";
	}
	else
	{
		cout<<k+2<<" ";
		for(i=2;i<=(k+1);i++)
			cout<<i<<" ";
		for(i=(k+2);i<n;i++)
			cout<<(i+1)<<" ";
		cout<<1<<" ";
	}
	return 0;
}