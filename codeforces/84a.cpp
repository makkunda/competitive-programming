#include <iostream>
#define lli long long int
using namespace std;
int main()
{
	lli n;
	cin>>n;
	lli ans = 0;
	if(n%2==0)
	{
		ans = 3*n/2;
	}
	else
	{
		ans = 3*(n+1)/2;
		ans = ans - 1;
	}
	cout<<ans;
	return 0;
}