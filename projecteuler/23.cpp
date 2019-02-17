// ans is 4179871

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	long int dsum[28124];
	int i,j;
	vector<int> abundant;
	for(i=0;i<28124;i++)
		dsum[i] = 0;
	for(i=1;i<28124;i++)
	{
		for(j=1;j<i;j++)
		{
			if(i%j==0)
				dsum[i] = dsum[i] + j;
		}
	}
	for(i=1;i<28124;i++)
		{
			if(dsum[i]>i)
			{
				abundant.push_back(i);
			}
		}
	long long int ans = 0;
	int n = abundant.size();
	for(i=1;i<28124;i++)
	{
		bool issum = false;
		for(j=0;j<n;j++)
		{
			if(abundant[j]>i)
				break;
			if(binary_search(abundant.begin(),abundant.end(),i-abundant[j]))
				 {
				 	issum = true;
				 	break;
				 }
		}
		if(!issum)
		{
			ans = ans + i;
			//cout<<i<<endl;
		}
	}
	cout<<ans<<endl;
	//for(i=0;i<n;i++)
	//	cout<<abundant[i]<<endl;
	return 0;
}