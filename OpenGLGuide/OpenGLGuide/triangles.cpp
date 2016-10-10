#include <iostream>

using namespace std;

#include "vgl.h"
#include "LoadShaders.h"
#include <vld.h>

using namespace std;

enum VAO_IDS {   Triangles, NumVAOs   };

enum Buffer_IDs{   ArrayBuffer, NumBuffers    };

enum Attrib_IDs {	vPosition = 0    };

GLuint VAOS[NumVAOs];
GLuint Buffers[NumBuffers]; 

const GLuint NumVertices = 6;

//----------------------------------
// init 
//

void init(void)
{
	glGenVertexArrays(NumVAOs, VAOS);
	glBindVertexArray(VAOS[Triangles]);

	GLfloat vertrtices[NumVertices][2] = {
		{-0.90, -0.90},
		{0.85, -0.90},
		{-0.90, 0.85},
		
		{0.90, -0.85},
		{0.90, 0.90},
		{-0.85, 0.90},
	};

	glGenBuffers(NumBuffers, Buffers);
	glBindBuffer(GL_ARRAY_BUFFER, Buffers[ArrayBuffer]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertrtices), vertrtices, GL_STATIC_DRAW);

	ShaderInfo shaders[] = {
		{GL_VERTEX_SHADER, "triangles.vert"},
		{GL_FRAGMENT_SHADER, "triangles.frga"},
		{GL_NONE, NULL}
	};
	GLuint program = LoadShaders(shaders);
	glUseProgram(program);

	glVertexAttribPointer(vPosition, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
	glEnableVertexAttribArray(vPosition);


	int vec = (int)malloc(sizeof(4));
}

//-----------------------------------------------------------------
//  display
//

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	glBindVertexArray(VAOS[Triangles]);
	glDrawArrays(GL_TRIANGLES, 0, NumVertices);

	glFlush();
}

int main(int argc, char** argv)
{
	glewExperimental = GL_TRUE;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA);
	glutInitWindowSize(512, 512);
	glutInitContextVersion(4, 3);
	glutInitContextProfile(GLUT_CORE_PROFILE);
	glutCreateWindow(argv[0]);


	if(glewInit())
	{
		cerr << "Unable to initialize GLEW .. exiting" << endl;
		exit(EXIT_FAILURE);
	}

	init();

	glutDisplayFunc(display);

	glutMainLoop();
}

 