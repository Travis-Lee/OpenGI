#include "comp_shader.h"

int main() {
    CompShader cs;
    try {
        cs.run();
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
