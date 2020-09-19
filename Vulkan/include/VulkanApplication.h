#ifndef SANDBOX_VULKANAPPLICATION_H
#define SANDBOX_VULKANAPPLICATION_H

#include "../../Application/include/Application.h"
#include "../../Application/Components/include/Window.h"
#include "VulkanGraphics.h"

namespace sandbox::application
{
	class VulkanApplication : public Application
	{
	protected:
		virtual void Initialize() override;

		virtual bool Continue() override;

		virtual void Loop() override;

		virtual void CleanUp() override;
	private:
		components::Window & window;
		components::VulkanGraphics graphics;
	};
}

#endif //SANDBOX_VULKANAPPLICATION_H
