#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	bool done = true;
	while(done)
	 {
	 int c,r,i,j;
	 cin>>c;
	 if(c==0)
	    done = false;
	 else
	  {
	  	string s;
	  	cin>>s;
	  	int n = s.length();
	  	r = n/c;
	  	vector<vector<char> > a(r);
	  	for(i=0;i<r;i++)
	  	    a[i].resize(c);
	  	int nn = 0;
	  	for(i=0;i<r;i++)
	  	  {
	  	  	if(i%2==0)
	  	  	 {
	  	  	 	for(j=0;j<c;j++)
	  	  	 	   a[i][j]=s[nn++];
	  	  	 }
	  	  	else
	  	  	 {
	  	  	 	for(j=0;j<c;j++)
	  	  	 	   a[i][c-j-1]=s[nn++];
	  	  	 } 
	  	  } 
	  	for(i=0;i<c;i++)
	  	 {
	  	 	for(j=0;j<r;j++)
	  	 	   cout<<a[j][i];
	  	 }
	  	cout<<"\n";      
	  }   
	 }
	return 0;
}