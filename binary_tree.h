#ifndef BINARY_TREE_H
#define BINARY_TREE_H

//bt as in Binary Tree
typedef struct bt_node bt_node;

struct bt_node{
    int data;
    bt_node* left;
    bt_node* right;

};

//Initializes the binary tree.
void init_bt(bt_node** proot, int data);

//Creates a leaf containing the specifed data.
bt_node* create_leaf(int data);

//delete_bt

#endif
