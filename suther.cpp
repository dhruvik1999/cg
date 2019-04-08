#include<stdio.h> 
#include<GL/glut.h> 
#include<math.h> 
#include<bits/stdc++.h>
#define pi 3.142857 



// function to initialize 
using namespace std;


int xmax=300,xmin=0,ymax=300,ymin=0;

int getbin(int x,int y){
	int ans = 0;
		if(y > ymax){
			ans = ans | 8;
		}

		if(y < ymin){
			ans = ans | 4;
		}

		if(x > xmax){
			ans = ans | 2;
		}

		if(x < xmin){
			ans = ans | 1;
		}

	return ans;	
}
int x1=0,yy1=0,x2=300,y2=400;
void display(){
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_LINE_LOOP);
		glVertex2i(xmin,ymin);
		glVertex2i(xmax,ymin);
		glVertex2i(xmax,ymax);
		glVertex2i(ymin,ymax);
	glEnd();


	glBegin(GL_LINES);
		bool accept = false;
		while(true){
			int code1 = getbin(x1,yy1);
			int code2 = getbin(x2,y2);
			
			

			if(code1==0 && code2==0){
				accept = true;
				break;
			}else if(code1 & code2){
				accept = false;
			}else{
				int code;
				int x,y;

				if(code1!=0){
					code = code1;
				}else{
					code = code2;
				}

				if(code & 8){
					x = x1 + (ymax-yy1) * (x2-x1)/(y2-yy1);
					y = ymax;
				}

				if(code & 4){
					x = x1 + (ymin-yy1) * (x2-x1)/(y2-yy1);
					y = ymin;
				}

				if(code & 2){
					x=xmax;
					y = yy1 + (xmax-x1)*(y2-yy1)/(x2-x1);
				}

				if(code & 1){
					x=xmin;
					y = yy1 + (xmin-x1)*(y2-yy1)/(x2-x1);
				}

				if(code == code1){
					x1=x;
					yy1=y;
				}else{
					x2=x;
					y2=y;
				}

			}
		}

		if(accept){
			glVertex2i(x1,yy1);
			glVertex2i(x2,y2);
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
