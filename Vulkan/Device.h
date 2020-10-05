#ifndef SANDBOX_DEVICE_H
#define SANDBOX_DEVICE_H

#include <vulkan/vulkan.h>
#include <map>
#include "DeviceSupport.h"

namespace sandbox::vulkan
{
	class Device
	{
	public:
		static std::vector<Device> GatherDevices(Surface surface, const std::vector<DeviceSupport> & neededSupports,
												 const std::vector<VkPhysicalDevice> & physicalDevices);

	private:
		VkPhysicalDevice physicalDevice;
		VkDevice logicalDevice;

		explicit Device(VkPhysicalDevice physicalDevice);

		static uint32_t FindDevice(Surface surface, const DeviceSupport & support, bool unused,
								   const std::map<uint32_t, uint32_t> & supported,
								   const std::vector<VkPhysicalDevice> & physicalDevices);
	};
}

#endif //SANDBOX_DEVICE_H
