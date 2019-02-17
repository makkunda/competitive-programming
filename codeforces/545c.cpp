#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;
#define inf 5e11 
int main()
{
   long int n,i;
   cin>>n;
   long long int x[100002],h[100002];
   x[0]=-1*inf;x[n+1] = inf;h[0]=h[n+1]=0;
   for(i=1;i<=n;i++)
   	 {
   	 	cin>>x[i]>>h[i];
   	 }
   vector<pair<long long int,long long int> > inter;
   for(i=1;i<=n;i++)
    {
    	if((x[i]-h[i])>x[i-1])
    	{
    		pair<long long int,long long int> ab(x[i],x[i]-h[i]);
    		inter.push_back(ab);
    	}
    	if((x[i]+h[i])<x[i+1])
    		{
    		pair<long long int,long long int> ab(x[i]+h[i],x[i]);
    		inter.push_back(ab);
    	    }
    }
   sort(inter.begin(),inter.end());
   long int ans = 1;
   long int ln = inter.size();
   long long int finish = inter[0].first;
   for(i=1;i<ln;i++)
     {
     	while(inter[i].second<=finish && i<ln)
     		   i++;
     	if(i<ln)
     	  {
     	  	ans++;
     	  	finish = inter[i].first;
     	  }	
     }
   cout<<ans<<"\n";    
   return 0;
}