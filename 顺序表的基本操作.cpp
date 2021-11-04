#include <stdio.h>
#include <stdlib.h>
#define List_Init_Size 100
#define ListIncrement 10
typedef struct {
int *elem;//�洢����ַ 
int length;//��ǰ�� 
int listsize;//��ǰ�洢���� 

} SqList;
int* p=NULL;int* q=NULL;
void InitList(SqList *L,int m);
void PrintList(SqList *L,int m);
void ListIinsert(SqList *L,int i,int e);
void ListDelete(SqList *L,int i);
void menu();

int LocateElem(SqList *L,int e);

int main()
{   int m,n,e;int a,b,tmp;
    SqList *L=(SqList*)malloc(List_Init_Size*sizeof(int));//��printf("%D",sizeof(L));�õ�Ϊ8 
    int operation;
    while(1){
	system("cls"); 
    menu(); 
	printf("��������Ҫ�����Ķ�Ӧ��ţ�");
    scanf("%d", &operation);
    if(operation==0) {
	printf ("ллʹ��\n");break;}
    switch(operation){
    case 1: 
        printf("�������ʼҪ����˳�����;");
        scanf("%d",&m);
        printf("�������ʼҪ˳���;");
	    InitList( L,m);
        break;
    case 2:
        printf("��������Ҫ���ҵ�ֵ;");
	    scanf("%d",&b);
	    tmp=LocateElem(L, b);
	    printf("��ǰҪ���ֵ�ڵ�%dλ��",tmp);
        break;
    case 3:
        printf("��������Ҫ����λ��;");
	    scanf("%d",&n);
	    printf("��������Ҫ����λ�õ�ֵ;");
	    scanf("%d",&e);
	    ListIinsert(L,n,e);
        break;
    case 4:
    	printf("��������Ҫɾ��λ��;");
	    scanf("%d",&a);
	    ListDelete(L,a);
 	    break;
 	case 5:
	    printf("��ǰ˳����ֵΪ��");
 	    PrintList( L,m);
		break; 
    case 0:
        break;
    default:
        printf ("�������\n");
        break;
    }
    system("pause"); 
   }
    free(L);
	return 0;
}
//����˳��� 
void InitList(SqList *L,int m)
{
 L->elem=(int*)malloc(List_Init_Size *sizeof(int));
 if(!L->elem) exit(1);//�洢����ʧ��
 L->length =0;        //�ձ���Ϊ0 
 L->listsize =List_Init_Size;//��ʼ�洢����
 for (int i=1;i<=m;i++)
 {
 	scanf("%d",&L->elem[i-1] );
 	L->length++;
 
  }
 return ; 	
 }
 // ˳���Ĳ��� 
 void ListIinsert(SqList *L,int i,int e)
 {
 	if(i<1||i>L->length+1) exit(1);//����λ�ò��Ϸ�
	if(L->length>L->listsize )
	{
	 int *newbase=NULL;
	 newbase=(int*)realloc(L->elem ,(L->listsize+ListIncrement)*sizeof(int));
	 if(!newbase) exit(1);
	 L->elem=newbase;//�»�ַ
	 L->listsize+=ListIncrement;//�������� 
	 } 
	 q=&(L->elem[i-1]);
	 for(p=&(L->elem[L->length]);p>=q;--p)
	 	*(p+1)=*p;//˳���Ԫ�شӺ���ǰ���κ���һ����λ 
		*q=e;++L->length; 
	 	return ; 	
  } 
  //˳����ɾ��
  void ListDelete(SqList *L,int i)
  {
  	if(i<1||i>L->length+1) exit(1);//ɾ��λ�ò��Ϸ�
  	p=&(L->elem[i-1]);
	q=L->elem+L->length ;
	for(++p;p<=q;++p)
		*(p-1)=*p;//��ɾ��λ��֮��Ԫ������ǰ��һ����λ 
		--L->length;
		return;	
   } 
   //˳���Ĳ���
   int LocateElem(SqList *L,int e)
   {
   	int i=1;
   	p=L->elem;
   	while((i<=L->length )&&!(*p==e)) {++i;p++;} 
   	if(i<=L->length ) return i;
   	else exit(1);
	}

	//�������˳���
	void PrintList(SqList *L,int m)
	{
	 int i;
	 printf("��ǰ˳����ֵΪ:\n");
	 for(i=1;i<=L->length ;i++)
	 {
	 	printf("\t%d\t",L->elem[i-1]);
	 }
	 }
	  //�˵����� 
 void menu()
{
    printf ("\t    ˳������������ʵ��\n");
    printf ("========================================\n");
    printf ("\t1.˳���Ĵ���\n");
    printf ("\t2.���ҵ�i��λ�õ�ֵ\n");
    printf ("\t3.�ڵ�i��Ԫ��֮ǰ����һ����ֵ\n");
    printf ("\t4.ɾ����i��λ��\n");
    printf ("\t5.������������ڵ�ֵ\n");
    printf ("\t0.�˳�ϵͳ\n");
    printf ("========================================\n");
}  
 
