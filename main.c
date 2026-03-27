#include <stdio.h>
#include "binary_tree.h"

int main(){

    bt_node* tree;
    tree = NULL;

    for(int i = 1; i < 64; i++){
        tree = insert_node(tree, i);
    }

    print_sorted(tree);
    printf("\n");
    print_tree(tree); 

    printf("\n%d\n", get_tree_height(tree));        
    printf("%d\n", get_balance_factor(tree));

    printf("%s\n", is_balanced(tree) ? "balanced" : "NOT balanced");

    tree = delete_tree(tree);
    return 0;
}
