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
float direcaoy = 1.0f;

// Camera / Visão
float x = 0.0f; 
float z = 5.0f;
float y = 1.0f;
float angulo = 0.0f;

// Posicão do sol / luz
float lightx = 0.0f; 
float lighty = 3.0f;
float lightz = 0.5f;

void drawObject(){
	
	// Posicão Luz
	glPushMatrix();
	glColor3f(1.0f,1.0f,0.0f);
	glTranslatef(lightx, lighty, lightz);
	glutSolidSphere(0.1, 10, 10);
	glPopMatrix();
		
	// Hitbox inimigo
	
	//------------------------------------------------------
	
	// Perna direita
	glPushMatrix();
	glColor3f(1.0f, 0.0f, 0.0f);	
	glTranslatef(0.309f,0.21f,0.0f);
	glutSolidCube(0.2f);
	
	glPushMatrix();
	glColor3f(1.0f, 0.0f, 0.0f);	
	glTranslatef(0.0f,0.2f,0.0f);
	glutSolidCube(0.2);
	
	glPushMatrix();
	glColor3f(1.0f, 0.0f, 0.0f);	
	glTranslatef(0.0f,0.2f,0.0f);
	glutSolidCube(0.2);
	
	glPushMatrix();
	glColor3f(1.0f, 0.0f, 0.0f);	
	glTranslatef(0.0f,0.2f,0.0f);
	glutSolidCube(0.2);
	glPopMatrix();
	
	
	// Perna Equerda
	glPushMatrix();
	glColor3f(1.0f, 0.0f, 0.0f);	
	glTranslatef(-0.1f,0.21f,0.0f);
	glutSolidCube(0.2f);
	
	glPushMatrix();
	glColor3f(1.0f, 0.0f, 0.0f);	
	glTranslatef(0.0f,0.2f,0.0f);
	glutSolidCube(0.2);
	
	glPushMatrix();
	glColor3f(1.0f, 0.0f, 0.0f);	
	glTranslatef(0.0f,0.2f,0.0f);
	glutSolidCube(0.2);
	
	glPushMatrix();
	glColor3f(1.0f, 0.0f, 0.0f);	
	glTranslatef(0.0f,0.2f,0.0f);
	glutSolidCube(0.2);
	glPopMatrix();
	
	
	// Corpo
	glPushMatrix();
	glColor3f(1.0f, 0.0f, 0.0f);	
	glTranslatef(-0.05f,1.06f,0.0f);
	glutSolidCube(0.3f);
	
	glColor3f(1.0f, 0.0f, 0.0f);	
	glTranslatef(-0.0f,0.3f,0.0f);
	glutSolidCube(0.3f);
	
	glColor3f(1.0f, 0.0f, 0.0f);	
	glTranslatef(-0.0f,0.3f,0.0f);
	glutSolidCube(0.3f);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0f, 0.0f, 0.0f);	
	glTranslatef(0.25f,1.06f,0.0f);
	glutSolidCube(0.3f);
	
	glColor3f(1.0f, 0.0f, 0.0f);	
	glTranslatef(0.0f,0.3f,0.0f);
	glutSolidCube(0.3f);
	
	glColor3f(1.0f, 0.0f, 0.0f);	
	glTranslatef(0.0f,0.3f,0.0f);
	glutSolidCube(0.3f);
	glPopMatrix();
	
	
	// Braço
	glPushMatrix();
	glColor3f(1.0f, 0.0f, 0.0f);	
	glTranslatef(0.5f,1.70f,0.0f);
	glutSolidCube(0.2f);
	
	glColor3f(1.0f, 0.0f, 0.0f);	
	glTranslatef(0.2f,0.0f,0.0f);
	glutSolidCube(0.2f);
	
	glColor3f(1.0f, 0.0f, 0.0f);	
	glTranslatef(0.2f,0.0f,0.0f);
	glutSolidCube(0.2f);
	glPopMatrix();
	
	glPushMatrix();
	glColor3f(1.0f, 0.0f, 0.0f);	
	glTranslatef(-0.3f,1.70f,0.0f);
	glutSolidCube(0.2f);
	
	glColor3f(1.0f, 0.0f, 0.0f);	
	glTranslatef(-0.2f,0.0f,0.0f);
	glutSolidCube(0.2f);
	
	glColor3f(1.0f, 0.0f, 0.0f);	
	glTranslatef(-0.2f,0.0f,0.0f);
	glutSolidCube(0.2f);
  	glPopMatrix();
	
	// Cabeça
	glPushMatrix();
	glColor3f(1.0f, 0.0f, 0.0f);	
	glTranslatef(0.10f,2.0f,0.0f);
	glutSolidCube(0.35f);
	glPopMatrix();
	
}

void drawWeapon(){
	
	//Arma / Braço
	// glPushMatrix();
	// glColor3f(0.0f, 0.0f, 1.0f);
	// glTranslatef(x + direcaox ,0.8f, z + direcaoz + 0.4f);
	// glRotatef(angulo, x + direcaox, y, z);
	// glutWireCube(0.1f);
	// glPopMatrix();
	
}


void crosshair(){
		
	glPushMatrix();
	glTranslatef(0,1,2);
	glScalef(1,8,0);
	glutWireCube(0.01);
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(0,1.14,2);
	glScalef(1,8,0);
	glutWireCube(0.01);
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(0.08,1.075,2);
	glRotatef(90, 0, 0, 1);
	glScalef(1,8,0);
	glutWireCube(0.01);
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(-0.08,1.075,2);
	glRotatef(90, 0, 0, 1);
	glScalef(1,8,0);
	glutWireCube(0.01);
	glPopMatrix();
		
}

float walkMoviment(){
	
	if (direcaoy == 1.0f){
		direcaoy += 0.05f;
	}
	if (direcaoy == 1.5f){
		direcaoy -= 0.05f;
	}
	
	return direcaoy;
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
	gluLookAt( x, y, z,
	   	   	   x+direcaox, direcaoy, z+direcaoz,
			   0.0f, 5.0f, 0.0f);

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
		direcaoy += 0.01f;
		break;
	
	case GLUT_KEY_DOWN :
		direcaoy -= 0.01f;
		break;
	}
}

void keyboard(unsigned char key, int x, int y) {

	switch (key) {
	case 27:
		exit(0);
		break;
	
	case 119:
		x += direcaox * 0.1f;
		z += direcaoz * 0.1f;
		break;
	
	case 115:
		x -= direcaox * 0.1f;
		z -= direcaoz * 0.1f;
		break;
	
	default:
		break;
	}
	glutPostRedisplay();
}

void lightining (void){
	GLfloat luzAmbiente[4]={0.2,0.2,0.2,1.0};
	GLfloat luzDifusa[4]={0.7,0.7,0.7,1.0};		 // "cor"
	GLfloat luzEspecular[4]={1.0, 1.0, 1.0, 1.0};// "brilho"
	GLfloat posicaoLuz[4]={0.0, 10.0, 05.0, 1.0};

	// Capacidade de brilho do material
	GLfloat especularidade[4]={1.0,1.0,1.0,1.0};
	GLint especMaterial = 60;

 	// Especifica que a cor de fundo da janela ser preta
 	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	// Habilita o modelo de colorização de Gouraud
	glShadeModel(GL_SMOOTH);

	// Define o grau de especularidade do material
	glMaterialfv(GL_FRONT,GL_SPECULAR, especularidade);
	// Define a concentração do brilho
	glMateriali(GL_FRONT,GL_SHININESS,especMaterial);

	// Ativa o uso da luz ambiente
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);

	// Define os parâmetros da luz de número 0
	glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa );
	glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular );
	glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz );

	// Habilita a definição da cor do material a partir da cor corrente
	glEnable(GL_COLOR_MATERIAL);
	//Habilita o uso de iluminação
	glEnable(GL_LIGHTING);
	// Habilita a luz de número 0
	glEnable(GL_LIGHT0);

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
	glutKeyboardFunc(keyboard);
	glEnable(GL_DEPTH_TEST);
	lightining();
	glutMainLoop();

	return 1;
}

