#ifndef MODULE_TREE_H_
#define MODULE_TREE_H_


struct bst {
    char data[64];
    struct bst *left;
    struct bst *right;
};

struct bst *bst_construct();
struct bst *bst_destruct(struct bst *tree);

void bst_insert(struct bst **tree, char *data);
struct bst *bst_remove_node(struct bst **node);

void bst_pre_order_traverse(struct bst *tree, void(*fn)(char* data));
void bst_in_order_traverse(struct bst *tree, void(*fn)(char* data));
void bst_post_order_traverse(struct bst *tree, void(*fn)(char* data));

#endif // MODULE_TREE_H_