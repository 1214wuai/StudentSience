#pragma warning(disable:4996)

#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
#include<assert.h>

typedef	struct student {
	char num[20];//ѧ�� 
	char name[20];
	int  chinese;
	int  math;
	int  English;
	int  sum;//�ܷ� 
	struct student *next;//���������ʽ�洢
} stud;

int menu_select();//�˵�ѡ���� 
void circulate();//ѭ��ѡ���� 
stud* Creat(stud** p);//¼��ģ�� 
void ShowStudent(stud *p);//��ʾģ�� 
void Search(stud *p);//��������ѯģ�� 
void IndexOnNumber(stud *p);//��ѧ�Ų�ѯģ�� 
void reorder(stud **p, int x);//������ 
char print(stud *d);//������� 
void  Computer(stud *p);//ͳ��ģ�� 
void End();//�������� 

int main()
{
	system("color F0");//����ɫ ��ɫ
	circulate();
	return 0;
}

int menu_select() {//�˵����桢����ѡ�� 
	int c;
	system("cls");
	printf("\n");
	printf("\t\t    ��ӭʹ��ѧ���ɼ�����ϵͳ    \n");
	printf("\t\t                                \n");
	printf("\t\t         1.����ѧ����Ϣ         \n");
	printf("\t\t                                \n");
	printf("\t\t         2.ɾ��ѧ����Ϣ         \n");
	printf("\t\t                                \n");
	printf("\t\t         3.����ѧ����Ϣ         \n");
	printf("\t\t                                \n");
	printf("\t\t         4.��ʾ����ѧ����Ϣ     \n");
	printf("\t\t                                \n");
	printf("\t\t         5.ѧ���ɼ�����         \n");
	printf("\t\t                                \n");
	printf("\t\t         6.�����ֺܷ�ƽ����     \n");
	printf("\t\t                                \n");
	printf("\t\t         7.������������ѧ����Ϣ \n");
	printf("\t\t                                \n");
	printf("\t\t         8.����ѧ�Ų���ѧ����Ϣ \n");
	printf("\t\t                                \n");
	printf("\t\t         9.�˳�ϵͳ             \n");
	printf("\n");
s1:	printf("\t\t   (����������1~9): ");
	scanf("%d", &c);
	getchar();
	if (c < 1 || c>9)
	{
		printf("\t\t ��Ч�����룬����������\n");
		c = 0;
		goto s1;
	}
	return c;
}

stud* Creat(stud** p) //������������һ������ѧ����Ϣ 
{
	if (*p != NULL)
	{
		printf("ϵͳ�Ѿ������������ٴ�������\n");
		system("pause");
		return *p;
	}
	system("cls");//��������
	printf("\t\t              HELLO������������ѧ����Ϣ...     \n\n");
	printf("\t\t              �������ʾ����ѧ����Ϣ:      \n\n");
	int i, j;
	stud *head, *p1, *p2;
s3:	printf("\t\t\t  ������������:");
	scanf("%d", &i);
	getchar();
	if (i <= 0)
	{
		printf("\t\t\t�������,����������\n");
		goto s3;
	}
	if ((head = (stud *)malloc(sizeof(stud))) == NULL)//����ͷָ�� 
	{
		printf("\t\t\t�ռ䲻�㽨��ʧ��\n");
		exit(0);
	}
	head->next = NULL;
	p1 = head;
	for (j = 0; j<i; j++)
	{
		if ((p2 = (stud *)malloc(sizeof(stud))) == NULL)//�����µĽڵ� 
		{
			printf("\t\t\t�ռ䲻�㽨��ʧ��\n");
			exit(0);
		}
		//����ѧ����Ϣ 
		printf("\t\t�����������%d���˵���Ϣ\n", j + 1);
		printf("\t\t ��������ѧ��:");
		scanf("%s", p2->num);
		printf("\t\t ������������:");
		scanf("%s", p2->name);
		printf("\t\t �����������ĳɼ�:");
		scanf("%d", &p2->chinese);
		printf("\t\t ����������ѧ�ɼ�:");
		scanf("%d", &p2->math);
		printf("\t\t ��������Ӣ��ɼ�:");
		scanf("%d", &p2->English);
		p2->sum = p2->chinese + p2->English + p2->math;
		//ʹ��һ���ڵ�ָ����һ���ڵ� 
		p1->next = p2;
		p2->next = NULL;//ʹ���ڵ�nextΪ�� 
		p1 = p2;//p1ָ�����һ���ڵ�
		if (i >= 3 && (j + 1) % 2 == 0) system("cls");
	}
	printf("\t\t�ѳɹ�����ѧ����Ϣ\n");
	system("pause");
	*p = head;
	return *p;//����ͷָ�� 
}

void Search(stud *p) //��������ѯ����  
{ //��ͷָ����� 
	if (p == NULL || p->next == NULL)//��ֹ��ѧ����Ϣ 
	{
		printf("\t\t\t��������ѧ����Ϣ\n");
		system("pause");
		return;
	}
	stud *q = p->next, *a = p->next;
	char name[20] = {'0'};
	//char b[20] = { '0' };
	char m = 'y';
	while (m == 'y')//��m=��y��ʱѭ�� 
	{
		q = a;//ÿ��ѭ������ָ��q 
		system("cls");
		printf("\t\t\t����������:");
		scanf("%s", name);
		printf("\n");
		while (q)
		{
			if (strcmp(q->name, name) == 0)//�ȽϽڵ��е������Ƿ�һ��
			{
				printf(" |---------|----------------|-----|-----|-----|-----|\n");
				printf(" |%9s|%16s|%3d  |%3d  |%3d  |%3d  |\n",
					q->name, q->num, q->chinese, q->math, q->English, q->sum);
				printf(" |---------|----------------|-----|-----|-----|-----|\n");
				break;
			}
			else  q = q->next;
		}
		if (q)//��ͬ��q!=NULL; 
		{
			printf("\t\t\t�Ƿ������ѯ(y or n):");
			scanf(" %c", &m);
		}
		if (q == NULL)
		{
			printf("\t\t\t�޴�ѧ��\n");
			system("pause");
			break;
		}
	}
	return;
}

void IndexOnNumber(stud *p)//��ѧ�Ų�ѯ���� 
{
	if (p == NULL || p->next == NULL)//��ֹ��ѧ����Ϣ 
	{
		printf("\t\t\t��������ѧ����Ϣ\n");
		system("pause");
		return;
	}
	stud *q = p->next, *a = p->next;
	char number[20] = { '0' };
	char m = 'y';
	while (m == 'y')
	{
		printf("\t\t\t������ѧ��:");
		scanf("%s", number);
		printf("\n");
		while (q)
		{
			if (strcmp(q->num, number) == 0)//�ȽϽڵ��е�ѧ���Ƿ�һ�� 
			{ //һ�������Ϣ 
				printf(" |---------|----------------|-----|-----|-----|-----|\n");
				printf(" |%9s|%16s|%3d  |%3d  |%3d  |%3d  |\n",
					 q->name, q->num, q->chinese, q->math, q->English, q->sum);
				printf(" |---------|----------------|-----|-----|-----|-----|\n");
				break;
			}
			q = q->next;// ��һ��ָ����һ���ڵ� 
		}
		if (q)//���q��=NULL 
		{
			printf("\t\t\t�Ƿ������ѯ(y or n):");
			scanf(" %c", &m);
		}
		if (q == NULL)
		{
			printf("\t\t\t�޴�ѧ��\n");
			system("pause");
			break;
		}
	}
	return;
}

void ShowStudent(stud *p) //�������ѧ����Ϣ 
{
	if (p == NULL || p->next == NULL)//��ֹ��ѧ����Ϣ 
	{
		printf("\t\t\t��������ѧ����Ϣ\n");
		system("pause");
		return;
	}
	stud *q = p->next;
	stud* d = p->next;
	int n = 0;
	while (q != NULL)//��q��=NULLʱ���ѧ����Ϣ 
	{
		n++;
		q = q->next;
	}
	int i=1;
	printf("����ѧ���ɼ����£�\n");
	printf(" |-----|---------|----------------|-----|-----|-----|-----|\n");
	printf(" | ���|    ���� |            ѧ��| ����| ��ѧ| Ӣ��| �ܷ�|\n");
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

void Add(stud *p)//��Ӻ��� 
{
	if (p == NULL || p->next == NULL)
	{
		printf("\t\t\t��������ѧ����Ϣ\n");
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
		printf("\t\t\t���������ѧ����Ϣ...:\n");
		if ((insert = (stud *)malloc(sizeof(stud))) == NULL)
		{
			printf("\t\t\t�ռ䲻�㽨��ʧ��\n");
			exit(0);
		}
		printf("\t\t\t��Ҫ���뵽��b������֮��(0<=b<=%d):", n);
		scanf("%d", &b);
		if (b<0 || b>n)
		{
			printf("\n\t\t�������\n");
			system("pause");
			break;
		}
		//���뵽��b������֮�� 
		for (n = 1; n <= b; n++)
			q = q->next;
		insert->next = NULL;
		printf("\t\t��������ѧ��:");
		scanf("%s", insert->num);
		printf("\t\t������������:");
		scanf("%s", insert->name);
		printf("\t\t�����������ĳɼ�:");
		scanf("%d", &insert->chinese);
		printf("\t\t����������ѧ�ɼ�:");
		scanf("%d", &insert->math);
		printf("\t\t��������Ӣ��ɼ�:");
		scanf("%d", &insert->English);
		insert->sum = insert->chinese + insert->English + insert->math;
		insert->next = q->next;
		q->next = insert;
		printf("\t\t\t����ɹ�\n");
		printf("\t\t\t�Ƿ��������(y or n):");
		scanf(" %c", &m);
	}
	return;
}

void Del(stud *p)  //ɾ������ 
{
	if (p == NULL || p->next == NULL)
	{
		printf("\t\t\t��������ѧ����Ϣ\n");
		system("pause");
		return;
	}
	stud *q = p->next, *a = p->next, *h = p;//hΪq��ǰһ���ڵ�
	char m = 'y', b[20] = { '0' }, n[20] = {'0'};
	int j;
	while (m == 'y')
	{
		if (p == NULL || p->next == NULL)
		{
			printf("\t\t\t��������ѧ����Ϣ\n");
			system("pause");
			return;
		}
		system("cls");
		q = a;
		h = p;
		printf("\t\t 		  ������ɾ��ѧ����Ϣ ...  \n");
		printf("\t\t                                      \n");
		printf("\t\t              ��ѡ��ɾ����ʽ          \n");
		printf("\t\t                                      \n");
		printf("\t\t              1.��ѧ��ɾ��            \n");
		printf("\t\t                                      \n");
		printf("\t\t              2.������ɾ��            \n");
		printf("\t\t                                      \n");
		printf("\t\t              0.�˳�                  \n");
		printf("\n");
s4:		printf("\t\t                ����������ѡ��:");
		scanf("%d", &j);
		getchar();
		switch (j)
		{
		case 1:
			printf("\t\t\t������ѧ��:");
			scanf("%s", b);

			while (q)
			{

				if (strcmp(q->num, b) == 0)
				{

					h->next = q->next;//ʹǰһ���ڵ�ָ���һ�� 
					free(q);
					printf("\t\t\tɾ���ɹ�\n");
					system("pause");
					break;
				}

				h = q;//hΪq��ǰһ���ڵ� 
				q = q->next;

			}

			if (q == NULL)
			{
				printf("\t\t\t�޴�ѧ��\n");
				system("pause");
				break;
			}

			if (q)
			{
				printf("\t\t\t�Ƿ����ɾ��(y or n):");
				scanf(" %c", &m);
			}
			break;

		case 2:
			printf("\t\t\t����������:");
			scanf("%s", n);

			while (q)
			{
				if (strcmp(q->name, n) == 0)
				{
					h->next = q->next;//ʹǰһ���ڵ�ָ���һ�� 
					free(q);
					printf("\t\t\tɾ���ɹ�\n");
					break;
				}
				h = q;
				q = q->next;
			}

			if (q == NULL)
			{
				printf("\t\t\t�޴�ѧ��\n");
				system("pause");
				break;
			}

			if (q)
			{
				printf("\t\t\t�Ƿ����ɾ��(y or n):");
				scanf(" %c", &m);
			}

			break;

		case 0:
			m = 'n';
			break;

		default:
			printf("\t\t\t�����������������\n");
			goto s4;
			break;

		}
	}
	return;
}

void  Computer(stud *p)//���ѧ��ƽ���ֺ��ֺܷ����� 
{
	if (p == NULL || p->next == NULL)
	{
		printf("\t\t\t��������ѧ����Ϣ\n");
		system("pause");
		return;
	}
	stud *q = p->next;
	int totalnumber = 0;
	while (q)
	{
		totalnumber++;
		printf("\t\t\t%s ͬѧ �ܷ�Ϊ��%d\n", q->name, q->sum);
		printf("\t\t\t          ����Ϊ:%.2f\n", (q->sum) / 3.0);
		putchar(10);
		q = q->next;
	}
	system("pause");
}

char print(stud *d)//���ѧ��ȫ����Ϣ������ 
{
	char m = 'y';
	int i = 1;
	printf("����ѧ���ɼ����£�\n");
	printf(" |-----|---------|----------------|-----|-----|-----|-----|\n");
	printf(" | ���|    ���� |            ѧ��| ����| ��ѧ| Ӣ��| �ܷ�|\n");
	while (d != NULL)
	{
		printf(" |-----|---------|----------------|-----|-----|-----|-----|\n");
		printf(" |%4d |%9s|%16s|%3d  |%3d  |%3d  |%3d  |\n",
			i++, d->name, d->num, d->chinese, d->math, d->English, d->sum);
		d = d->next;
	}
	printf(" |-----|---------|----------------|-----|-----|-----|-----|\n");
	printf("\t\t\t�Ƿ�����鿴(y or n):");
	scanf(" %c", &m);
	return m;
}

void reorder(stud **p, int x)//������ 
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
	case 1:  //�ܷ�����

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
			tail = cur;//ÿ�����꣬tailָ��ǰ��һλ
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
			tail = cur;//ÿ�����꣬tailָ��ǰ��һλ
		}
		break;
	case 2: //�������� 
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
			tail = cur;//ÿ�����꣬tailָ��ǰ��һλ
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
			tail = cur;//ÿ�����꣬tailָ��ǰ��һλ
		}
		break;
	case 3:    //��ѧ���� 
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
			tail = cur;//ÿ�����꣬tailָ��ǰ��һλ
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
			tail = cur;//ÿ�����꣬tailָ��ǰ��һλ
		}
		break;
	case 4://Ӣ������ 
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
			tail = cur;//ÿ�����꣬tailָ��ǰ��һλ
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
			tail = cur;//ÿ�����꣬tailָ��ǰ��һλ
					   //cur = (*p)->next;
		}
		break;
	}
	int x1 = 0;
	return ;
}

void Compare(stud *p) //�ȽϺ��� 
{
	if (p == NULL || p->next == NULL)
	{
		printf("\t\t\t��������ѧ����Ϣ\n");
		system("pause");
		return;
	}
	stud *q = p->next, *a = p->next, *d = NULL;
	char m = 'y';
	int n = 0, f, x;
	while (q)
	{
		n++;//�������� 
		q = q->next;
	}
	while (m == 'y')
	{
		system("cls");
		printf("\t\t �����ڲ鿴ѧ������:\n\n");
		printf("\t\t ��ѡ��鿴��ʽ\n");
		printf("\t\t 1.��ѯ�ܷ�����\n");
		printf("\t\t 2.��ѯ��������\n");
		printf("\t\t 3.��ѯ��ѧ����\n");
		printf("\t\t 4.��ѯӢ������\n");
		printf("\t\t 0.�˳�\n");
		printf("\n");
s:		printf("\t\t                ����������ѡ��:");
		scanf("%d", &f);
		getchar();
		if (f < 1 || f>4)
		{
			printf("\t\t\t�������,����������\n");
			goto s;
		}
		switch (f)
		{
		case 1:
			reorder(&p, x = 1);//��Ӧ��x��ֵ��Ӧ��Ӧ������ 
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
			printf("\t\t\t�������\n");
			system("pause");
			break;
		}
	}
	return;
}
void End()
{
	system("cls");
	printf("��лʹ��ѧ������ϵͳ,�ټ���\n");
	printf("\n");
	system("pause");
}

void circulate()
{
	stud *p = NULL;
	while (1) {
		switch (menu_select()) {
		case 1:
			p = Creat(&p);//����
			break;
		case 2:
			Del(p);//ɾ��
			break;
		case 3:
			Add(p);//���
			break;
		case 4:
			ShowStudent(p);//��ʾ����ѧ���ɼ�
			break;
		case 5:
			Compare(p);//����
			break;
		case 6:
			Computer(p);//�����ֺܷ�ƽ����
			break;
		case 7:
			Search(p);//��������ѯ
			break;
		case 8:
			IndexOnNumber(p);//��ѧ�Ų�ѯ
			break;
		case 9:
			End();
			return;
		default:
			printf("\t\t\t�����������������\n");
			printf("\n");
			system("pause");
			break;
		}
	}
}