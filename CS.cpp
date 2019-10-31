#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include "math.h"

// Dire��o da camera
float direcaox = 0.0f;
float direcaoz = -1.0f;

// Camera
float x = 0.0f;
float z = 5.0f;
float angulo = 0.0f;

void drawObject(){

	glColor3f(1.0f, 1.0f, 1.0f);
	
	//Corpo
	glColor3f(0.0f, 0.0f, 1.0f);	
	glTranslatef(0.0f,0.75f,0.0f);
	glutWireCube(0.3);

}

void changeSize(int w, int h){

	if (h == 0)
		h = 1;
	float ratio = w * 1.0 / h;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, w, h);
	gluPerspective(45.0f, ratio, 0.1f, 100.0f);
	glMatrixMode(GL_MODELVIEW);
}

void renderScene(void){
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();
	
// Camera
	gluLookAt( x, 1.0f, z,
			   x + direcaox, 1.0f, z + direcaoz,
			   0.0f, 1.0f, 0.0f);

// Draw ground
	glColor3f(0.9f, 0.9f, 0.9f);
	glBegin(GL_QUADS);
	glVertex3f(-100.0f, 0.0f, -100.0f);
	glVertex3f(-100.0f, 0.0f, 100.0f);
	glVertex3f( 100.0f, 0.0f, 100.0f);
	glVertex3f( 100.0f, 0.0f, -100.0f);
	glEnd();

// Draw 36 SnowMen
	// for(int i = -3; i < 3; i++)
	// 	for(int j = -3; j < 3; j++)
	// 	{
	 		glPushMatrix();
	// 		glTranslatef(i * 10.0, 0, j * 10.0);
	 		drawObject();
	 		glPopMatrix();
	// 	}

	glutSwapBuffers();
}


void processSpecialKeys(int key, int xx, int yy){

	switch (key){
	
	case GLUT_KEY_LEFT :
		angulo -= 0.03f;
		direcaox = sin(angulo);
		direcaoz = -cos(angulo);
		break;

	case GLUT_KEY_RIGHT :
		angulo += 0.03f;
		direcaox = sin(angulo);
		direcaoz = -cos(angulo);
		break;

	case GLUT_KEY_UP :
		x += direcaox * 0.1f;
		z += direcaoz * 0.1f;
		break;

	case GLUT_KEY_DOWN :
		x -= direcaox * 0.1f;
		z -= direcaoz * 0.1f;
		break;
	}
}

int main(int argc, char **argv)
{

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Counter-Strike GL");
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
	glutIdleFunc(renderScene);
	glutSpecialFunc(processSpecialKeys);
	glEnable(GL_DEPTH_TEST);
	glutMainLoop();

	return 1;
}

