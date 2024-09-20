#include "data.h"
#include "decl.h"
#include "defs.h"
// Convert a token into an AST operation
int aritop(int tok) {
    switch (tok) {
    case T_PLUS: return A_ADD; break;
    case T_MINUS: return A_SUBTRACT; break;
    case T_MUL: return A_MULTIPLY; break;
    case T_SLASH: return A_DIVIDE; break;
    default:
        fprintf(stderr, "unknown token in aritop() on line %d\n", Line);
        exit(1);
    }
}

// Parse a primary factor and return an
//  ASTnode representing it
static struct ASTnode *primary() {
    struct ASTnode *n;

    switch (Token.token) {
    case T_INTLIT:
        n = makeAstNodeLeaf(A_INTLIT, Token.intvalue);
        scan(&Token);
        return n;
    default: fprintf(stderr, "syntax error on line %d\n", Line); exit(1);
    }
}

// return an AST tree whose root is a binary operator
struct ASTnode *binexpr() {
    struct ASTnode *n, *left, *right;
    int             nodetype;

    // Get the integer literal on the left.
    // Fetch the next token at the same time.
    left = primary();
    if (Token.token == T_EOF) {
        return left;
    }

    // Convert the token into a node type
    nodetype = aritop(Token.token);

    // Get the next token in
    scan(&Token);

    // Recursively build the right-side tree
    right = binexpr();

    // Now build a tree with both sub-trees
    n = makeAstNode(nodetype, left, right, 0);
    return n;
}
