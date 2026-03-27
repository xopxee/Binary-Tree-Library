#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stdbool.h>

#define MAX(a, b) ( ( (a) > (b) ) ? (a) : (b) )
#define ABS(a) ( ( (a) >= 0 ) ? (a) : (-a) )
    
//bt as in Binary Tree
typedef struct bt_node bt_node;

struct bt_node{
    int data;
    bt_node* left;
    bt_node* right;

};

//Creates a 'root' and its sons.
bt_node* create_root(int data, bt_node* left, bt_node* right);

//Creates a leaf containing the specifed data.
bt_node* create_leaf(int data);

//Inserts a node in a Binary Search Tree.
bt_node* insert_node(bt_node* proot, int data);
  
//Finds the height of the Tree.
int get_tree_height(bt_node* proot);

//Returns balance factor of the especific node, for balancement purposes.
int get_balance_factor(bt_node* proot);

//Checks if balance_factor absolute value is less than 2.
bool is_balanced(bt_node* proot);

//Rotate right.
bt_node* rr(bt_node* proot);

//Rotate left.
bt_node* ll(bt_node* proot);

//Balances the tree if it's not already the case and returns the balanced tree's root.
bt_node* balance(bt_node* proot);

//Prints all of the nodes, starting from bottom left leaves.
void print_tree(bt_node* proot);

//Prints a binary search tree sorted.
void print_sorted(bt_node* proot);

//Deletes a tree.
bt_node* delete_tree(bt_node* proot);


#endif
