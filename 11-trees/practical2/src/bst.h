#ifndef MODULE_TREE_H_
#define MODULE_TREE_H_


struct bst {
    char data[64];
    struct bst *left;
    struct bst *right;
};

struct bst *bst_construct();
void bst_insert(struct bst **tree, char *data);

void bst_in_order_traverse(struct bst *tree, void(*fn)(char* data));

#endif // MODULE_TREE_H_