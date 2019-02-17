/*
ID: makkund2
PROG: crypt1
LANG: C++                  
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>

using namespace std;
bool isp(int* a,int b,int n)
  {
  	for(int i=0;i<n;i++)
  	{
  		if(a[i]==b)
  			return true;
  	}
  	return false;
  }
int main() {
    ofstream fout ("crypt1.out");
    ifstream fin ("crypt1.in");
    int arr[9];
    int n,i,j,k,l,m;
    int a,b,c,d,e;
    int num1,pp1,pp2,sum;
    fin>>n;
    for(i=0;i<n;i++)
    {
    	fin>>arr[i];
    }
    long int count = 0;
    for(i=0;i<n;i++)
    {
    	for(j=0;j<n;j++)
    	{
    		for(k=0;k<n;k++)
    		{
    			for(l=0;l<n;l++)
    			{
    				for(m=0;m<n;m++)
    				{
    					a = arr[i];b=arr[j];c=arr[k];d=arr[l];e=arr[m];
    					bool check = true;
    					num1 = 100*a + 10*b + c;
    					pp1 = e*num1;
    					pp2 = d*num1;
    					sum = pp1 + 10*pp2;
    					if(pp1>=1000 || pp1<=100 || pp2>=1000 || pp2<=100 || sum>=10000 || sum<=1000)
    						  check = false;
    					else
    					  {
    					  	int tdig;
    					  	while(pp1!=0)
    					  	{
    					  		tdig = pp1%10;
    					  		if(!isp(arr,tdig,n))
    					  			  check = false;
    					  		pp1 = pp1/10;	
    					  	}
    					  	while(pp2!=0)
    					  	{
    					  		tdig = pp2%10;
    					  		if(!isp(arr,tdig,n))
    					  			  check = false;
    					  		pp2 = pp2/10;	
    					  	}
    					  	while(sum!=0)
    					  	{
    					  		tdig = sum%10;
    					  		if(!isp(arr,tdig,n))
    					  			  check = false;
    					  		sum = sum/10;	
    					  	}
    					  }	
    					if(check)
    					   count++;  
    				}
    			}
    		}
    	}
    }
    fout<<count<<"\n";
    return 0;
}