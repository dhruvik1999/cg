#include <windows.h>
#include <GL/glut.h>
#include<stdlib.h>
#include<stdio.h>

float rx, ry, xc, yc;
void init()
{
    glClearColor(0.0,1.0,1.0,0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,0.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-200,200,-200,200);

}
void display()
{
    glBegin(GL_POINTS);
    glVertex2i(0+xc, ry+yc);
    glVertex2i(0+xc, ry-yc);
    glEnd();
    float x=0, y=ry, p1 = ry*ry+0.25*rx*rx-rx*rx*ry, dx, dy;
    dx=2*ry*ry*x, dy=2*rx*rx*y;
    float rysq=2*ry*ry, rxsq=2*rx*rx;
    while(dx < dy)
    {
        x++;
        if(p1 < 0)
        {
            dx = rysq*x;
            dy = rxsq*y;
            p1 += dx + rysq/2;
        }
        else{
            y--;
            dx = rysq*x;
            dy = rxsq*y;
            p1 += dx+rysq/2-dy;
        }
        glBegin(GL_POINTS);
        glVertex2i(x+xc, y+yc);
        glVertex2i(-x+xc, y+yc);
        glVertex2i(-x+xc, -y+yc);
        glVertex2i(x+xc, -y+yc);
        glEnd();

    }
    float p2=((ry * ry) * ((x + 0.5) * (x + 0.5))) +
         ((rx * rx) * ((y - 1) * (y - 1))) -
          (rx * rx * ry * ry);
    while(y>=0)
    {
        y--;
        if(p2>0)
        {
            p2+=rxsq/2-rxsq*y;
        }
        else{
            x++;
            p2+=rysq*x-rxsq*y+rxsq/2;
        }
        glBegin(GL_POINTS);
        glVertex2i(x+xc, y+yc);
        glVertex2i(-x+xc, y+yc);
        glVertex2i(-x+xc, -y+yc);
        glVertex2i(x+xc, -y+yc);
        glEnd();

    }
    glFlush();
}


int main(int argc,char**argv)
{

    printf("Enter the value of x : ");
    scanf("%f",&xc);
    printf("Enter the value of y : ");
    scanf("%f",&yc);
    printf("Enter the value of rx : ");
    scanf("%f",&rx);
    printf("Enter the value of ry : ");
    scanf("%f",&ry);
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (500, 500);
    glutInitWindowPosition (200,100);
    glutCreateWindow ("Mid-Point Circle Algo");
    init();
    glutDisplayFunc(display);
   glutMainLoop();

    return 0;
}