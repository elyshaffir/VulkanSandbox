#ifndef SANDBOX_EXTENSIONUNAVAILABLEEXCEPTION_H
#define SANDBOX_EXTENSIONUNAVAILABLEEXCEPTION_H

#include "InstanceCreationException.h"

namespace sandbox::vulkan
{
	class ExtensionUnavailableException : public InstanceCreationException
	{
	public:
		ExtensionUnavailableException(std::string extension);

	protected:
		std::string DescribeSpecific() override;
		
	private:
		std::string extension;
	};
}

#endif //SANDBOX_EXTENSIONUNAVAILABLEEXCEPTION_H
