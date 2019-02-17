#include <iostream>
using namespace std;
#define ll long long int
ll gcd(ll a,ll b)
	{
		ll a1,b1;
		a1 = max(a,b);
		b1 = min(a,b);
		if(b1==0)
			return a1;
		else
			return gcd(b1,a1%b1);
	}
int main()
{
	long long int n;
	cin>>n;
	long long int ans = 1,temp;
	if(n==1)
		cout<<1;
	else if(n==2)
		cout<<2;
	else{
		long long int i;
		if(n%2)
			ans = n*(n-1)*(n-2);
		else
		{
			ans = (n-3)*(n-1)*(n-2);
			for(i=n-2;i>0;i--)
			{
				temp = n*(n-1)*i;
				ll g1,g2;
				g1 = gcd(n,i);
				g2 = gcd(n-1,i);
				temp = temp/g1;
				temp = temp/g2;
				ans = max(ans,temp);
			}
		}
		cout<<ans<<endl;
	}

	return 0;
}