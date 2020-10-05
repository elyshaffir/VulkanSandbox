#ifndef SANDBOX_ENGINE_H
#define SANDBOX_ENGINE_H

#include <string>
#include "Version.h"

namespace sandbox
{
	class Engine
	{
	public:
		static inline const std::string ENGINE_NAME = "Sandbox";
		static inline const sandbox::Version ENGINE_VERSION = {1, 0, 0};
	};
}

#endif //SANDBOX_ENGINE_H
