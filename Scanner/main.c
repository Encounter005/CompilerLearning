#include "defs.h"
#define extern_
#include "data.h"
#undef extern_
#include "decl.h"
#include <errno.h>

// initialize global variables
static void init() {
    Line = 1;
    Putback = '\n';
}

char *tokenstr[] = {"+", "-", "*", "/", "initlit"};

// Print out a usage if started incorrectly
static void usage(char *prog) {
    fprintf(stderr, "Usage: %s infile\n", prog);
    exit(1);
}


static void scanfile() {
    struct  token T;
    while(scan(&T)) {
        printf("Token: %s", tokenstr[T.token]);
        if(T.token == T_INTLIT) {
            printf(", Value: %d\n", T.intvalue);
        }
        puts("");
    }
}
int main(int argc, char *argv[]) {
    if(argc != 2) {
        usage(argv[0]);
    }

    init();
    // r means read only mode
    if((Infile = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "Unable to open %s: %s\n", argv[1], strerror(errno));
        exit(1);
    }

    scanfile();

    return 0;
}
