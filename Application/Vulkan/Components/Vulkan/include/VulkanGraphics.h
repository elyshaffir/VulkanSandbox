#ifndef SANDBOX_VULKANGRAPHICS_H
#define SANDBOX_VULKANGRAPHICS_H

#include "../../Headers/Graphics.h"

namespace sandbox::application::components
{
	class VulkanGraphics : Graphics
	{
	public:
		virtual void Initialize() override;

		virtual void Draw() override;

		virtual void CleanUp() override;
	};
}

#endif //SANDBOX_VULKANGRAPHICS_H
