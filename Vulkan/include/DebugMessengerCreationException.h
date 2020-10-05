#ifndef SANDBOX_DEBUGMESSENGERCREATIONEXCEPTION_H
#define SANDBOX_DEBUGMESSENGERCREATIONEXCEPTION_H

#include "InstanceCreationException.h"

namespace sandbox::vulkan
{
	class DebugMessengerCreationException : public InstanceCreationException
	{
	protected:
		std::string DescribeSpecific() override;
	};
}

#endif //SANDBOX_DEBUGMESSENGERCREATIONEXCEPTION_H
