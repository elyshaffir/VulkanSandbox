#ifndef SANDBOX_EXCEPTION_H
#define SANDBOX_EXCEPTION_H

#include <string>

namespace sandbox::exceptions
{
	class Exception
	{
	public:
		std::string Describe();

	protected:
		virtual std::string DescribeDomain() = 0;

		virtual std::string DescribeReason() = 0;

		virtual std::string DescribeSpecific() = 0;
	};
}

#endif //SANDBOX_EXCEPTION_H
