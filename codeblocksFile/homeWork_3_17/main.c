#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

typedef struct{
    int a[MAXSIZE];
    int size;
}sequence_List;

void Initial(sequence_List *L){
    printf("���������ݣ�(��-1��Ϊ��β)\n");
    int x;
    scanf("%d",&x);
    while(x != -1){
        L->a[L->size]=x;
        L->size++;
        scanf("%d",&x);
    }
}

void insert(sequence_List *L,int x){
    if(L->size+1 >= 100){
        printf("��������\n");
        exit(1);
    }
    L->a[L->size]=x;
    L->size++;
}

void Add(sequence_List *L1,sequence_List *L2,sequence_List *L3){//��L1��L2������������ϲ���L3
    int maxSize=L1->size+L2->size;
    int i,indexI=0,indexJ=0,minNum;
    for(i=0;i<maxSize;i++){
        if(indexI < L1->size && indexJ < L2->size){
            if(L1->a[indexI] <= L2->a[indexJ]){
                minNum=L1->a[indexI];
                indexI++;
            }else{
                minNum=L2->a[indexJ];
                indexJ++;
            }
        }else if(indexI < L1->size){
            minNum=L1->a[indexI];
            indexI++;
        }else if(indexJ < L2->size){
            minNum=L2->a[indexJ];
            indexJ++;
        }
        L3->a[i]=minNum;
        L3->size++;
    }
}

void OutList(sequence_List *L){
    if(L->size ==0){
        printf("��Ϊ�գ�\n");
        exit(1);
    }
    int i;
    printf("��������Ϊ��\n");
    for(i=0;i<L->size;i++){
        printf("%3d",L->a[i]);
    }
    printf("\n");
}

void DeleteTimes(sequence_List *L){ //ɾ��3�ı���
    int index,count;
    for(index=0;index<L->size;index++){
        if(L->a[index] %3 != 0){
            L->a[count]=L->a[index];
            count++;
        }
    }
    L->size=count;
}

void DeleteItem(sequence_List *L){
    if(L->size == 0){
        printf("��Ϊ�գ�\n");
        return;
    }
    int index,position,x,flag=0;
    printf("������Ҫɾ��������\n");
    scanf("%d",&x);
    for(index=0;index<L->size;index++){
        if(L->a[index] == x){
            for(position=index;position<L->size-1;position++){
                L->a[position]=L->a[position+1];
            }
            flag=1;//˵���ҵ���Ҫɾ��������
            index--;
            L->size--;
        }
    }
    if(flag==0){
        printf("����û�д�����\n");
    }
    if(flag == 1){
        printf("ɾ���ɹ���\n");
    }

}

int main()
{
    sequence_List *L1,*L2,*L3;
    L3=(sequence_List *)malloc(sizeof(sequence_List));
    L3->size=0;
    L1=(sequence_List *)malloc(sizeof(sequence_List));
    L1->size=0;
    L2=(sequence_List *)malloc(sizeof(sequence_List));
    L2->size=0;
    Initial(L1);
    OutList(L1);
    DeleteItem(L1);
    OutList(L1);

}
