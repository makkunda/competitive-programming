#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;
long int mx(long int a,long int b)
 {
 	if(a>b)
 		return a;
 	return b;
 }
 long int mn(long int a,long int b)
 {
 	if(a<b)
 		return a;
 	return b;
 }
int main()
{
	long int n,k,i;
	long int fst = -1,tmp;
	int t[200001];
	long int count = 0;
	cin>>n>>k;
	for(i=0;i<n;i++)
	{
		cin>>t[i];
		if(t[i]<0)
	    {
	    	if(count==0)
	    		fst = i;
			count++;
	    }		  
	}
	if(count>k)
		  cout<<-1<<endl;
	else
	  {
	  	if(count==0)
	  		  cout<<0<<endl;
	  	else
	  	  {
	  	  	vector<long int> dur;
	  	  	t[n] = -1;
	  	  	long int prev = fst;
	  	  	for(i=fst+1;i<=n;i++)
	  	  		 {
	  	  		 	if(t[i]<0)
	  	  		 	{
	  	  		 		tmp = i - prev-1;
	  	  		 		prev = i;
	  	  		 		dur.push_back(tmp);
	  	  		 	}
	  	  		 }
	  	  	long int ctr = k - count;
	  	  	long int strch = count;
	  	  	long int l = dur.size();
	  	  	long int d1 = dur[l-1];
	  	  	sort(dur.begin(),dur.end()-1);
	  	  	long int done;
	  	  	for(i=0;i<(dur.size()-1);i++)
	  	  	  {
	  	  	  	if(dur[i]<=ctr)
	  	  	  		  {
	  	  	  		  	ctr = ctr - dur[i];
	  	  	  		  	strch -- ;
	  	  	  		  	done = i;
	  	  	  		  }
	  	  	  }	
	  	  	ans = 2*strch;
	  	  	if(ctr>=dur[l-1])
	  	  			ans = ans - 1;
	  	  	cout<<ans<<endl;	
	  	  }	
	  }	
	return 0;
}