#include<stdio.h>
#include <stdlib.h>
#define MVNum 100
typedef int SElemType;
typedef int Status;
bool visited[MVNum]; 
typedef struct ArcNode // �߱���
{
    int adjvex;    // �ڽӵ���,�洢�ö����Ӧ���±�(vertices�е�λ��)
    //int info;      //���ڴ洢Ȩֵ,���ڷ���ͼ���Բ���Ҫ
    struct ArcNode *nextarc; // ����,ָ����һ���ڽӵ�
}ArcNode;
typedef struct VNode // �������
{
    char data; // ������,�洢������Ϣ
    ArcNode *firstarc; // �߱�ͷָ��
}VNode, AdjList[MVNum];
typedef struct
{
    AdjList vertices;
    int vexnum,arcnum; // ͼ�е�ǰ�������ͱ���
}ALGraph;
//���д洢
typedef struct {
int front;//��ͷָ�� 
int rear;//��βָ��	
SElemType* data;//�洢����ַ	
}SqQueue; 

int LocateVex(ALGraph &G,char v);
void  CreateALGraph(ALGraph &G);
void DispGraphAdjList(ALGraph &G);
void DFS(ALGraph &G, int i);
void DFSTraverse(ALGraph &G);
Status InitQueue(SqQueue &S);
Status EmptyQueue(SqQueue S);
Status EnterQueue(SqQueue &S,SElemType e);
Status DeQueue(SqQueue &S,SElemType &e);
void BFSTraverse(ALGraph &G);

int main(void)
{
    ALGraph G;
    CreateALGraph(G);
    printf("\n�ڽӱ�Ϊ: \n");
    DispGraphAdjList(G);
    printf("\n\nͼ��������ȱ���Ϊ: ");
    DFSTraverse(G);
	printf("\nͼ�Ĺ�����ȱ���Ϊ: ");
    BFSTraverse(G); 
    return 0;
}
int LocateVex(ALGraph &G,char v)//�ҵ�v���ڽӱ�G�е�λ��
{
    for(int i=0;i<G.vexnum;i++)
    {
        if(G.vertices[i].data==v)
            return i;
    }
    return -1;
}
void  CreateALGraph(ALGraph &G)
{
    int i,j,k,v;
    char v1,v2;
    ArcNode *p1,*p2;
    printf("�����붥��(�ո�)������") ;
    scanf("%d%d",&G.vexnum,&G.arcnum); // ���붥�����ͱ���
    printf("\n�����붥����ĸ��\n") ;
    for(v = 0;v < G.vexnum;v++) // ���붥����Ϣ,���������
    {       
        scanf("%s",&G.vertices[v].data);     // ���붥����Ϣ
        G.vertices[v].firstarc=NULL;     // ���߱���Ϊ�ձ�
    }
    getchar();
    printf("\n�����������Ķ������У��磺A B����\n") ;
    for(k = 0;k < G.arcnum;k++)// �����߱�
    {
    	
        scanf("%c %c",&v1,&v2);
        getchar();
        i=LocateVex(G,v1);
        j=LocateVex(G,v2);
        p1=new ArcNode; // ���ڴ�����ռ�,���ɱ߱���
        p1->adjvex=j;    // �ڽ����Ϊj
        p1->nextarc=G.vertices[i].firstarc;    //��e��ָ��ָ��ǰ������ָ��Ľ��
        G.vertices[i].firstarc=p1;            // ����ǰ�����ָ��ָ��e

        p2=new ArcNode; // ���ڴ�����ռ�,���ɱ߱���
        p2->adjvex=i;    //�ڽ����Ϊi
        p2->nextarc=G.vertices[j].firstarc;    // ��e��ָ��ָ��ǰ������ָ��Ľ��
        G.vertices[j].firstarc=p2;        // ����ǰ�����ָ��ָ��e
    }
}
void DispGraphAdjList(ALGraph &G)
{
    int i;
    ArcNode *p;
    for(i=0;i< G.vexnum;i++)
    {
        printf("%c",G.vertices[i].data);
        for(p=G.vertices[i].firstarc;p!=NULL;p=p->nextarc)
            printf("->%c",G.vertices[p->adjvex].data);
        printf("\n");
    }
}
// ������ȱ�����ӡ 
void DFS(ALGraph &G, int i){
    visited[i] = 1;  
    printf("%c ", G.vertices[i].data);  
    
    ArcNode *p = G.vertices[i].firstarc  ;
    while(p){
        if(!visited[p->adjvex ]){
            DFS(G,p->adjvex  ); //�ݹ���ȱ���
        }
        p= p->nextarc ;
    }
}
// ������ȱ���
void DFSTraverse(ALGraph &G){
    int i;  
    for (i=0; i<G.vexnum ; ++i){ 
        visited[i] = 0;  //��ʼ����������visited��Ԫ��ֵΪfalse
    }
    for (i=0; i<G.vexnum ; ++i){
        if(!visited[i]){ //�ڵ���δ����
            DFS(G,i);
        }
    }
}
//��ʼ��
Status InitQueue(SqQueue &S)
{
  S.data=(SElemType*)malloc(MVNum *sizeof(SElemType));	
  if(!S .data) exit(1);
  S.front=S.rear=0;
  return 0;	
}
//�ж϶����Ƿ�Ϊ��
Status EmptyQueue(SqQueue S)
{
   	if(S.front==S.rear )
    return 1;
	else
	return 0; 
 }
 //Ԫ�����
 Status EnterQueue(SqQueue &S,SElemType e)
 {
 	if((S.rear+1)%MVNum==S.front ) exit(1);//��β����һ���Ƕ�ͷ������� 
  	S.data[S.rear]=e;
  	S.rear=(S.rear+1)%MVNum;//����ѭ������ 
  	return 0;	
}
  //Ԫ�س��ӣ�����e���س���Ԫ�� 
  Status DeQueue(SqQueue &S,SElemType &e)
  {
  	if(S.front==S.rear ) exit(1);
  	e=S.data[S.front];
	S.data[S.front]=0; 
  	S.front=(S.front+1)%MVNum;//����ѭ������ 
  	return 0;	
   }
//ͼ�Ĺ�����ȱ���   
void BFSTraverse(ALGraph &G){  
    int i;  
    SqQueue Q; 
    InitQueue(Q);
    for (i=0; i<G.vexnum ; ++i){  
        visited[i] = 0; 
    } 
    for (i=0; i<G.vexnum ; ++i){  
        if(!visited[i]){  
            visited[i] = 1;  
            printf("%c ", G.vertices[i].data);  
            EnterQueue(Q, i);  
            while (!EmptyQueue(Q)){  
                DeQueue(Q, i);  
                ArcNode *p = G.vertices[i].firstarc;  
                while (p){  
                    if (!visited[p->adjvex]){  
                        visited[p->adjvex] = 1;  
                        printf("%c ", G.vertices[p->adjvex].data );  
                        EnterQueue(Q, p->adjvex );  
                    }  
                    p = p->nextarc ;  
                }
            }
        }  
    }    
}
