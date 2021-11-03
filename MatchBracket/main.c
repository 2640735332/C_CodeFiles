#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char a[100];
    int top;
}Stack;

//��ջ
void Push(Stack *L,char x){
    if(L->top + 1 >100){
        printf("ջ������\n");
        return;
    }
    L->a[L->top]=x;
    L->top++;
}

//��ջ
void Pop(Stack *L){
    if(L->top == 0){
        printf("ջ�ǿյģ�\n");
        return;
    }
    L->top--;
}

//���ջ���ַ�
char Top(Stack *L){
    if(L->top == 0){
        printf("ջΪ�գ�\n");
        return;
    }
    return L->a[L->top-1];
}

//��ӡջ
void PrintStack(Stack *L)
{
    if(L->top == 0){
        printf("ջΪ�գ�\n");
        return;
    }
    printf("ջ������Ϊ��\n");
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

    printf("��������Ҫ��������ƥ���");
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
