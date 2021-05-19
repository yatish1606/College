/*
Assignment 10 ANIMATION WATER DROP

SE IT S1

8001 Yatish Kelkar
8005 Abhishek Thombare
8008 Atharva Joglekar
8009 Adesh Golghate

*/

#include<iostream>
#include<GL/glut.h>
#include<math.h>
using namespace std;

// function prototypes

void simplecircle(float r,float h,int k);
void concentric(float r,float h,int k);
void simplecircle1(float r,float h,int k);
void put_pixel(GLint x,GLint y);

// prog variables 
float boundaryColor[3]={1,0,0},interiorColor[3]={0,0,0},fillColor[3]={1,1,1},readpixel[3];
int X,Y;
int frame=0;


// draw ellipse
void myEllipse(int x,int y,float StAngle,float EndAngle,int RX, int RY)
{
	double i;
	glBegin(GL_LINE_STRIP);
	
		glColor3f(0.53f,0.81f,0.92f);
		i= StAngle;
		while(i<=EndAngle)
		{
			glVertex2f(int((RX*cos(i)+y)+.5),int((RY*sin(i)+x)+.5));
			i=i+.001;
		}
	glEnd();
	glFlush();
}

void setpixel(int x,int y)
{
	glColor3f(0.29,0.65,0.86);
	glBegin(GL_POINTS);
	glVertex2f(x,y);
	glEnd();
	glFlush();
}
void getpixel(int x,int y,float *color)
{
	glReadPixels(x,y,1,1,GL_RGB,GL_FLOAT,color);
}


// fill the drop
void floodfill(int x,int y)
{
	getpixel(x,y,readpixel);
	if(readpixel[0]==interiorColor[0] && readpixel[1]==interiorColor[1] && readpixel[2]==interiorColor[2])
	{
		setpixel(x,y);
		floodfill(x+1,y);
		floodfill(x,y+1);
		floodfill(x-1,y);
		floodfill(x,y-1);
	}
}


void myInit(void)
{
	glClearColor(0.0,0.0,0.0,0.0);
	glColor3f(0.53f,0.81f,0.92f);
	glPointSize(1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,640.0,0.0,480.0);
	
}

void performAnimation()
{
	for(float i=0;i<260;i=i+2.5)
	{
	
	
		glBegin(GL_LINES);
		
	        glVertex2i(300,420-i);
	        glVertex2i(280,380-i);
	        
	        glVertex2i(300,420-i);
	        glVertex2i(320,380-i);
	    glEnd();
	    
	        simplecircle(20,300,380-i);
	       
	        glClear(GL_COLOR_BUFFER_BIT);
        
    }
    
       
    glEnd();
       
	myEllipse(100,305,0,360,20,5);
	myEllipse(100,305,0,360,30,8);
	myEllipse(100,305,0,360,45,11);
	myEllipse(100,305,0,360,65,14);
	myEllipse(100,305,0,360,100,19);
	myEllipse(100,305,0,360,125,25);
	myEllipse(100,305,0,360,150,32);
	
	glFlush();
}

void myDisplay(void)
{
	
	glClear(GL_COLOR_BUFFER_BIT);
	performAnimation();
}

void put_pixel(GLint x,GLint y)
{
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
	glFlush();
}


int sign(float x)
{
	if(x>0)
		return 1;
	else if(x<0)
		return -1;
	else
		return 0;
}

void simplecircle(float r,float h,int k)
{
	int d;
	d=3-2*r;
	int x=0;
	int y=r;
	//put_pixel(h,k);
	while(x<=y)
	{
		if(d<0)
		{
			d=d+4*x+6;
			x=x+1;
		}
		else
		{
			d=d+4*(x-y)+10;
			x=x+1;
			y=y-1;
		}
		
		put_pixel(-x+h,-y+k);
		put_pixel(-y+h,-x+k);
		put_pixel(y+h,-x+k);
		put_pixel(x+h,-y+k);
	}
}

void timer(int v)                                  
{
	frame = frame + 10; 
	glutPostRedisplay();
	glutTimerFunc(30,timer,0); 
}

int main(int argc, char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE  | GLUT_RGB);
	glutInitWindowSize(640,480);
	glutInitWindowPosition(100,150);
	glutCreateWindow("Water Drop");
	myInit();
	glutDisplayFunc(myDisplay);
	glutTimerFunc(250,timer,0);
	glutMainLoop();
}        
