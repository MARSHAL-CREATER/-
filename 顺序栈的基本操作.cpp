#include <stdio.h>
#include <stdlib.h>

#define STACK_INIT_SIZE 100//��ʼ�洢���� 
#define STACKINCREMENT  10//�洢��������
#define OVERFLOW 1
#define ERROR    1
#define OK       0

typedef int SElemType;
typedef int Status;
typedef struct{
SElemType *base;//��ջ����֮ǰ������֮��baseֵΪnull 
SElemType *top;//ջ��ָ�� 
int stacksize;//��ǰ�ѷ���Ĵ洢���� 
} SqStack;

 Status InitStack(SqStack &S);//����һ����ջ
 Status Push(SqStack &S,SElemType e); //PUSH��ջ
 Status PrintStack(SqStack S);  //�������ջ��Ԫ��
 Status GetTop(SqStack S,SElemType &e); //��ȡջ��Ԫ��,����ֵ����e 
 Status ClearStack(SqStack &S); //�ÿ�ջ
 Status Pop(SqStack &S,SElemType &e);//ɾ��ջ��Ԫ�� 
 
int main()
{
  SElemType top;
  SqStack S;
  InitStack(S);
  Push(S,100);
  Push(S,120);
  Push(S,160); 	
  PrintStack(S);
  GetTop( S,top);
  printf("\n%d\n",top);	
  Pop(S,top);	
  PrintStack(S);
  ClearStack(S);
  	
  system("pause");
  return 0;
 }
 //����һ����ջ
 Status InitStack(SqStack &S)
 {
 	S.base=(SElemType*)malloc(STACK_INIT_SIZE*sizeof(SElemType));
 	if(!S.base ) exit(OVERFLOW);//�洢����ʧ��
	 S.top =S.base ;
	 S.stacksize =STACK_INIT_SIZE; 
 	 return OK;
  } 
  //PUSH��ջ
  Status Push(SqStack &S,SElemType e) 
  {
  if(S.top -S.base >=S.stacksize ){
  	S.base =(SElemType*)realloc(S.base ,(STACK_INIT_SIZE+STACKINCREMENT )*sizeof(SElemType));
  	if(!S.base ) exit(OVERFLOW);//�洢����ʧ��
  	S.top=S.base +S.stacksize ;
  	S.stacksize+=STACKINCREMENT;
  }	
  *S.top ++=e;
  return OK;
  }
  //�������ջ��Ԫ��
  Status PrintStack(SqStack S)
  {
  	while(S.top !=S.base )
  	{
  		printf("%d\t",*S.base );
  		S.base++;
	  }
  	return OK;
   } 
   //��ȡջ��Ԫ��,����ֵ����e 
   Status GetTop(SqStack S,SElemType &e)
   {
   	 if(S.top ==S.base) return ERROR;
   	 e=*(S.top-1);
   	 return OK;	
   } 
   //�ÿ�ջ
   Status ClearStack(SqStack &S)
   {
   	if(S.base==NULL) return ERROR;
    else 
    while(S.top !=S.base)
    {
    	*(S.top-1)=0;
    	S.top--;
	}
	*(S.base )=0;
	return OK;
	} 
	//ɾ��ջ��Ԫ�� 
	Status Pop(SqStack &S,SElemType &e)
	{
	 if(S.top ==S.base) return ERROR;
	 e=*--S.top;
	 return OK;		
	 } 
	
  
  	
  	
  	
  	
  	
 
