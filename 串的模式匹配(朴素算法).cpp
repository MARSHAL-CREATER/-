#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXSIZE 256
typedef struct//�ѷ��� 
{
	char *ch;//�洢��ʼλ�� 
	int length;//���� 
	int strsize;//����ռ��С 
 }String; 
  void CreatNullString (String &S);//�����մ�
  void  AssignString(String &S,char *s2);  //Ϊ����ֵ
  int index(String S,String T,int pos);//�����㷨ʵ�ִ���ģʽƥ��
 int main()
 {
  String S,T;
  CreatNullString(S);
  CreatNullString(T);
  char ch[MAXSIZE];
  printf("����������:\n");
  gets(ch);
  AssignString(S,ch);
  printf("�������Ӵ�:\n");
  gets(ch);
  AssignString(T,ch);
  int i= index(S,T,1);//pos=1��������ͷ����		
  printf("��ͬ�ַ�������������ʼλ��Ϊ����%dλ\n",i);	
  system("pause");
  return 0;	
  }
  
  //�����մ� 
  void CreatNullString (String &S) 
 {
 S.ch =(char*)malloc(MAXSIZE*sizeof(char));
 S.length=0;
 S.strsize =MAXSIZE;
 } 
 
 
 //Ϊ����ֵ
  void  AssignString(String &S,char *s2)
 {
   int i=0;
   //ͳ�������ַ����� 
   while(s2[i]!='\0')
   {
   	i++;
	   }
	//�ռ䲻������realloc�����¿ռ� 
	if(i>S.strsize)
	{
		S.ch=(char*)realloc(S.ch,i*sizeof(char));
		S.strsize=i;
		}
		S.length =i;	
 	//��ֵ
	 for(i=0;i<S.length;i++)
	 {S.ch[i]=s2[i]; } 
 }
 
 
 //�����㷨ʵ�ִ���ģʽƥ��
 int index(String S,String T,int pos)//pos�������������ʼλ��,TΪҪ�����Ӵ� 
 {
  int i,j;
  //pos�Ĵ��������ж� 
  if(pos<1||S.length<pos||S.length-T.length+1<pos)
   exit(1);
   
   i=pos-1;//���������Ǵ�0��ʼ�洢��
   j=0;
   while(i<S.length&&j<T.length)
   {
   	 if(S.ch[i]==T.ch[j])
   {
   	i++;
   	j++;
	}
	else
	{
		i=i-j+1;//i��λ�ñ�Ϊ��ʼλ��֮���һ��λ�� 
		j=0;
	 }
   }
    if(j>=T.length)
	return i-T.length+1;
	else return 0;//ƥ��ʧ�� 
 	 	
  } 
