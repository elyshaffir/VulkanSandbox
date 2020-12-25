#include "../_include/Device.h"

#include <utility>
#include "../_include/NoSupportingDeviceException.h"

using namespace sandbox::vulkan;

Device * Device::PickDevice(const DeviceSupport & support, Surface surface,
							std::vector<VkPhysicalDevice> & physicalDevices,
							const std::vector<const char *> & validationLayers)
{
	auto physicalDeviceIterator = physicalDevices.begin();
	while (physicalDeviceIterator != physicalDevices.end())
	{
		QueueFamilyIndices queueFamilyIndices = surface.GetQueueFamilyIndices(*physicalDeviceIterator,
																			  support.GetQueueFamilySupport());
		if (support.CheckSupport(*physicalDeviceIterator, surface, queueFamilyIndices))
		{
			Device * device = CreateDevice(*physicalDeviceIterator, queueFamilyIndices, support, validationLayers);
			if (device != nullptr)
			{
				physicalDevices.erase(physicalDeviceIterator);
				return device;
			}
		}
		++physicalDeviceIterator;
	}
	throw NoSupportingDeviceException();
}

Device::Device(VkPhysicalDevice physicalDevice, DeviceSupport deviceSupport, VkDevice logicalDevice) :
		physicalDevice(physicalDevice), deviceSupport(std::move(deviceSupport)), logicalDevice(logicalDevice)
{
}

Device * Device::CreateDevice(VkPhysicalDevice physicalDevice, QueueFamilyIndices queueFamilyIndices,
							  const DeviceSupport & deviceSupport, std::vector<const char *> validationLayers)
{
	VkDevice logicalDevice = { };
	if (CreateLogicalDevice(physicalDevice, queueFamilyIndices, deviceSupport, std::move(validationLayers),
							&logicalDevice))
	{
		return new Device(physicalDevice, deviceSupport, logicalDevice);
	}
	return nullptr;
}

bool Device::CreateLogicalDevice(VkPhysicalDevice physicalDevice, QueueFamilyIndices queueFamilyIndices,
								 const DeviceSupport & deviceSupport, std::vector<const char *> validationLayers,
								 VkDevice * logicalDevice)
{
	VkDeviceCreateInfo createInfo { };
	createInfo.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
	std::vector<VkDeviceQueueCreateInfo> queueCreateInfos = queueFamilyIndices.CreateQueueCreateInfos();
	createInfo.queueCreateInfoCount = static_cast<uint32_t>(queueCreateInfos.size());
	createInfo.pQueueCreateInfos = queueCreateInfos.data();

	VkPhysicalDeviceFeatures deviceFeatures { };
	deviceFeatures.samplerAnisotropy = deviceSupport.GetArbitraryDeviceSupport().GetSamplerAnisotropySupport();
	createInfo.pEnabledFeatures = &deviceFeatures;

	createInfo.enabledExtensionCount = static_cast<uint32_t>(deviceSupport.GetExtensions().size());
	createInfo.ppEnabledExtensionNames = deviceSupport.GetExtensions().data();

	createInfo.enabledLayerCount = static_cast<uint32_t>(validationLayers.size());
	createInfo.ppEnabledLayerNames = validationLayers.data();

	if (vkCreateDevice(physicalDevice, &createInfo, nullptr, logicalDevice) != VK_SUCCESS)
	{
		return false;
	}
	return true;
}
