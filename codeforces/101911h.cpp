#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define pb push_back
#define mp make_pair
using namespace std;
pair<int,int> count_ans(int length,int height)
{
	// cout<<length<<" "<<height<<endl;
	int ans = 0;
	int odd = 0;
	if(length%2)
	{
		if(height%2==0)
			ans = ans + (height/2);
		else
		{
			ans = ans + (height/2); 
			odd = 1;
		}
	}
	return mp(ans,odd);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m,x1,y1,x2,y2;
	int i,j;
	cin>>n>>m;
	cin>>x1>>y1>>x2>>y2;
	int ans = 0;
	int odd = 0;
	int non_f = n - (x2-x1+1);
	int f = (x2-x1+1);
	pair<int,int> p1;
	pair<int,int> p2;
	pair<int,int> p3;

	int left = y1 - 1;
	int right = m - y2;

	p1 = count_ans(m,non_f);
	p2 = count_ans(left,f);
	p3 = count_ans(right,f);

	ans = p1.first + p2.first + p3.first;
	odd = p1.second + p2.second + p3.second;

	if(odd==1 || odd==2)
		ans = ans + 1;
	if(odd==3)
		ans = ans + 2;


	cout<<ans<<endl;
	
	return 0;
}