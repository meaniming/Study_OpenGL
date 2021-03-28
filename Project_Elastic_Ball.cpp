//미완성 코드, 작성 중
#include <gl/glut.h>
#include <GL/GL.h>
#include <GL/GLU.h>
#include <math.h>
#include <stdlib.h>

GLfloat Delta = 0.0;
GLfloat Radius = 0.3;
GLfloat Gravity = -9.8;
int Width, Height;
unsigned int KeyboardValue = 0;

void MyReshape(int width, int height) {
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void MyKeyboard(unsigned char KeyPressed, int x, int y) {
	switch (KeyPressed) {
	case 's':
		KeyboardValue = 1;
		break;
	case 'w':
		KeyboardValue = 0;
		break;
	}
}


void MyDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glColor4f(1.0, 1.0, 1.0, 1.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	GLfloat Translate_y = sin(Delta);
	GLfloat Scale_x = 1;
	GLfloat Scale_y = 1;


	glTranslatef(0.0, Translate_y, 0.0);
	if (Translate_y <= -.9)
	{
		Scale_y = .5;
	}
	else
	{
		Scale_x = 0.5;
		Scale_y = 1;
	}
	glScalef(Scale_x, Scale_y, 1.0);

	//키보드 입력 시 wire/solid 변하게 설정
	if (KeyboardValue == 0) {
		glutWireSphere(Radius, 30, 30);
	}
	else
		glutSolidSphere(Radius, 30, 30);

	glEnd();
	//glFlush();
	glutSwapBuffers();

}

void MyIdle() {
	Delta = Delta + 0.001;
	glutPostRedisplay();
}


int main(int argc, char** argv) {
	glutInit(&argc, argv);
	Width = 500; Height = 500;
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(Width, Height);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("OpenGL Sample Drawing");
	glutDisplayFunc(MyDisplay);
	glutReshapeFunc(MyReshape);
	glutIdleFunc(MyIdle);
	glutKeyboardFunc(MyKeyboard);
	glutMainLoop();
	return 0;
}
