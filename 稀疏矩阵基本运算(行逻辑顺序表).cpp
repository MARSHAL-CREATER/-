#define ElemType int
#define Status int

#include <stdio.h> 
#include <stdlib.h>

#define MAX_SIZE 100
#define MAX_RC 20
#define ERROR 1
#define TRUE 0
#define OK 0
struct Triple
{
    int i, j;//���±꣬���±�
    ElemType e;//����Ԫ��ֵ
};

struct RLSMatrix
{
    Triple data[MAX_SIZE + 1];//����Ԫ��Ԫ���data[0]δ��
    int rpos[MAX_RC + 1];//���е�1������Ԫ�ص���Ԫ��λ�ñ�
    int mu, nu, tu;//���������������������Ԫ����
};

Status CreateSMatrix(RLSMatrix &M){//����ϡ�����M
    int i, j;
    Triple T;
    Status k;
    printf("��������������������������Ԫ�ظ�����");
    scanf("%d,%d,%d", &M.mu, &M.nu, &M.tu);
    if (M.tu > MAX_SIZE || M.mu > MAX_RC)//����M�ķ���Ԫ����̫�������̫��
        return ERROR;
    M.data[0].i = 0;//Ϊ���±Ƚ���׼��
    for (i = 1; i <= M.tu; i++)//��������M.tu������Ԫ��
    {
        do
        {
            printf("�밴����˳�������%d������Ԫ�����ڵ��У�1~%d��,�У�1~%d����Ԫ��ֵ��", i, M.mu, M.nu);
            scanf("%d,%d,%d", &T.i, &T.j, &T.e);
            k = 0;//����ֵ�ķ�Χ��ȷ�ı�־
            if (T.i < 1 || T.i > M.mu || T.j < 1 || T.j > M.nu)//�л��г�����Χ
                k = 1;
            if (T.i < M.data[i - 1].i || T.i == M.data[i - 1].i&&T.j <= M.data[i - 1].j)
                k = 1;//�л��е�˳���д�
        } while (k);//����ֵ�ķ�Χ����ȷ����������
        M.data[i] = T;//��������ȷ��ֵ����M����Ӧ�洢��Ԫ
    }
    for (i = 1; i <= M.mu; i++)//��rpos[]����ֵ1��ÿ�е�1������Ԫ�صĳ�ʼλ�ã�
        M.rpos[i] = 1;
    for (i = 1; i <= M.tu; i++)//����ÿ������Ԫ�أ�����ͳ�ƣ�������rpos[]
        for (j = M.data[i].i + 1; j <= M.mu; j++)//�ӷ���Ԫ�������е���һ���� 
            M.rpos[j] ++;//ÿ�е�1������Ԫ�ص�λ��+1
    return OK;
}
int comp(int c1, int c2){//�Ƚ������c1��c2�Ĵ�С��ϵ
    if (c1 < c2)
        return -1;
    if (c1 == c2)
        return 0;
    return 1;
}


Status AddSMatrix(RLSMatrix M, RLSMatrix N, RLSMatrix *Q)
{ /* ��ϡ�����ĺ�Q=M+N */
	int k, p, q;
	if (M.mu != N.mu || M.nu != N.nu)
		return ERROR;
	(*Q).mu = M.mu;
	(*Q).nu = M.nu;
	(*Q).tu = 0;
	M.rpos[M.mu + 1] = M.tu + 1; /* Ϊ��������whileѭ����ʱ���� */
	N.rpos[N.mu + 1] = N.tu + 1;
	for (k = 1; k <= M.mu; ++k) /* ����ÿһ�У�kָʾ�к� */
	{
		(*Q).rpos[k] = (*Q).tu + 1;
		p = M.rpos[k]; /* pָʾM�����k�е�ǰԪ�ص���� */
		q = N.rpos[k]; /* qָʾN�����k�е�ǰԪ�ص���� */
		while (p < M.rpos[k + 1] && q < N.rpos[k + 1])
		{ /* M,N������е�k��Ԫ��δ���� */
			if (M.data[p].j == N.data[q].j) /* M����ǰԪ�غ�N����ǰԪ�ص�����ͬ */
			{
				(*Q).data[(*Q).tu + 1].e = M.data[p].e + N.data[q].e;
				if ((*Q).data[(*Q).tu + 1].e != 0)
				{
					++(*Q).tu;
					(*Q).data[(*Q).tu].i = k;
					(*Q).data[(*Q).tu].j = M.data[p].j;
				}
				++p;
				++q;
			}
			else if (M.data[p].j < N.data[q].j)
			{ /* M����ǰԪ�ص���<N����ǰԪ�ص��� */
				++(*Q).tu;
				(*Q).data[(*Q).tu].e = M.data[p].e;
				(*Q).data[(*Q).tu].i = k;
				(*Q).data[(*Q).tu].j = M.data[p].j;
				++p;
			}
			else /* M����ǰԪ�ص���>N����ǰԪ�ص��� */
			{
				++(*Q).tu;
				(*Q).data[(*Q).tu].e = N.data[q].e;
				(*Q).data[(*Q).tu].i = k;
				(*Q).data[(*Q).tu].j = N.data[q].j;
				++q;
			}
		}
		while (p < M.rpos[k + 1]) /* M������k�е�Ԫ��δ���� */
		{
			++(*Q).tu;
			(*Q).data[(*Q).tu].e = M.data[p].e;
			(*Q).data[(*Q).tu].i = k;
			(*Q).data[(*Q).tu].j = M.data[p].j;
			++p;
		}
		while (q < N.rpos[k + 1]) /* N������k�е�Ԫ��δ���� */
		{
			++(*Q).tu;
			(*Q).data[(*Q).tu].e = N.data[q].e;
			(*Q).data[(*Q).tu].i = k;
			(*Q).data[(*Q).tu].j = N.data[q].j;
			++q;
		}
	}
	return OK;
}
 
Status SubtSMatrix(RLSMatrix M, RLSMatrix N, RLSMatrix *Q)
{ /* ��ϡ�����Ĳ�Q=M-N */
	int i;
	if (M.mu != N.mu || M.nu != N.nu)
		return ERROR;
	for (i = 1; i <= N.tu; ++i) /* ����N��ÿһԪ��,��ֵ����-1 */
		N.data[i].e *= -1;
	AddSMatrix(M, N, Q); /* Q=M+(-N) */
	return OK;
}

void TransposeSMatrix(RLSMatrix M, RLSMatrix &T){//��ϡ�����M��ת�þ���T
    int i, j, k, num[MAX_RC + 1];//[0]����
    T.mu = M.nu;//����T������ = ����M������
    T.nu = M.mu;//����T������ = ����M������
    T.tu = M.tu;//����T�ķ���Ԫ�ظ��� = ����M�ķ���Ԫ�ظ���
    if (T.tu)//����ǿ�
    {
        for (i = 1; i <= T.mu; ++i)//�Ӿ���T�ĵ�1�е����һ��
            num[i] = 0;//����Tÿ�з���Ԫ�ظ�������ֵ����Ϊ0
        for (i = 1; i <= M.tu; ++i)//����M�е�ÿһ������Ԫ�أ�����ͳ��
            ++num[M.data[i].j];//num[] = T��ÿ�У�M��ÿ�У�����Ԫ�ظ���
        T.rpos[1] = 1;//����T�е�1�еĵ�1������Ԫ�ص����Ϊ1
        for (i = 2; i <= T.mu; ++i)//�Ӿ���T�ĵ�2�е����һ��
            T.rpos[i] = T.rpos[i - 1] + num[i - 1];//��T�е�i�еĵ�1������Ԫ�ص����
        for (i = 1; i <= M.tu; ++i)
            num[i] = T.rpos[i];//num[] = M �ĵ�ǰ����Ԫ����T��Ӧ��ŵ�λ��
        for (i = 1; i <= M.tu; ++i)//����M�е�ÿһ������Ԫ��
        {
            j = M.data[i].j;//�ھ���T�е�����
            k = num[j] ++;//�ھ���T�е���ţ�num[j] + 1
            T.data[k].i = M.data[i].j;//��M.data[i]���жԵ�����T.data[k]
            T.data[k].j = M.data[i].i;
            T.data[k].e = M.data[i].e;
        }
    }
}

Status MultSMatrix(RLSMatrix M, RLSMatrix N, RLSMatrix &Q){//��ϡ�����˻�Q = M * N
    int arow, brow, p, q, ccol, ctemp[MAX_RC + 1], t, tp;
    if (M.nu != N.mu)//����M��N�޷����
        return ERROR;
    Q.mu = M.mu;//Q������ = M������
    Q.nu = M.nu;//Q������ = N������
    Q.tu = 0;//Q�ķ���Ԫ�ظ����ĳ�ֵΪ0
    if (M.tu * N.tu != 0)//Q�Ƿ������
    {
        for (arow = 1; arow <= M.mu; ++arow)//��M��ÿһ�У�arow��M�ĵ�ǰ��
        {
            for (ccol = 0; ccol <= Q.nu; ++ccol)//��Q�ĵ�1�е����һ��
                ctemp[ccol] = 0;//Q�ĵ�ǰ�еĸ���Ԫ���ۼ�������
            Q.rpos[arow] = Q.tu + 1;//Q��ǰ�еĵ�1��Ԫ��λ����һ�����1��Ԫ��֮��
            if (arow < M.mu)//�������һ��
                tp = M.rpos[arow + 1];//��һ�еĵ�1��Ԫ�ص�λ���Ǳ���Ԫ�ص��Ͻ�
            else//�����һ��
                tp = M.tu + 1;//�����һ�����Ͻ�
            for (p = M.rpos[arow]; p < tp; ++p)//��M��ǰԪ����ÿһ������Ԫ
            {
                brow = M.data[p].j;//�ҵ���ӦԪ��N�е��кţ�M��ǰԪ���кţ�
                if (brow < N.mu)//�������һ��
                    t = N.rpos[brow + 1];//��һ�еĵ�1��Ԫ�ص�λ���Ǳ���Ԫ�ص��Ͻ�
                else//�������һ��
                    t = N.tu + 1;//�����һ�����Ͻ�
                for (q = N.rpos[brow]; q < t; ++q)//��N��ǰ����ÿһ������Ԫ
                {
                    ccol = N.data[q].j;//�˻�Ԫ����Q�е��к�
                    ctemp[ccol] += M.data[p].e * N.data[q].e;//���˻��ۼӵ�Q��arow��ccol����
                }
            }//���Q�е�arow�е������е�Ԫ��ֵ������ctemp[]��
            for (ccol = 1; ccol <= Q.nu; ++ccol)//���ڵ�arow�е������У�ֻ�洢���еķ���Ԫ
            {
                if (ctemp[ccol])//���е�ֵ��Ϊ0
                {
                    if (++Q.tu > MAX_SIZE)//Q�ķ���Ԫ�ظ���+1���������Ԫ����̫��
                        return ERROR;
                    Q.data[Q.tu].i = arow;//��Q[i][j]��˳�����ϡ�����Q
                    Q.data[Q.tu].j = ccol;
                    Q.data[Q.tu].e = ctemp[ccol];
                }
            }
        }
    }
    return OK; 
}

Status MultSMatrix1(RLSMatrix M, RLSMatrix N, RLSMatrix &Q){//��ϡ�����Q = M * N(��ʹ����ʱ���飬����N��ת�Ⱦ���T)
    int i, j, q, p, up, uq;
    ElemType Qs;//����ԪQ[i][j]����ʱ��Ŵ�
    RLSMatrix T;//N��ת�Ⱦ���
    if (M.nu != N.mu)//����M��N�޷����
        return ERROR;
    Q.mu = M.mu;//Q������ = M������
    Q.nu = M.nu;//Q������ = M������
    Q.tu = 0;//Q�ķ���Ԫ�ظ����ĳ�ֵΪ0
    TransposeSMatrix(N, T);//T��N��ת�Ⱦ���
    for (i = 1; i <= Q.mu; i++)//����Q��ÿһ��
    {
        for (j = 1; j <= Q.nu; j++)//����Q��ÿһ�У���Q[i][j]
        {
            Qs = 0;//Q[i][j]�ĳ�ֵΪ0
            p = M.rpos[i];//pָʾ����M��i�еĵ�1������Ԫ�ص�λ��
            q = T.rpos[j];//qָʾ����T��j�У�N��j�У��ĵ�1������Ԫ�ص�λ��
            if (i < M.mu)//�������һ��
                up = M.rpos[i + 1];//��һ�еĵ�1��Ԫ�ص�λ���Ǳ���Ԫ�ص��Ͻ�
            else//�����һ��
                up = M.tu + 1;//�����һ�����Ͻ�
            if (j < T.mu)//�������һ��
                up = T.rpos[j + 1];//��һ�еĵ�1��Ԫ�ص�λ���Ǳ���Ԫ�ص��Ͻ�
            else//�����һ��
                up = T.tu + 1;//�����һ�����Ͻ�
            while (p < up && q < uq)//p,q�ֱ�ָʾ����M,T�е�i��j��Ԫ��
            {
                switch (comp(M.data[p].j, T.data[q].j))
                {//�Ƚ�M����ǰԪ�ص���ֵ��T����ǰԪ�ص���ֵ����N����ǰԪ�ص���ֵ��
                case -1:p++;//M����ǰԪ�ص���ֵ < T(N)����ǰԪ�ص��У��У�ֵ��p�����
                    break;
                    //M��ǰԪ�ص���ֵ = T(N)��ǰԪ�ص��У��У�ֵ������ֵ��˲��ۼӵ�Qs,p��q�������
                case 0:Qs += M.data[p++].e * T.data[q++].e;
                    break;
                case 1:q++;//M����ǰԪ�ص���ֵ > T(N)����ǰԪ�ص��У��У�ֵ��q�����
                }
            }
            if (Qs)//Q[i][j]��Ϊ0
            {
                if (++Q.tu > MAX_SIZE)//Q�ķ���Ԫ�ظ���+1���������Ԫ����̫��
                    return ERROR;
                Q.data[Q.tu].i = i;//��Q[i][j]��˳�����ϡ�����Q
                Q.data[Q.tu].j = j;
                Q.data[Q.tu].e = Qs;
            }
        }
    }
    return OK;
}

void PrintSMatrix1(RLSMatrix M)
{ // ��������ʽ���M
	int i, j, k = 1;
	Triple *p = M.data;
	p++; // pָ���1������Ԫ��
	for (i = 1; i <= M.mu; i++)
	{
		for (j = 1; j <= M.nu; j++)
			if (k <= M.tu&&p->i == i && p->j == j) // pָ�����Ԫ����p��ָԪ��Ϊ��ǰ����Ԫ��
			{
				printf("%3d", p->e); // ���p��ָԪ�ص�ֵ
				p++; // pָ����һ��Ԫ��
				k++; // ������+1
			}
			else // p��ָԪ�ز��ǵ�ǰ����Ԫ��
				printf("%3d", 0); // ���0
			printf("\n");
	}
}
 //�˵����� 
 void menu()
{
    printf ("\t    ϡ�����Ļ�������\n");
    printf ("========================================\n");
    printf ("\t1.����ӷ�\n");
    printf ("\t2.�������\n");
    printf ("\t3.����ת��\n");
    printf ("\t4.����˷�\n");
    printf ("\t0.�˳�ϵͳ\n");
    printf ("========================================\n");
     
}
int main()
{ 
	RLSMatrix M;
	RLSMatrix N;
	RLSMatrix Q;
	printf("���������A��\n");
	CreateSMatrix(M);
	PrintSMatrix1( M);
	printf("���������B��\n");
	CreateSMatrix(N);
	PrintSMatrix1( N);
	system("pause");  
	int operation;
	 while(1){
	system("cls"); 
    menu();
    printf("A=\n"); 
	PrintSMatrix1( M);
	printf("B=\n");
	PrintSMatrix1( N);
	printf("��������Ҫ�����Ķ�Ӧ��ţ�");
    scanf("%d", &operation);
    if(operation==0) {
	printf ("ллʹ��\n");break;}
    switch(operation){
    case 1: 
	    AddSMatrix( M, N, &Q);
	    PrintSMatrix1( Q);
        break;
    case 2:
        SubtSMatrix( M, N, &Q);
	    PrintSMatrix1( Q);
        break;
    case 3:
    	printf("����A��ת�ã�\n");
        TransposeSMatrix( M, Q);
        PrintSMatrix1( Q);
        break;
    case 4:
    	MultSMatrix( M,  N, Q);
    	PrintSMatrix1( Q);
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

