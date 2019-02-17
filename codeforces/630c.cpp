#include <iostream>
using namespace std;
int main()
{
	int n,i;
	cin>>n;
	long long int ans = 1;
	for(i=0;i<=n;i++)
		ans = ans*2;
	ans = ans - 2;
	cout<<ans<<endl;
	return 0;
}