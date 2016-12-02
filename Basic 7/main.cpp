/* PSEUDOCODE

PRIME(n,d)
    if n=d
        return 1
    else
        if n MOD d =0
            return 0
        else
            return PRIME(n,d+1)

*/

#include <iostream>
using namespace std;

int prime(int n,int d)
{if(d==n)
    return 1;
else
    if(n%d==0)
        return 0;
    else
        return prime(n,d+1);
}

int main()
{int n,d;
cout<<"Input number: ";
cin>>n;
d=2;
if(prime(n,d)==0)
    cout<<endl<<n<<" is not prime.";
else
    cout<<endl<<n<<" is prime.";
    return 0;
}
