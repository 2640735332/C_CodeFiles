#include <stdio.h>
#include <stdlib.h>

//"haveHead" means the list have head node,"noHead" means the list no head node
//"OnTail/OnHead" means function is operate on "tail/head"(insert or delete)

typedef struct n{
    int data;
    struct n *next;
}node;

node* Initial_haveHead(node *h){
    h=(node *)malloc(sizeof(node));
    h->next=NULL;
    return h;
}

node* Initial_noHead(node *h){
    h=NULL;
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

void Insert_haveHead_OnHead(node *h){
    int insertData;
    node *temp,*p;
    p=h;
    printf("Please input integer num:(0 as stop,no repeat num)");
    scanf("%d",&insertData);
    while(insertData!=0){
        temp=(node *)malloc(sizeof(node));
        temp->next=NULL;
        temp->data=insertData;
        temp->next=p->next;
        p->next=temp;
        scanf("%d",&insertData);
    }
}

node* Insert_noHead_OnTail(node *h){
    int insertData,isHeadNull=0;
    printf("Please input integer num:(0 as stop,no repeat num)");
    scanf("%d",&insertData);
    node *p,*tail,*head,*temp;
    if(h==NULL && insertData!=0){
        p=(node *)malloc(sizeof(node));
        p->data=insertData;
        p->next=NULL;
        isHeadNull=1;
    }
    head=p;
    tail=p;
    while(tail->next != NULL){//find tail node
        tail=tail->next;
    }
    while(insertData !=0){
        if(isHeadNull==1){
            scanf("%d",&insertData);
            isHeadNull=0;
            continue;
        }
        temp=(node *)malloc(sizeof(node));
        temp->next=NULL;

        temp->data=insertData;
        temp->next=tail->next;
        tail->next=temp;
        tail=temp;
        scanf("%d",&insertData);
    }
    return head;
}

node* Insert_noHead_OnHead(node *h){
    int insertData,isHeadNull=0;
    printf("Please input integer num:(0 as stop,no repeat num)");
    scanf("%d",&insertData);

    node *head,*temp;
    head=h;
    if(head==NULL){//judge whether head is null and create the head node
        head=(node *)malloc(sizeof(node));
        head->data=insertData;
        head->next=NULL;
        isHeadNull=1;
    }
    while(insertData!=0){
        if(isHeadNull==1){
            scanf("%d",&insertData);
            isHeadNull=0;
        }
        temp=(node *)malloc(sizeof(node));
        temp->data=insertData;
        temp->next=head;
        head=temp;
        scanf("%d",&insertData);
    }
    return head;
}

void InsertRegular_haveHead_DataUp(node *h){
    int insertData;
    printf("Please input integer num that needs to insert:(0 as stop,no repeat num)");
    scanf("%d",&insertData);

    node *p,*temp;
    p=h;
    while(p->next!=NULL){
        if(p->next->data>=insertData){
            temp=(node *)malloc(sizeof(node));
            temp->next=NULL;
            temp->data=insertData;
            break;
        }
        p=p->next;
    }
    temp->next=p->next;
    p->next=temp;
    printf("Succes insert!\n");
}

void InsertRegular_haveHead_DataDown(node *h){

}

node* InsertRegular_noHead_DataUp(node *h){
    int x;
    printf("Please input integer num that needs to insert:(0 as stop,no repeat num)");
    scanf("%d",&x);

    node *p,*pre,*t;
    if(h==NULL){
        h=(node *)malloc(sizeof(node));
        h->data=x;
        h->next=NULL;
        return h;
    }
    if(h->data > x){
        p=(node *)malloc(sizeof(node));
        p->next=h;
        h=p;
        p->data=x;
        return h;
    }
    p=h->next;
    pre=h;
    while(p!=NULL){
        if(p->data > x){
            t=(node *)malloc(sizeof(node));
            t->data=x;

            t->next=p;
            pre->next=t;
            return h;
        }else{
            p=p->next;
            pre=pre->next;
        }
    }
}

node* InsertRegular_noHead_DataDown(node *h){
    int x;
    printf("Please input integer num that needs to insert:(0 as stop,no repeat num)");
    scanf("%d",&x);

    node *p,*pre,*t;
    if(h==NULL){
        h=(node *)malloc(sizeof(node));
        h->data=x;
        h->next=NULL;
        return h;
    }
    if(h->data < x){
        p=(node *)malloc(sizeof(node));
        p->next=h;
        h=p;
        p->data=x;
        return h;
    }
    p=h->next;
    pre=h;
    while(p!=NULL){
        if(p->data < x){
            t=(node *)malloc(sizeof(node));
            t->data=x;

            t->next=p;
            pre->next=t;
            return h;
        }else{
            p=p->next;
            pre=pre->next;
        }
    }
}

void PrintList_haveHead(node *h){
    node *p;
    p=h->next;
    if(p==NULL){
        printf("List is Null!");
        return;
    }else{
        printf("List is:\n");
        while(p!=NULL){
            printf("%3d",p->data);
            p=p->next;
        }
        printf("\n");
    }
}

void PrintList_noHead(node *h){
    node *p;
    p=h;
    if(p==NULL){
        printf("List is Null!");
        return;
    }else{
        printf("List is:\n");
        while(p!=NULL){
            printf("%3d",p->data);
            p=p->next;
        }
        printf("\n");
    }
}

void FindAndDelete_haveHead(node *h){
    int deleteData;
    printf("Please input data that need to delete:");
    scanf("%d",&deleteData);
    node *pre,*p;
    pre=h,p=h->next;
    while(p!=NULL){
        if(p->data==deleteData){
            pre->next=p->next;
            free(p);
            printf("Success found and deleted!\n");
            return;
        }
        p=p->next;
        pre=pre->next;
    }
    printf("There is no the data in this list!");
}

node* FindAndDelete_noHead(node *h){
    int deleteData;
    printf("Please input data that need to delete:");
    scanf("%d",&deleteData);
    node *pre,*p,*temp;
    pre=h,p=h->next;
    if(pre->data==deleteData){
        temp=pre;
        pre=pre->next;
        free(temp);
        printf("Success found and deleted!\n");
        return pre;
    }
    while(p!=NULL){
        if(p->data==deleteData){
            pre->next=p->next;
            free(p);
            printf("Success found and deleted!\n");
            return h;
        }
        p=p->next;
        pre=pre->next;
    }
    printf("There is no the data in this list!");
}

void FindAndDeleteNext_haveHead(node *h){
    int deleteData;
    printf("Please input data that need to find:");
    scanf("%d",&deleteData);
    node *head,*p,*temp;
    p=h->next;
    while(p!=NULL){
        if(p->data == deleteData){
            if(p->next == NULL){
                printf("Failed to delete. The next of this num is null!\n");
                return;
            }
            temp=p->next;
            p->next=p->next->next;
            free(temp);
            printf("Succeed delete!\n");
            return;
        }
        p=p->next;
    }
    printf("Failed to delete. The list doesn't have this num!\n");
}

void FindAndDeletePre_haveHead(node *h){
    int findData;
    printf("Please input data that need to find:");
    scanf("%d",&findData);

    node *pre,*p,*temp;
    p=h;
    if(p->next->data==findData){
        printf("The pre of this data node is null!\n");
        return;
    }else{
        pre=h;
        p=h->next;
    }
    while(p->next!=NULL){
        if(p->next->data==findData){
            temp=p;
            pre->next=p->next;
            free(temp);
            printf("Succeed delete!\n");
            return;
        }
        p=p->next;
        pre=pre->next;
    }
    printf("Failed to find the num. The list doesn't have this num!\n");
}

node* MergeTwoRegular_haveHead_OnTail(node *ha,node *hb){
    node *p,*a,*b,*min,*tail;
    a=ha->next;
    b=hb->next;
    p=ha;
    p->next=NULL;
    tail=p;
    while(a!=NULL && b!=NULL){
        if(a->data<=b->data){
            min=a;
            a=a->next;
        }else{
            min=b;
            b=b->next;
        }
        min->next=tail->next;
        tail->next=min;
        tail=min;
    }
    if(a!=NULL){
        tail->next=a;
    }
    if(b!=NULL){
        tail->next=b;
    }
    return p;
}

node* MergeTwoRegular_haveHead_OnHead(node *ha,node *hb){
    node *p,*a,*b,*min,*temp;
    a=ha->next;
    b=hb->next;
    p=ha;
    p->next=NULL;
    while(a!=NULL && b!=NULL){
        if(a->data<=b->data){
            min=a;
            a=a->next;
        }else{
            min=b;
            b=b->next;
        }
        min->next=p->next;
        p->next=min;
    }
    while(a!=NULL){
        temp=a;
        a=a->next;
        temp->next=p->next;
        p->next=temp;
    }
    while(b!=NULL){
        temp=b;
        b=b->next;
        temp->next=p->next;
        p->next=temp;
    }
    return p;
}

node* MergeTwoRegular_noHead_OnHead(node *ha,node *hb){
    node *h,*p,*q,*t,*hc;
    h=(node *)malloc(sizeof(node));
    h->next=NULL;
    p=ha;
    q=hb;
    while(p!=NULL && q!=NULL){
        if(p->data > q->data){
            t=p;
            p=p->next;
        }else{
            t=q;
            q=q->next;
        }
        t->next=h->next;
        h->next=t;
    }
    while(p!=NULL){
        t=p;
        p=p->next;
        t->next=h->next;
        h->next=t;
    }

    while(q!=NULL){
        t=q;
        q=q->next;
        t->next=h->next;
        h->next=t;
    }
    h=h->next;
    return h;
}

node* MergeTwoRegular_noHead_OnTail(node *ha,node *hb){
    node *h,*p,*q,*t,*tail;
    h=(node *)malloc(sizeof(node));
    h->next=NULL;
    tail=h;

    p=ha;
    q=hb;
    while(p!=NULL && q!=NULL){
        if(p->data > q->data){
            t=p;
            p=p->next;
        }else{
            t=q;
            q=q->next;
        }
        t->next=tail;
        tail->next=t;
        tail=tail->next;
    }
    if(p!=NULL){
        tail->next=p;
    }

    if(q!=NULL){
        tail->next=q;
    }
    h=h->next;
    return h;

}

node* DeleteFirstOddData_noHead(node *h){//Delete the first data if it is odd number
    node *t;
    if(h->data %2 ==1){
        t=h;
        h=h->next;
        free(t);
        printf("Succeed delete!\n");
        return h;
    }
}

void DeleteAllOddNum_haveHead(node *h){
    node *p,*pre,*t;
    p=h->next;
    pre=h;
    while(p!=NULL){
        if(p->data %2 == 1){
            t=p;
            p=p->next;
            pre->next=p;
            free(t);
        }else{
            p=p->next;
            pre=pre->next;
        }
    }
}

node* DeleteAllOddNum_noHead(node *h){
    node *t,*pre,*p;
    if(h==NULL){
        printf("The list is Null!");
        return h;
    }
    while(h!=NULL && h->data %2 == 1){
        t=h;
        h=h->next;
        free(t);
    }

    if(h==NULL){
        return h;
    }
    pre=h;
    p=h->next;
    while(p!=NULL){
        if(p->data%2 ==1){
            t=p;
            p=p->next;
            pre->next=p;
            free(t);
        }else{
            p=p->next;
            pre=pre->next;
        }
    }
    return h;
}

int main()
{
    node *a,*b,*c;

    return 0;
}
