#include <glut.h>  

void myDisplay01(void)  
  
{	
	GLfloat		rtri = 0.1f;						// ���������εĽǶ�
	GLfloat		rquad = 0.1f;						// �����ı��εĽǶ�
  
    glClear(GL_COLOR_BUFFER_BIT); 
	glLoadIdentity();
	glTranslatef(-0.5f,0.0f,0.0f); 
  
     //��һ��ָ���ľ���
	 //glRectf(-0.5f, -0.5f, 0.5f, 0.5f);  
	glRotatef(rtri,0.0f,0.2f,0.0f);				// ��Y����ת������

	glBegin(GL_TRIANGLES);
		glColor3f(1.0f,0.0f,0.0f);				// ���õ�ǰɫΪ��ɫ
		glVertex3f( 0.0f, 0.5f, 0.0f);				// �϶���

		glColor3f(0.0f,1.0f,0.0f);				// ���õ�ǰɫΪ��ɫ
		glVertex3f(-0.5f,-0.5f, 0.0f);				// ����

		glColor3f(0.0f,0.0f,1.0f);				// ���õ�ǰɫΪ��ɫ
		glVertex3f( 0.5f,-0.5f, 0.0f);				// ����
	glEnd();
	glLoadIdentity();					// ����ģ�͹۲����
	glTranslatef(1.0f,0.0f,0.0f);					// ����3��λ
	
	glRotatef(rquad,1.0f,0.0f,0.0f);			//  ��X����ת�ı���
	glColor3f(0.5f,0.5f,1.0f);					// һ���Խ���ǰɫ����Ϊ��ɫ
	
	glBegin(GL_QUADS);						// ����������

		glVertex3f(-0.5f, 0.5f, 0.0f);				// ����

		glVertex3f( 0.5f, 0.5f, 0.0f);				// ����

		glVertex3f( 0.5f,-0.5f, 0.0f);				// ����

		glVertex3f(-0.5f,-0.5f, 0.0f);				// ����

	glEnd();							// �����λ��ƽ���
	//
	//rtri += 0.2f;						// ���������ε���ת����
	//rquad -= 0.15f;						// �����ı��ε���ת����

    glFlush();  
}  

void init01(void)
{
	glClearColor(255, 255, 255, 255);
	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();
	glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);

}

int main01(int argc, char *argv[])  
  
{  
  
    glutInit(&argc, argv);  
  
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);  
  
    glutInitWindowPosition(500, 200);  
  
    glutInitWindowSize(800, 600);  
  
    glutCreateWindow("��һ��OpenGL����");  

	init01();
  
    glutDisplayFunc(&myDisplay01);  
  
    glutMainLoop();  

     return 0;  
  
}  