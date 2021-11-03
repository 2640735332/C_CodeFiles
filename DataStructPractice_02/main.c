#include <stdio.h>
#include <stdlib.h>

//˳��ջ��ʵ��
#define MAXSIZE 100

typedef int dataType;
typedef struct{
    dataType a[MAXSIZE];
    int top;
}sequence_stack;

//˳��ջ�ĳ�ʼ��
void InitialSequence_Stack(sequence_stack *L){
    L->top=0;
}

//�ж�˳��ջ�Ƿ�Ϊ��
void EmptyOFSequence_Stack(sequence_stack *L){
    if(L->top == 0){
        printf("˳��ջΪ�գ�\n");
    }else{
        printf("˳��ջ��Ϊ�գ�\n");
    }
}

//ȡ��ջ���Ľڵ�ֵ
dataType GetTopOfSequence_Stack(sequence_stack *L){
    if(L->top==0){
        printf("˳��ջΪ�գ�\n");
    }
    return L->a[L->top-1];
}

//��ջ
void InsertInSequence_Stack(sequence_stack *L,int data){
    if(L->top+1 > MAXSIZE){
        printf("˳��ջ������\n");
    }
    L->a[L->top]=data;
    L->top++;
}

//��ջ
void PopInSequence_Stack(sequence_stack *L){
    if(L->top == 0){
        printf("˳��ջΪ�գ��޷���ջ��\n");
        return;
    }

    L->top--;
}

//�Ӷ����״�ӡջ
void PrintFromTopInSequence_Stack(sequence_stack *L){
    if(L->top == 0){
        printf("˳��ջΪ�գ��޷���ӡ��\n");
        return;
    }

    for(int i=L->top-1;i>=0;i--){
        printf("%4d",L->a[i]);
    }

}

//�ӵ׵�����ӡջ
void PrintFromBottonInSequence_Stack(sequence_stack *L){
    if(L->top == 0){
        printf("˳��ջΪ�գ��޷���ӡ��\n");
        return;
    }

    for(int i=0;i<L->top;i++){
        printf("%4d",L->a[i]);
    }
}

//������ջλ�ô�ӡջ
void PrintSequence_Stack(sequence_stack *L){
    if(L->top == 0){
        printf("˳��ջΪ�գ��޷���ӡ��\n");
        return;
    }

     for(int i=L->top-1;i>=0;i--){
        printf("%4d\n",L->a[i]);
    }

}

//��ʱ����
void relay(int timeNum){
    while(timeNum){
        timeNum--;
    }
}


int main()
{

    printf("============˳��ջ============\n");
    printf("[0]�˳�˳��ջ\n[1]˳��ջ�ĳ�ʼ��\n[2]�ж�˳��ջ�Ƿ�Ϊ��");
    printf("\n[3]ȡ��ջ���Ľڵ�ֵ\n[4]��ջ\n[5]��ջ\n");
    printf("[6]�Ӷ�����ӡջ����\n[7]�ӵײ���ӡջ����\n[8]��ӡջ����\n");
    printf("==============================\n");
    printf("(ע��ջ������Ϊ����)\n");
    int controlIndex,topNum,insertNum;
    sequence_stack *p;
    p=(sequence_stack *)malloc(sizeof(sequence_stack));
    p->top=0;

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
        case 1://˳��ջ�ĳ�ʼ��
            InitialSequence_Stack(p);
            printf("��ʼ���ɹ���\n");
            break;
        case 2://�ж�˳��ջ�Ƿ�Ϊ��
            EmptyOFSequence_Stack(p);
            break;
        case 3://ȡ��ջ���Ľڵ�ֵ
            topNum=GetTopOfSequence_Stack(p);
            printf("ջ���ڵ�ֵΪ��%d\n",topNum);
            break;
        case 4://��ջ
            printf("�������ջ��ֵ��");
            scanf("%d",&insertNum);
            InsertInSequence_Stack(p,insertNum);
            printf("��ջ�ɹ���\n");
            break;
        case 5://��ջ
            PopInSequence_Stack(p);
            printf("��ջ�ɹ���\n");
            break;
        case 6://�Ӷ�����ӡջ����
            PrintFromTopInSequence_Stack(p);
            break;
        case 7://�ӵײ���ӡջ����
            PrintFromBottonInSequence_Stack(p);
            break;
        case 8:
            PrintSequence_Stack(p);
            break;
        default:
            printf("��������ֳ���������Χ��");
            break;
        }

        printf("���������ֽ��в�����");
        scanf("%d",&controlIndex);

    }
}
