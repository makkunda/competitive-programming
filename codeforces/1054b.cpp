#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<long long int> a;
    a.resize(n);
    int i;
    for(i=0;i<n;i++)
        cin>>a[i];
    long long min = 0;
    int ans = -1;
    for(i=0;i<n;i++)
    {
        if(a[i]>min)
        {
            ans = i+1;
            break;
        }
        if(a[i]==min)
            min = min + 1;
    }
    cout<<ans;
    return 0;
}