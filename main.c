#include <stdio.h>
#include "binary_tree.h"

int main(){

    bt_node* tree;
    tree = create_root(5, create_root(3, create_leaf(2), create_leaf(4)), 
                          create_root(7, create_leaf(6), create_leaf(8)));

    print_sorted(tree);
    printf("\n%d\n", get_tree_height(tree));
    

    tree = delete_tree(tree);
    return 0;
}
