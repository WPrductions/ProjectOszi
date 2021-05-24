#pragma once

#include <ozpch.h>
#include "Oszi/Core.h"
#include "Oszi/Events/Event.h"


namespace Oszi {

	//Properties used to Create a Window
	struct WindowProps
	{
		std::string Title;
		unsigned int Width;
		unsigned int Hight;

		WindowProps(const std::string& title = "Oszi", unsigned int width = 1280, unsigned int hight = 720) : Title{ title }, Width{ width }, Hight{ hight }{}
	};


	//Interface representing a desktop window
	class OSZI_API Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() = default;

		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHight() const = 0;

		//Window attributes
		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		virtual void* GetNativeWindow() const = 0;

		static Window* Create(const WindowProps& props = WindowProps());
	};
}