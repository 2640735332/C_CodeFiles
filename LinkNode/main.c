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
        printf("������Ϊ�գ�\n");
        return;
    }
    node *temp;
    temp=L->next;
    printf("��������Ϊ��\n");
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
        printf("λ�ó����ɲ��뷶Χ��\t");
        printf("��ǰ������%d\n",LengthList(L));
        return;
    }
    if(L->next == NULL){
        printf("������Ϊ�գ�\n");
        return;
    }
    //�ҵ������λ��
    node *temp,*insertPosition;
    temp=L->next;
    //����

}


int main()
{
    node *head;
    head=(node *)malloc(sizeof(node));
    InitialList(head);


}
