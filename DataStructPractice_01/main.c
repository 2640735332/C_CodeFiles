#include <stdio.h>
#include <stdlib.h>
#include <math.h>;

#define MAXSIZE 100
//˳����ʵ��
typedef int dataType;

typedef struct{
    dataType a[MAXSIZE];
    int size;
}squence_list;

//˳�����ÿ�
void squence_list_init(squence_list *L){
    L->size=0;
}

//˳����β��
void appendOnSquence_ListTail(squence_list *L,dataType x){
    if(L->size == MAXSIZE){
        printf("˳�������!\n");
        exit(1);
    }

    L->a[L->size]=x;
    L->size++;
}

//˳���Ĵ�ӡ
void printSquence(squence_list *L){
    if(L->size == 0){
        printf("˳����ǿյģ�");
        exit(1);
    }
    for(int i=0;i<L->size;i++){
        printf("%d ",L->a[i]);
    }
}

//�ж�˳����Ƿ�Ϊ��
void squence_listEmpty(squence_list *L){
    if(L->size ==0){
        printf("˳���Ϊ�գ�\n");
    }else{
        printf("˳���Ϊ�գ�\n");
    }
}

//����˳�����ֵΪx��λ��
void findValueXInSquence_List(squence_list *L,int x){
    if(L->size == 0){
        printf("����ʧ�ܣ�˳���Ϊ�գ�\n");
        exit(1);
    }
    for(int i=0;i<L->size;i++){
        if(L->a[i]==x){
            printf("���ҳɹ�����ֵ%d�ڱ��е�λ��Ϊ��%d\n",x,i);
            exit(0);
        }
    }
    printf("����ʧ�ܣ�˳���������ֵx\n");
}

//��ȡ˳����е�i���ڵ��ֵ
void GetValue(squence_list *L,int i){
    if(L->size == 0){
        printf("˳���Ϊ�գ�\n");
        exit(1);
    }

    printf("˳����е�%d���ڵ��ֵΪ:%d",i,L->a[i-1]);
}


//��ʱ������ʵ��
void delay(unsigned i){
    while(i--);
}

//˳��������λ�ò�������
void InsertInMidSquence_List(squence_list *L,int data,int position){
    if(position > L->size || position < 1){
        printf("�����λ�ó���˳���Χ�����������룡\n");
        return;
    }

    if(L->size+1 >MAXSIZE){
        printf("˳���������\n");
        return;
    }

    //��λ��Ϊposition-1��λ�ò���Ϊdata������
    L->size++;
    for(int i=L->size-1;i>=position-1;i--){
        L->a[i]=L->a[i-1];
    }
    L->a[position-1]=data;
    printf("���ݳɹ����룡\n");
}

void DeleteInMidSquence_List(squence_list *L,int position){
    if(position<1 || position>L->size){
        printf("����λ�ó�����ǰ˲����Χ��\n");
        return ;
    }

    if(L->size == 0){
        printf("��ǰ˳���Ϊ�գ�\n");
    }

    //��˳�����ɾ�����ݲ���
    for(int i=position-1;i<L->size-1;i++){
        L->a[i]=L->a[i+1];
    }
    L->size--;
    printf("ɾ���ɹ���\n");
}


int main()
{
    int a,x,y,z,insertData,insertPosition,deletePosition;
    printf("============˳���============\n");
    printf("[0]�˳�˳������\n[1]��˳����в��뵥������\n[2]�ÿ�˳���\n[3]��ӡ˳���\n[4]�ж�˳����Ƿ�Ϊ��\n");
    printf("[5]����˳�����ֵΪx��λ��\n[6]˳���ĳ���ڵ��ֵ\n[7]��˳���β������������\n[8]����λ�ò���һ������\n");
    printf("[9]ɾ��һ������\n");
    printf("==============================\n");
    printf("��������Ž��в���:");
    scanf("%d",&a);

    squence_list *p;
    p=(squence_list *)malloc(sizeof(squence_list));
    p->size=0;

    while(1){
        switch(a){
            case 0:
                printf("�����˳�...");
                delay(500000000);
                printf("�˳��ɹ���");
                return;
                break;
            case 1:

                printf("������Ҫ��������ݣ�");
                scanf("%d",&x);
                appendOnSquence_ListTail(p,x);
                break;
            case 2:
                p->size=0;
                printf("˳������ÿգ�\n");
                break;
            case 3:
                if(p->size==0){
                    printf("˳���Ϊ�գ�\n");
                    break;
                }
                printf("���е�ֵΪ��\n");
                for(int j=0;j<p->size;j++){
                    printf("%4d",p->a[j]);
                }
                printf("\n");
                break;
            case 4:
                if(p->size ==0){
                    printf("˳���Ϊ�գ�\n");
                }else{
                    printf("˳���Ϊ�գ�\n");
                }
                break;
            case 5:
                if(p->size==0){
                    printf("˳���Ϊ�գ�\n");
                    break;
                }

                printf("������x��ֵ��");
                scanf("%d",&y);
                for(int j=0;j<p->size;p++){
                    if(p->a[j]==y){
                        printf("λ��Ϊ���е�%d��\n",j+1);
                    }
                }
                break;
            case 6:
                printf("������ڵ��λ�ã�\n");
                scanf("%d",&z);
                while((z-1)>=p->size || (z-1)<0){
                    printf("λ�ó����ڵ�ķ�Χ������������ڵ�λ��:");
                    scanf("%d",&z);
                    printf("\n");
                }
                printf("�ýڵ��ֵΪ��%d\n",p->a[z-1]);

                break;
            case 7:
                printf("�����������ݣ��Կո�ֿ�,��-1��־������:");
                while(scanf("%d",&x)){
                    if(x == -1){
                        break;
                    }
                    appendOnSquence_ListTail(p,x);
                }
                printf("����ɹ���\n");
                break;
            case 8:
                printf("������Ҫ��������ݺ�λ�ã�(�ÿո�ֿ�)");
                scanf("%d%d",&insertData,&insertPosition);
                InsertInMidSquence_List(p,insertData,insertPosition);
                break;
            case 9:
                printf("������Ҫɾ�����ݵ�λ�ã�");
                scanf("%d",&deletePosition);
                DeleteInMidSquence_List(p,deletePosition);
                break;
            default:
                printf("�������ֵ������Χ�����������룡\n");
                break;
            }

            printf("��������Ž��в�����");
            scanf("%d",&a);

        }

}


