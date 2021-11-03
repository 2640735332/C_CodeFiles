#include <stdio.h>
#include <stdlib.h>

//链表的初始化
typedef struct node{
    int num;
    struct node *next;
}node;

//头插法插入链表数据
void InsertAtHeadOfList(node *L,int addNum){
    node *temp;//建立一个新结点来储存数据
    temp=(node*)malloc(sizeof(node));//声明新节点的空间
    temp->num=addNum;//储存数据

    //新结点以头插法连入链表
    temp->next=L->next;
    L->next=temp;
}

//打印链表中的数据
void PrintList(node *L){
    //建立一个临时结点来遍历链表
    node *temp;
    temp=L->next;//让temp指向链表的第一个结点
    printf("链表中数据为：\n");
    while(temp != NULL){//遍历链表
        printf("%4d",temp->num);
        temp=temp->next;//让temp指向当前节点的下一个结点
    }
}

//用单链表存储数据
int main()
{
    int x;
    node *p;//建立表头
    p=(node*)malloc(sizeof(node));
    p->next=NULL;//让表头结点指向空指针

    printf("请输入整数（用空格分开，以-1作为结尾）:");
    scanf("%d",&x);
    while(x != -1){
        InsertAtHeadOfList(p,x);
        scanf("%d",&x);
    }
    PrintList(p);

}
