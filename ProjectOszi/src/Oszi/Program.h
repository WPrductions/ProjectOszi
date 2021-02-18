#pragma once

#ifdef OZ_PLATFORM_WINDOWS

extern Oszi::Application* Oszi::CreateApplication();

int main(void) {
	Oszi::Application* program = Oszi::CreateApplication();
	program->Run();
	delete program;
	return 0;
}
#endif 
