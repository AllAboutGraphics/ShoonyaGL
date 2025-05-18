#pragma once

#include "Event.h"

#include <sstream>

namespace SGL
{
	class SGL_API MouseMovedEvent : public Event
	{
		public:
			MouseMovedEvent(float x, float y) : m_MouseX(x), m_MouseY(y) {}

			inline float GetX() const { return m_MouseX; }
			inline float GetY() const { return m_MouseY; }

			std::string ToString() const override
			{
				std::stringstream ss;
				ss << "MouseMovedEvent: " << m_MouseX << ", " << m_MouseY;
				return ss.str();
			}

			EVENT_CLASS_TYPE(MouseMoved);
			EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse);

		private:
			float m_MouseX;
			float m_MouseY;
	};


	class SGL_API MouseScrolledEvent : public Event
	{
		public:
			MouseScrolledEvent(int offsetX, int offsetY) : m_OffsetX(offsetX), m_OffsetY(offsetY) {}

			inline float GetXOffset() const { return m_OffsetX; }
			inline float GetYOffset() const { return m_OffsetY; }

			std::string ToString() const override
			{
				std::stringstream ss;
				ss << "MouseScrolledEvent: " << GetXOffset() << ", " << GetYOffset();
				return ss.str();
			}

			EVENT_CLASS_TYPE(MouseScrolled);
			EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse);

		private:
			float m_OffsetX;
			float m_OffsetY;
	};


	class SGL_API MouseButtonEvent : public Event
	{
		public:
			inline int GetMouseButton() const { return m_Button; }

			EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouseButton);
			
		protected:
			int m_Button;
			MouseButtonEvent(int button) : m_Button(button) {}
	};


	class SGL_API MouseButtonPressedEvent : public MouseButtonEvent
	{
		public:
			MouseButtonPressedEvent(int button) : MouseButtonEvent(button) {}

			std::string ToString() const override
			{
				std::stringstream ss;
				ss << "MouseButtonPressedEvent: " << m_Button;
				return ss.str();
			}

			EVENT_CLASS_TYPE(MouseButtonPressed);
	};

	
	class SGL_API MouseButtonReleaseEvent : public MouseButtonEvent
	{
		public:
			MouseButtonReleaseEvent(int button) : MouseButtonEvent(button) {}

			std::string ToString() const override
			{
				std::stringstream ss;
				ss << "MouseButtonReleaseEvent: " << m_Button;
				return ss.str();
			}

			EVENT_CLASS_TYPE(MouseButtonReleased);
	};
}