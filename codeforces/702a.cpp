#include <iostream>
using namespace std;
int main()
{
	long int n,i,cur=1,max = 1;
	long long int a[100000];
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(i=1;i<n;i++)
	{
		if(a[i]>a[i-1])
			cur++;
		else{
			if(cur>max)
				 max = cur;
			cur = 1;	
		}
	}
	if(cur>max)
		 max = cur;
	cout<<max<<"\n";	
	return 0;
}