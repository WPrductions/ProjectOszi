#include <Oszi.h>
#include <stdio.h>

class Startup
{
public:
	Startup() {

	}
	~Startup() {

	}
};

int main() {
	Startup* program = new Startup();
	/*program->Run();*/
	delete program;
	printf("R");
	return 0;
}