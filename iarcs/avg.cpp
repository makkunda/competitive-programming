#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int n,i,j,x,lb,ub;
	vector<int> a;
	cin>>n;
	a.resize(n);
	for(i=0;i<n;i++)
		cin>>a[i];
	sort(a.begin(),a.begin()+n);
	long int count = 0;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if((a[i]+a[j])%2 == 0)
			{
				x = (a[i] + a[j])/2;
				if(binary_search(a.begin()+i,a.begin()+j+1,x))
					{	count =count +(int)( upper_bound(a.begin()+i,a.begin()+j+1,x) - lower_bound(a.begin()+i,a.begin()+j+1,x)) ;
					}	
			}
		}
	}
	cout<<count;

	return 0;
}