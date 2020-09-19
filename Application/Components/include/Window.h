#ifndef SANDBOX_WINDOW_H
#define SANDBOX_WINDOW_H

namespace sandbox::application::components
{
	class Window
	{
	public:
		virtual void Initialize() = 0;

		virtual bool ShouldClose() = 0;

		virtual void Update() = 0;

		virtual void CleanUp() = 0;
	};
}

#endif //SANDBOX_WINDOW_H
