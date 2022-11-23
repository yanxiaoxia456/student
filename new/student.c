#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define max 100			//数组定义统一大小
int g = 0;				//全局变量，为登录时输入密码次数
struct user				//定义一个结构体，存储用户登录账号和密码，并初始化五个管理员的信息
{
	char username[20];
	char password[20];
} user[5] = { //管理员信息
	{"chuan", "123"},
	{"郝", "202008071505"},
	{"晏", "200"},
	{"李", "12345"},
	{"霞", "1111"}};
struct student //定义结构体，包含学生信息，并初始化五个学生的信息
{
	char num[max];	//学号
	char name[max]; //姓名
	int age;		//年龄
	char sex[max];	//性别
    int class;      //班级
	int thought;	//思想成绩
	int academic;	//学业成绩
	int style;		//文体成绩
	int total;		//综测
}a[max];	
int  student_number	= 0;
void read();
void login();
void main_menu();
void input_record();
void show_record();
void search_record();
void print_table();
void search_by_num();
void search_by_name();
void change_record();
void delete_record();
void refresh();
void save_record();
void exit_record();
void help();
int main() //*主函数
{
    read();
	login();	 //首先进行管理员登录
	main_menu(); //登录成功后显示主界面
	return 0;
}
void read()//从已有文件读数据
{
    FILE *fp = NULL;
    fp = fopen("C:\\Users\\86136\\Desktop\\C C++\\new\\information.txt","r");
    if( fp == NULL) { printf("\nError!\n"); exit(0);}
    while(feof(fp) == 0 )
    {
        fscanf(fp,"%20s%20s%5d%5s%5d%5d%5d%5d%5d\n",&a[student_number].num,&a[student_number].name,&a[student_number].age,
        &a[student_number].sex,&a[student_number].class,&a[student_number].thought,
        &a[student_number].academic,&a[student_number].style,&a[student_number].total);
        student_number++;
    }   
    fclose(fp);
}
void login() //登录函数，管理员使用该系统前需进行登录，定义密码只允许输错三次
{
	int i;
	int j;
	char id[20], password[20];
	printf("****登录界面****\n");
	printf("请输入账号名：");
	scanf("%s", id);
	printf("请输入密码：");
	scanf("%s", password);
	for (i = 0; i < 5; i++) //遍历五个管理员的信息，如果输入的信息在初始化的信息中存在则登录成功
	{
		for (j = 0; j != 10; j++)//for循环，对比账号名
		{
			if (id[j] != user[i].username[j])//有一个字符不对，则退出循环
				break;
		}
		if (j != 10 && (strcmp(password, user[i].password) == 0))
		{
			printf("登录成功!\n");
			system("cls"); //清屏函数
			main_menu();   //登录成功，打印主界面
			break;
		}
	}
    
	if (i == 5) //遍历完一轮管理员信息，此时i=5且未找到符合的管理员信息，说明账号密码输入错误
	{
		system("cls");
		printf("登录失败！\n\n");
		g++;		//有三次登录机会，每次登录都遍历一次user结构体
		if (g >= 3) //若三次机会都用完，则退出系统
		{
			printf("你已经输错三次，将自动退出系统\n");
			exit(1);
		}
		else //机会未用完，则递归调用登陆界面函数
		{
			login(); //否则，登陆成功，进入主界面
		}
	}
}
void main_menu() //展示主菜单，并对用户的请求做出对应响应
{
	int i = 1;
	system("cls"); //清屏函数
	int x;
	//主菜单
	printf("*************************************************\n");
	printf("*\t欢迎使用高校学生成绩管理系统V2.0\t*\n");
	printf("*************************************************\n");
	printf("*\t\t1.添加学生信息\t\t\t*\n");
	printf("*\t\t2.显示学生信息\t\t\t*\n");
	printf("*\t\t3.查询学生信息\t\t\t*\n");
	printf("*\t\t4.修改学生信息\t\t\t*\n");
	printf("*\t\t5.删除学生信息\t\t\t*\n");
	printf("*\t\t6.刷新学生信息\t\t\t*\n");
	printf("*\t\t7.保存学生信息\t\t\t*\n");
	printf("*\t\t8.帮助\t\t\t\t*\n");
	printf("*\t\t9.退出系统\t\t\t*\n");
	printf("*************************************************\n");
	printf("请输入你要执行的操作：");
	scanf("%d", &x);
	if (x == 1)
		input_record(); //输入信息
	if (x == 2)
		show_record(); //显示信息
	if (x == 3)
		search_record(); //查询信息
	if (x == 4)
		change_record(); //更新信息
	if (x == 5)
		delete_record(); //删除信息
	if (x == 6)
		refresh(); //刷新
    if (x == 7)
        save_record();
    if (x == 8)
        help();
	if (x == 9)
		exit_record(); //退出
	else
	{
		printf("输入错误，即将重新进入主界面\n");
		main_menu();
	}
}
void input_record() //功能一，输入学生信息
{
    system("cls"); //清屏函数
    int i = student_number;
    printf("\n输入第%d组的信息：",i);
    printf("\n输入学号(以#结束)：");
    scanf("%s",a[i].num);
    while(strcmp(a[i].num,"#") != 0)
    { 
        printf("\n请输入学生姓名：");
        scanf("%s",a[i].name);
        printf("\n请输入学生年龄：");
        scanf("%d",&a[i].age);
        printf("\n请输入学生性别：(boy/girl)");
        scanf("%s",a[i].sex);
        printf("\n请输入学生班级：");
        scanf("%d",&a[i].class);
        printf("\n请输入学生思想成绩：");
        scanf("%d",&a[i].thought);
        printf("\n请输入学生学业成绩：");
        scanf("%d",&a[i].academic);
        printf("\n请输入学生文体成绩：");
        scanf("%d",&a[i].style);
        a[i].total = 0.2 * a[i].thought + 0.7 * a[i].academic + 0.1 * a[i].style;
        ++i;
        printf("\n     输入第%d组信息：\n",i);
        printf("\n     输入学号(以#结束)：\n");
        scanf("%s",a[i].num);
        student_number++;
    }
    printf("输入结束");
    printf("输入结束按任意键回到主函数");
    getch();
	main_menu();
}
void show_record() //功能二，显示学生信息
{
    system("cls"); //清屏函数
    int i;
    
    print_table();
    for(i = 0; i < student_number ; i++)
    {

        printf("|%15s|%15s|%5d|%5s|%5d|%5d|%5d|%5d|%5d|\n", a[i].num, a[i].name, a[i].age, a[i].sex, a[i].class ,a[i].thought, a[i].academic,
			   a[i].style, a[i].total);
    }
    printf("显示完成,可按任意键回到主函数");
    getch();
	main_menu();
}
void search_record() //功能三，查询学生
{
	system("cls"); //清屏函数
	int n = 0, x = 0;
	printf("1 按学号查询\n");
	printf("2 按姓名查询\n");
	printf("3 返回上一级\n");
	printf("请输入：\n");
	scanf("%d", &x);
	if (x == 1)
		search_by_num(); //按学号查询函数
	if (x == 2)
		search_by_name(); //按姓名查询函数
	if (x == 3)
		main_menu(); //返回主界面
	else
	{
		printf("输入错误\n");
		search_record(); //重新查询
	}
}
void print_table() //打印学生信息表格的表头函数
{
	printf("+---------------+---------------+-----+-----+-----+-----+-----+-----+-----+\n");
	printf("|    学号       |     姓名      | 年龄| 性别| 班级|思想 | 学业|文体 |综测 |\n");
	printf("+---------------+---------------+-----+-----+-----+-----+-----+-----+-----+\n");
}
void search_by_num() //查询学生信息函数的子函数——按学号查询函数
{
    system("cls");	//清屏函数
    int i;
    printf("请输入要查找的学号：");
    char num1[max]; //用户输入学生学号
    scanf("%s", num1);
    for(i = 0; i < student_number; i++)
    {
        if(strcmp(num1, a[i].num) == 0)  break;
    }
    if( i < student_number)
    {
        printf("找到了！\n");
        print_table();
        printf("|%15s|%15s|%5d|%5s|%5d|%5d|%5d|%5d|%5d|\n", a[i].num, a[i].name, a[i].age, a[i].sex,a[i].class, a[i].thought, a[i].academic,
			   a[i].style, a[i].total);
    }
    else     printf("不存在这个学号的学生！\n\n");
    int k = 0;
    printf("1.返回主界面\n2.继续查询\n");
	printf("请输入：\n");
	scanf("%d", &k);
	if (k == 1)
	{
		main_menu();
	}
	else
	{
		search_record();
	}
}
void search_by_name() //询学生信息函数的子函数——按姓名查询函数
{
    system("cls");	//清屏函数
    printf("请输入查找的的学生姓名");
    char name1[max];
    int i;
    scanf("%s",name1);
    for(i = 0; i < student_number; i++)
    {
        if(strcmp(name1, a[i].name) == 0)  break;
    }
    if( i < student_number )
    {
        printf("找到了！\n");
        print_table();
        printf("|%15s|%15s|%5d|%5s|%5d|%5d|%5d|%5d|%5d|1\n", a[i].num, a[i].name, a[i].age, a[i].sex,a[i].class, a[i].thought, a[i].academic,
			   a[i].style, a[i].total);
    }
    else     printf("不存在这个学号的学生！\n\n");
    int k = 0;
    printf("1.返回主界面\n2.继续查询\n");
	printf("请输入：\n");
	scanf("%d", &k);
	if (k == 1)
	{
		main_menu();
	}
	else
	{
		search_record();
	}
}
void change_record() //功能四，修改学生信息
{
	//输入学生学号修改学生信息并保持
	system("cls"); //清屏函数
	int i = 0,x = 0;//n为信息条数
    char number[max];
    printf("请输入要修改的学生的学号：\n"); //用户输入学生学号
    scanf("%s", number);
    for(i=0; i < student_number ; i++)
    {
        if( strcmp(number,a[i].num) == 0 )  break;
    }
    if( i < student_number)//修改信息
    {
        printf("修改前：\n");
        print_table();
        printf("|%15s|%15s|%5d|%5s|%5d|%5d|%5d|%5d|%5d|\n", a[i].num, a[i].name, a[i].age, a[i].sex, a[i].class, a[i].thought, 
        a[i].academic, a[i].style, a[i].total);
        printf("\n请输入修改后的信息:\n");
        printf("\n请输入学生姓名：");
        scanf("%s",a[i].name);
        printf("\n请输入学生年龄：");
        scanf("%d",&a[i].age);
        printf("\n请输入学生性别(boy/girl)：");
        scanf("%s",a[i].sex);
        printf("\n请输入学生班级：");
        scanf("%d",&a[i].class);
        printf("\n请输入学生思想成绩：");
        scanf("%d",&a[i].thought);
        printf("\n请输入学生学业成绩：");
        scanf("%d",&a[i].academic);
        printf("\n请输入学生文体成绩：");
        scanf("%d",&a[i].style);
        a[i].total = 0.2 * a[i].thought + 0.7 * a[i].academic + 0.1 * a[i].style;
        ++i;
        printf("修改完成\n");
    }
    else {
        printf("输入信息不正确\n");
    }
    printf("请选择下一步\n");
    printf("1 回到首页\n");
	printf("2 重新输入所要修改的学生学号\n");
	scanf("%d", &x);
	if (x == 2)     change_record();
	else main_menu();
}
void delete_record() //功能五，删除所选学生信息
{
	//输入学生学号删除学生信息并保存
	system("cls");
	char number[max];
    int i = 0;
    printf("请输入要修改的学生的学号：\n"); //用户输入学生学号
    scanf("%s", number);
    for(i=0; i < student_number ; i++)
    {
        if( strcmp(number,a[i].num) == 0 )  break;
    }
    if( i < student_number )//删除信息
    {
        printf("已找到！\n");
        for (int j = i; j < student_number - 1 ; j++) //将删除位置后续元素往前移一位
            {
                strcpy(a[j].num, a[j + 1].num);
                strcpy(a[j].name, a[j + 1].name);
                strcpy(a[j].sex, a[j + 1].sex);
                a[j].age = a[j + 1].age;
                a[j].class = a[j + 1].class;
                a[j].thought = a[j + 1].thought;
                a[j].academic = a[j + 1].academic;
                a[j].style = a[j + 1].style;
                a[j].total = a[j + 1].total;
            }
        student_number--;
        printf("修改完成");
    }
    else{
        printf("未找到！\n");
        printf("已取消操作\n");
    }
    int x = 0;
    printf("请选择下一步\n");
    printf("1 回到首页\n");
	printf("2 重新输入所要删除的学生学号\n");
	scanf("%d", &x);
	if (x == 2)     delete_record();
	else main_menu();
}
void refresh()//功能六，删除所有学生信息。
{
	system("cls"); //清屏函数
	printf("确定要清除所有数据吗？\n");
    printf("1.确定\n");
    printf("2,取消并返回主界面\n");
	int choose;
	scanf("%d",&choose);
	if( choose == 1)
	{
        for(int j = 0; j < student_number; j++)
        {
            strcpy(a[j].num, "");
            strcpy(a[j].name, "");
            strcpy(a[j].sex, "");
            a[j].age = 0;
            a[j].class = 0;
            a[j].thought = 0;
            a[j].academic = 0;
            a[j].style = 0;
            a[j].total = 0;
        }
        student_number = 0;
        printf("更新成功,可按任意键回到主函数");
        getch();
        main_menu();
	}
	else     main_menu();

}
void save_record()//功能七，保存学生信息
{
    system("cls"); //清屏函数
    FILE *fp = NULL;//修改信息
    fp = fopen("C:\\Users\\86136\\Desktop\\C C++\\new\\information.txt","w");
    if( fp == NULL) { printf("\nError!\n"); exit(0);}
    int i = 0;
    for(i = 0; i < student_number ; i++)
    {   
        fprintf(fp,"%-20s%-20s%-5d%-5s%-5d%-5d%-5d%-5d%-5d\n",a[i].num, a[i].name, a[i].age, a[i].sex, a[i].class, a[i].thought, 
        a[i].academic, a[i].style, a[i].total);
    }
    fclose(fp);
    printf("保存成功\n");
    printf("按任意键回到主函数");
    getch();
	main_menu();
}   
void help()//功能八，帮助
{
    system("cls"); //清屏函数
    printf("关于此小程序的介绍：\n");
    printf("功能概述：\n");
    printf("查询学生信息;添加学生信息;修改学生信息;删除学生信息;刷新学生信息;保存学生信息;输出当前学生信息\n");
    printf("关于此程序源代码，已开源在github上，账号为\n");
    printf("可按任意键回到主函数");
    getch();
	main_menu();
}
void exit_record() //功能九，退出程序
{
	printf("感谢您的使用，已退出！");
	exit(0);
}
