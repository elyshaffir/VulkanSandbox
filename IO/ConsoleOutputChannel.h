#ifndef SANDBOX_CONSOLEOUTPUTCHANNEL_H
#define SANDBOX_CONSOLEOUTPUTCHANNEL_H

#include "include/OutputChannel.h"

namespace sandbox::io
{
	class ConsoleOutputChannel : public OutputChannel
	{
		void Info(std::string info) override;

		void Error(std::string error) override;
	};
}

#endif //SANDBOX_CONSOLEOUTPUTCHANNEL_H
