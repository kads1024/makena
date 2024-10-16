#pragma once

#include "Makena/Layer.h"

#include "Makena/Events/KeyEvent.h"
#include "Makena/Events/MouseEvent.h"
#include "Makena/Events/ApplicationEvent.h"

namespace Makena
{
	class MAKENA_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;

		void Begin();
		void End();
	private:
		float m_Time = 0.0f;
	};
}
