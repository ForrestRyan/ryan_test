#include "header.h"
#include <optional>
#include <string>


void testOptional() {

    // std::cout << "Hello, World!" << std::endl;
    std::optional<std::string> testOptional;
    testOptional.reset();
    try
    {
        std::cout << testOptional.value() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}