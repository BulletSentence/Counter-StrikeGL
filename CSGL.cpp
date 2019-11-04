#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include "math.h"

// Direção da camera
float direcaox = 0.0f;
float direcaoz = -1.0f;	

// Camera / Visão
float x = 0.0f; 
float z = 5.0f;
float angulo = 0.0f;

void drawObject(){
		
	// Hitbox inimigo
	
	//------------------------------------------------------
	
	// Perna direita
	glPushMatrix();
	glColor3f(1.0f, 0.0f, 0.0f);	
	glTranslatef(0.3f,0.2f,0.0f);
	glutWireCube(0.2f);
	
	glPushMatrix();
	glColor3f(1.0f, 0.0f, 0.0f);	
	glTranslatef(0.0f,0.2f,0.0f);
	glutWireCube(0.2);
	
	glPushMatrix();
	glColor3f(1.0f, 0.0f, 0.0f);	
	glTranslatef(0.0f,0.2f,0.0f);
	glutWireCube(0.2);
	
	glPushMatrix();
	glColor3f(1.0f, 0.0f, 0.0f);	
	glTranslatef(0.0f,0.2f,0.0f);
	glutWireCube(0.2);
	glPopMatrix();
	
	
	// Perna Equerda
	glPushMatrix();
	glColor3f(1.0f, 0.0f, 0.0f);	
	glTranslatef(-0.1f,0.2f,0.0f);
	glutWireCube(0.2f);
	
	glPushMatrix();
	glColor3f(1.0f, 0.0f, 0.0f);	
	glTranslatef(0.0f,0.2f,0.0f);
	glutWireCube(0.2);
	
	glPushMatrix();
	glColor3f(1.0f, 0.0f, 0.0f);	
	glTranslatef(0.0f,0.2f,0.0f);
	glutWireCube(0.2);
	
	glPushMatrix();
	glColor3f(1.0f, 0.0f, 0.0f);	
	glTranslatef(0.0f,0.2f,0.0f);
	glutWireCube(0.2);
	glPopMatrix();
	
	
	// Corpo
	
	// glPushMatrix();
	// glColor3f(1.0f, 0.0f, 0.0f);	
	// glTranslatef(0.0f,0.45f,0.0f);
	// glutWireSphere(0.2,20,10);
	// glPopMatrix();
	
}

void drawWeapon(){
	
	// Arma / Braço
	glPushMatrix();
	glColor3f(0.0f, 0.0f, 1.0f);
	glTranslatef(x + direcaox ,0.8f, z + direcaoz + 0.4f);
	glRotatef(0.03f, direcaox, 0.0f, direcaoz);
	glutWireCube(0.1f);
	glPopMatrix();
	
}

void walkMoviment(){
	
	
	
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
	glClearColor(0.2f, 0.6f, 0.9f, 1.0f);
	glLoadIdentity();
	
// Camera
	gluLookAt( x, 1.0f, z,
	   	   	   x + direcaox, 1.0f, z + direcaoz,
			   0.0f, 1.0f, 0.0f);

// Terreno
	glColor3f(0.2f, 0.8f, 0.2f);
	glBegin(GL_QUADS);
	glVertex3f(-100.0f, 0.0f, -100.0f);
	glVertex3f(-100.0f, 0.0f, 100.0f);
	glVertex3f( 100.0f, 0.0f, 100.0f);
	glVertex3f( 100.0f, 0.0f, -100.0f);
	glEnd();

	glPushMatrix();
	drawObject();
    drawWeapon();
	glPopMatrix();

	glutSwapBuffers();
}


void SpecialKeys(int key, int xx, int yy){

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
	glutSpecialFunc(SpecialKeys);
	glEnable(GL_DEPTH_TEST);
	glutMainLoop();

	return 1;
}

