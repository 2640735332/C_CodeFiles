#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

//��������+����
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

//˳�������+����
typedef struct{
    int a[MAXSIZE];
    int size;
}sequence_List;

sequence_List* Initial_sequenceList(sequence_List *L){
    printf("���������ݣ�(��-1��Ϊ��β)\n");
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
        printf("��������\n");
        exit(1);
    }
    L->a[L->size]=x;
    L->size++;
}

//�ݹ��ӡ����
void Print_TriangleNum(int row,int maxRow){
    //��ӡ �ո� 1~row  row-1~1
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

//�ݹ��ӡ������
void Print_ReverseTriangleNum(int row,int maxRow){
    //��ӡ �ո� 1~row  row-1~1
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

//�ݹ�������������
void Print_LinkList(node *h){
    if(h==NULL){
        return;
    }
    printf("%2d",h->data);

    Print_LinkList(h->next);
}

//�ݹ������������
void Print_ReverseLinkList(node *h){
    if(h==NULL){
        return;
    }

    Print_ReverseLinkList(h->next);
    printf("%2d",h->data);
}

//�ݹ���������������η���(ʹ���˳˷�����������)
int PositiveSqrt(int num,int i){
    if(num >= i*i && num< (i+1)*(i+1)){
        return i;
    }else{
        return PositiveSqrt(num,i+1);
    }
}

//�ݹ��ӡ˳������׵�+β����
void PrintSequenceList_HeadPoint(int a[],int low,int high){
    if(low<=high){
        printf("%d  ",a[low]);
        PrintSequenceList_HeadPoint(a,low+1,high);
    }
}

//�ݹ��ӡ˳������ײ�+β�㣩
void PrintSequenceList_TailPoint(int a[],int low,int high){
    if(low<=high){
        printf("%d  ",a[high]);
        PrintSequenceList_TailPoint(a,low,high-1);
    }
}

//�ݹ��ӡ˳������е�+���ࣩ
void PrintSequencelList_MidPoint(int a[],int low,int high){
    if(low >high){
        return;
    }

    int mid = (low+high)/2;
    printf("%d  ",a[mid]);
    PrintSequencelList_MidPoint(a,low,mid-1);
    PrintSequencelList_MidPoint(a,mid+1,high);
}

//�ݹ�˳���������ң����е�+���ࣩ
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

//�ݹ�������ż(����ż��)
void ResetOddEven_SequenceList(int a[],int low,int high){
    if(low>high){
        return;
    }

    if(a[low]%2==0 && a[high]%2 == 0){//��ż ��ż
        ResetOddEven_SequenceList(a,low,high-1);
    }else if(a[low]%2==0 && a[high]%2==1){//��ż ����
        int temp;
        temp=a[low];
        a[low]=a[high];
        a[high]=temp;
        ResetOddEven_SequenceList(a,low+1,high-1);
    }else if(a[low]%2 == 1 && a[high]%2==0){//���� ��ż
        ResetOddEven_SequenceList(a,low+1,high-1);
    }else if(a[low]%2==1 && a[high]%2 ==1){//���� ����
        ResetOddEven_SequenceList(a,low+1,high);
    }
}

//�ݹ�����¥�ݣ�N�ף�һ��1��or2��
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

//�ݹ�����¥�ݣ�N�ף�һ��1��or2��
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

//���ӷ�ֳ����(��һ����һ�ԣ�һ���³��죬�����һ���²�һ�����ӣ���+ĸ��,���������ӵ�����)
//��һ����ֻ��һֻ����
int TotalRabbitCouples(int months){
    //�����������ӿ��ɵ�һ���͵ڶ��������ӵó�������һ���º͵ڶ����������޷����ƣ���
    //��Ҫ�ֶ����㲢���ص�һ���͵ڶ����µ�����
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
        ���µ��������� = ���µ��������� + ���³�������
        �� ���³������� = �����µ���������
        �ʣ� ���µ����� = ���µ��������� + �����µ���������
    */
    //���õݹ��ԭ���� ĳ�������� Ϊ ǰ������ÿ���������ӵĺͣ��ʴ���ͳһ�ԣ��ɵݹ�
    return TotalRabbitCouples(months-1)+TotalRabbitCouples(months-2);
}

//ȫ��������(Permutation ����)
void All_Permutation(int a[]){


}


//�ҵ�˳����е����ֵ
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

//�ҵ�˳����е���Сֵ
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
    //������¥�ݵ��ܴ���
    int x;
    printf("Please input total stairs:");
    scanf("%d",&x);
    printf("The num of ways to climb %d stair which most climb 2 stair per step is:%d",x,Calculate_ClimbStair2(x));
    printf("\n-----------------\n");
    printf("The num of ways to climb %d stair which most climb 3 stair per step is:%d",x,Calculate_ClimbStair3(x));
    */

    /*
    //�ݹ�ʵ��˳����������żת��
    sequence_List *s;
    s=Initial_sequenceList(s);
    ResetOddEven_SequenceList(s->a,0,s->size-1);
    PrintSequenceList_HeadPoint(s->a,0,s->size-1);
    */

    /*
    //�ݹ�ʵ��˳���Ĳ���
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
    //�ݹ��ӡ˳���
    sequence_List *s;
    s=Initial_sequenceList(s);
    PrintSequenceList_HeadPoint(s->a,0,s->size-1);//���׵�+β����ӡ
    printf("\n--------------------\n");
    PrintSequenceList_TailPoint(s->a,0,s->size-1);//���ײ�+β���ӡ
    printf("\n--------------------\n");
    PrintSequencelList_MidPoint(s->a,0,s->size-1);//���в���ӡ
    */

    /*
    //�ݹ����������η���
    int n;
    printf("Input num:");
    scanf("%d",&n);
    n=PositiveSqrt(n,1);
    printf("Positive sqrt num is:%d",n);
    */

    /*
    //��ӡ���ǲ���
    Print_TriangleNum(8,8);
    printf("-----------���Ƿָ���-----------\n");
    Print_ReverseTriangleNum(8,8);
    */

    /*
    //�ݹ��ӡ���������
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
