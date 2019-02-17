#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
using namespace std;
int ab(int a)
   {
   	if(a>0)
   		return a;
   	return -1*a;
   }
int main()
{
	int t1=0,n=0,t2=0,q=0,i;
	string s1,s2;
	long long int fact[11],pow2[11];
	fact[0]=1;pow2[0]=1;
	for(i=1;i<=10;i++)
	{
		fact[i]=fact[i-1]*i;
		pow2[i] = pow2[i-1]*2;
	}
	cin>>s1>>s2;
	n = s1.size();
	for(i=0;i<n;i++)
	{
		if(s1[i]=='+')
			 t1++;
		else
		     t1--;	
	}
	for(i=0;i<n;i++)
	{
		if(s2[i]=='+')
			 t2++;
		else if(s2[i]=='-')
		     t2--;	
		else
		      q++; 
	}
	if(ab(t1-t2)>q)
		 cout<<0<<endl;
	else
	    {
	    	int y = ab(t1-t2);
	    	if((q+y)%2==1)
	    		cout<<0<<endl;
	    	else{
	    	y = (q +y)/2;	
	    	long long int num = fact[q]/fact[y];
	    	num = num / fact[q-y];
	    	double ans = (double)num/(double)pow2[q];
	    	cout<<setprecision(12)<<ans<<endl;}
	    }	
	return 0;
}