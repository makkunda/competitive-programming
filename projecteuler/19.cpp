// ans is 171

#include <iostream>
using namespace std;
int main()
{
	int day = 2;
	int date = 1;
	int month = 1;
	int year = 1901;
	int ans = 0;
	while (year<2001)
	{
        if(date==1 && day==7)
        	 ans++;	
        if(date==28 && month==2 && (year%4))
        {
        	date = 1;
        	month = 3;
        }
        else if(date==29 && month==2)
        {
        	date = 1;
        	month = 3;
        }
        else if (date==30 && ((month==4)||(month==6)||(month==9)||(month==11)))
        {
        	date = 1;
        	month = month + 1;
        }
        else if (date==31 && ((month==1)||(month==3)||(month==5)||(month==7)||(month==8)||(month==10)))
        {
        	date = 1;
        	month = month + 1;
        }  
        else if (date==31 && month==12)
        {
        	date = 1;
        	month = 1;
        	year = year+1;
        }
        else
        {
        	date = date + 1;
        }
		day = day%7 + 1;
	}
	cout<<ans<<endl;
	return 0;
}
