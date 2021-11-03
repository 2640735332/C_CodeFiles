#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100
//顺序队列的实现

//顺序队列的建立
typedef struct{
    int a[MAXSIZE];
    int front,rear;
}squence_queue;
//注：front & rear 与数组下标对应,队列删除从队列首部删除
//顺序队列的初始化
void InitialSquence_Queue(squence_queue *L){
    L->front=0;
    L->rear=0;
}

//判断顺序队列是否为空
void EmptySquence_Queue(squence_queue *L){
    if(L->front == L->rear){
        printf("队列为空！\n");
    }else{
        printf("队列不为空！\n");
    }
}

//打印顺序队列的节点值
void PrintSquence_Queue(squence_queue *L){
    if(L->front == L->rear){
        printf("队列为空！\n");
        exit(1);
    }

    for(int i=L->front;i<L->rear;i++){
        printf("%4d",L->a[i]);
    }
    printf("\n");
}

//连续插入队列节点值
void InsertSquence_Queue(squence_queue *L){
    int nodeNum;
    if(L->rear == MAXSIZE){
        printf("队列已满，无法继续加入结点！");
        exit(1);
    }

    printf("请输入节点值：(以空格分隔，以-1标志结束)");
    scanf("%d",&nodeNum);
    while(nodeNum != -1){
        L->a[L->rear]=nodeNum;
        L->rear++;
        if(L->rear == MAXSIZE){
            printf("队列已满，无法继续加入结点！");
            exit(1);
        }
    scanf("%d",&nodeNum);
    }
}

//连续删除队列节点值
void DeleteSquence_Queue(squence_queue *L,int deleteNum){
    if(deleteNum > L->rear - L->front){
        printf("队列不够长！\n");
        exit(1);
    }
    if(L->front == L->rear){
        printf("队列为空！\n");
        exit(1);
    }

    for(int i=0;i<deleteNum;i++){
        L->front++;
    }

}

//取得队列首结点值
void GetHeadNodeSquence_Queue(squence_queue *L){
    if(L->front == L->rear){
        printf("队列为空！\n");
        exit(1);
    }

    printf("队列首节点值为：%d\n",L->a[L->front]);
}

//延时函数
void relay(int timeIndex){
    while(timeIndex){
        timeIndex--;
    }
}

int main()
{
    squence_queue *p;
    p=(squence_queue *)malloc(sizeof(squence_queue));
    p->front=0;
    p->rear=0;

    printf("==============顺序队列==============\n");
    printf("[0]退出顺序队列程序\n[1]判断顺序队列是否为空\n[2]打印顺序队列的节点值\n[3]连续插入队列节点值\n");
    printf("[4]连续删除队列节点值\n[5]取得队列首结点值\n");
    printf("====================================\n");
    printf("注：节点值都为整数\n");

    int controlIndex,num;
    printf("请输入数字进行操作：");
    scanf("%d",&controlIndex);

    while(1){
        switch(controlIndex){
        case 0://退出顺序栈
            printf("正在退出...");
            relay(300000000);
            printf("退出成功！");
            return;
            break;
        case 1://判断顺序队列是否为空
            EmptySquence_Queue(p);
            break;
        case 2://打印顺序队列的节点值
            PrintSquence_Queue(p);
            break;
        case 3://连续插入队列节点值
            InsertSquence_Queue(p);
            break;
        case 4://连续删除队列节点值
            printf("请输入删除的结点个数：");
            scanf("%d",&num);
            DeleteSquence_Queue(p,num);
            break;
        case 5://取得队列首结点值
            GetHeadNodeSquence_Queue(p);
            break;
        default:
            printf("输入的数字超出操作范围！\n");
            break;
        }

        printf("请输入数字进行操作：");
        scanf("%d",&controlIndex);
    }

    return 0;
}
