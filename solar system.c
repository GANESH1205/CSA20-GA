#include<GL/glut.h>
static bool spinning = true;
static const int FPS = 60;
static GLfloat currentAngleOfRotation = 0.0;
void reshape(GLint w, GLint h) 
{
glViewport(0, 0, w, h);
GLfloat aspect = (GLfloat)w /(GLfloat)h;
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
if (w &lt;= h) 
{
glOrtho(-50.0, 50.0, -50.0/aspect, 50.0/aspect, -1.0, 1.0);
} else 
{
glOrtho(-50.0*aspect, 50.0*aspect, -50.0, 50.0, -1.0, 1.0);
}
}
void display() 
{
glClear(GL_COLOR_BUFFER_BIT);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
glRotatef(currentAngleOfRotation, 0.0, 0.0, 1.0);
glRectf(-25.0, -25.0, 25.0, 25.0);
glFlush();
glutSwapBuffers();
}
void timer(int v) {
if (spinning) {
currentAngleOfRotation += 1.0;
if (currentAngleOfRotation &gt; 360.0) {
currentAngleOfRotation -= 360.0;
}
glutPostRedisplay();
}
glutTimerFunc(1000/FPS, timer, v);
}
void mouse(int button, int state, int x, int y) {
if (button == GLUT_LEFT_BUTTON &amp;&amp; state == GLUT_DOWN) {
spinning = true;
} else if (button == GLUT_RIGHT_BUTTON &amp;&amp; state == GLUT_DOWN) {
spinning = false;
}
}
int main(int argc, char** argv) {
glutInit(&amp;argc, argv);
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
glutInitWindowPosition(80, 80);
glutInitWindowSize(800, 500);
glutCreateWindow(&quot;Spinning Square&quot;);
glutReshapeFunc(reshape);
glutDisplayFunc(display);
glutTimerFunc(100, timer, 0);
glutMouseFunc(mouse);
glutMainLoop();
}
