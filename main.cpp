// A trapezium Polygon
#include <windows.h> // for MS Windows
#include <GL/glut.h> // GLUT, include glu.h and gl.h
#include<math.h>
//parameterised functions for specific objects

int status=0;
GLfloat position_1 = 0.0;
GLfloat position_2 = 0.0;
GLfloat speed=0.0;
GLfloat speed_car=0.0;
GLfloat position_car_1 = 0.0;
GLfloat position_car_2 = 0.0;
GLfloat position_car_3 = 0.0;
GLfloat position_car_4 = 0.0;
GLfloat position_4 = 0.0;
GLfloat position_5 = 0.0;
GLfloat position_6 = 0.0;
float _rain = 0.0;
GLfloat sun_position = -40;
GLfloat sun_speed = .01;
GLfloat moon_position = -50;
GLfloat moon_speed = .01;

void rainy()
{
    sun_position = -40;
    moon_position = -50;
    //speed= 0.01f;
    //speed_car= 0.1f;
    if (position_1> 185)
        position_1 = -180.0f;
    position_1 +=speed+.01;

    if (position_2> 120)
        position_2 = -180.0f;
    position_2 +=speed+.015;

    if (position_car_1< -120)
        position_car_1 = 180.0f;
    position_car_1 -=speed_car+.01;

    if (position_car_3< -120)
        position_car_3 = 180.0f;
    position_car_3 -=speed_car+.015;


    if (position_car_2> 180)
        position_car_2 = -180.0f;
    position_car_2 +=speed_car;

    if (position_car_4> 160)
        position_car_4 = -180.0f;
    position_car_4 +=speed_car+.01;

    if (position_4< -220)
        position_4 = 180.0f;
    position_4 -=speed_car+.01;

    if (position_5> 220)
        position_5 = -180.0f;
    position_5 +=speed_car+.01;

    if (position_6< -220)
        position_6 = 220.0f;
    position_6 -=speed_car+.01;
    glutPostRedisplay();
}

void day()
{
    moon_position = -50;
    //speed= 0.01;
    //speed_car= 0.1;

    if (position_1> 185)
        position_1 = -180.0f;
    position_1 +=speed+.01;

    if (position_2> 120)
        position_2 = -180.0f;
    position_2 +=speed+0.015;

    if (position_car_1< -120)
        position_car_1 = 180.0f;
    position_car_1 -=speed_car+.01;

    if (position_car_3< -120)
        position_car_3 = 180.0f;
    position_car_3 -=speed_car+.015;

    if (position_car_2> 180)
        position_car_2 = -180.0f;
    position_car_2 +=speed_car+0.02;

    if (position_car_4> 160)
        position_car_4 = -180.0f;
    position_car_4 +=speed_car+.01;

    if (position_4< -220)
        position_4 = 180.0f;
    position_4 -=speed_car+.01;

    if (position_5> 220)
        position_5 = -180.0f;
    position_5 +=speed_car+.01;

    if (position_6< -220)
        position_6 = 220.0f;
    position_6 -=speed_car+.01;
    glutPostRedisplay();

    if(status==0)
    {
        sun_position += sun_speed;
        if(sun_position >= 5)
            sun_position = 5;

    }
}
void night()
{
    sun_position = -40;
    //speed= 0.01f;
    //speed_car= 0.1f;
    if (position_1> 185)
        position_1 = -180.0f;
    position_1 +=speed+.01;

    if (position_2> 120)
        position_2 = -180.0f;
    position_2 +=speed+.015;

    if (position_car_1< -120)
        position_car_1 = 180.0f;
    position_car_1 -=speed_car+.01;

    if (position_car_3< -120)
        position_car_3 = 180.0f;
    position_car_3 -=speed_car+.015;

    if (position_car_2> 160)
        position_car_2 = -180.0f;
    position_car_2 +=speed_car;

    if (position_car_4> 160)
        position_car_4 = -180.0f;
    position_car_4 +=speed_car+.01;

    if (position_4< -220)
        position_4 = 180.0f;
    position_4 -=speed_car+.01;

    if (position_5> 220)
        position_5 = -180.0f;
    position_5 +=speed_car+.01;

    if (position_6< -220)
        position_6 = 220.0f;
    position_6 -=speed_car+.01;
    glutPostRedisplay();

    if(status==2)
    {
        moon_position += moon_speed;
        if(moon_position >= 0)
            moon_position = 0;

    }
}


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
void drawLine(GLint x0, GLint y0, GLint x1, GLint y1)
{
    glBegin(GL_LINES);
    glVertex2f(x0,y0);
    glVertex2f(x1,y1);
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
}
//platform
//platform
void platform()
{
    //pillar garden under wall
    glColor3ub(157,170,179);
    drawQuad(-100,-15,100,-15,100,-14,-100,-14);

    //below pillar block
    glColor3ub(0, 255, 0);
    drawQuad(-100,-22,100,-22,100,-15,-100,-15);

    //pillar 1 sideways line
    glLineWidth(4);
    glColor3ub(0, 0, 0);
    drawLine(-78,-17,-78,25);
    drawLine(-80,-20,-78,-17);

    //pillar 3 sideways line
    glLineWidth(4);
    glColor3ub(0, 0, 0);
    drawLine(78,-17,78,25);
    drawLine(80,-20,78,-17);

    //pillar 1 sideways
    glColor3ub(122,132,143);
    drawQuad(-80,-20,-78,-17,-78,25,-80,25);//pillar 1 sideways
    /*
    //pillar 2 sideways
    glColor3ub(122,132,143);
    glBegin(GL_POLYGON);
    glVertex2f(-1.50f, -20.0f);
    glVertex2f(2.0f, -20.0f);
    glVertex2f(3.0f,-17.0f);
    glVertex2f(3.0f,25.0f);
    glVertex2f(-2.50f, 25.0f);
    glVertex2f(-2.50f, -17.0f);
    glEnd();
    */
    //pillar 3 sideways
    glColor3ub(122,132,143);
    drawQuad(80,-20,78,-17,78,25,80,25);//pillar 3 sideways

    //pillar 1 lines
    glLineWidth(4);
    glColor3ub(0, 0, 0);
    drawLine(-83,-20,-80,-20);
    glColor3ub(0, 0, 0);
    drawLine(-80,-20,-80,25);
    glColor3ub(0, 0, 0);
    drawLine(-83,-20,-83,25);

    //pillar 2 lines
    glColor3ub(0, 0, 0);
    drawLine(-1.5,-20,2,-20);
    glColor3ub(0, 0, 0);
    drawLine(2,-20,2,25);
    glColor3ub(0, 0, 0);
    drawLine(-1.5,-20,-1.5,25);
    //pillar 3 lines
    glColor3ub(0, 0, 0);
    drawLine(83,-20,80,-20);
    glColor3ub(0, 0, 0);
    drawLine(80,-20,80,25);
    glColor3ub(0, 0, 0);
    drawLine(83,-20,83,25);

    //pillars
    glColor3ub(157,170,179);
    drawQuad(-83,-20,-80,-20,-80,25,-83,25);//pillar 1
    drawQuad(-1.5,-20,2,-20,2,25,-1.5,25);//pillar 2
    drawQuad(83,-20,80,-20,80,25,83,25);// pillar 3

    //pillar garden over wall
    glColor3ub(157,170,179);
    drawQuad(-100,-22,100,-22,100,-18,-100,-18);

    //platform
    glColor3ub(169,169,169);
    drawQuad(-100,24,100,24,100,31,-100,31);

    //rail line
    glLineWidth(2);
    glColor3ub(0, 0, 0);
    drawLine(-100,26.5,100,26.5);
    glColor3ub(0, 0, 0);
    drawLine(-100,29,100,29);

}
void road()
{
    //Road
    glColor3ub(47,47,47);
    drawQuad(-100,-55,100,-55,100,15,-100,15);

    //white lines upper
    glLineWidth(5);
    glColor3ub(255, 255, 255);
    drawLine(-100,2,-85,2);
    drawLine(-77,2,-55,2);
    drawLine(-47,2,-22,2);
    drawLine(-14,2,8,2);
    drawLine(16,2,38,2);
    drawLine(46,2,68,2);
    drawLine(76,2,100,2);
    glColor3ub(210,183,70);
    drawLine(-100,-13,100,-13);//long line

    //white lines below
    glLineWidth(5);
    glColor3ub(255, 255, 255);
    drawLine(-100,-37,-85,-37);
    drawLine(-77,-37,-55,-37);
    drawLine(-47,-37,-22,-37);
    drawLine(-14,-37,8,-37);
    drawLine(16,-37,38,-37);
    drawLine(46,-37,68,-37);
    drawLine(76,-37,100,-37);
    glColor3ub(210,183,70);
    drawLine(-100,-23,100,-23);//long line
}

void footpath()
{
    //footpath below
    glColor3ub(226,135,67);
    drawQuad(-100,-61,100,-61,100,-55,-100,-55);

    //footpath upper
    glColor3ub(226,135,67);
    drawQuad(-100,15,100,15,100,23,-100,23);
    //grey shade upper
    glColor3ub(140,140,140);
    drawQuad(-100,15,100,15,100,18,-100,18);
    //grey shade below
    glColor3ub(140,140,140);
    drawQuad(-100,-61,100,-61,100,-59,-100,-59);

    //dark line
    glLineWidth(2);
    glColor3ub(0,0,0);
    drawLine(-100,18,100,18);
    drawLine(-100,23,100,23);
    drawLine(-100,-59,100,-59);

}

void light1(GLfloat r,GLfloat g,GLfloat b)
{
    glColor3ub(102,1,0);//light1
    drawQuad(-75,-61,-69,-61,-69,-58,-75,-58);
    glLineWidth(9);
    drawLine(-72,-58,-72,-33);
    glColor3ub(r, g, b);
    drawQuad(-73,-33,-71,-33,-69,-28,-75,-28);
    glLineWidth(3);
    glColor3ub(0,0,0);
    drawLine(-72,-33,-74,-28);
    drawLine(-72,-33,-70,-28);



    glColor3ub(102,1,0);//light2
    drawQuad(-33,-61,-27,-61,-27,-58,-33,-58);
    glLineWidth(9);
    drawLine(-30,-58,-30,-33);
    glColor3ub(r,g,b);
    drawQuad(-31,-33,-29,-33,-27,-28,-33,-28);
    glLineWidth(3);
    glColor3ub(0,0,0);
    drawLine(-30,-33,-32,-28);
    drawLine(-30,-33,-28,-28);



    glColor3ub(102,1,0);//light4
    drawQuad(75,-61,69,-61,69,-58,75,-58);
    glLineWidth(9);
     drawLine(72,-58,72,-33);
    glColor3ub(r,g,b);
    drawQuad(73,-33,71,-33,69,-28,75,-28);
    glLineWidth(3);
    glColor3ub(0,0,0);
    drawLine(72,-33,74,-28);
    drawLine(72,-33,70,-28);



    glColor3ub(102,1,0);//light3
    drawQuad(33,-61,27,-61,27,-58,33,-58);
    glLineWidth(9);
    drawLine(30,-58,30,-33);
    glColor3ub(r,g,b);
    drawQuad(31,-33,29,-33,27,-28,33,-28);
    glLineWidth(3);
    glColor3ub(0,0,0);
    drawLine(30,-33,32,-28);
    drawLine(30,-33,28,-28);



}


void light2(GLfloat r,GLfloat g,GLfloat b)
{
    glColor3ub(102,1,0);//light1
    drawQuad(-75,19,-71,19,-71,21,-75,21);
    glLineWidth(7);
    drawLine(-73,21,-73,35);
    glColor3ub(r,g,b);
    drawQuad(-74,35,-72,35,-71,38,-75,38);
     glLineWidth(3);
    glColor3ub(0,0,0);
    drawLine(-73,35,-74,38);
    drawLine(-73,35,-72,38);



    glColor3ub(102,1,0);//light2
    drawQuad(-33,19,-29,19,-29,21,-33,21);
    glLineWidth(7);
    drawLine(-31,21,-31,35);
    glColor3ub(r,g,b);
    drawQuad(-32,35,-30,35,-29,38,-33,38);
    glLineWidth(3);
    glColor3ub(0,0,0);
    drawLine(-31,35,-32,38);
    drawLine(-31,35,-30,38);



    glColor3ub(102,1,0);//light4
    drawQuad(75,19,71,19,71,21,75,21);
    glLineWidth(7);
    drawLine(73,21,73,35);
    glColor3ub(r,g,b);
    drawQuad(74,35,72,35,71,38,75,38);
    glLineWidth(3);
    glColor3ub(0,0,0);
    drawLine(73,35,74,38);
    drawLine(73,35,72,38);



    glColor3ub(102,1,0);//light3
    drawQuad(33,19,29,19,29,21,33,21);
    glLineWidth(7);
    drawLine(31,21,31,35);
    glColor3ub(r,g,b);
    drawQuad(32,35,30,35,29,38,33,38);
     glLineWidth(3);
    glColor3ub(0,0,0);
    drawLine(31,35,32,38);
    drawLine(31,35,30,38);




}

void sun(GLfloat r,GLfloat g,GLfloat b){

    glPushMatrix();
    glTranslatef(0.0f, sun_position,0.0f);
    glColor3ub(r,g,b);
    DrawCircle(5,70,10,25);
    glPopMatrix();
}

void moon(GLfloat r,GLfloat g,GLfloat b){

    glPushMatrix();
    glTranslatef(0.0f, moon_position,0.0f);
    glColor3ub(r,g,b);
    DrawCircle(-90,90,4,25);
    glPopMatrix();
}

void sky(GLfloat r,GLfloat g,GLfloat b)
{
    //sky
    glColor3ub(r,g,b);
    drawQuad(-100,23,100,23,100,100,-100,100);
}

void star(){
    glPointSize(3.0);
    glBegin(GL_POINTS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(90, 70);
    glVertex2f(90, 80);
    glVertex2f(80, 90);
    glVertex2f(60, 70);
    glVertex2f(70, 80);
    glVertex2f(70, 90);
    glVertex2f(60, 90);
    glVertex2f(50, 80);
    glVertex2f(50, 70);
    glVertex2f(60, 65);
    glVertex2f(40, 80);
    glVertex2f(40, 75);
    glVertex2f(30, 73);
    glVertex2f(30, 87);
    glVertex2f(20, 81);
    glVertex2f(20, 66);
    glVertex2f(10, 91);
    glVertex2f(10, 76);
    glVertex2f(0, 77);
    glVertex2f(-90, 70);
    glVertex2f(-90, 80);
    glVertex2f(-80, 90);
    glVertex2f(-60, 70);
    glVertex2f(-70, 80);
    glVertex2f(-70, 90);
    glVertex2f(-60, 90);
    glVertex2f(-50, 80);
    glVertex2f(-50, 70);
    glVertex2f(-60, 65);
    glVertex2f(-40, 80);
    glVertex2f(-40, 75);
    glVertex2f(-30, 73);
    glVertex2f(-30, 87);
    glVertex2f(-20, 81);
    glVertex2f(-20, 66);
    glVertex2f(-10, 91);
    glVertex2f(-10, 76);


    glEnd();
}

void ground()
{
    //sky
    glColor3ub(38,139,7);
    drawQuad(-100,-100,100,-100,100,-61,-100,-61);
    //pathway
    glColor3ub(226,135,67);
    drawQuad(-20,-85,100,-85,100,-77,-20,-77);
    drawQuad(38,-100,42,-100,42,-61,38,-61);
    //tree
    glLineWidth(30);
    glColor3ub(166,123,81);
    drawLine(-90,-95,-90,-83);
    drawLine(-85,-90,-85,-73);
    drawLine(-80,-85,-80,-68);
    drawLine(-75,-80,-75,-63);

    glColor3ub(12,174,91);
    drawTriangle(-95,-86,-85,-86,-90,-81);
    drawTriangle(-95,-83,-85,-83,-90,-78);
    drawTriangle(-95,-80,-85,-80,-90,-75);
    drawTriangle(-95,-77,-85,-77,-90,-70);

    drawTriangle(-90,-83,-80,-83,-85,-78);
    drawTriangle(-90,-80,-80,-80,-85,-75);
    drawTriangle(-90,-77,-80,-77,-85,-72);
    drawTriangle(-90,-74,-80,-74,-85,-67);

    drawTriangle(-85,-80,-75,-80,-80,-75);
    drawTriangle(-85,-77,-75,-77,-80,-72);
    drawTriangle(-85,-74,-75,-74,-80,-69);
    drawTriangle(-85,-71,-75,-71,-80,-63);

    drawTriangle(-80,-77,-70,-77,-75,-72);
    drawTriangle(-80,-74,-70,-74,-75,-69);
    drawTriangle(-80,-71,-70,-71,-75,-64);
    drawTriangle(-80,-68,-70,-68,-75,-58);

    //tree2
    glLineWidth(30);
    glColor3ub(166,123,81);
    drawLine(90,-95,90,-83);
    drawLine(85,-90,85,-73);
    //drawLine(80,-85,80,-68);
    //drawLine(75,-80,75,-63);
    glColor3ub(12,174,91);
    drawTriangle(95,-86,85,-86,90,-81);
    drawTriangle(95,-83,85,-83,90,-78);
    drawTriangle(95,-80,85,-80,90,-75);
    drawTriangle(95,-77,85,-77,90,-70);

    drawTriangle(90,-83,80,-83,85,-78);
    drawTriangle(90,-80,80,-80,85,-75);
    drawTriangle(90,-77,80,-77,85,-72);
    drawTriangle(90,-74,80,-74,85,-67);
    /*
    drawTriangle(85,-80,75,-80,80,-75);
    drawTriangle(85,-77,75,-77,80,-72);
    drawTriangle(85,-74,75,-74,80,-69);
    drawTriangle(85,-71,75,-71,80,-63);

    drawTriangle(80,-77,70,-77,75,-72);
    drawTriangle(80,-74,70,-74,75,-69);
    drawTriangle(80,-71,70,-71,75,-64);
    drawTriangle(80,-68,70,-68,75,-58);
    */

    //pond

    glColor3ub(89,192,249);
    drawQuad(-68,-95,-20,-95,-20,-66,-64,-66);
    glLineWidth(3);
    glColor3ub(0,0,0);
    drawLine(-68,-95,-20,-95);
    drawLine(-68,-94,-20,-94);
    drawLine(-68,-93,-20,-93);
    drawLine(-68,-92,-20,-92);

    drawLine(-20,-95,-20,-66);
    drawLine(-21,-95,-21,-66);
    drawLine(-22,-95,-22,-66);
    drawLine(-23,-95,-23,-66);

    drawLine(-20,-66,-64,-66);
    drawLine(-20,-67,-64,-67);
    drawLine(-20,-68,-64,-68);
    drawLine(-20,-69,-64,-69);

    drawLine(-64,-66,-68,-95);
    drawLine(-63,-66,-67,-95);
    drawLine(-62,-66,-66,-95);
    drawLine(-61,-66,-65,-95);
    //bench
    glLineWidth(5);
    glColor3ub(255,205,0);
    drawLine(-10,-70,-0,-70);
    drawLine(-10,-72,-0,-72);
    drawLine(-10,-66,-0,-66);
    drawLine(-10,-64,-0,-64);
    glLineWidth(3);
    drawLine(-8,-72,-8,-77);
    drawLine(-2,-72,-2,-77);
    drawLine(-6,-66,-7,-72);
    drawLine(-4,-66,-3,-72);
    drawLine(-6,-66,-7,-72);
    drawLine(-7,-72,-7,-74);
    drawLine(-3,-72,-3,-74);

    //bench2
    glLineWidth(5);
    glColor3ub(255,205,0);
    drawLine(46,-70,56,-70);
    drawLine(46,-72,56,-72);
    drawLine(46,-66,56,-66);
    drawLine(46,-64,56,-64);
    glLineWidth(3);
    drawLine(48,-72,48,-77);
    drawLine(54,-72,54,-77);
    drawLine(50,-66,49,-72);
    drawLine(52,-66,53,-72);
    drawLine(50,-66,49,-72);
    drawLine(49,-72,49,-74);
    drawLine(53,-72,53,-74);


}


void background_clouds(GLfloat r,GLfloat g,GLfloat b)
{

    glPushMatrix();
    glTranslatef(position_1, 0.0f,0.0f);
    //clouds
    glLineWidth(6);
    glColor3ub(r,g,b);
    drawLine(-70,70,-68,70);
    drawLine(-71,71,-67,71);
    drawLine(-72,72,-66,72);
    drawLine(-71,73,-67,73);
    drawLine(-70,74,-68,74);

    drawLine(-58,76,-57,76);
    drawLine(-59,77,-56,77);
    drawLine(-60,78,-55,78);
    drawLine(-59,79,-56,79);
    drawLine(-58,80,-57,80);

    drawLine(70,70,68,70);
    drawLine(71,71,67,71);
    drawLine(72,72,66,72);
    drawLine(71,73,67,73);
    drawLine(70,74,68,74);

    drawLine(58,76,57,76);
    drawLine(59,77,56,77);
    drawLine(60,78,55,78);
    drawLine(59,79,56,79);
    drawLine(58,80,57,80);

    drawLine(-95,80,-94,80);
    drawLine(-96,81,-93,81);
    drawLine(-97,82,-92,82);
    drawLine(-96,83,-93,83);
    drawLine(-95,84,-94,84);

    drawLine(95,80,94,80);
    drawLine(96,81,93,81);
    drawLine(97,82,92,82);
    drawLine(96,83,93,83);
    drawLine(95,84,94,84);

    drawLine(23,70,22,70);
    drawLine(24,71,21,71);
    drawLine(25,72,20,72);
    drawLine(24,73,21,73);
    drawLine(23,74,22,74);

    drawLine(-23,80,-22,80);
    drawLine(-24,81,-21,81);
    drawLine(-25,82,-20,82);
    drawLine(-24,83,-21,83);
    drawLine(-23,84,-22,84);

    glPopMatrix();
}

void forward_clouds(GLfloat r,GLfloat g,GLfloat b )
{

    glPushMatrix();
    glTranslatef(position_2, 0.0f,0.0f);
    //clouds
    glLineWidth(8);
    glColor3ub(r, g, b);
    drawLine(-53,70,-49,70);
    drawLine(-54,71,-48,71);
    drawLine(-55,72,-47,72);
    drawLine(-54,73,-48,73);
    drawLine(-53,74,-49,74);

    drawLine(53,70,49,70);
    drawLine(54,71,48,71);
    drawLine(55,72,47,72);
    drawLine(54,73,48,73);
    drawLine(53,74,49,74);

    drawLine(8,80,4,80);
    drawLine(9,81,3,81);
    drawLine(10,82,2,82);
    drawLine(9,83,3,83);
    drawLine(8,84,4,84);


    glPopMatrix();


}

void background_buildings()
{
    //background buildings
    glLineWidth(10);
    glColor3ub(211, 211, 211);
    drawLine(-100,23,-100,70);
    drawLine(-99,23,-99,76);
    drawLine(-98,23,-98,26);
    drawLine(-97,23,-97,67);
    drawLine(-96,23,-96,77);
    drawLine(-95,23,-95,78);
    drawLine(-94,23,-94,80);
    drawLine(-93,23,-93,29);
    drawLine(-92,23,-92,72);
    drawLine(-91,23,-91,67);
    drawLine(-90,23,-90,60);
    drawLine(-89,23,-89,32);
    drawLine(-88,23,-88,74);
    drawLine(-87,23,-87,44);
    drawLine(-86,23,-86,41);
    drawLine(-85,23,-85,30);
    drawLine(-84,23,-84,74);
    drawLine(-83,23,-83,77);
    drawLine(-82,23,-82,36);
    drawLine(-81,23,-81,72);
    drawLine(-80,23,-80,72);
    drawLine(-79,23,-79,24);
    drawLine(-78,23,-78,62);
    drawLine(-77,23,-77,75);
    drawLine(-76,23,-76,53);
    drawLine(-75,23,-75,42);
    drawLine(-74,23,-74,82);
    drawLine(-73,23,-73,67);
    drawLine(-72,23,-72,36);
    drawLine(-71,23,-71,67);
    drawLine(-70,23,-70,25);
    drawLine(-69,23,-69,33);
    drawLine(-68,23,-68,29);
    drawLine(-67,23,-67,44);
    drawLine(-66,23,-66,58);
    drawLine(-65,23,-65,59);
    drawLine(-64,23,-64,27);
    drawLine(-63,23,-63,66);
    drawLine(-62,23,-62,33);
    drawLine(-61,23,-61,70);
    drawLine(-60,23,-60,42);
    drawLine(-59,23,-59,61);
    drawLine(-58,23,-58,84);
    drawLine(-57,23,-57,28);
    drawLine(-56,23,-56,62);
    drawLine(-55,23,-55,72);
    drawLine(-54,23,-54,27);
    drawLine(-53,23,-53,61);
    drawLine(-52,23,-52,66);
    drawLine(-51,23,-51,26);
    drawLine(-50,23,-50,34);
    drawLine(-49,23,-49,60);
    drawLine(-48,23,-48,67);
    drawLine(-47,23,-47,67);
    drawLine(-46,23,-46,82);
    drawLine(-45,23,-45,51);
    drawLine(-44,23,-44,72);
    drawLine(-43,23,-43,50);
    drawLine(-42,23,-42,23);
    drawLine(-41,23,-41,45);
    drawLine(-40,23,-40,53);
    drawLine(-39,23,-39,51);
    drawLine(-38,23,-38,34);
    drawLine(-37,23,-37,81);
    drawLine(-36,23,-36,36);
    drawLine(-35,23,-35,80);
    drawLine(-34,23,-34,44);
    drawLine(-33,23,-33,71);
    drawLine(-32,23,-32,45);
    drawLine(-31,23,-31,55);
    drawLine(-30,23,-30,29);
    drawLine(-29,23,-29,26);
    drawLine(-28,23,-28,62);
    drawLine(-27,23,-27,31);
    drawLine(-26,23,-26,35);
    drawLine(-25,23,-25,79);
    drawLine(-24,23,-24,49);
    drawLine(-23,23,-23,26);
    drawLine(-22,23,-22,27);
    drawLine(-21,23,-21,69);
    drawLine(-20,23,-20,67);
    drawLine(-19,23,-19,70);
    drawLine(-18,23,-18,61);
    drawLine(-17,23,-17,68);
    drawLine(-16,23,-16,55);
    drawLine(-15,23,-15,25);
    drawLine(-14,23,-14,80);
    drawLine(-13,23,-13,81);
    drawLine(-12,23,-12,34);
    drawLine(-11,23,-11,64);
    drawLine(-10,23,-10,29);
    drawLine(-9,23,-9,33);
    drawLine(-8,23,-8,45);
    drawLine(-7,23,-7,76);
    drawLine(-6,23,-6,71);
    drawLine(-5,23,-5,74);
    drawLine(-4,23,-4,38);
    drawLine(-3,23,-3,35);
    drawLine(-2,23,-2,42);
    drawLine(-1,23,-1,63);
    drawLine(0,23,0,62);
    drawLine(1,23,1,45);
    drawLine(2,23,2,56);
    drawLine(3,23,3,74);
    drawLine(4,23,4,37);
    drawLine(5,23,5,30);
    drawLine(6,23,6,35);
    drawLine(7,23,7,30);
    drawLine(8,23,8,44);
    drawLine(9,23,9,74);
    drawLine(10,23,10,35);
    drawLine(11,23,11,41);
    drawLine(12,23,12,39);
    drawLine(13,23,13,33);
    drawLine(14,23,14,25);
    drawLine(15,23,15,52);
    drawLine(16,23,16,37);
    drawLine(17,23,17,23);
    drawLine(18,23,18,54);
    drawLine(19,23,19,34);
    drawLine(20,23,20,60);
    drawLine(21,23,21,33);
    drawLine(22,23,22,76);
    drawLine(23,23,23,68);
    drawLine(24,23,24,24);
    drawLine(25,23,25,35);
    drawLine(26,23,26,64);
    drawLine(27,23,27,62);
    drawLine(28,23,28,39);
    drawLine(29,23,29,60);
    drawLine(30,23,30,67);
    drawLine(31,23,31,64);
    drawLine(32,23,32,41);
    drawLine(33,23,33,53);
    drawLine(34,23,34,81);
    drawLine(35,23,35,53);
    drawLine(36,23,36,80);
    drawLine(37,23,37,72);
    drawLine(38,23,38,60);
    drawLine(39,23,39,33);
    drawLine(40,23,40,47);
    drawLine(41,23,41,39);
    drawLine(42,23,42,53);
    drawLine(43,23,43,32);
    drawLine(44,23,44,31);
    drawLine(45,23,45,31);
    drawLine(46,23,46,56);
    drawLine(47,23,47,39);
    drawLine(48,23,48,39);
    drawLine(49,23,49,74);
    drawLine(50,23,50,56);
    drawLine(51,23,51,72);
    drawLine(52,23,52,57);
    drawLine(53,23,53,57);
    drawLine(54,23,54,81);
    drawLine(55,23,55,77);
    drawLine(56,23,56,64);
    drawLine(57,23,57,71);
    drawLine(58,23,58,66);
    drawLine(59,23,59,41);
    drawLine(60,23,60,34);
    drawLine(61,23,61,70);
    drawLine(62,23,62,36);
    drawLine(63,23,63,26);
    drawLine(64,23,64,33);
    drawLine(65,23,65,55);
    drawLine(66,23,66,68);
    drawLine(67,23,67,84);
    drawLine(68,23,68,31);
    drawLine(69,23,69,71);
    drawLine(70,23,70,69);
    drawLine(71,23,71,29);
    drawLine(72,23,72,40);
    drawLine(73,23,73,52);
    drawLine(74,23,74,63);
    drawLine(75,23,75,32);
    drawLine(76,23,76,36);
    drawLine(77,23,77,68);
    drawLine(78,23,78,67);
    drawLine(79,23,79,24);
    drawLine(80,23,80,50);
    drawLine(81,23,81,49);
    drawLine(82,23,82,57);
    drawLine(83,23,83,74);
    drawLine(84,23,84,50);
    drawLine(85,23,85,70);
    drawLine(86,23,86,68);
    drawLine(87,23,87,33);
    drawLine(88,23,88,34);
    drawLine(89,23,89,36);
    drawLine(90,23,90,27);
    drawLine(91,23,91,45);
    drawLine(92,23,92,44);
    drawLine(93,23,93,28);
    drawLine(94,23,94,69);
    drawLine(95,23,95,53);
    drawLine(96,23,96,71);
    drawLine(97,23,97,55);
    drawLine(98,23,98,23);
    drawLine(99,23,99,65);
    drawLine(100,23,100,79);
}

void front_buildings()
{
    //1st building
    glColor3ub(112,128,144);
    drawQuad(-100,23,-92,23,-92,50,-100,50);

    glColor3ub(204, 255, 255);// window
    drawQuad(-100,46,-92,46,-92,48,-100,48);
    drawQuad(-100,42,-92,42,-92,44,-100,44);
    drawQuad(-100,38,-92,38,-92,40,-100,40);
    drawQuad(-100,34,-92,34,-92,36,-100,36);
    drawQuad(-100,30,-92,30,-92,32,-100,32);


    //2nd building
    glColor3ub(0,0,0);
    drawQuad(-91,23,-75,23,-75,60,-91,60);

    glColor3ub(204, 255, 255);// window
    drawQuad(-91,54,-75,54,-75,57,-91,57);
    drawQuad(-91,48,-75,48,-75,51,-91,51);
    drawQuad(-91,42,-75,42,-75,45,-91,45);
    drawQuad(-91,36,-75,36,-75,39,-91,39);
    drawQuad(-91,30,-75,30,-75,33,-91,33);


    //3rd building
    glColor3ub(112,128,144);
    drawQuad(-74,23,-65,23,-65,55,-74,55);

    glColor3ub(204, 255, 255);// window
    drawQuad(-73,51,-72,51,-72,53, -73,53);
    drawQuad(-70,51,-69,51,-69,53, -70,53);
    drawQuad(-67,51,-66,51,-66,53, -67,53);

    drawQuad(-73,47,-72,47,-72,49, -73,49);
    drawQuad(-70,47,-69,47,-69,49, -70,49);
    drawQuad(-67,47,-66,47,-66,49, -67,49);

    drawQuad(-73,43,-72,43,-72,45, -73,45);
    drawQuad(-70,43,-69,43,-69,45, -70,45);
    drawQuad(-67,43,-66,43,-66,45, -67,45);

    drawQuad(-73,39,-72,39,-72,41, -73,41);
    drawQuad(-70,39,-69,39,-69,41, -70,41);
    drawQuad(-67,39,-66,39,-66,41, -67,41);

    drawQuad(-73,35,-72,35,-72,37, -73,37);
    drawQuad(-70,35,-69,35,-69,37, -70,37);
    drawQuad(-67,35,-66,35,-66,37, -67,37);

    drawQuad(-73,31,-72,31,-72,33, -73,33);
    drawQuad(-70,31,-69,31,-69,33, -70,33);
    drawQuad(-67,31,-66,31,-66,33, -67,33);



    //4th building
    glColor3ub(0,0,0);
    drawQuad(-64,23,-54,23,-54,55,-64,55);

    glColor3ub(204, 255, 255);// window
    drawQuad(-63,49,-62,49,-62,53,-63,53);
    drawQuad(-61,49,-60,49,-60,53,-61,53);
    drawQuad(-59,49,-58,49,-58,53,-59,53);
    drawQuad(-57,49,-56,49,-56,53,-57,53);

    drawQuad(-63,45,-60,45,-60,47,-63,47);
    drawQuad(-58,45,-55,45,-55,47,-58,47);

    drawQuad(-63,41,-60,41,-60,43,-63,43);
    drawQuad(-58,41,-55,41,-55,43,-58,43);

    drawQuad(-63,37,-60,37,-60,39,-63,39);
    drawQuad(-58,37,-55,37,-55,39,-58,39);

    drawQuad(-63,33,-60,33,-60,35,-63,35);
    drawQuad(-58,33,-55,33,-55,35,-58,35);

    drawQuad(-63,33,-60,33,-60,35,-63,35);
    drawQuad(-58,33,-55,33,-55,35,-58,35);

    drawQuad(-63,29,-60,29,-60,31,-63,31);
    drawQuad(-58,29,-55,29,-55,31,-58,31);


    //5th building
    glColor3ub(112,128,144);
    drawQuad(-53,23,-45,23,-45,50,-53,50);
    glLineWidth(10);
    glColor3ub(112,128,144);
    drawLine(-52,51,-46,51);
    drawLine(-51,53,-47,53);
    drawLine(-50,55,-48,55);
     glColor3ub(204, 255, 255);// window
    drawQuad(-52,42,-51,42,-51,48,-52,48);
    drawQuad(-50,42,-49,42,-49,48,-50,48);
    drawQuad(-48,46,-46,46,-46,48,-48,48);
    drawQuad(-48,42,-46,42,-46,44,-48,44);
    drawQuad(-52,39,-49,39,-49,41,-52,41);
    drawQuad(-52,36,-49,36,-49,38,-52,38);
    drawQuad(-48,36,-46,36,-46,41,-48,41);
    drawQuad(-53,32,-45,32,-45,34,-53,34);
    drawQuad(-53,28,-45,28,-45,30,-53,30);
    drawQuad(-53,24,-45,24,-45,26,-53,26);






    //6th building
    glColor3ub(0,0,0);
    drawQuad(-44,23,-36,23,-36,60,-44,53);
    glColor3ub(204, 255, 255);// window
    drawQuad(-43,50,-41,50,-41,53,-43,53);
    drawQuad(-43,46,-41,46,-41,49,-43,49);
    drawQuad(-43,42,-41,42,-41,45,-43,45);
    drawQuad(-43,38,-41,38,-41,41,-43,41);
    drawQuad(-43,34,-41,34,-41,37,-43,37);
    drawQuad(-43,30,-41,30,-41,33,-43,33);
    drawQuad(-43,26,-41,26,-41,29,-43,29);
    drawQuad(-43,24,-41,24,-41,27,-43,27);

    drawQuad(-39,50,-37,50,-37,53,-39,53);
    drawQuad(-39,46,-37,46,-37,49,-39,49);
    drawQuad(-39,42,-37,42,-37,45,-39,45);
    drawQuad(-39,38,-37,38,-37,41,-39,41);
    drawQuad(-39,34,-37,34,-37,37,-39,37);
    drawQuad(-39,30,-37,30,-37,33,-39,33);
    drawQuad(-39,26,-37,26,-37,29,-39,29);
    drawQuad(-39,24,-37,24,-37,27,-39,27);




   //7th building
    glColor3ub(112,128,144);
    drawQuad(-34,23,-24,23,-24,70,-34,70);
    glColor3ub(204, 255, 255);// window
    drawQuad(-33,66, -28,66, -28, 68,-33,68);
    drawQuad(-33,62, -28,62, -28, 64,-33,64);
    drawQuad(-33,58, -28,58, -28, 60,-33,60);
    drawQuad(-33,54, -28,54, -28, 56,-33,56);
    drawQuad(-33,50, -28,50, -28, 52,-33,52);
    drawQuad(-33,46, -28,46, -28, 48,-33,48);
    drawQuad(-33,42, -28,42, -28, 44,-33,44);
    drawQuad(-33,38, -28,38, -28, 40,-33,40);
    drawQuad(-33,34, -28,34, -28, 36,-33,36);
    drawQuad(-33,30, -28,30, -28, 32,-33,32);
    drawQuad(-33,26, -28,26, -28, 28,-33,28);
    drawQuad(-33,24, -28,24, -28, 26,-33,26);

    drawQuad(-26,66, -25,66, -25, 68,-26,68);
    drawQuad(-26,62, -25,62, -25, 64,-26,64);
    drawQuad(-26,58, -25,58, -25, 60,-26,60);
    drawQuad(-26,54, -25,54, -25, 56,-26,56);
    drawQuad(-26,50, -25,50, -25, 52,-26,52);
    drawQuad(-26,46, -25,46, -25, 48,-26,48);
    drawQuad(-26,42, -25,42, -25, 44,-26,44);
    drawQuad(-26,38, -25,38, -25, 40,-26,40);
    drawQuad(-26,34, -25,34, -25, 36,-26,36);
    drawQuad(-26,30, -25,30, -25, 32,-26,32);
    drawQuad(-26,26, -25,26, -25, 28,-26,28);
    drawQuad(-26,24, -25,24, -25, 26,-26,26);




    //8th building
    glColor3ub(0,0,0);
    drawQuad(-23,23,-13,23,-13,60,-23,60);
    glColor3ub(204, 255, 255);// window
    drawQuad(-20,56, -19,56, -19, 58,-20,58);
    drawQuad(-17,56, -16,56, -16, 58,-17,58);
    drawQuad(-22,52, -19,52, -19, 54,-22,54);
    drawQuad(-22,48, -19,48, -19, 50,-22,50);
    drawQuad(-22,44, -19,44, -19, 46,-22,46);
    drawQuad(-17,52, -14,52, -14, 54,-17,54);
    drawQuad(-17,48, -14,48, -14, 50,-17,50);
    drawQuad(-17,44, -14,44, -14, 46,-17,46);
    drawQuad(-20,40, -19,40, -19,42,-20,42);
    drawQuad(-17,40, -16,40, -16,42,-17,42);
    drawQuad(-22,36, -19,36, -19, 38,-22,38);
    drawQuad(-22,32, -19,32, -19, 34,-22,34);
    drawQuad(-22,28, -19,28, -19, 30,-22,30);
    drawQuad(-22,24, -19,24, -19, 26,-22,26);
    drawQuad(-17,36, -14,36, -14, 38,-17,38);
    drawQuad(-17,32, -14,32, -14, 34,-17,34);
    drawQuad(-17,28, -14,28, -14, 30,-17,30);
    drawQuad(-17,24, -14,24, -14, 26,-17,26);



    //9th building
    glColor3ub(0,0,0);
    drawQuad(-12,23,-2,23,-2,60,-12,60);
    glColor3ub(204, 255, 255);// window
    drawQuad(-11, 24, -9,24, -9,58,-11,58);
    drawQuad(-8, 24, -6,24, -6,58,-8,58);
    drawQuad(-5, 24, -3,24, -3,58,-5,58);


    //10th building
    glColor3ub(112,128,144);
    drawQuad(-1,23,10,23,10,60,-1,67);
    glColor3ub(204, 255, 255);// window
    drawQuad(-1,56,5,56,5,60,-1,60);
    drawQuad(7,56,9,56,9,60,7,60);
    drawQuad(10,50,4,50,4,54,10,54);
    drawQuad(0,50,2,50,2,54,0,54);
    drawQuad(-1,44,5,44,5,48,-1,48);
    drawQuad(7,44,9,44,9,48,7,48);
    drawQuad(10,38,4,38,4,42,10,42);
    drawQuad(0,38,2,38,2,42,0,42);
    drawQuad(-1,32,5,32,5,36,-1,36);
    drawQuad(7,32,9,32,9,36,7,36);
    drawQuad(10,24,4,24,4,28,10,28);
    drawQuad(-1,24,5,24,5,28,-1,28);







    //scscscsc

    //18th building

    glColor3ub(139,125,107);
    drawQuad(100,23,92,23,92,70,100,70);
    glColor3ub(204, 255, 255);// window
    drawQuad(100,65, 92,65, 92,68, 100,68);
    drawQuad(100,59, 92,59, 92,62, 100,62);
    drawQuad(100,53, 92,53, 92,56, 100,56);
    drawQuad(100,47, 92,47, 92,50, 100,50);
    drawQuad(100,41, 92,41, 92,44, 100,44);
    drawQuad(100,35, 92,35, 92,38, 100,38);
    drawQuad(100,29, 92,29, 92,32, 100,32);
    drawQuad(100,24, 92,24, 92,27, 100,27);


    //17th building
    glColor3ub(0,0,0);
    drawQuad(91,23,75,23,75,60,91,60);
    glColor3ub(204, 255, 255);// window
    drawQuad(90,56,89,56,89,58,90,58);
    drawQuad(90,52,89,52,89,54,90,54);
    drawQuad(90,48,89,48,89,50,90,50);
    drawQuad(90,44,89,44,89,46,90,46);
    drawQuad(90,40,89,40,89,42,90,42);
    drawQuad(90,36,89,36,89,38,90,38);
    drawQuad(90,32,89,32,89,34,90,34);
    drawQuad(90,28,89,28,89,30,90,30);
    drawQuad(90,24,89,24,89,26,90,26);
    drawQuad(76,56,77,56,77,58,76,58);
    drawQuad(76,52,77,52,77,54,76,54);
    drawQuad(76,48,77,48,77,50,76,50);
    drawQuad(76,44,77,44,77,46,76,46);
    drawQuad(76,40,77,40,77,42,76,42);
    drawQuad(76,36,77,36,77,38,76,38);
    drawQuad(76,32,77,32,77,34,76,34);
    drawQuad(76,28,77,28,77,28,76,30);
    drawQuad(76,24,77,24,77,24,76,26);
    drawQuad(78,56,88,56,88,58,78,58);
    drawQuad(78,52,88,52,88,54,78,54);
    drawQuad(78,48,88,48,88,50,78,50);
    drawQuad(78,44,88,44,88,46,78,46);
    drawQuad(78,40,88,40,88,42,78,42);
    drawQuad(78,36,88,36,88,38,78,38);
    drawQuad(78,32,88,32,88,34,78,34);
    drawQuad(78,28,88,28,88,30,78,30);
    drawQuad(78,24,88,24,88,26,78,26);



    //16th building
    glColor3ub(139,125,107);
    drawQuad(74,23,65,23,65,55,74,55);
    glColor3ub(204, 255, 255);// window
    drawQuad(67,49,69,49,69,53,67,53);
    drawQuad(70,49,72,49,72,53,70,53);
    drawQuad(65,45,74,45,74,47,65,47);
    drawQuad(65,41,74,41,74,43,65,43);
    drawQuad(65,37,74,37,74,39,65,39);
    drawQuad(66,23,69,23,69,35,66,35);
    glColor3ub(0, 206, 209);
    drawQuad(70,23,73,23,73,35,70,35);





    //15th building

    glColor3ub(0,0,0);
    drawQuad(64,23,54,23,54,63,64,63);
    glColor3ub(204, 255, 255);// window
    drawQuad(57,53, 59,53, 59,61, 57,61);
    drawQuad(57,43, 59,43, 59,51, 57,51);
    drawQuad(57,33, 59,33, 59,41, 57,41);
    drawQuad(57,23, 59,23, 59,31, 57,31);
    glColor3ub(0, 206, 209);
    drawQuad(59,53, 61,53, 61,61, 59,61);
    drawQuad(59,43, 61,43, 61,51, 59,51);
    drawQuad(59,33, 61,33, 61,41, 59,41);
    drawQuad(59,23, 61,23, 61,31, 59,31);




    //14th building
    glColor3ub(112,128,144);
    drawQuad(53,23,45,23,45,65,53,65);
    glColor3ub(112,128,144);
    glColor3ub(112,128,144);
    drawLine(52,66,46,66);
    drawLine(51,68,47,68);
    drawLine(50,70,48,70);
    glColor3ub(204, 255, 255);// window
    drawQuad(47,53,51,53,51,63,47,63);
    drawQuad(46,40,48,40,48,46,46,46);
    drawQuad(50,40,52,40,52,46,50,46);
    drawQuad(45,34,49,34,49,38,45,38);

    //drawQuad(45,36,53,36,53,38,45,38);
    drawQuad(45,31,53,31,53,33,45,33);
    drawQuad(45,28,53,28,53,30,45,30);
    drawQuad(45,24,53,24,53,26,45,26);
    glColor3ub(0, 206, 209);
    drawQuad(47,47,51,47,51,53,47,53);
    drawQuad(49,34,53,34,53,38,49,38);
    drawQuad(46,40,48,40,48,46,46,46);



    //13th building

    glColor3ub(0,0,0);
    drawQuad(44,23,36,23,36,60,44,53);
    glColor3ub(204, 255, 255);// window
    drawQuad(37,53,38,53,38,58,37,58);
    drawQuad(37,50,38,50,38,52,37,52);
    drawQuad(42,48,43,48,43,53,42,53);
    drawQuad(42,45,43,45,43,47,42,47);
    drawQuad(39,44,40,44,40,40,39,40);
    drawQuad(39,37,40,37,40,39,39,39);
    drawQuad(36,34,44,34,44,36,36,36);
    drawQuad(36,31,44,31,44,33,36,33);
    drawQuad(36,28,44,28,44,30,36,30);
    drawQuad(36,24,44,24,44,27,36,27);



    //12th building

    glColor3ub(139,125,107);
    drawQuad(34,23,25,23,25,70,34,70);
    glColor3ub(204, 255, 255);// window
    drawQuad(26,66,27,66,27,68,26,68);
    drawQuad(29,66,30,66,30,68,29,68);
    drawQuad(32,66,33,66,33,68,32,68);

    drawQuad(26,62,27,62,27,64,26,64);
    drawQuad(29,62,30,62,30,64,29,64);
    drawQuad(32,62,33,62,33,64,32,64);

    drawQuad(26,58,27,58,27,60,26,60);
    drawQuad(29,58,30,58,30,60,29,60);
    drawQuad(32,58,33,58,33,60,32,60);

    drawQuad(26,54,27,54,27,56,26,56);
    drawQuad(29,54,30,54,30,56,29,56);
    drawQuad(32,54,33,54,33,56,32,56);

     drawQuad(26,50,27,50,27,52,26,52);
    drawQuad(29,50,30,50,30,52,29,52);
    drawQuad(32,50,33,50,33,52,32,52);

    drawQuad(26,46,27,46,27,48,26,48);
    drawQuad(29,46,30,46,30,48,29,48);
    drawQuad(32,46,33,46,33,48,32,48);

    drawQuad(26,42,27,42,27,44,26,44);
    drawQuad(29,42,30,42,30,44,29,44);
    drawQuad(32,42,33,42,33,44,32,44);

    drawQuad(26,38,27,38,27,40,26,40);
    drawQuad(29,38,30,38,30,40,29,40);
    drawQuad(32,38,33,38,33,40,32,40);

    drawQuad(26,34,27,34,27,36,26,36);
    drawQuad(29,34,30,34,30,36,29,36);
    drawQuad(32,34,33,34,33,36,32,36);

    drawQuad(26,30,27,30,27,32,26,32);
    drawQuad(29,30,30,30,30,32,29,32);
    drawQuad(32,30,33,30,33,32,32,32);

    drawQuad(26,26,27,26,27,28,26,28);
    drawQuad(29,26,30,26,30,28,29,28);
    drawQuad(32,26,33,26,33,28,32,28);

    drawQuad(26,24,27,24,27,26,26,26);
    drawQuad(29,24,30,24,30,26,29,26);
    drawQuad(32,24,33,24,33,26,32,26);




    //11th building

    glColor3ub(105,105,105);
    drawQuad(23,23,11,23,11,60,23,60);
    glColor3ub(204, 255, 255);// window
    drawQuad(12,56,18,56,18,58,12,58);
    drawQuad(12,52,18,52,18,54,12,54);
    drawQuad(12,48,18,48,18,50,12,50);
    drawQuad(12,44,18,44,18,46,12,46);
    drawQuad(12,40,18,40,18,42,12,42);
    drawQuad(12,36,18,36,18,38,12,38);
    drawQuad(12,32,18,32,18,34,12,34);
    drawQuad(12,28,18,28,18,30,12,30);
    drawQuad(12,24,18,24,18,26,12,26);

    glColor3ub(0, 206, 209);
    drawQuad(18,56,22,56,22,58,18,58);
    drawQuad(18,52,22,52,22,54,18,54);
    drawQuad(18,48,22,48,22,50,18,50);
    drawQuad(18,44,22,44,22,46,18,46);
    drawQuad(18,40,22,40,22,42,18,42);
    drawQuad(18,36,22,36,22,38,18,38);
    drawQuad(18,32,22,32,22,34,18,34);
    drawQuad(18,28,22,28,22,30,18,30);
    drawQuad(18,24,22,24,22,26,18,26);


}

void car1()
{
    glPushMatrix();
    glTranslatef(position_car_1, 0.0f,0.0f);
//car 1
glColor3ub(239,119,43);
glBegin(GL_POLYGON);
glVertex2f(7.0f, -48.0f); //8
glVertex2f(13.0f, -48.0f); //7
glVertex2f(14.0f, -42.0f); //6
glVertex2f(19.0f, -42.0f); //5
glVertex2f(21.0f,-48.0f); //4
glVertex2f(24.0f,-48.0f); //3
glVertex2f(24.0f,-42.0f);
glVertex2f(22.0f, -42.0f);
glVertex2f(20.0f, -38.0f);
glVertex2f(15.0f, -38.0f);
glVertex2f(13.0f, -42.0f);
glVertex2f(7.0f, -42.0f);
glEnd();

 //car 1 detail
glColor3ub(155, 209, 225);
drawQuad(12,-46,22,-46,20,-42,15,-42);
drawQuad(12,-46,15,-42,15,-38,12,-42);
drawQuad(20,-42,22,-46,22,-42,20,-38);

 glLineWidth(2);
glColor3ub(0, 0, 0);
drawLine(12,-46,22,-46);
drawLine(22,-46,20,-42);
drawLine(20,-42,15,-42);
drawLine(12,-46,15,-42);
drawLine(18,-48,18,-42);

 drawLine(15,-42,15,-38);
drawLine(15,-38,12,-42);
drawLine(12,-42,12,-46);

 drawLine(22,-46,22,-42);
drawLine(22,-42,20,-38);
drawLine(20,-38,20,-42);
//car 1 wheel
glColor3ub(0,0,0);
DrawCircle(12,-48,2,200);
DrawCircle(20,-48,2,200);
glColor3ub(210,224,237);
DrawCircle(12,-48,1,200);
DrawCircle(20,-48,1,200);
glPopMatrix();
}

void car2()
{
//car 2
glPushMatrix();
    glTranslatef(position_car_3, 0.0f,0.0f);

glColor3ub(209,222,230);
glBegin(GL_POLYGON);
glVertex2f(-45.0f, -32.0f); //8
glVertex2f(-27.0f, -32.0f); //7
glVertex2f(-27.0f, -25.0f); //6
glVertex2f(-30.0f, -25.0f); //6
glVertex2f(-32.0f, -22.0f); //5
glVertex2f(-37.0f, -22.0f); //4
glVertex2f(-40.0f, -25.0f); //3
glVertex2f(-45.0f,- 25.0f);
glEnd();

 //car 2 detail
glColor3ub(155, 209, 225);
drawQuad(-40,-29,-30,-29,-32,-25,-37,-25);
drawQuad(-40,-29,-37,-25,-37,-22,-40,-25);
drawQuad(-30,-29,-32,-25,-32,-22,-30,-25);

 glLineWidth(2);
glColor3ub(0, 0, 0);
drawLine(-40,-29,-30,-29);
drawLine(-30,-29,-32,-25);
drawLine(-32,-25,-37,-25);
drawLine(-37,-25,-40,-29);
drawLine(-34,-32,-34,-25);//vertical

 drawLine(-37,-25,-37,-22);
drawLine(-37,-22,-40,-25);
drawLine(-40,-25,-40,-29);

 drawLine(-32,-25,-32,-22);
drawLine(-32,-22,-30,-25);
drawLine(-37,-22,-32,-22);

 //car 2 wheel
glColor3ub(0,0,0);
DrawCircle(-30,-32,2,100);
DrawCircle(-40,-32,2,100);
glColor3ub(210,224,237);
DrawCircle(-30,-32,1,100);
DrawCircle(-40,-32,1,100);
glPopMatrix();
}

void car3()
{
    glPushMatrix();
    glTranslatef(position_car_2, 0.0f,0.0f);
//car 3
glColor3ub(59,137,213);
glBegin(GL_POLYGON);
glVertex2f(-77.0f, 7.0f); //8
glVertex2f(-60.0f, 7.0f); //7
glVertex2f(-60.0f, 10.0f); //6
glVertex2f(-65.0f, 10.0f); //6
glVertex2f(-68.0f, 12.0f); //5
glVertex2f(-72.0f, 12.0f); //4
glVertex2f(-74.0f, 10.0f); //3
glVertex2f(-77.0f, 10.0f);
glEnd();
//car 3 detail
glColor3ub(155, 209, 225);
drawQuad(-74.0, 10.0,-65.0, 10.0,-68.0, 12.0,-72.0, 12.0);

 glLineWidth(2);
glColor3ub(0,0,0);
drawLine(-74.0, 10.0,-65.0, 10.0);
drawLine(-65.0, 10.0,-68.0, 12.0);
drawLine(-68.0, 12.0,-72.0, 12.0);
drawLine(-68.0, 12.0,-72.0, 12.0);
drawLine(-70,7,-70,12);
//car 3 wheel
glColor3ub(0,0,0);
DrawCircle(-74,7,1.5,200);
DrawCircle(-65,7,1.5,200);
glColor3ub(210,224,237);
DrawCircle(-74,7,1,200);
DrawCircle(-65,7,1,200);
glPopMatrix();
}
void car4()
{
//car 4

glPushMatrix();
    glTranslatef(position_car_4, 0.0f,0.0f);
glColor3ub(149,204,202);
glBegin(GL_POLYGON);
glVertex2f(20.0f, -8.0f); //8
glVertex2f(37.0f, -8.0f); //7
glVertex2f(37.0f, -5.0f); //6
glVertex2f(32.0f, -5.0f); //6
glVertex2f(29.0f, -2.0f); //5
glVertex2f(25.0f, -2.0f); //4
glVertex2f(23.0f, -5.0f); //3
glVertex2f(20.0f, -5.0f);
glEnd();
//car 4 detail
glColor3ub(155, 209, 225);
drawQuad(23.0,-5.0,32.0,-5.0,29.0,-2.0,25.0,-2.0);
glLineWidth(2);
glColor3ub(0,0,0);
drawLine(23.0,-5.0,32.0,-5.0);
drawLine(32.0,-5.0,29.0,-2.0);
drawLine(25.0,-2.0,23.0,-5.0);
drawLine(25.0,-2.0,23.0,-5.0);
drawLine(27.0,-2.0,27.0,-8.0);
//car 4 wheel
glColor3ub(0,0,0);
DrawCircle(23,-8,1.5,200);
DrawCircle(32,-8,1.5,200);
glColor3ub(210,224,237);
DrawCircle(23,-8,1,200);
DrawCircle(32,-8,1,200);
glPopMatrix();
}

void trainOver()
{
    glPushMatrix();
    glTranslatef(position_5, 0.0f,0.0f);
    //train body
    glColor3ub(234,235,239);
    drawQuad(-95,26,-20,26,-20,36.5,-95,36.5);

    //train head
    glColor3ub(234,235,239);
    glBegin(GL_POLYGON);
    glVertex2f(-20.0f, 26.0f);
    glVertex2f(-8.0f, 26.0f);
    glVertex2f(-8.0f,31.0f);
    glVertex2f(-12.0f,36.0f);
    glVertex2f(-20.0f, 36.0f);
    glEnd();

     //train head door
    glColor3ub(131,132,127);
    drawQuad(-19,27,-17.25,27,-17.25,35.5,-19,35.5);

    //train head window
    glColor3ub(155, 209, 225);
    drawQuad(-15.5,31,-9.8,31,-12,35,-15.5,35);

    //train compartment doors
    glColor3ub(131,132,127);
    drawQuad(-44,27,-42.25,27,-42.25,35.5,-44,35.5);
    drawQuad(-48,27,-46.0,27,-46.0,35.5,-48,35.5);
    drawQuad(-73,27,-71.25,27,-71.25,35.5,-73,35.5);

    //train compartment windows
    glColor3ub(155, 209, 225);
    drawQuad(-41,30.5,-21.0,30.5,-21.0,35.5,-41.25,35.5);
    drawQuad(-69,30.5,-49.0,30.5,-49.0,35.5,-69.25,35.5);
    drawQuad(-93.5,30.5,-74.0,30.5,-74.0,35.5,-93.50,35.5);

    //decorate red line
    glLineWidth(4);
    glColor3ub(170,3,3);
    drawLine(-95,36.5,-12,36.5);
    drawLine(-12,36.5,-8,31);
    drawLine(-8,31,-8,26);
    drawLine(-95,36.5,-95,32);

    //decorate green line
    glLineWidth(4);
    glColor3ub(23,143,82);
    drawLine(-95,26,-8,26);
    drawLine(-95,26,-95,32);

    //compartment line
    glLineWidth(5);
    glColor3ub(0, 0, 0);
    drawLine(-70,26,-70,36.5);
    glColor3ub(0, 0, 0);
    drawLine(-45,26,-45,36.5);
    glColor3ub(0, 0, 0);
    drawLine(-20,26,-20,36.5);
    glPopMatrix();

}

void trainUnder()
{
    glPushMatrix();
    glTranslatef(position_6, 0.0f,0.0f);
    //train body
    glColor3ub(234,235,239);
    drawQuad(95,29.5,20,29.5,20,38.5,95,38.5);

    //train head
    glColor3ub(234,235,239);
    glBegin(GL_POLYGON);
    glVertex2f(20.0f, 29.0f);
    glVertex2f(8.0f, 29.0f);
    glVertex2f(8.0f,33.0f);
    glVertex2f(12.0f,38.0f);
    glVertex2f(20.0f, 38.0f);
    glEnd();

    //train head door
    glColor3ub(131,132,127);
    drawQuad(19,30,17.25,30,17.25,37,19,37);

    //train head window
    glColor3ub(155, 209, 225);
    drawQuad(9.8,33,16,33,16,37,12,37);

    //train compartment doors
    glColor3ub(131,132,127);
    drawQuad(44,30,42.25,30,42.25,37,44,37);
    drawQuad(48,30,46.0,30,46.0,37,48,37);
    drawQuad(73,30,71.25,30,71.25,37,73,37);

    //train compartment windows
    glColor3ub(155, 209, 225);
    drawQuad(41,33,21.0,33,21.0,37.0,41.25,37);
    drawQuad(69,33,49.0,33,49.0,37,69.25,37);
    drawQuad(93.5,33,74.0,33,74.0,37,93.50,37);

    //decorate red line
    glLineWidth(4);
    glColor3ub(170,3,3);
    drawLine(95,38,12,38);
    drawLine(12,38,8,33);
    drawLine(8,33,8,29);
    drawLine(95,38,95,32);

    //decorate green line
    glLineWidth(4);
    glColor3ub(23,143,82);
    drawLine(95,29,8,29);
    drawLine(95,29,95,33);

    //compartment line
    glLineWidth(3);
    glColor3ub(0, 0, 0);
    drawLine(70,29.5,70,38.5);
    glColor3ub(0, 0, 0);
    drawLine(45,29.5,45,38.5);
    glColor3ub(0, 0, 0);
    drawLine(20,29.5,20,38.5);
    glPopMatrix();
}


void display()
{

    if(status==0){
        road();
        sky(135,206,255);
        sun(255,255,0);

        background_clouds(245, 245, 245);
        background_buildings();
        car1();
        car2();
        car3();
        car4();
        footpath();
        light1(204, 255, 255);

        forward_clouds(245, 245, 245);
        front_buildings();
        light2(204, 255, 255);
        platform();
        trainUnder();
        trainOver();
        ground();
        glutIdleFunc(day);
    }

    if(status==1){

        road();
        sky(190,190,190);
        background_clouds(105, 105, 105);
        background_buildings();
        car1();
        car2();
        car3();
        car4();
        footpath();
        light1(255,255,0);
        forward_clouds(87, 87, 87);
        front_buildings();
        light2(255,255,0);
        platform();
        trainUnder();
        trainOver();
        ground();
    }
    if(status==2){

        road();
        sky(0,0,128);
        star();
        moon(255,255,0);
        background_clouds(211, 211, 211);
        car1();
        car2();
        car3();
        car4();
        footpath();
        light1(255,255,0);
        forward_clouds(211, 211, 211);
        front_buildings();
        light2(255,255,0);
        platform();
        trainUnder();
        trainOver();
        ground();
    }

glFlush ();

}

void keyboard(unsigned char key, int x, int y){
if (key == 'C' || key == 'c'){
status = 0;
glutIdleFunc(day);
}
if (key == 'A' || key == 'a'){
status = 1;
glutIdleFunc(rainy);
}
if (key == 'B' || key == 'b'){
status = 2;
glutIdleFunc(night);
}
glutPostRedisplay();
}

void myInit (void)
{
glClearColor(1., 1., 1.0, 1.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0,1000.0,0.0,1000.0);
}

int main(int argc, char** argv)
{

glutInit(&argc, argv); // Initialize GLUT
glutCreateWindow("Metro Rail"); // Create a window with the given title
glutInitWindowSize(1920, 1080);
gluOrtho2D(-100,100,-100,100); // Set the window's initial width & height

glutDisplayFunc(display); // Register display callback handler for window re-paint
glutKeyboardFunc(keyboard);
glutMainLoop(); // Enter the event-processing loop
myInit ();
return 0;
}

