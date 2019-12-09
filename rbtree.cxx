#include <iostream>

typedef int KEY_TYPE;

typedef struct _rbtree_node
{
    KEY_TYPE key;
    void* value;
    
    unsigned char color;
    _rbtree_node *left;
    _rbtree_node *right;
    _rbtree_node *parent;
} rbtree_node;

typedef struct _rbtree
{
    rbtree_node *root;
    rbtree_node *nil;
} rbtree;

//  basic operate
//  left rotate
void rbtree_left_rotate(rbtree *T,rbtree_node *x)
{
    rbtree_node *y = x->right;
    
    x->right = y->left; //1
    if (y->left != T->nil)  //2
        y->left->parent = x;
    
    y->parent = x->parent; //3
    if (x->parent == T->nil) //4
    {
        T->root = y;
    }
    else if (x == x->parent->left)
    {
        x->parent->left = y;
    }
    else
    {
        x->parent->right = y;
    }
    
    y->left = x;  //5
    x->parent = y; //6
}

//  basic operate
//  right rotate
void rbtree_right_rotate(rbtree *T,rbtree_node *y)
{
    rbtree_node *x = y->left;
    
    y->left = x->right; //1
    if (x->right != T->nil)  //2
        x->right->parent = y;
    
    x->parent = y->parent; //3
    if (y->parent == T->nil) //4
    {
        T->root = x;
    }
    else if (y == y->parent->right)
    {
        y->parent->right = x;
    }
    else
    {
        y->parent->left = x;
    }
    
    x->right = y;  //5
    y->parent = x; //6
}



