#include <iostream>
using namespace std;
int main()
{
	int n;
	int a[100];
	int i;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	bool pos = true;
	int diff = a[1] - a[0];
	for(i=2;i<n;i++)
	{
		if((a[i]-a[i-1])!=diff)
			pos = false;
	}
	if(pos)
		cout<<a[n-1]+diff<<endl;
	else
		cout<<a[n-1]<<endl;
	return 0;
}