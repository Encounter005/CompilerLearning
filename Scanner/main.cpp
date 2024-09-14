#include "Scanner.h"


int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << std::endl;
        exit(1);
    }
    
    Scanner scanner(argv[1]);
    scanner.work();

    return 0;
}
