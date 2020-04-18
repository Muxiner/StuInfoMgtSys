#include <iostream>
#include <stdlib.h>
using namespace std;

//显示平面上的点的结构体
struct Point
{
	int x;//横坐标
	int y;//纵坐标
};

//显示主菜单
void displayMenu()
{
	cout << "************************************" << "\n";
	cout << "1.Circle(圆)\n2.Rectangle(长方形)\n3.Exit(退出)\n";
	cout << "************************************" << endl;
	cout << "Please select the shape:";
}

//得到用户数入的两个点
void getTwoPoints(struct Point *startP, struct Point *endP)
{
	cout << "Please input the coordinate (X, Y) of the start point:";
	cin >> startP->x >> startP->y;
	cout << "Please input the coordinate (X, Y) of the end point:";
	cin >> endP->x >> endP->y;
}

//以（X，Y）的形式打印点
void printPoint(struct Point *p)
{
    //(X,Y)
    cout << "(" << p->x << ", " << p->y << ")";
}

//画圆的函数
void drawCircle(struct Point *startP, struct Point *endP)
{
	int Width, Length;
    Width = endP->x - startP->x;
    Length = endP->y - startP->y;
    if (Length != Width)
    {
        cout << "No a circle, Select again\n";
    } else
    {
        //模拟画圆
        cout << "Draw a circle at center ";
        //圆心坐标
        cout << "(" << (startP->x + endP->x)/2 << ", " << (startP->y + endP->y)/2 << ")";
        cout << " with radius ";
        //半径长度
        cout << Width / 2 << endl;
    }
}

//画长方形的函数
void drawRectangle(struct Point *startP, struct Point *endP)
{
	int Width, Length;

    if ((endP->x - startP->x) <= 0 || (endP->y - startP->y) <= 0)
    {
        cout << "No a rectangle, Please select again\n";
    }
    else 
    {
    Width = endP->x - startP->x;
    Length = endP->y - startP->y;

    //模拟画长方形
    cout << "Draw a rectangle at top left ";
    printPoint(startP);
    cout << " whose width is "<< Width << " and height is " << Length << endl;
    }
}

int main()
{
	int choice = 1;//用户选择

	struct Point startP, endP;//起点和终点

	while (choice != 0)
	{
		displayMenu(); //显示主菜单
		cin >> choice; //接受用户输入

		switch (choice)
		{
		case 1://圆
			getTwoPoints(&startP, &endP);//得到两个点
			drawCircle(&startP, &endP);  //接受用户输入
			break;
		case 2://长方形
			getTwoPoints(&startP, &endP);
			drawRectangle(&startP, &endP);
			break;
		case 0:
			cout << "Good Bye!\n";
			break;
		default:
			cout << "Not supported! Please select again!";
			break;
		}
	}
	system("pause");
	return 0;
}