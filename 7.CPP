#include <iostream.h>
#include <stdio.h>
#include <math.h>
#include <graphics.h>
#include <stdlib.h>
#include <dos.h>
#include <conio.h>

int gd = DETECT, gm;
double x_, x, y_, y;

void draw_cube(double edge[20][3])
{
    initgraph(&gd, &gm, NULL);
    int i;

    for (i = 0; i < 19; i++)
    {
        x_ = edge[i][0] + edge[i][2] * (cos(2.3562));
        y_ = edge[i][1] - edge[i][2] * (sin(2.3562));
        x = edge[i + 1][0] + edge[i + 1][2] * (cos(2.3562));
        y = edge[i + 1][1] - edge[i + 1][2] * (sin(2.3562));
        line(x_ + 320, 240 - y_, x + 320, 240 - y);
    }
    line(320, 240, 320, 25);
    line(320, 240, 550, 240);
    line(320, 240, 150, 410);
    getch();
    closegraph();
}

void scale(double edge[20][3])
{
    double a, b, c;
    int i;
    cout << "Enter The Scaling Factors (a, b, c) in order :";
    cin >> a >> b >> c;
    initgraph(&gd, &gm, NULL);

    for (i = 0; i < 20; i++)
    {
        edge[i][0] = edge[i][0] * a;
        edge[i][1] = edge[i][1] * b;
        edge[i][2] = edge[i][2] * c;
    }
    draw_cube(edge);
    closegraph();
}

void translate(double edge[20][3])
{
    int a, b, c;
    int i;
    cout << "Enter The Translation Factors\n";
    cin >> a >> b >> c;
    initgraph(&gd, &gm, NULL);
    for (i = 0; i < 20; i++)
    {
        edge[i][0] += a;
        edge[i][0] += b;
        edge[i][0] += c;
    }
    draw_cube(edge);
    closegraph();
}

void rotate(double edge[20][3])
{
    int ch;
    int i;
    double temp, theta, temp1;

    cout << "-=[ Rotation About ]=-\n";
    cout << "1:==> X-Axis \n";
    cout << "2:==> Y-Axis\n";
    cout << "3:==> Z-Axis \n";
    cout << "Enter Your Choice :=";
    cin >> ch;
    switch (ch)
    {
    case 1:
	cout << " Enter The Angle :=";
	cin >> theta;
        theta = (theta * 3.14) / 180;
        for (i = 0; i < 20; i++)
        {
            edge[i][0] = edge[i][0];
            temp = edge[i][1];
            temp1 = edge[i][2];
            edge[i][1] = temp * cos(theta) - temp1 * sin(theta);
            edge[i][2] = temp * sin(theta) + temp1 * cos(theta);
        }
        draw_cube(edge);
        break;

    case 2:
	cout << " Enter The Angle :=";
	cin >> theta;
	theta = (theta * 3.14) / 180;
	for (i = 0; i < 20; i++)
	{
	    edge[i][1] = edge[i][1];
	    temp = edge[i][0];
	    temp1 = edge[i][2];
	    edge[i][0] = temp * cos(theta) + temp1 * sin(theta);
	    edge[i][2] = -temp * sin(theta) + temp1 * cos(theta);
	}
	draw_cube(edge);
	break;

    case 3:
	cout << " Enter The Angle :=";
	cin >> theta;
	theta = (theta * 3.14) / 180;
	for (i = 0; i < 20; i++)
	{
	    edge[i][2] = edge[i][2];
	    temp = edge[i][0];
	    temp1 = edge[i][1];
	    edge[i][0] = temp * cos(theta) - temp1 * sin(theta);
	    edge[i][1] = temp * sin(theta) + temp1 * cos(theta);
	}
	draw_cube(edge);
	break;
    }
}

void reflect(double edge[20][3])
{
    int ch;
    int i;

    cout << "-=[ Reflection About ]=-\n";
    cout << "1:==> X-Axis\n";
    cout << "2:==> Y-Axis \n";
    cout << "3:==> Z-Axis \n";
    cout << " Enter Your Choice :=";
    cin >> ch;
    switch (ch)
    {
    case 1:
	for (i = 0; i < 20; i++)
	{
	    edge[i][0] = edge[i][0];
	    edge[i][1] = -edge[i][1];
	    edge[i][2] = -edge[i][2];
	}
	draw_cube(edge);
	break;

    case 2:
	for (i = 0; i < 20; i++)
	{
	    edge[i][1] = edge[i][1];
	    edge[i][0] = -edge[i][0];
	    edge[i][2] = -edge[i][2];
	}
	draw_cube(edge);
	break;

    case 3:
	for (i = 0; i < 20; i++)
	{
	    edge[i][2] = edge[i][2];
	    edge[i][0] = -edge[i][0];
	    edge[i][1] = -edge[i][1];
	}
	draw_cube(edge);
	break;
    }
}

void perspect(double edge[20][3])
{
    int ch;
    int i;
    double p, q, r;

    cout << "-=[ Perspective Projection About ]=-\n";
    cout << "1:==> X-Axis \n";
    cout << "2:==> Y-Axis \n";
    cout << "3:==> Z-Axis\n";
    cout << " Enter Your Choice :=";
    cin >> ch;
    switch (ch)
    {
    case 1:
	cout << " Enter P :=";
	cin >> p;
	for (i = 0; i < 20; i++)
	{
	    edge[i][0] = edge[i][0] / (p * edge[i][0] + 1);
	    edge[i][1] = edge[i][1] / (p * edge[i][0] + 1);
	    edge[i][2] = edge[i][2] / (p * edge[i][0] + 1);
	}
	draw_cube(edge);
	break;

    case 2:
	cout << " Enter Q :=";
	cin >> q;
	for (i = 0; i < 20; i++)
	{
	    edge[i][1] = edge[i][1] / (edge[i][1] * q + 1);
	    edge[i][0] = edge[i][0] / (edge[i][1] * q + 1);
	    edge[i][2] = edge[i][2] / (edge[i][1] * q + 1);
	}
	draw_cube(edge);
	break;

    case 3:
	cout << " Enter R :=";
	cin >> r;
	for (i = 0; i < 20; i++)
	{
	    edge[i][2] = edge[i][2] / (edge[i][2] * r + 1);
	    edge[i][0] = edge[i][0] / (edge[i][2] * r + 1);
	    edge[i][1] = edge[i][1] / (edge[i][2] * r + 1);
	}
	draw_cube(edge);
	break;
    }
    closegraph();
}

int main()
{
    int choice;
    double edge[20][3] = {
	100, 0, 0,
	100, 100, 0,
	0, 100, 0,
	0, 100, 100,
        0, 0, 100,
        0, 0, 0,
        100, 0, 0,
        100, 0, 100,
        100, 75, 100,
        75, 100, 100,
        100, 100, 75,
        100, 100, 0,
        100, 100, 75,
        100, 75, 100,
        75, 100, 100,
        0, 100, 100,
        0, 100, 0,
        0, 0, 0,
        0, 0, 100,
        100, 0, 100};
    while (1)
    {
	cout << "1:==> Draw Cube \n";
	cout << "2:==> Scaling \n";
	cout << "3:==> Rotation \n";
	cout << "4:==> Reflection \n";
	cout << "5:==> Translation \n";
	cout << "6:==> Perspective Projection \n";
	cout << "7:==> Exit \n";
	cout << " Enter Your Choice :=\n";
	cin >> choice;
	switch (choice)
	{
	case 1:
	    draw_cube(edge);
	    break;

	case 2:
	    scale(edge);
	    break;

	case 3:
	    rotate(edge);
	    break;

        case 4:
            reflect(edge);
            break;

        case 5:
            translate(edge);
            break;

        case 6:
            perspect(edge);
            break;

        case 7:
            exit(0);

        default:
	    cout << " Press A Valid Key...!!! ";
            getch();
            break;
        }
        closegraph();
    }
}
