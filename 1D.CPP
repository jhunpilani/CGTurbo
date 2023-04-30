#include <iostream>
//#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <graphics.h>

using namespace std;

void dda(int x1, int y1, int x2, int y2)
{
	int dx, dy, steps, x_inc, y_inc;
	dx = float(x2 - x1);
	dy = float(y2 - y1);
	if (abs(dx) >= abs(dy))
	{
		steps = abs(dx);
	}
	else
	{
		steps = abs(dy);
	}
	x_inc = dx / steps;
	y_inc = dy / steps;
	for (int i = 0; i <= steps; i++)
	{
		putpixel(x1, y1, WHITE);
		x1 = x1 + x_inc;
		y1 = y1 + y_inc;
	}
}

int main()
{
	int gd = DETECT, gm, i;
	initgraph(&gd, &gm, NULL);
	dda(20, 20, 80, 80);
	getch();
	return 0;
}
