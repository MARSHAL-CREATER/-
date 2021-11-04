#include <stdio.h>
#include <stdlib.h>
#define Init_SSTable_Num 100
#define LEN 10
int hash[LEN]={0};   //��ϣ���ʼ��Ϊ0
 
typedef struct{
	int *elem;
	int length;
}SSTable;
int InitSSTable(int a[],SSTable &List,int len)
{
	List.elem=(int*)malloc(Init_SSTable_Num*sizeof(int));
	if(!List.elem) exit(1);
	List.length=0;
	for(int i=1;i<=len;i++)
	{
		List.elem[i]=a[i-1];
		List.length ++;
	}
	return 0;
}
//˳����� 
int Search_Seq(SSTable List,int key) 
{
	List.elem[0]=key;               //���ü����� 
	int i=0;
	for( i=List.length;List.elem[i]!=key;i--);
		return i;
	
}
//�۰����
int Search_Bin(SSTable List,int key)
{
	int mid,low=1;
	int high=List.length;
	while(low<= high){
	    mid=(low+high)/2;
		if(List.elem[mid]==key) return mid;
		else if(List.elem [mid]<key) low=mid+1;
		else high=mid-1;
	} 
	return 0;
 } 
 //��ϣ��Ĳ��� 
 void InsertHash(int data[])
{
	for(int i=0;i<LEN;i++)  
	{
		//���ؼ��ֲ��뵽��ϣ��hash�У�
		int j=data[i]%10;       //�����ϣ��ַ
		while(hash[j])          //Ԫ��λ���ѱ�ռ��
			j=(++j)%LEN;        //����̽�ⷨ�����ͻ
		hash[j]=data[i];
	}
}
//��ϣ����� 
int Search_Haxi(int key)
{
	int i=key%LEN;  //�����ϣ��ַ��
	while(hash[i]&&hash[i]!=key)   //�ж��Ƿ��ͻ
		i=(++i)%LEN;   //����̽�ⷨ�����ͻ
	if(hash[i]==0)  //���ҵ����ŵ�Ԫ����ʾ����ʧ��
		return -1; 
	else
		return i;   //���ض�Ӧ��Ԫ���±�
}
 //�˵����� 
 void menu()
{
    printf ("\t  ˳���۰�͹�ϣ���Ҳ�����ʵ��\n");
    printf ("========================================\n");
    printf ("\t1.˳�����\n");
    printf ("\t2.�۰����\n");
    printf ("\t3.��ϣ����\n");
    printf ("\t4.���˳���\n");
    printf ("\t5.�����ϣ��\n");
    printf ("\t0.�˳�ϵͳ\n");
    printf ("========================================\n");
}
int main()
{
	SSTable List;
	int key,operation,t;
	printf("������ҵĹؼ���:");
	scanf("%d",&key);
	int b[10]={23,45,46,55,76,89,100,110,568,600};
	InitSSTable(b,List,10);  //˳���ֵ 
	InsertHash(b);           //��ϣ��ֵ 
    while(1){
	system("cls"); 
    menu(); 
	printf("��������Ҫ�����Ķ�Ӧ��ţ�");
    scanf("%d", &operation);
    if(operation==0) {
	printf ("ллʹ��\n");break;}
    switch(operation){
    case 1:
	    t= Search_Seq( List, key);
        printf("˳����ҵĽ��Ϊ��%d",t) ;
        break;
    case 2:
        t=Search_Bin( List,key);
        printf("�۰���ҵĽ��Ϊ��%d",t) ;
        break;
    case 3:
    	t=Search_Haxi(key); 
        printf("���ҳɹ����ùؼ����ڹ�ϣ���е��±�Ϊ %d !!!",t); 
        break; 
    case 4:
    	printf("˳����и�Ԫ�ص�ֵ:\n");
    	for(int i=1;i<=10;i++)
	    printf("%d\t",List.elem[i]);
	    break;
	case 5:
		printf("��ϣ���и�Ԫ�ص�ֵ:\n");
	    for(int i=0;i<LEN;i++)
		printf("%d\t",hash[i]);
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


