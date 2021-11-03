#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100
//˳����е�ʵ��

//˳����еĽ���
typedef struct{
    int a[MAXSIZE];
    int front,rear;
}squence_queue;
//ע��front & rear �������±��Ӧ,����ɾ���Ӷ����ײ�ɾ��
//˳����еĳ�ʼ��
void InitialSquence_Queue(squence_queue *L){
    L->front=0;
    L->rear=0;
}

//�ж�˳������Ƿ�Ϊ��
void EmptySquence_Queue(squence_queue *L){
    if(L->front == L->rear){
        printf("����Ϊ�գ�\n");
    }else{
        printf("���в�Ϊ�գ�\n");
    }
}

//��ӡ˳����еĽڵ�ֵ
void PrintSquence_Queue(squence_queue *L){
    if(L->front == L->rear){
        printf("����Ϊ�գ�\n");
        exit(1);
    }

    for(int i=L->front;i<L->rear;i++){
        printf("%4d",L->a[i]);
    }
    printf("\n");
}

//����������нڵ�ֵ
void InsertSquence_Queue(squence_queue *L){
    int nodeNum;
    if(L->rear == MAXSIZE){
        printf("�����������޷����������㣡");
        exit(1);
    }

    printf("������ڵ�ֵ��(�Կո�ָ�����-1��־����)");
    scanf("%d",&nodeNum);
    while(nodeNum != -1){
        L->a[L->rear]=nodeNum;
        L->rear++;
        if(L->rear == MAXSIZE){
            printf("�����������޷����������㣡");
            exit(1);
        }
    scanf("%d",&nodeNum);
    }
}

//����ɾ�����нڵ�ֵ
void DeleteSquence_Queue(squence_queue *L,int deleteNum){
    if(deleteNum > L->rear - L->front){
        printf("���в�������\n");
        exit(1);
    }
    if(L->front == L->rear){
        printf("����Ϊ�գ�\n");
        exit(1);
    }

    for(int i=0;i<deleteNum;i++){
        L->front++;
    }

}

//ȡ�ö����׽��ֵ
void GetHeadNodeSquence_Queue(squence_queue *L){
    if(L->front == L->rear){
        printf("����Ϊ�գ�\n");
        exit(1);
    }

    printf("�����׽ڵ�ֵΪ��%d\n",L->a[L->front]);
}

//��ʱ����
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

    printf("==============˳�����==============\n");
    printf("[0]�˳�˳����г���\n[1]�ж�˳������Ƿ�Ϊ��\n[2]��ӡ˳����еĽڵ�ֵ\n[3]����������нڵ�ֵ\n");
    printf("[4]����ɾ�����нڵ�ֵ\n[5]ȡ�ö����׽��ֵ\n");
    printf("====================================\n");
    printf("ע���ڵ�ֵ��Ϊ����\n");

    int controlIndex,num;
    printf("���������ֽ��в�����");
    scanf("%d",&controlIndex);

    while(1){
        switch(controlIndex){
        case 0://�˳�˳��ջ
            printf("�����˳�...");
            relay(300000000);
            printf("�˳��ɹ���");
            return;
            break;
        case 1://�ж�˳������Ƿ�Ϊ��
            EmptySquence_Queue(p);
            break;
        case 2://��ӡ˳����еĽڵ�ֵ
            PrintSquence_Queue(p);
            break;
        case 3://����������нڵ�ֵ
            InsertSquence_Queue(p);
            break;
        case 4://����ɾ�����нڵ�ֵ
            printf("������ɾ���Ľ�������");
            scanf("%d",&num);
            DeleteSquence_Queue(p,num);
            break;
        case 5://ȡ�ö����׽��ֵ
            GetHeadNodeSquence_Queue(p);
            break;
        default:
            printf("��������ֳ���������Χ��\n");
            break;
        }

        printf("���������ֽ��в�����");
        scanf("%d",&controlIndex);
    }

    return 0;
}
