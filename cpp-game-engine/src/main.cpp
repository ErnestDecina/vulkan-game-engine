
#include "pch.h"
#include "hello_triangle_application.h"


int main() 
{
    // Variables
    HelloTriangleApplication app;

    try {
        app.run();
    }
    catch (const std::exception& error) {
        std::cerr << error.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
} // End main