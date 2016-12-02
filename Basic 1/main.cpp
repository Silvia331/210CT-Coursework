#include <iostream>
#include<cstdlib>
using namespace std;
void shuffle(int n,int a[101]) //Function that randomly choses positions in the array to display and so shuffling the array
{ int r,i;
cout<<endl<<"Random shuffled array: ";
    while (n!=0)
    {r=rand()%n+1;
    cout<<a[r]<<" ";
    for(i=r+1;i<=n;i++)
        a[i-1]=a[i];
    n--;}
}
int main()
{int n,a[101],i;
cout<<"Number of elements in the array: ";
cin>>n;
cout<<endl<<"Elements of the array: ";
for(i=1;i<=n;i++)
    cin>>a[i];
shuffle(n,a);
    return 0;
}
