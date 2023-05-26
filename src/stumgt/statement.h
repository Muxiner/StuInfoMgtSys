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

void InputData(PNODE head);      // ����ѧ����Ϣ
void InsertStudent(PNODE pHead); // ����ѧ����Ϣ
void NumberSort(PNODE head);     // ��ѧ�ŴӴ�С�����ݽ�������
void DisplayNode(PNODE head);    // �������� ��ʾѧ����Ϣ
void DeleteNodeID();             // ����ѧ��ɾ��
void DeleteNodeName();           // ��������ɾ��
void ModifyNodeID();             // ����ѧ���޸�
void ModifyNodeName();           // ���������޸�
void DeleteMemory(PNODE head);   // ɾ��������ռ�õ��ڴ棻
void FileSave(PNODE head);       // ��������
void FileOpen();                 // ������
void studentIDFind();            // ��ѧ�Ų���ѧ��
void studentNameFind();          // ����������ѧ��;
void Menu();                     // ���ܲ˵�
void ChoiceMenu();               // ���ܲ˵�ѡ��
void HZ();                       // ��ʽ��
// void CreatingNode();
// struct Student *CreatNode();

