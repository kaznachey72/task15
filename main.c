#include<GL/glut.h>
#include <string.h>

/*******************
     7--------6
    /|       /|
   / |      / |
  3--------2  |
  |  4-----|--5
  |  /     |  /
  | /      | /
  |/       |/
  0--------1
********************/

GLfloat vertex[] = { 
   -1, -1,  1,  // 0	
    1, -1,  1, 	// 1
    1,  1,  1, 	// 2
   -1,  1,  1, 	// 3
   -1, -1, -1, 	// 4
    1, -1, -1, 	// 5
    1,  1, -1, 	// 6
   -1,  1, -1,  // 7
};
GLfloat colors[] = {
    1, 0, 0,    // 0
    1, 1, 0,    // 1
    0, 0, 1,    // 2
    0, 1, 0,    // 3
    0, 0, 1,    // 4
    0, 1, 0,    // 5
    1, 0, 0,    // 6 
    1, 1, 0,    // 7
};
GLubyte indices[] = {
    0, 1, 2, 3,  // front    
    4, 0, 3, 7,  // left
    1, 5, 6, 2,  // right
    3, 2, 6, 7,  // up
    4, 5, 1, 0,  // down
    7, 6, 5, 4,  // back
};
GLfloat angles[]= { 
    0, 0, 0
};


void rotate()
{
    for (GLint axis = 0; axis < 3; ++axis) {
	    angles[axis] += 0.5;
	    if (angles[axis] > 360) { 
	        angles[axis] -= 360;
        }
    }
	glutPostRedisplay(); 
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glRotatef(angles[0], 1, 0, 0);
	glRotatef(angles[1], 0, 1, 0);
	glRotatef(angles[2], 0, 0, 1);
	glDrawElements(GL_QUADS, 24, GL_UNSIGNED_BYTE, indices);
	glutSwapBuffers(); 
}


void redraw(int width, int height)
{
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (width <= height) { 
	    glOrtho (
            -2, 
             2, 
            -2 * (GLfloat)height / (GLfloat)width, 
             2 * (GLfloat)height / (GLfloat)width, 
            -10, 
             10
        );
	}
    else {
	    glOrtho(
            -2 * (GLfloat)width / (GLfloat)height, 
             2 * (GLfloat)width / (GLfloat)height, 
            -2, 
             2, 
            -10, 
             10
        );
    }
	glMatrixMode(GL_MODELVIEW);
}

void key_press(unsigned char key, int x, int y)
{
    (void)x;
    (void)y;

	if (key == 27) {
	    exit(0);
    }
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 800);
	glutCreateWindow("Task 15");
	
    glutReshapeFunc(redraw); 
	glutDisplayFunc(display); 
	glutIdleFunc(rotate);
    glutKeyboardFunc(key_press);
	
    glEnable(GL_DEPTH_TEST); 
    glEnable(GL_TEXTURE_2D);

    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, vertex);

    glEnableClientState(GL_COLOR_ARRAY);
    glColorPointer(3, GL_FLOAT, 0, colors);

	glutMainLoop();
}
