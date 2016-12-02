#include<iostream>
using namespace std;

class node
{public:
int value;
node *left,*right;

} *root,*tns, *tns1;

void add_node(node *&root,int v)
{if(!root)
    {root=new node;
     root->value=v;
     root->left=root->right=0;
    }

 else
    {if(v<root->value)
        add_node(root->left,v);
     else
        if(v>root->value)
            add_node(root->right,v);
    }
}

void create(node *&root)
{int v,n,i;

cout<<"Input number of nodes: ";

cin>>n;

cout<<endl<<"Input values in the tree: ";

for(i=1;i<=n;i++)
    {cin>>v;
     add_node(root,v);
    }

}

node *replace(node *p,node *&tns1)
{tns1=p;
p=p->right;
while(p->left)
    {tns1=p;
     p=p->left;
    }
return p;
}

void delete_node(node *&root,int x)
{node *nd, *rep;

nd=root;

while(nd->value!=x)
    {if(nd->value>x)
        {tns=nd;
         nd=nd->left;}
     else
        {tns=nd;
         nd=nd->right;}
    }

if(!nd)
    cout<<endl<<"Value "<<x<<" is not in the binary search tree.";
else
    if(nd->right==nd->left)  //the node does not have children
        {if(nd==root)
            delete root;
        else
            if(nd->value<tns->value)
                tns->left=0;
            else
                tns->right=0;
        }
    else
        if(nd->right==0&&nd->left)  //the node has only left child
            {if(nd==root)
                {tns=root;
                 root=root->left;
                 delete tns;
                }
             else
                if(tns->value<nd->value)
                    {tns->right=nd->left;
                     delete nd;
                    }
                else
                    {tns->left=nd->left;
                     delete nd;
                    }
            }
        else
            if(nd->left==0&&nd->right)  //the node has only right child
                {if(nd==root)
                    {tns=root;
                     root=root->right;
                     delete tns;
                    }
                 else
                    if(tns->value>nd->value)
                        {tns->left=nd->right;
                         delete nd;
                        }
                    else
                        {tns->right=nd->right;
                         delete nd;
                        }
                }
            else   //the node has both left and right child
                {rep=replace(nd,tns1);
                 if(rep->right==rep->left)  //replacement node has no children
                     {if(nd==root)
                        {rep->right=root->right;
                         rep->left=root->left;
                         root=rep;
                         tns1->left=0;
                        }
                      else
                        if(tns->value>rep->value)
                            {tns->left=tns1->left;
                             rep->right=nd->right;
                             rep->left=nd->left;
                             tns1->left=0;}
                        else
                            {tns->right=tns1->left;
                             rep->right=nd->right;
                             rep->left=nd->left;
                             tns1->left=0;
                        }
                     }

                 else  //replacement node has right child
                    {if(nd==root)
                        {tns1->left=rep->right;
                         rep->right=root->right;
                         rep->left=root->left;
                         root=rep;
                        }
                     else
                        if(tns->value>rep->value)
                            {tns->left=tns1->left;
                             tns1->left=rep->right;
                             rep->left=nd->left;
                             rep->right=nd->right;
                            }
                        else
                            {tns->right=tns1->left;
                             tns1->left=rep->right;
                             rep->right=nd->right;
                             rep->left=nd->left;
                            }
                    }

                }
}

void inorder(node *root)
{if(root)
    {inorder(root->left);
     cout<<root->value<<" ";
     inorder(root->right);
    }
}

int main()
{int x;

create(root);

cout<<endl<<"Binary search tree (in order): ";
inorder(root);

cout<<endl<<endl<<"Input value to delete : ";
cin>>x;

delete_node(root,x);

cout<<endl<<"Binary search tree (in order): ";
inorder(root);

return 0;
}
