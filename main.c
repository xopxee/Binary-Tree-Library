#include <stdio.h>
#include "binary_tree.h"

int main(){

    bt_node* tree;
    tree = NULL;

    for(int i = 1; i < 16; i++){
        tree = insert_node(tree, i);
    }
    
    bt_node* arv;
    arv = clone_tree(tree);

    print_sorted(tree);
    printf("\n");
    print_sorted(arv); 

    printf("\n%d\n", get_tree_height(tree));        
    printf("%d\n", get_balance_factor(tree));
    printf("%d\n", get_num_of_leaves(tree));

    printf("%s\n", is_balanced(tree) ? "balanced" : "NOT balanced");
    printf("%s\n", is_identical(tree, arv) ? "they are identical" : "they are NOT identical");
    printf("%s\n", is_leaf(tree) ? "Yes" : "No" );
    printf("%d\n", largest(tree)->data);

    tree = delete_tree(tree);
    arv = delete_tree(arv);
    return 0;
}
