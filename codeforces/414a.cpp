#include <iostream>
#include <vector>
using namespace std;
#define lli long long int
int main()
{
	lli n,k;
	cin>>n>>k;
	lli num = n/2;
	if(n==1 && k==0)
		cout<<5;
	else if(n==1)
		cout<<-1;
	else if(num>k)
		cout<<-1<<endl;
	else
	{
		lli num1 = k - num;
		if(num1==0)
		{
			for(lli i =1;i<=n;i++)
				cout<<i<<" ";
		}
		else
		{
			lli count = 0;
			lli i=1;
			lli skip1,skip2;
			skip1 = num1+1;
			skip2 = 2*num1+2;
			while(count<(num-1))
			{
				if(i==skip1||(i+1)==skip1)
					i=i+2;
				else if(i==skip2||(i+1)==skip2)
					i=i+2;
				else
				{
					cout<<i<<" "<<i+1<<" ";
					i=i+2;
					count++;
				}
			}
			cout<<skip1<<" "<<skip2<<" ";
			if(n%2)
				cout<<300000000;
		}
	}
	return 0;
}