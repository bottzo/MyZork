#include <conio.h>
#include "Globals.h"
#include "Input.h"

Input::Input(): Module() {}

Input::~Input(){}

bool Input::Update()
{
	if (_kbhit() != 0)
	{
		auto key = _getch();
		OutputConsole("Key ");
		OutputConsole(key);
		OutputConsole(" pressed\n");
	}
	return true;
}