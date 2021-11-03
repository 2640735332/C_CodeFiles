#include <stdio.h>
#include <stdlib.h>
#define MaxNode 20
#define FINITY 10000

//����ͼ�����д��붼��д�ڴ���Ŀ

//�ڱ߾���ṹ�Ķ���
typedef struct graph{
    char vertexs[MaxNode];//����洢������
    int edges[MaxNode][MaxNode];//��ά����洢����֮��ߵĹ�ϵ-> 0Ϊû�б� 1Ϊ�б�
    int vertexNum,edgeNum,hasDirection;
}MatrixGraph;//Matrix->����

//���������ڽӾ���
MatrixGraph *CreateMatrixGraph(char *txtName,int hasDirectionGraph){
    FILE *txt;
    MatrixGraph *graph;
    int i,j,startIndex,endIndex;
    int edgeInform;

    graph=(MatrixGraph *)malloc(sizeof(MatrixGraph));
    graph->hasDirection=hasDirectionGraph;//�����ڽӾ����������
    txt=fopen(txtName,"r");//Read data in the txt
    //��ȡ����+����-����ȡ�ڵ�ֵ-����ȡ��ֵ
    if(txt==NULL){
        printf("Read failed!");
        graph=NULL;
        return graph;
    }

    fscanf(txt,"%d%d",&graph->vertexNum,&graph->edgeNum);//��ȡ�������ͱ���
    fscanf(txt,"%c");//��ȡ��һ�еĻ��з�
    for(i=0;i<=graph->vertexNum;i++){//��ȡ�ڵ�ֵ
        fscanf(txt,"%c",&graph->vertexs[i]);
    }
    //��ʼ���ڽӾ���ߵĹ�ϵ
    for(i=0;i<graph->vertexNum;i++){
        for(j=0;j<graph->vertexNum;j++){
            graph->edges[i][j]=FINITY;//FINITY ��ʾ���ڵ�û�й�ϵ
        }
    }

    //�ڽӾ���ߵĶ�ȡ
    for(i=0;i<graph->edgeNum;i++){
        fscanf(txt,"%d%d%d",&startIndex,&endIndex,&edgeInform);
        graph->edges[startIndex][endIndex]=edgeInform;//�����ڽӾ���

        if(!hasDirectionGraph){
            graph->edges[endIndex][startIndex]=edgeInform;//�����ڽӾ���Ľ���
        }
    }

    fclose(txt);
    return graph;
}

//�жϱ�(i,j)�Ƿ���ڡ�>��i�����͵�j�����ı�
int Exist_MatrixGraph(MatrixGraph *g,int i,int j){
    if(g==NULL){
        return 0;
    }

    if(i>MaxNode || j>MaxNode){
        return 0;
    }

    if(g->edges[i][j]!=FINITY){
        return g->edges[i][j];
    }else{
        return FINITY;
    }
}

//�����ڽӾ����бߵ���Ŀ
int Edges_MatrixGraph(MatrixGraph *g){
    if(g==NULL){
        return 0;
    }

    int num=0,i,j;
    if(g->hasDirection){
        for(i=0;i<g->vertexNum;i++){
            for(j=0;j<g->vertexNum;j++){
                if(g->edges[i][j]!=FINITY){
                    num++;
                }
            }
        }
    }else{
        for(i=0;i<g->vertexNum;i++){
            for(j=0;j<g->vertexNum;j++){
                if(i<j && g->edges[i][j]!=FINITY){
                    num++;
                }
            }
        }
    }


    return num;
}

//����ͼ�ж������Ŀ
int Vertices_MatrixGraph(MatrixGraph *g){
    if(g==NULL){
        return 0;
    }

    return g->vertexNum;
}

//��ͼ����ӱ�
void Add_MatrixGraph(MatrixGraph *g,int i,int j,int edgeInform){
    g->edges[i][j]=edgeInform;
    if(!g->hasDirection){
        g->edges[j][i]=edgeInform;
    }
    g->edgeNum++;
}

//ɾ����
void Delete_MatrixGraph(MatrixGraph *g,int i,int j){
    g->edges[i][j]=FINITY;
    if(!g->hasDirection){
        g->edges[j][i]=FINITY;
    }
    g->edgeNum--;
}

//���ض���i�����
int InDegree_MatrixGraph(MatrixGraph *g,int i){
    int num=0;
    int j;
    for(j=0;j<Vertices_MatrixGraph(g);j++){
        if(g->edges[j][i]!=FINITY){
            num++;
        }
    }
    return num;
}

//���ض���i�ĳ���
int OutDegree_MatrixGraph(MatrixGraph *g,int i){
    int num=0;
    int j;
    for(j=0;j<Vertices_MatrixGraph(g);j++){
        if(g->edges[i][j]!=FINITY){//����Ȳ�ͬ��һ��
            num++;
        }
    }
    return num;
}

//������ȱ���(�ڽӾ���
void DepthFirstTraverse_MatrixGraph(MatrixGraph *g){
    int visited[MaxNode]={0};
    int i,j;

    for(i=0;i<g->vertexNum;i++){
        printf("��%d��㿪ʼ���ڽӾ�����ȱ�����",i);
        DFS_MatrixGraph(g,i,visited);
        for(j=0;j<g->vertexNum;j++){
            visited[j]=0;
        }
        printf("\n");
    }
}

//������Ȳ���(�ڽӾ���
void DFS_MatrixGraph(MatrixGraph *g,int nodeIndex,int visited[]){
    //������һ���� -�� ���ҵ�һ��δ�����߶�Ӧ�ĵ� -�����ò��Һ���
    printf("%c ",g->vertexs[nodeIndex]);
    visited[nodeIndex]=1;
    int i;

    for(i=0;i<g->vertexNum;i++){
        if(g->edges[nodeIndex][i]!=FINITY && visited[i]==0){
            DFS_MatrixGraph(g,i,visited);
        }
    }
}

//������ȱ���(�ڽӾ���
void BreadthFirstSearch_MatrixGraph(MatrixGraph *g){
    int visited[MaxNode]={0};
    int i,j;

    for(i=0;i<g->vertexNum;i++){
        printf("��%d��㿪ʼ���ڽӾ����ȱ�����",i);
        BFS_MatrixGraph(g,i,visited);
        for(j=0;j<g->vertexNum;j++){
            visited[j]=0;
        }
        printf("\n");
    }
}

//������Ȳ���(�ڽӾ���
void BFS_MatrixGraph(MatrixGraph *g,int nodeIndex,int visited[]){
    //�ö��б��������
    int queue[MaxNode];
    int rear,front,i,j;
    rear=front=0;

    printf("%c ",g->vertexs[nodeIndex]);
    visited[nodeIndex]=1;
    queue[rear] = nodeIndex;//���
    rear++;

    while(rear>front)//���в��գ�˵������Ȼ�����Ա���
    {
        nodeIndex = queue[front];//����
        front++;

        for(i=0;i<g->vertexNum;i++){//�����ýڵ�ָ�������δ���ʹ��Ľ��
            if(g->edges[nodeIndex][i] != FINITY && visited[i]==0){
                printf("%c ",g->vertexs[i]);
                visited[i]=1;
                queue[rear]=i;
                rear++;
            }
        }
    }
}

//�������ֵ�ͱ�ֵ
void PrintMatrixData(MatrixGraph *g){
    int i,j;

    printf("����ֵ:");
    for(i=0;i<g->vertexNum;i++){
        printf("%c ",g->vertexs[i]);
    }
    printf("\n��ֵ:\n");
    for(i=0;i<g->vertexNum;i++){
        for(j=0;j<g->vertexNum;j++){
            if(g->edges[i][j]==FINITY){
                printf("FINITY ");
            }else{
                printf("%6d ",g->edges[i][j]);
            }
        }
        printf("\n");
    }
}

//�ڽӱ�Ķ���
typedef struct edge{
    int vertexIndex;
    int edgeNetData;
    struct edge *next;
}EdgeNode;

typedef struct vertex{
    int vertexData;
    EdgeNode *firstEdge;
}VertexNode;

typedef struct gra{
    VertexNode list[MaxNode];
    int vertexNum,edgeNum;
}LinkGraph;

//�����ڽӱ�
LinkGraph *CreateLinkGraph(char *fileName,int hasDirection){
    FILE *dataFile;
    LinkGraph *g;
    EdgeNode *t;
    int i,j,startVertex,endVertex,edgeData;

    g=(LinkGraph *)malloc(sizeof(LinkGraph));
    dataFile = fopen(fileName,"r");

    if(dataFile){
        //�������� �ߵĹ�ϵ ������� �ߵĸ���
        //��ȡ-������
        fscanf(dataFile,"%d%d",&g->vertexNum,&g->edgeNum);//��ȡ����ͱ߸���

        for(i=0;i<g->vertexNum;i++){//��ȡ�����ö�������
            fscanf(dataFile,"%d",&g->list[i].vertexData);
            g->list[i].firstEdge=NULL;
        }
        printf("\n");

        for(j=0;j<g->edgeNum;j++){//��ȡ�������ߵ�����
            fscanf(dataFile,"%d%d%d",&startVertex,&endVertex,&edgeData);//��ȡ

            t=(EdgeNode *)malloc(sizeof(EdgeNode));
            t->vertexIndex=endVertex;//���ñ�ָ���������
            t->edgeNetData=edgeData;

            //ͷ�巨
            t->next=g->list[startVertex].firstEdge;
            g->list[startVertex].firstEdge=t;

            if(!hasDirection){//��������ͼ�ı�
                t=(EdgeNode *)malloc(sizeof(EdgeNode));
                t->vertexIndex=startVertex;

                t->next=g->list[endVertex].firstEdge;
                g->list[endVertex].firstEdge=t;
            }
        }
        fclose(dataFile);
        return g;
    }else{
        printf("Read file failed!");
        return NULL;
    }
}

//�������ڽӱ�(һ������)
LinkGraph *CreateLinkGraph_Reverse(char *fileName){
    FILE *dataFile;
    LinkGraph *g;
    EdgeNode *t;
    int i,j,startVertex,endVertex,edgeData;

    g=(LinkGraph *)malloc(sizeof(LinkGraph));
    dataFile = fopen(fileName,"r");

    if(dataFile){
        //�������� �ߵĹ�ϵ ������� �ߵĸ���
        //��ȡ-������
        fscanf(dataFile,"%d%d",&g->vertexNum,&g->edgeNum);//��ȡ����ͱ߸���

        for(i=0;i<g->vertexNum;i++){//��ȡ�����ö�������
            fscanf(dataFile,"%d",&g->list[i].vertexData);
            g->list[i].firstEdge=NULL;
        }
        printf("\n");

        for(j=0;j<g->edgeNum;j++){//��ȡ�������ߵ�����
            fscanf(dataFile,"%d%d%d",&startVertex,&endVertex,&edgeData);//��ȡ

            t=(EdgeNode *)malloc(sizeof(EdgeNode));
            t->vertexIndex=startVertex;//������ʼָ���������
            t->edgeNetData=edgeData;

            //ͷ�巨
            t->next=g->list[endVertex].firstEdge;
            g->list[endVertex].firstEdge=t;
        }
        fclose(dataFile);
        return g;
    }else{
        printf("Read file failed!");
        return NULL;
    }
}


//���
int InDegree_LinkGraph(LinkGraph *g,int i){
    if(g==NULL){
        return 0;
    }

    EdgeNode *t=NULL;
    int j,k,num;

    t=NULL;
    num=0;
    for(j=0;j<g->vertexNum;j++){
        t=g->list[j].firstEdge;
        while(t!=NULL){
            //printf("vertexIndex:%d ",t->vertexIndex);
            if(t->vertexIndex==i){
                num++;
            }
            t=t->next;
        }
    }
    return num;
}

//����
int OutDegree_LinkGraph(LinkGraph *g,int i){
    if(g==NULL){
        return 0;
    }

    EdgeNode *t;
    int num,j;
    num=0;

    t=g->list[i].firstEdge;
    while(t!=NULL){
        num++;
        t=t->next;
    }
    return num;
}

/*
//������ȱ�����ջ
typedef struct sta{
    int a[MaxNode];
    int top;
}stack;


//����ջ
stack *CreateStack(){
    stack *s;
    s=(stack *)malloc(sizeof(stack));
    s->top=0;
    return s;
}

//��ջ
void Push(stack *s,int nodeIndex){
    s->a[s->top]=nodeIndex;
    s->top++;
}

//��ջ
int Pop(stack *s){
    s->top--;
    return s->a[s->top];
}

//�п�
int isStackEmpty(stack *s){
    if(s->top<=0){
        return 1;
    }else{
        return 0;
    }
}
*/

//������ȱ���
void DepthFirstTraverse_LinkGraph(LinkGraph *g){
    int i,j;
    int visited[MaxNode]={0};

    for(i=0;i<g->vertexNum;i++){
        printf("��%d��㿪ʼ�ڽӱ���ȱ�����",i);
        DFS_LinkGraph(g,i,visited);
        printf("\n");
        for(j=0;j<g->vertexNum;j++){
            visited[j]=0;
        }
    }
}

//������Ȳ���
void DFS_LinkGraph(LinkGraph *g,int i,int visited[]){
    printf("%d ",i,g->list[i].vertexData);
    visited[i]=1;

    EdgeNode *t;
    t=g->list[i].firstEdge;
    while(t){
        if(visited[t->vertexIndex]==0){
            DFS_LinkGraph(g,t->vertexIndex,visited);
        }
        t=t->next;
    }

}

//������ȱ���
void BreadthFirstSearch_LinkGraph(LinkGraph *g){
    int visited[MaxNode]={0};
    int i,j;

    for(i=0;i<g->vertexNum;i++){
        printf("��%d��㿪ʼ�ڽӱ��ȱ�����",i);
        BFS_LinkGraph(g,i,visited);
        printf("\n");
        for(j=0;j<g->vertexNum;j++){
            visited[j]=0;
        }
    }
}

//������Ȳ���(��nodeIndex��ʼ�Ĺ�����ȱ���
void BFS_LinkGraph(LinkGraph *g,int nodeIndex,int visited[]){
    int i;
    EdgeNode *t;

    int queue[MaxNode],front,rear;
    front=0;
    rear=0;

    printf("%d ",g->list[nodeIndex].vertexData);//�����һ�����ֵ
    visited[nodeIndex]=1;
    queue[rear]=nodeIndex;
    rear++;

    //���η��ʽ���ڽӱ������δ�����ʹ���ֵ
    while(rear>front){//���в�Ϊ��
        i = queue[front];
        front++;
        t=g->list[i].firstEdge;

        //���ʵ�ǰ����ڽӱ������ֵ
        while(t!=NULL){//�߲�Ϊ��
            if(visited[t->vertexIndex] == 0){//���δ�����ʹ��������
                printf("%d ",g->list[t->vertexIndex].vertexData);
                visited[t->vertexIndex]=1;
                queue[rear]=t->vertexIndex;
                rear++;
            }
            //ִ�е��⣬���һ�������ʹ�,������һ�����
            t=t->next;
        }
    }
}

//����ڽӱ�Ķ���ֵ�ͱ�
void PrintLinkGraph(LinkGraph *g){
    int i,j;
    EdgeNode *t;

    printf("����ֵ:");
    for(i=0;i<g->vertexNum;i++){
        printf("%d ",g->list[i].vertexData);
    }
    printf("\n");

    printf("��\n");
    for(j=0;j<g->vertexNum;j++){
        printf("���:%d",j,g->list[j].vertexData);
        t=g->list[j].firstEdge;
        while(t!=NULL){
            printf("->%d",t->vertexIndex);
            t=t->next;
        }
        printf("\n");
    }
    printf("\n");
}

//���Prim�㷨����С������(������б�
void PrintByPrim_LinkGraph(LinkGraph *g){

}




int main()
{
    printf("--------�ڽӱ�---------");
    LinkGraph *linkG;
    linkG=CreateLinkGraph("linkGraphData01.txt",1);
    PrintLinkGraph(linkG);
    printf("���1����ȣ�%d\n",InDegree_LinkGraph(linkG,2));
    printf("���0�ĳ��ȣ�%d\n",OutDegree_LinkGraph(linkG,2));
    DepthFirstTraverse_LinkGraph(linkG);
    BreadthFirstSearch_LinkGraph(linkG);

    printf("\n���ڽӱ�");
    LinkGraph *RlinkG;
    RlinkG=CreateLinkGraph_Reverse("linkGraphData01.txt");
    PrintLinkGraph(RlinkG);
    printf("\n");

    printf("\n--------�ڽӾ���---------\n");
    int visited[MaxNode]={0};
    int i,j;
    MatrixGraph *g;
    g=CreateMatrixGraph("graphData01.txt",1);
    PrintMatrixData(g);

    printf("\n");
    printf("0->1�ߵ�ֵ:%d\n",Exist_MatrixGraph(g,0,1));
    printf("����:%d\n",Edges_MatrixGraph(g));
    printf("������:%d\n",Vertices_MatrixGraph(g));
    printf("���1�����:%d\n",InDegree_MatrixGraph(g,1));
    printf("���1�ĳ���:%d\n",OutDegree_MatrixGraph(g,1));
    DepthFirstTraverse_MatrixGraph(g);
    BreadthFirstSearch_MatrixGraph(g);
}
