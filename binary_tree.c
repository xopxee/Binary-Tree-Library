#include <stdlib.h>
#include <stdio.h>
#include "binary_tree.h"

//Creates a 'root' an its sons. 
bt_node* create_root(int data, bt_node* left, bt_node* right){
    bt_node* proot = (bt_node*)malloc(sizeof(bt_node));
    
    if(proot == NULL){
        perror("Failed to allocate memory");
        exit(1);
    }

    //Initializes root's fields.
    proot->data  = data;
    proot->left  = left;
    proot->right = right;

    return proot;
}

//Creates a leaf containing the specifed data.
bt_node* create_leaf(int data){
    bt_node* pleaf = (bt_node*)malloc(sizeof(bt_node));

    if(pleaf == NULL){
        perror("Failed to allocate memory");
        exit(1);
    }

    //Initializes leaf's fields.
    pleaf->data  = data;
    pleaf->left  = NULL;
    pleaf->right = NULL;

    return pleaf;
}

bt_node* insert_node(bt_node* proot ,int data){
    
    //While root exists, tries to find the leaf recursively.
    if(proot != NULL){
        
        if(proot->data > data){
            proot->left = insert_node(proot->left, data);
        }
        else{
            proot->right = insert_node(proot->right, data);
        }
        //Return the new tree.
        return proot;
    }
    else{
        
        //Returns the new leaf inserted.
        bt_node* pnew = create_leaf(data);
        return pnew;
    }

}

//Finds the maximum height recursively.
int get_tree_height(bt_node* proot){ 
    
    //Stop Condition
    if(proot == NULL)
        return 0;
    
    //Haskell go brrrr
    return 1 + MAX(get_tree_height(proot->left), get_tree_height(proot->right));
}

//Prints all of the nodes, starting from bottom left leaves.
void print_tree(bt_node* proot){
    
    if(proot != NULL){
        print_tree(proot->left);
        print_tree(proot->right);
        printf("%d ", proot->data);
    }

}

//Prints a binary search tree sorted.
void print_sorted(bt_node* proot){

    if(proot != NULL){
        print_tree(proot->left);
        printf("%d ", proot->data);
        print_tree(proot->right);
    }
}

bt_node* delete_tree(bt_node* proot){    

    if(proot != NULL){
        proot->left  = delete_tree(proot->left);
        proot->right = delete_tree(proot->right);
        free(proot);
    }
    return NULL;
}






