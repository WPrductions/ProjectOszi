#pragma once

#ifdef OZ_PLATFORM_WINDOWS

extern Oszi::Application* Oszi::CreateApplication();

int main(void) {

	Oszi::Log::Init();
	int a = 5;

	OZ_INFO("Hello");
	OZ_ERROR("Yeet {0}", a);

	Oszi::Application* program = Oszi::CreateApplication();
	program->Run();
	delete program;
	return 0;
}

#endif 