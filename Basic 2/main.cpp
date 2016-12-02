#include <iostream>
using namespace std;
int main()
{int n,i,num=0;

cout<<"Input number: ";
cin>>n;

for(i=1;i<=n;i++)//Counts the number of elements in the factorial that are divisible by 5
    if(i%5==0)
        num++;

cout<<endl<<"Number of trailing 0s in "<<n<<"! is "<<num;
return 0;
}
