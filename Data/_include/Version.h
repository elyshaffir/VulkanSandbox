#ifndef SANDBOX_VERSION_H
#define SANDBOX_VERSION_H

#include <cstdint>

namespace sandbox
{
	struct Version
	{
	public:
		const uint8_t major;
		const uint8_t minor;
		const uint8_t patch;
	};
}

#endif //SANDBOX_VERSION_H
