#pragma once

#include <ozpch.h>
#include "Oszi/Core.h"

namespace Oszi
{
	enum class EventType
	{
		None = 0,
		//Window Events
		WindowClose, WindowResize, WindowFocus, WindowMoved,
		//Key Events
		KeyPressed, KeyReleased,
		//Mouse Events
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScroled
	};

	enum EventCategory
	{
		None = 0,
		ApplicationEvent	= BIT(0),
		InputEvent			= BIT(1),
		KeyboardEvent		= BIT(2),
		MouseEvent			= BIT(3),
		MouseButtonEvent	= BIT(4)
	};

#define EVENT_CLASS_TYPE(type)  static EventType GetStaticEventType() { return EventType::type; }\
								virtual EventType GetEventType() const override { return GetStaticEventType(); }\
								virtual const char* GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

	class Event
	{
	public:
		virtual ~Event() = default;

		bool Handled = false;

		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }

		bool IsInCategory(EventCategory category)
		{
			return GetCategoryFlags() & category;
		}
	};

	class EventDispatcher
	{
		template<typename T>
		using EventFn = std::function<bool(&T)>;
	public:
		EventDispatcher(Event& event) : m_Event{ event } {}
		
		template<typename T>
		bool Dispatch(EventFn<T> func)
		{
			if (m_Event.GetEventType() == T::GetStaticType())
			{
				m_Event.Handled = func(*(T*)&m_Event);
				return true;
			}
			return false;
		}
	private:
		Event& m_Event;
	};

	inline std::ostream& operator<<(std::ostream& os, const Event& e)
	{
		return os << e.ToString();
	}
}