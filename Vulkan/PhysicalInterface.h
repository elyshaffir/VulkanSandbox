#ifndef SANDBOX_PHYSICALINTERFACE_H
#define SANDBOX_PHYSICALINTERFACE_H

#include <vector>
#include "Device.h"
#include "include/Instance.h"
#include "Surface.h"
#include "DeviceSupport.h"

namespace sandbox::vulkan
{
	class PhysicalInterface
	{
	public:
		PhysicalInterface();

		void Initialize(Instance instance, Surface surface, const std::vector<DeviceSupport> & neededSupports);

	private:
		std::vector<Device> devices;

		static bool IsPhysicalDeviceSuitable(Surface surface, VkPhysicalDevice physicalDevice);
	};
}

#endif //SANDBOX_PHYSICALINTERFACE_H
