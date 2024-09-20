#include "decl.h"
#include "defs.h"
#include "data.h"


static char *ASTop[] = {"+", "-", "*", "/"};
int interpreAST(struct ASTnode *t) {
    int leftval, rightval;

    // Get the left and right sub-tree values
    if (t->left) {
        leftval = interpreAST(t->left);
    }
    if (t->right) {
        rightval = interpreAST(t->right);
    }

    if(t->op == A_INTLIT) {
        printf("int %d\n", t->intvalue);
    } else {
        printf("%d %s %d\n", leftval, ASTop[t->op] ,rightval);
    }

    switch (t->op) {
    case A_ADD: return leftval + rightval;
    case A_SUBTRACT: return leftval - rightval;
    case A_MULTIPLY: return leftval * rightval;
    case A_DIVIDE: return leftval / rightval;
    case A_INTLIT: return t->intvalue;
    default: fprintf(stderr, "Unknown AST operator %d\n", t->op); exit(1);
    }
}
