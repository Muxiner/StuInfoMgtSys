#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN sizeof(NODE)
//#define  DOit "D:\\what the\\Mywork\\student.txt"
#define  DOit "student.txt"

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
    //struct Student *next;
} ;

typedef struct Node
{
    struct Student stu;
    struct Node *pNext;
} NODE, *PNODE;

NODE *head = NULL;
int number;

void InputData(PNODE head);//输入学生信息
void InsertStudent(PNODE pHead);//插入学生信息
void NumberSort(PNODE head);//按学号从大到小对数据进行排序
void DisplayNode(PNODE head);//遍历链表 显示学生信息
void DeleteNodeID();//输入学号删除
void DeleteNodeName();//输入姓名删除
void ModifyNodeID();//输入学号修改
void ModifyNodeName();//输入姓名修改
void DeleteMemory(PNODE head);//删除链表所占用的内存；
void FileSave(PNODE head);//保存数据
void FileOpen();//打开数据
void studentIDFind();//按学号查找学生
void studentNameFind();//按姓名查找学生;
void Menu();//功能菜单
void ChoiceMenu();//功能菜单选择
void HZ();//格式化
//void CreatingNode();
//struct Student *CreatNode();


int main()
{
    system("color 03");
    FileOpen();
AA:
    Menu();
    ChoiceMenu();
    goto AA;
    return 0;
}

void ChoiceMenu()
{
    int choose;
    printf("请选择要进行的功能\n=>");
    scanf("%d", &choose);
    switch (choose)
    {
    case 1:
    {
        InputData(head);
        HZ();
        system("cls");
    }
    break;
    case 2:
    {
        DisplayNode(head);
        HZ();
        system("cls");
    }
    break;
    case 3:
    {
        NumberSort(head);
        FileSave(head);
        HZ();
        system("cls");
    }
    break;
    case 4:
    {
        studentIDFind();
        FileSave(head);
        HZ();
        system("cls");
    }
    break;
    case 5:
    {
        studentNameFind();
        FileSave(head);
        HZ();
        system("cls");
    }
    break;
    case 6:
    {
        ModifyNodeID();
        FileSave(head);
        HZ();
        system("cls");
    }
    break;
    case 7:
    {
        ModifyNodeName();
        FileSave(head);
        HZ();
        system("cls");
    }
    break;
    case 8:
    {
        DeleteNodeID();
        FileSave(head);
        HZ();
        system("cls");
    }
    break;
    case 9:
    {
        DeleteNodeName();
        FileSave(head);
        HZ();
        system("cls");
    }
    break;
    case 10:
    {
        FileOpen();
        HZ();
        system("cls");
    }
    break;
    case 11:
    {
        DeleteMemory(head);
        HZ();
        system("cls");
    }
    break;
    case 12:
    {
        InsertStudent(head);
        FileSave(head);
        HZ();
        system("cls");
    }
    break;
    case 0:
    {
        printf("欢迎您再次使用本系统\n");
        DeleteMemory(head);
        exit(0);
    }
    default:
    {
        printf("输入了错误的选项  请重新输入\n");
        break;
    }
    }
}

void HZ()//格式化
{
    printf("按回车返回菜单......");
    getchar();
    getchar();
}

void Menu()
{
    printf("\n");
    printf("\t\t|...........学生信息管理系统...........|\n");
    printf("\t\t|\t 1.输入学生信息                |\n");
    printf("\t\t|\t 2.浏览学生信息                |\n");
    printf("\t\t|\t 3.按学号排序                  |\n");
    printf("\t\t|\t 4.学号查找学生信息            |\n");
    printf("\t\t|\t 5.姓名查找学生信息            |\n");
    printf("\t\t|\t 6.修改学生成绩(按学号)信息    |\n");
    printf("\t\t|\t 7.修改学生成绩(按姓名)信息    |\n");
    printf("\t\t|\t 8.按学号删除学生成绩信息      |\n");
    printf("\t\t|\t 9.按姓名删除学生成绩信息      |\n");
    printf("\t\t|\t10.打开学生信息                |\n");
    printf("\t\t|\t11.清除节点信息                |\n");
    printf("\t\t|\t12.添加学生信息                |\n");
    printf("\t\t|\t 0.退出                        |\n");
    printf("\t\t|......................................|\n");
}

void InputData(PNODE head)
{
    head = (NODE *)malloc(LEN);
    if(NULL == head)
    {
        printf("内存分配失败,程序终止!\n");

        exit(0);
    }
    PNODE pTail = head;//定义一个指向头结点的指针
    pTail->pNext = NULL;//清空指针域
    NODE Stu;
    PNODE pNew = (PNODE)malloc(sizeof(NODE));
    if(NULL == pNew)
    {
        printf("内存分配失败,程序终止!\n");
        exit(0);
    }
    number = 0;
    printf("请输入学生的信息\n");
    printf("---------------------------学号为“0”结束输入-------------------------------------\n");
    while (Stu.stu.num != 0)
    {
        printf("\t学号=>");
        scanf("%ld", &Stu.stu.num);
        if (Stu.stu.num != 0)
        {
            number += 1;
            printf("=>请输入姓名，年龄，性别，出生年月，地址，电话，E-mail\n");
            printf("\t输入=>>");
            scanf("%s %d %s %d %d %d %s %s %s", Stu.stu.name, &Stu.stu.age, Stu.stu.Gender, &Stu.stu.birthday[0], &Stu.stu.birthday[1],
                  &Stu.stu.birthday[2], Stu.stu.address, Stu.stu.t_number, Stu.stu.E_mail);

            PNODE pNew = (PNODE)malloc(LEN);
            if(NULL == pNew)//判断内存是否为空
            {
                printf("内存分配失败,程序终止!\n");
                exit(0);
            }
            pNew->stu = Stu.stu;//初始化结点的数据域
            pTail->pNext = pNew;//将新结点挂到老结点后
            pNew->pNext = NULL;//清空新结点的指针域
            pTail = pNew;//将pTail移到新结点上
        }
    }
    printf("\n共输入%d个学生的信息\n", number);
    FileSave(head);
}

void NumberSort(PNODE head)
{
    PNODE p, q;//定义两个指针

    NODE temp;

    for(p = head->pNext; NULL != p; p = p->pNext)
    {
        for(q = p->pNext; NULL != q; q = q->pNext)
        {
            if(p->stu.num < q->stu.num)//当前一个学生的学号小于后一个学生学号时
            {
                temp.stu  = p->stu;//交换学生的位置
                p->stu =  q->stu;
                q->stu = temp.stu;
            }
        }
    }
    printf("\n排序已完成\n");
}

void DisplayNode(PNODE pHead)
{
    PNODE p = pHead->pNext;
    int i = 1;
    printf("\t\t\t   学号   姓名   年龄  性别    出生年月        地址     电话             E-mail\n");
    do{
        printf("\t学生信息(%02d):%10lld%10s %3d%7s %5d%3d%3d  %10s  %12s %20s\n", i++, p->stu.num, p->stu.name, p->stu.age, p->stu.Gender,
               p->stu.birthday[0], p->stu.birthday[1], p->stu.birthday[2], p->stu.address, p->stu.t_number, p->stu.E_mail);
        p = p->pNext;
    }while(p != NULL);

}

void InsertStudent(PNODE pHead)
{
    PNODE p = pHead;

    int i = 0;

    struct Student stu;//学生结构

    int pos;//插入结点的位置

    printf("请输入插入学生的位置:");
    scanf("%d",&pos);

    while(NULL != p && i<pos-1)
    {
        p = p->pNext;

        i++;
    }

    if(NULL == p || i>pos)
    {
        printf("插入结点的位置不存在!\n");

        return;
    }

    printf("\t学号=>");
    scanf("%lld", &stu.num);
    if (stu.num != 0)
    {
        number += 1;
        printf("=>请输入姓名，年龄，性别，出生年月，地址，电话，E-mail\n");
        printf("\t输入=>>");
        scanf("%s %d %s %d %d %d %s %s %s", stu.name, &stu.age, stu.Gender, &stu.birthday[0], &stu.birthday[1],
              &stu.birthday[2], stu.address, stu.t_number, stu.E_mail);
    }
    PNODE pNew = (PNODE)malloc(LEN);

    if(NULL == pNew)
    {
        printf("动态内存分配失败,程序终止!\n");

        exit(-1);
    }

    pNew->stu = stu;
    PNODE q = p->pNext;
    p->pNext = pNew;
    pNew->pNext = q;
}

void DeleteNodeID()
{
    NODE *p = head, *pr = head;
    //NODE Stu;
    long long studentID ;
    if (head == NULL)
    {
        printf("对不起，没有数据可以删除\n\n");
        return;
    }
    printf("------------------------------\n");
    printf("请输入你要删除的学生的学号:");
    scanf("%lld", &studentID);
    printf("------------------------------\n");
    while (studentID != p->stu.num && p->pNext != NULL)
    {
        pr = p;
        p = p->pNext;
    }
    if (studentID == p->stu.num)
    {
        printf("\t成功删除的学生的信息\n");
        printf("学号:        %lld\n", p->stu.num);
        printf("姓名:        %s\n",p->stu.name);
        printf("年龄:        %d\n", p->stu.age);
        printf("性别:        %s\n",p->stu.Gender);
        printf("出生日期:    %4d %02d %02d\n",p->stu.birthday[0], p->stu.birthday[1], p->stu.birthday[2]);
        printf("家庭地址:    %s\n",p->stu.address);
        printf("电话号码:    %s\n", p->stu.t_number);
        printf("邮箱：       %s\n", p->stu.E_mail);
        printf("\n");
        if (p == head)
            head = p->pNext;
        else
            pr->pNext = p->pNext;
        free(p);

    }
    else
        printf("你要查找的这个数据未找到\n");
    return;
}

void DeleteNodeName()
{
    NODE *p = head, *pr = head;
    char studentName[10];
    if (head == NULL)
    {
        printf("对不起，没有数据可以删除\n");
        return;
    }
    printf("------------------------------\n");
    printf("请输入你要删除的学生的姓名:");
    scanf("%s", studentName);
    printf("------------------------------\n");
    while (0 != strcmp(studentName, p->stu.name) && p->pNext != NULL)
    {
        pr = p;
        p = p->pNext;
    }
    if (strcmp(studentName, p->stu.name) == 0)
    {
        printf("\t成功删除的学生的信息\n");
        printf("学号:        %lld\n", p->stu.num);
        printf("姓名:        %s\n",p->stu.name);
        printf("年龄:        %d\n", p->stu.age);
        printf("性别:        %s\n",p->stu.Gender);
        printf("出生日期:    %4d %02d %02d\n",p->stu.birthday[0], p->stu.birthday[1], p->stu.birthday[2]);
        printf("家庭地址:    %s\n",p->stu.address);
        printf("电话号码:    %s\n", p->stu.t_number);
        printf("邮箱：       %s\n", p->stu.E_mail);
        printf("\n");
        if (p == head)
            head = p->pNext;
        else
            pr->pNext = p->pNext;
        free(p);
    }
    else
        printf("你要查找的这个数据未找到\n");
    return;
}

void studentIDFind()
{
    NODE *p = head;
    long long num = 0;
    if (head == NULL)
    {
        printf("没有数据查找\n");
        return;
    }
    printf("------------------------------\n");
    printf("请输入你要查找的学生的学号：");
    scanf("%lld", &num);
    printf("------------------------------\n");
    while (num != p->stu.num&&p->pNext != NULL)
    {
        p = p->pNext;
    }
    if (p->stu.num == num)
    {
        printf("学号:        %lld\n", p->stu.num);
        printf("姓名:        %s\n",p->stu.name);
        printf("年龄:        %d\n", p->stu.age);
        printf("性别:        %s\n",p->stu.Gender);
        printf("出生日期:    %4d %02d %02d\n",p->stu.birthday[0], p->stu.birthday[1], p->stu.birthday[2]);
        printf("家庭地址:    %s\n",p->stu.address);
        printf("电话号码:    %s\n", p->stu.t_number);
        printf("邮箱：       %s\n", p->stu.E_mail);
        printf("\n");
    }
    else
        printf("没有你要查找的数据\n");
    return;
}

void studentNameFind()
{
    NODE *p = head;
    char name[10] = "";
    if (head == NULL)
    {
        printf("没有数据查找\n");
        return;
    }
    printf("------------------------------\n");
    printf("请输入你要查找的学生的姓名：");
    scanf("%s", name);
    printf("------------------------------\n");
    while (0!=strcmp(name,p->stu.name)&&p->pNext != NULL)
    {
        p = p->pNext;
    }
    if (0 == strcmp(name,p->stu.name))
    {
        printf("学号:        %lld\n", p->stu.num);
        printf("姓名:        %s\n",p->stu.name);
        printf("年龄:        %d\n", p->stu.age);
        printf("性别:        %s\n",p->stu.Gender);
        printf("出生日期:    %4d %02d %02d\n",p->stu.birthday[0], p->stu.birthday[1], p->stu.birthday[2]);
        printf("家庭地址:    %s\n",p->stu.address);
        printf("电话号码:    %s\n", p->stu.t_number);
        printf("邮箱：       %s\n", p->stu.E_mail);
        printf("\n");
    }
    else
        printf("没有你要查找的数据\n");
    return;
}

void ModifyNodeID()//输入学号修改
{
    if (head == NULL)
    {
        printf("没有数据查找");
        return;
    }
    PNODE p = head->pNext;//定义一个指针用于遍历学生信息
    long long num;
    printf("------------------------------\n");
    printf("请输入你要查找的学生的学号：");
    scanf("%lld", &num);
    printf("------------------------------\n");

    while (NULL != p)
    {
        if (p->stu.num == num)
        {
            printf("修改前的学生信息!\n");
            printf("学号:        %lld\n", p->stu.num);
            printf("姓名:        %s\n",p->stu.name);
            printf("年龄:        %d\n", p->stu.age);
            printf("性别:        %s\n",p->stu.Gender);
            printf("出生日期:    %4d %02d %02d\n",p->stu.birthday[0], p->stu.birthday[1], p->stu.birthday[2]);
            printf("家庭地址:    %s\n",p->stu.address);
            printf("电话号码:    %s\n", p->stu.t_number);
            printf("邮箱：       %s\n", p->stu.E_mail);
            printf("\n");
            int choice;
            printf("请选择需要修改的信息\n0.所有信息\n1.学号\n2.姓名\n3.年龄\n4.性别\n5.出生年月\n6.家庭住址\n7.电话号码\n8.邮箱\n=>");
            scanf("%d", &choice);

            switch (choice)
            {
            case 0:
            {
                printf("请输入新的学生信息\n学号、姓名、年龄、性别、出生年月、家庭地址、电话号码、邮箱\n=>");
                scanf("%lld %s %d %s %d %d %d %s %s %s", &p->stu.num,p->stu.name, &p->stu.age, p->stu.Gender, &p->stu.birthday[0], &p->stu.birthday[1],
                      &p->stu.birthday[2], p->stu.address, p->stu.t_number, p->stu.E_mail);

            }
            break;
            case 1:
            {
                printf("请输入新的学生学号\n=>");
                scanf("%lld", &p->stu.num);

            }
            break;
            case 2:
            {
                printf("请输入新的学生姓名\n=>");
                scanf("%s", p->stu.name);

            }
            break;
            case 3:
            {
                printf("请输入新的学生年龄\n=>");
                scanf("%d", &p->stu.age);

            }
            break;
            case 4:
            {
                printf("请输入新的学生性别\n=>");
                scanf("%s", p->stu.Gender);

            }
            break;
            case 5:
            {
                printf("请输入新的学生出生年月\n=>");
                scanf("%d %d %d", &p->stu.birthday[0], &p->stu.birthday[1], &p->stu.birthday[2]);

            }
            break;
            case 6:
            {
                printf("请输入新的学生家庭地址\n=>");
                scanf("%s", p->stu.address);

            }
            break;
            case 7:
            {
                printf("请输入新的学生电话号码\n=>");
                scanf("%s", p->stu.t_number);

            }
            break;
            case 8:
            {
                printf("请输入新的学生邮箱\n=>");
                scanf("%s", p->stu.E_mail);

            }
            break;
            default:
            {
                printf("输入了不存在的序号\n退回菜单栏\n");

            }
            continue;
            }
            break;
        }
        else
            printf("没有你要删除的数据\n");
        p = p->pNext;
    }
}

void ModifyNodeName()//输入姓名修改
{
    char name[10] = "";
    if (head == NULL)
    {
        printf("没有数据查找");
        return;
    }
    PNODE p = head->pNext;//定义一个指针用于遍历学生信息
    printf("------------------------------\n");
    printf("请输入你要查找的学生的姓名：");
    scanf("%s", name);
    printf("------------------------------\n");

    while(NULL != p)
    {
        if(0 == strcmp(name, p->stu.name))
        {
            printf("修改前的学生信息!\n");
            printf("学号:        %lld\n", p->stu.num);
            printf("姓名:        %s\n",p->stu.name);
            printf("年龄:        %d\n", p->stu.age);
            printf("性别:        %s\n",p->stu.Gender);
            printf("出生日期:    %4d %02d %02d\n",p->stu.birthday[0], p->stu.birthday[1], p->stu.birthday[2]);
            printf("家庭地址:    %s\n",p->stu.address);
            printf("电话号码:    %s\n", p->stu.t_number);
            printf("邮箱：       %s\n", p->stu.E_mail);
            printf("\n");

            int choice;
            printf("请选择需要修改的信息\n0.所有信息\n1.学号\n2.姓名\n3.年龄\n4.性别\n5.出生年月\n6.家庭住址\n7.电话号码\n8.邮箱\n=>");
            scanf("%d", &choice);

            switch (choice)
            {
            case 0:
            {
                printf("请输入新的学生信息\n学号、姓名、年龄、性别、出生年月、家庭地址、电话号码、邮箱\n=>");
                scanf("%lld %s %d %s %d %d %d %s %s %s", &p->stu.num,p->stu.name, &p->stu.age, p->stu.Gender, &p->stu.birthday[0], &p->stu.birthday[1],
                      &p->stu.birthday[2], p->stu.address, p->stu.t_number, p->stu.E_mail);
            }
            break;
            case 1:
            {
                printf("请输入新的学生学号\n=>");
                scanf("%lld", &p->stu.num);

            }
            break;
            case 2:
            {
                printf("请输入新的学生姓名\n=>");
                scanf("%s", p->stu.name);

            }
            break;
            case 3:
            {
                printf("请输入新的学生年龄\n=>");
                scanf("%d", &p->stu.age);

            }
            break;
            case 4:
            {
                printf("请输入新的学生性别\n=>");
                scanf("%s", p->stu.Gender);

            }
            break;
            case 5:
            {
                printf("请输入新的学生出生年月\n=>");
                scanf("%d %d %d", &p->stu.birthday[0], &p->stu.birthday[1], &p->stu.birthday[2]);

            }
            break;
            case 6:
            {
                printf("请输入新的学生家庭地址\n=>");
                scanf("%s", p->stu.address);

            }
            break;
            case 7:
            {
                printf("请输入新的学生电话号码\n=>");
                scanf("%s", p->stu.t_number);

            }
            break;
            case 8:
            {
                printf("请输入新的学生邮箱\n=>");
                scanf("%s", p->stu.E_mail);

            }
            break;
            default:
            {
                printf("输入了不存在的序号\n退回菜单栏\n");

            }
            continue;
            }
            break;
        }
        else
            printf("没有你要删除的数据\n");
        p = p->pNext;
    }
}

void DeleteMemory(PNODE head)
{
    NODE *p = head, *pr = NULL;
    while (p != NULL)
    {
        pr = p;
        p = p->pNext;
        free(pr);
    }
}

void FileOpen()
{
    number = 0;

    NODE *p, *pr;
    p = (NODE *) malloc(sizeof(NODE));
    pr = p;

    FILE *fp;
    if ((fp = fopen(DOit, "r")) == NULL)
    {
        FILE *fp1;
        fp1 = fopen(DOit, "a+");
        fclose(fp1);
    }
    if (p == NULL)
    {
        printf("[初始化]节点创建失败");
        return;
    }
    else
    {
        head = NULL;
        if (fscanf(fp, "%lld %s %d %s %d %d %d %s %s %s", &p->stu.num, p->stu.name, &p->stu.age, p->stu.Gender, &p->stu.birthday[0], &p->stu.birthday[1], &p->stu.birthday[2], p->stu.address, p->stu.t_number, p->stu.E_mail)==EOF)
            return;
    }

    while(1)
    {
        number++;
        if (number == 1)
        {
            head = p;
            pr->pNext = NULL;
        }
        else
            pr->pNext = p;

        pr = p;
        p = (NODE *)malloc(sizeof(NODE));
        if (fscanf(fp, "%lld %s %d %s %d %d %d %s %s %s", &p->stu.num, p->stu.name, &p->stu.age, p->stu.Gender, &p->stu.birthday[0], &p->stu.birthday[1], &p->stu.birthday[2], p->stu.address, p->stu.t_number, p->stu.E_mail)==EOF)
        {
            pr->pNext = NULL;
            free(p);
            p = NULL;
            break;
        }
    }
    fclose(fp);
}

void FileSave(PNODE head)
{
    FILE *fp;
    NODE *p = head;
    if ((fp = fopen("student.txt", "a+")) == NULL)
    {
        printf("打开文件失败");
        exit(0);
    }
    while(p != NULL)   //将链表的内容存储到文本文件中
    {
        fprintf(fp, "%lld %s %d %s %d %d %d %s %s %s\n", p->stu.num, p->stu.name, p->stu.age, p->stu.Gender, p->stu.birthday[0], p->stu.birthday[1], p->stu.birthday[2], p->stu.address, p->stu.t_number, p->stu.E_mail);
        printf("\n");
        p = p->pNext;
    }
    fclose(fp);
}