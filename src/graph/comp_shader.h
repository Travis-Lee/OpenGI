#ifndef COMP_SHADER_H
#define COMP_SHADER_H
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <iostream>
#include <stdexcept>
#include <cstdlib>

class CompShader{
public:
    CompShader(); 
    
    ~CompShader();
    
    void run();

    const uint32_t WIDTH = 800;
    
    const uint32_t HEIGHT = 600;

private:
    GLFWwindow* window;
    
    VkInstance instance;
    
    void initWindow(); 

    void initVulkan();

    void mainLoop();

    void cleanup();
    
    void createInstance();

};
#endif 
