#include<stdio.h> 
#include<GL/glut.h> 
#include<math.h> 
#include<bits/stdc++.h>
#define pi 3.142857 



// function to initialize 
using namespace std;


int rx =200,ry=100;	

void display(){
	glClear(GL_COLOR_BUFFER_BIT);

	int rx2 = rx*rx;
	int ry2 = ry*ry;

	float px =0;
	float py = 2*rx2*ry;

	float x = 0;
	float y = ry;

	float p = ry2 + rx2*(0.25 - ry);
	glBegin(GL_POINTS);
	glVertex2i((int)x,(int)y);

	while(px < py){
		x++;
		px+=2*ry2;
		if(p>0){
			y--;
			py -= 2*rx2;
			p = p + px - py + ry2;
		}else{
			p = p + px + ry2;
		}

		glVertex2i((int)x,(int)y);
		glVertex2i((int)x,-(int)y);
		glVertex2i(-(int)x,-(int)y);
		glVertex2i(-(int)x,(int)y);

	}

	while(y>0){
		y--;
		py -= 2*rx2;

		if(p>0){
			p = p - py + rx2;
		}else{
			x++;
			px += 2*ry2;
			p = p - py + px + rx2;
		}
		glVertex2i((int)x,(int)y);
		glVertex2i((int)x,-(int)y);
		glVertex2i(-(int)x,-(int)y);
		glVertex2i(-(int)x,(int)y);
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
