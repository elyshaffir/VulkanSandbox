#ifndef SANDBOX_EXCEPTIONSEVERITY_H
#define SANDBOX_EXCEPTIONSEVERITY_H

#include <string>

namespace sandbox::exceptions
{
	enum class ExceptionSeverity
	{
		Warning,
		Fatal
	};

	std::string SeverityToString(ExceptionSeverity severity);
}

#endif //SANDBOX_EXCEPTIONSEVERITY_H
