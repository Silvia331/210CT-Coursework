/* PSEUDOCODE

ADD-MATRIX(n,B,C,M)
    for i<-1 TO n
        for j<-1 TO n
            M[i][j]<-B[i][j]+C[i][j]

SUBSTRACT-MATRIX(n,B,C,M)
    for i<-1 TO n
        for j<-1 TO n
            M[i][j]<-B[i][j]-C[i][j];

MULTIPLY-MATRIX(n,B,C,M)
    for i<-1 TO n
        for j<-1 TO n
            mul<-0
            for k<-1 TO n
                mul<-mul+B[i][k]*C[k][j]
            M[i][j]<-mul
*/

#include <iostream>
using namespace std;

void add_matrix(int n,int B[101][101], int C[101][101], int M[101][101])
{int i,j;
for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
        M[i][j]=B[i][j]+C[i][j];
}

void substract_matrix(int n,int B[101][101], int C[101][101], int M[101][101])
{int i,j;
for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
        M[i][j]=B[i][j]-C[i][j];
}

void multiply_matrix(int n,int B[101][101], int C[101][101], int M[101][101])
{int i,j,k,mul;
for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    {mul=0;
     for(k=1;k<=n;k++)
        mul=mul+B[i][k]*C[k][j];
     M[i][j]=mul;
    }
}

int main()
{int n,i,j,B[101][101],C[101][101],A[101][101],M1[101][101],M2[101][101];
cout<<"Input matrix size: ";
cin>>n;
cout<<endl<<"Elements of matrix B: ";
for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    cin>>B[i][j];
cout<<endl<<"Elements of matrix C: ";
for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    cin>>C[i][j];

multiply_matrix(n,B,C,M1);

add_matrix(n,B,C,M2);

for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    M2[i][j]=2*M2[i][j];

substract_matrix(n,M1,M2,A);

cout<<endl<<"Matrix A: ";
for(i=1;i<=n;i++)
  {cout<<endl;
    for(j=1;j<=n;j++)
        cout<<A[i][j]<<" ";
  }
    return 0;
}
