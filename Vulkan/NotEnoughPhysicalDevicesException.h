#ifndef SANDBOX_NOTENOUGHPHYSICALDEVICESEXCEPTION_H
#define SANDBOX_NOTENOUGHPHYSICALDEVICESEXCEPTION_H

#include "PhysicalInterfaceCreationException.h"

namespace sandbox::vulkan
{
	class NotEnoughPhysicalDevicesException : public PhysicalInterfaceCreationException
	{
	public:
		NotEnoughPhysicalDevicesException(uint32_t requestedDevices, uint32_t availableDevices);

	protected:
		std::string DescribeSpecific() override;

	private:
		uint32_t requestedDevices;
		uint32_t availableDevices;
	};
}

#endif //SANDBOX_NOTENOUGHPHYSICALDEVICESEXCEPTION_H
