#include <algorithm>
#include <iostream>
#include <vector>
#include <utility>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		long int n ,k ,i;
		long long int x;
		cin>>n>>k;
		long int count = n/k;
		long int a[100001];
		for(i = 0;i<=100000;i++)
			   a[i] = 0;
		for(i=0;i<n;i++)
		 {
		 	cin>>x;
		 	a[x%100001]++;
		 }	
		vector<pair<long int,long int>> box;
		for(i=1;i<=100000;i++)
		 {
		 	if(a[i]>0)
		 		{
		 			pair <long int,long int> ab(a[i],i);
		 			box.push_back(ab);
		 		}
		 } 
		long int size = box.size();
		sort(box.begin(),box.end());
		long int ans = 0;
		while(count>0)
		 {
		 	if(box[size-1].first>=k)
		 		 {
		 		 	count = count - 1;
		 		 	box[size-1].first = box[size-1].first - k;
		 		 	pair<long int,long int>  temp = box[size-1];
		 		 	long int i = size - 2;
		 		 	while(box[i].first>temp.size && i>=0)
		 		 	{
		 		 		box[i+1]=box[i];
		 		 		i--;
		 		 	}
		 		 	box[i+1] = temp;
		 		 }
		 	else
		 	  {
		 	  	count = count - 1;
		 	  	
		 	  }	 
		 } 
	}
	return 0;
}