#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100  //�洢���� 

typedef int SElemType;
typedef int Status;
typedef struct {
int front;//��ͷָ�� 
int rear;//��βָ��	
SElemType* data;//�洢����ַ	
}SqQueue;

Status InitQueue(SqQueue &S);//��ʼ��Ϊ�ն��� 
Status EmptyQueue(SqQueue S);//�ж϶����Ƿ�Ϊ��
Status EnterQueue(SqQueue &S,SElemType e); //Ԫ�����
Status DeQueue(SqQueue &S,SElemType &e); //Ԫ�س��ӣ�����e���س���Ԫ��
Status GetFront(SqQueue &S,SElemType &e);//ȡ��ͷԪ��,����e���ض�ͷԪ�� 
Status PrintQueue(SqQueue S);//��������
int QueueLength(SqQueue S); //��ӳ�
 
int main()
{
	SqQueue S;
	int front;
	InitQueue(S);
	EmptyQueue(S);
	EnterQueue(S,100);
	EnterQueue(S,120);
	EnterQueue(S,170);
	PrintQueue(S);
	EmptyQueue(S);
	GetFront(S,front);
	DeQueue(S,front);
	EnterQueue(S,300);
	PrintQueue(S);
	
	system("pause");
	return 0;
}
//��ʼ��
Status InitQueue(SqQueue &S)
{
  S.data=(SElemType*)malloc(MAXSIZE *sizeof(SElemType));	
  if(!S .data) exit(1);
  S.front=S.rear=0;
  return 0;	
}
//�ж϶����Ƿ�Ϊ��
Status EmptyQueue(SqQueue S)
{
   	if(S.front==S.rear )
	printf("����Ϊ��\n");
	else
	printf("���в�ΪΪ��\n");
	return 0; 
 }
 //Ԫ�����
 Status EnterQueue(SqQueue &S,SElemType e)
 {
 	if((S.rear+1)%MAXSIZE==S.front ) exit(1);//��β����һ���Ƕ�ͷ������� 
  	S.data[S.rear]=e;
  	S.rear=(S.rear+1)%MAXSIZE;//����ѭ������ 
  	return 0;	
  } 
  //Ԫ�س��ӣ�����e���س���Ԫ�� 
  Status DeQueue(SqQueue &S,SElemType &e)
  {
  	if(S.front==S.rear ) exit(1);
  	e=S.data[S.front];
	S.data[S.front]=0; 
  	S.front=(S.front+1)%MAXSIZE;//����ѭ������ 
  	return 0;	
   }
 //ȡ��ͷԪ��,����e���ض�ͷԪ�� 
 Status GetFront(SqQueue &S,SElemType &e)
 {
   if(S.front==S.rear ) exit(1);	
   else
   printf("��ͷԪ��Ϊ%d\n",S.data[S.front]);
   e=S.data[S.front];	
   return 0;	
  } 
//��������
Status PrintQueue(SqQueue S)
{
  if(S.front==S.rear ) exit(1);
  for(int i=S.front;i<=S.rear-1;i++)	
  printf(" %d\t",S.data[i]);		
 } 
 //��ӳ� 
int QueueLength(SqQueue S) 
{
 return(S.rear -S.front +MAXSIZE)%MAXSIZE;	
	
}
