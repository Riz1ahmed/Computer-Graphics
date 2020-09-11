// C program for DDA line generation
#include<stdio.h>
#include<graphics.h>
float abs (float n){ return n>0 ? n:-n;}
float max(float x,float y){return x>y ? x:y;}

void DDA(float X0, float Y0, float X1, float Y1){
    X0+=200, Y0+=200, X1+=200, Y1+=200;
	float dx=X1-X0, dy=Y1-Y0;
	float steps = max(abs(dx),abs(dy));
	//Increment of x & y
    printf("Dx=%f,Dy=%f, Step=%f\n",dx,dy,steps);
	float Xinc = dx / (float)steps;
	float Yinc = dy / (float)steps;

    printf("Xinc=%f,Yinc=%f\n",Xinc,Yinc);
	float X = X0, Y = Y0;
	for (float i = 0; i <= steps; i++){
        //printf("%f,%f\n",X,Y);

		putpixel (X,Y,YELLOW);
		X+=Xinc, Y+=Yinc;
		delay(1);
	}
}

int main(){
	int gd = DETECT, gm;
	initgraph (&gd, &gm, "");//Initialize graphics function
    DDA(-70,90, -20,50);

//    DDA(30,-70, 10,50);
//    DDA(10,50, -50,20);
//    DDA(-50,20,30,-70);
//    DDA(71.63,-10.73, -35.45,33.09);
//    DDA(-35.45,33.09, -08.81,-50.45);
//    DDA(-08.81,-50.45, 71.63,-10.73);


	while(1);
	return 0;
}

