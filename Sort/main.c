#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100
#define DataLength 10
//ֱ�Ӳ�������
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

//��ϣ���루����̽�ⷨ
void InsertByHash(int c[],int b[]){
    int x,i,index,j,count;
    int temp;

    printf("����������:");
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

//�������
void Print_Hash(int c[],int b[]){
    //����±�
    int j;

    for(j=0;j<15;j++){
        printf("%3d ",c[j]);
    }
    printf("    �±�\n");

    for(j=0;j<15;j++){
        printf("----");
    }
    printf("\n");

    //�������
    for(j=0;j<15;j++){
        printf("%3d ",b[j]);
    }
    printf("    ����\n");

    for(j=0;j<15;j++){
        printf("----");
    }
    printf("\n");

}

//����ɹ����Ҵ���
void PrintSuccess_Hash(int b[]){
    //������ҳɹ�����
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
    printf("    ���ҳɹ�����\n");
}

//���ʧ�ܲ��Ҵ���
void PrintFail_Hash(int b[]){
    //�������ʧ�ܴ���
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
    printf("    ����ʧ�ܴ���\n");

}

typedef struct node{
    int data;
    struct node* next;
}zipperNode;

typedef struct nodeArray{
    zipperNode *a[15];
}zipperArray;

//��ϣ���루������
zipperArray *InsertByHash_Zipper(zipperArray *z){
    int i;
    for(i=0;i<15;i++){
        z->a[i]=NULL;
    }

    int x,index;
    int count,temp;
    zipperNode *p,*t;

    printf("����������:");
    for(i=0;i<10;i++){
        scanf("%d",&x);
        index = x%15;
        t=(zipperNode *)malloc(sizeof(zipperNode));
        t->data=x;
        t->next=NULL;

        //β����
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

//���ɢ�б�
void Print_HashZipper(zipperArray *z){
    int i;
    zipperNode *p;

    printf("ɢ�б�\n");
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

//����ɹ�����(��ɢ�б����
void PrintSuccess_HashZipper(zipperArray *z){
    int i,count;
    zipperNode *p;

    printf("�ɹ�����:\n");
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

//���ʧ�ܲ���
void PrintFail_HashZipper(zipperArray *z){
    int i,count,index;
    zipperNode *p;

    printf("ʧ�ܲ��ң�\n");
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

//ð��ѡ������
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

//�������
void PrintArray_Int(int a[],int length){
    int i;

    for(i=0;i<length;i++){
        printf("%3d ",a[i]);
    }
    printf("\n");
}

//��������Сֵ������
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

//ֱ��ѡ������
void DierctSelectSort(int a[],int length){
    int minIndex,i,temp;

    for(i=0;i<length;i++){
        minIndex = MinIndex(a,i,length);
        temp = a[i];
        a[i] = a[minIndex];
        a[minIndex] = temp;
    }
}

//����ѡ������
/*�㷨˼�룺
    ѡһ����Ϊ������һ�ο���ѡ����������󣬽����бȸ���С����������ߣ��ȸ�������������ұ�
    �ݹ齫���������п���ѡ�����򣬽������Ҳ���п���ѡ������ֱ���˳���������ѡ����������Ϊֹ��
    ����ɹ�
*/
void QuickSelectSort(int a[],int left,int right){
    if(left >= right){
        return;
    }
    int temp,i,j;
    temp=a[left];
    i=left;
    j=right;

    while(i<j){//ii<j��ζ�Ż�������û�бȶ���(�������㣬��ȶ���)
        //�ҵ��ұ߱ȵ�ǰ��һ���ȵ�ǰtempС��
        while(i<j && temp>a[j]){
            j--;
        }
        if(i<j){//���߿�λ
            a[i]=a[j];
            i++;
        }
        //�ҵ���߱ȵ�ǰ��һ���ȵ�ǰtemp���
        while(i<j && temp<=a[i]){
            i++;
        }
        if(i<j){//��ұ߿�λ
            a[j]=a[i];
            j--;
        }
    }
    a[i]=temp;
    QuickSelectSort(a,left,i-1);
    QuickSelectSort(a,i+1,right);
}

//ϣ������
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


//����ֵ����
void ArrayDataSwap(int a[],int i,int j){
    int temp;
    temp=a[i];
    a[i]=a[j];
    a[j]=temp;
}

//�ѵ���
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

//����
void CreateHeap(int a[],int length){
    int j;

    for(j=(length/2-1);j>=0;j--){
        HeapAdjust(a,j,length);
    }
}

//������
void HeapSort(int a[],int length){
    int i,j,temp;

    for(i=length-1;i>0;i--){
        //����
        temp=a[i];
        a[i]=a[0];
        a[0]=temp;

        //����
        for(j=((i-1)/2-1);j>=0;j--){
            HeapAdjust(a,j,i);
        }
    }
}

//�鲢����(���߽� �ں�����
void MergeSort(int a[],int aLen){
    int i,step,mid,end;
    step=1;

    while(step < aLen){//�жϲ����Ƿ�Ϸ�
        for(i=0;(i+step*2)<=aLen;i=i+step*2){//�鲢
            Merge(a,i,i+step,i+2*step);
        }
        step*=2;

        if(step > aLen){//����β��ʣ��û�й鲢�Ĳ���
            Merge(a,0,step/2,aLen);
        }
    }
}

void Merge(int a[],int start,int mid,int end){
    //b������������ʱ����,���������д��a�������ͬλ��
    int b[MAXSIZE]={0};
    //�ڶ�����Ҫ�鲢�����ʼλ��mid���ڶ����鲢������λ��end
    int i,j,minNum,index,k;
    i=start;//i��j�ֱ�������һ���ڶ�������������
    j=mid;
    index=0;//��¼������b�����е�λ��/����

    while(i<mid && j<end){//���鲢�鳤���ص����ֺϲ�
        if(a[i]<a[j]){
            b[index]=a[i];
            i++;
        }else{
            b[index]=a[j];
            j++;
        }
        index++;
    }

    while(i<mid){//��һ���鲢��ǲ���д��b����
        b[index]=a[i];
        i++;
        index++;
    }

    while(j<end){//�ڶ����鲢��ǲ���д��b����
        b[index]=a[j];
        j++;
        index++;
    }

    for(k=0;k<index;k++){//��д��a����Ķ�Ӧλ��
        a[start+k]=b[k];
    }
}

int main()
{
    //ֱ�Ӳ�������
    /*
    int a[5]={5,-28,26,129,-1};
    int j;
    DirectInsertSort(a,5);

    PrintArray_Int(a,5);
    */

    //��ϣ�����������ݣ�1 68 23 57 9 93 43 32 19 29 �� 35 1 28 49 8 29 40 20 69 98

    /*
    int c[15]={0};
    int b[15]={0};
    //����̽�ⷨ��ϣ����
    InsertByHash(c,b);
    Print_Hash(c,b);
    PrintSuccess_Hash(b);
    PrintFail_Hash(b);
    */

    //��������ϣ����
    /*
    zipperArray *z;
    z=(zipperArray *)malloc(sizeof(zipperArray));
    z=InsertByHash_Zipper(z);
    Print_HashZipper(z);
    PrintSuccess_HashZipper(z);
    PrintFail_HashZipper(z);
    */

    //ð������
    /*
    int a[10]={1,68 ,23 ,57, 9 ,93, 43, 32 ,19, 29};
    BubbleSort(a,10);
    PrintArray_Int(a,10);
    */

    /*
    //ֱ��ѡ������
    int a[10]={1,68 ,23 ,57, 9 ,93, 43, 32 ,19, 29};
    DierctSelectSort(a,10);
    PrintArray_Int(a,10);
    */

    /*
    //ϣ������
    int a[10]={1,68 ,23 ,57, 9 ,93, 43, 32 ,19, 29};
    ShellSort(a,10);
    PrintArray_Int(a,10);
    */

    /*
    //����ѡ������
    int a[10]={1,68,23,57,9,93,43,32,19,29};
    QuickSelectSort(a,0,9);
    PrintArray_Int(a,10);
    */

    /*
    //�鲢����,���ں�����
    int a[10]={1,68,23,57,9,93,43,32,19,29};
    MergeSort(a,10);
    PrintArray_Int(a,10);
    */

    //������
    int a[10]={1,68,23,57,9,93,43,32,19,29};
    CreateHeap(a,DataLength);
    HeapSort(a,DataLength);
    PrintArray_Int(a,DataLength);
}
