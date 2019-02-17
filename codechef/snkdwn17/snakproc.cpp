#include <iostream>
#include <string>

using namespace std;

int main() {
    int r;
    cin>>r;
    while(r--)
    {
        int l;
        string s;
        cin>>l>>s;
        int state = 2;
        int i;
        for(i=0;i<l;i++)
        {
            if(state==1 && s[i]=='H')
            {
                state = 3;
                break;
            }
            else if(state == 1 && s[i]=='T')
                state = 2;
            else if(state == 2 && s[i]=='T')
                {
                    state = 3;
                    break;
                }
            else if(state == 2 && s[i] == 'H')
                {
                    state = 1;
                }
        }
        if(state == 2)
           cout<<"Valid\n";
        else
           cout<<"Invalid\n";
    }
    return 0;
}