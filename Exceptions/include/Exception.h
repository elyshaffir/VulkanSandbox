#ifndef SANDBOX_EXCEPTION_H
#define SANDBOX_EXCEPTION_H

#include <string>
#include "ExceptionSeverity.h"

namespace sandbox::exceptions
{
	class Exception
	{
	public:
		inline explicit Exception(ExceptionSeverity severity) : severity(severity)
		{
		}

		std::string Describe();

	protected:
		virtual std::string DescribeDomain() = 0;

		virtual std::string DescribeReason() = 0;

		virtual std::string DescribeSpecific() = 0;

	private:
		ExceptionSeverity severity;
	};
}

#endif //SANDBOX_EXCEPTION_H
