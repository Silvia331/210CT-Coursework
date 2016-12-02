#include <iostream>
#include <fstream>
using namespace std;

int am[11][11],q[21],seen[11],n,first, last, peak,vis[101],p;

ofstream f("Output.txt");

void BFS(int q[21])
{int i;
 while(first<=last)
    {peak=q[first];
     for(i=1;i<=n;i++)
        if(am[peak][i]==1&&seen[i]==0)
            {last++;
             q[last]=i;
             seen[i]=1;
            }
     first++;
    }

}

void DFS(int p)
{f<<p<<" ";
 vis[p]=1;
 for(int i=1;i<=n;i++)
    if(am[p][i]==1&&vis[i]==0)
        DFS(i);
}

int main()
{int start,i,j;
cout<<"Number of nodes: ";
cin>>n;
cout<<endl<<"Input adjacency matrix: "<<endl;
for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    cin>>am[i][j];
cout<<endl<<"Input start node for BFS: ";
cin>>start;
q[first]=start;
BFS(q);
f<<"Breadth First Search: ";
for(i=1;i<=last;i++)
    f<<q[i]<<" ";
cout<<"Input start node for DFS: ";
cin>>p;
f<<endl<<"Depth First Search: ";
DFS(p);
f.close();
    return 0;
}
