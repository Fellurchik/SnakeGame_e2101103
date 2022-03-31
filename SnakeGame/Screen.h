#pragma once

//Constant defenitions
enum COLORS { BLACK = 30, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE };

//Function declarations
void clearScreen(void);  //(clear screen functions)
void goTo(int x, int y);

void resetColors(void);			//(colors functions)
void setForeground(int color);
void setBackground(int color);