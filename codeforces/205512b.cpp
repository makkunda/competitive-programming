#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n,k;
	cin>>n>>k;
	int cnt,lst;
	cnt = n/k;
	lst = n%k;
	if(lst==0)
		lst = k;
	else
		cnt = cnt + 1;
	vector<int> mn;
	mn.resize(cnt);
	vector<int> data;
	data.resize(n);
	int i;
	for(i=0;i<n;i++)
		cin>>data[i];
	bool new_buck = true;
	int cur_cnt = 0;
	int b_count = -1;
	int cur_min = 0;
	for(i=0;i<n;i++)
	{
		if(new_buck==true)
		{
			if(b_count>=0)
			{
				mn[b_count] = cur_min;
			}
			b_count++;
			new_buck = false;
			cur_min = data[i];
		}
		cur_min = min(cur_min,data[i]);
		cur_cnt++;
		if(cur_cnt==k)
		{
			cur_cnt = 0;
			new_buck = true;
		}
	}
	mn[b_count] = cur_min;
	for(i=0;i<cnt;i++)
		cout<<mn[i]<<" ";
	return 0;
}