#include <iostream>
#include <vector>
#include <algorithm>
#define lli long long int
using namespace std;
vector<lli> a;
lli first(lli beg,lli end,lli x)
 {
 	if(end>=beg)
 	{
 		lli mid = beg + (end-beg)/2;
 		if((mid==0 || (x>a[mid-1]))&&(a[mid]==x))
 			return mid;
 		else if(x>a[mid])
 			return first(mid+1,end,x);
 		else
 			return first(beg,mid-1,x);

 	}
 	return -1;
 }
lli last(lli beg,lli end,lli x)
 {
 	if(end>=beg)
 	{
 		lli mid = beg + (end-beg)/2;
 		if((mid==(a.size()-1) || (x<a[mid+1]))&&(a[mid]==x))
 			return mid;
 		else if(x<a[mid])
 			return last(beg,mid-1,x);
 		else
 			return last(mid+1,end,x);

 	}
 	return -1;
 }
lli no_of_ocur(lli beg,lli end,lli x)
 {
 	lli ans = 0;
 	if(binary_search(a.begin()+beg,a.end(),x))
 	{
 		lli fs,lst;
 		fs  = first(beg,end,x);
 		lst = last(beg,end,x);
 		ans = lst - fs + 1;
 	}
 	return ans;
 }
int main()
{
	lli n;
	lli x;
	cin>>n>>x;
	a.resize(n);
	lli i,j;
	for(i=0;i<n;i++)
		cin>>a[i];
	sort(a.begin(),a.end());
	lli ans = 0;
	if(x>0){
	for(i=0;i<(n-1);i++)
	{
		lli tofind = x^a[i];
		lli cur = no_of_ocur(i+1,n-1,tofind);
		ans = ans + cur;
	}}
	else
	{
		lli cur=a[0];
		lli count = 1;
		for(i=1;i<n;i++)
		{
			if(a[i]==cur)
				count++;
			else
			{
				cur = a[i];
				ans = ans + count*(count-1)/2;
				count = 1;
			}
		}
		ans = ans + count*(count-1)/2;
	}
	cout<<ans<<"\n";
	return 0;
}