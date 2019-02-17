#include <iostream>
using namespace std;
int main()
{
	int n,k;
	cin>>n>>k;
	int cnt,lst;
	cnt = n/k;
	lst = n%k;
	if(lst==0)
		lst = k;
	else
		cnt = cnt + 1;
	cout<<cnt<<" "<<lst;
	return 0;
}