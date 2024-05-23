// Single Level Directory 

#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>

void main( )
{
    int gd=DETECT,gm,count,i,j,mid,cir_x;
    char fname[10] [20] ;

    initgraph(&gd,&gm,"c:\\tc\\bgi");
    cleardevice( ) ;
    setbkcolor(BLACK) ;
    puts("Enter No. of Files you have: ");
    scanf("%d",&count);

    for(i=0; i<count; i++)
    {
        cleardevice( );
        setbkcolor(BLACK);
        printf("Enter File %d Name: ", i+ 1);
        scanf("%s",fname[ i] ) ;

        setfillstyle(1,MAGENTA);
        mid=640/count ;
        cir_x=mid/3 ;
        bar3d(270,100,370,150,0,0);

        settextstyle(2,0,4);
        settextjustify(1,1);
        outtextxy(320,125,"Root Directory");
        setcolor( BLUE) ;

        for(j=0; j<=i; j++, cir_x+=mid)
        {
            line(320,150,cir_x,250);
            fillellipse(cir_x,250,30,30);
            outtextxy(cir_x,250,fname[j]);
        }
    }
}