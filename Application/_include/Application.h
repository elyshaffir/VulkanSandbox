#ifndef SANDBOX_APPLICATION_H
#define SANDBOX_APPLICATION_H

#include <string>
#include "../../Data/include/Version.h"

namespace sandbox::application
{
	class Application
	{
	public:
		Application(std::string name, const Version & version);

		void Run();
	protected:
		virtual void Initialize() = 0;

		virtual bool Continue() = 0;

		virtual void Loop() = 0;

		virtual void CleanUp() = 0;
	private:
		const std::string name;
		const Version version;
	};
}

#endif //SANDBOX_APPLICATION_H
