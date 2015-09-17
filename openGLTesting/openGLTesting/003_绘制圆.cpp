#include <glut.h>  
#include "math.h"

#define PI 3.1415926

void myDisplay03(void)  
  
{	
	GLint circle_points = 1000; 

	glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT); 
	glLoadIdentity();
	
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_TRIANGLES);
	for (int i = 1; i < circle_points; i ++)
	{
		GLfloat angle = 2 * PI * i / circle_points * 30.0;
		glVertex2d(cos(angle), sin(angle));
	}
	glEnd();
	

    glFlush();  
}  

void init03(void)
{
	glClearColor(255, 255, 255, 255);
	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();
	gluOrtho2D(0.0, 1.0, 0.0, 1.0);

}

int main03(int argc, char *argv[])  
  
{  
  
    glutInit(&argc, argv);  
  
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);  
  
    glutInitWindowPosition(500, 200);  
  
    glutInitWindowSize(800, 600);  
  
    glutCreateWindow("第一个OpenGL程序");  

	init03();
  
    glutDisplayFunc(&myDisplay03);  
  
    glutMainLoop();  

     return 0;  
  
}  