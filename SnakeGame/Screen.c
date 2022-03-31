#include "Screen.h"
#include <stdio.h>

void goTo(int x, int y)
{
    printf("\033[%d;%dH", y, x);
    fflush(stdout);
}


void clearScreen(void)
{
    printf("\033[J");
    printf("\033[1J");
    fflush(stdout);
}


void resetColors(void)
{
    printf("\033[0m");
    fflush(stdout);
}


void setForeground(int color)
{
    printf("\033[%dm", color);
    fflush(stdout);
}


void setBackground(int color)
{
    printf("\033[%dm", color + 10);
    fflush(stdout);
}



