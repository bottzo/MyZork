#include "App.h"
#include "Input.h"
#include "World.h"

App::App() {
	modules[0] = new Input();
	modules[1] = new World((Input*)modules[0]); //World??
}

App::~App(){
	for (int i = 0; i < NUM_MODULES; ++i)
		delete modules[i];
}

bool App::Init()
{
	for (int i = 0; i < NUM_MODULES; ++i)
		if (!modules[i]->Init())
			return false;
	return true;
}

bool App::Update()
{
	for (int i = 0; i < NUM_MODULES; ++i)
		if (!modules[i]->Update())
			return false;
	return true;
}