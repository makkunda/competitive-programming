#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int m,s;
	cin>>m>>s;
	int max = m*9;
	if(s==0&&m==1)
		cout<<"0 0\n";
	else if(s==0||(s>max))
		cout<<"-1 -1\n";
	else
	{
		vector<int> mx;
		mx.resize(m+1);
		vector<int> mn;
		mn.resize(m+1);
		int l = s/9;
		int i ;
		for(i=0;i<l;i++)
			mx[i]=9;
		int tmp = s - l*9;
		mx[l]=tmp;
		for(i=0;i<=m;i++)
			mn[i]=mx[i];
		if(mx[m-1]==0)
		{
			if(mx[l]>0)
			{
				mx[l]=mx[l]-1;
				mx[m-1]=1;
			}
			else
			{
				mx[l-1]=mx[l-1]-1;
				mx[m-1]=1;
			}
		}

		for(i=m-1;i>=0;i--)
			cout<<mx[i];
		cout<<" ";
		for(i=0;i<m;i++)
			cout<<mn[i];
		cout<<endl;
	}
	return 0;
}