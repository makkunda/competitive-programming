#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	vector<int> ans;
	int m,i;
	cin>>m;
	for(i=5;i<=10*m;i++)
	{
		int count = 0;
		int temp = 5;
		int temp1;
		while(temp<=i)
		{
			temp1 = i/temp;
			count = count + temp1;
			temp = temp*5;
		}
		if(count==m)
			ans.push_back(i);
		if(count>m)
			break;
	}
	sort(ans.begin(),ans.end());
	cout<<ans.size()<<endl;
	for(i=0;i<ans.size();i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}
