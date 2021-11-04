#include<stdio.h>  

#define  MAX_VERNUM  20                  //���洢������  

typedef char VexType;                 //ͼ��Ԫ�ص�Ŀ����������   

typedef struct      
{                    
    VexType vertexArr[MAX_VERNUM];        //����Ԫ��λ������   

    int arcArr[MAX_VERNUM][MAX_VERNUM];   //�������ά����   
    int VexNum;                              //������Ŀ 

}ArrayGraph;  

void InitArrayGraph(ArrayGraph &A,int num);
void CreateArrayGraph(ArrayGraph  &A,int num) ;
void PrintArrayGraph(ArrayGraph &A) ;

int main()  
{   int vexnum;
    printf("����Ҫ����ͼ��������\n");
	scanf(" %d",&vexnum);
    ArrayGraph A;  
    InitArrayGraph(A,vexnum);
    CreateArrayGraph(A,vexnum) ;
    PrintArrayGraph(A) ;
    return 0;  
}  

//��ʼ��Ϊһ��ֻ�ж����ͼ   
void InitArrayGraph(ArrayGraph &A,int num)  
{  
    for (int i = 0; i < MAX_VERNUM; i++)  
    A.arcArr[i][i] = 0;  
}  

void CreateArrayGraph(ArrayGraph  &A,int num)  
{   
    //�洢�������� 
	A.VexNum=num ;    
    for (int i = 0; i < num; ++i)  //��䶥������  
    {  
        printf("�����%d������ֵ\n",i+1);  
        scanf(" %c",&(A.vertexArr[i]));   
    }
    //�洢�������ά����
    for (int j = 0; j <num; ++j)   //���߹�ϵ   
    {  
        for (int i = j+1; i < num; ++i)  
        {  

            printf("��%c��%c֮���л���������1����������0\t",A.vertexArr[i],A.vertexArr[j]);  
            scanf("%d",&(A.arcArr[i][j]));  
            if(A.arcArr[i][j]==1)
			A.arcArr[j][i]=1;
			else A.arcArr[j][i]=0;
            /*  ��Ϊ����ͼ��ֻҪɾ��if else, �������´��� 
			printf("��Ԫ��%c��ָ��%c�Ļ���������1����������0\t",A.vertexArr[j],A.vertexArr[i]]);  
            scanf("%d",&( A.arcArr[j][i]));
            */
        }  
    }  
}  


void PrintArrayGraph(ArrayGraph &A)  
{   //������� 
    printf("\n\n����Ԫ������\n");  
    for (int i = 0; i < A.VexNum; ++i)  
    {  
        printf("%-5c", A.vertexArr[i]);  
    }  
    printf("\n\n");  
    puts("����������\n\n");   
    printf("%-2c",' '); 
	 
    for(int i=0;i<A.VexNum;++i)  
      printf("%-5c",A.vertexArr[i]);  
    putchar('\n');    

    for (int i = 0; i <A.VexNum; ++i)  
    {  
        printf("%-2c",A.vertexArr[i]);  
        for (int j = 0; j < A.VexNum; ++j)  
        {  
            printf("%-5d",A.arcArr[i][j]);  

        }  
        putchar('\n');  
    }  
    putchar('\n');    
}  
