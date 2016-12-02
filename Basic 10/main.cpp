#include <iostream>
using namespace std;

struct node
{ int info;
  node* next;
};

void add_end(node* &first, node* &last, int inf)
{if(first==0)
    {
        first=last=new node;
        first->info=inf;
        first->next=0;
    }
    else
    {
        node *new_node=new node;
        new_node->info=inf;
        new_node->next=0;
        last->next=new_node;
        last=new_node;
    }
}

int main()
{int n,i,inf,max=0,max_aux,ok=0;
node *first, *last, *start, *stop, *start_aux, *stop_aux, *p;
first=last=0;

cout<<"Input number of elements in the array: ";
cin>>n;
cout<<endl<<"Elements of the array: ";

for(i=1;i<=n;i++)
    {cin>>inf;
     add_end(first, last, inf);
    }

for(p=first;p->next;p=p->next)
    {if((p->info)<(p->next->info))
        {if(ok==0)
            {start_aux=p;
             ok=1;
             max_aux=1;}
         stop_aux=p->next;
         max_aux++;
        }
    else
       {ok=0;
        if(max_aux>max)
            {start=start_aux;
             stop=stop_aux;
             max=max_aux;
            }
       }
}

cout<<endl<<"Length: "<<max;

cout<<endl<<endl<<"Sub-sequence of maximum length in ascending order: ";

p=start;
while(max)
    {cout<<p->info<<" ";
     max--;
     p=p->next;
    }
    return 0;
}
