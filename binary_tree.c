#include <stdlib.h>
#include <stdio.h>
#include "binary_tree.h"

//Creates a 'root' an its children. 
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
        
        if(data < proot->data){
            proot->left = insert_node(proot->left, data);
        }
        else{
            proot->right = insert_node(proot->right, data);
        }

        //Balances if needed.
        proot = balance(proot);

        //Return the new tree.
        return proot;
    }
    else{
        
        //Returns the new leaf inserted.
        bt_node* pnew = create_leaf(data);
        return pnew;
    }

}

bt_node* remove_node(bt_node* proot, int data){
    
    if(proot == NULL)
        return NULL;
    
    //Found node to delete.
    if(data == proot->data){
        
        //If it has one or zero children.
        if(proot->right == NULL){
            bt_node* aux = proot->left;
            
            //Delete and return its child.
            free(proot); 
            proot = aux;
        }
        else if(proot->left == NULL){
            bt_node* aux = proot->right;
            
            //Delete and return its child.
            free(proot);
            proot = aux;
        }
        else{   //If it has two children.
            
            //Finds the largest node on the left subtree.
            bt_node* target = largest(proot->left);
            
            //Copies the data from it to the root node.
            proot->data = target->data;

            //Deletes it (Since the node to delete is a leaf, it's easier now).
            proot->left = remove_node(proot->left, target->data);
        }
    }   //Finds recursively the desired node based on its value.
    else if(data < proot->data){
        proot->left = remove_node(proot->left, data);
    }
    else{
        proot->right = remove_node(proot->right, data);
    }
    
    //Rebalances it if needed.
    return balance(proot);
}

//Finds the maximum height recursively.
unsigned int get_tree_height(bt_node* proot){ 
    
    //Stop Condition
    if(proot == NULL)
        return 0;
    
    //Haskell go brrrr
    return 1 + MAX(get_tree_height(proot->left), get_tree_height(proot->right));
}

unsigned int get_num_of_leaves(bt_node* proot){

    if(proot == NULL)
        return 0;

    return 1 + get_num_of_leaves(proot->left) + get_num_of_leaves(proot->right);
}

int get_balance_factor(bt_node* proot){
    
    if(proot == NULL)
        return 0;

    return get_tree_height(proot->left) - get_tree_height(proot->right); 
}

bool is_identical(bt_node* pa, bt_node* pb){
    
    //If they both reached the end, they're equal so far.
    if(pa == NULL && pb == NULL){
        return true;
    }

    //Avoids seg fault.
    if(pa == NULL || pb == NULL){
        return false;
    }
    
    //If they are equal, checks recursively if their children are equal too.
    if(pa->data == pb->data){
        return is_identical(pa->left, pb->left)
            && is_identical(pa->right, pb->right);
    }
    return false;
}

bool is_balanced(bt_node* proot){
   return ABS(get_balance_factor(proot)) < 2 ? true : false; 
}

//nested ternary operator :0
bool is_leaf(bt_node* proot){
    
    if(proot == NULL){
        return false;
    }

    return proot->left == NULL ? (proot->right == NULL ? true : false) : false;
}

bt_node* rr(bt_node* proot){
    
    bt_node* aux = proot->left;
    proot->left = aux->right;
    aux->right = proot;
    
    //aux is returned as the new root now.
    return aux;
}

bt_node* ll(bt_node* proot){
    
    bt_node* aux = proot->right;
    proot->right = aux->left;
    aux->left = proot;
    
    //aux is returned as the new root now.
    return aux;
}

bt_node* balance(bt_node* proot){
 
    if(is_balanced(proot))
        return proot;
        
    //if the tree is heavier on the left side.
    if(get_balance_factor(proot) > 0){
      
        //if signs don't match, first you make it do.
        if(get_balance_factor(proot->left) < 0){
            proot->left = ll(proot->left);
        }

        //rotates the tree right.
        proot = rr(proot);

    }
    else{   //heavier on the right side (< 0).

        //if signs don't match, first you make it do.
        if(get_balance_factor(proot->right) > 0){
            proot->right = rr(proot->right);
        }

        //rotates the tree left.
        proot = ll(proot);
    }

}

bt_node* clone_tree(bt_node* proot){
    
    if(proot == NULL)
        return NULL;
    
    //Clones root and all subtrees recursively.
    bt_node* clone;
    clone = create_root(proot->data, clone_tree(proot->left), clone_tree(proot->right));
    
    return clone;
}

bt_node* largest(bt_node* proot){
    
    if(proot == NULL)
        return NULL;

    bt_node* target = proot;

    if(proot->right != NULL){
        target = largest(proot->right);
    }
    return target;
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
        print_sorted(proot->left);
        printf("%d ", proot->data);
        print_sorted(proot->right);
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






