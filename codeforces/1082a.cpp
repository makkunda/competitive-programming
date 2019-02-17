#include <iostream>
#include <vector>
using namespace std;
long ab(long x)
{
	if(x>0)
		return x;
	return (-1*x);
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long int n,x,y,d;
		cin>>n>>x>>y>>d;
		int ans = -1;
		if((x%d)==(y%d))
		{
			ans = ab(x-y)/d;
		}
		if((y%d)==1)
		{
			long t1 = x/d;
			if((x%d)==1)
				
		}

	}
	return 0;
}