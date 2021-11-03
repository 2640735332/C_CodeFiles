#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100
#define DataLength 10
//直接插入排序
void DirectInsertSort(int a[],int len){
    int i,j,x;

    for(i=0;i<len;i++){
        x=a[i];

        for(j=i;j>0 && a[j-1]>x;j--){
            a[j]=a[j-1];
        }
        a[j]=x;
    }
}

//哈希插入（线性探测法
void InsertByHash(int c[],int b[]){
    int x,i,index,j,count;
    int temp;

    printf("请输入数据:");
    for(i=0;i<10;i++){
        scanf("%d",&x);
        index = x%15;
        while(b[index]!=0){
            index = (index+1)%15;
        }
        b[index]=x;
        c[index]=i+1;
    }

}

//输出数据
void Print_Hash(int c[],int b[]){
    //输出下标
    int j;

    for(j=0;j<15;j++){
        printf("%3d ",c[j]);
    }
    printf("    下标\n");

    for(j=0;j<15;j++){
        printf("----");
    }
    printf("\n");

    //输出数据
    for(j=0;j<15;j++){
        printf("%3d ",b[j]);
    }
    printf("    数据\n");

    for(j=0;j<15;j++){
        printf("----");
    }
    printf("\n");

}

//输出成功查找次数
void PrintSuccess_Hash(int b[]){
    //输出查找成功次数
    int count,j,index,temp;
    for(j=0;j<15;j++){
        count=1;
        if(b[j]==0){
            printf("%3d ",0);
            continue;
        }
        temp=b[j];

        index = temp%15;
        while(b[index] != temp){
            index = (index+1)%15;
            count++;
        }
        printf("%3d ",count);
    }
    printf("    查找成功次数\n");
}

//输出失败查找次数
void PrintFail_Hash(int b[]){
    //输出查找失败次数
    int j,count,index;

    for(j=0;j<15;j++){
        count=1;
        index=j;
        while(b[index] != 0){
            count++;
            index= (index+1)%15;
        }
        printf("%3d ",count);
    }
    printf("    查找失败次数\n");

}

typedef struct node{
    int data;
    struct node* next;
}zipperNode;

typedef struct nodeArray{
    zipperNode *a[15];
}zipperArray;

//哈希插入（拉链法
zipperArray *InsertByHash_Zipper(zipperArray *z){
    int i;
    for(i=0;i<15;i++){
        z->a[i]=NULL;
    }

    int x,index;
    int count,temp;
    zipperNode *p,*t;

    printf("请输入数据:");
    for(i=0;i<10;i++){
        scanf("%d",&x);
        index = x%15;
        t=(zipperNode *)malloc(sizeof(zipperNode));
        t->data=x;
        t->next=NULL;

        //尾插入
        p=z->a[index];
        while(p!=NULL && p->next !=NULL){
            p=p->next;
        }

        if(p==NULL){
            z->a[index]=t;
        }else{
            t->next=p->next;
            p->next=t;
        }
    }

    return z;
}

//输出散列表
void Print_HashZipper(zipperArray *z){
    int i;
    zipperNode *p;

    printf("散列表：\n");
    for(i=0;i<15;i++){
        printf("%2d:",i);
        if(z->a[i]==NULL){
            printf(" null");

        }else{
            p=z->a[i];
            while(p!=NULL){
                printf("%3d ",p->data);
                p=p->next;
            }
        }
        printf("\n");
    }
}

//输出成功查找(按散列标对齐
void PrintSuccess_HashZipper(zipperArray *z){
    int i,count;
    zipperNode *p;

    printf("成功查找:\n");
    for(i=0;i<15;i++){
        count=0;
        printf("%2d: ",i);
        if(z->a[i]==NULL){
            printf("%2d ",0);
        }else{
            p=z->a[i];
            while(p!=NULL){
                count++;
                printf("%2d",count);
                p=p->next;
            }
        }
        printf("\n");
    }

}

//输出失败查找
void PrintFail_HashZipper(zipperArray *z){
    int i,count,index;
    zipperNode *p;

    printf("失败查找：\n");
    for(i=0;i<15;i++){
        count=1;
        index=i;
        printf("%2d: ",i);
        while(z->a[index] !=NULL){
            count++;
            index = (index+1)%15;
        }
        printf("%2d \n",count);
    }
}

//冒泡选择排序
void BubbleSort(int a[],int length){
    int isSorted = 1;
    int i,j,temp;

    for(i=0;i<length;i++){
        isSorted = 1;
        for(j=0;j<length-i-1;j++){
            if(a[j] > a[j+1]){
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;

                isSorted = 0;
            }
        }

        if(isSorted == 1){
            return;
        }
    }
}

//输出数组
void PrintArray_Int(int a[],int length){
    int i;

    for(i=0;i<length;i++){
        printf("%3d ",a[i]);
    }
    printf("\n");
}

//找数组最小值的索引
int MinIndex(int a[],int left,int right){
    if(left>right){
        return -1;
    }

    int min,i;
    min = left;

    for(i=left;i<right;i++){
        if(a[min] > a[i]){
            min = i;
        }
    }
    return min;
}

//直接选择排序
void DierctSelectSort(int a[],int length){
    int minIndex,i,temp;

    for(i=0;i<length;i++){
        minIndex = MinIndex(a,i,length);
        temp = a[i];
        a[i] = a[minIndex];
        a[minIndex] = temp;
    }
}

//快速选择排序
/*算法思想：
    选一个数为基础，一次快速选择排序结束后，将所有比该数小的数置于左边，比该数大的数置于右边
    递归将该数左侧进行快速选择排序，将该数右侧进行快速选择排序，直到退出（不满足选择排序条件为止）
    排序成功
*/
void QuickSelectSort(int a[],int left,int right){
    if(left >= right){
        return;
    }
    int temp,i,j;
    temp=a[left];
    i=left;
    j=right;

    while(i<j){//ii<j意味着还存在数没有比对完(若不满足，则比对完)
        //找到右边比当前第一个比当前temp小的
        while(i<j && temp>a[j]){
            j--;
        }
        if(i<j){//填到左边空位
            a[i]=a[j];
            i++;
        }
        //找到左边比当前第一个比当前temp大的
        while(i<j && temp<=a[i]){
            i++;
        }
        if(i<j){//填到右边空位
            a[j]=a[i];
            j--;
        }
    }
    a[i]=temp;
    QuickSelectSort(a,left,i-1);
    QuickSelectSort(a,i+1,right);
}

//希尔排序
void ShellSort(int a[],int length){
    int d,i,j,temp;
    d=length/2;

    while(d>0){
        for(i=d;i<length;i++){
            temp = a[i];
            for(j=i-d;j>=0 && a[j]>temp;j=j-d){
                a[j+d] = a[j];
            }
            a[j+d]=temp;
        }
        d=d/2;
    }
}


//数组值交换
void ArrayDataSwap(int a[],int i,int j){
    int temp;
    temp=a[i];
    a[i]=a[j];
    a[j]=temp;
}

//堆调整
void HeapAdjust(int a[],int i,int length){
    int leftChild,rightChild,maxIndex;
    leftChild=i*2+1;
    rightChild=i*2+2;
    maxIndex=i;

    if(leftChild<length && a[leftChild]>a[maxIndex]){
        maxIndex=leftChild;
    }

    if(rightChild<length && a[rightChild]>a[maxIndex]){
        maxIndex=rightChild;
    }

    if(maxIndex!=i){
        ArrayDataSwap(a,i,maxIndex);
        HeapAdjust(a,maxIndex,length);
    }
}

//建堆
void CreateHeap(int a[],int length){
    int j;

    for(j=(length/2-1);j>=0;j--){
        HeapAdjust(a,j,length);
    }
}

//堆排序
void HeapSort(int a[],int length){
    int i,j,temp;

    for(i=length-1;i>0;i--){
        //交换
        temp=a[i];
        a[i]=a[0];
        a[0]=temp;

        //调整
        for(j=((i-1)/2-1);j>=0;j--){
            HeapAdjust(a,j,i);
        }
    }
}

//归并排序(或者叫 融合排序
void MergeSort(int a[],int aLen){
    int i,step,mid,end;
    step=1;

    while(step < aLen){//判断步长是否合法
        for(i=0;(i+step*2)<=aLen;i=i+step*2){//归并
            Merge(a,i,i+step,i+2*step);
        }
        step*=2;

        if(step > aLen){//处理尾部剩余没有归并的部分
            Merge(a,0,step/2,aLen);
        }
    }
}

void Merge(int a[],int start,int mid,int end){
    //b数组用来存临时数据,排序完后重写到a数组的相同位置
    int b[MAXSIZE]={0};
    //第二个需要归并块的起始位置mid，第二个归并块的最后位置end
    int i,j,minNum,index,k;
    i=start;//i，j分别索引第一、第二个排序块的数据
    j=mid;
    index=0;//记录数据在b数组中的位置/总数

    while(i<mid && j<end){//两归并块长度重叠部分合并
        if(a[i]<a[j]){
            b[index]=a[i];
            i++;
        }else{
            b[index]=a[j];
            j++;
        }
        index++;
    }

    while(i<mid){//第一个归并块非部分写入b数组
        b[index]=a[i];
        i++;
        index++;
    }

    while(j<end){//第二个归并块非部分写入b数组
        b[index]=a[j];
        j++;
        index++;
    }

    for(k=0;k<index;k++){//重写回a数组的对应位置
        a[start+k]=b[k];
    }
}

int main()
{
    //直接插入排序
    /*
    int a[5]={5,-28,26,129,-1};
    int j;
    DirectInsertSort(a,5);

    PrintArray_Int(a,5);
    */

    //哈希插入输入数据：1 68 23 57 9 93 43 32 19 29 或 35 1 28 49 8 29 40 20 69 98

    /*
    int c[15]={0};
    int b[15]={0};
    //线性探测法哈希插入
    InsertByHash(c,b);
    Print_Hash(c,b);
    PrintSuccess_Hash(b);
    PrintFail_Hash(b);
    */

    //拉链法哈希插入
    /*
    zipperArray *z;
    z=(zipperArray *)malloc(sizeof(zipperArray));
    z=InsertByHash_Zipper(z);
    Print_HashZipper(z);
    PrintSuccess_HashZipper(z);
    PrintFail_HashZipper(z);
    */

    //冒泡排序
    /*
    int a[10]={1,68 ,23 ,57, 9 ,93, 43, 32 ,19, 29};
    BubbleSort(a,10);
    PrintArray_Int(a,10);
    */

    /*
    //直接选择排序
    int a[10]={1,68 ,23 ,57, 9 ,93, 43, 32 ,19, 29};
    DierctSelectSort(a,10);
    PrintArray_Int(a,10);
    */

    /*
    //希尔排序
    int a[10]={1,68 ,23 ,57, 9 ,93, 43, 32 ,19, 29};
    ShellSort(a,10);
    PrintArray_Int(a,10);
    */

    /*
    //快速选择排序
    int a[10]={1,68,23,57,9,93,43,32,19,29};
    QuickSelectSort(a,0,9);
    PrintArray_Int(a,10);
    */

    /*
    //归并排序,或“融合排序”
    int a[10]={1,68,23,57,9,93,43,32,19,29};
    MergeSort(a,10);
    PrintArray_Int(a,10);
    */

    //堆排序
    int a[10]={1,68,23,57,9,93,43,32,19,29};
    CreateHeap(a,DataLength);
    HeapSort(a,DataLength);
    PrintArray_Int(a,DataLength);
}
