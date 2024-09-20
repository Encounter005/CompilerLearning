#include "Scanner.h"


int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << std::endl;
        exit(1);
    }

    try {
        Scanner scanner(argv[1]);
        scanner.run();
    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
