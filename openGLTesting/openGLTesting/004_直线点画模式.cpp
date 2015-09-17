#include <glut.h>  
#include "math.h"

void drowOneLine(GLdouble x1, GLdouble y1, GLdouble x2, GLdouble y2)
{
	glBegin(GL_LINE);
		glVertex2f((x1), (y1)); 
		glVertex2f((x2), (y2)); 
	glEnd();
}

void myDisplay04(void)  
{	
	//glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT); 
	glLoadIdentity();
	
	glEnable(GL_LINE_STIPPLE);
	glColor3f(1.0, 1.0, 1.0);
	
	glLineStipple(2, 0x0101);
	drowOneLine(50.0, 125.0, 150.0, 125.0);
	glLineStipple(2, 0x00FF);
	drowOneLine(150.0, 125.0, 125.0, 125.0);
	glLineStipple(2, 0x1c47);
	drowOneLine(250.0, 125.0, 350.0, 125.0);


	
	glDisable(GL_LINE_STIPPLE);
	

    glFlush();  
}  

void reshape(int width, int height)
{
	glViewport(0.0, (GLsizei) width, 0.0, (GLsizei) height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, (GLdouble) width, 0.0, (GLdouble) height);
}

void init04(void)
{
	glClearColor(0, 0, 0, 0);
	/*glMatrixMode(GL_PROJECTION);

	glLoadIdentity();
	gluOrtho2D(0.0, 1.0, 0.0, 1.0);*/
	glShadeModel(GL_FLAT);

}

int main(int argc, char *argv[])  
  
{  
  
    glutInit(&argc, argv);  
  
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);  
  
    glutInitWindowPosition(500, 200);  
  
    glutInitWindowSize(800, 600);  
  
    glutCreateWindow("第一个OpenGL程序");  

	init04();
  
    glutDisplayFunc(&myDisplay04);  

	glutReshapeFunc(reshape);
  
    glutMainLoop();  

     return 0;  
  
}  