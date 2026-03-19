#ifndef BINARY_TREE_H
#define BINARY_TREE_H

//bt as in Binary Tree
typedef struct bt_node bt_node;

struct bt_node{
    int data;
    bt_node* left;
    bt_node* right;

};

//Creates a 'root' an its sons.
bt_node* create_root(int data, bt_node* left, bt_node* right);

//Creates a leaf containing the specifed data.
bt_node* create_leaf(int data);

//Prints all of the nodes, starting from bottom left leaves.
void print_tree(bt_node* proot);

//Prints a binary search tree sorted.
void print_sorted(bt_node* proot);

//Deletes a tree.
bt_node* delete_tree(bt_node* proot);


#endif
