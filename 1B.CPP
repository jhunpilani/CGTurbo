#include <iostream.h>
#include <graphics.h>
#include <conio.h>
// #include <stdlib.h>
// #include <stdio.h>

void Bresenham(int x1, int y1, int x2, int y2)
{
    int x = x1;
    int y = y1;
    int dx = x2 - x1;
    int dy = y2 - y1;

    // initial decision variable
    int p = 2 * dy - dx;
    // putpixel(x,y,WHITE);
    while (x <= x2)
    {
        putpixel(x, y, WHITE);
        x++;
        if (p < 0)
        {
            p = p + 2 * dy;
        }
        else
        {
            p = p + 2 * dy - dx;
            y++;
        }
    }
}
int main()
{
    int gd = DETECT, gm, i;
    initgraph(&gd, &gm, NULL);
    Bresenham(0, 0, 200, 400);
    getch();
    return 0;
}