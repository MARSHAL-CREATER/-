#include <stdio.h>
#include <stdlib.h>
#define List_Init_Size 100
#define ListIncrement 10
typedef struct {
int *elem;//�洢����ַ 
int length;//��ǰ�� 
int listsize;//��ǰ�洢���� 

} SqList;
void InitList(SqList &L,int m);// void InitList(SqList *L,int m)ǰ���������ö�ʵ�ν��в�������������ָ��ʵ��ͬ��Ч�������Ƿ�����ͬ 
SqList MergeList(SqList L,SqList M,SqList N); 
	void PrintList(SqList L);

int main() 
{ int m,n;
  SqList L;// SqList *L=(SqList*)malloc(List_Init_Size*sizeof(int)); 
  printf("\n�������ʼҪ����˳�����;");
  scanf("%d",&m);
  printf("�������ʼ˳���ֵ��");
  InitList( L,m);//InitList( &L,m); 
  printf("��ǰLA˳����ֵΪ��");
  PrintList( L);
  
  SqList M;
  printf("\n�������ʼҪ����˳�����;");
  scanf("%d",&n);
  printf("�������ʼ˳���ֵ��");
  InitList( M,n);//InitList( &M,m); 
  printf("��ǰLB˳����ֵΪ��");
  PrintList( M);
  
  SqList N;
  //MergeList(L,M,N);
  printf("\n�鲢��LC˳���Ϊ��"); 
  PrintList(MergeList(L,M,N) );
  		
  system("pause");
}
//����˳��� 
void InitList(SqList &L,int m)// void InitList(SqList *L,int m)
{
 L .elem=(int*)malloc(List_Init_Size *sizeof(int));
 if(!L .elem) exit(1);//�洢����ʧ��
 L .length =0;        //�ձ���Ϊ0 
 L .listsize =List_Init_Size;//��ʼ�洢����
 for (int i=1;i<=m;i++)
 {
 	scanf("%d",&L .elem[i-1] );//���������ô�ַ ������βα���Ϊָ�� 
 	L .length++;
 
  }
 return ; 	
 }
 	//�������˳���
	void PrintList(SqList L)
	{
	 int i;

	 for(i=1;i<=L .length ;i++)
	 {
	 	printf("\t%d\t",L .elem[i-1]);
	 }
	 }
	 //�鲢����˳��� 
SqList MergeList(SqList L,SqList M,SqList N)
	 {
	 	 if(!L .elem ||! M .elem){
         exit(1);
        }
	 	N .listsize=N .length=L .length+M .length ;
	 	N .elem =(int*)malloc(N .listsize*sizeof(int));
	 	int* pa=L .elem  ;
	 	int* pb=M .elem  ;
	 	int* pc=N .elem  ;
		if(!N .elem )exit(1);
		 int* pa_last=L .elem +L .length -1;
		 int* pb_last=M .elem +M .length-1;
		 while(pa<=pa_last&&pb<=pb_last){
		 	if(*pa>=*pb ) *pc++=*pa++;
		 	else *pc++=*pb++;	
		 }
	 while(pa<=pa_last)	*pc++=*pa++;
	 while(pb<=pb_last)	*pc++=*pb++;
	 return N;	
	 
	 }

