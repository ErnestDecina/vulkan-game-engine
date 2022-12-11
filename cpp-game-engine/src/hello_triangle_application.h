//
// hello_triangle_application.h
//
//



// Symbolic Names
#define GLFW_INCLUDE_VULKAN
#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE

class HelloTriangleApplication
{
public:
	// Functions
	void run();
private:
	// Variables
	const uint32_t WIDTH = 800;
	const uint32_t HEIGHT = 800;

	GLFWwindow *window;
	VkInstance instance;

	uint32_t glfwExtensionCount = 0;
	const char** glfwExtensions;

	// Functions
	// Vulkan Managment
	void initVulkan();
	void createVulkanInstance();

	// Window Managment
	void initWindow();
	void mainWindowLoop();
	void cleanUp();
	static void glfwError(int , const char* );
};