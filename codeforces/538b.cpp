#include <iostream>
#include <string>
using namespace std;
int main()
{
	long int n,i,j=0,ld;
	int digits=0;
	int max = 0;
	long int temp;
	cin>>n;
	temp = n;
	int a[8];
	while(temp>0)
	{
		int x = temp%10;
		temp = temp/10;
		digits++;
		if(x>max)
			 max = x;
	}
	temp = n;
	int ctr = digits - 1;
	while(temp>0)
	{
		int x = temp%10;
		temp = temp/10;
		a[ctr] = x;
		ctr --;
	}
	cout<<max<<endl;
	ld = 0;
	for(i=0;i<max;i++)
	{
		for(j=ld;j<digits;j++)
			 {
			 	if(a[j]>0)
			 		{cout<<1;a[j]--;}
			 	else
			 		cout<<0;
			 }
		cout<<" ";
		if(a[ld]==0)
		   {
		   	for(j=ld;j<digits;j++)
		   	{
		   		if(a[j]>0)
		   		{
		   			ld = j;
		   			break;
		   		}
		   	}
		   }	 
	}

	return 0;
}