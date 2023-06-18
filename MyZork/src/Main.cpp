#include "App.h"

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
	return 0;
}