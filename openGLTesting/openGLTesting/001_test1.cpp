#include <glut.h>  

void myDisplay01(void)  
  
{	
	GLfloat		rtri = 0.1f;						// 用于三角形的角度
	GLfloat		rquad = 0.1f;						// 用于四边形的角度
  
    glClear(GL_COLOR_BUFFER_BIT); 
	glLoadIdentity();
	glTranslatef(-0.5f,0.0f,0.0f); 
  
     //画一个指定的矩形
	 //glRectf(-0.5f, -0.5f, 0.5f, 0.5f);  
	glRotatef(rtri,0.0f,0.2f,0.0f);				// 绕Y轴旋转三角形

	glBegin(GL_TRIANGLES);
		glColor3f(1.0f,0.0f,0.0f);				// 设置当前色为红色
		glVertex3f( 0.0f, 0.5f, 0.0f);				// 上顶点

		glColor3f(0.0f,1.0f,0.0f);				// 设置当前色为绿色
		glVertex3f(-0.5f,-0.5f, 0.0f);				// 左下

		glColor3f(0.0f,0.0f,1.0f);				// 设置当前色为蓝色
		glVertex3f( 0.5f,-0.5f, 0.0f);				// 右下
	glEnd();
	glLoadIdentity();					// 重置模型观察矩阵
	glTranslatef(1.0f,0.0f,0.0f);					// 右移3单位
	
	glRotatef(rquad,1.0f,0.0f,0.0f);			//  绕X轴旋转四边形
	glColor3f(0.5f,0.5f,1.0f);					// 一次性将当前色设置为蓝色
	
	glBegin(GL_QUADS);						// 绘制正方形

		glVertex3f(-0.5f, 0.5f, 0.0f);				// 左上

		glVertex3f( 0.5f, 0.5f, 0.0f);				// 右上

		glVertex3f( 0.5f,-0.5f, 0.0f);				// 左下

		glVertex3f(-0.5f,-0.5f, 0.0f);				// 右下

	glEnd();							// 正方形绘制结束
	//
	//rtri += 0.2f;						// 增加三角形的旋转变量
	//rquad -= 0.15f;						// 减少四边形的旋转变量

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
  
    glutCreateWindow("第一个OpenGL程序");  

	init01();
  
    glutDisplayFunc(&myDisplay01);  
  
    glutMainLoop();  

     return 0;  
  
}  