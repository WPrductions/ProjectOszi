#pragma once

#include "Oszi/Events/Event.h"

namespace Oszi
{
	class WindowRezizeEvent : public Event
	{
	public:
		WindowRezizeEvent(unsigned int width, unsigned int height) : m_Width{ width }, m_Height{ height } {}

		unsigned int GetWidth() const { return m_Width; }
		unsigned int GetHight() const { return m_Height; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowResizeEvent: " << m_Width << ", " << m_Height;
			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowResize)
		EVENT_CLASS_CATEGORY(ApplicationEvent)
	private:
		unsigned int m_Width, m_Height;
	};

	class WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent() = default;

		EVENT_CLASS_TYPE(WindowClose)
		EVENT_CLASS_CATEGORY(ApplicationEvent)
	};
}