#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXSIZE 100

//实现后缀表达式的计算
/*
    核心思想：先将字符数转为计算数-》再进行计算
*/

//实现中缀转后缀
/*
    具体算法： 1.数字：直接输出
               2.运算符:①栈为空，入栈
                        ②栈内top的运算符级别小于待输入运算符，入栈
                        ③栈内top的运算符级别大于待输入运算符，top运算符输出（1）并出栈，直到top运算符级别更小、或者栈为空、或者遇到左括号，入栈
               3.左括号：直接入栈
               4.右括号：与栈top字符匹配，遇到左括号之前一直输出（2）top的字符
               5.所有中缀表达式字符读取完，若栈内还有字符，依次输出（3）到空为止
*/

//用顺序栈实现
typedef struct{
    double a[MAXSIZE];
    int top;
}sequence_Stack;

typedef struct{
    char a[MAXSIZE];
    int top;
}sequence_Stack_Char;

int GetLength(sequence_Stack *L){
    return L->top;
}

void Push(sequence_Stack *L,double x){
    if(L->top >= MAXSIZE){
        printf("栈已满！\n");
        exit(0);
    }
    L->a[L->top]=x;
    L->top++;
}

void Push_Char(sequence_Stack_Char *L,char x){
    if(L->top >= MAXSIZE){
        printf("栈已满！\n");
        exit(0);
    }
    L->a[L->top]=x;
    L->top++;
}


void Pop(sequence_Stack *L){
    if(L->top == 0){
        printf("栈已空!\n");
    }
    L->top--;
}

void Pop_Char(sequence_Stack_Char *L){
    if(L->top == 0){
        printf("栈已空!\n");
    }
    L->top--;
}

double PopAndGetTopNum(sequence_Stack *L){
    if(L->top == 0){
        printf("栈为空！\n");
        exit(0);
    }
    L->top--;
    return L->a[L->top];
}

void Print(sequence_Stack *L){
    if(L->top == 0){
        printf("栈已空!\n");
    }
    int t=L->top;
    while(t>0){
        printf("%4lf",L->a[t-1]);
        t--;
    }
    printf("\n");
}


//将中缀表达式数字字符转为数字
double TurnCharToNum(char a[],int *i){
    double intNum=0,pointNum=0;//整数部分 非数字部分 小数部分

    //整数部分
    while(a[*i] != '.' && a[*i] != '\0'){
        if(a[*i] >= '0' && a[*i] <= '9'){
            intNum= intNum*10 + (a[*i] - '0');
            (*i)++;
        }
        if(a[*i]==' '){//此时没有遍历到 .  就碰到空格，说明为整数
            return intNum;
        }
    }
    //小数部分
    int k=0;
    (*i)++;
    while(a[*i]>= '0' && a[*i] <='9' && a[*i] != '\0' && a[*i]!=' '){
        k++;
        pointNum = pointNum + pow(0.1,k)*(a[*i]-'0');
        (*i)++;
    }
    return intNum+pointNum;
}

//后缀表达式的实现(从字符串中读取数字——》存入栈中——》遇到符号进行计算——》最后返回结果
double PostfixExpressionCalculate(sequence_Stack *L,char a[]){
    int i=0;
    double frontNum=0,postNum=0,getNum=0;

    while(a[i] != '\0'){
        if(a[i] >= '0' && a[i]<= '9'){
            getNum=TurnCharToNum(a,&i);
            Push(L,getNum);
        }else if(a[i] == '+'){
            postNum=PopAndGetTopNum(L);
            frontNum=PopAndGetTopNum(L);
            Push(L,postNum+frontNum);
        }else if(a[i] == '-'){
            postNum=PopAndGetTopNum(L);
            frontNum=PopAndGetTopNum(L);
            Push(L,frontNum-postNum);
        }else if(a[i] == '*'){
            postNum=PopAndGetTopNum(L);
            frontNum=PopAndGetTopNum(L);
            Push(L,postNum*frontNum);
        }else if(a[i]== '/'){
            postNum=PopAndGetTopNum(L);
            frontNum=PopAndGetTopNum(L);
            Push(L,frontNum/postNum);
        }
        i++;
    }
    return L->a[0];
}

//将中缀表达式转为后缀表达式（用栈实现
char* TurnMidExToInfixExpression(char str[],sequence_Stack_Char *L){
    int i,j=0;
    char outStr[MAXSIZE];
    for(i=0;i<strlen(str);i++){//遍历字符
        if(str[i]>='0' && str[i]<='9' || str[i]==' '){
            outStr[j]=str[i];
            j++;
            printf("%c",str[i]);
        }else if(str[i]=='+' || str[i]=='-' || str[i]=='*' || str[i]=='/'){
            if(L->top==0){
               Push_Char(L,str[i]);
            }else if(str[i]=='*'||str[i]=='/'){
                if(L->a[L->top-1]=='+'||L->a[L->top-1]=='-'){
                    Push_Char(L,str[i]);
                }else{
                    while(L->top!=0 && L->a[L->top-1]!='('){
                        outChar(outStr,&j,L);
                    }
                    Push_Char(L,str[i]);
                }//先进的-》操作符优先级就更高
            }else if(str[i]=='+'||str[i]=='-'){
                while(L->top!=0 && L->a[L->top-1]!='('){
                        outChar(outStr,&j,L);
                }
                Push_Char(L,str[i]);
            }
        }else if(str[i]=='('){
            Push_Char(L,str[i]);
        }else if(str[i]==')'){
            while(L->a[L->top-1]!='('){
                outChar(outStr,&j,L);
            }
            Pop_Char(L);
        }
    }
    while(L->top!=0){
        outChar(outStr,&j,L);
    }
    outStr[j]='\0';
    return outStr;
}

void outChar(char outStr[],int *j,sequence_Stack_Char *L){
    outStr[*j]=L->a[L->top-1];
    printf("%c",outStr[*j]);
    Pop_Char(L);
    (*j)++;
}


int main()
{
    double totalNum;
    char str[MAXSIZE],* outStr;
    /*sequence_Stack *p;
    p=(sequence_Stack *)malloc(sizeof(sequence_Stack));
    p->top=0;
    printf("请输入后缀表达式:");
    gets(str);
    totalNum=PostfixExpressionCalculate(p,str);
    printf("结果：%g",totalNum);
    */
    sequence_Stack_Char *p;
    p=(sequence_Stack_Char *)malloc(sizeof(sequence_Stack_Char));
    p->top=0;
    sequence_Stack *k;
    k=(sequence_Stack *)malloc(sizeof(sequence_Stack));
    k->top=0;
    printf("请输入中缀表达式：");
    gets(str);
    printf("\n对应后缀表达式为：");
    outStr=TurnMidExToInfixExpression(str,p);

}
