#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

//链表声明+操作
typedef struct n{
    int data;
    struct n *next;
}node;

node* Initial_haveHead(node *h){
    h=(node *)malloc(sizeof(node));
    h->next=NULL;
    return h;
}

void Insert_haveHead_OnTail(node *h){
    int insertData;
    node *temp,*tail,*p;
    p=h;
    while(p!=NULL){//find tail
        tail=p;
        p=p->next;
    }
    printf("Please input integer num:(0 as stop,no repeat num)");
    scanf("%d",&insertData);
    while(insertData!=0){
        temp=(node *)malloc(sizeof(node));
        temp->next=NULL;
        temp->data=insertData;
        temp->next=tail->next;
        tail->next=temp;
        tail=temp;
        scanf("%d",&insertData);
    }
}

//顺序表声明+操作
typedef struct{
    int a[MAXSIZE];
    int size;
}sequence_List;

sequence_List* Initial_sequenceList(sequence_List *L){
    printf("请填入数据：(以-1作为结尾)\n");
    int x;
    scanf("%d",&x);
    L=(sequence_List *)malloc(sizeof(sequence_List));
    L->size=0;
    while(x != -1){
        L->a[L->size]=x;
        L->size++;
        scanf("%d",&x);
    }
    return L;
}

void Insert_seuqenceList(sequence_List *L,int x){
    if(L->size+1 >= 100){
        printf("表已满！\n");
        exit(1);
    }
    L->a[L->size]=x;
    L->size++;
}

//递归打印三角
void Print_TriangleNum(int row,int maxRow){
    //打印 空格 1~row  row-1~1
    int i;
    if(row <= 0 || row > maxRow){
        return;
    }
    Print_TriangleNum(row-1,maxRow);

    for(i=0;i<maxRow-row;i++){
        printf("  ");
    }

    for(i=1;i<=row;i++){
        printf("%2d",i);
    }

    for(i=row-1;i>=1;i--){
        printf("%2d",i);
    }
    printf("\n");
}

//递归打印倒三角
void Print_ReverseTriangleNum(int row,int maxRow){
    //打印 空格 1~row  row-1~1
    int i;
    if(row <= 0 || row > maxRow){
        return;
    }
    for(i=0;i<maxRow-row;i++){
        printf("  ");
    }

    for(i=1;i<=row;i++){
        printf("%2d",i);
    }

    for(i=row-1;i>=1;i--){
        printf("%2d",i);
    }
    printf("\n");
    Print_ReverseTriangleNum(row-1,maxRow);
}

//递归正遍历单链表
void Print_LinkList(node *h){
    if(h==NULL){
        return;
    }
    printf("%2d",h->data);

    Print_LinkList(h->next);
}

//递归逆遍历单链表
void Print_ReverseLinkList(node *h){
    if(h==NULL){
        return;
    }

    Print_ReverseLinkList(h->next);
    printf("%2d",h->data);
}

//递归输出正整数最大二次方根(使用了乘法，不算正解)
int PositiveSqrt(int num,int i){
    if(num >= i*i && num< (i+1)*(i+1)){
        return i;
    }else{
        return PositiveSqrt(num,i+1);
    }
}

//递归打印顺序表（按首点+尾部）
void PrintSequenceList_HeadPoint(int a[],int low,int high){
    if(low<=high){
        printf("%d  ",a[low]);
        PrintSequenceList_HeadPoint(a,low+1,high);
    }
}

//递归打印顺序表（按首部+尾点）
void PrintSequenceList_TailPoint(int a[],int low,int high){
    if(low<=high){
        printf("%d  ",a[high]);
        PrintSequenceList_TailPoint(a,low,high-1);
    }
}

//递归打印顺序表（按中点+两侧）
void PrintSequencelList_MidPoint(int a[],int low,int high){
    if(low >high){
        return;
    }

    int mid = (low+high)/2;
    printf("%d  ",a[mid]);
    PrintSequencelList_MidPoint(a,low,mid-1);
    PrintSequencelList_MidPoint(a,mid+1,high);
}

//递归顺序表的数查找（按中点+两侧）
int FindSequenceList_MisPoint(int a[],int low,int high,int x){
    if(low>high){
        return -1;
    }

    int mid = (low+high)/2;
    if(a[mid] == x){
        return 1;
    }

    int isFind = FindSequenceList_MisPoint(a,low,mid-1,x);
    if(isFind!=-1){
        return isFind;
    }
    isFind = FindSequenceList_MisPoint(a,mid+1,high,x);
    if(isFind!=-1){
        return isFind;
    }
}

//递归重置奇偶(奇左偶右)
void ResetOddEven_SequenceList(int a[],int low,int high){
    if(low>high){
        return;
    }

    if(a[low]%2==0 && a[high]%2 == 0){//左偶 右偶
        ResetOddEven_SequenceList(a,low,high-1);
    }else if(a[low]%2==0 && a[high]%2==1){//左偶 右奇
        int temp;
        temp=a[low];
        a[low]=a[high];
        a[high]=temp;
        ResetOddEven_SequenceList(a,low+1,high-1);
    }else if(a[low]%2 == 1 && a[high]%2==0){//左奇 右偶
        ResetOddEven_SequenceList(a,low+1,high-1);
    }else if(a[low]%2==1 && a[high]%2 ==1){//左奇 右奇
        ResetOddEven_SequenceList(a,low+1,high);
    }
}

//递归求走楼梯（N阶，一次1格or2格）
int Calculate_ClimbStair2(int n){
    if(n<1){
        return 0;
    }
    if(n==1){
        return 1;
    }
    if(n==2){
        return 2;
    }
    return Calculate_ClimbStair2(n-1)+Calculate_ClimbStair2(n-2);
}

//递归求走楼梯（N阶，一次1格or2格）
int Calculate_ClimbStair3(int n){
    if(n<1){
        return 0;
    }
    if(n==1){
        return 1;
    }
    if(n==2){
        return 2;
    }
    if(n==3){
        return 4;
    }
    return Calculate_ClimbStair3(n-1)+Calculate_ClimbStair3(n-2)+Calculate_ClimbStair3(n-3);
}

//兔子繁殖问题(第一个月一对，一个月成熟，成熟后一个月产一对兔子（公+母）,不考虑兔子的死亡)
//第一个月只有一只兔子
int TotalRabbitCouples(int months){
    //第三个月兔子可由第一个和第二个月兔子得出，而第一个月和第二个月兔子无法递推，故
    //需要手动计算并返回第一个和第二个月的兔子
    if(months<1){
        return 0;
    }
    if(months==1){
        return 1;
    }
    if(months==2){
        return 1;
    }
    /*
        本月底所有兔子 = 上月底所有兔子 + 本月出生兔子
        因： 本月出生兔子 = 上上月底所有兔子
        故： 本月底兔子 = 上月底所有兔子 + 上上月底所有兔子
    */
    //可用递归的原因是 某月总兔子 为 前两个月每个月总兔子的和，故存在统一性，可递归
    return TotalRabbitCouples(months-1)+TotalRabbitCouples(months-2);
}

//全排列问题(Permutation 排列)
void All_Permutation(int a[]){


}


//找到顺序表中的最大值
int recursion_max(sequence_List* L, int i, int max)
{
    if (i == L->size) return max;
    if (L->a[i] > max)
    {
        max = L->a[i];
        return recursion_max(L, ++i, max);
    }
    return recursion_max(L, ++i, max);
}

//找到顺序表中的最小值
int mina(int n, int a[])
{
    int t;
    if (n == 1)
        return a[0];
    t = mina(n - 1, a);
    if (t < a[n - 1])
        return t;
    else
        return a[n - 1];
}

int main()
{
    /*
    //计算爬楼梯的总次数
    int x;
    printf("Please input total stairs:");
    scanf("%d",&x);
    printf("The num of ways to climb %d stair which most climb 2 stair per step is:%d",x,Calculate_ClimbStair2(x));
    printf("\n-----------------\n");
    printf("The num of ways to climb %d stair which most climb 3 stair per step is:%d",x,Calculate_ClimbStair3(x));
    */

    /*
    //递归实现顺序表的左奇右偶转置
    sequence_List *s;
    s=Initial_sequenceList(s);
    ResetOddEven_SequenceList(s->a,0,s->size-1);
    PrintSequenceList_HeadPoint(s->a,0,s->size-1);
    */

    /*
    //递归实现顺序表的查找
    int i,x;
    sequence_List *s;
    s=Initial_sequenceList(s);
    printf("Please input num need to find:");
    scanf("%d",&x);
    i=FindSequenceList_MisPoint(s->a,0,s->size-1,x);
    if(i!=-1){
        printf("Find!");
    }else{
        printf("Not find!");
    }
    */

    /*
    //递归打印顺序表
    sequence_List *s;
    s=Initial_sequenceList(s);
    PrintSequenceList_HeadPoint(s->a,0,s->size-1);//按首点+尾部打印
    printf("\n--------------------\n");
    PrintSequenceList_TailPoint(s->a,0,s->size-1);//按首部+尾点打印
    printf("\n--------------------\n");
    PrintSequencelList_MidPoint(s->a,0,s->size-1);//按中部打印
    */

    /*
    //递归求整数二次方根
    int n;
    printf("Input num:");
    scanf("%d",&n);
    n=PositiveSqrt(n,1);
    printf("Positive sqrt num is:%d",n);
    */

    /*
    //打印三角操作
    Print_TriangleNum(8,8);
    printf("-----------我是分割线-----------\n");
    Print_ReverseTriangleNum(8,8);
    */

    /*
    //递归打印单链表操作
    /*
    node *a;
    a=Initial_haveHead(a);
    Insert_haveHead_OnTail(a);
    printf("Data in this list is:");
    Print_LinkList(a->next);
    printf("\nData in this list is:");
    Print_ReverseLinkList(a->next);
    */

    return 0;
}
