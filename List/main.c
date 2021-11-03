#include <stdio.h>
#include <stdlib.h>

//����ĳ�ʼ��
typedef struct node{
    int num;
    struct node *next;
}node;

//ͷ�巨������������
void InsertAtHeadOfList(node *L,int addNum){
    node *temp;//����һ���½������������
    temp=(node*)malloc(sizeof(node));//�����½ڵ�Ŀռ�
    temp->num=addNum;//��������

    //�½����ͷ�巨��������
    temp->next=L->next;
    L->next=temp;
}

//��ӡ�����е�����
void PrintList(node *L){
    //����һ����ʱ�������������
    node *temp;
    temp=L->next;//��tempָ������ĵ�һ�����
    printf("����������Ϊ��\n");
    while(temp != NULL){//��������
        printf("%4d",temp->num);
        temp=temp->next;//��tempָ��ǰ�ڵ����һ�����
    }
}

//�õ�����洢����
int main()
{
    int x;
    node *p;//������ͷ
    p=(node*)malloc(sizeof(node));
    p->next=NULL;//�ñ�ͷ���ָ���ָ��

    printf("�������������ÿո�ֿ�����-1��Ϊ��β��:");
    scanf("%d",&x);
    while(x != -1){
        InsertAtHeadOfList(p,x);
        scanf("%d",&x);
    }
    PrintList(p);

}
