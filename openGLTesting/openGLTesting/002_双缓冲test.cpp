#include <glut.h> 

static GLfloat spin = 0.0;  

void myDisplay02(void)  
  
{	
	glClear(GL_COLOR_BUFFER_BIT); 
	//glLoadIdentity();
	//glPushMatrix();
	glRotatef(30, 0.0, 0.0, 1.0);
	glColor3f(1.0, 1.0, 1.0);
	glRectf(-0.25, -0.25, 0.25, 0.25);
	//glPopMatrix();
	glutSwapBuffers();
    glFlush();  
}  

void spinDisplay(void)
{
	spin = spin + 2.0;
	if (spin > 360)
	{
		spin = spin - 360;
	}
	glutPostRedisplay();
}

void reShape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 0.5, 0.0, 0.5);
	//glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
	//glMatrixMode(GL_MODELVIEW);
	//glLoadIdentity();
}

void mouse02(int button, int state, int x, int y)
{
	switch (button)
	{
	case GLUT_LEFT_BUTTON:
		if (state == GLUT_DOWN)
			glutIdleFunc(spinDisplay);
			break;
	case GLUT_RIGHT_BUTTON:
		if (state == GLUT_DOWN)
			glutIdleFunc(nullptr);
			break;
	default:
		break;
	}
}

void init02(void)
{
	glClearColor(0, 0, 0, 0);
	glShadeModel(GL_FLAT);

	/*glLoadIdentity();
	glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);*/

}

int main02(int argc, char *argv[])  
  
{  
  
    glutInit(&argc, argv);  
  
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);  
  
    glutInitWindowPosition(500, 200);  
  
    glutInitWindowSize(800, 600);  
  
    glutCreateWindow("OpenGLË«»º³å³ÌÐò");  

	init02();
  
    glutDisplayFunc(myDisplay02);  

	glutReshapeFunc(reShape);

	//glutMouseFunc(mouse);
  
    glutMainLoop();  

     return 0;  
  
}  