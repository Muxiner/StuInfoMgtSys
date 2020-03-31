#include<iostream>
using namespace std;
int fun(int a)   //定义函数求数字根
{
	if (a < 10)
		return a;
	int t = 0;
	while (a)
	{
		t += a % 10;
		a /= 10;
	}
	return fun(t);

}
int main()
{
	int i, j, t = 0, m, n = 1;
	int a;
	int b;    //所输入图形数字根

	cout << "   |";
	for (m = 1; m <= 9; m++)
		cout<< " " << m << " ";

	cout << endl;
	cout<< "---|---------------------------" << endl;

	for (i = 1; i <= 9; i++)
		for (j = 1; j <= 9; j++, t++)
		{
			a = i * j;

			if (t % 9 == 0)
			{
				cout << " " << n++ << " |";
			}
			cout << " " << fun(a) << " ";    //函数调用
			if (j == 9)
				cout << endl;                //换行，形成二维图
		}

	n = 1;
	t = 0;

	cout << endl;
	cout << "Please input a number:";
	cin >> b;
	cout << "   |";
	for (m = 1; m <= 9; m++)
		cout <<" "<< m << " ";
	cout << endl;


	for (i = 1; i <= 9; i++)
		for (j = 1; j <= 9; j++, t++)
		{
			a = i * j;

			if (t % 9 == 0)
			{
				cout << " " << n++ << " |";
			}
			if (b == fun(a))
				cout << " " << "*" << " ";
			if (b != fun(a)) {
				cout << "   ";
			}
			if (j == 9)
				cout << endl;

		}
	cout << endl;
	getchar();
	return 0;
}
