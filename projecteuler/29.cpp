//ans = 9183
/*
2 - 6
3 - 4
5 - 2
6 - 2
7 - 2
10 - 2

81 * 99 = 8019

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	vector<int> two,three,five;
	for(int i=2;i<=100;i++)
	{
		two.push_back(i);
		two.push_back(2*i);
		two.push_back(3*i);
		two.push_back(4*i);
		two.push_back(5*i);
		two.push_back(6*i);
		three.push_back(i);
		three.push_back(2*i);
		three.push_back(3*i);
		three.push_back(4*i);
		five.push_back(i);
		five.push_back(2*i);
	}
	sort(two.begin(),two.end());
	sort(three.begin(),three.end());
	sort(five.begin(),five.end());
	int prev = 0;
	int twocnt,threecnt,fivecnt;
	int i;
	for(i=0;i<two.size();i++)
	{
		if(two[i]!=prev)
			twocnt++;
		prev = two[i];
	}
	prev = 0;
	for(i=0;i<three.size();i++)
	{
		if(three[i]!=prev)
			threecnt++;
		prev = three[i];
	}
	prev = 0;
	for(i=0;i<five.size();i++)
	{
		if(five[i]!=prev)
			fivecnt++;
		prev = five[i];
	}
	cout<<99*81<<endl;
	cout<<twocnt<<endl;
	cout<<threecnt<<endl;
	cout<<fivecnt<<endl;
	int ans = 99*81 + twocnt + threecnt + 4*fivecnt ;
	cout<<ans<<endl;
}