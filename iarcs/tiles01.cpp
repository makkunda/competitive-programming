#include <iostream>
using namespace std;
int main()
{
	long int n;
	cin>>n;
	long long int a_1 = 1,a_2 = 2;
	if(n==1)
		cout<<1;
	else if(n==2)
		 cout<<2;
	else
	 {
	 	for(int i=3;i<=n;i++)
             {
             	long long int temp = a_2;
             	a_2 = (a_2 + a_1)%15746;
             	a_1 = temp;
             }
             cout<<a_2;
	 }	
	return 0;
}