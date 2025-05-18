#pragma once

#include "Event.h"

#include <sstream>

namespace SGL
{
	class SGL_API KeyEvent : public Event
	{
		public:
			inline int GetKeyCode() const { return m_KeyCode; }

			EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryKeyboard);

		protected:
			KeyEvent(int keyCode) : m_KeyCode(keyCode) {}
			int m_KeyCode;
	};


	class SGL_API KeyPressedEvent : public KeyEvent
	{
		public:
			KeyPressedEvent(int keyCode, int repeatCount) : KeyEvent(keyCode), m_RepeatCount(repeatCount) {}

			inline int GetRepeatCount() const { return m_RepeatCount; }

			std::string ToString() const override
			{
				std::stringstream ss;
				ss << "KetPressedEvent: " << m_KeyCode << " (" << m_RepeatCount << " repeats)";
				return ss.str();
			}

			EVENT_CLASS_TYPE(KeyPressed);

		private:
			int m_RepeatCount;
	};


	class SGL_API KeyReleaseEvent : public KeyEvent
	{
		public:
			KeyReleaseEvent(int keyCode) : KeyEvent(keyCode) {}
			
			std::string ToString() const override
			{
				std::stringstream ss;
				ss << "KeyReleaseEvent: " << m_KeyCode;
				return ss.str();
			}
			
			EVENT_CLASS_TYPE(KeyReleased);
	};
}