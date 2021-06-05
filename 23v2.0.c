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
    printf("1.修改学号\n");
    printf("2.修改姓名\n");
    printf("3.修改成绩\n");
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
    printf("----学生成绩记录程序----\n");
    printf("1.添加学生成绩(写入文件)\n");
    printf("2.显示学生成绩(读取文件)\n)");
    printf("3.查询学生成绩\n");
    printf("4.修改成绩并保存\n");
    printf("5.显示学生成绩分段信息\n");
    printf("0.退出程序\n");
}

int Add_student(Student **p,int *len)
{
    
    if ((*len) >= MAX) 
    {
        printf("空间已满,添加失败\n");
        return -1;
    }
    printf("请输入学生学号:");
    scanf("%d",&(*p)[(*len)].num);
    printf("请输入学生姓名:");
    scanf("%s",&(*p)[(*len)].name);
    printf("请输入学生c语言成绩:");
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
        printf("学号:%d 姓名:%s 成绩:%d,\n",(*p)[i].num,(*p)[i].name,(*p)[i].result);
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
    printf("请输入选项:\n");
    printf("1.按学号查找\n");
    printf("2.按姓名查找\n");
    scanf("%d",&temp);
    switch (temp)
    {
    case 1:
    	printf("请输入学号:");
        scanf("%d",&n);
        for ( i = 0; i < len; i++)
        {
            if ((*p)[i].num == n)
            {
                printf("学号:%d 姓名:%s 成绩:%d,\n",(*p)[i].num,(*p)[i].name,(*p)[i].result);
            }
        }
        break;
    case 2:
        printf("请输入姓名:");
        scanf("%s",t);
        for ( i = 0; i < len; i++)
        {
            if (strcmp((*p)[i].name,t) == 0)
            {
                printf("学号:%d 姓名:%s 成绩:%d,\n",(*p)[i].num,(*p)[i].name,(*p)[i].result);
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
    printf("请输入名字:");
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
                printf("请输入新学号:");
                scanf("%d",&(*p)[i].num);
                break;
            case 2:
                printf("请输入新姓名:");
                scanf("%s",&(*p)[i].name);
                break;
            case 3:
                printf("请输入新成绩:");
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
    printf("请输入学号:");
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
                printf("请输入新学号:");
                scanf("%d",&(*p)[i].num);
                break;
            case 2:
                printf("请输入新姓名:");
                scanf("%s",&(*p)[i].name);
                break;
            case 3:
                printf("请输入新成绩:");
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
    printf("请输入选项:\n");
    printf("1.按姓名修改\n");
    printf("2.按学号修改\n");
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
    printf("分数在60分一下的同学\n");
    for ( i = 0; i < len; i++)
    {
        if ((*p)[i].result < 60)
        {
            printf("学号:%d 姓名:%s 成绩:%d,\n",(*p)[i].num,(*p)[i].name,(*p)[i].result);
        }
    }
    printf("分数在60 - 79的同学\n");
    for ( i = 0; i < len; i++)
    {
        if ((*p)[i].result >= 60 && (*p)[i].result <= 79)
        {
            printf("学号:%d 姓名:%s 成绩:%d,\n",(*p)[i].num,(*p)[i].name,(*p)[i].result);
        }
    }
    printf("分数在80 - 89分一下的同学\n");
    for ( i = 0; i < len; i++)
    {
        if ((*p)[i].result >= 80 && (*p)[i].result <= 89)
        {
            printf("学号:%d 姓名:%s 成绩:%d,\n",(*p)[i].num,(*p)[i].name,(*p)[i].result);
        }
    }
    printf("分数在90分以上的同学\n");
    for ( i = 0; i < len; i++)
    {
        if ((*p)[i].result >= 90)
        {
            printf("学号:%d 姓名:%s 成绩:%d,\n",(*p)[i].num,(*p)[i].name,(*p)[i].result);
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
        	//测试专用
        	printf("当前的len值为:%d\n",len);
        	 for ( i = 0; i < MAX; i++)
    		 {
        	 	printf("学号:%d 姓名:%s 成绩:%d\n",S_List[i].num,S_List[i].name,S_List[i].result);
    		 }
//            printf("%d\n",get_len(&S_List));
            break;
        default:
            break;
        }
    }
}
