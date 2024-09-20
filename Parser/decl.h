int             scan(struct token *t);
struct ASTnode *makeAstNode(
    int op, struct ASTnode *left, struct ASTnode *right, int value);

struct ASTnode *makeAstNodeLeaf(int op, int value);
struct ASTnode *makeAstNodeUnary(int op, struct ASTnode *left, int value);
struct ASTnode *binexpr();

int interpreAST(struct ASTnode *t);
