#ifndef SANDBOX_INSTANCE_H
#define SANDBOX_INSTANCE_H

#include <vulkan/vulkan.h>
#include <string>
#include "../../../Data/_include/Version.h"
#include "../../../IO/_include/OutputChannel.h"

namespace sandbox::vulkan
{
	class Instance
	{
	public:

		Instance();

		explicit Instance(std::vector<const char *> validationLayers);

		void Initialize(const std::string & applicationName, Version applicationVersion,
						io::OutputChannel outputChannel);

		void CleanUp();

		VkInstance GetInstance();

		std::vector<const char *> GetValidationLayers();
	private:
		static inline const std::vector<const char *> DEFAULT_VALIDATION_LAYERS = {
				"VK_LAYER_KHRONOS_validation"
		};

		std::vector<const char *> validationLayers;
		VkInstance instance;
		VkDebugUtilsMessengerEXT debugMessenger;

		static bool CheckValidationLayerSupport(const std::vector<const char *> & validationLayers);

		static void CreateApplicationInfo(const std::string & applicationName, Version applicationVersion,
										  VkApplicationInfo * appInfo);

		static std::vector<const char *> GetRequiredExtensions(bool enableValidationLayers);

		static VKAPI_ATTR VkBool32 VKAPI_CALL DebugCallback(VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
															VkDebugUtilsMessageTypeFlagsEXT messageType,
															const VkDebugUtilsMessengerCallbackDataEXT * pCallbackData,
															void * pUserData);

		static void PopulateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT & createInfo,
													 io::OutputChannel & outputChannel);

		void CreateDebugUtilsMessengerEXT(const VkDebugUtilsMessengerCreateInfoEXT * pCreateInfo,
										  const VkAllocationCallbacks * pAllocator);
	};
}

#endif //SANDBOX_INSTANCE_H
