#include <iostream>
#include <vector>
using namespace std;
int main()
{
	long long int a,b;
	cin>>a>>b;
	long long int a1 =a,b1=b;
	int a2=0,a3=0,a5=0,b2=0,b3=0,b5=0;
	{
		while(a1%2==0)
			{a1 = a1/2;a2++;}
		while(a1%3==0)
			{a1 = a1/3;a3++;}
		while(a1%5==0)
			{a1 = a1/5;a5++;}
	}
	{
		while(b1%2==0)
			{b1 = b1/2;b2++;}
		while(b1%3==0)
			{b1 = b1/3;b3++;}
		while(b1%5==0)
			{b1 = b1/5;b5++;}
	}
	if(a1!=b1)
		cout<<"-1\n";
	else
	{
		int ans = 0;
		ans = ans + max(a2,b2) - min(a2,b2);
		ans = ans + max(a3,b3) - min(a3,b3);
		ans = ans + max(a5,b5) - min(a5,b5);
		cout<<ans<<endl;
	}
	return 0;
}