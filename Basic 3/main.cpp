/*  PSEUDOCODE

HIGHEST-SQUARE(n)
    if n=0
        return 0
    else
        if n=1
            return 1
        else
            int i
            for i<-1 TO n DIV 2
                if i*i<=n AND (i+1)*(i+1)>n
                    return i
*/
#include <iostream>
using namespace std;
int highest_square(int n)
{if(n==0)
    return 0;
else
    if(n==1)
    return 1;
else
{int i;
for(i=1;i<=n/2;i++)
    if((i*i)<=n &&(i+1)*(i+1)>n)
        return i;
}
}

int main()
{int n;
cout<<"Input number: ";
cin>>n;
cout<<endl<<"The highest perfect square which is less or equal to "<<n<<" is "<<highest_square(n);
    return 0;
}
