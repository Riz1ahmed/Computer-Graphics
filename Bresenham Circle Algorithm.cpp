
// C program for DDA line generation
#include<stdio.h>
#include<graphics.h>
int abs(int n) {return n<0? -n:n;}
int swap(int &x,int &y){ x^=y^=x^=y;}
int max(int x,int y){return x>y ? x:y;}

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

void BresenhamCircleAlgo(int r, int x0,int y0){
    int x=0, y=r, k=0, Pk=0;
    while(x<=y){
        printf("k=%2d, Pk=%3d xy(%2d,%2d)\n",k, Pk, x, y);
        setPixel(x,y,x0,y0);
        delay(10);//So that we can see how draw line

        if (Pk==0)     Pk=3-2*r;
        else if (Pk<0) Pk=Pk+4*x+6,      x++;
        else if (Pk>0) Pk=Pk+4*(x-y)+10, x++, y--;
        k++;
    }

}

int main(){
	int gd = DETECT, gm;
	initgraph (&gd, &gm, "");//Initialize graphics function
	puts("***Bresenham Circle Algorithm***\n");

    int r, x, y;
    while(1){
        printf("Enter Center(x,y) and Radius(r) of circle (Ex:50 50 20): ");
        scanf("%d %d %d", &x, &y,&r);
        BresenhamCircleAlgo(x, y, r);
    }
	return 0;
}


