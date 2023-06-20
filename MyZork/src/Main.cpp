#include "App.h"
#include <iostream>
#include <stdlib.h>

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
	std::cout << "Thanks for playing\n";
	system("pause");
	return 0;
}