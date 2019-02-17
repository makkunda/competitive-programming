#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int p;
	cin>>p;
	int i,j;
	int count = 0;
	for(i=1;i<p;i++)
	{
		int temp = 1;
		bool done = true;
		for(j=1;j<=(p-2);j++)
		{
			temp = temp*i;
			temp = temp%p;
			temp = temp + p;
			temp = temp%p;
			if(temp==1)
				done = false;
		}
		if(done)
			count++;
	}
	cout<<count<<endl;
	return 0;
}