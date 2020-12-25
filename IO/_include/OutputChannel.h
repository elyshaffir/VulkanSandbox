#ifndef SANDBOX_OUTPUTCHANNEL_H
#define SANDBOX_OUTPUTCHANNEL_H

#include <string>

namespace sandbox::io
{
	class OutputChannel
	{
	public:
		virtual void Info(std::string toWrite) = 0;

		virtual void Error(std::string toWrite) = 0;
	};
}

#endif //SANDBOX_OUTPUTCHANNEL_H
