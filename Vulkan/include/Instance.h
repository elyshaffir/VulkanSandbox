#ifndef SANDBOX_INSTANCE_H
#define SANDBOX_INSTANCE_H

#include <vulkan/vulkan.h>
#include <string>
#include "../../Metadata/include/Version.h"

namespace sandbox::vulkan
{
	class Instance
	{
	public:

		Instance();

		explicit Instance(std::vector<const char *> validationLayers);

		void Initialize(const std::string & applicationName, sandbox::Version applicationVersion);

		void CleanUp();

	private:
		std::vector<const char *> validationLayers;
		VkInstance instance;
	};
}

#endif //SANDBOX_INSTANCE_H
