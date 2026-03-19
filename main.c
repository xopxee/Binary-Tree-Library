#include <stdio.h>
#include "binary_tree.h"

int main(){

    bt_node* tree;
    tree = create_root(5, create_leaf(3), create_leaf(7)); 
    
    print_tree(tree);
    printf("\n");
    print_sorted(tree);
    
    tree = delete_tree(tree);
    return 0;
}
