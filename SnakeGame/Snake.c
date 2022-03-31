#include "Snake.h"
#include "Screen.h"
#include <conio.h>
#include <stdio.h>

struct snake move(struct snake s, int dir)
{
	struct snake ns;
	ns.length = s.length;
	ns.head = s.head;
	if (dir == UP)
		{ ns.head.y--; }
	else if (dir == DOWN)
		{ ns.head.y++; }
	else if (dir == LEFT)
		{ ns.head.x--; }
	else { ns.head.x++; }
	ns.body[0] = s.head;
	for (int i = 1; i < s.length; i++)
		{ns.body[i] = s.body[i - 1];};

	if (ns.head.x <= 0 || ns.head.x >= 120) { death(); }
	else if (ns.head.y <= 0 || ns.head.y > 30) { death(); }

	return ns;
}

int input_key(void)
{
	while (1)
	{
		int k = _getch();
		if (k == 224)
		{
			k = _getch();
			if (k==UP || k==LEFT || k==RIGHT || k==DOWN)
				{return k;}
		}
	};
}

struct snake init_snake(int len)
{
	struct snake s;
	s.length = len;
	s.head.x = INITCOL;
	s.head.y = INITROW;
	for (int i = 0; i < len; i++)
	{
		s.body[i].x = INITCOL - 1 - i;
		s.body[i].y = INITROW;
	}
	return s;
}

void draw(struct snake s)
{
	clearScreen();
	setBackground(RED);
	goTo(s.head.x, s.head.y);
	printf(" ");
	setBackground(YELLOW);
	for (int i = 0; i < s.length; i++)
	{
		goTo(s.body[i].x, s.body[i].y);
		printf(" ");
	}
	resetColors();
}

void death()
{
	init_snake(0);
	clearScreen();
	goTo(40, 13);
	setForeground(MAGENTA);
	printf("You dead :)\n\n\n");
	resetColors();
	exit();
}