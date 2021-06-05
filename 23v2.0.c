#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define FNAME "student.txt"
#define MAX 5

typedef struct student
{
    int num;
    char name[128];
    int result;
} Student;
void re_menu()
{
    printf("1.�޸�ѧ��\n");
    printf("2.�޸�����\n");
    printf("3.�޸ĳɼ�\n");
}
int get_len(Student **p)
{
    int i = 0;
    int count = 0;
    while ((*p)[i].num > 0 && (*p)[i].num < 100)
    {
        count++;
        i++;
    }
    return count;
}

void Print_menu()
{
    printf("----ѧ���ɼ���¼����----\n");
    printf("1.���ѧ���ɼ�(д���ļ�)\n");
    printf("2.��ʾѧ���ɼ�(��ȡ�ļ�)\n)");
    printf("3.��ѯѧ���ɼ�\n");
    printf("4.�޸ĳɼ�������\n");
    printf("5.��ʾѧ���ɼ��ֶ���Ϣ\n");
    printf("0.�˳�����\n");
}

int Add_student(Student **p,int *len)
{
    
    if ((*len) >= MAX) 
    {
        printf("�ռ�����,���ʧ��\n");
        return -1;
    }
    printf("������ѧ��ѧ��:");
    scanf("%d",&(*p)[(*len)].num);
    printf("������ѧ������:");
    scanf("%s",&(*p)[(*len)].name);
    printf("������ѧ��c���Գɼ�:");
    scanf("%d",&(*p)[(*len)].result);
    (*len)++;
    FILE *fp = fopen(FNAME,"w");
    if (!fp)
    {
        perror("");
        return -1;
    }
    int cont = fwrite((*p),sizeof(Student),MAX,fp);
    printf("cout = %d\n",cont);
	fclose(fp);
    return 1;
    
}

int Open_student(Student **p,int *len)
{
	int i;
    FILE *fp = NULL;
    fp = fopen(FNAME,"r");
//    Student *p = malloc(sizeof(Student)*MAX);
	if(!fp)
	{
		return 0;	
	} 
    int cont = fread((*p),sizeof(Student),MAX,fp);
    printf("%d\n",cont);
    for (i = 0; i < (*len); i++)
    {
        printf("ѧ��:%d ����:%s �ɼ�:%d,\n",(*p)[i].num,(*p)[i].name,(*p)[i].result);
    }
    fclose(fp);
    return 1;
    
}

void Init_student(Student **p)
{
    FILE *fp = NULL;
    fp = fopen(FNAME,"r");
    if (!fp)
    {
        return;
    }
    fread((*p),sizeof(Student),MAX,fp);
}

void search_student(Student **p,int len)
{
    int temp;
    int i;
    int n;
    char t[128] = { 0 };
    printf("������ѡ��:\n");
    printf("1.��ѧ�Ų���\n");
    printf("2.����������\n");
    scanf("%d",&temp);
    switch (temp)
    {
    case 1:
    	printf("������ѧ��:");
        scanf("%d",&n);
        for ( i = 0; i < len; i++)
        {
            if ((*p)[i].num == n)
            {
                printf("ѧ��:%d ����:%s �ɼ�:%d,\n",(*p)[i].num,(*p)[i].name,(*p)[i].result);
            }
        }
        break;
    case 2:
        printf("����������:");
        scanf("%s",t);
        for ( i = 0; i < len; i++)
        {
            if (strcmp((*p)[i].name,t) == 0)
            {
                printf("ѧ��:%d ����:%s �ɼ�:%d,\n",(*p)[i].num,(*p)[i].name,(*p)[i].result);
            }
            
        }
        
        break;

    default:
        break;
    }    
}

int re_name(Student **p,int len)
{
    char temp[128] = { 0 };
    printf("����������:");
    scanf("%s",temp);
    int x;
    int i;
    for ( i = 0; i < len; i++)
    {
        if (strcmp((*p)[i].name,temp) == 0)
        {
            re_menu();
            scanf("%d",&x);
            switch (x)
            {
            case 1:
                printf("��������ѧ��:");
                scanf("%d",&(*p)[i].num);
                break;
            case 2:
                printf("������������:");
                scanf("%s",&(*p)[i].name);
                break;
            case 3:
                printf("�������³ɼ�:");
                scanf("%d",&(*p)[i].result);
                break;
            default:
                break;
            }
        }
        
    }
    
}
int re_num(Student **p,int len)
{
    int temp;
    int i,x;
    printf("������ѧ��:");
	scanf("%d",&temp); 
    for ( i = 0; i < len; i++)
    {
        if ((*p)[i].num == temp)
        {
            re_menu();
            scanf("%d",&x);
            switch (x)
            {
            case 1:
                printf("��������ѧ��:");
                scanf("%d",&(*p)[i].num);
                break;
            case 2:
                printf("������������:");
                scanf("%s",&(*p)[i].name);
                break;
            case 3:
                printf("�������³ɼ�:");
                scanf("%d",&(*p)[i].result);
                break;
            default:
                break;
            }
            return 1;
        }
    }
    return 0;
}
int re_student(Student **p,int len)
{   
    int a;
    printf("������ѡ��:\n");
    printf("1.�������޸�\n");
    printf("2.��ѧ���޸�\n");
    scanf("%d",&a);
    switch (a)
    {
    case 1:
        re_name(p,len);
        system("cls");
        break;
    case 2:
        re_num(p,len);
        system("cls");
        break;
    default:
        break;
    }
    
   	FILE *fp = fopen(FNAME,"w");
    if (!fp)
    {
        perror("");
        return -1;
    }
    fwrite((*p),sizeof(Student),MAX,fp);
    fclose(fp); 
}
void sort_student(Student **p,int len)
{
    int i;
    printf("������60��һ�µ�ͬѧ\n");
    for ( i = 0; i < len; i++)
    {
        if ((*p)[i].result < 60)
        {
            printf("ѧ��:%d ����:%s �ɼ�:%d,\n",(*p)[i].num,(*p)[i].name,(*p)[i].result);
        }
    }
    printf("������60 - 79��ͬѧ\n");
    for ( i = 0; i < len; i++)
    {
        if ((*p)[i].result >= 60 && (*p)[i].result <= 79)
        {
            printf("ѧ��:%d ����:%s �ɼ�:%d,\n",(*p)[i].num,(*p)[i].name,(*p)[i].result);
        }
    }
    printf("������80 - 89��һ�µ�ͬѧ\n");
    for ( i = 0; i < len; i++)
    {
        if ((*p)[i].result >= 80 && (*p)[i].result <= 89)
        {
            printf("ѧ��:%d ����:%s �ɼ�:%d,\n",(*p)[i].num,(*p)[i].name,(*p)[i].result);
        }
    }
    printf("������90�����ϵ�ͬѧ\n");
    for ( i = 0; i < len; i++)
    {
        if ((*p)[i].result >= 90)
        {
            printf("ѧ��:%d ����:%s �ɼ�:%d,\n",(*p)[i].num,(*p)[i].name,(*p)[i].result);
        }
    }
    
    
}

int main()
{   
    int i;
    Student* S_List = malloc(sizeof(Student)* MAX);
    memset(S_List,0,sizeof(Student)*MAX);
    Init_student(&S_List);
    int len = get_len(&S_List);
    while (1)
    {
        int a;
        Print_menu();
        scanf("%d",&a);
        switch (a)
        {
        case 1:
            Add_student(&S_List,&len);
            break;
        case 2:
            Open_student(&S_List,&len);
            break;
        case 3:
            search_student(&S_List,len);
            break;
        case 4:
            re_student(&S_List,len);
            break;
        case 5:
            sort_student(&S_List,len);
            break;
        case 0:
        	exit(0);
        	break;
        case 6:
        	//����ר��
        	printf("��ǰ��lenֵΪ:%d\n",len);
        	 for ( i = 0; i < MAX; i++)
    		 {
        	 	printf("ѧ��:%d ����:%s �ɼ�:%d\n",S_List[i].num,S_List[i].name,S_List[i].result);
    		 }
//            printf("%d\n",get_len(&S_List));
            break;
        default:
            break;
        }
    }
}
