#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node
{
	int data;
	struct Node *next;
 } LNode,*LinkList;
 
 void Create2(LinkList &L,int n);
 void Print(LinkList L,int m);
LNode* MergeList(LinkList L,LinkList M);


struct Node *p= NULL; 
 int main()
 {
 	LinkList L,M,N;
 	//L=(LinkList)malloc(sizeof(Node));
 	//M=(LinkList)malloc(sizeof(Node));
 	
 	int m,n;
 	
 	printf("��������Ҫ�����Ľڵ�����"); 
    scanf("%d",&m);
    printf("����������ڵ����ֵ��");
    Create2(L,m);
    printf("��ǰLA�����ֵΪ��");
 	Print(L,m);
 	
    printf("\n��������Ҫ�����Ľڵ�����"); 
    scanf("%d",&n);
    printf("����������ڵ����ֵ��");
	Create2(M,n);
	printf("\n��ǰLB�����ֵΪ��");
 	Print(M,n);
 	
 	//Create2(N,n+m,0);
	
	printf("\n�ϲ���LC�����ֵΪ��");
 	Print(MergeList( L, M),m+n); 
 
 
 system("pause"); 
 }
 //������Ĵ�����ͷ�巨����������� 
 void Create2(LinkList &L,int n)
 {  
    L=(LinkList)malloc(sizeof(Node));
 	L->next=NULL;//����һ����ͷ�ڵ�ĵ����� 
 	for(int i=0;i<n;++i)
 	{
 	LNode *s=NULL;
	s=(LinkList)malloc(sizeof(Node));
	scanf("%d",&(s->data));
    s->next=L->next;
    L->next=s; 
	}
 }
 //�鲢������������ 
LNode* MergeList(LinkList L,LinkList M)
{
 LNode* N=(LinkList)malloc(sizeof(Node));
 N->next =NULL;
 LNode* pa=L->next;LNode* pb=M->next;
 LNode* pc=N;
 while(pa&&pb)
 {
   if(pa->data  >=pb->data )	
   {pc->next =pa;pc=pc->next ;pa=pa->next ;}
   else
   {pc->next =pb;pc=pc->next ;pb=pb->next ;} 
 	
 }
 pc->next =pa?pa:pb; 
return N;
} 
 //������ı������
 void Print(LinkList L,int m)
 {
   p=L->next;//L��ͷ�ڵ㣬������pָ���׽ڵ� 
   for(int i=0;i<m;i++)	
   {
   	printf("%d\t",p->data );
   	p=p->next ;
   }	
 }


  
