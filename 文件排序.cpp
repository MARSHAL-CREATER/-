/*Ҫ��ʹ�����ֲ�ͬ�������㷨����ָ���ļ��е��ַ����н��в�������
����ʹ�ÿ��������㷨֮�⣬Ҫ����ʹ��һ���Լ���Ϥ�������㷨��ʵ�֣�*/
#include <stdio.h>  
#include  <string.h> 
char xx[50][80];
int maxline = 0 ;                      
void readtxt(void) ;                                 
void writetxt(void) ;
void SelectSort();
void quick_sort(char s[], int l, int r);
void UseQuick();                
int main() 
{  
   readtxt();
   SelectSort();
   //UseQuick();
   writetxt() ;
   return 0;   
  } 
void readtxt(void) {   
FILE *fp;
int i = 0 ; char *p ; 
fp = fopen("in.txt", "r");
while(fgets(xx[i], 80, fp) != NULL){   
  p = strchr(xx[i], '\n');//ȥ�����з� ������Ϊnull 
  if(p)  
     xx[i][p - xx[i]] = 0 ;
     i++;
  } 
  maxline = i ;
  fclose(fp);
}
void writetxt(void) {   
FILE *fp ;  
int i ; 
  fp = fopen("out.txt", "w") ;
  for(i = 0 ; i < maxline ; i++) 
  fprintf(fp, "%s\n", xx[i]) ;  
  fclose(fp) ;  
}
//ֱ��ѡ�� 
void SelectSort()
{
	int n,i,j,len;char k;
	for(n=0;n<maxline;n++)
	{
		len=strlen(xx[n]);//ȷ�����г��� 
		for(i=0;i<len;i++)//����ֱ�Ӳ������� 
		{
			k=xx[n][i];j=i-1;  //k���ڱ�
			while(k<xx[n][j])   //�ɺ���ǰ���Ҳ���λ�� 
			{
				if(j<0) break;
				xx[n][j+1]=xx[n][j];j--;
			}
			xx[n][j+1]=k;  //����ǰ��Сֵ�ڱ��������λ�� 
		}
	 } 

}
//��������
void quick_sort(char s[], int l, int r)
{
    if (l < r)
    {
        int i = l, j = r, x = s[l];
        while (i < j)
        {
            while(i < j && s[j] >= x) // ���������ҵ�һ��С��x����
                j--;  
            if(i < j) 
                s[i++] = s[j];//��s[j]�s[i]�У�s[j]���γ���һ���µĿ�
            
            while(i < j && s[i] < x) // ���������ҵ�һ�����ڵ���x����
                i++;  
            if(i < j) 
                s[j--] = s[i];//��s[i]�s[j]�У�s[i]���γ���һ���µĿ�
        }
        s[i] = x;//�˳�ʱ��i����j����x�������С�
        quick_sort(s, l, i - 1); // �ݹ���� 
        quick_sort(s, i + 1, r);
    }
}
void UseQuick()
{
	int len;
	for(int n=0;n<maxline;n++)
	{
		    len=strlen(xx[n]);//ȷ�����г��� 
			quick_sort(xx[n],0,len-1);
	}	
 } 
