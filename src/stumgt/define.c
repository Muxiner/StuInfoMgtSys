#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "statement.h"

void ChoiceMenu()
{
    int choose;
    printf("��ѡ��Ҫ���еĹ���\n=>");
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
        printf("��ӭ���ٴ�ʹ�ñ�ϵͳ\n");
        DeleteMemory(head);
        exit(0);
    }
    default:
    {
        printf("�����˴����ѡ��  ����������\n");
        break;
    }
    }
}

void HZ() // ��ʽ��
{
    printf("���س����ز˵�......");
    getchar();
    getchar();
}

void Menu()
{
    printf("\n");
    printf("\t\t|...........ѧ����Ϣ����ϵͳ...........|\n");
    printf("\t\t|\t 1.����ѧ����Ϣ                |\n");
    printf("\t\t|\t 2.���ѧ����Ϣ                |\n");
    printf("\t\t|\t 3.��ѧ������                  |\n");
    printf("\t\t|\t 4.ѧ�Ų���ѧ����Ϣ            |\n");
    printf("\t\t|\t 5.��������ѧ����Ϣ            |\n");
    printf("\t\t|\t 6.�޸�ѧ���ɼ�(��ѧ��)��Ϣ    |\n");
    printf("\t\t|\t 7.�޸�ѧ���ɼ�(������)��Ϣ    |\n");
    printf("\t\t|\t 8.��ѧ��ɾ��ѧ���ɼ���Ϣ      |\n");
    printf("\t\t|\t 9.������ɾ��ѧ���ɼ���Ϣ      |\n");
    printf("\t\t|\t10.��ѧ����Ϣ                |\n");
    printf("\t\t|\t11.����ڵ���Ϣ                |\n");
    printf("\t\t|\t12.���ѧ����Ϣ                |\n");
    printf("\t\t|\t 0.�˳�                        |\n");
    printf("\t\t|......................................|\n");
}

void InputData(PNODE head)
{
    head = (NODE *)malloc(LEN);
    if (NULL == head)
    {
        printf("�ڴ����ʧ��,������ֹ!\n");

        exit(0);
    }
    PNODE pTail = head;  // ����һ��ָ��ͷ����ָ��
    pTail->pNext = NULL; // ���ָ����
    NODE Stu;
    PNODE pNew = (PNODE)malloc(sizeof(NODE));
    if (NULL == pNew)
    {
        printf("�ڴ����ʧ��,������ֹ!\n");
        exit(0);
    }
    number = 0;
    printf("������ѧ������Ϣ\n");
    printf("---------------------------ѧ��Ϊ��0����������-------------------------------------\n");
    while (Stu.stu.num != 0)
    {
        printf("\tѧ��=>");
        scanf("%ld", &Stu.stu.num);
        if (Stu.stu.num != 0)
        {
            number += 1;
            printf("=>���������������䣬�Ա𣬳������£���ַ���绰��E-mail\n");
            printf("\t����=>>");
            scanf("%s %d %s %d %d %d %s %s %s", Stu.stu.name, &Stu.stu.age, Stu.stu.Gender, &Stu.stu.birthday[0], &Stu.stu.birthday[1],
                  &Stu.stu.birthday[2], Stu.stu.address, Stu.stu.t_number, Stu.stu.E_mail);

            PNODE pNew = (PNODE)malloc(LEN);
            if (NULL == pNew) // �ж��ڴ��Ƿ�Ϊ��
            {
                printf("�ڴ����ʧ��,������ֹ!\n");
                exit(0);
            }
            pNew->stu = Stu.stu; // ��ʼ������������
            pTail->pNext = pNew; // ���½��ҵ��Ͻ���
            pNew->pNext = NULL;  // ����½���ָ����
            pTail = pNew;        // ��pTail�Ƶ��½����
        }
    }
    printf("\n������%d��ѧ������Ϣ\n", number);
    FileSave(head);
}

void NumberSort(PNODE head)
{
    PNODE p, q; // ��������ָ��

    NODE temp;

    for (p = head->pNext; NULL != p; p = p->pNext)
    {
        for (q = p->pNext; NULL != q; q = q->pNext)
        {
            if (p->stu.num < q->stu.num) // ��ǰһ��ѧ����ѧ��С�ں�һ��ѧ��ѧ��ʱ
            {
                temp.stu = p->stu; // ����ѧ����λ��
                p->stu = q->stu;
                q->stu = temp.stu;
            }
        }
    }
    printf("\n���������\n");
}

void DisplayNode(PNODE pHead)
{
    PNODE p = pHead->pNext;
    int i = 1;
    printf("\t\t\t   ѧ��   ����   ����  �Ա�    ��������        ��ַ     �绰             E-mail\n");
    do
    {
        printf("\tѧ����Ϣ(%02d):%10lld%10s %3d%7s %5d%3d%3d  %10s  %12s %20s\n", i++, p->stu.num, p->stu.name, p->stu.age, p->stu.Gender,
               p->stu.birthday[0], p->stu.birthday[1], p->stu.birthday[2], p->stu.address, p->stu.t_number, p->stu.E_mail);
        p = p->pNext;
    } while (p != NULL);
}

void InsertStudent(PNODE pHead)
{
    PNODE p = pHead;

    int i = 0;

    struct Student stu; // ѧ���ṹ

    int pos; // �������λ��

    printf("���������ѧ����λ��:");
    scanf("%d", &pos);

    while (NULL != p && i < pos - 1)
    {
        p = p->pNext;

        i++;
    }

    if (NULL == p || i > pos)
    {
        printf("�������λ�ò�����!\n");

        return;
    }

    printf("\tѧ��=>");
    scanf("%lld", &stu.num);
    if (stu.num != 0)
    {
        number += 1;
        printf("=>���������������䣬�Ա𣬳������£���ַ���绰��E-mail\n");
        printf("\t����=>>");
        scanf("%s %d %s %d %d %d %s %s %s", stu.name, &stu.age, stu.Gender, &stu.birthday[0], &stu.birthday[1],
              &stu.birthday[2], stu.address, stu.t_number, stu.E_mail);
    }
    PNODE pNew = (PNODE)malloc(LEN);

    if (NULL == pNew)
    {
        printf("��̬�ڴ����ʧ��,������ֹ!\n");

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
    // NODE Stu;
    long long studentID;
    if (head == NULL)
    {
        printf("�Բ���û�����ݿ���ɾ��\n\n");
        return;
    }
    printf("------------------------------\n");
    printf("��������Ҫɾ����ѧ����ѧ��:");
    scanf("%lld", &studentID);
    printf("------------------------------\n");
    while (studentID != p->stu.num && p->pNext != NULL)
    {
        pr = p;
        p = p->pNext;
    }
    if (studentID == p->stu.num)
    {
        printf("\t�ɹ�ɾ����ѧ������Ϣ\n");
        printf("ѧ��:        %lld\n", p->stu.num);
        printf("����:        %s\n", p->stu.name);
        printf("����:        %d\n", p->stu.age);
        printf("�Ա�:        %s\n", p->stu.Gender);
        printf("��������:    %4d %02d %02d\n", p->stu.birthday[0], p->stu.birthday[1], p->stu.birthday[2]);
        printf("��ͥ��ַ:    %s\n", p->stu.address);
        printf("�绰����:    %s\n", p->stu.t_number);
        printf("���䣺       %s\n", p->stu.E_mail);
        printf("\n");
        if (p == head)
            head = p->pNext;
        else
            pr->pNext = p->pNext;
        free(p);
    }
    else
        printf("��Ҫ���ҵ��������δ�ҵ�\n");
    return;
}

void DeleteNodeName()
{
    NODE *p = head, *pr = head;
    char studentName[10];
    if (head == NULL)
    {
        printf("�Բ���û�����ݿ���ɾ��\n");
        return;
    }
    printf("------------------------------\n");
    printf("��������Ҫɾ����ѧ��������:");
    scanf("%s", studentName);
    printf("------------------------------\n");
    while (0 != strcmp(studentName, p->stu.name) && p->pNext != NULL)
    {
        pr = p;
        p = p->pNext;
    }
    if (strcmp(studentName, p->stu.name) == 0)
    {
        printf("\t�ɹ�ɾ����ѧ������Ϣ\n");
        printf("ѧ��:        %lld\n", p->stu.num);
        printf("����:        %s\n", p->stu.name);
        printf("����:        %d\n", p->stu.age);
        printf("�Ա�:        %s\n", p->stu.Gender);
        printf("��������:    %4d %02d %02d\n", p->stu.birthday[0], p->stu.birthday[1], p->stu.birthday[2]);
        printf("��ͥ��ַ:    %s\n", p->stu.address);
        printf("�绰����:    %s\n", p->stu.t_number);
        printf("���䣺       %s\n", p->stu.E_mail);
        printf("\n");
        if (p == head)
            head = p->pNext;
        else
            pr->pNext = p->pNext;
        free(p);
    }
    else
        printf("��Ҫ���ҵ��������δ�ҵ�\n");
    return;
}

void studentIDFind()
{
    NODE *p = head;
    long long num = 0;
    if (head == NULL)
    {
        printf("û�����ݲ���\n");
        return;
    }
    printf("------------------------------\n");
    printf("��������Ҫ���ҵ�ѧ����ѧ�ţ�");
    scanf("%lld", &num);
    printf("------------------------------\n");
    while (num != p->stu.num && p->pNext != NULL)
    {
        p = p->pNext;
    }
    if (p->stu.num == num)
    {
        printf("ѧ��:        %lld\n", p->stu.num);
        printf("����:        %s\n", p->stu.name);
        printf("����:        %d\n", p->stu.age);
        printf("�Ա�:        %s\n", p->stu.Gender);
        printf("��������:    %4d %02d %02d\n", p->stu.birthday[0], p->stu.birthday[1], p->stu.birthday[2]);
        printf("��ͥ��ַ:    %s\n", p->stu.address);
        printf("�绰����:    %s\n", p->stu.t_number);
        printf("���䣺       %s\n", p->stu.E_mail);
        printf("\n");
    }
    else
        printf("û����Ҫ���ҵ�����\n");
    return;
}

void studentNameFind()
{
    NODE *p = head;
    char name[10] = "";
    if (head == NULL)
    {
        printf("û�����ݲ���\n");
        return;
    }
    printf("------------------------------\n");
    printf("��������Ҫ���ҵ�ѧ����������");
    scanf("%s", name);
    printf("------------------------------\n");
    while (0 != strcmp(name, p->stu.name) && p->pNext != NULL)
    {
        p = p->pNext;
    }
    if (0 == strcmp(name, p->stu.name))
    {
        printf("ѧ��:        %lld\n", p->stu.num);
        printf("����:        %s\n", p->stu.name);
        printf("����:        %d\n", p->stu.age);
        printf("�Ա�:        %s\n", p->stu.Gender);
        printf("��������:    %4d %02d %02d\n", p->stu.birthday[0], p->stu.birthday[1], p->stu.birthday[2]);
        printf("��ͥ��ַ:    %s\n", p->stu.address);
        printf("�绰����:    %s\n", p->stu.t_number);
        printf("���䣺       %s\n", p->stu.E_mail);
        printf("\n");
    }
    else
        printf("û����Ҫ���ҵ�����\n");
    return;
}

void ModifyNodeID() // ����ѧ���޸�
{
    if (head == NULL)
    {
        printf("û�����ݲ���");
        return;
    }
    PNODE p = head->pNext; // ����һ��ָ�����ڱ���ѧ����Ϣ
    long long num;
    printf("------------------------------\n");
    printf("��������Ҫ���ҵ�ѧ����ѧ�ţ�");
    scanf("%lld", &num);
    printf("------------------------------\n");

    while (NULL != p)
    {
        if (p->stu.num == num)
        {
            printf("�޸�ǰ��ѧ����Ϣ!\n");
            printf("ѧ��:        %lld\n", p->stu.num);
            printf("����:        %s\n", p->stu.name);
            printf("����:        %d\n", p->stu.age);
            printf("�Ա�:        %s\n", p->stu.Gender);
            printf("��������:    %4d %02d %02d\n", p->stu.birthday[0], p->stu.birthday[1], p->stu.birthday[2]);
            printf("��ͥ��ַ:    %s\n", p->stu.address);
            printf("�绰����:    %s\n", p->stu.t_number);
            printf("���䣺       %s\n", p->stu.E_mail);
            printf("\n");
            int choice;
            printf("��ѡ����Ҫ�޸ĵ���Ϣ\n0.������Ϣ\n1.ѧ��\n2.����\n3.����\n4.�Ա�\n5.��������\n6.��ͥסַ\n7.�绰����\n8.����\n=>");
            scanf("%d", &choice);

            switch (choice)
            {
            case 0:
            {
                printf("�������µ�ѧ����Ϣ\nѧ�š����������䡢�Ա𡢳������¡���ͥ��ַ���绰���롢����\n=>");
                scanf("%lld %s %d %s %d %d %d %s %s %s", &p->stu.num, p->stu.name, &p->stu.age, p->stu.Gender, &p->stu.birthday[0], &p->stu.birthday[1],
                      &p->stu.birthday[2], p->stu.address, p->stu.t_number, p->stu.E_mail);
            }
            break;
            case 1:
            {
                printf("�������µ�ѧ��ѧ��\n=>");
                scanf("%lld", &p->stu.num);
            }
            break;
            case 2:
            {
                printf("�������µ�ѧ������\n=>");
                scanf("%s", p->stu.name);
            }
            break;
            case 3:
            {
                printf("�������µ�ѧ������\n=>");
                scanf("%d", &p->stu.age);
            }
            break;
            case 4:
            {
                printf("�������µ�ѧ���Ա�\n=>");
                scanf("%s", p->stu.Gender);
            }
            break;
            case 5:
            {
                printf("�������µ�ѧ����������\n=>");
                scanf("%d %d %d", &p->stu.birthday[0], &p->stu.birthday[1], &p->stu.birthday[2]);
            }
            break;
            case 6:
            {
                printf("�������µ�ѧ����ͥ��ַ\n=>");
                scanf("%s", p->stu.address);
            }
            break;
            case 7:
            {
                printf("�������µ�ѧ���绰����\n=>");
                scanf("%s", p->stu.t_number);
            }
            break;
            case 8:
            {
                printf("�������µ�ѧ������\n=>");
                scanf("%s", p->stu.E_mail);
            }
            break;
            default:
            {
                printf("�����˲����ڵ����\n�˻ز˵���\n");
            }
                continue;
            }
            break;
        }
        else
            printf("û����Ҫɾ��������\n");
        p = p->pNext;
    }
}

void ModifyNodeName() // ���������޸�
{
    char name[10] = "";
    if (head == NULL)
    {
        printf("û�����ݲ���");
        return;
    }
    PNODE p = head->pNext; // ����һ��ָ�����ڱ���ѧ����Ϣ
    printf("------------------------------\n");
    printf("��������Ҫ���ҵ�ѧ����������");
    scanf("%s", name);
    printf("------------------------------\n");

    while (NULL != p)
    {
        if (0 == strcmp(name, p->stu.name))
        {
            printf("�޸�ǰ��ѧ����Ϣ!\n");
            printf("ѧ��:        %lld\n", p->stu.num);
            printf("����:        %s\n", p->stu.name);
            printf("����:        %d\n", p->stu.age);
            printf("�Ա�:        %s\n", p->stu.Gender);
            printf("��������:    %4d %02d %02d\n", p->stu.birthday[0], p->stu.birthday[1], p->stu.birthday[2]);
            printf("��ͥ��ַ:    %s\n", p->stu.address);
            printf("�绰����:    %s\n", p->stu.t_number);
            printf("���䣺       %s\n", p->stu.E_mail);
            printf("\n");

            int choice;
            printf("��ѡ����Ҫ�޸ĵ���Ϣ\n0.������Ϣ\n1.ѧ��\n2.����\n3.����\n4.�Ա�\n5.��������\n6.��ͥסַ\n7.�绰����\n8.����\n=>");
            scanf("%d", &choice);

            switch (choice)
            {
            case 0:
            {
                printf("�������µ�ѧ����Ϣ\nѧ�š����������䡢�Ա𡢳������¡���ͥ��ַ���绰���롢����\n=>");
                scanf("%lld %s %d %s %d %d %d %s %s %s", &p->stu.num, p->stu.name, &p->stu.age, p->stu.Gender, &p->stu.birthday[0], &p->stu.birthday[1],
                      &p->stu.birthday[2], p->stu.address, p->stu.t_number, p->stu.E_mail);
            }
            break;
            case 1:
            {
                printf("�������µ�ѧ��ѧ��\n=>");
                scanf("%lld", &p->stu.num);
            }
            break;
            case 2:
            {
                printf("�������µ�ѧ������\n=>");
                scanf("%s", p->stu.name);
            }
            break;
            case 3:
            {
                printf("�������µ�ѧ������\n=>");
                scanf("%d", &p->stu.age);
            }
            break;
            case 4:
            {
                printf("�������µ�ѧ���Ա�\n=>");
                scanf("%s", p->stu.Gender);
            }
            break;
            case 5:
            {
                printf("�������µ�ѧ����������\n=>");
                scanf("%d %d %d", &p->stu.birthday[0], &p->stu.birthday[1], &p->stu.birthday[2]);
            }
            break;
            case 6:
            {
                printf("�������µ�ѧ����ͥ��ַ\n=>");
                scanf("%s", p->stu.address);
            }
            break;
            case 7:
            {
                printf("�������µ�ѧ���绰����\n=>");
                scanf("%s", p->stu.t_number);
            }
            break;
            case 8:
            {
                printf("�������µ�ѧ������\n=>");
                scanf("%s", p->stu.E_mail);
            }
            break;
            default:
            {
                printf("�����˲����ڵ����\n�˻ز˵���\n");
            }
                continue;
            }
            break;
        }
        else
            printf("û����Ҫɾ��������\n");
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
    p = (NODE *)malloc(sizeof(NODE));
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
        printf("[��ʼ��]�ڵ㴴��ʧ��");
        return;
    }
    else
    {
        head = NULL;
        if (fscanf(fp, "%lld %s %d %s %d %d %d %s %s %s", &p->stu.num, p->stu.name, &p->stu.age, p->stu.Gender, &p->stu.birthday[0], &p->stu.birthday[1], &p->stu.birthday[2], p->stu.address, p->stu.t_number, p->stu.E_mail) == EOF)
            return;
    }

    while (1)
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
        if (fscanf(fp, "%lld %s %d %s %d %d %d %s %s %s", &p->stu.num, p->stu.name, &p->stu.age, p->stu.Gender, &p->stu.birthday[0], &p->stu.birthday[1], &p->stu.birthday[2], p->stu.address, p->stu.t_number, p->stu.E_mail) == EOF)
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
        printf("���ļ�ʧ��");
        exit(0);
    }
    while (p != NULL) // ����������ݴ洢���ı��ļ���
    {
        fprintf(fp, "%lld %s %d %s %d %d %d %s %s %s\n", p->stu.num, p->stu.name, p->stu.age, p->stu.Gender, p->stu.birthday[0], p->stu.birthday[1], p->stu.birthday[2], p->stu.address, p->stu.t_number, p->stu.E_mail);
        printf("\n");
        p = p->pNext;
    }
    fclose(fp);
}