#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
	int n;
	string x[1000];
	vector<int> cnt;
	cnt.resize(7);
	int i,j;
	cin>>n;
	for(i=0;i<n;i++)
		cin>>x[i];
	for(i=0;i<n;i++)
	{
		for(j=0;j<7;j++)
		{
			if(x[i][j]=='1')
				cnt[j]++;
		}
	}
	int mx = 0;
	for(i=0;i<7;i++)
		mx = max(mx,cnt[i]);
	cout<<mx<<endl;
	return 0;
}