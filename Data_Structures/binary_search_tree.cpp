#include<iostream>
using namespace std;

typedef struct tree
{
    int item;
    struct tree * parent; // pointer to parent
    struct tree *left;   // pointer to left child
    struct tree *right; // pointer to right child
}tree;

tree* search_tree(tree *l, int data)
{
    if (l==NULL)
        return NULL;
    if (l->item==data)
        return l;
    if (data < l->item)
        return search_tree(l->left,data);
    else
        return search_tree(l->right, data);
}

tree * find_minimum(tree *t)
{
    tree *min;
    if (t==NULL)
        return NULL;
    min = t;
    while(min->left!=NULL)
        min = min->left;
    return min;
}

void inorder_traverse_tree(tree *l)
{
    if (l!= NULL)
    {
        inorder_traverse_tree(l->left);
        cout<<l->item;
        inorder_traverse_tree(l->right);
    }
}


void preorder_traverse_tree(tree *l)
{
    if (l!= NULL)
    {
        cout<<l->item;
        inorder_traverse_tree(l->left);

        inorder_traverse_tree(l->right);
    }
}

void postorder_traverse_tree(tree *l)
{
    if (l!= NULL)
    {

        inorder_traverse_tree(l->left);

        inorder_traverse_tree(l->right);

        cout<<l->item; //process last
    }
}

void insert_tree(tree** root, int x, tree *parent)
{
    tree *p;
    if (root==NULL)
    {
        p = new tree;
        p->item = x;
        p->left = p->right = NULL;
        p->parent = parent;
        *root = p;
        return;
    }
    if (x<(*root)->item)
        insert_tree(&((*root)->left),x,*root);
    else
        insert_tree(&((*root)->right),x,*root);
}






























