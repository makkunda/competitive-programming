#include <bits/stdc++.h>
using namespace std;

int findans(long long int k,int mx)
  {
  	long long int x = (long long int)pow(2,mx-1);
  	if(mx==1)
  		 return 1;	
  	else
  	 {
  	 	if(k==x)
  	 		 return mx;
  	 	else if(k<x)	
  	 		  return findans(k,mx-1);
  	 	else
  	 	      return findans(k-x,mx-1);	
  	 }	
  } 
int main()
{
	 ios::sync_with_stdio(false);cin.tie(0);
	 int n;
	 long long int k;
	 cin>>n>>k;
	 cout<<findans(k,n)<<endl;
	return 0;
}