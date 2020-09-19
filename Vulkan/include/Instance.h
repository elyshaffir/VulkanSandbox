#ifndef SANDBOX_INSTANCE_H
#define SANDBOX_INSTANCE_H

#include <vulkan/vulkan.h>
#include <string>
#include "../../Metadata/include/Version.h"
#include "../../IO/include/OutputChannel.h"

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

	private:
		std::vector<const char *> validationLayers;
		VkInstance instance;

		static bool CheckValidationLayerSupport(const std::vector<const char *> & validationLayers);

		static std::vector<const char *> GetRequiredExtensions(bool enableValidationLayers);

		static VKAPI_ATTR VkBool32 VKAPI_CALL DebugCallback(VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
															VkDebugUtilsMessageTypeFlagsEXT messageType,
															const VkDebugUtilsMessengerCallbackDataEXT * pCallbackData,
															void * pUserData);

		static void PopulateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT & createInfo,
													 io::OutputChannel & outputChannel);
	};
}

#endif //SANDBOX_INSTANCE_H
