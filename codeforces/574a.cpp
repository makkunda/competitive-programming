#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n;
	vector<int> a;
	cin>>n;
	a.resize(n);
	int i,j;
	int maxv = 0;
	for(i=0;i<n;i++){
		cin>>a[i];
		maxv = max(maxv,a[i]);
	}
	int ans=0;
	for(j=a[0];j<=(maxv+1);j++)
	{
		int extra = 0;
		for(i=1;i<n;i++)
		{
			extra = extra + max(0,a[i]-j+1);
		}
		if(extra<=(j-a[0]))
		{
			ans = j;
			break;
		}
	}
	cout<<ans-a[0]<<endl;
	return 0;
}
