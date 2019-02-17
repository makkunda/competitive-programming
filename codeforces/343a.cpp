#include <iostream>
#include <vector>
using namespace std;
#define ll long long int 
int main()
{
	ll a,b;
	cin>>a>>b;
	if(a==1 || b==1)
		cout<<max(a,b)<<'\n';
	else
	{
		ll sum = a/b;
		a = a%b;
		while(b>1)
		{
			ll temp = b/a;
			sum = sum + temp;
			ll temp1 = b%a;
			b = a;
			a = temp1;
		}
		cout<<sum<<'\n';
	}
	return 0;
}