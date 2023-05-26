#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN sizeof(NODE)
// #define  DOit "D:\\what the\\Mywork\\student.txt"
#define DOit "../../Data/student.txt"

struct Student
{
    long long num;
    char name[10];
    int age;
    char Gender[10];
    int birthday[3];
    char address[15];
    char t_number[12];
    char E_mail[20];
    // struct Student *next;
};

typedef struct Node
{
    struct Student stu;
    struct Node *pNext;
} NODE, *PNODE;

NODE *head = NULL;
int number;

void InputData(PNODE head);      // 输入学生信息
void InsertStudent(PNODE pHead); // 插入学生信息
void NumberSort(PNODE head);     // 按学号从大到小对数据进行排序
void DisplayNode(PNODE head);    // 遍历链表 显示学生信息
void DeleteNodeID();             // 输入学号删除
void DeleteNodeName();           // 输入姓名删除
void ModifyNodeID();             // 输入学号修改
void ModifyNodeName();           // 输入姓名修改
void DeleteMemory(PNODE head);   // 删除链表所占用的内存；
void FileSave(PNODE head);       // 保存数据
void FileOpen();                 // 打开数据
void studentIDFind();            // 按学号查找学生
void studentNameFind();          // 按姓名查找学生;
void Menu();                     // 功能菜单
void ChoiceMenu();               // 功能菜单选择
void HZ();                       // 格式化
// void CreatingNode();
// struct Student *CreatNode();

