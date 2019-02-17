#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
	  string s1;
	  cin>>s1;
	  int n = s1.length();
	  int i,j;
	  vector<string> a;
	  a.resize(n);
	  a[0] = s1;
	  for(i=1;i<n;i++)
	  {
	  	a[i] = s1;
	  	a[i][0] = a[i-1][n-1];
	  	for(j=1;j<n;j++)
	  		 a[i][j] = a[i-1][j-1];
	  }
	  int ans = 1;
	  for(i=1;i<n;i++)
	  {
	  	bool check = true;
	  	for(j=i-1;j>=0;j--)
	  	{
	  		if(a[i] == a[j])
	  		{
	  			check = false;
	  			break;
	  		}
	  	}
	  	if(check)
	  		ans++;
	  }
	  cout<<ans<<endl;
}