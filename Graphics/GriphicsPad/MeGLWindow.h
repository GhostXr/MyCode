#ifndef ME_GL_WINDOW
#define ME_GL_WINDOW

#include <QtOpenGL\qglwidget>

class MeGLWindow : public  QGLWidget
{
public:
protected:
	void initializeGL();
	void paintGL();
};

#endif
