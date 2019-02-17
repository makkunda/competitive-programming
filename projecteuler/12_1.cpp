#include <iostream>
#include <vector>
#define MAX 10000000
using namespace std;
int main()
{
	vector<long int> prime;
	vector<bool> a(10001,true);
	long int i;
	for(i=2;i<100;i++)
		 {
		 	if(a[i])
		 	{
		 		//prime.push_back(i);
		 		for(long int j = i*i;j<10000;j=j+i)
		 		{
		 			a[j]=false;
		 		}
		 	}
		 }
	for(i=2;i<10000;i++)
	  {
	  	if(a[i])
	  		prime.push_back(i);
	  }	
	int sz = prime.size();  
	for(i=7;i<=MAX;i++)
    {
    	long long int mult = 1;
    	vector<int> pcount;
    	pcount.resize(sz);
    	long int temp,temp1 ;
    	if(i%2)
    		{
    			temp = i;
    			temp1 = (i+1)/2;
    		}
    	else
    	   {
    	   	temp = i/2;
    	   	temp1 = (i+1)/2;
    	   }	
    	for(int j = 0;j<sz && prime[j]<temp;j++)
    	{
    		while((temp%prime[j]) == 0)
    		{
    			pcount[j]++;
    			temp = temp /  prime[j];
    		}
    	}
    	for(int j = 0;j<sz && prime[j]<temp1;j++)
    	{
    		while((temp1%prime[j]) == 0)
    		{
    			pcount[j]++;
    			temp1 = temp1 /  prime[j];
    		}
    	}
    	for(int j=0;j<sz;j++)
    		mult = mult*(pcount[j]+1);
    	if(temp>1)
    		mult = mult*2;
    	if(temp1>1)
    		mult = mult*2;
    	if(mult>500)
    	{
    		cout<<i<<endl;
    		break;
    	}
    }	  
	return 0;
}