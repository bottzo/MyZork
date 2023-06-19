#include "App.h"
#include <iostream>

int main()
{
	//TODO: Error LOG system

	App app;
	if (!app.Init())
		return 0;
	while (true) {
		if (!app.Update())
			break;
	}
	std::cout << "Thanks for playing";
	return 0;
}