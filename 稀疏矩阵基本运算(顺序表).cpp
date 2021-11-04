#define ElemType int
#define Status  int

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100
#define ERROR 1
#define OK 0
typedef struct 
{
	int i,j;
	ElemType e;
 } Triple;
 typedef struct{
 	Triple data[MAXSIZE+1];
 	int mu,nu,tu;
 }TSMatrix;
  void CreateTS(TSMatrix &M);
 void PrintMatrix(TSMatrix M); 
void Add(TSMatrix A, TSMatrix B, TSMatrix &C);
void Substra(TSMatrix M, TSMatrix N, TSMatrix &Q); 
void MultiplyTS(TSMatrix A, TSMatrix B, TSMatrix &C);
 void menu();
 int main()
 {
 	TSMatrix M,N,Q;
 	printf("���������A��\n");
 	CreateTS(M);
 	PrintMatrix( M) ;
 	printf("���������B��\n");
 	CreateTS(N);
 	PrintMatrix( N) ;
 	int operation;
	 while(1){
	system("cls"); 
    menu();
    printf("A=\n"); 
	PrintMatrix( M);
	printf("B=\n");
	PrintMatrix( N);
	printf("��������Ҫ�����Ķ�Ӧ��ţ�");
    scanf("%d", &operation);
    if(operation==0) {
	printf ("ллʹ��\n");break;}
    switch(operation){
    case 1: 
	    Add( M, N, Q);
	    PrintMatrix( Q);
        break;
    case 2:
        Substra( M, N, Q);
	    PrintMatrix( Q);
        break;
    case 3:
    	MultiplyTS( M,  N, Q);
    	PrintMatrix( Q);
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
 //������
  void CreateTS(TSMatrix &M)
{
	int t, m, n;
	ElemType e;
	bool k;
	printf( "��������������,����,����Ԫ������");
    scanf("%d,%d,%d", &M.mu, &M.nu, &M.tu);
	M.data[0].i = 0;
	for (t = 1; t<=M.tu; ++t)
	{
		do
		{
			printf("�밴����˳�������%d������Ԫ�����ڵ��У�1~%d��,�У�1~%d����Ԫ��ֵ��", t, M.mu, M.nu);
			scanf("%d,%d,%d", &m, &n, &e);
			k = false;
			if (m<1 || m>M.mu || n<1 || n>M.nu)//�л��г�����Χ
				k = true;
			if (m < M.data[t - 1].i || m == M.data[t - 1].i&&n <= M.data[t - 1].j)//�л��е�˳���д�
				k = true;
		} while (k);//��������򲻶�ѭ����ǰֵ������ 
		M.data[t].i = m;
		M.data[t].j = n;
		M.data[t].e = e;
	}
}
 //�����ӡ
 void PrintMatrix(TSMatrix M)
 {
 	int i,j,k=1;//k���������ǰ����ֵ���� 
 	Triple *p=M.data ;
 	p++;//Pָ���һ��Ԫ�� 
 	for(i=1;i<=M.mu;i++){
 		for(j=1;j<=M.nu;j++)
 		if(k<=M.tu &&p->i==i&&p->j==j)
 		{
 			printf("%3d",p->e);
 			p++;
 			k++;
		 }
		 else
		   printf("%3d",0);
		   printf("\n");
	 }
  } 
  //����ӷ�
void Add(TSMatrix A, TSMatrix B, TSMatrix &C)
{
	
	if(A.mu!=B.mu || A.nu!=B.nu)
    {
    printf("\n ����������������!");
    printf("\n ���������������������������Ӧ��ȷ��ɽ��мӷ����㣡��");
    } 
	C.mu = A.mu;
	C.nu = A.nu;
	C.tu = 0;
    int i = 1, j = 1, m = 1;
    int sum;
    while(i<=A.tu && j<=B.tu)
    {//A��B��û�м��������ʱ��
        if(A.data[i].i<B.data[j].i|| (A.data[i].i==B.data[j].i && A.data[i].j<B.data[j].j))
        {//A��Ԫ����BԪ�ص�ǰ��
            C.data[m].i = A.data[i].i;
            C.data[m].j = A.data[i].j;
            C.data[m].e = A.data[i].e;
            m++;
            i++;
        }
        else if(A.data[i].i==B.data[j].i && A.data[i].j==B.data[j].j)
        {//A��B��Ԫ���к��к����
            sum = A.data[i].e + B.data[j].e;
            if(sum != 0)//������0��ʱ����ܸ�ֵ
            {
                C.data[m].i= A.data[i].i;
                C.data[m].j= A.data[i].j;
                C.data[m].e = sum;
                m++;
            }
            i++;
            j++;
        }
        else
        {//BԪ����AԪ��ǰ��
            C.data[m].i = B.data[j].i;
            C.data[m].j = B.data[j].j;
            C.data[m].e = B.data[j].e;
            m++;
            j++;
        }
    }
    while(i<=A.tu)
    {//A����û������
        C.data[m].i = A.data[i].i;
        C.data[m].j = A.data[i].j;
        C.data[m].e = A.data[i].e;
        i++;
        m++;
    }
    while(j<=B.tu)
    {//B����û������
        C.data[m].i = B.data[j].i;
        C.data[m].j = B.data[j].j;
        C.data[m].e = B.data[j].e;
        j++;
        m++;
    }
    C.tu = m;//C�����з���Ԫ�ĸ���
}
//���� 
void Substra(TSMatrix M, TSMatrix N, TSMatrix &Q)
{
	int i;
	if (M.mu != N.mu || M.nu != N.nu)
		exit(1);
	for (i = 1; i <= N.tu; ++i) /* ����N��ÿһԪ��,��ֵ����-1 */
		N.data[i].e *= -1;
	Add(M, N, Q); /* Q=M+(-N) */
}
//�˷�
void MultiplyTS(TSMatrix A, TSMatrix B, TSMatrix &C)
{ //�������
	int i, j, h = A.mu, l = B.nu, Cn = 0;
	//h,lΪ����C����,��ֵ,CnΪ����C�ķ���Ԫ����,��ֵΪ��
	ElemType *Ce;
	if (A.nu != B.mu)
		exit(1);
	C.mu = A.mu;
	C.nu= B.nu;
	Ce = new ElemType[h*l];
	for (i = 0; i<h*l; i++)
		*(Ce + i) = 0; //����������Ԫ�س�ʼ��Ϊ��
	for (i = 1; i <= A.tu; i++)
		for (j = 1; j <= B.tu; j++)
			if (A.data[i].j == B.data[j].i)
				*(Ce + (A.data[i].i - 1)*l + B.data[j].j - 1) += (A.data[i].e)*(B.data[j].e);
	for (i = 1; i <= A.mu; i++)
	{
		for (j = 1; j <= B.nu; j++)
		{
			if (*(Ce + (i - 1)*l + j - 1))
			{
				Cn++;
				C.data[Cn].e = *(Ce + (i - 1)*l + j - 1);
				C.data[Cn].i = i;
				C.data[Cn].j = j;
			}
		}
	}
	delete Ce;
	C.tu = Cn;
}
 //�˵����� 
 void menu()
{
    printf ("\t    ϡ�����Ļ�������\n");
    printf ("========================================\n");
    printf ("\t1.����ӷ�\n");
    printf ("\t2.�������\n");
    printf ("\t3.����˷�\n");
    printf ("\t0.�˳�ϵͳ\n");
    printf ("========================================\n");
     
}
 


