#include <stdio.h>
#include <stdlib.h>
#define maxChild 3
#define MaxStackLength 100
#define MaxQueueLenght 100
#define MaxBinTreeRoots 100
//关于树的所有代码都会写在此项目

//树的定义（数据为存字符）
typedef struct n{
    char data;
    struct n* child[maxChild];
}tree;

//创建一个树
tree *CreateTree(){
    //创建一个根-》初始化其子树
    tree *t;
    t=(tree *)malloc(sizeof(tree));
    char c;
    c=getchar();

    if(c == '#'){//输入#表示根为空
        return NULL;
    }
    t->data=c;

    //初始化该根所有子树
    int i;
    for(i=0;i<maxChild;i++){
        t->child[i]=CreateTree();
    }
    return t;
}

//先序遍历树 注:traversal 遍历
void Pre_TraversalTree(tree *t){
    //树为空-》返回
    //树不为空-》输出根的data-》输出所有子树的data
    int i;
    if(t==NULL){
        return ;
    }

    printf("%c ",t->data);
    for(i=0;i<maxChild;i++){//输出子树data
        Pre_TraversalTree(t->child[i]);
    }
}

//后序遍历树
void Post_TraversalTree(tree *t){
    //树为空-》返回
    //树不空-》输出所有子树的data-》输出根的data
    int i;
    if(t== NULL){
        return;
    }

    for(i=0;i<maxChild;i++){
        Post_TraversalTree(t->child[i]);
    }
    printf("%c ",t->data);
}

int FindData_Tree(tree *t,char findChar){
    //用前序或后续遍历树
    //树为空-》返回0
    //找到-》返回1  没找到继续找 如果全部遍历完返回0
    int i,isFind;
    if(t==NULL){
        return 0;
    }

    if(t->data == findChar){
        return 1;
    }

    for(i=0;i<maxChild;i++){//遍历根的全部子树
        isFind=FindData_Tree(t->child[i],findChar);
        if(isFind==1){
            return 1;//在某一个子树下找到需要数据，返回，函数结束，不再
            //继续查找剩下的子树
        }
    }

    //for循环结束，表示全部的子树找完，都没有触发for中的return函数，即未找到
    //既然未找到，那么此时返回0表示整个树中未找到需要的数据
    return 0;

}


////////
//以下代码为整形二叉树部分
////////

typedef struct bt{
    int data;
    struct bt *leftChild;
    struct bt *rightChild;
}binTree;

//前序创建二叉树
binTree *CreateBinTree(){
    int x;
    scanf("%d",&x);

    if(x==-1){
        return NULL;
    }

    binTree *t;
    t=(binTree *)malloc(sizeof(binTree));
    t->data=x;
    t->leftChild=CreateBinTree();
    t->rightChild=CreateBinTree();
}

//递归前序遍历二叉树
void Pre_TraversalBinTree(binTree *t){
    if(t==NULL){
        return;
    }

    printf("%d ",t->data);
    Pre_TraversalBinTree(t->leftChild);
    Pre_TraversalBinTree(t->rightChild);
}

//递归中序遍历二叉树
void Mid_TraversalBinTree(binTree *t){
    if(t==NULL){
        return;
    }

    Mid_TraversalBinTree(t->leftChild);
    printf("%d ",t->data);
    Mid_TraversalBinTree(t->rightChild);
}

//递归后续遍历二叉树
void Post_TraversalBinTree(binTree *t){
    if(t==NULL){
        return;
    }

    Post_TraversalBinTree(t->leftChild);
    Post_TraversalBinTree(t->rightChild);
    printf("%d ",t->data);
}

//递归查找树种最大值对应的结点
binTree *Max_BinTree(binTree *t,int max){
    if(t==NULL){
        return NULL;
    }
    binTree *maxLeftNode,*maxRightNode;

    if(t->data > max){
        max=t->data;
    }

    maxLeftNode=Max_BinTree(t->leftChild,max);
    maxRightNode=Max_BinTree(t->rightChild,max);

    if(maxLeftNode!=NULL && maxRightNode!=NULL){
        if(maxLeftNode->data > maxRightNode->data){
            return maxLeftNode;
        }else{
            return maxRightNode;
        }
    }

    if(maxLeftNode!=NULL && maxRightNode==NULL){
        return maxLeftNode;
    }

    if(maxLeftNode==NULL && maxRightNode!=NULL){
        return maxRightNode;
    }

    return t;
}

//二度结点个数
int TwoChildRoot_BinTree(binTree *t){
    if(t==NULL){
        return 0;
    }
    int sum=0;

    if(t->leftChild!=NULL && t->rightChild!=NULL){
        sum++;
    }

    sum+=TwoChildRoot_BinTree(t->leftChild);
    sum+=TwoChildRoot_BinTree(t->rightChild);
    return sum;
}

//二叉树的合并
binTree *Merge_TwoBinTree(binTree *t1,binTree *t2){
    if(t1==NULL && t2==NULL){
        return NULL;
    }

    if(t1==NULL && t2!=NULL){
        return t2;
    }

    if(t1!=NULL && t2==NULL){
        return t1;
    }

    if(t1!=NULL && t2!=NULL){
        t1->data+=t2->data;
    }

    t1->leftChild=Merge_TwoBinTree(t1->leftChild,t2->leftChild);
    t1->rightChild=Merge_TwoBinTree(t1->rightChild,t2->rightChild);
    return t1;
}

//建二叉树的栈，为非递归遍历二叉树做准备
typedef struct stack{
    binTree *a[MaxStackLength];
    int top;
}binTreeStack;

//创建栈
binTreeStack *Create_BinTreeStack(){
    binTreeStack *s;
    s=(binTreeStack *)malloc(sizeof(binTreeStack));
    s->top=0;
    return s;
}

//入栈
void Push_BinTreeStack(binTreeStack *s,binTree *t){
    if(s->top+1>MaxStackLength){
        printf("Stack is full, push failed!");
        return;
    }
    s->a[s->top]=t;
    s->top++;
}

//判断栈空
int isBinTreeStackEmpty(binTreeStack *s){
    if(s->top==0){
        return 1;
    }else{
        return 0;
    }
}

//出栈
binTree *Pop_BinTreeStack(binTreeStack *s){
    if(s->top==0){
        printf("Stack is null, pop failed!");
        return NULL;
    }

    s->top--;
    return s->a[s->top];
}

//非递归前序遍历二叉树
void Pre_TraversalBinTree_UnRecursion(binTree *t){//recursion 递归
    if(t==NULL){
        return;
    }

    binTreeStack *s;
    s=Create_BinTreeStack();

    while(t!=NULL || isBinTreeStackEmpty(s)==0){
        if(t!=NULL){
            printf("%d ",t->data);
            Push_BinTreeStack(s,t);
            t=t->leftChild;
        }else{
            t=Pop_BinTreeStack(s);
            t=t->rightChild;
        }
    }

}

//非递归中序遍历二叉树
void Mid_TraversalBinTree_UnRecursion(binTree *t){
    if(t==NULL){
        return;
    }

    binTreeStack *s;
    s=Create_BinTreeStack();

    while(t!=NULL || isBinTreeStackEmpty(s)==0){
        if(t!=NULL){
            Push_BinTreeStack(s,t);
            t=t->leftChild;
        }else{
            t=Pop_BinTreeStack(s);
            //走到这说明左侧全部走完，开始回溯到根的位置，此时输出根的数据,再进入右侧
            printf("%d ",t->data);
            t=t->rightChild;
        }
    }
}

// 2021-5-11 第十一周作业

//找到值对应的结点，返回节点高度
int FindAndGetHeight_BinTree(binTree *t,int findData,int height){
    if(t==NULL){
        return -1;
    }

    if(t->data == findData){//找到
        return height;
    }

    int nodeHeight=0;
    nodeHeight=FindAndGetHeight_BinTree(t->leftChild,findData,height+1);//左子树里找
    if(nodeHeight!=-1){//如果找到
        return nodeHeight;
    }
    nodeHeight=FindAndGetHeight_BinTree(t->rightChild,findData,height+1);//右子树里找
    if(nodeHeight!=-1){//如果找到
        return nodeHeight;
    }
    //执行到此处，说明根本身+左子树+右子树都没找到,那么结果没找到
    return -1;
}

//将二叉树的左右子树互换
void ExchangeChild_BinTree(binTree *t){
    if(t==NULL){
        return ;
    }

    ExchangeChild_BinTree(t->leftChild);//换左子树
    ExchangeChild_BinTree(t->rightChild);//换右子树

    binTree *temp;//换的具体操作
    temp=t->leftChild;
    t->leftChild=t->rightChild;
    t->rightChild=temp;
}

//整形二叉树对应的队列
typedef struct queue{
    binTree *a[MaxQueueLenght];
    int front,rear;
}binTreeQueue;

//创建队列
binTreeQueue *Create_BinTreeQueue(){
    binTreeQueue *q;
    q=(binTreeQueue *)malloc(sizeof(binTreeQueue));
    q->front=0;
    q->rear=0;
    return q;
}

//入队
void EnBinTreeQueue(binTreeQueue *q,binTree *t){
    if((q->rear+1)%MaxQueueLenght==q->front){
        printf("Queue is full, EnQqueue failed!");
        return;
    }
    q->a[q->rear]=t;
    q->rear= (q->rear+1)%MaxQueueLenght;
}

//出队
binTree *OutBinTreeQueue(binTreeQueue *q){
    binTree *temp;
    temp=q->a[q->front];
    q->front= (q->front+1)%MaxQueueLenght;
    return temp;
}

//判断队列是否为空
int isBinTreeQueueEmpty(binTreeQueue *q){
    if(q->front==q->rear){
        return 1;
    }else{
        return 0;
    }
}

//二叉树的层次遍历
void TraversalByLayers_BinTree(binTree *t){
    if(t==NULL){
        return;
    }
    //注：层次遍历需要队列协助实现
    binTreeQueue *q;
    binTree *temp;
    q=Create_BinTreeQueue();
    temp=t;

    //层次遍历入队，出队
    while(temp!=NULL || isBinTreeQueueEmpty(q)==0){
        if(temp!=NULL){//输出
            printf("%d ",temp->data);
        }
        if(temp->leftChild==NULL && temp->rightChild==NULL && isBinTreeQueueEmpty(q)==1){
            break;//如果当前根的孩子都为空，且队列也为空，则表示没有结点可以输出，输出结束，跳出循环
        }

        if(temp->leftChild!=NULL){//左孩子入队
            EnBinTreeQueue(q,temp->leftChild);
        }
        if(temp->rightChild!=NULL){//右孩子入队
            EnBinTreeQueue(q,temp->rightChild);
        }

        temp=OutBinTreeQueue(q);//得到最先入队的根
    }
}

//前序首点
binTree *PreFirstRoot_BinTree(binTree *t){
    return t;//前序首点-》根
}

//前序尾点
binTree *PreLastRoot_BinTree(binTree *t){
    if(t==NULL){
        return NULL;
    }
    binTree *temp;
    temp=t;
    //思路：先根后子树-》有子树就往下走，右子树优先，没有右子树就走左子树，
    //直到走到底,则得到尾点
    while(temp->rightChild!=NULL || temp->leftChild!=NULL){
        if(temp->rightChild!=NULL){
            temp=temp->rightChild;
        }else{
            temp=temp->rightChild;
        }
    }
    return temp;
}

//中序首点
binTree *MidFirstRoot_BinTree(binTree *t){
    if(t==NULL){
        return NULL;
    }
    //思路：中序：左孩子-》根-》右孩子，那么最左的就是首点
    binTree *temp;
    while(temp->leftChild!=NULL){
        temp=temp->leftChild;
    }
    return temp;
}

//中序尾点
binTree *MidLastRoot_BinTree(binTree *t){
    if(t==NULL){
        return NULL;
    }
    binTree *temp;
    while(temp->rightChild!=NULL){
        temp=temp->rightChild;
    }
    return temp;
}

//后序首点
binTree *PostFirstRoot_BinTree(binTree *t){
    if(t==NULL){
        return NULL;
    }
    binTree *temp;
    temp=t;

    while(temp->rightChild!=NULL || temp->leftChild!=NULL){
        if(temp->leftChild!=NULL){
            temp=temp->leftChild;
        }else{
            temp=temp->rightChild;
        }
    }
    return temp;
}

//后序尾点
binTree *PostLasrRoot_BinTree(binTree *t){
    return t;//先孩子后根，t为树根，最后
}

///给定前序和中序创建二叉树
//pre：1 2 4 5 3 6 7 0
//mid：4 2 5 1 6 3 7 0
binTree *CreateBinTree_Mid(int pre[],int mid[],int left,int right){
    //根据pre 找到中点值
    //根据mid找到中点值的左边 建立左子树
    //填入当前根的值
    //根据mid找到中点值的右边 建立右子树
    static int index=0;
    if(left > right){
        index--;
        return NULL;
    }

    binTree *t;
    t=(binTree *)malloc(sizeof(binTree));

    int num;
    num=pre[index];
    for(int i=left;i<=right;i++){
        if(mid[i]==num){
            index++;
            t->leftChild=CreateBinTree_Mid(pre,mid,left,i-1);
            t->data=num;
            index++;
            t->rightChild=CreateBinTree_Mid(pre,mid,i+1,right);
        }
    }
    return t;
}

int main()
{

    //二叉树
    //建树数据①：1 2 -1 -1 3 -1 -1
    //建树数据②：1 2 4 -1 -1 -1 -1
    //建树数据③：4 2 1 -1 -1 3 -1 -1 6 5 -1 -1 7 -1 -1
    binTree *t,*max,*q,*pmid;

    ///给定前序和中序创建二叉树
    int twoChildCount,data,i=0,j=0;
    int pre[MaxBinTreeRoots],mid[MaxBinTreeRoots];
    printf("请输入前序序列：(0作为序列结尾)");
    scanf("%d",&data);
    while(data!=0){
        pre[i]=data;
        i++;
        scanf("%d",&data);
    }
    printf("\n请输入中序序列：(0作为序列结尾)");
    scanf("%d",&data);
    while(data!=0){
        mid[j]=data;
        j++;
        scanf("%d",&data);
    }
    pmid=CreateBinTree_Mid(pre,mid,0,j-1);
    printf("\n前序遍历树：");
    Pre_TraversalBinTree(pmid);
    printf("\n中序遍历树：");
    Mid_TraversalBinTree(pmid);
    printf("\n后续遍历树：");
    Post_TraversalBinTree(pmid);

    //创建二叉树
    printf("\nPlease input data in bin tree:(-1 as stop)");
    t=CreateBinTree();
    printf("二叉树的层次遍历：");
    TraversalByLayers_BinTree(t);
    printf("\n前序遍历树：");
    Pre_TraversalBinTree(t);
    printf("\n中序遍历树：");
    Mid_TraversalBinTree(t);
    //子树互换
    printf("\n----------子树互换--------\n");
    ExchangeChild_BinTree(t);
    printf("前序遍历树：");
    Pre_TraversalBinTree(t);
    printf("\n中序遍历树：");
    Mid_TraversalBinTree(t);
    /*
    printf("Please input data in bin 2 tree:(-1 as stop)");
    q=CreateBinTree();
    */

    //得到某个结点的树高
    int height,findData;
    printf("\nPlease input data need to find:");
    scanf("%d",&findData);
    height=FindAndGetHeight_BinTree(t,findData,0);
    if(height!=-1){
        printf("找到的数据所在根的树高为：%d\n",height);
    }else{
        printf("未找到数据！\n");
    }

    //各种遍历
    printf("前序遍历树：");
    Pre_TraversalBinTree(t);
    printf("\n非递归前序遍历树：");
    Pre_TraversalBinTree_UnRecursion(t);
    printf("\n中序遍历树：");
    Mid_TraversalBinTree(t);
    printf("\n非递归中序遍历树：");
    Mid_TraversalBinTree_UnRecursion(t);
    printf("\n后续遍历树：");
    Post_TraversalBinTree(t);

    //得到树的最大值
    max=Max_BinTree(t,-1);
    printf("\n最大值为：%d",max->data);

    //二度节点数
    twoChildCount=TwoChildRoot_BinTree(t);
    printf("\n该树二度结点个数：%d",twoChildCount);

    /*
    t=Merge_TwoBinTree(t,q);
    printf("\n前序遍历树：");
    Pre_TraversalBinTree(t);
    */



    //3度结点树
    /*
    tree *t;
    char find;
    printf("请输入树的数据：(# 作为停止，树的度为%d,每个根存一个字符)\n",maxChild);
    t=CreateTree();
    printf("前序遍历树：");
    Pre_TraversalTree(t);
    printf("\n后续遍历树:");
    Post_TraversalTree(t);
    printf("\n");

    while(1){
        printf("请输入需要查找的数据：");
        getchar();
        find=getchar();
        if(FindData_Tree(t,find)){
            printf("查找到数据！\n");
        }else{
            printf("未找到数据！\n");
        }
    }
    */
}
