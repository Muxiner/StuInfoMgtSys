#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

#define UP 6
#define DOWN 4
#define STOP 5

int main()
{
	int Seconds, N, Floor;
	Seconds = 0;
	int i;
	int j;//前一个楼层数
	j = 0;

	//printf("需要前往的楼层数及其序列：\n");
	//scanf_s("%d", &N);

	cout << "需要前往的楼层数及其序列："<< endl;
	cin >> N;

	for (i = 0; i < N; i++)
	{
		//scanf_s("%d", &Floor);
		cin >> Floor;
		if (Floor > j)
			Seconds = Seconds + (Floor - j) * UP + STOP;
		else if (Floor < j)
			Seconds = Seconds + (j - Floor) * DOWN + STOP;
		j = Floor;
	}
	//printf("电梯停靠完这条序列的楼层花费的总时间：\n%d\n", Seconds);
	cout << "电梯停靠完这条序列的楼层花费的总时间："<< endl << Seconds << endl;
	getchar();
	return 0;
}