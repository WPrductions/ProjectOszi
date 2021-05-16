#pragma once

#include "Window.h"
#include "GLFW/glfw3.h"

namespace Oszi {
	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();

		void OnUpdate() override;

		unsigned int GetWidth() const override { return m_Data.Width; }
		unsigned int GetHight() const override { return m_Data.Hight; }

		void SetVSync(bool enabled) override;
		bool IsVSync() const override { return m_Data.VSync; }

		virtual void* GetNativeWindow() const { return m_Window; }
	private:
		virtual void Init(const WindowProps& props);
		virtual void Shutdown();

		GLFWwindow* m_Window;

		struct WindowData
		{
			std::string Title;
			unsigned int Width, Hight;
			bool VSync;
		};

		WindowData m_Data;
	};
}