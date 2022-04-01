#include "Snake.h"
#include "Screen.h"
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

int foodX = 0;
int foodY = 0;
int lastdir=RIGHT;
int wait=0;

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

	if (ns.head.x <= 0 || ns.head.x >= 120) { death(ns.length); }
	else if (ns.head.y <= 0 || ns.head.y > 30) { death(ns.length); }

	alive(ns);

	if (ns.head.x == foodX && ns.head.y == foodY)
	{
		ns.length++;
		spawn_food(ns);
		draw(ns);
	};

	return ns;
}

int input_key(void)
{
	while (1)
	{
		int k = _getch_nolock();
		if (k == 224)
		{
			k = _getch_nolock();
			if (k == UP || k == LEFT || k == RIGHT || k == DOWN)
			{
				return k;
				wait = 0;
			};
		};
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

	setBackground(GREEN);
	goTo(foodX, foodY);
	printf(" ");

	resetColors();
}

void death(int n)
{
	init_snake(0);
	clearScreen();
	goTo(40, 13);
	setForeground(MAGENTA);
	printf("You dead :)\n");
	goTo(38, 14);
	printf("Your score is %d\n\n", n);
	resetColors();
	system("pause");
	exit(EXIT_SUCCESS);
}

struct snake alive(struct snake ns)
{
	for (int i = 0; i < ns.length; i++)
	{
		if ((ns.body[i].x == ns.head.x) && (ns.body[i].y == ns.head.y)) { death(ns.length); };
	};
}

struct snake spawn_food(struct snake s)
{
	int temp = 0;
	int randX = 0;
	int randY = 0;

	while (temp != 1)
	{
		randX = rand() % 120 + 1;
		randY = rand() % 29 + 1;
		for (int i = 0; i < s.length; i++)
		{
			if ((s.body[i].x == randX) && (s.body[i].y == randY)) { temp = 0; }
			else if ((s.head.x == randX) && (s.head.y == randY)) { temp = 0; }
			else { temp = 1; };
		};
	};

	foodX = randX;
	foodY = randY;

}


void you_win(void)
{
	init_snake(0);
	clearScreen();
	goTo(40, 13);
	setForeground(MAGENTA);
	printf("You WIN! :)\n");
	goTo(38, 14);
	printf("Your score is %d\n\n", MAXLINE);
	resetColors();
	system("pause");
	exit(EXIT_SUCCESS);
}