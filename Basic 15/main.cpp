#include <iostream>
#include<fstream>
using namespace std;

int am[11][11],n,vis[11], dist[11], par[11],nr,track[11];
ifstream f("Input.txt");

void input()
{f>>n;
int x,y,weight;
while(f>>x>>y)
    {f>>weight;
     am[x][y]=weight;
    }
}

void dijkstra(int start)
{int i,min,ok,j,k=start;

for (i=1;i<=n;i++)
    dist[i]=32000;

par[k]=0;
vis[k]=1;
ok = 1;

for(i=1;i<=n;i++)
    if(am[k][i])
        {dist[i]=am[k][i];
         par[i]=k;
        }
while (ok)
    {min=32000;
     for(i=1;i<=n;i++)
        if (dist[i]<min&&vis[i]==0)
            {min = dist[i];
             k=i;
            }
     vis[k]=1;
     for(i=1;i<=n;i++)
        if (vis[i]==0&&am[k][i])
            {if(dist[i]>(dist[k]+am[k][i]))
                {dist[i]=dist[k]+am[k][i];
                 par[i]=k;
                }
            }
        else ok=0;
    }
for(i=1;i<=n;i++)
    if(i!=start)
        if(dist[i]!=32000)
            {cout<<endl<<"Shortest path from node "<<start<<" to node "<<i<<": ";
             nr=1;
             j=i;
             track[nr]=j;
                while(par[j]!=0)
                    {j=par[j];
                     nr++;
                     track[nr]=j;
                    }
             for(j=nr;j>=1;j--)
                cout<<" "<<track[j];
             cout<<"    Distance: "<<dist[i];
            }
        else
            cout<<endl<<"No path between nodes "<<start<<" and "<<i;
}

int main()
{int start;
input();

cout<<"Input start node: ";
cin>>start;

dijkstra(start);

return 0;
}
