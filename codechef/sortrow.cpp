#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	long long int a[300];
	vector<long long int> b,brev;
	int n,i,j;
	cin>>n;
	b.resize(n);
	brev.resize(n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			 {cin>>a[j];b[j]=a[j];}
		sort(b.begin(),b.end());
		for(j=n-1;j>=0;j--)
			brev[j]=b[n-j-1];
		long long int c=0,crev=0;
		for(j=0;j<n;j++)
		{
			int n1 = (int)(find(b.begin(),b.end(),a[j]) - b.begin());
			c = c + (n1-j)*(n1-j) ;
			crev = crev + (n-1-n1-j)*(n-1-n1-j); 
		}
		if(c<=crev){
		for(j=0;j<n;j++)
		   cout<<b[j]<<" "; }
		else
		{
			for(j=0;j<n;j++)
		      cout<<brev[j]<<" ";
		}
		cout<<"\n";   	
	}
	return 0;
}