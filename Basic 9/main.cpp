/*  PSEUDOCODE

FOUND(v,n,low,high)
    left<-1
    right<-n
    while left<=right
        mid<-(left+right) DIV 2
        if v[mid]>=low AND v[mid]<=high
            return 1
        else
            if v[mid]<low
                left<-mid+1
            else
                right<-mid-1
    return 0
*/


#include<iostream>
using namespace std;

int found(int v[101],int n,int low, int high)
{int left=1,right=n,mid;

while(left<=right)
    {mid=(left+right)/2;
     if(v[mid]>=low && v[mid]<=high)
         return 1;
     else
        if(v[mid]<low)
            left=mid+1;
         else
            right=mid-1;
    }
return 0;
}

int main()
{int n,v[101],i,low,high;

cout<<"Number of elements in array : ";
cin>>n;
cout<<endl<<"Elements of the array(in ascending order): ";

for(i=1;i<=n;i++)
    cin>>v[i];

cout<<endl<<"Low: ";
cin>>low;
cout<<endl<<"High: ";
cin>>high;

if(found(v,n,low,high)==1)
    cout<<endl<<"True";
else
    cout<<endl<<"False";
   return 0;
}
