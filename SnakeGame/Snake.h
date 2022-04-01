#pragma once

//Constant defenitions
#define MAXLINE 12  //(max length of tail of snake)
#define STARTLINE 10 //(start length of tail of snake)
#define WINDOWS

enum INITCORDS { INITCOL = 40, INITROW=13 };
enum ARROW{UP=72, LEFT=75, RIGHT=77, DOWN=80};

//Srtructure definitions
struct cords
{
	int x;
	int	y;
};

struct snake
{
	int length;
	struct cords head;
	struct cords body[MAXLINE];
};


//Function declarations
struct snake init_snake(int len);
void draw(struct snake s);
int input_key(void);
struct snake move(struct snake s, int dir);

void death(int n);
struct snake alive(struct snake s);
void you_win(void);

struct snake spawn_food(struct snake s);