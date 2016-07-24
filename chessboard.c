#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>


int color = 0;
int width = 800;
int hight = 800;

void init()
{   glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(4.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, width, 0, hight);
}

void drawSquare(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4){

    if (color == 0)
    {
        glColor3f(1, 1, 1);
        color = 1;
    }

    else
    {
        glColor3f(0, 0, 0);
        color = 0;
    }

    // Draw Square
    glBegin(GL_QUADS);
    glVertex2i(x1, y1);
    glVertex2i(x2, y2);
    glVertex2i(x3, y3);
    glVertex2i(x4, y4);
    glEnd();
}
void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);
    int x, y;
    int squareWidth = 100;
    int squareHight = 100;
    for (x = 0; x <= width; x += squareWidth)
    {
        for (y = 0; y <= hight; y += squareHight)
        {
            drawSquare(x, y + squareHight, x + squareWidth, y + squareHight, x + squareWidth, y, x, y);
        }
    }
    glFlush ();
}

int main(int agrc, char ** argv)
{
    glutInit(&agrc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Chess Board");
    init();
    glutDisplayFunc(myDisplay);
    glutMainLoop();
}
