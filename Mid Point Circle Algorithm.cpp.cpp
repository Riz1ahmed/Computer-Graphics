#include<stdio.h>
#include<graphics.h>
float abs (float n){ return n>0 ? n:-n;}
float max(float x,float y){return x>y ? x:y;}

void setPixel(int x,int y,int x0,int y0){
    putpixel(x0 + x, y0 + y, YELLOW);
    putpixel(x0 - x, y0 + y, YELLOW);
    putpixel(x0 + x, y0 - y, YELLOW);
    putpixel(x0 - x, y0 - y, YELLOW);
    putpixel(x0 + y, y0 + x, YELLOW);
    putpixel(x0 - y, y0 + x, YELLOW);
    putpixel(x0 + y, y0 - x, YELLOW);
    putpixel(x0 - y, y0 - x, YELLOW);
}
void MidPointCircleAlgorithm(int x0, int y0, int r){
    int x=0, y=r, p=1-r;
    while(x<=y){
        printf("p=%3d xy(%d,%d)\n",p,x,y);
        setPixel(x,y,x0,y0);
        delay(10);//So that we can see how draw line

        if (p<0)       x++,    p=p+2*x+1;
        else if (p>=0) x++,y--,p=p+2*(x-y)+1;
    }
}
int main(){
    int gd = DETECT, gm;
	initgraph (&gd, &gm, "");//Initialize graphics function
    puts("***Mid Point Cirle Algorithm***\n");

    int x, y, r;
    while(1){
        printf("Enter Center(x,y) and Radius(r) of circle (Ex:50 50 20): ");
        scanf("%d %d %d", &x, &y,&r);
        MidPointCircleAlgorithm(x, y, r);
    }
}
