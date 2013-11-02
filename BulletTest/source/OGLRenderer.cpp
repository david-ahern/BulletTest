#include "stdafx.h"

char* OGLRenderer::debugClassName = "OGLRenderer";

OGLRenderer::OGLRenderer()
{
	debugPrint(debugClassName, "empty constructor");
}

OGLRenderer::OGLRenderer(int argc, char **argv)
{
	debugPrint(debugClassName, "constructor");

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	glutInitWindowPosition(0,0);
	glutCreateWindow(WINDOW_NAME);
	glutReshapeFunc(Reshape);
}

OGLRenderer::~OGLRenderer()
{
	debugPrint(debugClassName, "descructor");
}

void OGLRenderer::SetIdleFunc(void idleFunc())
{
	debugPrint(debugClassName, "SetIdleFunc");

	glutIdleFunc(idleFunc);
}

void OGLRenderer::SetDisplayFunc(void updateFunc())
{
	debugPrint(debugClassName, "SetDisplayFunc");

	glutDisplayFunc(updateFunc);
}

void OGLRenderer::SetKeyboardReadFunc(void keyboardReadFunc(unsigned char key, int x, int y))
{
	debugPrint(debugClassName, "SetKeyboardReadFunc");

	glutKeyboardFunc(keyboardReadFunc);
}

void OGLRenderer::SetMouseReadFunc(void mouseReadFunc(int button, int state, int x, int y))
{
	debugPrint(debugClassName, "SetMouseReadFunc");

	glutMouseFunc(mouseReadFunc);
}

void OGLRenderer::SetMouseTrackFunc(void mouseTrackFunc(int x, int y))
{
	debugPrint(debugClassName, "SetMouseTrackFunc");

	glutMotionFunc(mouseTrackFunc);
}

void OGLRenderer::Init()
{
	debugPrint(debugClassName, "Init");
	glViewport(0,0,SCREEN_WIDTH,SCREEN_HEIGHT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f,(GLfloat)SCREEN_WIDTH/(GLfloat)SCREEN_HEIGHT,0.1f,10000.0f);

	glMatrixMode(GL_MODELVIEW);

	glClearColor(0.0, 0.0, 0.0, 0.0);

	//Lights initialization and activation
	glLightfv (GL_LIGHT1, GL_AMBIENT, light_ambient);
	glLightfv (GL_LIGHT1, GL_DIFFUSE, light_diffuse);
	glLightfv (GL_LIGHT1, GL_DIFFUSE, light_specular);
	glLightfv (GL_LIGHT1, GL_POSITION, light_position);    
	glEnable (GL_LIGHT1);
	glEnable (GL_LIGHTING);

	////* Materials initialization and activation*/
	glMaterialfv (GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv (GL_FRONT, GL_DIFFUSE, mat_specular);
	glMaterialfv (GL_FRONT, GL_POSITION, mat_shininess);
	GLfloat c[] = { 1, 0, 0, 0.0f };
	glMaterialfv (GL_FRONT, GL_AMBIENT, c);

	//Other initializations
	glShadeModel(GL_SMOOTH); 
	glHint (GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	glPolygonMode (GL_FRONT_AND_BACK, GL_FILL);
	//glEnable(GL_CULL_FACE); 

	glutInitDisplayMode(GLUT_DEPTH);
 	glEnable(GL_DEPTH_TEST);
}

void OGLRenderer::PrepareRendering()
{
	debugPrint(debugClassName, "PrepareRendering");
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60,(GLfloat)SCREEN_WIDTH/(GLfloat)SCREEN_HEIGHT,0.1f,1000);

	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glColor3f(0.0,1.0,0.0);

	glPushMatrix();
}

void OGLRenderer::FinishRendering()
{
	debugPrint(debugClassName, "FinishRendering");

	glPopMatrix();

	glutSwapBuffers();
}

void OGLRenderer::Reshape(int w, int h)
{
	debugPrint(debugClassName, "Reshape");

	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//glFrustum(-1.0,1.0,-1.0,1.0,1.5,20.0); 

	glMatrixMode(GL_MODELVIEW);
}