#include<iostream.h>
#include<graphics.h>
#include<math.h>
#include<conio.h>
float pi=3.14;
float rad=(pi*30)/180;
int mal[3][3],mal1[3][3],xc,yc;
void mul(int a[3][3],int b[3][3])
{
	int sum=0;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			for(int k=0;k<3;k++)
			{
				sum=sum+a[i][k]*b[k][j];
			}
			mal[i][j]=sum;
			sum=0;
		}
	}
}

void mul1(int a[3][3],int b[3][1])
{
	int sum=0;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<1;j++)
		{
			for(int k=0;k<3;k++)
			{
				sum=sum+a[i][k]*b[k][j];
			}
			mal1[i][j]=sum;
			sum=0;
		}
	}
}

void fill(int x, int y,int bound, int new_c)
{
	int check=getpixel(x,y);
	if(check!=bound && check!=new_c)
	{
		putpixel(x,y,new_c);
		fill(x+1,y,bound,new_c);
		fill(x-1,y,bound,new_c);
		fill(x,y-1,bound,new_c);
		fill(x,y+1,bound,new_c);
	}
}
void petal(int x,int y, int r, float q1, float q2)
{       int z,a;
	setcolor(15);
	float a1=x+(r*cos(q1));
	float b1=y+(r*sin(q1));
	float a2=x+(r*cos(q2));
	float b2=y+(r*sin(q2));

	int ax[3][1];
	ax[0][0]=x;
	ax[1][0]=y;
	ax[2][0]=1;
	mul1(mal,ax);
	xc=mal1[0][0];
	yc=mal1[1][0];

	ax[0][0]=a1;
	ax[1][0]=b1;
	ax[2][0]=1;
	mul1(mal,ax);
	z=mal1[0][0];
	a=mal1[1][0];
	line(xc,yc,mal1[0][0],mal1[1][0]);
	ax[0][0]=a2;
	ax[1][0]=b2;
	ax[2][0]=1;
	mul1(mal,ax);

	line(xc,yc,mal1[0][0],mal1[1][0]);
	line(z,a,mal1[0][0],mal1[1][0]);

	line(x,y,a1,b1);
	line(x,y,a2,b2);
       line(a1,b1,a2,b2);
       //	for(float i=q1;i<=q2;){
       //	putpixel((x+(r*cos(i))),(y+(r*sin(i))),4);

       //	i+=0.000001;}

}
void main()
{       int gd=DETECT,gm,ts[3][3],ref[3][3];


	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(i==j){
				ts[i][j]=1;
				ref[i][j]=1;}
			else
			       {
			       ts[i][j]=0;
			       ref[i][j]=0;}
		}
	}
	ts[0][2]=-400;
	ref[0][0]=-1;
	mul(ref,ts);
	ts[0][2]=400;
	mul(ts,mal);

	petal(300,200,20,0,rad);
	petal(300,200,20,2*rad,3*rad);
	petal(300,200,20,4*rad,5*rad);
	petal(300,200,20,6*rad,7*rad);
	petal(300,200,20,8*rad,9*rad);
	petal(300,200,20,10*rad,11*rad);
	fill(300+(10*cos(rad/2)),200+(10*sin(rad/2)),WHITE,GREEN);
	fill(300+(10*cos(5*rad/2)),200+(10*sin(5*rad/2)),WHITE,YELLOW);
	fill(300+(10*cos(9*rad/2)),200+(10*sin(9*rad/2)),WHITE,GREEN);
	fill(300+(10*cos(13*rad/2)),200+(10*sin(13*rad/2)),WHITE,YELLOW);
	fill(300+(10*cos(17*rad/2)),200+(10*sin(17*rad/2)),WHITE,GREEN);
	fill(300+(10*cos(21*rad/2)),200+(10*sin(21*rad/2)),WHITE,YELLOW);
	fill(xc+(10*cos(3*rad/2)),yc+(10*sin(3*rad/2)),WHITE,GREEN);
	fill(xc+(10*cos(7*rad/2)),yc+(10*sin(7*rad/2)),WHITE,YELLOW);
	fill(xc+(10*cos(11*rad/2)),yc+(10*sin(11*rad/2)),WHITE,GREEN);
	fill(xc+(10*cos(15*rad/2)),yc+(10*sin(15*rad/2)),WHITE,YELLOW);
	fill(xc+(10*cos(19*rad/2)),yc+(10*sin(19*rad/2)),WHITE,GREEN);
	fill(xc+(10*cos(23*rad/2)),yc+(10*sin(23*rad/2)),WHITE,YELLOW);

	getch();
	closegraph();
}