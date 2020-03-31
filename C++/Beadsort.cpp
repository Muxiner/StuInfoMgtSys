#include <iostream>
#include <stdlib.h>
#include <time.h>
#define COL 5
#define COW 5
using namespace std;

int CBead[5], CbBead[5], Bmap[COL][COW] = { 0 }, bmap[COW][COL] = { 0 };

void CreatBead()
{
	for (int i = 0; i < 5; i++)
		CBead[i] = rand() % 5;

	for (int i = 0; i < COL; i++)
		for (int j = 0; j < CBead[i]; j++)
			Bmap[i][j] = 1;

	for (int i = 0; i < COL; i++)
		for (int j = 0; j < COW; j++)
			bmap[i][j] = Bmap[j][i];
}

void displayBead()
{
	cout << "原始数组:\n";
	for (int i = 0; i < 5; i++)
		cout << CBead[i] << " ";
	cout << endl;
	cout << "算珠掉落前：\n";
	for (int i = 0; i < COL; i++)
		for (int j = 0; j < COW; j++)
		{
			cout << Bmap[i][j] << "   ";
			if ((j + 1) % 5 == 0)
				cout << "\n\n";
		}
	cout << "算珠掉落后：\n";
	for (int i = 0; i < COL; i++)
		for (int j = 0; j < COW; j++)
		{
			cout << bmap[i][j] << "   ";
			if ((j + 1) % 5 == 0)
				cout << "\n\n";
		}
	cout << "升序数组：\n";
	for (int i = 0; i < 5; i++)
		cout << CbBead[i] << " ";
	cout << endl;
}

void BeadDroped()
{
	int t, count;
	int bMap[COW][COL] = { 0 };
	for (int i = 0; i < 5; i++)
	{
		t = 4;
		count = 0;
		while (t >= 0)
		{
			if (bmap[i][t] == 1)
				count++;
			t--;
		}
		for (int j = 0; j < count; j++)
			bMap[j][i] = 1;
	}
	for (int i = 0; i < COL; i++)
		for (int j = 0; j < COW; j++)
			bmap[i][j] = bMap[COW - 1 - i][j];

	for (int i = 0; i < 5; i++)
	{
		t = 4;
		count = 0;
		while (t >= 0)
		{
			if (bmap[i][t] == 1)
				count++;
			t--;
		}
	
		CbBead[i] = count;
	}
}
 
int main()
{
	srand(time(NULL));
	CreatBead();
	BeadDroped();
	displayBead();
	system("pause");
	return 0;
}