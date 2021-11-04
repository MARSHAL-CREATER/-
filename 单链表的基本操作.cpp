#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node
{
	int data;
	struct Node *next;
 } LNode,*LinkList;


struct Node *p= NULL;//һ����ûȷ��ָ��Ľڵ�ָ�� 
int GetData (LinkList L,int i,int e);
void Insert1(LinkList L,int i,int e);
void Insert2(LinkList L,int i,int e);
void Delete(LinkList L,int i);
void Create1(LinkList &L,int n);
void Create2(LinkList &L,int n);
void Print(LinkList L,int m);
void menu(); 

 int main()
 { 
    int operation;
    int m,n,o,q,l,tmp;
	LinkList L;
	while(1){
	system("cls"); 
    menu(); 
	printf("��������Ҫ�����Ķ�Ӧ��ţ�");
    scanf("%d", &operation);
    if(operation==0) {
	printf ("ллʹ��\n");break;}
    switch(operation){
    case 1: 
        printf("��������Ҫ�����Ľڵ�����"); 
        scanf("%d",&m);
        printf("����������ڵ����ֵ��"); 
 	    Create1(L, m);
        break;
    case 2:
        printf("\n��������Ҫ�����ĸ�λ�����֣�");
 	    scanf("%d",&o);
 	    tmp=GetData(L,o,tmp);
 	    printf("\n��ǰ�ڵ��ֵΪ��%d",tmp);
        break;
    case 3:
        printf("\n��������Ҫ�ĸ��ڵ����룺");
	    scanf("%d",&n);
	    printf("\n��������Ҫ��������֣�");
	    scanf("%d",&l); 
 	    Insert1(L,n,l);
 	    m+=1; 
        break;
    case 4:
    	printf("\n��������Ҫɾ���ĸ�λ�����֣�");
 	    scanf("%d",&q);
 	    Delete(L,q);
 	    m-=1; 
 	    break;
 	case 5:
	    printf("��ǰ�����ֵΪ��");
 	    Print(L,m);
		break; 
    case 0:
        break;
    default:
        printf ("�������\n");
        break;
    }
    system("pause"); 
   }
 	return 0; 
 }
 //����-----��λ����� 
 int GetData (LinkList L,int i,int e)
 {
 	p=L->next;
	int j=1;
 	while(p&&j<i)
 	{
 	p=p->next ;++j;	
	 }
 if(!p||j>i) exit(1);
	 e=p->data ;
	 return e;
 }
 //����-----�ڵ�i��Ԫ�غ���루����������i+1��λ�ã� 
void Insert1(LinkList L,int i,int e)
 {
 	p=L;
 	int j=0;
 	while(p&&j<i)
 	{
	 p=p->next ;++j; 
	 } //Ѱ�ҵ�i���ڵ� 
	if(!p||j>i)  exit(1);
	
	LNode *s=NULL;
	s=(LinkList)malloc(sizeof(Node)); //�����½ڵ� 
	s->data =e;
	s->next =p->next; 
	p->next =s;
 }
 
//����-----�ڵ�i��Ԫ��ǰ���루����������i��λ�ã� 
void Insert2(LinkList L,int i,int e)
 {
 	p=L;
 	int j=0;
 	while(p&&j<i-1)
 	{
	 p=p->next ;++j; 
	 } //Ѱ�ҵ�i-1���ڵ� 
	if(!p||j>i-1)  exit(1);
	
	LNode *s=NULL;
	s=(LinkList)malloc(sizeof(Node)); //�����½ڵ� 
	s->data =e;
	s->next =p->next ;
	p->next =s;
 } 
 
 //ɾ����i��Ԫ�� 
 void Delete(LinkList L,int i)
 {
 	p=L;
 	int j=0;int e;
 	while(p->next&&j<i-1)
 	{
 		p=p->next ;++j;
	 }//��pָ���i-1���ڵ�
	 if (!(p->next )||j>i-1) exit(1);
	 LNode *s= NULL;//LinkList s=NULL;
	 s=(LinkList)malloc(sizeof(Node));
	 s=p->next;p->next =s->next;
	 e=s->data ;free(s);   
 }
 //������Ĵ�����β�巨��˳������� 
 void Create1(LinkList &L,int n)
 {  
    L=(LinkList)malloc(sizeof(Node));
	LinkList T=(LinkList)malloc(sizeof(Node));
	T=L;//��Tָ��ͷ�ڵ�	
 	L->next=NULL;//����һ����ͷ�ڵ�ĵ����� 
 	for(int i=0;i<n;++i)
 	{
 	LNode *s=NULL;
	s=(LinkList)malloc(sizeof(Node));
	scanf("%d",&(s->data));
    s->next=NULL;
	T->next=s;
	T=s; 
	}
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
 //�˵����� 
 void menu()
{
    printf ("\t    ���������������ʵ��\n");
    printf ("========================================\n");
    printf ("\t1.������Ĵ�����β�巨��\n");
    printf ("\t2.���ҵ�i���ڵ��ֵ\n");
    printf ("\t3.�ڵ�i��Ԫ�غ����һ���½ڵ�\n");
    printf ("\t4.ɾ����i���ڵ�\n");
    printf ("\t5.������������ڵ�ֵ\n");
    printf ("\t0.�˳�ϵͳ\n");
    printf ("========================================\n");
} 
 
 
 
