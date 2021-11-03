#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int index;
    struct node* next;
}node;

void InitialList(node *L){
    L->next=NULL;
}

int LengthList(node *L){
    int length=0;
    node *temp;
    temp=L->next;
    while(temp!=NULL){
        i++;
        temp=temp->next;
    }
    return length;
}

void PrintList(node *L)
{
    if(L->next == NULL){
        printf("单链表为空！\n");
        return;
    }
    node *temp;
    temp=L->next;
    printf("表中数据为：\n");
    while(temp != NULL){
        printf("%4d",temp->index);
        temp=temp->next;
    }
    printf("\n");
}

void InsertList_OnHead(node *L,int insertData){
    node *temp;
    temp=(node *)malloc(sizeof(node));
    temp->index=insertData;

    temp->next=L->next;
    L->next=temp;
}

void InsertList_OnTail(node *L,int insertData){

}

void InsertList_OnAnyPosition(node *L,int position,int insertData){
    if(LengthList(L)+1 <= position){
        printf("位置超出可插入范围！\t");
        printf("当前链表长：%d\n",LengthList(L));
        return;
    }
    if(L->next == NULL){
        printf("单链表为空！\n");
        return;
    }
    //找到插入的位置
    node *temp,*insertPosition;
    temp=L->next;
    //插入

}


int main()
{
    node *head;
    head=(node *)malloc(sizeof(node));
    InitialList(head);


}
