#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char a[100];
    int top;
}Stack;

//进栈
void Push(Stack *L,char x){
    if(L->top + 1 >100){
        printf("栈已满！\n");
        return;
    }
    L->a[L->top]=x;
    L->top++;
}

//出栈
void Pop(Stack *L){
    if(L->top == 0){
        printf("栈是空的！\n");
        return;
    }
    L->top--;
}

//输出栈顶字符
char Top(Stack *L){
    if(L->top == 0){
        printf("栈为空！\n");
        return;
    }
    return L->a[L->top-1];
}

//打印栈
void PrintStack(Stack *L)
{
    if(L->top == 0){
        printf("栈为空！\n");
        return;
    }
    printf("栈中数据为：\n");
    for(int i=0;i<L->top;i++){
        printf("%4c",L->a[i]);
    }
    printf("\n");
}

int main()
{
    char a[100];
    int i=0;
    int isError=0;
    Stack *L;
    L=(Stack *)malloc(sizeof(Stack));
    L->top=0;

    printf("请输入需要检测的括号匹配项：");
    gets(a);

    while(a[i] != '\0'){
        if(a[i]=='(' || a[i]=='[' || a[i]=='{'){
            Push(L,a[i]);
        }
        char temp;
        temp=Top(L);
        if(a[i]==')'){
            if(temp+1 != a[i]){
                printf("Error!\n");
                isError=1;
                break;
            }else{
                Pop(L);
            }
        }
        if(a[i]==']' || a[i]=='}'){
            if(temp+2 != a[i]){
                printf("Error!\n");
                isError=1;
                break;
            }else{
                Pop(L);
            }
        }
        i++;
    }

    if(isError == 0){
        printf("Match Right!");
    }

    return 0;
}
