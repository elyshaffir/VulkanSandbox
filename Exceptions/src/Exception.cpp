
#include "../include/Exception.h"

using namespace sandbox::exceptions;

std::string Exception::Describe()
{
	return SeverityToString(severity) + DescribeDomain() + " exception through " + DescribeReason() + ":\n\t" +
		   DescribeSpecific();
}
