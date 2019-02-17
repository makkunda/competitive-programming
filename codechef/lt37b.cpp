#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int ans=0;
        int n,m,i,j;
        cin>>n>>m;
        char a[10][10];
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            cin>>a[i][j];
        }
        for(i=0;i<m;i++)
        {
            int ct = 0;
            for(j=0;j<n;j++)
            {
                if(a[i][j]=='1')
                ct++;
            }
            ans = ans + (ct*(ct-1)/2);
        }
        cout<<ans<<endl;   
    }
    return 0;
}
