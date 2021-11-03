#include <stdio.h>
#include <stdlib.h>
#define MaxNode 20
#define FINITY 10000

//关于图的所有代码都会写在此项目

//邻边矩阵结构的定义
typedef struct graph{
    char vertexs[MaxNode];//顶点存储的数据
    int edges[MaxNode][MaxNode];//二维矩阵存储顶点之间边的关系-> 0为没有边 1为有边
    int vertexNum,edgeNum,hasDirection;
}MatrixGraph;//Matrix->矩阵

//创建网络邻接矩阵
MatrixGraph *CreateMatrixGraph(char *txtName,int hasDirectionGraph){
    FILE *txt;
    MatrixGraph *graph;
    int i,j,startIndex,endIndex;
    int edgeInform;

    graph=(MatrixGraph *)malloc(sizeof(MatrixGraph));
    graph->hasDirection=hasDirectionGraph;//设置邻接矩阵的有向性
    txt=fopen(txtName,"r");//Read data in the txt
    //读取顶点+边数-》读取节点值-》读取边值
    if(txt==NULL){
        printf("Read failed!");
        graph=NULL;
        return graph;
    }

    fscanf(txt,"%d%d",&graph->vertexNum,&graph->edgeNum);//读取顶点数和边数
    fscanf(txt,"%c");//读取第一行的换行符
    for(i=0;i<=graph->vertexNum;i++){//读取节点值
        fscanf(txt,"%c",&graph->vertexs[i]);
    }
    //初始化邻接矩阵边的关系
    for(i=0;i<graph->vertexNum;i++){
        for(j=0;j<graph->vertexNum;j++){
            graph->edges[i][j]=FINITY;//FINITY 表示两节点没有关系
        }
    }

    //邻接矩阵边的读取
    for(i=0;i<graph->edgeNum;i++){
        fscanf(txt,"%d%d%d",&startIndex,&endIndex,&edgeInform);
        graph->edges[startIndex][endIndex]=edgeInform;//有向邻接矩阵

        if(!hasDirectionGraph){
            graph->edges[endIndex][startIndex]=edgeInform;//无向邻接矩阵的建立
        }
    }

    fclose(txt);
    return graph;
}

//判断边(i,j)是否存在—>第i个结点和第j个结点的边
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

//返回邻接矩阵中边的数目
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

//返回图中顶点的数目
int Vertices_MatrixGraph(MatrixGraph *g){
    if(g==NULL){
        return 0;
    }

    return g->vertexNum;
}

//向图中添加边
void Add_MatrixGraph(MatrixGraph *g,int i,int j,int edgeInform){
    g->edges[i][j]=edgeInform;
    if(!g->hasDirection){
        g->edges[j][i]=edgeInform;
    }
    g->edgeNum++;
}

//删除边
void Delete_MatrixGraph(MatrixGraph *g,int i,int j){
    g->edges[i][j]=FINITY;
    if(!g->hasDirection){
        g->edges[j][i]=FINITY;
    }
    g->edgeNum--;
}

//返回顶点i的入度
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

//返回顶点i的出度
int OutDegree_MatrixGraph(MatrixGraph *g,int i){
    int num=0;
    int j;
    for(j=0;j<Vertices_MatrixGraph(g);j++){
        if(g->edges[i][j]!=FINITY){//与入度不同的一行
            num++;
        }
    }
    return num;
}

//深度优先遍历(邻接矩阵
void DepthFirstTraverse_MatrixGraph(MatrixGraph *g){
    int visited[MaxNode]={0};
    int i,j;

    for(i=0;i<g->vertexNum;i++){
        printf("第%d结点开始的邻接矩阵深度遍历：",i);
        DFS_MatrixGraph(g,i,visited);
        for(j=0;j<g->vertexNum;j++){
            visited[j]=0;
        }
        printf("\n");
    }
}

//深度优先查找(邻接矩阵
void DFS_MatrixGraph(MatrixGraph *g,int nodeIndex,int visited[]){
    //遍历第一个点 -》 查找第一个未遍历边对应的点 -》调用查找函数
    printf("%c ",g->vertexs[nodeIndex]);
    visited[nodeIndex]=1;
    int i;

    for(i=0;i<g->vertexNum;i++){
        if(g->edges[nodeIndex][i]!=FINITY && visited[i]==0){
            DFS_MatrixGraph(g,i,visited);
        }
    }
}

//广度优先遍历(邻接矩阵
void BreadthFirstSearch_MatrixGraph(MatrixGraph *g){
    int visited[MaxNode]={0};
    int i,j;

    for(i=0;i<g->vertexNum;i++){
        printf("第%d结点开始的邻接矩阵广度遍历：",i);
        BFS_MatrixGraph(g,i,visited);
        for(j=0;j<g->vertexNum;j++){
            visited[j]=0;
        }
        printf("\n");
    }
}

//广度优先查找(邻接矩阵
void BFS_MatrixGraph(MatrixGraph *g,int nodeIndex,int visited[]){
    //用队列保存遍历点
    int queue[MaxNode];
    int rear,front,i,j;
    rear=front=0;

    printf("%c ",g->vertexs[nodeIndex]);
    visited[nodeIndex]=1;
    queue[rear] = nodeIndex;//入队
    rear++;

    while(rear>front)//队列不空，说明有仍然结点可以遍历
    {
        nodeIndex = queue[front];//出队
        front++;

        for(i=0;i<g->vertexNum;i++){//遍历该节点指向的所有未访问过的结点
            if(g->edges[nodeIndex][i] != FINITY && visited[i]==0){
                printf("%c ",g->vertexs[i]);
                visited[i]=1;
                queue[rear]=i;
                rear++;
            }
        }
    }
}

//输出顶点值和边值
void PrintMatrixData(MatrixGraph *g){
    int i,j;

    printf("顶点值:");
    for(i=0;i<g->vertexNum;i++){
        printf("%c ",g->vertexs[i]);
    }
    printf("\n边值:\n");
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

//邻接表的定义
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

//创建邻接表
LinkGraph *CreateLinkGraph(char *fileName,int hasDirection){
    FILE *dataFile;
    LinkGraph *g;
    EdgeNode *t;
    int i,j,startVertex,endVertex,edgeData;

    g=(LinkGraph *)malloc(sizeof(LinkGraph));
    dataFile = fopen(fileName,"r");

    if(dataFile){
        //顶点数据 边的关系 顶点个数 边的个数
        //读取-》设置
        fscanf(dataFile,"%d%d",&g->vertexNum,&g->edgeNum);//读取顶点和边个数

        for(i=0;i<g->vertexNum;i++){//读取并设置顶点数据
            fscanf(dataFile,"%d",&g->list[i].vertexData);
            g->list[i].firstEdge=NULL;
        }
        printf("\n");

        for(j=0;j<g->edgeNum;j++){//读取并建立边的数据
            fscanf(dataFile,"%d%d%d",&startVertex,&endVertex,&edgeData);//读取

            t=(EdgeNode *)malloc(sizeof(EdgeNode));
            t->vertexIndex=endVertex;//设置被指向结点的索引
            t->edgeNetData=edgeData;

            //头插法
            t->next=g->list[startVertex].firstEdge;
            g->list[startVertex].firstEdge=t;

            if(!hasDirection){//设置无向图的边
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

//创建逆邻接表(一定有向)
LinkGraph *CreateLinkGraph_Reverse(char *fileName){
    FILE *dataFile;
    LinkGraph *g;
    EdgeNode *t;
    int i,j,startVertex,endVertex,edgeData;

    g=(LinkGraph *)malloc(sizeof(LinkGraph));
    dataFile = fopen(fileName,"r");

    if(dataFile){
        //顶点数据 边的关系 顶点个数 边的个数
        //读取-》设置
        fscanf(dataFile,"%d%d",&g->vertexNum,&g->edgeNum);//读取顶点和边个数

        for(i=0;i<g->vertexNum;i++){//读取并设置顶点数据
            fscanf(dataFile,"%d",&g->list[i].vertexData);
            g->list[i].firstEdge=NULL;
        }
        printf("\n");

        for(j=0;j<g->edgeNum;j++){//读取并建立边的数据
            fscanf(dataFile,"%d%d%d",&startVertex,&endVertex,&edgeData);//读取

            t=(EdgeNode *)malloc(sizeof(EdgeNode));
            t->vertexIndex=startVertex;//设置起始指向结点的索引
            t->edgeNetData=edgeData;

            //头插法
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


//入度
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

//出度
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
//深度优先遍历的栈
typedef struct sta{
    int a[MaxNode];
    int top;
}stack;


//创建栈
stack *CreateStack(){
    stack *s;
    s=(stack *)malloc(sizeof(stack));
    s->top=0;
    return s;
}

//入栈
void Push(stack *s,int nodeIndex){
    s->a[s->top]=nodeIndex;
    s->top++;
}

//出栈
int Pop(stack *s){
    s->top--;
    return s->a[s->top];
}

//判空
int isStackEmpty(stack *s){
    if(s->top<=0){
        return 1;
    }else{
        return 0;
    }
}
*/

//深度优先遍历
void DepthFirstTraverse_LinkGraph(LinkGraph *g){
    int i,j;
    int visited[MaxNode]={0};

    for(i=0;i<g->vertexNum;i++){
        printf("第%d结点开始邻接表深度遍历：",i);
        DFS_LinkGraph(g,i,visited);
        printf("\n");
        for(j=0;j<g->vertexNum;j++){
            visited[j]=0;
        }
    }
}

//深度优先查找
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

//广度优先遍历
void BreadthFirstSearch_LinkGraph(LinkGraph *g){
    int visited[MaxNode]={0};
    int i,j;

    for(i=0;i<g->vertexNum;i++){
        printf("第%d结点开始邻接表广度遍历：",i);
        BFS_LinkGraph(g,i,visited);
        printf("\n");
        for(j=0;j<g->vertexNum;j++){
            visited[j]=0;
        }
    }
}

//广度优先查找(从nodeIndex开始的广度优先遍历
void BFS_LinkGraph(LinkGraph *g,int nodeIndex,int visited[]){
    int i;
    EdgeNode *t;

    int queue[MaxNode],front,rear;
    front=0;
    rear=0;

    printf("%d ",g->list[nodeIndex].vertexData);//输出第一个结点值
    visited[nodeIndex]=1;
    queue[rear]=nodeIndex;
    rear++;

    //依次访问结点邻接表的所有未被访问过的值
    while(rear>front){//队列不为空
        i = queue[front];
        front++;
        t=g->list[i].firstEdge;

        //访问当前结点邻接表的所有值
        while(t!=NULL){//边不为空
            if(visited[t->vertexIndex] == 0){//结点未被访问过，则访问
                printf("%d ",g->list[t->vertexIndex].vertexData);
                visited[t->vertexIndex]=1;
                queue[rear]=t->vertexIndex;
                rear++;
            }
            //执行到这，结点一定被访问过,访问下一个结点
            t=t->next;
        }
    }
}

//输出邻接表的顶点值和表
void PrintLinkGraph(LinkGraph *g){
    int i,j;
    EdgeNode *t;

    printf("顶点值:");
    for(i=0;i<g->vertexNum;i++){
        printf("%d ",g->list[i].vertexData);
    }
    printf("\n");

    printf("表：\n");
    for(j=0;j<g->vertexNum;j++){
        printf("结点:%d",j,g->list[j].vertexData);
        t=g->list[j].firstEdge;
        while(t!=NULL){
            printf("->%d",t->vertexIndex);
            t=t->next;
        }
        printf("\n");
    }
    printf("\n");
}

//输出Prim算法的最小生成树(输出所有边
void PrintByPrim_LinkGraph(LinkGraph *g){

}




int main()
{
    printf("--------邻接表---------");
    LinkGraph *linkG;
    linkG=CreateLinkGraph("linkGraphData01.txt",1);
    PrintLinkGraph(linkG);
    printf("结点1的入度：%d\n",InDegree_LinkGraph(linkG,2));
    printf("结点0的出度：%d\n",OutDegree_LinkGraph(linkG,2));
    DepthFirstTraverse_LinkGraph(linkG);
    BreadthFirstSearch_LinkGraph(linkG);

    printf("\n逆邻接表：");
    LinkGraph *RlinkG;
    RlinkG=CreateLinkGraph_Reverse("linkGraphData01.txt");
    PrintLinkGraph(RlinkG);
    printf("\n");

    printf("\n--------邻接矩阵---------\n");
    int visited[MaxNode]={0};
    int i,j;
    MatrixGraph *g;
    g=CreateMatrixGraph("graphData01.txt",1);
    PrintMatrixData(g);

    printf("\n");
    printf("0->1边的值:%d\n",Exist_MatrixGraph(g,0,1));
    printf("边数:%d\n",Edges_MatrixGraph(g));
    printf("顶点数:%d\n",Vertices_MatrixGraph(g));
    printf("结点1的入度:%d\n",InDegree_MatrixGraph(g,1));
    printf("结点1的出度:%d\n",OutDegree_MatrixGraph(g,1));
    DepthFirstTraverse_MatrixGraph(g);
    BreadthFirstSearch_MatrixGraph(g);
}
