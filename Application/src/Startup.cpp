#include <Oszi.h>

class Startup : public Oszi::Application
{
public:
	Startup() {

	}
	~Startup() {

	}
};

int main() {
	Startup* program = new Startup();
	program->Run();
	delete program;
	return 0;
}