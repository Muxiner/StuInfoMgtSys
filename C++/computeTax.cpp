#include <iostream>
#include <stdlib.h>
using namespace std;

struct taxRule
{
  int mThreshold; //纳税钱
  int rTax;       //税率
};

struct taxRule *taxRules;
int ruleNum = 0;

//根据用户输入的规则条数，从键盘得到所有的规则，存放到数组
void inputRules(int n)
{
  cout << "请输入规则得条数:";
  cin >> ruleNum;

  taxRules = new struct taxRule[ruleNum];

  for (int i = 0; i < ruleNum; i++)
  {
    cout << "请输入第" << i + 1 << "条规则：";
    cin >> taxRules[i].mThreshold >> taxRules[i].rTax;
  }
}

//显示规则
void displayRules()
{
  cout << "\n纳税规则如下：\n";
  cout << "纳税钱\t税率\n";
  for (int i = 0; i < ruleNum; i++)
  {
    cout << taxRules[i].mThreshold << "\t" << taxRules[i].rTax << "\n";
  }
}

//参数income表示个人所得税，计算个人所得税
double computeTax(int income)
{
  double sum = 0;
  int i = 0;

  if (taxRules[0].mThreshold > income)
    return 0;

  for (i = 1; i < ruleNum && taxRules[i].mThreshold <= income; i++)
  {
    sum += (taxRules[i].mThreshold - taxRules[i - 1].mThreshold) * taxRules[i - 1].rTax;
  }

  sum += (income - taxRules[i - 1].mThreshold ) * taxRules[i - 1].rTax;
  return sum / 100;
}

int main()
{
  inputRules(ruleNum);

  displayRules();

  int income;

  while (income > -1)
  {
    cout << "\n请输入您的收入：";
    cin >> income;
    if (income == -1)
    {
      cout << "再见。" << endl;
      break;
    }
    cout << "您的收入是：" << income << ", "
         << "应缴所得税：" << computeTax(income) << "元。" << endl;
  }
  system("pause");
  return 0;
}
