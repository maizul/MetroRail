// A trapezium Polygon
#include <windows.h> // for MS Windows
#include <GL/glut.h> // GLUT, include glu.h and gl.h
#include<math.h>
//parameterised functions for specific objects
void drawQuad(GLint x0, GLint y0, GLint x1, GLint y1, GLint x2, GLint y2, GLint x3, GLint y3)
{
    glBegin(GL_QUADS);
    glVertex2f(x0,y0);
    glVertex2f(x1,y1);
    glVertex2f(x2,y2);
    glVertex2f(x3,y3);
    glEnd();
}
void drawTriangle(GLint x0, GLint y0, GLint x1, GLint y1, GLint x2, GLint y2)
{
    glBegin(GL_TRIANGLES);
    glVertex2f(x0,y0);
    glVertex2f(x1,y1);
    glVertex2f(x2,y2);
    glEnd();
}

void DrawCircle(float cx, float cy, float r, int num_segments)
{
    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i < num_segments; i++)
    {
        float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);//get current angle
        float x = r * cosf(theta);//calculate x
        float y = r * sinf(theta);//calculate y
        glVertex2f(x + cx, y + cy);//output vertex
    }
    glEnd();
    glFlush();
}
//platform
void platform()
{
    //pillars
    glColor3ub(0, 255, 255);
    drawQuad(-2.5, -60, -2.5, -97.5, 5, -100, 5, -65);
    glColor3ub(255, 255, 0);
    drawQuad(5, -65, 5, -100, 7.5, -97.5, 7.5, -60);
    glColor3ub(0, 255, 255);
    drawQuad(-75, -20, -75, -70, -65, -75, -65, -25);
    glColor3ub(255, 255, 0);
    drawQuad(-65, -25, -65, -75, -60, -70, -60, -25);
    //platform
    glColor3ub(255, 0, 0);
    drawQuad(-100, -10, 70, -100, 80, -100, -100, 0);
    glColor3ub(0, 255, 0);
    drawQuad(-100, 0, 80, -100, 95, -100, -100, 5);
    glColor3ub(0, 0, 255);
    drawQuad(-100, 20, 100, -50, 100, -40, -100, 25);
}
void cage(){
     glColor3ub(255, 0, 255);
     drawQuad(-50, 7.5, -50, -28, -48, -30, -48, 5);
     drawQuad(-30, 25, -30, 2, -32.5, 3, -32.5, 26);
     drawQuad(-50, 7.5, -48, 5, -30, 25, -32.5, 26);

     glColor3ub(255, 0, 255);
     drawQuad(-55, 9, -55, -25.5, -53, -27.5, -53, 7.5);
     drawQuad(-35, 27.5, -35, 4.5, -37.5, 5.5, -37.5, 28.5);
     drawQuad(-55, 9, -53, 7.5, -35, 27.5, -37.5, 28.5);

     glColor3ub(255, 0, 255);
     drawQuad(-60, 11.5, -60, -23, -58, -25, -58, 10);
     drawQuad(-40, 30, -40, 5, -42.5, 6, -42.5, 31);
     drawQuad(-60, 11.5, -58, 10, -40, 30, -42.5, 31);

     glColor3ub(255, 0, 255);
     drawQuad(-65, 14, -65, -20.5, -63, -22.5, -63, 12.5);
     drawQuad(-45, 32.5, -45, 7.5, -47.5, 8.5, -47.5, 33.5);
     drawQuad(-65, 14, -63, 12.5, -45, 32.5, -47.5, 33.5);

     glColor3ub(255, 0, 255);
     drawQuad(-70, 17.5, -70, -17, -68, -19, -68, 15);
     drawQuad(-50, 35, -50, 9, -52.5, 10, -52.5, 36);
     drawQuad(-70, 17.5, -68, 15, -50, 35, -52.5, 36);

}

void road(){
    //background
    glColor3ub(255, 255, 255);
    drawQuad(-100, -100, 100, -100, 100, 100, -100, 100);
    glColor3ub(1, 0, 0);
    drawQuad(-72.5, -100, -10, -100, 40, 100, 20, 100);
    //white lines
    glColor3ub(255, 255, 255);
    drawQuad(-42.5, -100, -37.5, -100, -26.5, -65, -30.5, -63);
    glColor3ub(255, 255, 255);
    drawQuad(-28.5, -55.5, -24.5, -57, -4.5, 0, -7.5, 1);
    glColor3ub(255, 255, 255);
    drawQuad(-2.5, 8, -5.5, 9, 14.5, 58, 16, 57);
    glColor3ub(255, 255, 255);
    drawQuad(16.5, 65, 18, 64, 31.75, 100, 29.25, 100);

}

void display()
{
    road();
    platform();
    cage();
    glFlush();
}

int main(int argc, char** argv)
{

glutInit(&argc, argv); // Initialize GLUT
glutCreateWindow("Lab Task 1"); // Create a window with the given title
glutInitWindowSize(1920, 1080);
gluOrtho2D(-100,100,-100,100); // Set the window's initial width & height

glutDisplayFunc(display); // Register display callback handler for window re-paint
glutMainLoop(); // Enter the event-processing loop
return 0;
}
