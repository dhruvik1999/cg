#include<stdio.h> 
#include<GL/glut.h> 
#include<math.h> 
#include<bits/stdc++.h>
#define pi 3.142857 



// function to initialize 
using namespace std;


int xmax=300,xmin=0,ymax=300,ymin=0;


int x1=-150,yy1=200,x2=50,y2=0;
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

	int m = max(dx,dy);


	glBegin(GL_POINTS);
		
		while(x<x2){
			glVertex2i(x,y);

			x = x + ((float)dx/m);
			y = y +  ((float)(dy/m))*((y2-yy1)/abs(y2-yy1));
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
