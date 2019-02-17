#include <iostream>

using namespace std;
int ab(int x)
{
    if(x>0)
        return x;
    return -1*x;
}
int main()
{
    // cout<<"IN"<<endl;
    int x,y,z,t1,t2,t3;
    cin>>x;
    cin>>y;
    cin>>z;
    cin>>t1;
    cin>>t2;
    cin>>t3;
    
    int t_e = 0;
    int t_s = 0;

    t_s = ab(x-y)*t1;
    t_e = 3*t3 + t2*(ab(z-x) + ab(y-x)); 

    if(t_e<=t_s)
        cout<<"YES";
    else
        cout<<"NO";

    return 0;
}