#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int a[100];
    int len;
}s1;

void init(s1 *L)   //˳���ĳ�ʼ����
{
    L->len=0;
}
void creatlist(s1 *L)    //����һ��˳���
{
    int x,i=0;
    printf("������һ�����ݣ�\n");
    scanf("%d",&x);
    while(x!=0)
    {
        L->a[i]=x;
        i++;
        scanf("%d",&x);
    }
    L->len=i;     //˳���ı���
}

void printlist(s1 *L,int len)
{
   int x,i;
   printf("��������Ϊ��\n");
   for(i=0;i<L->len;i++)
   {
       printf("%d ",L->a[i]);

   }
   printf("\n");
}

void deletelist(s1 *L)
{
    int j,i;
    int x;
    printf("����������Ҫɾ�������ݣ�\n");
    scanf("%d",&x);
    for(i=0;i<L->len;i++)
    {
        if(L->a[i]==x)  //����ҵ���Ҫɾ�������ݣ�
        for(j=i;j<L->len;j++)   //����Ҫɾ��������λ�ÿ�ʼ����˳���Ľ�β������
            {
               L->a[j]=L->a[j+1];  //�����������һ�κ���һ��λ�ã�

            }
            L->len--;        //����һ��
    }

}

int main()
{
    s1 L;
    init(&L);
    creatlist(&L);
    printlist(&L,L.len);
    deletelist(&L);
    printlist(&L,L.len);

}


















