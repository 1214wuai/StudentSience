#pragma warning(disable:4996)

#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
#include<assert.h>

typedef	struct student {
	char num[20];//学号 
	char name[20];
	int  chinese;
	int  math;
	int  English;
	int  sum;//总分 
	struct student *next;//以链表的形式存储
} stud;

int menu_select();//菜单选择函数 
void circulate();//循环选择函数 
stud* Creat(stud** p);//录入模块 
void ShowStudent(stud *p);//显示模块 
void Search(stud *p);//按姓名查询模块 
void IndexOnNumber(stud *p);//按学号查询模块 
void reorder(stud **p, int x);//排序函数 
char print(stud *d);//输出函数 
void  Computer(stud *p);//统计模块 
void End();//结束函数 

int main()
{
	system("color F0");//改颜色 白色
	circulate();
	return 0;
}

int menu_select() {//菜单界面、功能选择 
	int c;
	system("cls");
	printf("\n");
	printf("\t\t    欢迎使用学生成绩管理系统    \n");
	printf("\t\t                                \n");
	printf("\t\t         1.输入学生信息         \n");
	printf("\t\t                                \n");
	printf("\t\t         2.删除学生信息         \n");
	printf("\t\t                                \n");
	printf("\t\t         3.增添学生信息         \n");
	printf("\t\t                                \n");
	printf("\t\t         4.显示所有学生信息     \n");
	printf("\t\t                                \n");
	printf("\t\t         5.学生成绩排名         \n");
	printf("\t\t                                \n");
	printf("\t\t         6.计算总分和平均分     \n");
	printf("\t\t                                \n");
	printf("\t\t         7.按查姓名查找学生信息 \n");
	printf("\t\t                                \n");
	printf("\t\t         8.按查学号查找学生信息 \n");
	printf("\t\t                                \n");
	printf("\t\t         9.退出系统             \n");
	printf("\n");
s1:	printf("\t\t   (请输入数字1~9): ");
	scanf("%d", &c);
	getchar();
	if (c < 1 || c>9)
	{
		printf("\t\t 无效的输入，请重新输入\n");
		c = 0;
		goto s1;
	}
	return c;
}

stud* Creat(stud** p) //创建函数，第一次输入学生信息 
{
	if (*p != NULL)
	{
		printf("系统已经创建，无需再创建！！\n");
		system("pause");
		return *p;
	}
	system("cls");//清屏函数
	printf("\t\t              HELLO，您正在输入学生信息...     \n\n");
	printf("\t\t              请根据提示输入学生信息:      \n\n");
	int i, j;
	stud *head, *p1, *p2;
s3:	printf("\t\t\t  ◎请输入总数:");
	scanf("%d", &i);
	getchar();
	if (i <= 0)
	{
		printf("\t\t\t输入错误,请重新输入\n");
		goto s3;
	}
	if ((head = (stud *)malloc(sizeof(stud))) == NULL)//创建头指针 
	{
		printf("\t\t\t空间不足建立失败\n");
		exit(0);
	}
	head->next = NULL;
	p1 = head;
	for (j = 0; j<i; j++)
	{
		if ((p2 = (stud *)malloc(sizeof(stud))) == NULL)//创建新的节点 
		{
			printf("\t\t\t空间不足建立失败\n");
			exit(0);
		}
		//输入学生信息 
		printf("\t\t您正在输入第%d个人的信息\n", j + 1);
		printf("\t\t ◎请输入学号:");
		scanf("%s", p2->num);
		printf("\t\t ◎请输入姓名:");
		scanf("%s", p2->name);
		printf("\t\t ◎请输入语文成绩:");
		scanf("%d", &p2->chinese);
		printf("\t\t ◎请输入数学成绩:");
		scanf("%d", &p2->math);
		printf("\t\t ◎请输入英语成绩:");
		scanf("%d", &p2->English);
		p2->sum = p2->chinese + p2->English + p2->math;
		//使上一个节点指向下一个节点 
		p1->next = p2;
		p2->next = NULL;//使最后节点next为空 
		p1 = p2;//p1指向最后一个节点
		if (i >= 3 && (j + 1) % 2 == 0) system("cls");
	}
	printf("\t\t已成功输入学生信息\n");
	system("pause");
	*p = head;
	return *p;//返回头指针 
}

void Search(stud *p) //按姓名查询函数  
{ //传头指针过来 
	if (p == NULL || p->next == NULL)//防止无学生信息 
	{
		printf("\t\t\t请先输入学生信息\n");
		system("pause");
		return;
	}
	stud *q = p->next, *a = p->next;
	char name[20] = {'0'};
	//char b[20] = { '0' };
	char m = 'y';
	while (m == 'y')//当m=‘y’时循环 
	{
		q = a;//每次循环重置指针q 
		system("cls");
		printf("\t\t\t请输入姓名:");
		scanf("%s", name);
		printf("\n");
		while (q)
		{
			if (strcmp(q->name, name) == 0)//比较节点中的姓名是否一致
			{
				printf(" |---------|----------------|-----|-----|-----|-----|\n");
				printf(" |%9s|%16s|%3d  |%3d  |%3d  |%3d  |\n",
					q->name, q->num, q->chinese, q->math, q->English, q->sum);
				printf(" |---------|----------------|-----|-----|-----|-----|\n");
				break;
			}
			else  q = q->next;
		}
		if (q)//等同于q!=NULL; 
		{
			printf("\t\t\t是否继续查询(y or n):");
			scanf(" %c", &m);
		}
		if (q == NULL)
		{
			printf("\t\t\t无此学生\n");
			system("pause");
			break;
		}
	}
	return;
}

void IndexOnNumber(stud *p)//按学号查询函数 
{
	if (p == NULL || p->next == NULL)//防止无学生信息 
	{
		printf("\t\t\t请先输入学生信息\n");
		system("pause");
		return;
	}
	stud *q = p->next, *a = p->next;
	char number[20] = { '0' };
	char m = 'y';
	while (m == 'y')
	{
		printf("\t\t\t请输入学号:");
		scanf("%s", number);
		printf("\n");
		while (q)
		{
			if (strcmp(q->num, number) == 0)//比较节点中的学号是否一致 
			{ //一致输出信息 
				printf(" |---------|----------------|-----|-----|-----|-----|\n");
				printf(" |%9s|%16s|%3d  |%3d  |%3d  |%3d  |\n",
					 q->name, q->num, q->chinese, q->math, q->English, q->sum);
				printf(" |---------|----------------|-----|-----|-----|-----|\n");
				break;
			}
			q = q->next;// 不一致指向下一个节点 
		}
		if (q)//如果q！=NULL 
		{
			printf("\t\t\t是否继续查询(y or n):");
			scanf(" %c", &m);
		}
		if (q == NULL)
		{
			printf("\t\t\t无此学生\n");
			system("pause");
			break;
		}
	}
	return;
}

void ShowStudent(stud *p) //输出所有学生信息 
{
	if (p == NULL || p->next == NULL)//防止无学生信息 
	{
		printf("\t\t\t请先输入学生信息\n");
		system("pause");
		return;
	}
	stud *q = p->next;
	stud* d = p->next;
	int n = 0;
	while (q != NULL)//当q！=NULL时输出学生信息 
	{
		n++;
		q = q->next;
	}
	int i=1;
	printf("所有学生成绩如下：\n");
	printf(" |-----|---------|----------------|-----|-----|-----|-----|\n");
	printf(" | 序号|    姓名 |            学号| 语文| 数学| 英语| 总分|\n");
	while(d != NULL)
	{
		printf(" |-----|---------|----------------|-----|-----|-----|-----|\n");
		printf(" |%4d |%9s|%16s|%3d  |%3d  |%3d  |%3d  |\n",
			i ++, d->name, d->num, d->chinese, d->math, d->English, d->sum);
		d = d->next;
	}
	printf(" |-----|---------|----------------|-----|-----|-----|-----|\n");
	system("pause");
	return;
}

void Add(stud *p)//添加函数 
{
	if (p == NULL || p->next == NULL)
	{
		printf("\t\t\t请先输入学生信息\n");
		system("pause");
		return;
	}
	stud *q = p, *a = p;
	stud *insert;
	int b, n = 0;
	char m = 'y';
	while (m == 'y')
	{
		n = 0;
		q = a->next;
		while (q!=NULL)
		{
			n++;
			q = q->next;
		}
		system("cls");
		q = a;
		printf("\t\t\t您正在添加学生信息...:\n");
		if ((insert = (stud *)malloc(sizeof(stud))) == NULL)
		{
			printf("\t\t\t空间不足建立失败\n");
			exit(0);
		}
		printf("\t\t\t需要插入到第b个数据之后(0<=b<=%d):", n);
		scanf("%d", &b);
		if (b<0 || b>n)
		{
			printf("\n\t\t输入错误\n");
			system("pause");
			break;
		}
		//插入到第b个数据之后 
		for (n = 1; n <= b; n++)
			q = q->next;
		insert->next = NULL;
		printf("\t\t◎请输入学号:");
		scanf("%s", insert->num);
		printf("\t\t◎请输入姓名:");
		scanf("%s", insert->name);
		printf("\t\t◎请输入语文成绩:");
		scanf("%d", &insert->chinese);
		printf("\t\t◎请输入数学成绩:");
		scanf("%d", &insert->math);
		printf("\t\t◎请输入英语成绩:");
		scanf("%d", &insert->English);
		insert->sum = insert->chinese + insert->English + insert->math;
		insert->next = q->next;
		q->next = insert;
		printf("\t\t\t输入成功\n");
		printf("\t\t\t是否继续增添(y or n):");
		scanf(" %c", &m);
	}
	return;
}

void Del(stud *p)  //删除函数 
{
	if (p == NULL || p->next == NULL)
	{
		printf("\t\t\t请先输入学生信息\n");
		system("pause");
		return;
	}
	stud *q = p->next, *a = p->next, *h = p;//h为q的前一个节点
	char m = 'y', b[20] = { '0' }, n[20] = {'0'};
	int j;
	while (m == 'y')
	{
		if (p == NULL || p->next == NULL)
		{
			printf("\t\t\t请先输入学生信息\n");
			system("pause");
			return;
		}
		system("cls");
		q = a;
		h = p;
		printf("\t\t 		  您正在删除学生信息 ...  \n");
		printf("\t\t                                      \n");
		printf("\t\t              请选择删除方式          \n");
		printf("\t\t                                      \n");
		printf("\t\t              1.按学号删除            \n");
		printf("\t\t                                      \n");
		printf("\t\t              2.按姓名删除            \n");
		printf("\t\t                                      \n");
		printf("\t\t              0.退出                  \n");
		printf("\n");
s4:		printf("\t\t                请输入您的选择:");
		scanf("%d", &j);
		getchar();
		switch (j)
		{
		case 1:
			printf("\t\t\t请输入学号:");
			scanf("%s", b);

			while (q)
			{

				if (strcmp(q->num, b) == 0)
				{

					h->next = q->next;//使前一个节点指向后一个 
					free(q);
					printf("\t\t\t删除成功\n");
					system("pause");
					break;
				}

				h = q;//h为q的前一个节点 
				q = q->next;

			}

			if (q == NULL)
			{
				printf("\t\t\t无此学生\n");
				system("pause");
				break;
			}

			if (q)
			{
				printf("\t\t\t是否继续删除(y or n):");
				scanf(" %c", &m);
			}
			break;

		case 2:
			printf("\t\t\t请输入姓名:");
			scanf("%s", n);

			while (q)
			{
				if (strcmp(q->name, n) == 0)
				{
					h->next = q->next;//使前一个节点指向后一个 
					free(q);
					printf("\t\t\t删除成功\n");
					break;
				}
				h = q;
				q = q->next;
			}

			if (q == NULL)
			{
				printf("\t\t\t无此学生\n");
				system("pause");
				break;
			}

			if (q)
			{
				printf("\t\t\t是否继续删除(y or n):");
				scanf(" %c", &m);
			}

			break;

		case 0:
			m = 'n';
			break;

		default:
			printf("\t\t\t输入错误，请重新输入\n");
			goto s4;
			break;

		}
	}
	return;
}

void  Computer(stud *p)//输出学生平均分和总分函数； 
{
	if (p == NULL || p->next == NULL)
	{
		printf("\t\t\t请先输入学生信息\n");
		system("pause");
		return;
	}
	stud *q = p->next;
	int totalnumber = 0;
	while (q)
	{
		totalnumber++;
		printf("\t\t\t%s 同学 总分为：%d\n", q->name, q->sum);
		printf("\t\t\t          均分为:%.2f\n", (q->sum) / 3.0);
		putchar(10);
		q = q->next;
	}
	system("pause");
}

char print(stud *d)//输出学生全部信息函数； 
{
	char m = 'y';
	int i = 1;
	printf("所有学生成绩如下：\n");
	printf(" |-----|---------|----------------|-----|-----|-----|-----|\n");
	printf(" | 序号|    姓名 |            学号| 语文| 数学| 英语| 总分|\n");
	while (d != NULL)
	{
		printf(" |-----|---------|----------------|-----|-----|-----|-----|\n");
		printf(" |%4d |%9s|%16s|%3d  |%3d  |%3d  |%3d  |\n",
			i++, d->name, d->num, d->chinese, d->math, d->English, d->sum);
		d = d->next;
	}
	printf(" |-----|---------|----------------|-----|-----|-----|-----|\n");
	printf("\t\t\t是否继续查看(y or n):");
	scanf(" %c", &m);
	return m;
}

void reorder(stud **p, int x)//排序函数 
{                            
	int str[20];
	stud * cur = NULL;
	stud * _next = NULL;
	stud * tail = NULL;
	stud * h = (*p)->next;
	int count = 0;
	while (h)
	{
		count++;
		h = h->next;
	}
	cur = (*p)->next;
	switch (x)
	{
	case 1:  //总分排序

		while (cur != tail)
		{
			cur = (*p)->next;
			_next = cur->next;
			while (_next != NULL)
			{
				if ((cur->sum) < (_next->sum))
				{
					int chinese = cur->chinese;
					int English = cur->English;
					int math = cur->math;
					int sum = cur->sum;
					cur->chinese = _next->chinese;
					cur->English = _next->English;
					cur->math = _next->math;
					cur->sum = _next->sum;
					_next->chinese = chinese;
					_next->English = English;
					_next->math = math;
					_next->sum = sum;
					strcpy(str, cur->num); strcpy(cur->num, _next->num); strcpy(_next->num, str);
					strcpy(str, cur->name); strcpy(cur->name, _next->name); strcpy(_next->name, str);
				}
				cur = _next;
				_next = cur->next;
			}
			tail = cur;//每次排完，tail指针前移一位
		}
		cur = (*p)->next;
		tail = NULL;
		while (cur != tail)
		{
			cur = (*p)->next;
			_next = cur->next;
			while (_next != NULL)
			{
				if ((cur->sum) < (_next->sum))
				{
					int chinese = cur->chinese;
					int English = cur->English;
					int math = cur->math;
					int sum = cur->sum;
					cur->chinese = _next->chinese;
					cur->English = _next->English;
					cur->math = _next->math;
					cur->sum = _next->sum;
					_next->chinese = chinese;
					_next->English = English;
					_next->math = math;
					_next->sum = sum;
					strcpy(str, cur->num); strcpy(cur->num, _next->num); strcpy(_next->num, str);
					strcpy(str, cur->name); strcpy(cur->name, _next->name); strcpy(_next->name, str);
				}
				cur = _next;
				_next = cur->next;
			}
			tail = cur;//每次排完，tail指针前移一位
		}
		break;
	case 2: //语文排序 
		while (cur != tail)
		{
			cur = (*p)->next;
			_next = cur->next;
			while (_next != NULL)
			{
				if ((cur->chinese) < (_next->chinese))
				{
					int chinese = cur->chinese;
					int English = cur->English;
					int math = cur->math;
					int sum = cur->sum;
					cur->chinese = _next->chinese;
					cur->English = _next->English;
					cur->math = _next->math;
					cur->sum = _next->sum;
					_next->chinese = chinese;
					_next->English = English;
					_next->math = math;
					_next->sum = sum;
					strcpy(str, cur->num); strcpy(cur->num, _next->num); strcpy(_next->num, str);
					strcpy(str, cur->name); strcpy(cur->name, _next->name); strcpy(_next->name, str);
				}
				cur = _next;
				_next = cur->next;
			}
			tail = cur;//每次排完，tail指针前移一位
		}
		cur = (*p)->next;
		_next = cur->next;
		while (cur != tail)
		{
			cur = (*p)->next;
			_next = cur->next;
			while (_next != NULL)
			{
				if ((cur->chinese) < (_next->chinese))
				{
					int chinese = cur->chinese;
					int English = cur->English;
					int math = cur->math;
					int sum = cur->sum;
					cur->chinese = _next->chinese;
					cur->English = _next->English;
					cur->math = _next->math;
					cur->sum = _next->sum;
					_next->chinese = chinese;
					_next->English = English;
					_next->math = math;
					_next->sum = sum;
					strcpy(str, cur->num); strcpy(cur->num, _next->num); strcpy(_next->num, str);
					strcpy(str, cur->name); strcpy(cur->name, _next->name); strcpy(_next->name, str);
				}
				cur = _next;
				_next = cur->next;
			}
			tail = cur;//每次排完，tail指针前移一位
		}
		break;
	case 3:    //数学排序 
		while (cur != tail)
		{
			cur = (*p)->next;
			_next = cur->next;
			while (_next != NULL)
			{
				if ((cur->math) < (_next->math))
				{
					int chinese = cur->chinese;
					int English = cur->English;
					int math = cur->math;
					int sum = cur->sum;
					cur->chinese = _next->chinese;
					cur->English = _next->English;
					cur->math = _next->math;
					cur->sum = _next->sum;
					_next->chinese = chinese;
					_next->English = English;
					_next->math = math;
					_next->sum = sum;
					strcpy(str, cur->num); strcpy(cur->num, _next->num); strcpy(_next->num, str);
					strcpy(str, cur->name); strcpy(cur->name, _next->name); strcpy(_next->name, str);
				}
				cur = _next;
				_next = cur->next;
			}
			tail = cur;//每次排完，tail指针前移一位
			//cur = (*p)->next;
		}
		cur = (*p)->next;
		tail = NULL;
		while (cur != tail)
		{
			cur = (*p)->next;
			_next = cur->next;
			while (_next != NULL)
			{
				if ((cur->math) < (_next->math))
				{
					int chinese = cur->chinese;
					int English = cur->English;
					int math = cur->math;
					int sum = cur->sum;
					cur->chinese = _next->chinese;
					cur->English = _next->English;
					cur->math = _next->math;
					cur->sum = _next->sum;
					_next->chinese = chinese;
					_next->English = English;
					_next->math = math;
					_next->sum = sum;
					strcpy(str, cur->num); strcpy(cur->num, _next->num); strcpy(_next->num, str);
					strcpy(str, cur->name); strcpy(cur->name, _next->name); strcpy(_next->name, str);
				}
				cur = _next;
				_next = cur->next;
			}
			tail = cur;//每次排完，tail指针前移一位
		}
		break;
	case 4://英语排序 
		while (cur != tail)
		{
			cur = (*p)->next;
			_next = cur->next;
			while (_next != NULL)
			{
				if ((cur->English) < (_next->English))
				{
					int chinese = cur->chinese;
					int English = cur->English;
					int math = cur->math;
					int sum = cur->sum;
					cur->chinese = _next->chinese;
					cur->English = _next->English;
					cur->math = _next->math;
					cur->sum = _next->sum;
					_next->chinese = chinese;
					_next->English = English;
					_next->math = math;
					_next->sum = sum;
					strcpy(str, cur->num); strcpy(cur->num, _next->num); strcpy(_next->num, str);
					strcpy(str, cur->name); strcpy(cur->name, _next->name); strcpy(_next->name, str);
				}
				cur = _next;
				_next = cur->next;
			}
			tail = cur;//每次排完，tail指针前移一位
			//cur = (*p)->next;
		}
		cur = (*p)->next;
		tail = NULL;
		while (cur != tail)
		{
			cur = (*p)->next;
			_next = cur->next;
			while (_next != NULL)
			{
				if ((cur->English) < (_next->English))
				{
					int chinese = cur->chinese;
					int English = cur->English;
					int math = cur->math;
					int sum = cur->sum;
					cur->chinese = _next->chinese;
					cur->English = _next->English;
					cur->math = _next->math;
					cur->sum = _next->sum;
					_next->chinese = chinese;
					_next->English = English;
					_next->math = math;
					_next->sum = sum;
					strcpy(str, cur->num); strcpy(cur->num, _next->num); strcpy(_next->num, str);
					strcpy(str, cur->name); strcpy(cur->name, _next->name); strcpy(_next->name, str);
				}
				cur = _next;
				_next = cur->next;
			}
			tail = cur;//每次排完，tail指针前移一位
					   //cur = (*p)->next;
		}
		break;
	}
	int x1 = 0;
	return ;
}

void Compare(stud *p) //比较函数 
{
	if (p == NULL || p->next == NULL)
	{
		printf("\t\t\t请先输入学生信息\n");
		system("pause");
		return;
	}
	stud *q = p->next, *a = p->next, *d = NULL;
	char m = 'y';
	int n = 0, f, x;
	while (q)
	{
		n++;//计算总数 
		q = q->next;
	}
	while (m == 'y')
	{
		system("cls");
		printf("\t\t 您正在查看学生排名:\n\n");
		printf("\t\t 请选择查看方式\n");
		printf("\t\t 1.查询总分排序\n");
		printf("\t\t 2.查询语文排序\n");
		printf("\t\t 3.查询数学排序\n");
		printf("\t\t 4.查询英语排序\n");
		printf("\t\t 0.退出\n");
		printf("\n");
s:		printf("\t\t                请输入您的选择:");
		scanf("%d", &f);
		getchar();
		if (f < 1 || f>4)
		{
			printf("\t\t\t输入错误,请重新输入\n");
			goto s;
		}
		switch (f)
		{
		case 1:
			reorder(&p, x = 1);//相应的x的值对应相应的排序 
			m = print(p->next);
			break;
		case 2:
			reorder(&p, x = 2);
			m = print(p->next);
			break;
		case 3:
			reorder(&p, x = 3);
			m = print(p->next);
			break;
		case 4:
			reorder(&p, x = 4);
			m = print(p->next);
			break;
		case 0:
			m = 'n';
			break;
		default:
			printf("\t\t\t输入错误\n");
			system("pause");
			break;
		}
	}
	return;
}
void End()
{
	system("cls");
	printf("感谢使用学生管理系统,再见！\n");
	printf("\n");
	system("pause");
}

void circulate()
{
	stud *p = NULL;
	while (1) {
		switch (menu_select()) {
		case 1:
			p = Creat(&p);//创建
			break;
		case 2:
			Del(p);//删除
			break;
		case 3:
			Add(p);//添加
			break;
		case 4:
			ShowStudent(p);//显示所有学生成绩
			break;
		case 5:
			Compare(p);//排序
			break;
		case 6:
			Computer(p);//计算总分和平均分
			break;
		case 7:
			Search(p);//按姓名查询
			break;
		case 8:
			IndexOnNumber(p);//按学号查询
			break;
		case 9:
			End();
			return;
		default:
			printf("\t\t\t输入错误请重新输入\n");
			printf("\n");
			system("pause");
			break;
		}
	}
}