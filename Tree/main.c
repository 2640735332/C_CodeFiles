#include <stdio.h>
#include <stdlib.h>
#define maxChild 3
#define MaxStackLength 100
#define MaxQueueLenght 100
#define MaxBinTreeRoots 100
//�����������д��붼��д�ڴ���Ŀ

//���Ķ��壨����Ϊ���ַ���
typedef struct n{
    char data;
    struct n* child[maxChild];
}tree;

//����һ����
tree *CreateTree(){
    //����һ����-����ʼ��������
    tree *t;
    t=(tree *)malloc(sizeof(tree));
    char c;
    c=getchar();

    if(c == '#'){//����#��ʾ��Ϊ��
        return NULL;
    }
    t->data=c;

    //��ʼ���ø���������
    int i;
    for(i=0;i<maxChild;i++){
        t->child[i]=CreateTree();
    }
    return t;
}

//��������� ע:traversal ����
void Pre_TraversalTree(tree *t){
    //��Ϊ��-������
    //����Ϊ��-���������data-���������������data
    int i;
    if(t==NULL){
        return ;
    }

    printf("%c ",t->data);
    for(i=0;i<maxChild;i++){//�������data
        Pre_TraversalTree(t->child[i]);
    }
}

//���������
void Post_TraversalTree(tree *t){
    //��Ϊ��-������
    //������-���������������data-���������data
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
    //��ǰ������������
    //��Ϊ��-������0
    //�ҵ�-������1  û�ҵ������� ���ȫ�������귵��0
    int i,isFind;
    if(t==NULL){
        return 0;
    }

    if(t->data == findChar){
        return 1;
    }

    for(i=0;i<maxChild;i++){//��������ȫ������
        isFind=FindData_Tree(t->child[i],findChar);
        if(isFind==1){
            return 1;//��ĳһ���������ҵ���Ҫ���ݣ����أ���������������
            //��������ʣ�µ�����
        }
    }

    //forѭ����������ʾȫ�����������꣬��û�д���for�е�return��������δ�ҵ�
    //��Ȼδ�ҵ�����ô��ʱ����0��ʾ��������δ�ҵ���Ҫ������
    return 0;

}


////////
//���´���Ϊ���ζ���������
////////

typedef struct bt{
    int data;
    struct bt *leftChild;
    struct bt *rightChild;
}binTree;

//ǰ�򴴽�������
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

//�ݹ�ǰ�����������
void Pre_TraversalBinTree(binTree *t){
    if(t==NULL){
        return;
    }

    printf("%d ",t->data);
    Pre_TraversalBinTree(t->leftChild);
    Pre_TraversalBinTree(t->rightChild);
}

//�ݹ��������������
void Mid_TraversalBinTree(binTree *t){
    if(t==NULL){
        return;
    }

    Mid_TraversalBinTree(t->leftChild);
    printf("%d ",t->data);
    Mid_TraversalBinTree(t->rightChild);
}

//�ݹ��������������
void Post_TraversalBinTree(binTree *t){
    if(t==NULL){
        return;
    }

    Post_TraversalBinTree(t->leftChild);
    Post_TraversalBinTree(t->rightChild);
    printf("%d ",t->data);
}

//�ݹ�����������ֵ��Ӧ�Ľ��
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

//���Ƚ�����
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

//�������ĺϲ�
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

//����������ջ��Ϊ�ǵݹ������������׼��
typedef struct stack{
    binTree *a[MaxStackLength];
    int top;
}binTreeStack;

//����ջ
binTreeStack *Create_BinTreeStack(){
    binTreeStack *s;
    s=(binTreeStack *)malloc(sizeof(binTreeStack));
    s->top=0;
    return s;
}

//��ջ
void Push_BinTreeStack(binTreeStack *s,binTree *t){
    if(s->top+1>MaxStackLength){
        printf("Stack is full, push failed!");
        return;
    }
    s->a[s->top]=t;
    s->top++;
}

//�ж�ջ��
int isBinTreeStackEmpty(binTreeStack *s){
    if(s->top==0){
        return 1;
    }else{
        return 0;
    }
}

//��ջ
binTree *Pop_BinTreeStack(binTreeStack *s){
    if(s->top==0){
        printf("Stack is null, pop failed!");
        return NULL;
    }

    s->top--;
    return s->a[s->top];
}

//�ǵݹ�ǰ�����������
void Pre_TraversalBinTree_UnRecursion(binTree *t){//recursion �ݹ�
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

//�ǵݹ��������������
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
            //�ߵ���˵�����ȫ�����꣬��ʼ���ݵ�����λ�ã���ʱ�����������,�ٽ����Ҳ�
            printf("%d ",t->data);
            t=t->rightChild;
        }
    }
}

// 2021-5-11 ��ʮһ����ҵ

//�ҵ�ֵ��Ӧ�Ľ�㣬���ؽڵ�߶�
int FindAndGetHeight_BinTree(binTree *t,int findData,int height){
    if(t==NULL){
        return -1;
    }

    if(t->data == findData){//�ҵ�
        return height;
    }

    int nodeHeight=0;
    nodeHeight=FindAndGetHeight_BinTree(t->leftChild,findData,height+1);//����������
    if(nodeHeight!=-1){//����ҵ�
        return nodeHeight;
    }
    nodeHeight=FindAndGetHeight_BinTree(t->rightChild,findData,height+1);//����������
    if(nodeHeight!=-1){//����ҵ�
        return nodeHeight;
    }
    //ִ�е��˴���˵��������+������+��������û�ҵ�,��ô���û�ҵ�
    return -1;
}

//����������������������
void ExchangeChild_BinTree(binTree *t){
    if(t==NULL){
        return ;
    }

    ExchangeChild_BinTree(t->leftChild);//��������
    ExchangeChild_BinTree(t->rightChild);//��������

    binTree *temp;//���ľ������
    temp=t->leftChild;
    t->leftChild=t->rightChild;
    t->rightChild=temp;
}

//���ζ�������Ӧ�Ķ���
typedef struct queue{
    binTree *a[MaxQueueLenght];
    int front,rear;
}binTreeQueue;

//��������
binTreeQueue *Create_BinTreeQueue(){
    binTreeQueue *q;
    q=(binTreeQueue *)malloc(sizeof(binTreeQueue));
    q->front=0;
    q->rear=0;
    return q;
}

//���
void EnBinTreeQueue(binTreeQueue *q,binTree *t){
    if((q->rear+1)%MaxQueueLenght==q->front){
        printf("Queue is full, EnQqueue failed!");
        return;
    }
    q->a[q->rear]=t;
    q->rear= (q->rear+1)%MaxQueueLenght;
}

//����
binTree *OutBinTreeQueue(binTreeQueue *q){
    binTree *temp;
    temp=q->a[q->front];
    q->front= (q->front+1)%MaxQueueLenght;
    return temp;
}

//�ж϶����Ƿ�Ϊ��
int isBinTreeQueueEmpty(binTreeQueue *q){
    if(q->front==q->rear){
        return 1;
    }else{
        return 0;
    }
}

//�������Ĳ�α���
void TraversalByLayers_BinTree(binTree *t){
    if(t==NULL){
        return;
    }
    //ע����α�����Ҫ����Э��ʵ��
    binTreeQueue *q;
    binTree *temp;
    q=Create_BinTreeQueue();
    temp=t;

    //��α�����ӣ�����
    while(temp!=NULL || isBinTreeQueueEmpty(q)==0){
        if(temp!=NULL){//���
            printf("%d ",temp->data);
        }
        if(temp->leftChild==NULL && temp->rightChild==NULL && isBinTreeQueueEmpty(q)==1){
            break;//�����ǰ���ĺ��Ӷ�Ϊ�գ��Ҷ���ҲΪ�գ����ʾû�н�����������������������ѭ��
        }

        if(temp->leftChild!=NULL){//�������
            EnBinTreeQueue(q,temp->leftChild);
        }
        if(temp->rightChild!=NULL){//�Һ������
            EnBinTreeQueue(q,temp->rightChild);
        }

        temp=OutBinTreeQueue(q);//�õ�������ӵĸ�
    }
}

//ǰ���׵�
binTree *PreFirstRoot_BinTree(binTree *t){
    return t;//ǰ���׵�-����
}

//ǰ��β��
binTree *PreLastRoot_BinTree(binTree *t){
    if(t==NULL){
        return NULL;
    }
    binTree *temp;
    temp=t;
    //˼·���ȸ�������-���������������ߣ����������ȣ�û��������������������
    //ֱ���ߵ���,��õ�β��
    while(temp->rightChild!=NULL || temp->leftChild!=NULL){
        if(temp->rightChild!=NULL){
            temp=temp->rightChild;
        }else{
            temp=temp->rightChild;
        }
    }
    return temp;
}

//�����׵�
binTree *MidFirstRoot_BinTree(binTree *t){
    if(t==NULL){
        return NULL;
    }
    //˼·����������-����-���Һ��ӣ���ô����ľ����׵�
    binTree *temp;
    while(temp->leftChild!=NULL){
        temp=temp->leftChild;
    }
    return temp;
}

//����β��
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

//�����׵�
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

//����β��
binTree *PostLasrRoot_BinTree(binTree *t){
    return t;//�Ⱥ��Ӻ����tΪ���������
}

///����ǰ������򴴽�������
//pre��1 2 4 5 3 6 7 0
//mid��4 2 5 1 6 3 7 0
binTree *CreateBinTree_Mid(int pre[],int mid[],int left,int right){
    //����pre �ҵ��е�ֵ
    //����mid�ҵ��е�ֵ����� ����������
    //���뵱ǰ����ֵ
    //����mid�ҵ��е�ֵ���ұ� ����������
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

    //������
    //�������ݢ٣�1 2 -1 -1 3 -1 -1
    //�������ݢڣ�1 2 4 -1 -1 -1 -1
    //�������ݢۣ�4 2 1 -1 -1 3 -1 -1 6 5 -1 -1 7 -1 -1
    binTree *t,*max,*q,*pmid;

    ///����ǰ������򴴽�������
    int twoChildCount,data,i=0,j=0;
    int pre[MaxBinTreeRoots],mid[MaxBinTreeRoots];
    printf("������ǰ�����У�(0��Ϊ���н�β)");
    scanf("%d",&data);
    while(data!=0){
        pre[i]=data;
        i++;
        scanf("%d",&data);
    }
    printf("\n�������������У�(0��Ϊ���н�β)");
    scanf("%d",&data);
    while(data!=0){
        mid[j]=data;
        j++;
        scanf("%d",&data);
    }
    pmid=CreateBinTree_Mid(pre,mid,0,j-1);
    printf("\nǰ���������");
    Pre_TraversalBinTree(pmid);
    printf("\n�����������");
    Mid_TraversalBinTree(pmid);
    printf("\n������������");
    Post_TraversalBinTree(pmid);

    //����������
    printf("\nPlease input data in bin tree:(-1 as stop)");
    t=CreateBinTree();
    printf("�������Ĳ�α�����");
    TraversalByLayers_BinTree(t);
    printf("\nǰ���������");
    Pre_TraversalBinTree(t);
    printf("\n�����������");
    Mid_TraversalBinTree(t);
    //��������
    printf("\n----------��������--------\n");
    ExchangeChild_BinTree(t);
    printf("ǰ���������");
    Pre_TraversalBinTree(t);
    printf("\n�����������");
    Mid_TraversalBinTree(t);
    /*
    printf("Please input data in bin 2 tree:(-1 as stop)");
    q=CreateBinTree();
    */

    //�õ�ĳ����������
    int height,findData;
    printf("\nPlease input data need to find:");
    scanf("%d",&findData);
    height=FindAndGetHeight_BinTree(t,findData,0);
    if(height!=-1){
        printf("�ҵ����������ڸ�������Ϊ��%d\n",height);
    }else{
        printf("δ�ҵ����ݣ�\n");
    }

    //���ֱ���
    printf("ǰ���������");
    Pre_TraversalBinTree(t);
    printf("\n�ǵݹ�ǰ���������");
    Pre_TraversalBinTree_UnRecursion(t);
    printf("\n�����������");
    Mid_TraversalBinTree(t);
    printf("\n�ǵݹ������������");
    Mid_TraversalBinTree_UnRecursion(t);
    printf("\n������������");
    Post_TraversalBinTree(t);

    //�õ��������ֵ
    max=Max_BinTree(t,-1);
    printf("\n���ֵΪ��%d",max->data);

    //���Ƚڵ���
    twoChildCount=TwoChildRoot_BinTree(t);
    printf("\n�������Ƚ�������%d",twoChildCount);

    /*
    t=Merge_TwoBinTree(t,q);
    printf("\nǰ���������");
    Pre_TraversalBinTree(t);
    */



    //3�Ƚ����
    /*
    tree *t;
    char find;
    printf("�������������ݣ�(# ��Ϊֹͣ�����Ķ�Ϊ%d,ÿ������һ���ַ�)\n",maxChild);
    t=CreateTree();
    printf("ǰ���������");
    Pre_TraversalTree(t);
    printf("\n����������:");
    Post_TraversalTree(t);
    printf("\n");

    while(1){
        printf("��������Ҫ���ҵ����ݣ�");
        getchar();
        find=getchar();
        if(FindData_Tree(t,find)){
            printf("���ҵ����ݣ�\n");
        }else{
            printf("δ�ҵ����ݣ�\n");
        }
    }
    */
}
