#pragma once

#include "Oszi/Events/Event.h"

namespace Oszi {
	class OSZI_API KeyEvent : public Event
	{
	public:
		inline int GetKeyCode() const { return m_KeyCode; }

		EVENT_CLASS_CATEGORY(KeyboardEvent | InputEvent)

	protected:
		KeyEvent(int keyCode) : m_KeyCode{ keyCode } {}

		int m_KeyCode;
	};

	class OSZI_API KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(const int keyCode, const int repeatCount) :KeyEvent(keyCode), m_RepeatCount(repeatCount) {}

		int GetRepeatCount() const { return m_RepeatCount; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent: " << m_KeyCode << "(" << m_RepeatCount << "repeats)";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)
	private:
		int m_RepeatCount;
	};
	
	class OSZI_API KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(const int keyCode) :KeyEvent(keyCode){}


		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << m_KeyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)
	};

	class OSZI_API KeyTypedEvent : public KeyEvent
	{
	public:
		KeyTypedEvent(const int keyCode) : KeyEvent(keyCode) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyTypedEvent: " << m_KeyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyTyped)
	};
}

