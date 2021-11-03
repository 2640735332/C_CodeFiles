#include <stdio.h>
#include <stdlib.h>

//顺序栈的实现
#define MAXSIZE 100

typedef int dataType;
typedef struct{
    dataType a[MAXSIZE];
    int top;
}sequence_stack;

//顺序栈的初始化
void InitialSequence_Stack(sequence_stack *L){
    L->top=0;
}

//判断顺序栈是否为空
void EmptyOFSequence_Stack(sequence_stack *L){
    if(L->top == 0){
        printf("顺序栈为空！\n");
    }else{
        printf("顺序栈不为空！\n");
    }
}

//取得栈顶的节点值
dataType GetTopOfSequence_Stack(sequence_stack *L){
    if(L->top==0){
        printf("顺序栈为空！\n");
    }
    return L->a[L->top-1];
}

//进栈
void InsertInSequence_Stack(sequence_stack *L,int data){
    if(L->top+1 > MAXSIZE){
        printf("顺序栈已满！\n");
    }
    L->a[L->top]=data;
    L->top++;
}

//出栈
void PopInSequence_Stack(sequence_stack *L){
    if(L->top == 0){
        printf("顺序栈为空，无法出栈！\n");
        return;
    }

    L->top--;
}

//从顶到底打印栈
void PrintFromTopInSequence_Stack(sequence_stack *L){
    if(L->top == 0){
        printf("顺序栈为空，无法打印！\n");
        return;
    }

    for(int i=L->top-1;i>=0;i--){
        printf("%4d",L->a[i]);
    }

}

//从底到顶打印栈
void PrintFromBottonInSequence_Stack(sequence_stack *L){
    if(L->top == 0){
        printf("顺序栈为空，无法打印！\n");
        return;
    }

    for(int i=0;i<L->top;i++){
        printf("%4d",L->a[i]);
    }
}

//按理论栈位置打印栈
void PrintSequence_Stack(sequence_stack *L){
    if(L->top == 0){
        printf("顺序栈为空，无法打印！\n");
        return;
    }

     for(int i=L->top-1;i>=0;i--){
        printf("%4d\n",L->a[i]);
    }

}

//延时函数
void relay(int timeNum){
    while(timeNum){
        timeNum--;
    }
}


int main()
{

    printf("============顺序栈============\n");
    printf("[0]退出顺序栈\n[1]顺序栈的初始化\n[2]判断顺序栈是否为空");
    printf("\n[3]取得栈顶的节点值\n[4]进栈\n[5]出栈\n");
    printf("[6]从顶部打印栈内容\n[7]从底部打印栈内容\n[8]打印栈内容\n");
    printf("==============================\n");
    printf("(注：栈中数据为整数)\n");
    int controlIndex,topNum,insertNum;
    sequence_stack *p;
    p=(sequence_stack *)malloc(sizeof(sequence_stack));
    p->top=0;

    printf("请输入数字进行操作：");
    scanf("%d",&controlIndex);

    while(1){
        switch(controlIndex){
        case 0://退出顺序栈
            printf("正在退出...");
            relay(300000000);
            printf("退出成功！");
            return;
            break;
        case 1://顺序栈的初始化
            InitialSequence_Stack(p);
            printf("初始化成功！\n");
            break;
        case 2://判断顺序栈是否为空
            EmptyOFSequence_Stack(p);
            break;
        case 3://取得栈顶的节点值
            topNum=GetTopOfSequence_Stack(p);
            printf("栈顶节点值为：%d\n",topNum);
            break;
        case 4://进栈
            printf("请输入进栈的值：");
            scanf("%d",&insertNum);
            InsertInSequence_Stack(p,insertNum);
            printf("进栈成功！\n");
            break;
        case 5://出栈
            PopInSequence_Stack(p);
            printf("出栈成功！\n");
            break;
        case 6://从顶部打印栈内容
            PrintFromTopInSequence_Stack(p);
            break;
        case 7://从底部打印栈内容
            PrintFromBottonInSequence_Stack(p);
            break;
        case 8:
            PrintSequence_Stack(p);
            break;
        default:
            printf("输入的数字超出操作范围！");
            break;
        }

        printf("请输入数字进行操作：");
        scanf("%d",&controlIndex);

    }
}
