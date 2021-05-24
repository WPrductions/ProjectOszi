#include <Oszi.h>

class Startup : public Oszi::Application
{
public:
	Startup() {
		PushLayer(new Oszi::ImGuiLayer());
	}
	~Startup() {

	}
};

Oszi::Application* Oszi::CreateApplication() {
	return new Startup();
}