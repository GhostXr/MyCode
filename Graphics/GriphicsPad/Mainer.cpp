#include <Qt\qapplication.h>
#include <MeGLWindow.h>

int main(int argc, char* argv[])
{
	QApplication app(argc, argv);
	MeGLWindow glwidow;
	glwidow.show();
	return app.exec();
}