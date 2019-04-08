#include<stdio.h> 
#include<GL/glut.h> 
#include<math.h> 
#include<bits/stdc++.h>
#define pi 3.142857 



// function to initialize 
using namespace std;


int xmax=300,xmin=0,ymax=300,ymin=0;

int x1=0,yy1=0,x2=-100,y2=10;
void display(){


	int temp;


	if(x1 > x2){
		temp = x2;
		x2 = x1;
		x1 = temp;

		temp = yy1;
		yy1 = y2;
		y2 = temp;
	}


	float x = x1;
	float y = yy1;

	int dy = abs(y2-yy1);
	int dx = abs(x2-x1);


	glBegin(GL_POINTS);
		int p = 2*dy-dx;
		while(x<x2){
			x++;
			if(p>0){
				y+=(y2-yy1)/abs(y2-yy1);
				p = p + 2*dy-2*dx;
			}else{
				p = p + 2*dy;
			}
			glVertex2i((int)x,(int)y);
		}

	glEnd();
	glFlush();
}

int main (int argc, char** argv) 
{ 
    glutInit(&argc, argv); 
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
    
    // giving window size in X- and Y- direction 
    glutInitWindowSize(1366, 768); 
    glutInitWindowPosition(0, 0); 
    
    // Giving name to window 
    glutCreateWindow("Circle Drawing"); 
    //myInit(); 
    gluOrtho2D(-683,683,-384,384);
    glutDisplayFunc(display); 
    glutMainLoop(); 
} 
