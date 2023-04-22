#ifndef NODE_H
#define NODE_H

#include <stdbool.h>

enum node_type
{
    LEAF,
    AND,
    OR,
    NOT
};

struct node
{
    enum node_type type;
    union
    {
        char var;
        struct
        {
            struct node *left;
            struct node *right;
        };
    };
};

struct node *new_leaf(char var);
struct node *new_node(enum node_type type, struct node *left, struct node *right);
bool eval(struct node *root, bool values[]);
void print_node(struct node *root);
int est_satisfiable(struct node *root, int num_atoms);

#endif
