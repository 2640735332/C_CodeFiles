#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXSIZE 100

//ʵ�ֺ�׺���ʽ�ļ���
/*
    ����˼�룺�Ƚ��ַ���תΪ������-���ٽ��м���
*/

//ʵ����׺ת��׺
/*
    �����㷨�� 1.���֣�ֱ�����
               2.�����:��ջΪ�գ���ջ
                        ��ջ��top�����������С�ڴ��������������ջ
                        ��ջ��top�������������ڴ������������top����������1������ջ��ֱ��top����������С������ջΪ�ա��������������ţ���ջ
               3.�����ţ�ֱ����ջ
               4.�����ţ���ջtop�ַ�ƥ�䣬����������֮ǰһֱ�����2��top���ַ�
               5.������׺���ʽ�ַ���ȡ�꣬��ջ�ڻ����ַ������������3������Ϊֹ
*/

//��˳��ջʵ��
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
        printf("ջ������\n");
        exit(0);
    }
    L->a[L->top]=x;
    L->top++;
}

void Push_Char(sequence_Stack_Char *L,char x){
    if(L->top >= MAXSIZE){
        printf("ջ������\n");
        exit(0);
    }
    L->a[L->top]=x;
    L->top++;
}


void Pop(sequence_Stack *L){
    if(L->top == 0){
        printf("ջ�ѿ�!\n");
    }
    L->top--;
}

void Pop_Char(sequence_Stack_Char *L){
    if(L->top == 0){
        printf("ջ�ѿ�!\n");
    }
    L->top--;
}

double PopAndGetTopNum(sequence_Stack *L){
    if(L->top == 0){
        printf("ջΪ�գ�\n");
        exit(0);
    }
    L->top--;
    return L->a[L->top];
}

void Print(sequence_Stack *L){
    if(L->top == 0){
        printf("ջ�ѿ�!\n");
    }
    int t=L->top;
    while(t>0){
        printf("%4lf",L->a[t-1]);
        t--;
    }
    printf("\n");
}


//����׺���ʽ�����ַ�תΪ����
double TurnCharToNum(char a[],int *i){
    double intNum=0,pointNum=0;//�������� �����ֲ��� С������

    //��������
    while(a[*i] != '.' && a[*i] != '\0'){
        if(a[*i] >= '0' && a[*i] <= '9'){
            intNum= intNum*10 + (a[*i] - '0');
            (*i)++;
        }
        if(a[*i]==' '){//��ʱû�б����� .  �������ո�˵��Ϊ����
            return intNum;
        }
    }
    //С������
    int k=0;
    (*i)++;
    while(a[*i]>= '0' && a[*i] <='9' && a[*i] != '\0' && a[*i]!=' '){
        k++;
        pointNum = pointNum + pow(0.1,k)*(a[*i]-'0');
        (*i)++;
    }
    return intNum+pointNum;
}

//��׺���ʽ��ʵ��(���ַ����ж�ȡ���֡���������ջ�С������������Ž��м��㡪������󷵻ؽ��
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

//����׺���ʽתΪ��׺���ʽ����ջʵ��
char* TurnMidExToInfixExpression(char str[],sequence_Stack_Char *L){
    int i,j=0;
    char outStr[MAXSIZE];
    for(i=0;i<strlen(str);i++){//�����ַ�
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
                }//�Ƚ���-�����������ȼ��͸���
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
    printf("�������׺���ʽ:");
    gets(str);
    totalNum=PostfixExpressionCalculate(p,str);
    printf("�����%g",totalNum);
    */
    sequence_Stack_Char *p;
    p=(sequence_Stack_Char *)malloc(sizeof(sequence_Stack_Char));
    p->top=0;
    sequence_Stack *k;
    k=(sequence_Stack *)malloc(sizeof(sequence_Stack));
    k->top=0;
    printf("��������׺���ʽ��");
    gets(str);
    printf("\n��Ӧ��׺���ʽΪ��");
    outStr=TurnMidExToInfixExpression(str,p);

}
