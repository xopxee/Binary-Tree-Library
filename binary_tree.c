#include <stdlib.h>
#include <stdio.h>
#include "binary_tree.h"

//Initializes the binary tree.
void init_bt(bt_node** proot, int data){
    bt_node* root = (bt_node*)malloc(sizeof(bt_node));
    
    if(root == NULL){
        perror("Failed to allocate memory");
        exit(1);
    }

    //Initializes root's fields.
    root->data  = data;
    root->left  = NULL;
    root->right = NULL;

    *proot = root;
}

//Creates a leaf containing the specifed data.
bt_node* create_leaf(int data){
    bt_node* leaf = (bt_node*)malloc(sizeof(bt_node));

    if(leaf == NULL){
        perror("Failed to allocate memory");
        exit(1);
    }

    //Initializes leaf's fields.
    leaf->data  = data;
    leaf->left  = NULL;
    leaf->right = NULL;

    return leaf;
}




