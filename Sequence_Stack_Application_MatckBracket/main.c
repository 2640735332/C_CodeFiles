#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef struct{
    int a[MAXSIZE];
    int top;
}sequence_stack;

void Initial_Sequence_Stack(sequence_stack *L){
    L->top=0;
}

void Push_Sequence_Stack(sequence_stack *L){
    if(L->top == 0){
        printf("Õ»Îª¿Õ£¡\n");
        return;
    }
    L->top--;
}

int EmptyJudge_Sequence_Stack(sequence_stack *L)
{
    if(L->top == 0){
        return 0;
    }else{
        return 1;
    }
}

int Read_HeadOf_Sequence_Stack(sequence_stack *L

                               )

int main()
{


}
