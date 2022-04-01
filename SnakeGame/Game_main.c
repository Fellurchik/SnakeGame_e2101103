#include "Snake.h"
#include "Screen.h"
#include <windows.h>

int main(void)
{
#ifdef WINDOWS
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD mode = 0;
	GetConsoleMode(h, &mode);
	mode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
	SetConsoleMode(h, mode);
#endif

	struct snake s = init_snake(STARTLINE);
	spawn_food(s);
	while (MAXLINE>s.length)
	{
		draw(s);
		int k = input_key();
		s = move(s, k);
	}
	you_win();
}