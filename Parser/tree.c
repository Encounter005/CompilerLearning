#include "data.h"
#include "decl.h"
#include "defs.h"
// AST node Types


struct ASTnode *makeAstNode(
    int op, struct ASTnode *left, struct ASTnode *right, int value) {

    struct ASTnode *n;

    // malloc a new ASTNODE
    n = (struct ASTnode *) malloc(sizeof(struct ASTnode));
    if (n == NULL) {
        fprintf(stderr, "Unable to malloc for ASTnode");
        exit(1);
    }

    // Copy in the field values and return it
    n->op       = op;
    n->left     = left;
    n->right    = right;
    n->intvalue = value;
    return n;
}

// Make an ASTnode leaf
struct ASTnode *makeAstNodeLeaf(int op, int value) {
    return makeAstNode(op, NULL, NULL, value);
}


// Make an unary ASTnode: only one child ASTndoe
struct ASTnode *makeAstNodeUnary(int op, struct ASTnode *left, int value) {
    return makeAstNode(op, left, NULL, value);
}
