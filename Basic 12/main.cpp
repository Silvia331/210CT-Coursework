#include <iostream>

using namespace std;

class node
{public:
 int value;
 node *left;
 node *right;
};

node *root;

struct stack
{node *point;
 stack *back;
};

stack *top;

void push(stack* &top,node *p)
{stack *c;
if(!top)
    {top=new stack;
     top->point=p;
     top->back=0;}
 else
    {c=new stack;
     c->back=top;
     c->point=p;
     top=c;}
}

node *pop(stack* &top)
{if(top)
    {stack* c=top;
     top=top->back;
     return c->point;
    }
}

void insert(node *&root,int value)
{if(!root)
    {root=new node;
     root->value=value;
     root->left=root->right=0;
    }

 else
    {if(value<root->value)
        insert(root->left,value);
     else
        if(value>root->value)
            insert(root->right,value);
    }
}

void inorder(node *root)
{top=0;
 node *p=root;
 int ok=1;
 while(ok==1)
    {if(p)
        {push(top,p);
         p=p->left;
        }
     else
        if(top)
            {p=pop(top);
             cout<<p->value<<" ";
             p=p->right;
            }
     else
        ok=0;
    }
}

int main()
{int a[11],n,i;
cout<<"Input number of elements in array: ";
cin>>n;
cout<<endl<<"Input elements of the array: ";
for(i=1;i<=n;i++)
    cin>>a[i];
for(i=1;i<=n;i++)
    insert(root,a[i]);
cout<<endl<<"In order: ";
inorder(root);
return 0;
}
