#include<GL/glut.h>
#include<stdio.h>
#include <math.h>
#define PI 3.1415926535898
GLfloat escala = 1;
int i = 0;
void circulo (float dx, float dy)
{
    float ang, x, y;
    glBegin(GL_LINE_LOOP);
    for (i = 0; i < 360; i++)
    {
//angle = 2*PI*i/circle_points;
        ang = (i * PI) / 180.0;
        x = dx+ (cos(ang) * escala);
        y = dy + (sin(ang) * escala);
        glVertex2f(x, y);
    }
    glEnd();
}
void desenha(void)
{
    glClear( GL_COLOR_BUFFER_BIT );
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-6, 6, -6, 6);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glColor3f(1, 0, 0);
    glLineWidth(6);

    circulo (-2, 0);
    circulo (0, 0);
    circulo (2, 0);

    glFlush();
}
void listeningKey (unsigned char tecla,
                   GLint x, GLint y)
{
    switch(tecla)
    {
    case '+':
        escala=escala+0.25;
        break;
    case '-':
        escala=escala-0.25;
        break;
    }
    desenha();
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800,600);
    glutInitWindowPosition(300,100);
    glutCreateWindow("Ola Glut");
    glutKeyboardFunc(listeningKey);
    glutDisplayFunc(desenha);
    glClearColor( 0, 0, 1, 0);
    glutMainLoop();
    return 0;
}
