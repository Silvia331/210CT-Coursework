#include <iostream>
using namespace std;

struct double_list
{int value;
double_list *prev,*next;
};

double_list *head;

void add_end(double_list *&head,int value)
{double_list *elem=new double_list;
 elem->value=value;
 elem->next=0;
 elem->prev=0;

if(head==0)
    head=elem;
else
    {double_list *node=head;
     while(node->next)
        node=node->next;
     node->next=elem;
     elem->prev=node;
    }
}

void delete_head(double_list *&head)
{double_list *d=head->next;
head=d;
head->prev=0;
}

void delete_value(double_list *head, int value)
{while(head->value!=value)
    head=head->next;
if(head->next)
    {head->prev->next=head->next;
     head->next->prev=head->prev;
    }
else
    head->prev->next=0;
}

void print(double_list *head)
{while(head)
    {cout<<head->value<<" ";
     head=head->next;
    }
}

int main()
{int i,n,value;
cout<<"Input number of elements in list: ";
cin>>n;
cout<<"Input values of elements in the list: ";
for(i=1;i<=n;i++)
    {cin>>value;
     add_end(head,value);
    }
print(head);
cout<<endl<<"Input value to delete: ";
cin>>value;
if(head->value==value)
    delete_head(head);
else
    delete_value(head,value);
cout<<endl<<"List after deleting value "<<value<<": ";
print(head);
return 0;
}
