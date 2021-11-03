#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[6][6]={
        {0,1,2,3,4 ,5},
        {6,7,8,9,10,6},
        {0,1,2,3,4 ,5},
        {6,7,8,9,10,6},
        {0,1,2,3,4 ,5},
        {2,3,4,5,6 ,5},
    };

    int *X,*Y,x=0,y=0;
    X=&x,Y=&y;
    int startX=0,startY=0,maxX=6,maxY=6;

    int i;
    for(i=0;i<1;i++){
                for(x=startX;x<maxX;(*X)++){
                    printf("%3d",a[y][x]);

                }
                for(y=startY;y<maxY;(*Y)++){
                    printf("%3d",a[y][*X]);

                }
                for(x;x>=startX;(*X)--){
                    printf("%3d",a[y][x]);

                }
                startY++;
                startX++;
                maxX--;
                maxY--;
                for(y;y>=startY;(*Y)--){
                    printf("%3d",a[y][x]);

                }

    }

}
