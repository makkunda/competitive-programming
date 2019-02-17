#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

 int main()
 {
    long long int t;
    cin>>t;
    while(t--)
    {
    	bool ans[100000];
        bool visit[100000];
    	long long int n,i,x,temp,y,prev;
    	long long int a[100000];
    	cin>>n;
    	vector<long long int>adj;
    	adj.resize(n);
    	for(i=0;i<n;i++)
    		 {
    		 	cin>>x;
    		 	adj[i]=((i+x+1)%n + n)%n;
    		 	a[i]=-1;
    		 	ans[i]=false;
                visit[i]=false;
    		 }
 
        for(i=0;i<n;i++)
        {
        	if(!visit[i])
        	{

        		temp = adj[i];
                prev=i;
        		while(visit[temp])
        		{
        		    a[temp]=prev;
                    prev=temp;
                    visit[temp]=true;
        		    temp=adj[temp];
        		}
        		if(visit[i])
        		{
        			temp =adj[i];
        			ans[i]=true;
        			while(temp!=i)
        			{
        				ans[temp]=true;
                        temp = adj[temp];
        				ans[temp]=true;
                      //  visit[temp]=true;
        			}
        		}
                else
                {
                    long long int cur = temp;
                    long long int temp1 = adj[i];
                    visit[i]=true;
                    while(temp1!=cur)
                    {
                     //   visit[temp1]=true;
                        temp1=adj[temp1];
                    }
                    ans[cur]=true;
                //    visit[cur]=true;
                    temp1=adj[temp1];
                    while(temp1!=cur)
                    {
                        ans[temp1]=true;
                     //   visit[temp1]=true;
                        temp1=adj[temp1];
                    }
                }

        		temp = adj[i];
                a[i]=-1;
        		while(a[temp]!=-1)
        		{
        		    a[temp]=-1;
                  visit[temp]=true;
        		    temp=adj[temp];
        		}
        	}
        }
        long long int ct = 0;
        for(i=0;i<n;i++)
        {
        	if(ans[i])
        		ct++;
        }
        cout<<ct<<endl;

    }
 	return 0;
 }