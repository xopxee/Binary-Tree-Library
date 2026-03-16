#include <stdio.h>
#include "binary_tree.h"

int main(){

    bt_node* tree;
    init_bt(&tree, 3);

    tree->left  = create_leaf(5);
    tree->right = create_leaf(2);

    return 0;
}
