#include <stdio.h> 
#include <stdlib.h>
#define OVERFLOW -1
#define OK 1
#define ERROR -1
typedef struct BiTNode{       //���Ķ�������洢�ṹ 
	char data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
//����������ĵݹ��㷨������ 
int CreateBiTree(BiTree &T)   
{
  char ch;
  ch=getchar(); 
  if (ch==' ') T = NULL; 
  else {
  if (!(T = (BiTNode *)malloc(sizeof(BiTNode))))
  exit(OVERFLOW);
  T->data = ch; // ���ɸ����
  CreateBiTree(T->lchild); // ����������
  CreateBiTree(T->rchild); // ����������
}
  return 0;
} 
//�����ǰ�ڵ��ַ� 
int Display(char e)
{
printf("%c\t",e);
return OK ;
}
//�������������
int PreOrder (BiTree T, int ( *visit)(char e))
{ 
if (T) {
  if (visit(T->data))            // ���ʸ����
     if(PreOrder(T->lchild, visit)) // ����������
        if(PreOrder(T->rchild, visit))// ����������
              return OK ;
              return ERROR;
		}
		else
	return OK; 
} 
//�������������
int InOrder (BiTree T, int ( *visit)(char e))
{ 
if (T) {
  if (InOrder(T->lchild, visit))             // ����������
     if(visit(T->data))              // ���ʸ����
        if(InOrder(T->rchild, visit))// ����������
              return OK ;
              return ERROR;
		}
		else
	return OK; 
}
//�������������
int PostOrder (BiTree T, int ( *visit)(char e))
{ 
if (T) {
  if (PostOrder(T->lchild, visit))             // ����������
        if(PostOrder(T->rchild, visit))// ����������
             if(visit(T->data))              // ���ʸ����
              return OK ;
              return ERROR;
		}
		else
	return OK; 
}
//��������߶�
int GetHeight(BiTree T)
{
	int m,n;
	if(T==NULL) return 0;
	m=GetHeight(T->lchild );
	n=GetHeight(T->rchild );
	if(m>n) return m+1;
	else return n+1;
 } 
//��������������������
void change(BiTree T)
{
	BiTNode *temp=(BiTNode *)malloc(sizeof(BiTNode));//����	BiTNode *temp=NULL; 
	if(T)
	{
		if(T==NULL) return ;
		temp=T->lchild ;
		T->lchild=T->rchild;
		T->rchild=temp;
		change(T->lchild);
		change(T->rchild);
	}
}
//ͳ��Ҷ�ӽڵ���
void CountLeaf(BiTree T,int &count)
{
	if(T)
	if(!T->lchild&&!T->rchild ) count++;
	else{
		CountLeaf(T->lchild ,count);//ͳ��������Ҷ���� 
		CountLeaf(T->rchild ,count);//ͳ��������Ҷ���� 
	}
 } 
  //�˵����� 
 void menu()
{
    printf ("\t    ������Ӧ��\n");
    printf ("========================================\n");
    printf ("\t1.���Ĵ���\n");
    printf ("\t2.�������������������\n");
    printf ("\t3.�������������������\n");
    printf ("\t4.����������ĺ�������\n");
    printf ("\t5.����������ĸ�\n");
    printf ("\t6.�����������Ҷ����\n");
    printf ("\t7.������������Ҷ��������\n");
    printf ("\t0.�˳�ϵͳ\n");
    printf ("========================================\n");
} 
int main()
{
	int operation;
	BiTree T;int leafs,height;
	while(1){
	system("cls"); 
    menu(); 
	printf("��������Ҫ�����Ķ�Ӧ��ţ�");
    scanf("%d", &operation);
    if(operation==0) {
	printf ("ллʹ��\n");break;}
    switch(operation){
    case 1:
	    while(getchar()!='\n');
	    //������ǰscanf�����ڻ�����д��ġ�\n���� CreateBiTree������getchar()��Ӱ�� 
        printf("�������ָ���ǵ���������:\n");
	    CreateBiTree(T);
        break;
    case 2:
        printf("�ö���������������Ϊ:\n");
	    PreOrder (T,Display);
        break;
    case 3:
        printf("�ö���������������Ϊ:\n");
	    InOrder (T,Display); 
        break;
    case 4:
    	printf("�ö������ĺ�������Ϊ:\n");
	    PostOrder (T,Display);
 	    break;
 	case 5:
	    height=GetHeight( T);
	    printf("�ö������ĸ߶�Ϊ:%d",height);
		break;
	case 6:
	    CountLeaf(T,leafs);
	    printf("�ö�������Ҷ����Ϊ:%d",leafs);
	    leafs=0;//���������� 
	    break;
	case 7:
        change(T); 
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

