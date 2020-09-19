#include <utility>
#include <vector>
#include <GLFW/glfw3.h>
#include "../include/Instance.h"
#include "../../Metadata/include/Engine.h"
#include "../include/ValidationLayersUnavailableException.h"

using namespace sandbox::vulkan;

Instance::Instance() : Instance(std::vector<const char *>())
{
}

Instance::Instance(std::vector<const char *> validationLayers) : validationLayers(std::move(validationLayers)),
																 instance(nullptr)
{
	if (!CheckValidationLayerSupport(validationLayers))
	{
		throw ValidationLayersUnavailableException();
	}
}

void Instance::Initialize(const std::string & applicationName, Version applicationVersion,
						  io::OutputChannel outputChannel)
{
	VkApplicationInfo appInfo { };
	appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
	appInfo.pApplicationName = applicationName.c_str();
	appInfo.applicationVersion = VK_MAKE_VERSION(applicationVersion.major, applicationVersion.minor,
												 applicationVersion.patch);
	appInfo.pEngineName = Engine::ENGINE_NAME.c_str();
	appInfo.engineVersion = VK_MAKE_VERSION(Engine::ENGINE_VERSION.major, Engine::ENGINE_VERSION.minor,
											Engine::ENGINE_VERSION.patch);
	appInfo.apiVersion = VK_API_VERSION_1_0;

	VkInstanceCreateInfo createInfo { };
	createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
	createInfo.pApplicationInfo = &appInfo;

	std::vector<const char *> extensions = GetRequiredExtensions(!validationLayers.empty());
	createInfo.enabledExtensionCount = static_cast<uint32_t>(extensions.size());
	createInfo.ppEnabledExtensionNames = extensions.data();

	if (!validationLayers.empty())
	{
		VkDebugUtilsMessengerCreateInfoEXT debugCreateInfo { };
		createInfo.enabledLayerCount = static_cast<uint32_t>(validationLayers.size());
		createInfo.ppEnabledLayerNames = validationLayers.data();
		PopulateDebugMessengerCreateInfo(debugCreateInfo, outputChannel);
		createInfo.pNext = (VkDebugUtilsMessengerCreateInfoEXT *) &debugCreateInfo;
	}

	if (vkCreateInstance(&createInfo, nullptr, &instance) != VK_SUCCESS)
	{
		throw InstanceCreationException();
	}
}

bool Instance::CheckValidationLayerSupport(const std::vector<const char *> & validationLayers)
{
	uint32_t layerCount = 0;
	vkEnumerateInstanceLayerProperties(&layerCount, nullptr);

	std::vector<VkLayerProperties> availableLayers(layerCount);
	vkEnumerateInstanceLayerProperties(&layerCount, availableLayers.data());

	for (const char * layerName : validationLayers)
	{
		bool layerFound = false;
		for (const auto & layerProperties : availableLayers)
		{
			if (strcmp(layerName, layerProperties.layerName) == 0)
			{
				layerFound = true;
				break;
			}
		}
		if (!layerFound)
		{
			return false;
		}
	}
	return true;
}

std::vector<const char *> Instance::GetRequiredExtensions(bool enableValidationLayers)
{
	uint32_t glfwExtensionCount = 0;
	const char ** glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);
	std::vector<const char *> extensions(glfwExtensions, glfwExtensions + glfwExtensionCount);

	if (enableValidationLayers)
	{
		extensions.push_back(VK_EXT_DEBUG_UTILS_EXTENSION_NAME);
	}

	return extensions;
}

VkBool32 Instance::DebugCallback(VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
								 VkDebugUtilsMessageTypeFlagsEXT messageType,
								 const VkDebugUtilsMessengerCallbackDataEXT * pCallbackData, void * pUserData)
{
	((io::OutputChannel *) pUserData)->Error(std::string("validation layer: ") +
											 std::string(pCallbackData->pMessage));
	return VK_FALSE;
}

void Instance::PopulateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT & createInfo,
												io::OutputChannel & outputChannel)
{
	createInfo = { };
	createInfo.sType = VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT;
	createInfo.messageSeverity =
			VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT |
			VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT;
	createInfo.messageType =
			VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT |
			VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT;
	createInfo.pfnUserCallback = DebugCallback;
	createInfo.pUserData = &outputChannel;
}
