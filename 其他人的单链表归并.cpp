#include <stdlib.h>
#include <iostream>
using namespace std;

//������
typedef struct LNode
{
	int data;
	struct LNode *next;
}LNode;

//���������
void outputList(LNode *C) 
{
	LNode *list = C->next;
	while (list->next != NULL)
	{
		//����endl�ͱ�ʾ����
		cout << list->data << "->";
		list = list -> next;
	}
	cout << list->data;
}


//β�巨����������
//*&C����˼�Ǵ������һ����L�ڵ����õ�ָ��
void createListByTail(LNode *&L, int a[], int n)
{
	LNode *node, *last;	//n����ָ��������Ľڵ�,lastʼ��ָ��C���ն˽ڵ�
	L = (LNode *)malloc(sizeof(LNode));	//����C��ͷ���ռ�
	L->next = NULL;
	last = L;
	for (int i = 0; i < n; i++)	//����˳���
	{
		node = (LNode *)malloc(sizeof(LNode));
		node->data = a[i];
		last->next = node;	
		last = last->next;	//lastָ��ʼ��ָ��β�ڵ�
	}
	last->next = NULL;	//β�ڵ��nextʼ��Ϊ��
}

//ͷ�巨����������
void createListByHead(LNode *&L, int a[], int n)
{
	LNode *head, *node;	//head��ʼ��ָ��ͷ����ָ�룬node��ָ���½ڵ��ָ��
	L = (LNode *)malloc(sizeof(LNode));
	L->next = NULL;
	head = L;
	for (int i = 0; i < n; i++)
	{
		node = (LNode *)malloc(sizeof(LNode));
		node->data = a[i];
		node->next = head->next;
		head->next = node;
	}
}

//���յ���˳��鲢����
LNode* mergeList(LNode *L1, LNode *L2)
{
	//���������������ͷ���
	LNode *C = (LNode *)malloc(sizeof(LNode));
	C->next = NULL;
	LNode *p = L1->next, *q = L2->next;
	//�����ڵ�ָ�룬��ʼ��ָ�������ͷ�ڵ���ն˽ڵ㣬������β�巨
	LNode *r = C;
	while (p != NULL && q !=NULL)
	{
		//�Ƚ���ָ�뵱ǰָ��Ԫ�صĴ�С��С�ľ͹��ɵ���������ָ�����һλ
		//���������ȣ�ѡȡ��һ�����ֵ�������������
		if (p->data < q->data)
		{
			r->next = p;
			r = r->next;	//ʼ��ָ��β�ڵ�
			p = p->next;
		}
		else if (p->data == q->data)
		{
			r->next = p;
			r = r->next;
			p = p->next;
			q = q->next;
		}
		else
		{
			r->next = q;
			r = r->next;
			q = q->next;
		}
		if (p != NULL)	r->next = p;
		if (q != NULL) r->next = q;
	}
	return C;
}

int main()
{
	int a[5] = { 1,5,7,9,10 };
	int b[6] = { 8,6,5,3,2,1 };
	LNode *L1;	//β�巨��������
	LNode *L2;	//ͷ�巨��������
	createListByTail(L1, a, 5);
	cout << "β�巨����������";
	outputList(L1);
	createListByHead(L2, b,6);
	cout <<"\nͷ�巨����������";
	outputList(L2);
	cout << "\n�鲢��Ľ��Ϊ��";
	outputList(mergeList(L1, L2));
	return 0;
}

