#include "node.h"

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

struct node *new_leaf(char var)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->type = LEAF;
    n->var = var;
    return n;
}

struct node *new_node(enum node_type type, struct node *left, struct node *right)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->type = type;
    n->left = left;
    n->right = right;
    return n;
}

bool eval(struct node *root, bool values[])
{
    if (root == NULL)
    {
        return false;
    }

    switch (root->type)
    {
    case LEAF:
        return root->var;
    case NOT:
        return !eval(root->left, values);
    case AND:
        return eval(root->left, values) && eval(root->right, values);
    case OR:
        return eval(root->left, values) || eval(root->right, values);
    default:
        return false;
    }
}

void print_node(struct node *root)
{
    switch (root->type)
    {
    case LEAF:
        printf("%c", root->var);
        break;
    case AND:
        printf("(");
        print_node(root->left);
        printf(" & ");
        print_node(root->right);
        printf(")");
        break;
    case OR:
        printf("(");
        print_node(root->left);
        printf(" | ");
        print_node(root->right);
        printf(")");
        break;
    case NOT:
        printf("!");
        print_node(root->left);
        break;
    }
}

int est_satisfiable(struct node *root, int nb_atoms)
{
    int max = (1 << nb_atoms) - 1;
    bool values[nb_atoms];

    for (int i = max; i >= 0; i--)
    {
        for (int j = 0; j < nb_atoms; j++)
        {
            values[j] = (i >> j) & 1;
        }
        if (eval(root, values))
        {
            printf("\nLa formule est satisfiable avec : ");
            for (int j = 0; j < nb_atoms; j++)
            {
                printf("%d ", values[j]);
            }
            printf("\n");
            return 1;
        }
    }
    printf("\nLa formule n'est pas satisfiable\n");
    return 0;
}
