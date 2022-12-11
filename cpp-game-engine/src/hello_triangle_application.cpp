//
// hello_triangle_application.h
//
//	

#include "pch.h"
#include "hello_triangle_application.h"

void HelloTriangleApplication::run()
{
	// glfwSetErrorCallback(&glfwError);
	glfwInit();
	initVulkan();
	initWindow();
	mainWindowLoop();
	cleanUp();
}


//
// initVulkan()
// 
// Desc: Creates a Vulkan Instance
//
void HelloTriangleApplication::initVulkan()
{
	std::cout << "Initializing Vulkan\n";
	createVulkanInstance();
}

//
// createVulkanInstance()
// 
// Desc: Creating Vulkan Instance
//
void HelloTriangleApplication::createVulkanInstance()
{
	VkApplicationInfo appInfo{};
	appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
	appInfo.pApplicationName = "Hello Triangle";
	appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
	appInfo.pEngineName = "No Engine";
	appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);

	VkInstanceCreateInfo createInfo{};
	appInfo.apiVersion = VK_API_VERSION_1_0;
	createInfo.pApplicationInfo = &appInfo;

	uint32_t glfwExtensionCount = 0;
	const char** glfwExtensions;

	glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

	createInfo.enabledExtensionCount = glfwExtensionCount;
	createInfo.ppEnabledExtensionNames = glfwExtensions;

	createInfo.enabledLayerCount = 0;

	std::cout << "Creating Vulkan Instance\n";
	VkResult result = vkCreateInstance(&createInfo, nullptr, &instance);

	if(result != VK_SUCCESS)
		throw std::runtime_error("failed to create instance!\n");

}

// Window Management

//
// initWindow()
// 
// Desc: Creates a glfwWindow
//
void HelloTriangleApplication::initWindow()
{
	std::cout << "Created window\n";
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

	window = glfwCreateWindow(WIDTH, HEIGHT, "vulkan", nullptr, nullptr);
}

//
// mainWindowLoop()
// 
// Desc: Main Window render loop
//
void HelloTriangleApplication::mainWindowLoop()
{
	std::cout << "Entered main loop\n";
	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
	} // End While
	std::cout << "Exit main loop\n";
}

//
// cleanUp()
// 
// Desc: Deletes and frees memory linked to Window
//
void HelloTriangleApplication::cleanUp()
{
	std::cout << "Deleting Vulkan Instance\n";
	vkDestroyInstance(instance, nullptr);

	std::cout << "Closing Window\n";
	glfwDestroyWindow(window);
	glfwTerminate();
}


//
// glfwError(int, const char* description)
// 
// Desc: Displays GLFW Errors
//
void HelloTriangleApplication::glfwError(int, const char* description)
{
	std::cout << description << std::endl;
}

	