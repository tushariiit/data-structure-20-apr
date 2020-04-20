#include<stdio.h>
struct node{
int data;
struct node *left;
struct node *right;
};
int inorder(struct node *t)
{
    if(t)
    {
     inorder(t->left);
     printf("%d\n",t->data);
     inorder(t->right);
    }
    else
    {
     return 0;
    }
}
int balance(struct node* root)
{
    int lh;
    int rh;


    if (root == NULL)
        return 1;


    lh = height(root->left);
    rh = height(root->right);

    if (abs(lh - rh) <= 1 && balance(root->left) && balance(root->right))
        {
            printf("balanced");
        }
        else
            printf("unbalanced");


    return 0;
}


int max(int a, int b)
{
    return (a >= b) ? a : b;
}
int height(struct node* node)
{

    if (node == NULL)
        return 0;
    return 1 + max(height(node->left), height(node->right));
}
int main()
{
    int n,i,item;
    struct node*p,*q,*root,*t;
    printf("enter no of nodes");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        p=(struct node*)malloc(sizeof(struct node));
        scanf("%d",&item);
        p->data=item;
        p->left=NULL;
        p->right=NULL;
        if(i==0)
        {
            root=p;
        }
        else
        {
            q=root;
            while(1)
            {
                if(p->data>q->data)
                {
                    if(q->right==NULL)
                    {
                        q->right=p;
                        break;
                    }
                    else
                    {
                        q=q->right;
                    }
                }
                else
                {
                    if(q->left==NULL)
                    {
                        q->left=p;
                        break;
                    }
                    else
                    {
                        q=q->left;
                    }
                }
             }
            }
        }
        t=root;
        printf("inorder traversal\n:");
        inorder(t);
        t=root;
        balance(t);

    }

