/*   PSEUDOCODE

matrix am[11][11]

ADD-NODE(am,n)
    for i->1 TO n
        a[i][n]=0
        a[n][i]=0

ADD-EDGE(am,x,y)
    am[x][y]->1
    am[y][x]->1
*/

#include <iostream>
using namespace std;

void add_node(int am[11][11],int n)
{int i;

for(i=1;i<=n;i++)
    {am[i][n]=0;
     am[n][i]=0;
    }
}

void add_edge(int am[11][11],int x, int y)
{
am[x][y]=1;
am[y][x]=1;
}
int main()
{int am[11][11],n,i,j,e,x,y,opt=1;
cout<<"Number of nodes: ";
cin>>n;
for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
        am[i][j]=0;
cout<<endl<<"Number of edges: ";
cin>>e;
for(i=1;i<=e;i++)
    {cout<<endl<<"Edge between ";
     cin>>x;
     cout<<x<<" and ";
     cin>>y;
     cout<<y;
     add_edge(am,x,y);
    }

while(opt)
{cout<<endl<<"If you want to add a new node, press 1"<<endl<<"If you want to add a new edge, press 2"<<endl<<"If you don't want to make changes, press 0";
cout<<endl<<"Option: ";
cin>>opt;
if(opt==1)
    {n++;
     add_node(am,n);
     cout<<endl<<"Node "<<n<<" added.";
    }
if(opt==2)
    {cout<<endl<<"Edge between ";
     cin>>x;
     cout<<x<<" and ";
     cin>>y;
     cout<<y;
     add_edge(am,x,y);
     cout<<endl<<"Edge ("<<x<<","<<y<<") added.";
    }
}
return 0;
}
