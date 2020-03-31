#include <iostream>
#include <iomanip>
#include <stdlib.h>
using namespace std;

//输入n个温度
void inputTemps(int temp[], int n);
//显示柱状图
void displayTemps(int temp[], int n);
//显示月间温度中所有的峰值
void displayPeaks(int temp[], int n);
//显示约见持续最久的温度
void displayFlat(int temp[], int n);
//显示出现次数最多的温度及次数
void displayTempsTime(int temp[], int n);
//找出温度的最小值
int MinTemp(int temp[], int n);
void Pause(void);

//主函数
int main()
{
	int temps[30];

	inputTemps(temps, 30);//输入n个温度
	displayTemps(temps, 30);//显示柱状图
	Pause();
	displayPeaks(temps, 30);//显示月间温度中所有的峰值
	Pause();
	displayFlat(temps, 30);//显示约见持续最久的温度
	Pause();
	displayTempsTime(temps, 30);//显示出现次数最多的温度及次数
	Pause();
	return 0;
}

//输入n个温度
void inputTemps(int temp[], int n)
{
	cout << "Please input the tempratures:" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> temp[i];
	}
}

//显示柱状图
void displayTemps(int temp[], int n)
{
	int Min = MinTemp(temp, n);
	cout << "显示柱状图\n";
	for (int i = 0; i < n; i++)
	{
		//cout << i + 1 << '\t';
		if (Min < 0)
		{
			cout << setw(4) << i + 1 << " ";
			if (temp[i] < 0)
			{
				for (int j = 0; j < temp[i] - Min; j++)
					cout << " ";
				for (int k = temp[i]; k < 0; k++)
					cout << "*";
				cout << "|" << endl;
			}
			else
			{
				for (int j = Min; j < 0; j++)
					cout << " ";
				cout << "|";
				for (int k = 0; k < temp[i]; k++)
					cout << "*";
				cout << endl;
			}
		}
		else
		{
			int j = 1;
			cout << i + 1 << " \t";
			while (j <= temp[i])
			{
				cout << "*";
				j++;
			}
			cout << '\n';
		}
	}
}

//显示月间温度中所有的峰值
void displayPeaks(int temp[], int n)
{
	int i;
	cout << "显示峰值如下：\n";
	for (i = 1; i < n - 1; i++)
	{
		if ((temp[i] > temp[i - 1]) && (temp[i] > temp[i + 1]))
			cout << "Max at day " << i + 1 << " is " << temp[i] << endl;
	}
}

//显示约见持续最久的温度
void displayFlat(int temp[], int n)
{
	int flat = 1, Flat = 0;
	bool T;

	for (int i = 0; i < n - 1; i++)
	{
		T = false;
		if (temp[i] == temp[i + 1])
		{
			flat += 1;
			T = true;
		}
		else
		{
			flat = 1;
			T = false;
		}

		
			if (flat > Flat && T == true)
				Flat = flat;
		
	}
	cout << "显示崮的长度如下：\n" << "The length of longest flat is " << Flat << endl;
}

//显示出现次数最多的温度及次数
void displayTempsTime(int temp[], int n)
{
	int i, j, max = 0;
	int times, Times;
	Times = 0;
	for (i = 0; i < n; i++)
	{
		times = 0;
		for (j = 0; j < n; j++)
		{
			if (temp[i] == temp[j])
				times++;
		}
		if (times > Times)
		{
			Times = times;
			max = i;
		}
	}
	cout << "出现次数最多的温度 " << temp[max] <<" 次数 "    << Times << endl;
}

//找出温度最小值
int MinTemp(int temp[], int n)
{
	int Min = temp[0];
	for (int i = 1; i < n; i++)
	{
		if (temp[i] < Min)
			Min = temp[i];
	}
	return Min;
}

void Pause(void)
{
	cout << endl;
	system("pause");
}