#include "Snake.h"
#include "Screen.h"

int main(void)
{
	struct snake s = init_snake(10);
	while (1)
	{
		draw(s);
		int k = input_key();
		s = move(s, k);
	}
}