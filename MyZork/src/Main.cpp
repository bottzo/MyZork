#include "App.h"

int main()
{
	App app;
	if (!app.Init())
		return 0;
	//TODO: Error LOG system
	while (true) {
		if (!app.Update())
			break;
	}
	return 0;
}