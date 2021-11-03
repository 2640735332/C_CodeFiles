#include <stdio.h>
#include <stdlib.h>
#include <math.h>;

#define MAXSIZE 100
//顺序表的实现
typedef int dataType;

typedef struct{
    dataType a[MAXSIZE];
    int size;
}squence_list;

//顺序表的置空
void squence_list_init(squence_list *L){
    L->size=0;
}

//顺序表的尾插
void appendOnSquence_ListTail(squence_list *L,dataType x){
    if(L->size == MAXSIZE){
        printf("顺序表已满!\n");
        exit(1);
    }

    L->a[L->size]=x;
    L->size++;
}

//顺序表的打印
void printSquence(squence_list *L){
    if(L->size == 0){
        printf("顺序表是空的！");
        exit(1);
    }
    for(int i=0;i<L->size;i++){
        printf("%d ",L->a[i]);
    }
}

//判断顺序表是否为空
void squence_listEmpty(squence_list *L){
    if(L->size ==0){
        printf("顺序表为空！\n");
    }else{
        printf("顺序表不为空！\n");
    }
}

//查找顺序表中值为x的位置
void findValueXInSquence_List(squence_list *L,int x){
    if(L->size == 0){
        printf("查找失败！顺序表为空！\n");
        exit(1);
    }
    for(int i=0;i<L->size;i++){
        if(L->a[i]==x){
            printf("查找成功！数值%d在表中的位置为：%d\n",x,i);
            exit(0);
        }
    }
    printf("查找失败！顺序表中无数值x\n");
}

//获取顺序表中第i个节点的值
void GetValue(squence_list *L,int i){
    if(L->size == 0){
        printf("顺序表为空！\n");
        exit(1);
    }

    printf("顺序表中第%d个节点的值为:%d",i,L->a[i-1]);
}


//延时函数的实现
void delay(unsigned i){
    while(i--);
}

//顺序表的任意位置插入数据
void InsertInMidSquence_List(squence_list *L,int data,int position){
    if(position > L->size || position < 1){
        printf("插入的位置超过顺序表范围！请重新输入！\n");
        return;
    }

    if(L->size+1 >MAXSIZE){
        printf("顺序表已满！\n");
        return;
    }

    //在位置为position-1的位置插入为data的数据
    L->size++;
    for(int i=L->size-1;i>=position-1;i--){
        L->a[i]=L->a[i-1];
    }
    L->a[position-1]=data;
    printf("数据成功插入！\n");
}

void DeleteInMidSquence_List(squence_list *L,int position){
    if(position<1 || position>L->size){
        printf("数据位置超出当前瞬步表范围！\n");
        return ;
    }

    if(L->size == 0){
        printf("当前顺序表为空！\n");
    }

    //从顺序表中删除数据操作
    for(int i=position-1;i<L->size-1;i++){
        L->a[i]=L->a[i+1];
    }
    L->size--;
    printf("删除成功！\n");
}


int main()
{
    int a,x,y,z,insertData,insertPosition,deletePosition;
    printf("============顺序表============\n");
    printf("[0]退出顺序表程序\n[1]往顺序表中插入单个数据\n[2]置空顺序表\n[3]打印顺序表\n[4]判断顺序表是否为空\n");
    printf("[5]查找顺序表中值为x的位置\n[6]顺序表某个节点的值\n[7]往顺序表尾部插入多个数据\n[8]任意位置插入一个数据\n");
    printf("[9]删除一个数据\n");
    printf("==============================\n");
    printf("请输入序号进行操作:");
    scanf("%d",&a);

    squence_list *p;
    p=(squence_list *)malloc(sizeof(squence_list));
    p->size=0;

    while(1){
        switch(a){
            case 0:
                printf("正在退出...");
                delay(500000000);
                printf("退出成功！");
                return;
                break;
            case 1:

                printf("请输入要插入的数据：");
                scanf("%d",&x);
                appendOnSquence_ListTail(p,x);
                break;
            case 2:
                p->size=0;
                printf("顺序表已置空！\n");
                break;
            case 3:
                if(p->size==0){
                    printf("顺序表为空！\n");
                    break;
                }
                printf("表中的值为：\n");
                for(int j=0;j<p->size;j++){
                    printf("%4d",p->a[j]);
                }
                printf("\n");
                break;
            case 4:
                if(p->size ==0){
                    printf("顺序表为空！\n");
                }else{
                    printf("顺序表不为空！\n");
                }
                break;
            case 5:
                if(p->size==0){
                    printf("顺序表为空！\n");
                    break;
                }

                printf("请输入x的值：");
                scanf("%d",&y);
                for(int j=0;j<p->size;p++){
                    if(p->a[j]==y){
                        printf("位置为表中第%d个\n",j+1);
                    }
                }
                break;
            case 6:
                printf("请输入节点的位置：\n");
                scanf("%d",&z);
                while((z-1)>=p->size || (z-1)<0){
                    printf("位置超出节点的范围！请重新输入节点位置:");
                    scanf("%d",&z);
                    printf("\n");
                }
                printf("该节点的值为：%d\n",p->a[z-1]);

                break;
            case 7:
                printf("请输入多个数据（以空格分开,以-1标志结束）:");
                while(scanf("%d",&x)){
                    if(x == -1){
                        break;
                    }
                    appendOnSquence_ListTail(p,x);
                }
                printf("插入成功！\n");
                break;
            case 8:
                printf("请输入要插入的数据和位置：(用空格分开)");
                scanf("%d%d",&insertData,&insertPosition);
                InsertInMidSquence_List(p,insertData,insertPosition);
                break;
            case 9:
                printf("请输入要删除数据的位置：");
                scanf("%d",&deletePosition);
                DeleteInMidSquence_List(p,deletePosition);
                break;
            default:
                printf("输出的数值超出范围！请重新输入！\n");
                break;
            }

            printf("请输入序号进行操作：");
            scanf("%d",&a);

        }

}


