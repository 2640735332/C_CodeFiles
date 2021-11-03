#include <stdio.h>
#include <stdlib.h>

typedef struct a{//结点的结构体
    struct a *pre,*next;
    int data;
}node;

typedef struct b{//保存front和rear指针的结构体
    struct a *front,*rear;
}headNode;

void Init_Queue(headNode *head){
    head->front=NULL;
    head->rear=NULL;
}

void Insert_Queue(headNode *head){
    int insertNum,isHeadNull=1;
    printf("Please input insert num:(0 as stop)");
    scanf("%d",&insertNum);

    if(head->front==NULL){
        node *p;
        p=(node *)malloc(sizeof(node));
        p->data=insertNum;
        p->next=NULL;
        p->pre=NULL;

        head->front=p;
        head->rear=p;
        isHeadNull=0;
    }

    while(insertNum!=0){
        if(isHeadNull == 0){
            scanf("%d",&insertNum);
            if(insertNum==0){
                break;
            }
            isHeadNull=1;
        }
        node *p;
        p=(node *)malloc(sizeof(node));
        p->data=insertNum;
        p->next=NULL;
        p->pre=NULL;

        head->rear->next=p;
        p->pre=head->rear;
        head->rear=p;
        scanf("%d",&insertNum);
    }
}

void Print_Queue(headNode *head){
    node *p;
    p=head->front;
    if(p==NULL){
        printf("Queue is null!\n");

        return;
    }
    printf("Data is:\n");
    while(p!=NULL){
        printf("%3d",p->data);
        p=p->next;
    }
    printf("\n");
}

void Delete_Queue(headNode *head){
    int deleteNum,totalNum=0;
    printf("Please input data num that need to delete:");
    scanf("%d",&deleteNum);

    node *p;
    p=head->front;
    while(p!=NULL){
        totalNum++;
        p=p->next;
    }
    if(totalNum<deleteNum){
        printf("The num is longer than the queue, please input again!\n");
        return;
    }
    for(int i=0;i<deleteNum;i++){
        if(head->front == head->rear){
            p=head->front;
            head->front=NULL;
            head->rear=NULL;
            free(p);
            break;
        }
        p=head->front;
        head->front=head->front->next;
        head->front->pre=NULL;
        free(p);
    }
}

int main()
{
    headNode head;
    Init_Queue(&head);
    Insert_Queue(&head);
    Print_Queue(&head);
    Delete_Queue(&head);
    Print_Queue(&head);
}
