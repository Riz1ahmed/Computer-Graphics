#include<stdio.h>
#include<graphics.h>
int abs(int n) {return n<0? -n:n;}
int swap(int &x,int &y){ x^=y^=x^=y;}
int max(int x,int y){return x>y ? x:y;}

void BresenhamLineAlgo(int x1,int y1, int x2,int y2){
    //abs(x1-x2) is less abs(y1-y2), then apply
    int m=abs(x1-x2) > abs(y1-y2);
    if (m==false) swap(x1,y1), swap(x2,y2);

    int dX=x2-x1;
    int dY=y2-y1;
    int twodlY=2*dY;
    int _2dY_2dX=2*dY-2*dX;
    int X=x1, Y=y1, k=0,Pk;

    while(k<abs(dX)){
        printf("k=%2d, Pk=%3d xy(%2d,%2d)\n",k, Pk, X,Y);
        if (m==true) putpixel (X,Y,YELLOW);
        else putpixel (Y,X,YELLOW);
        delay(10);//So that we can see how draw line

        if (k==0)       Pk=2*dY-dX;
        else if (Pk>=0) Pk=Pk+_2dY_2dX;
        else if (Pk<0)  Pk=Pk+twodlY;

        if (Pk>=0)     X++,Y++;
        else if (Pk<0) X++;

        k++;
    }
}

int main(){
	int gd = DETECT, gm;
	initgraph (&gd, &gm, "");//Initialize graphics function
	puts("***Bresenham Line Algorithm***\n");

    int x1, y1,x2,y2;
    while(1){
        printf("Enter x1,x1 (Ex:20 10): ");
        scanf("%d %d", &x1, &y1);
        printf("Enter x2,x2 (Ex:30 18): ");
        scanf("%d %d", &x2, &y2);
        BresenhamLineAlgo(x1,y1,x2,y2);
    }
	return 0;
}


