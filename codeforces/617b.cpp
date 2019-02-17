#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n;
	int i,x;
	vector<int> pos;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>x;
		if(x==1)
			pos.push_back(i);
	}
	int z = pos.size();
	long long int ans = 1;
	if(z==0)
		ans = 0;
	for(i=1;i<z;i++)
		ans = ans*(pos[i]-pos[i-1]);
	cout<<ans<<endl;
}