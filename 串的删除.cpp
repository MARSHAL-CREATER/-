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
  void DelString(String &S,int pos,int len); //����ɾ��
 int main()
 {
  String S,T;int pos,len;
  CreatNullString(S);
  CreatNullString(T);
  char ch[MAXSIZE];
  printf("�����봮:\n");
  gets(ch);
  AssignString(S,ch);
  printf("%s\n",S.ch);
  printf("������ɾ����ʼλ�ã�"); 
  scanf("%d",&pos) ;
  printf("\n������ɾ�����ȣ�") ;
  scanf("%d",&len) ;
  DelString(S,pos,len);
  printf("\nɾ����Ĵ�Ϊ��");
  printf("%s\n",S.ch);
  //puts(S.ch);	
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
 //����ɾ��
 void DelString(String &S,int pos,int len)
 {
 	if(pos+len-1>S.length ) exit(1);
 	int i;
 	for( i=pos+len;i<=S.length;i++)
 	S.ch[i-len-1]=S.ch [i-1];
 	S.ch[S.length-len]='\0';
	S.length=S.length -len;	
  }
 

