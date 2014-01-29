#include "stdafx.h"

char* OGLRenderer::debugClassName = "OGLRenderer";

OGLRenderer::OGLRenderer()
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, "empty constructor");
#endif
}

OGLRenderer::OGLRenderer(int argc, char **argv)
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, "constructor");
#endif

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	glutInitWindowPosition(0,0);
	glutCreateWindow(WINDOW_NAME);
	glutReshapeFunc(Reshape);
}

OGLRenderer::~OGLRenderer()
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, "descructor");
#endif
}

void OGLRenderer::SetIdleFunc(void idleFunc())
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, "SetIdleFunc");
#endif

	glutIdleFunc(idleFunc);
}

void OGLRenderer::SetDisplayFunc(void updateFunc())
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, "SetDisplayFunc");
#endif

	glutDisplayFunc(updateFunc);
}

void OGLRenderer::SetKeyboardDownFunc(void keyboardDownFunc(unsigned char key, int x, int y))
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, "SetKeyboardDownFunc");
#endif

	glutKeyboardFunc(keyboardDownFunc);
}

void OGLRenderer::SetKeyboardUpFunc(void keyboardUpFunc(unsigned char key, int x, int y))
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, "SetKeyboardUpFunc");
#endif

	glutKeyboardUpFunc(keyboardUpFunc);
}

void OGLRenderer::SetMouseReadFunc(void mouseReadFunc(int button, int state, int x, int y))
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, "SetMouseReadFunc");
#endif

	glutMouseFunc(mouseReadFunc);
}

void OGLRenderer::SetMouseTrackFunc(void mouseTrackFunc(int x, int y))
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, "SetMouseTrackFunc");
#endif

	glutMotionFunc(mouseTrackFunc);
}

void OGLRenderer::Init()
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, "Init");
#endif

	glViewport(0,0,SCREEN_WIDTH,SCREEN_HEIGHT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f,(GLfloat)SCREEN_WIDTH/(GLfloat)SCREEN_HEIGHT,0.1f,10000.0f);

	glMatrixMode(GL_MODELVIEW);

	glClearColor(0.0, 0.0, 0.0, 0.0);

	//Lights initialization and activation
	//glLightfv (GL_LIGHT1, GL_AMBIENT, light_ambient);
	//glLightfv (GL_LIGHT1, GL_DIFFUSE, light_diffuse);
	//glLightfv (GL_LIGHT1, GL_DIFFUSE, light_specular);
	//glLightfv (GL_LIGHT1, GL_POSITION, light_position);    
	//glEnable (GL_LIGHT1);
	//glEnable (GL_LIGHTING);

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

	glEnable (GL_LIGHTING);
}

void OGLRenderer::PrepareRendering()
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, "PrepareRendering");
#endif
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60,(GLfloat)SCREEN_WIDTH/(GLfloat)SCREEN_HEIGHT,0.1f,1000);

	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glClearColor(0.0, 0.0, 0.0, 1.0);

	glPushMatrix();

	glColor3f(0.0,0.0,0.0);

	//gluLookAt(0, 0, 0, 0, 0, 0, 0, 1, 0);
}

void OGLRenderer::FinishRendering()
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, "FinishRendering");
#endif

	glPopMatrix();

	glutSwapBuffers();
}

void OGLRenderer::Reshape(int w, int h)
{
#if defined(DEBUG_OUTPUT)
	debugPrint(debugClassName, "Reshape");
#endif

	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//glFrustum(-1.0,1.0,-1.0,1.0,1.5,20.0); 

	glMatrixMode(GL_MODELVIEW);
}