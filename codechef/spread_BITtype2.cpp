#include <iostream>
#include <vector>
using namespace std;
vector<long long int>a;
long long int n;
void update1(long long int loc,long long int val)
 {
 	while(loc<=(n+1))
 	{
 		a[loc]=a[loc]+val;
 		loc = loc + (loc&(-loc));
 	}
 }
void update(long long int start,long long int end,long long int val)
 {
 	update1(start,val);
 	update1(end+1,-1*val);
 }
long long int val(long long int loc)
{
	long long int ans = 0;
	while(loc>=1)
	{
		ans = ans + a[loc];
		loc = loc - (loc&(-loc));
	}
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	long long int m,c,i;
	long long int u,v,k,p;
	char y;
	cin>>n>>m>>c;
	a.resize(n+2);
	for(i=0;i<=(n+1);i++)
		a[i]=0;
	while(m--)
	{
		cin>>y;
		if(y=='S')
		{
			cin>>u>>v>>k;
			update(u,v,k);
		}
		else
		{
			cin>>p;
			cout<<(val(p)+c)<<"\n";
		}
	}
	return 0;
}