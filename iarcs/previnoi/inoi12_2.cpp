#include <iostream>
#include <vector>

using namespace std;
int main()
{
	vector<long int> a,b;
	long int n,i,mx,x;
	cin>>n;
	a.resize(n);
	b.resize(n);
	cin>>a[0];
	 mx = a[0] + n;
	for(i=1;i<n;i++)
	{
		cin>>a[i];
		x = a[i] + i;
		if(x>mx)
			 mx = x;
	}
	b[n-1] = mx;
	for(i=1;i<n;i++)
	{
		mx = mx - 1;
		if((a[i] + n)>mx)
			  mx = a[i] + n;
		b[n-i-1] = mx;	
	}
	for(i=0;i<n;i++)
		 cout<<b[i]<<" ";
 	return 0;
}