#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);
    long long int t;
    cin>>t;
    while(t--)
    {
        long long int n,i;
        cin>>n;
        long long int x,sum=0;
        for(i=0;i<n;i++)
        {
            cin>>x;
            sum = sum + x;
        }
        if(sum%n==0)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}