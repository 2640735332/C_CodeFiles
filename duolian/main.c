#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int a[100];
    int len;
}s1;

void init(s1 *L)   //顺序表的初始化；
{
    L->len=0;
}
void creatlist(s1 *L)    //创建一个顺序表；
{
    int x,i=0;
    printf("请输入一组数据：\n");
    scanf("%d",&x);
    while(x!=0)
    {
        L->a[i]=x;
        i++;
        scanf("%d",&x);
    }
    L->len=i;     //顺序表的表长；
}

void printlist(s1 *L,int len)
{
   int x,i;
   printf("这组数据为：\n");
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
    printf("请输入你所要删除的数据：\n");
    scanf("%d",&x);
    for(i=0;i<L->len;i++)
    {
        if(L->a[i]==x)  //如果找到想要删除的数据；
        for(j=i;j<L->len;j++)   //从想要删除的数据位置开始，到顺序表的结尾结束；
            {
               L->a[j]=L->a[j+1];  //将后面的数据一次后移一个位置；

            }
            L->len--;        //表长减一；
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


















