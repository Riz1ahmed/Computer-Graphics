#include<stdio.h>
#include<graphics.h>
float abs (float n){ return n>0 ? n:-n;}
float max(float x,float y){return x>y ? x:y;}
float min(float x,float y){return x<y ? x:y;}

int winX1,winY1,winX2,winY2;
void DrawWindow(){
    for (int i=winX1; i<=winX2; i++)
        putpixel(i, winY1, YELLOW), putpixel(i, winY2, YELLOW), delay(10);
    for (int i=winY1; i<=winY2; i++)
        putpixel(winX1, i, YELLOW), putpixel(winX2, i, YELLOW), delay(10);
}

void DrawLineUsingDDA(float X0, float Y0, float X1, float Y1,int color){
	float dx=X1-X0, dy=Y1-Y0;
	float steps = max(abs(dx),abs(dy));
	//Increment of x & y
	float Xinc = dx / (float)steps;
	float Yinc = dy / (float)steps;

	float X = X0, Y = Y0;
	for (float i = 0; i <= steps; i++){
		putpixel (X,Y,color);
		X+=Xinc, Y+=Yinc;
		delay(10);
	}
}
int FindBits(int x,int y){
    int bt=0;
    if (y-max(winY1,winY2) > 0) bt|=(1<<3);
    if (min(winY1,winY2)-y > 0) bt|=(1<<2);
    if (x-max(winX1,winX2) > 0) bt|=(1<<1);
    if (min(winX1,winX2)-x > 0) bt|=(1<<0);
    return bt;
}
void CandidateTheLine(int initBits,float x1,float y1, int termBits,float x2,float y2){
    float m=(y2-y1)/(x2-x1);
    float cx1=x1,cy1=y1,cx2=x2,cy2=y2;
    //printf("m=%.2f\n",m);
    if (initBits&(1<<3)) y1=max(winY1,winY2);
    if (initBits&(1<<2)) y1=min(winY1,winY2);
    if (y1==max(winY1,winY2) || y1==min(winY1,winY2))
        x1=cx1 + (1/m)*(y1-cy1);

    if (initBits&(1<<1)) x1=max(winX1,winX2);
    if (initBits&(1<<0)) x1=min(winX1,winX2);
    if (x1==max(winX1,winX2) || x1==min(winX1,winX2))
        y1=cy1 + m*(x1-cx1);

    if (termBits&(1<<3)) y2=max(winY1,winY2);
    if (termBits&(1<<2)) y2=min(winY1,winY2);
    if (y2==max(winY1,winY2) || y2==min(winY1,winY2))
        x2=cx1 + (1/m)*(y2-cy1);

    if (termBits&(1<<1)) x2=max(winX1,winX2);
    if (termBits&(1<<0)) x2=min(winX1,winX2);
    if (x2==max(winX1,winX2) || x2==min(winX1,winX2))
        y2=cy1 + m*(x2-cx1);

    DrawLineUsingDDA(x1,y1,x2,y2,YELLOW);
}
int main(){
    int bt=0;
    bt|=(1<<0);
    printf("%d\n",bt);
    int gd = DETECT, gm;
	initgraph (&gd, &gm, "");//Initialize graphics function
    puts("***Cohen Sutherland Line Clipping Algorithm***\n");

    puts("Input the lower bound of window (winX1 winY1):");
    scanf("%d %d", &winX1, &winY1);
    puts("Input the upper bound of window (winX2 winY2):");
    scanf("%d %d", &winX2, &winY2);
    DrawWindow();

    int lx1,ly1,lx2,ly2;
    while(1){
        puts("Input the initial position of line (lx1 ly1):");
        scanf("%d %d", &lx1, &ly1);
        puts("Input the terminal position of line (lx2 ly2):");
        scanf("%d %d", &lx2, &ly2);
        DrawLineUsingDDA(lx1,ly1,lx2,ly2, YELLOW);
        int initBits=FindBits(lx1,ly1);
        int termBits=FindBits(lx2,ly2);

        if ((initBits & termBits)!=0){
            puts("This line is out size of Region.");
            delay(1000);
            DrawLineUsingDDA(lx1,ly1,lx2,ly2, BLACK);
            puts("So I removed it.");
        }else{
            puts("This line maybe candidate.");
            DrawLineUsingDDA(lx1,ly1,lx2,ly2, BLACK);//Remove line
            CandidateTheLine(initBits,lx1,ly1, termBits,lx2,ly2);
        }
        puts("\nTry another line.");
    }
}
