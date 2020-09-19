#ifndef SANDBOX_GRAPHICS_H
#define SANDBOX_GRAPHICS_H

namespace sandbox::application::components
{
	class Graphics
	{
	public:
		virtual void Initialize() = 0;

		virtual void Draw() = 0;

		virtual void CleanUp() = 0;
	};
}

#endif //SANDBOX_GRAPHICS_H
