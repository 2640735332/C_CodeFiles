#include <stdio.h>
#include <stdlib.h>
#define newjd (node*)malloc(sizeof(node))
typedef struct k //��������
{
    int data;
    struct k *next;
} node;


node* creatlist() //��������
{
    node *h,*q,*tail;
    int x;
    h=NULL;
    printf("�����룺 ");
    scanf("%d",&x);
    if(x==0)
    {
        return NULL;
    }
    h=newjd;
    h->data=x;
    h->next=NULL;
    tail=h;
    scanf("%d",&x);
    while (x!=0)
    {
        q=newjd;
        q->data=x;
        q->next=NULL;
        tail->next=q;
        tail=q;
        scanf("%d",&x);
    }
    return h;
}

void  prt(node *h)
{
    node *q;
    for (q=h; q!=NULL; q=q->next)
    {
        printf("%d ",q->data);
    }
}



/*node* deljs(node *h)//ɾ������
{
    node *p,*q,*pre,*t;

    if(h==NULL)
    {
        return NULL;
    }
    while(h!=NULL && h->data%2!=0)
    {
        t=h;
        h=h->next;
        free(t);
    }
    if(h==NULL){
       return h;}
       pre=h;
    p=h->next;
while (p!=NULL)
    {
        if(p->data%2!=0)
        {
            t=p;
            pre->next=p->next;
            p=pre->next;
            free(t);
        }
        else
        {
            p=p->next;
            pre=pre->next;
        }

    }
    return h;
}
node *del(node *h,int x) //ɾ��xǰһ���ڵ�
{
    node *pre,*p,*q,*t;
   if(h==NULL){
    return h;
   }
    if(h->data==x)
    {
        printf("��ɾȥֵ");
        return h;}
        if(h->next->data==x){
            t=h;
            h=h->next;
            free(t);
            return h;
        }
        for (pre=h,p=h->next,q=p->next; q!=NULL && q->data!=x; p=p->next, q=q->next,pre=pre->next );
        if(q==NULL)
        {
            printf("δ�ҵ�");
            return h;
        }
        pre->next=q;
        free(p);
        return h;
    }*/
node *ehyd(node *h1,node *h2,node *h3)//�������ϳ������
{
    node *a,*b,*c,*h;
    a=h1;
    b=h2;
    h=h3;
    while(a!=NULL && b!=NULL)
    {
        if(a->data > b->data)
        {
            c=a;
            a=a->next;
        }
        else
        {
            c=b;
            b=b->next;
        }
            c->next=h;
             h=c;
    }
    while (a!=NULL){
            c=a;
            a=a->next;
            c->next=h;
            h=c;

    }
    while (b!=NULL){
            c=b;
            b=b->next;
            c->next=h;
            h=c;
    }

    return h;
}


main()
{
    node  *h1,*h2,*h3;
    h1=creatlist();
    printf("\n������:");
    prt(h1);
    h2=creatlist();
    printf("\n������:");
    prt(h2);
    //h=deljs(h);
    //h=del(h,5);
    h3=newjd;
    h3=NULL;
    h3=ehyd(h1,h2,h3);
    printf("\n���ձ�Ϊ��");
    prt(h3);
}


