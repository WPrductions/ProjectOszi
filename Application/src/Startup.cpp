#include <Oszi.h>

class Startup : public Oszi::Application
{
public:
	Startup() {

	}
	~Startup() {

	}
};

Oszi::Application* Oszi::CreateApplication() {
	return new Startup();
}