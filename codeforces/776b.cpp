#include <iostream>
#include <vector>
#define lli long long int
using namespace std;
int main()
{
	lli n;
	cin>>n;
	if(n==1)
		cout<<1<<endl<<1<<endl;
	else if(n==2)
		cout<<1<<endl<<"1 1\n";
	else
	{
		vector<lli> ls;
		ls.resize(n+2);
		ls[0]=ls[1]=1;
		lli i;
		for(i=3;i<=(n+1);i++)
			ls[i]=2;
		vector<bool> isp;
		isp.resize(n+2);
		for(i=0;i<=(n+1);i++)
			isp[i]=true;
		for(i=2;i<=(n+1);i++)
		{
			if(isp[i])
			{
				lli j;
				for(j=i*i;j<=(n+1);j=j+i)
					isp[j]=false;
			}
		}
		for(i=2;i<=(n+1);i++)
		{
			if(isp[i])
				ls[i]=1;
		}
		cout<<2<<"\n";
		for(i=2;i<=(n+1);i++)
			cout<<ls[i]<<" ";
	}
	return 0;
}