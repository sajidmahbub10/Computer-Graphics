#include <iostream>
#include<cstdio>
#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
#include<Windows.h>
#include<MMSystem.h>
#include<iostream>
GLfloat position = 1.2f;
GLfloat position2 = -0.2f;
GLfloat position3 = 2.5f;
GLfloat position4 = 0.0f;
GLfloat position5 = 1.2f;
GLfloat position6 = -1.5f;
GLfloat position7 = 0.0f;
GLfloat speed = 0.025f;
GLfloat speed2 = 0.02f;
GLfloat speed3 = 0.01f;
GLfloat speed4 = 0.032f;
GLfloat speed5 = 0.029;
GLfloat a =0.0f;
int r=135;int g=206;int b=250;int n;
int s=127;int e=234;int m=230;
int l=19;int i=30;int h=100;
int k=0,o=0;
bool onOff;
bool rainday = false;
float _rain = 0.0f;
int wave_count=1;
GLfloat flagPos_X=0.35f;
GLfloat flagPos_Y=0.55f;
GLfloat flagPos_Y2=0.40f,
circlePos_Y=0.475f,
circlePos_X=0.270f;

//GLfloat rain_position1 = -0.10f;
//GLfloat rain_speed1 = 0.1f;
//GLfloat rain_position2 = -0.10f;
//GLfloat rain_speed2 = 0.1f;
/*void rain_update1(int value) {
    if(rain_position1 <-1.0)
    rain_position1 = 1.0f;
    rain_position1 -= rain_speed1;
	glutPostRedisplay();
	glutTimerFunc(200, rain_update1, 0);
}
void rain_update2(int value) {
    if(rain_position2 <-1.0)
    rain_position2 = 1.0f;
    rain_position2 -= rain_speed2;
	glutPostRedisplay();
	glutTimerFunc(100, rain_update2, 0);
}*/

void update(int value) {
    if(position > 1.2f)
    position = -2.0f;
    position += speed;
	glutPostRedisplay();
	glutTimerFunc(100, update, 0);
}
void updateSun(int value) {
    if(position2 > 0.7f)
    speed2=0.0f;
    else
    position2 += speed2;
	glutPostRedisplay();
	glutTimerFunc(100, updateSun, 0);
}
void updateCloud1(int value) {
    if(position3 > 1.2f)
    position3=-1.8f;
    position3 += speed3;
	glutPostRedisplay();
	glutTimerFunc(100, updateCloud1, 0);
}
void updateFlag(int value){
    if(wave_count>=1){
    flagPos_X=flagPos_X+0.015f;
    flagPos_Y2=flagPos_Y2+0.005f;
    flagPos_Y=flagPos_Y-0.01f;
    circlePos_Y=circlePos_Y-0.012f;
    circlePos_X=circlePos_X+0.015f;
    wave_count--;
    }
    else{
    flagPos_X=0.35f;
    flagPos_Y2=flagPos_Y2-0.005f;
    flagPos_Y=flagPos_Y+0.01f;
    circlePos_Y=circlePos_Y+0.012f;
    circlePos_X=circlePos_X-0.015f;
    wave_count++;
    }
    glutPostRedisplay();
    glutTimerFunc(800,updateFlag,0);
}
void init() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}
void handleMouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON)
	{
		if (state == GLUT_DOWN)
		{
			speed += 0.1f;
			printf("clicked at (%d, %d)\n", x, y);
		}
	}
	glutPostRedisplay();
}
void updateCar(int value) {
    if(position5 > 1.2f)
    position5 = -2.0f;
    position5 += speed4;
	glutPostRedisplay();
	glutTimerFunc(100, updateCar, 0);
}
void updateCar2(int value) {
    if(position6 < -2.0)
    position6 = 1.2f;
    position6 -= speed5;
	glutPostRedisplay();
	glutTimerFunc(100, updateCar2, 0);
}
void human(int value) {
    if(position7 < -2.0)
    position7 = 2.0f;
    position7 -= speed5;
	glutPostRedisplay();
	glutTimerFunc(100, human, 0);
}
void Rain(int value){
    if(rainday){
    _rain += 0.5f;
    glBegin(GL_POINTS);
    for(int i=1;i<=5000;i++)
    {
        int x=rand(),y=rand();
        x%=1000; y%=1000;
        glBegin(GL_LINES);
        glColor3f(1.0, 1.0, 1.0);
        glVertex2d(x,y);
        glVertex2d(x-3,y-3);
        glEnd();
    }
	glutPostRedisplay();
	glutTimerFunc(10, Rain, 0);
    glFlush();

}
}
void handleKeypress(unsigned char key, int x, int y) {
	switch (key) {
case 'a':
    speed= 0.0f;
    break;
case 'w':
    speed += 0.01f;
    break;
    case 'q':
    speed -= 0.01f;
    break;
case 'n':
     r=25;
     g=25;
     b=112;
     position2=-0.2;
     speed2=0.02;
     n=255;
     s=0;
     e=105;
     m=148;
     l=255;
     i=255;
     h=0;
     k=255;
     o=255;
     break;
case 'd':
     r=135;
     g=206;
     b=250;
     position2=-0.2;
     position3=-0.2;
     speed2=0.02;
     n=0;
     s=127;
     e=234;
     m=230;
     l=19;
     i=30;
     h=100;
     k=0;
     o=0;
     break;
case 'r':
    rainday = true;
    r=25;
    g=25;
    b=112;
    Rain(_rain);
    sndPlaySound("rain.wav",SND_ASYNC|SND_LOOP);
    break;
case 's':
    rainday = false;
    sndPlaySound(NULL,SND_ASYNC);
    sndPlaySound("PurboDigonte.wav",SND_ASYNC|SND_LOOP);
    break;
case 27:     // ESC key
    exit(0);
    break;
	default:
	break;
	}
glutPostRedisplay();
	}
void display() {
   glClear(GL_COLOR_BUFFER_BIT);
   glLoadIdentity();

//********************************Sky***********************************//
    glPushMatrix();
    glTranslatef(a,0.0f, 0.0f);
    glBegin(GL_POLYGON);//SKY
    glColor3ub(r,g,b);
    glVertex2f(1.0f, 0.0f);
    glVertex2f(1.0f, 1.0f);
    glVertex2f(-1.0f, 1.0f);
    glVertex2f(-1.0f, 0.0f);
    glEnd();
    glPopMatrix();
//****************************************************************//

//***************************Sun & Moon*************************//

    glPushMatrix();
    glTranslatef(0.4f,position2, 0.0f);
    glColor3ub(255,255,n);
    glutSolidSphere(0.15,30,15);
    glPopMatrix();

//****************************************************************//

  glBegin(GL_TRIANGLES);//.........................................Tree
      glColor3ub(52 ,176 ,21);
      glVertex2f(-0.85f, 0.7f);
      glVertex2f(-0.9f, 0.6f);
      glVertex2f(-0.8f, 0.6f);
   glEnd();

      glBegin(GL_QUADS);
      glColor3ub(52 ,176 ,21);
      glVertex2f(-0.875, 0.6f);
      glVertex2f(-0.9f, 0.5f);
      glVertex2f(-0.8f, 0.5f);
      glVertex2f(-0.825f, 0.6f);

      glColor3ub(52 ,176 ,21);
      glVertex2f(-0.875, 0.5f);
      glVertex2f(-0.9f, 0.4f);
      glVertex2f(-0.8f, 0.4f);
      glVertex2f(-0.825f, 0.5f);
    glEnd();
      glBegin(GL_QUADS);
      glColor3ub(122 ,80 ,60);
      glVertex2f(-.86f, 0.4f);
      glVertex2f(-.86f, 0.2f);
      glVertex2f(-.84f, 0.2f);
      glVertex2f(-.84f, 0.4f);

      glEnd();

      glBegin(GL_TRIANGLES);//...............................................Tree
      glColor3ub(52 ,176 ,21);
      glVertex2f(-0.15f, 0.6f);
      glVertex2f(-0.2f, 0.5f);
      glVertex2f(-0.1f, 0.5f);
   glEnd();

      glBegin(GL_QUADS);
      glColor3ub(52 ,176 ,21);
      glVertex2f(-0.175, 0.5f);
      glVertex2f(-0.2f, 0.4f);
      glVertex2f(-0.1f, 0.4f);
      glVertex2f(-0.125f, 0.5f);

      glColor3ub(52 ,176 ,21);
      glVertex2f(-0.175, 0.4f);
      glVertex2f(-0.2f, 0.3f);
      glVertex2f(-0.1f, 0.3f);
      glVertex2f(-0.125f, 0.4f);
    glEnd();
      glBegin(GL_QUADS);
      glColor3ub(122 ,80 ,60);
      glVertex2f(-.16f, 0.3f);
      glVertex2f(-.16f, 0.1f);
      glVertex2f(-.14f, 0.1f);
      glVertex2f(-.14f, 0.3f);

      glEnd();


      glBegin(GL_TRIANGLES);//........................................Tree
      glColor3ub(52 ,176 ,21);
      glVertex2f(0.6f, 0.6f);
      glVertex2f(0.55f, 0.5f);
      glVertex2f(0.65f, 0.5f);
   glEnd();

      glBegin(GL_QUADS);
      glColor3ub(52 ,176 ,21);
      glVertex2f(0.575, 0.5f);
      glVertex2f(0.55f, 0.4f);
      glVertex2f(0.65f, 0.4f);
      glVertex2f(0.625f, 0.5f);

      glColor3ub(52 ,176 ,21);
      glVertex2f(0.575, 0.4f);
      glVertex2f(0.55f, 0.3f);
      glVertex2f(0.65f, 0.3f);
      glVertex2f(0.625f, 0.4f);
    glEnd();
      glBegin(GL_QUADS);
      glColor3ub(122 ,80 ,60);
      glVertex2f(.59f, 0.3f);
      glVertex2f(.59f, 0.1f);
      glVertex2f(.61f, 0.1f);
      glVertex2f(.61f, 0.3f);

      glEnd();


    glBegin(GL_TRIANGLES);//.......................................Tree
      glColor3ub(52 ,176 ,21);
      glVertex2f(0.9f, 0.6f);
      glVertex2f(0.85f, 0.5f);
      glVertex2f(0.95f, 0.5f);
   glEnd();

      glBegin(GL_QUADS);
      glColor3ub(52 ,176 ,21);
      glVertex2f(0.875, 0.5f);
      glVertex2f(0.85f, 0.4f);
      glVertex2f(0.95f, 0.4f);
      glVertex2f(0.925f, 0.5f);

      glColor3ub(52 ,176 ,21);
      glVertex2f(0.875, 0.4f);
      glVertex2f(0.85f, 0.3f);
      glVertex2f(0.95f, 0.3f);
      glVertex2f(0.925f, 0.4f);
    glEnd();
      glBegin(GL_QUADS);
      glColor3ub(122 ,80 ,60);
      glVertex2f(.89f, 0.3f);
      glVertex2f(.89f, 0.2f);
      glVertex2f(.91f, 0.2f);
      glVertex2f(.91f, 0.3f);

      glEnd();


//*******************************************//

   glBegin(GL_POLYGON);//Mountains 134 201 100
   glColor3ub(134,201,100);
   glVertex2f(1.2f, 0.0f);
   glVertex2f(0.97f, 0.4f);
   glVertex2f(0.8f, 0.0f);
   glEnd();
   glBegin(GL_POLYGON);//Mountains small 134,201,100
   glColor3ub(134,201,100);
   glVertex2f(1.0f, 0.0f);
   glVertex2f(0.8f, 0.6f);
   glVertex2f(0.6f, 0.0f);
   glEnd();

//*******************************************//
   glBegin(GL_TRIANGLES);//.........................................Tree
      glColor3ub(52 ,176 ,21);
      glVertex2f(0.8f, 0.3f);
      glVertex2f(0.75f, 0.07f);
      glVertex2f(0.85f, 0.07f);
   glEnd();

      glBegin(GL_QUADS);
      glColor3ub(122 ,80 ,60);
      glVertex2f(.79f, 0.07f);
      glVertex2f(.79f, 0.0f);
      glVertex2f(.81f, 0.0f);
      glVertex2f(.81f, 0.07f);

      glEnd();
//*******************************************//

   glBegin(GL_POLYGON);//Mountains 96,142,107
   glColor3ub(96,142,107);
   glVertex2f(0.7f, 0.0f);
   glVertex2f(0.55f, 0.4f);
   glVertex2f(0.4f, 0.0f);
   glEnd();
   glBegin(GL_POLYGON);//Mountains small 96 142 107
   glColor3ub(96,142,107);
   glVertex2f(.45f, 0.0f);
   glVertex2f(0.35f, 0.3f);
   glVertex2f(0.25f, 0.0f);
   glEnd();

   //*******************************************//
    glBegin(GL_TRIANGLES);//..............................................Tree
      glColor3ub(52 ,176 ,21);
      glVertex2f(0.4f, 0.25f);
      glVertex2f(0.35f, 0.05f);
      glVertex2f(0.45f, 0.05f);
   glEnd();

      glBegin(GL_QUADS);
      glColor3ub(122 ,80 ,60);
      glVertex2f(.39f, 0.05f);
      glVertex2f(.39f, 0.0f);
      glVertex2f(.41f, 0.0f);
      glVertex2f(.41f, 0.05f);

      glEnd();
   //*******************************************//

   glBegin(GL_POLYGON);//Mountains small 134 201 100
   glColor3ub(134,201,100);
   glVertex2f(.3f, 0.0f);
   glVertex2f(0.15f, 0.4f);
   glVertex2f(0.0f, 0.0f);
   glEnd();
   glBegin(GL_POLYGON);//Mountains medium 134 201 100
   glColor3ub(134,201,100);
   glVertex2f(.1f, 0.0f);
   glVertex2f(-.05f, 0.45f);
   glVertex2f(-.2f, 0.0f);
   glEnd();

   glBegin(GL_POLYGON);//Mountains
   glColor3ub(96,142,107);
   glVertex2f(-.055f, 0.0f);
   glVertex2f(-0.325f, 0.6f);
   glVertex2f(-.55f, 0.0f);
   glEnd();

   //*******************************************//
    glBegin(GL_TRIANGLES);//..........................................Tree
      glColor3ub(52 ,176 ,21);
      glVertex2f(-0.45f, 0.5f);
      glVertex2f(-0.5f, 0.4f);
      glVertex2f(-0.4f, 0.4f);
   glEnd();

      glBegin(GL_QUADS);
      glColor3ub(52 ,176 ,21);
      glVertex2f(-0.475, 0.4f);
      glVertex2f(-0.5f, 0.3f);
      glVertex2f(-0.4f, 0.3f);
      glVertex2f(-0.425f, 0.4f);

      glColor3ub(52 ,176 ,21);
      glVertex2f(-0.475, 0.3f);
      glVertex2f(-0.5f, 0.2f);
      glVertex2f(-0.4f, 0.2f);
      glVertex2f(-0.425f, 0.3f);
    glEnd();

      glBegin(GL_QUADS);
      glColor3ub(122 ,80 ,60);
      glVertex2f(-.46f, 0.2f);
      glVertex2f(-.46f, 0.0f);
      glVertex2f(-.44f, 0.0f);
      glVertex2f(-.44f, 0.2f);

      glEnd();
   //*******************************************//
   glBegin(GL_POLYGON);//Mountains
   glColor3ub(96,142,107);
   glVertex2f(-.45f, 0.0f);
   glVertex2f(-0.6f, 0.4f);
   glVertex2f(-.75f, 0.0f);
   glEnd();

   glBegin(GL_POLYGON);//Mountains
   glColor3ub(134,201,100);
   glVertex2f(-.65f, 0.0f);
   glVertex2f(-0.8f, 0.45f);
   glVertex2f(-.95f, 0.0f);
   glEnd();


   //*******************************************//
   glBegin(GL_TRIANGLES);//.................................................Tree
      glColor3ub(52 ,176 ,21);
      glVertex2f(-0.7f, 0.3f);
      glVertex2f(-0.75f, 0.07f);
      glVertex2f(-0.65f, 0.07f);
   glEnd();

      glBegin(GL_QUADS);
      glColor3ub(122 ,80 ,60);
      glVertex2f(-.71f, 0.07f);
      glVertex2f(-.71f, 0.0f);
      glVertex2f(-.69f, 0.0f);
      glVertex2f(-.69f, 0.07f);

      glEnd();
//*******************************************//

   glBegin(GL_POLYGON);//Mountains small 96 142 107
   glColor3ub(134,201,100);
   glVertex2f(-.8f, 0.0f);
   glVertex2f(-0.95f, 0.55f);
   glVertex2f(-1.1f, 0.0f);
   glEnd();
   glBegin(GL_POLYGON);//Fornt
   glColor3ub(s,e,m);
   glVertex2f(1.0f, -0.0f);
   glVertex2f(1.0f, -1.0f);
   glVertex2f(-1.0f, -1.0f);
   glVertex2f(-1.0f, -0.0f);
   glEnd();
   glPushMatrix();

//************************************************Lamp(From Left to Right)***********************//
       glBegin(GL_POLYGON);//lamp 1 stand
       glColor3ub(193 ,205 ,193);
       glVertex2f(.910f, 0.15f);
       glVertex2f(.910f, 0.0f);
       glVertex2f(.9f, 0.0f);
       glVertex2f(.9f, 0.15f);
       glEnd();
       glBegin(GL_QUADS);//lamp 1 top
       glColor3ub(k,o,10);
       glVertex2f(.90f, 0.15f);
       glVertex2f(.91f, 0.15f);
       glVertex2f(.93f, 0.2f);
       glVertex2f(.880f, 0.2f);
       glEnd();
       glBegin(GL_POLYGON);//lamp 2 stand
       glColor3ub(210,210,210);
       glVertex2f(.610f, 0.15f);
       glVertex2f(.610f, 0.0f);
       glVertex2f(.6f, 0.0f);
       glVertex2f(.6f, 0.15f);
       glEnd();
       glBegin(GL_POLYGON);//lamp 2 top
       glColor3ub(k,o,10);
       glVertex2f(.580f, 0.2f);
       glVertex2f(.60f, 0.15f);
       glVertex2f(.61f, 0.15f);
       glVertex2f(.63f, 0.2f);
       glEnd();
       glBegin(GL_POLYGON);//lamp 3 stand
       glColor3ub(193 ,205 ,193);
       glVertex2f(.310f, 0.15f);
       glVertex2f(.310f, 0.0f);
       glVertex2f(.3f, 0.0f);
       glVertex2f(.3f, 0.15f);
       glEnd();
        glBegin(GL_POLYGON);//lamp 3 top
        glColor3ub(k,o,10);
        glVertex2f(.280f, 0.2f);
        glVertex2f(.30f, 0.15f);
        glVertex2f(.31f, 0.15f);
        glVertex2f(.33f, 0.2f);
        glEnd();
        glBegin(GL_POLYGON);//lamp 4 stand
        glColor3ub(193 ,205 ,193);
        glVertex2f(-.310f, 0.15f);
        glVertex2f(-.310f, 0.0f);
        glVertex2f(-.30f, 0.0f);
        glVertex2f(-.30f, 0.15f);
        glEnd();
        glBegin(GL_POLYGON);//lamp 4 top
        glColor3ub(k,o,10);
        glVertex2f(-.280f, 0.2f);
        glVertex2f(-.30f, 0.15f);
        glVertex2f(-.31f, 0.15f);
        glVertex2f(-.33f, 0.2f);
        glEnd();
        glBegin(GL_POLYGON);//lamp 5 stand
        glColor3ub(210,210,210);
        glVertex2f(-.610f, 0.15f);
        glVertex2f(-.610f, 0.0f);
        glVertex2f(-.60f, 0.0f);
        glVertex2f(-.60f, 0.15f);
        glEnd();
        glBegin(GL_POLYGON);//lamp 5 top
        glColor3ub(k,o,10);
        glVertex2f(-.580f, 0.2f);
        glVertex2f(-.60f, 0.15f);
        glVertex2f(-.61f, 0.15f);
        glVertex2f(-.63f, 0.2f);
        glEnd();
        glBegin(GL_POLYGON);//lamp 6 stand
        glColor3ub(193 ,205 ,193);
        glVertex2f(-.910f, 0.15f);
        glVertex2f(-.910f, 0.0f);
        glVertex2f(-.90f, 0.0f);
        glVertex2f(-.90f, 0.15f);
        glEnd();
        glBegin(GL_POLYGON);//lamp 6 top
        glColor3ub(k,o,10);
        glVertex2f(-.880f, 0.2f);
        glVertex2f(-.90f, 0.15f);
        glVertex2f(-.91f, 0.15f);
        glVertex2f(-.93f, 0.2f);
        glEnd();
        glPopMatrix();

//***********************************************************************************//

//********************************************Tree***********************************//
      glBegin(GL_TRIANGLES);//.........................................Tree
      glColor3ub(52 ,176 ,21);
      glVertex2f(0.8f, 0.3f);
      glVertex2f(0.75f, 0.07f);
      glVertex2f(0.85f, 0.07f);
      glEnd();
      glBegin(GL_QUADS);
      glColor3ub(122 ,80 ,60);
      glVertex2f(.79f, 0.07f);
      glVertex2f(.79f, 0.0f);
      glVertex2f(.81f, 0.0f);
      glVertex2f(.81f, 0.07f);
      glEnd();

      glBegin(GL_TRIANGLES);//..............................................Tree
      glColor3ub(52 ,176 ,21);
      glVertex2f(0.4f, 0.3f);
      glVertex2f(0.35f, 0.05f);
      glVertex2f(0.45f, 0.05f);
      glEnd();
      glBegin(GL_QUADS);
      glColor3ub(122 ,80 ,60);
      glVertex2f(.39f, 0.05f);
      glVertex2f(.39f, 0.0f);
      glVertex2f(.41f, 0.0f);
      glVertex2f(.41f, 0.05f);
      glEnd();

      glBegin(GL_QUADS);//..........................................Tree
      glColor3ub(122 ,80 ,60);
      glVertex2f(-.46f, 0.2f);
      glVertex2f(-.46f, 0.0f);
      glVertex2f(-.44f, 0.0f);
      glVertex2f(-.44f, 0.2f);
      glEnd();
      glBegin(GL_TRIANGLES);
      glColor3ub(52 ,176 ,21);
      glVertex2f(-0.45f, 0.3f);
      glVertex2f(-0.5f, 0.05f);
      glVertex2f(-0.4f, 0.05f);
      glEnd();

      glBegin(GL_TRIANGLES);//.................................................Tree
      glColor3ub(52 ,176 ,21);
      glVertex2f(-0.7f, 0.3f);
      glVertex2f(-0.75f, 0.07f);
      glVertex2f(-0.65f, 0.07f);
      glEnd();
      glBegin(GL_QUADS);
      glColor3ub(122 ,80 ,60);
      glVertex2f(-.71f, 0.07f);
      glVertex2f(-.71f, 0.0f);
      glVertex2f(-.69f, 0.0f);
      glVertex2f(-.69f, 0.07f);
      glEnd();
//******************************************************************************************************//

//******************************************************cloud******************************************//
    glPushMatrix(); //cloud
    glTranslatef(position3, 0.2f, 0);
    glPushMatrix();
    glTranslatef(0.5, 0.5f, 0);
    glColor3ub(255,255,255);
    glutSolidSphere(0.021,30,15);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.52f, 0.5f, 0);
    glColor3ub(255,255,255);
    glutSolidSphere(0.026,30,15); //cloud
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.54f, 0.5f, 0);
    glColor3ub(255,255,255);
    glutSolidSphere(0.021,30,15); //cloud
    glPopMatrix();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(position3, 0.25f, 0);
    glPushMatrix();
    glTranslatef(0.6f, 0.55f, 0);
    glColor3ub(255,255,255);
    glutSolidSphere(0.021,30,15);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.62f, 0.55f, 0);
    glColor3ub(255,255,255);
    glutSolidSphere(0.026,30,15);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.64f, 0.55f, 0);
    glColor3ub(255,255,255);
    glutSolidSphere(0.021,30,15);
    glPopMatrix();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(position3, 0.25f, 0);
    glPushMatrix();
    glTranslatef(0.4f, 0.55f, 0);
    glColor3ub(255,255,255);
    glutSolidSphere(0.021,30,15);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.42f, 0.55f, 0); //cloud
    glColor3ub(255,255,255);
    glutSolidSphere(0.026,30,15);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.44f, 0.55f, 0);//cloud
    glColor3ub(255,255,255);
    glutSolidSphere(0.021,30,15);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-0.2f, 0.30f, 0);//cloud
    glColor3ub(255,255,255);
    glutSolidSphere(0.021,30,15);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-0.22f, 0.30f, 0);//cloud
    glColor3ub(255,255,255);
    glutSolidSphere(0.026,30,15);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-0.24f, 0.30f, 0);
    glColor3ub(255,255,255);
    glutSolidSphere(0.021,30,15);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-0.4f, 0.20f, 0);
    glColor3ub(255,255,255);
    glutSolidSphere(0.021,30,15);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-0.42f, 0.20f, 0);
    glColor3ub(255,255,255);
    glutSolidSphere(0.026,30,15);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-0.44f, 0.20f, 0);
    glColor3ub(255,255,255);
    glutSolidSphere(0.021,30,15);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-0.6f, 0.25f, 0);
    glColor3ub(255,255,255);
    glutSolidSphere(0.021,30,15);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-0.62f, 0.25f, 0);
    glColor3ub(255,255,255);
    glutSolidSphere(0.026,30,15);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-0.64f, 0.25f, 0);
    glColor3ub(255,255,255);
    glutSolidSphere(0.021,30,15);
    glPopMatrix();
    glPopMatrix();
    glEnd();
//*********************************************************************//

//**********************ShiriShowdho****************************190 211//
       glBegin(GL_TRIANGLES);//shritishowdho1
       glColor3ub(190,190,190);
       glVertex2f(-.35f, 0.0f);
       glVertex2f(.35f, 0.0f);
       glVertex2f(0.0f, 0.1f);
       glEnd();

       glBegin(GL_TRIANGLES);//shritishowdho1
       glColor3ub(211,211,211);
       glVertex2f(-.30f, 0.0f);
       glVertex2f(.30f, 0.0f);
       glVertex2f(0.0f, 0.2f);
       glEnd();

       glBegin(GL_TRIANGLES);//shritishowdho1
       glColor3ub(190,190,190);
       glVertex2f(-.25f, 0.0f);
       glVertex2f(.25f, 0.0f);
       glVertex2f(0.0f, 0.3f);
       glEnd();

       glBegin(GL_TRIANGLES);//shritishowdho1
       glColor3ub(211,211,211);
       glVertex2f(-.20f, 0.0f);
       glVertex2f(.20f, 0.0f);
       glVertex2f(0.0f, 0.4f);
       glEnd();

       glBegin(GL_TRIANGLES);//shritishowdho1
       glColor3ub(190,190,190);
       glVertex2f(-.15f, 0.0f);
       glVertex2f(.15f, 0.0f);
       glVertex2f(0.0f, 0.5f);
       glEnd();

       glBegin(GL_TRIANGLES);//shritishowdho1
       glColor3ub(211,211,211);
       glVertex2f(-.10f, 0.0f);
       glVertex2f(.10f, 0.0f);
       glVertex2f(0.0f, 0.7f);
       glEnd();

       glBegin(GL_TRIANGLES);//shritishowdho1
       glColor3ub(190,190,190);
       glVertex2f(-.05f, 0.0f);
       glVertex2f(.05f, 0.0f);
       glVertex2f(0.0f, 0.9f);
       glEnd();

       glBegin(GL_TRIANGLES);//shritishowdho center1
       glColor3ub(211,211,211);
       glVertex2f(-.01f, 0.3f);
       glVertex2f(.01f, 0.3f);
       glVertex2f(0.0f, 0.8f);
       glEnd();

       glBegin(GL_TRIANGLES);//shritishowdho center2
       glColor3ub(211,211,211);
       glVertex2f(-.01f, 0.28f);
       glVertex2f(0.0f, 0.0f);
       glVertex2f(.01f, 0.28f);
       glEnd();
//*************************************flower infront of shahid minar**********************8

        glPushMatrix();//flower
        glTranslatef(0.0f,0.0f, 0.0f);
        glColor3ub(218,41,28);
        glutSolidSphere(0.040,30,15);
        glPopMatrix();
        glPushMatrix();//flower
        glTranslatef(-0.05f,0.0f, 0.0f);
        glColor3ub(255,140,25);
        glutSolidSphere(0.040,30,15);
        glPopMatrix();
        glPushMatrix();//flower
        glTranslatef(0.05f,0.0f, 0.0f);
        glColor3ub(255,140,25);
        glutSolidSphere(0.040,30,15);
        glPopMatrix();
        glPushMatrix();//flower
        glTranslatef(0.1f,0.0f, 0.0f);
        glColor3ub(255,255,77);
        glutSolidSphere(0.040,30,15);
        glPopMatrix();
        glPushMatrix();//flower
        glTranslatef(-0.1f,0.0f, 0.0f);
        glColor3ub(255,255,77);
        glutSolidSphere(0.040,30,15);
        glPopMatrix();
        glPushMatrix();//flower
        glTranslatef(0.15f,0.0f, 0.0f);
        glColor3ub(218,41,28);
        glutSolidSphere(0.040,30,15);
        glPopMatrix();
        glPushMatrix();//flower
        glTranslatef(-0.15f,0.0f, 0.0f);
        glColor3ub(218,41,28);
        glutSolidSphere(0.040,30,15);
        glPopMatrix();
        glPushMatrix();//flower
        glTranslatef(0.2f,0.0f, 0.0f);
        glColor3ub(255,255,77);
        glutSolidSphere(0.040,30,15);
        glPopMatrix();
        glPushMatrix();//flower
        glTranslatef(-0.2f,0.0f, 0.0f);
        glColor3ub(255,255,77);
        glutSolidSphere(0.040,30,15);
        glPopMatrix();

//**************************************************************************************
//***************************************waving Flag of Bangladesh******************************//
        glBegin(GL_QUADS);//stand
        glColor3ub(205,170,125);
        glVertex2f(.2f, 0.0f);
        glVertex2f(.208f, 0.0f);
        glVertex2f(0.208f, 0.55f);
        glVertex2f(.2f, 0.55f);
        glEnd();
        glBegin(GL_QUADS);//Green Area
        glColor3ub(0,103,71);
        glVertex2f(0.204f, flagPos_Y2);
        glVertex2f(flagPos_X, flagPos_Y2);
        glVertex2f(flagPos_X, flagPos_Y);
        glVertex2f(0.204f, flagPos_Y);
        glEnd();
        glPushMatrix();//Circle
        glTranslatef(circlePos_X,circlePos_Y, 0.0f);
        glColor3ub(218,41,28);
        glutSolidSphere(0.035,30,15);
        glPopMatrix();

//**********************************************************************************************//

 //***************************************Pond**************************************************//
       glBegin(GL_QUADS);//base red
       glColor3ub(139,26,26);
       glVertex2f(-.7f, -1.0f);
       glVertex2f(.7f, -1.0f);
       glVertex2f(.35f, -0.18f);
       glVertex2f(-.35f, -0.18f);
       glEnd();
       glBegin(GL_QUADS);//base green
       glColor3ub(134,201,100);
       glVertex2f(-.65f, -1.0f);
       glVertex2f(.65f, -1.0f);
       glVertex2f(.32f, -0.18f);
       glVertex2f(-.32f, -0.18f);
       glEnd();
       glBegin(GL_QUADS);//base
       glColor3ub(255,228,196);
       glVertex2f(-.4f, -1.0f);
       glVertex2f(.4f, -1.0f);
       glVertex2f(.2f, -0.18f);
       glVertex2f(-.2f, -0.18f);
       glEnd();

       glBegin(GL_QUADS);//base1
       glColor3ub(238,213,183);
       glVertex2f(-.35f, -0.95f);
       glVertex2f(.35f, -0.95f);
       glVertex2f(.18f, -0.14f);
       glVertex2f(-.18f, -0.14f);
       glEnd();

       glBegin(GL_QUADS);//water
       glColor3ub(r,g,b);
       glVertex2f(-.325f, -0.925f);
       glVertex2f(.325f, -0.925f);
       glVertex2f(.175f, -0.18f);
       glVertex2f(-.175f, -0.18f);
       glEnd();

       glBegin(GL_TRIANGLES);//shritishowdho1 reflection
       glColor3ub(190,190,190);
       glVertex2f(-.15f, -0.f);
       glVertex2f(.15f, -0.0f);
       glVertex2f(0.0f, -0.5f);
       glEnd();

       glBegin(GL_TRIANGLES);//shritishowdho1 reflection
       glColor3ub(211,211,211);
       glVertex2f(-.10f, -0.0f);
       glVertex2f(.10f, -0.0f);
       glVertex2f(0.0f, -0.7f);
       glEnd();

       glBegin(GL_TRIANGLES);//shritishowdho1 reflection
       glColor3ub(190,190,190);
       glVertex2f(-.05f, -0.0f);
       glVertex2f(.05f, -0.0f);
       glVertex2f(0.0f, -0.9f);
       glEnd();

       glBegin(GL_TRIANGLES);//shritishowdho center1 reflection
       glColor3ub(211,211,211);
       glVertex2f(-.01f, -0.3f);
       glVertex2f(.01f, -0.3f);
       glVertex2f(0.0f, -0.8f);
       glEnd();

       glBegin(GL_TRIANGLES);//shritishowdho center2 reflection
       glColor3ub(211,211,211);
       glVertex2f(-.01f, -0.28f);
       glVertex2f(0.0f, 0.0f);
       glVertex2f(.01f, -0.28f);
       glEnd();



 //*********************************************************************************************//
//************************Road**************************** 139 26 26
   glBegin(GL_QUADS);//road
   glColor3ub(139,26,26);
   glVertex2f(1.0f, -0.15f);
   glVertex2f(1.0f, 0.0f);
   glVertex2f(-1.0f, 0.0f);
   glVertex2f(-1.0f, -0.15f);
   glEnd();
   glBegin(GL_POLYGON);//road white big border
   glColor3ub(255,255,255);
   glVertex2f(1.0f, -0.18f);
   glVertex2f(1.0f, -0.14f);
   glVertex2f(-1.0f, -0.14f);
   glVertex2f(-1.0f, -0.18f);
   glEnd();
   glBegin(GL_POLYGON);//road white big border
   glColor3ub(255,255,255);
   glVertex2f(1.0f, -0.12f);
   glVertex2f(1.0f, -0.1f);
   glVertex2f(-1.0f, -0.1f);
   glVertex2f(-1.0f, -0.12f);
   glEnd();
glBegin(GL_POLYGON);//road white big border top
   glColor3ub(255,255,255);
   glVertex2f(1.0f, -0.10f);
   glVertex2f(1.0f, -0.05f);
    glVertex2f(-1.0f, -0.05f);
   glVertex2f(-1.0f, -0.1f);
   glEnd();
   glBegin(GL_POLYGON);//road white big border top
   glColor3ub(255,255,255);
   glVertex2f(1.0f, 0.02f);
   glVertex2f(1.0f, 0.0f);
    glVertex2f(-1.0f, 0.0f);
   glVertex2f(-1.0f, 0.02f);
   glEnd();
   glPushMatrix();
   glBegin(GL_POLYGON);//Border brown
   glColor3ub(200, 140, 100);
   glVertex2f(-1.0f, -0.150f);
   glVertex2f(-1.0f, -0.18f);
   glVertex2f(1.0f, -0.18f);
   glVertex2f(1.0f, -0.150f);
   glEnd();
   glPopMatrix();

 //=============================human==========================

   glBegin(GL_POLYGON); //human1
   glColor3ub(70, 64, 149);
   glVertex2f(-0.04f, 0.02f);
   glVertex2f(-0.04f, 0.080f);
   glVertex2f(-0.07f, 0.080f);
   glVertex2f(-0.07f, 0.02f);
   glEnd();

   glPushMatrix();
   glTranslatef(-0.055f, 0.1f, 0);
   glColor3ub(0, 0, 0);
   glutSolidSphere(0.018,30,15);
   glPopMatrix();

   glBegin(GL_POLYGON); //human2
   glColor3ub(146, 68, 144);
   glVertex2f(0.04f,0.02f );
   glVertex2f(0.04f,0.080f);
   glVertex2f(0.07f,0.080f );
   glVertex2f(0.07f, 0.02f);
   glEnd();
   glPushMatrix();
   glTranslatef(0.055f, 0.1f, 0);
   glColor3ub(0, 0, 0);
   glutSolidSphere(0.018,30,15);
   glPopMatrix();

   glBegin(GL_POLYGON); //human3
   glColor3ub(89, 164, 71);
   glVertex2f(-0.11f,0.02f );
   glVertex2f(-0.11f,0.080f) ;
   glVertex2f(-0.14f,0.080f);
   glVertex2f(-0.14f,0.02f);
   glEnd();

   glPushMatrix();
   glTranslatef(-0.125f, 0.1f, 0);
   glColor3ub(0, 0, 0);
   glutSolidSphere(0.018,30,15);
   glPopMatrix();

   glBegin(GL_POLYGON); //human4
   glColor3ub(204, 0 ,0);
   glVertex2f(0.11f, 0.02f);
   glVertex2f(0.11f,0.080f);
   glVertex2f(0.14f,0.080f);
   glVertex2f(0.14f,0.02f);
   glEnd();
    glPushMatrix();
    glTranslatef(0.125f, 0.1f, 0);
    glColor3ub(0, 0, 0);
    glutSolidSphere(0.018,30,15);
    glPopMatrix();
///////////////////////////////////////////////////////////////////////
    glPushMatrix(); //human5
    glTranslatef(position7, 0.0f, 0);
     glBegin(GL_POLYGON); //human1
   glColor3ub(70, 64, 149);
   glVertex2f(-0.04f, 0.02f);
   glVertex2f(-0.04f, 0.080f);
   glVertex2f(-0.07f, 0.080f);
   glVertex2f(-0.07f, 0.02f);
   glEnd();

   glPushMatrix();
   glTranslatef(-0.055f, 0.1f, 0);
   glColor3ub(0, 0, 0);
   glutSolidSphere(0.018,30,15);
   glPopMatrix();

   glBegin(GL_POLYGON); //human2
   glColor3ub(146, 68, 144);
   glVertex2f(0.04f,0.02f );
   glVertex2f(0.04f,0.080f);
   glVertex2f(0.07f,0.080f );
   glVertex2f(0.07f, 0.02f);
   glEnd();
   glPushMatrix();
   glTranslatef(0.055f, 0.1f, 0);
   glColor3ub(0, 0, 0);
   glutSolidSphere(0.018,30,15);
   glPopMatrix();

   glBegin(GL_POLYGON); //human3
   glColor3ub(89, 164, 71);
   glVertex2f(-0.11f,0.02f );
   glVertex2f(-0.11f,0.080f) ;
   glVertex2f(-0.14f,0.080f);
   glVertex2f(-0.14f,0.02f);
   glEnd();

   glPushMatrix();
   glTranslatef(-0.125f, 0.1f, 0);
   glColor3ub(0, 0, 0);
   glutSolidSphere(0.018,30,15);
   glPopMatrix();

   glBegin(GL_POLYGON); //human4
   glColor3ub(204, 0 ,0);
   glVertex2f(0.11f, 0.02f);
   glVertex2f(0.11f,0.080f);
   glVertex2f(0.14f,0.080f);
   glVertex2f(0.14f,0.02f);
   glEnd();
    glPushMatrix();
    glTranslatef(0.125f, 0.1f, 0);
    glColor3ub(0, 0, 0);
    glutSolidSphere(0.018,30,15);
    glPopMatrix();
    glBegin(GL_POLYGON);
    glColor3ub(0, 102, 102);
    glVertex2f(-0.97f, -0.022f);
    glVertex2f(-0.97f, 0.03f);
    glVertex2f(-1.0f, 0.03f);
    glVertex2f(-1.0f, -0.022f);
    glEnd();

    glPushMatrix();
    glTranslatef(-0.986f, 0.05f, 0);
    glColor3ub(0, 0, 0);
    glutSolidSphere(0.018,30,15);
    glPopMatrix();

   glBegin(GL_POLYGON); //human6
   glColor3ub(251, 50, 251);
   glVertex2f(-0.92f, -0.022f);
   glVertex2f(-0.92f,0.03f );
   glVertex2f(-0.95f, 0.03f);
   glVertex2f(-0.95f,-0.022f);
   glEnd();

    glPushMatrix();
    glTranslatef(-0.935f, 0.05f, 0);
    glColor3ub(0, 0, 0);
    glutSolidSphere(0.018,30,15);
    glPopMatrix();

   glBegin(GL_POLYGON); //human7
   glColor3ub(255,255,255);
   glVertex2f(-0.88f, -0.022f);
   glVertex2f(-0.88f,0.03f );
   glVertex2f(-0.91f,0.03f );
   glVertex2f(-0.91f,-0.022f );
   glEnd();

    glPushMatrix();
    glTranslatef(-0.896f, 0.05f, 0);
    glColor3ub(0, 0, 0);
    glutSolidSphere(0.018,30,15);
    glPopMatrix();

    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 0);
    glVertex2f(-0.83f,-0.022f );
    glVertex2f(-0.83f, 0.03f);
    glVertex2f(-0.86f, 0.03f);
    glVertex2f(-0.86f, -0.022f);
    glEnd();
    glPushMatrix();
    glTranslatef(-0.846f, 0.05f, 0);
    glColor3ub(0, 0, 0);
    glutSolidSphere(0.018,30,15);
    glPopMatrix();
///////////////////////
   glBegin(GL_POLYGON); //human7
   glColor3ub(251, 70, 251);
   glVertex2f(-0.78f, -0.022f);
   glVertex2f(-0.78f,0.03f );
   glVertex2f(-0.81f, 0.03f);
   glVertex2f(-0.81f,-0.022f);
   glEnd();

    glPushMatrix();
    glTranslatef(-0.796f, 0.05f, 0);
    glColor3ub(0, 0, 0);
    glutSolidSphere(0.018,30,15);
    glPopMatrix();

   glBegin(GL_POLYGON); //human8
   glColor3ub(2555, 0,0);
   glVertex2f(-0.73f, -0.022f);
   glVertex2f(-0.73f,0.03f );
   glVertex2f(-0.76f, 0.03f);
   glVertex2f(-0.76f,-0.022f);
   glEnd();

    glPushMatrix();
    glTranslatef(-0.746f, 0.05f, 0);
    glColor3ub(0, 0, 0);
    glutSolidSphere(0.018,30,15);
    glPopMatrix();
    glPopMatrix();


     glPushMatrix(); //human5
    glTranslatef(-position7, 0.00f, 0);
    glBegin(GL_POLYGON); //human1
   glColor3ub(70, 64, 149);
   glVertex2f(-0.04f, 0.02f);
   glVertex2f(-0.04f, 0.080f);
   glVertex2f(-0.07f, 0.080f);
   glVertex2f(-0.07f, 0.02f);
   glEnd();

   glPushMatrix();
   glTranslatef(-0.055f, 0.1f, 0);
   glColor3ub(0, 0, 0);
   glutSolidSphere(0.018,30,15);
   glPopMatrix();

   glBegin(GL_POLYGON); //human2
   glColor3ub(146, 68, 144);
   glVertex2f(0.04f,0.02f );
   glVertex2f(0.04f,0.080f);
   glVertex2f(0.07f,0.080f );
   glVertex2f(0.07f, 0.02f);
   glEnd();
   glPushMatrix();
   glTranslatef(0.055f, 0.1f, 0);
   glColor3ub(0, 0, 0);
   glutSolidSphere(0.018,30,15);
   glPopMatrix();

   glBegin(GL_POLYGON); //human3
   glColor3ub(89, 164, 71);
   glVertex2f(-0.11f,0.02f );
   glVertex2f(-0.11f,0.080f) ;
   glVertex2f(-0.14f,0.080f);
   glVertex2f(-0.14f,0.02f);
   glEnd();

   glPushMatrix();
   glTranslatef(-0.125f, 0.1f, 0);
   glColor3ub(0, 0, 0);
   glutSolidSphere(0.018,30,15);
   glPopMatrix();

   glBegin(GL_POLYGON); //human4
   glColor3ub(204, 0 ,0);
   glVertex2f(0.11f, 0.02f);
   glVertex2f(0.11f,0.080f);
   glVertex2f(0.14f,0.080f);
   glVertex2f(0.14f,0.02f);
   glEnd();
    glPushMatrix();
    glTranslatef(0.125f, 0.1f, 0);
    glColor3ub(0, 0, 0);
    glutSolidSphere(0.018,30,15);
    glPopMatrix();;
    glBegin(GL_POLYGON);
    glColor3ub(0, 102, 102);
    glVertex2f(-0.97f, -0.022f);
    glVertex2f(-0.97f, 0.03f);
    glVertex2f(-1.0f, 0.03f);
    glVertex2f(-1.0f, -0.022f);
    glEnd();

    glPushMatrix();
    glTranslatef(-0.986f, 0.05f, 0);
    glColor3ub(0, 0, 0);
    glutSolidSphere(0.018,30,15);
    glPopMatrix();

   glBegin(GL_POLYGON); //human6
   glColor3ub(251, 50, 251);
   glVertex2f(-0.92f, -0.022f);
   glVertex2f(-0.92f,0.03f );
   glVertex2f(-0.95f, 0.03f);
   glVertex2f(-0.95f,-0.022f);
   glEnd();

    glPushMatrix();
    glTranslatef(-0.935f, 0.05f, 0);
    glColor3ub(0, 0, 0);
    glutSolidSphere(0.018,30,15);
    glPopMatrix();

   glBegin(GL_POLYGON); //human7
   glColor3ub(255,255,255);
   glVertex2f(-0.88f, -0.022f);
   glVertex2f(-0.88f,0.03f );
   glVertex2f(-0.91f,0.03f );
   glVertex2f(-0.91f,-0.022f );
   glEnd();

    glPushMatrix();
    glTranslatef(-0.896f, 0.05f, 0);
    glColor3ub(0, 0, 0);
    glutSolidSphere(0.018,30,15);
    glPopMatrix();

    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 0);
    glVertex2f(-0.83f,-0.022f );
    glVertex2f(-0.83f, 0.03f);
    glVertex2f(-0.86f, 0.03f);
    glVertex2f(-0.86f, -0.022f);
    glEnd();
    glPushMatrix();
    glTranslatef(-0.846f, 0.05f, 0);
    glColor3ub(0, 0, 0);
    glutSolidSphere(0.018,30,15);
    glPopMatrix();
///////////////////////
   glBegin(GL_POLYGON); //human7
   glColor3ub(251, 70, 251);
   glVertex2f(-0.78f, -0.022f);
   glVertex2f(-0.78f,0.03f );
   glVertex2f(-0.81f, 0.03f);
   glVertex2f(-0.81f,-0.022f);
   glEnd();

    glPushMatrix();
    glTranslatef(-0.796f, 0.05f, 0);
    glColor3ub(0, 0, 0);
    glutSolidSphere(0.018,30,15);
    glPopMatrix();

   glBegin(GL_POLYGON); //human8
   glColor3ub(2555, 0,0);
   glVertex2f(-0.73f, -0.022f);
   glVertex2f(-0.73f,0.03f );
   glVertex2f(-0.76f, 0.03f);
   glVertex2f(-0.76f,-0.022f);
   glEnd();

    glPushMatrix();
    glTranslatef(-0.746f, 0.05f, 0);
    glColor3ub(0, 0, 0);
    glutSolidSphere(0.018,30,15);
    glPopMatrix();
    glPopMatrix();

   //////////////////////////////////////////////////////////////
   //Rain body starts//
	   //raining open

//*********************************************************************************************//




  /////////////////////////////CAR/////////////////////////////////
   GLfloat rain_position1 = -0.10f;
GLfloat rain_speed1 = 0.1f;
GLfloat rain_position2 = -0.10f;
GLfloat rain_speed2 = 0.1f; glTranslatef(position5,-0.01f, 0.0f);//car
    glPushMatrix();
    glBegin(GL_POLYGON);// Body
    glColor3ub(44, 50, 135);
    glVertex2f(0.0f, -0.025f);
    glVertex2f(0.0f, -0.045f);
    glVertex2f(.085f, -0.045f);
    glVertex2f(.085f, -0.025f);
    glEnd();
    glBegin(GL_POLYGON);// Body
    glColor3ub(44, 50, 135);
    glVertex2f(0.03f, -0.00650f);
    glVertex2f(0.02f, -0.045f);
    glVertex2f(.075f, -0.045f);
    glVertex2f(.065f, -0.0065f);
    glEnd();
    glBegin(GL_POLYGON);// glass
    glColor3ub(k, o, 10);
    glVertex2f(0.065f, -0.00650f);
    glVertex2f(0.075f, -0.025f);
    glVertex2f(.04f, -0.025f);
    glVertex2f(.04f, -0.0065f);
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.025f,-0.041f, 0.0f);//tyres
    glColor3ub(0,0,0);
    glutSolidSphere(0.01,30,15);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.065f,-0.041f, 0.0f);//tyres
    glColor3ub(0,0,0);
    glutSolidSphere(0.01,30,15);
    glPopMatrix();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(position6,-0.08f, 0.0f);
   //car2
   glPushMatrix();
   glBegin(GL_POLYGON);// Body
   glColor3ub(255,128,0);
   glVertex2f(0.0f, -0.025f);
   glVertex2f(0.0f, -0.045f);
   glVertex2f(.085f, -0.045f);
   glVertex2f(.085f, -0.025f);
   glEnd();
   glBegin(GL_POLYGON);//Body
   glColor3ub(255,128,0);
   glVertex2f(0.03f, -0.00650f);
   glVertex2f(0.02f, -0.045f);
   glVertex2f(.075f, -0.045f);
   glVertex2f(.065f, -0.0065f);
   glEnd();
   glBegin(GL_POLYGON);// glass
   glColor3ub(k, o, 10);
   glVertex2f(0.03f, -0.00650f);
   glVertex2f(0.02f, -0.025f);
   glVertex2f(.04f, -0.025f);
   glVertex2f(.04f, -0.0065f);
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.025f,-0.041f, 0.0f);//tyres
    glColor3ub(0,0,0);
    glutSolidSphere(0.01,30,15);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.065f,-0.041f, 0.0f);//tyres
    glColor3ub(0,0,0);
    glutSolidSphere(0.01,30,15);
    glPopMatrix();
    glPushMatrix();
    glPushMatrix();
    glTranslatef(position,0.0f, 0.0f);
    glPopMatrix();
    glPopMatrix();
//////////////////////////////////////////////////////////////
/*   //Rain body starts//
	   //raining open
   glPushMatrix();//////raining1
   glTranslatef(0,rain_position2, 0.0f);
   glBegin(GL_LINES);
      glColor3f(1.0f, 1.0f, 1.0f);
      glVertex2f(-0.8,1);//1st row
      glVertex2f(-0.8,0.9);
      glVertex2f(-0.8,0.7);
      glVertex2f(-0.8,0.6);
      glVertex2f(-0.8,0.4);
      glVertex2f(-0.8,0.3);
      glVertex2f(-0.8,0.2);
      glVertex2f(-0.8,0.1);
      glVertex2f(-0.8,0.0);
      glVertex2f(-0.8,-0.1);
      glVertex2f(-0.8,-0.2);
      glVertex2f(-0.8,-0.3);
      glVertex2f(-0.8,-0.4);
      glVertex2f(-0.8,-0.5);
      glVertex2f(-0.8,-0.6);
      glVertex2f(-0.8,-0.7);
      glVertex2f(-0.4,1);//3rd row
      glVertex2f(-0.4,0.9);
      glVertex2f(-0.4,0.7);
      glVertex2f(-0.4,0.6);
      glVertex2f(-0.4,0.4);
      glVertex2f(-0.4,0.3);
      glVertex2f(-0.4,0.2);
      glVertex2f(-0.4,0.1);
      glVertex2f(-0.4,0.0);
      glVertex2f(-0.4,-0.1);
      glVertex2f(-0.4,-0.2);
      glVertex2f(-0.4,-0.3);
      glVertex2f(-0.4,-0.4);
      glVertex2f(-0.4,-0.5);
      glVertex2f(-0.4,-0.6);
      glVertex2f(-0.4,-0.7);
      glVertex2f(-0.4,-0.8);
      glVertex2f(-0.4,-0.9);
      glVertex2f(0,1);    /////5th row
      glVertex2f(0,0.9);
      glVertex2f(0,0.7);
      glVertex2f(0,0.6);
      glVertex2f(0,0.4);
      glVertex2f(0,0.3);
      glVertex2f(0,0.2);
      glVertex2f(0,0.1);
      glVertex2f(0,0.0);
      glVertex2f(0,-0.1);
      glVertex2f(0,-0.2);
      glVertex2f(0,-0.3);
      glVertex2f(0,-0.4);
      glVertex2f(0,-0.5);
      glVertex2f(0,-0.6);
      glVertex2f(0,-0.7);
      glVertex2f(0,-0.8);
      glVertex2f(0,-0.9);
      glVertex2f(0.4,1);//3rd row
      glVertex2f(0.4,0.9);
      glVertex2f(0.4,0.7);
      glVertex2f(0.4,0.6);
      glVertex2f(0.4,0.4);
      glVertex2f(0.4,0.3);
      glVertex2f(0.4,0.2);
      glVertex2f(0.4,0.1);
      glVertex2f(0.4,0.0);
      glVertex2f(0.4,-0.1);
      glVertex2f(0.4,-0.2);
      glVertex2f(0.4,-0.3);
      glVertex2f(0.4,-0.4);
      glVertex2f(0.4,-0.5);
      glVertex2f(0.4,-0.6);
      glVertex2f(0.4,-0.7);
      glVertex2f(0.4,-0.8);
      glVertex2f(0.4,-0.9);
      glEnd();
      glPopMatrix();
     //copy rain starts//
      glPushMatrix();//////raining1
      glTranslatef(0,rain_position2, 0.0f);
      glTranslatef(2,2,0);
      glBegin(GL_LINES);
      glColor3f(1.0f, 1.0f, 1.0f);
      glVertex2f(-0.8,1);//1st row
      glVertex2f(-0.8,0.9);
      glVertex2f(-0.8,0.7);
      glVertex2f(-0.8,0.6);
      glVertex2f(-0.8,0.4);
      glVertex2f(-0.8,0.3);
      glVertex2f(-0.8,0.2);
      glVertex2f(-0.8,0.1);
      glVertex2f(-0.8,0.0);
      glVertex2f(-0.8,-0.1);
      glVertex2f(-0.8,-0.2);
      glVertex2f(-0.8,-0.3);
      glVertex2f(-0.8,-0.4);
      glVertex2f(-0.8,-0.5);
      glVertex2f(-0.8,-0.6);
      glVertex2f(-0.8,-0.7);
      glVertex2f(-0.4,1);//3rd row
      glVertex2f(-0.4,0.9);
      glVertex2f(-0.4,0.7);
      glVertex2f(-0.4,0.6);
      glVertex2f(-0.4,0.4);
      glVertex2f(-0.4,0.3);
      glVertex2f(-0.4,0.2);
      glVertex2f(-0.4,0.1);
      glVertex2f(-0.4,0.0);
      glVertex2f(-0.4,-0.1);
      glVertex2f(-0.4,-0.2);
      glVertex2f(-0.4,-0.3);
      glVertex2f(-0.4,-0.4);
      glVertex2f(-0.4,-0.5);
      glVertex2f(-0.4,-0.6);
      glVertex2f(-0.4,-0.7);
      glVertex2f(-0.4,-0.8);
      glVertex2f(-0.4,-0.9);
      glVertex2f(0,1);//5th row
      glVertex2f(0,0.9);
      glVertex2f(0,0.7);
      glVertex2f(0,0.6);
      glVertex2f(0,0.4);
      glVertex2f(0,0.3);
      glVertex2f(0,0.2);
      glVertex2f(0,0.1);
      glVertex2f(0,.0);
      glVertex2f(0,-0.1);
      glVertex2f(0,-0.2);
      glVertex2f(0,-0.3);
      glVertex2f(0,-0.4);
      glVertex2f(0,-0.5);
      glVertex2f(0,-0.6);
      glVertex2f(0,-0.7);
      glVertex2f(0,-0.8);
      glVertex2f(0,-0.9);
      glVertex2f(0.4,1);//3rd row
      glVertex2f(0.4,0.9);
      glVertex2f(0.4,0.7);
      glVertex2f(0.4,0.6);
      glVertex2f(0.4,0.4);
      glVertex2f(0.4,0.3);
      glVertex2f(0.4,0.2);
      glVertex2f(0.4,0.1);
      glVertex2f(0.4,0.0);
      glVertex2f(0.4,-0.1);
      glVertex2f(0.4,-0.2);
      glVertex2f(0.4,-0.3);
      glVertex2f(0.4,-0.4);
      glVertex2f(0.4,-0.5);
      glVertex2f(0.4,-0.6);
      glVertex2f(0.4,-0.7);
      glVertex2f(0.4,-0.8);
      glVertex2f(0.4,-0.9);
      glEnd();
  //copy rain stops//
      glPopMatrix();
        glPushMatrix();
        glTranslatef(0.0f ,rain_position1, 0.0f);
        glBegin(GL_LINES);
      //2nd row
      glVertex2f(-0.6,0.7);
      glVertex2f(-0.6,0.6);
      glVertex2f(-0.6,0.4);
      glVertex2f(-0.6,0.3);
      glVertex2f(-0.6,0.2);
      glVertex2f(-0.6,0.1);
      glVertex2f(-0.6,0.0);
      glVertex2f(-0.6,-0.1);
      glVertex2f(-0.6,-0.2);
      glVertex2f(-0.6,-0.3);
      glVertex2f(-0.6,-0.4);
      glVertex2f(-0.6,-0.5);
      glVertex2f(-0.6,-0.6);
      glVertex2f(-0.6,-0.7);
      glVertex2f(-0.6,-0.8);
      glVertex2f(-0.6,-0.9);
      glVertex2f(-0.2,1);//4th row
      glVertex2f(-0.2,0.9);
      glVertex2f(-0.2,0.7);
      glVertex2f(-0.2,0.6);
      glVertex2f(-0.2,0.4);
      glVertex2f(-0.2,0.3);
      glVertex2f(-0.2,0.2);
      glVertex2f(-0.2,0.1);
      glVertex2f(-0.2,0.0);
      glVertex2f(-0.2,-0.1);
      glVertex2f(-0.2,-0.2);
      glVertex2f(-0.2,-0.3);
      glVertex2f(-0.2,-0.4);
      glVertex2f(-0.2,-0.5);
      glVertex2f(-0.2,-0.6);
      glVertex2f(-0.2,-0.7);
      glVertex2f(-0.2,-0.8);
      glVertex2f(-0.2,-0.9);
      glVertex2f(0.2,1);//6th row
      glVertex2f(0.2,0.9);
      glVertex2f(0.2,0.7);
      glVertex2f(0.2,0.6);
      glVertex2f(0.2,0.4);
      glVertex2f(0.2,0.3);
      glVertex2f(0.2,0.2);
      glVertex2f(0.2,0.1);
      glVertex2f(0.2,0.0);
      glVertex2f(0.2,-0.1);
      glVertex2f(0.2,-0.2);
      glVertex2f(0.2,-0.3);
      glVertex2f(0.2,-0.4);
      glVertex2f(0.2,-0.5);
      glVertex2f(0.2,-0.6);
      glVertex2f(0.2,-0.7);
      glVertex2f(0.2,-0.8);
      glVertex2f(0.2,-0.9);
      glVertex2f(0.8,1);//7st row
      glVertex2f(0.8,0.9);
      glVertex2f(0.8,0.7);
      glVertex2f(0.8,0.6);
      glVertex2f(0.8,0.4);
      glVertex2f(0.8,0.3);
      glVertex2f(0.8,0.2);
      glVertex2f(0.8,0.1);
      glVertex2f(0.8,0.0);
      glVertex2f(0.8,-0.1);
      glVertex2f(0.8,-0.2);
      glVertex2f(0.8,-0.3);
      glVertex2f(0.8,-0.4);
      glVertex2f(0.8,-0.5);
      glVertex2f(0.8,-0.6);
      glVertex2f(0.8,-0.7);
      //8th row
      glVertex2f(0.6,0.7);
      glVertex2f(0.6,0.6);
      glVertex2f(0.6,0.4);
      glVertex2f(0.6,0.3);
      glVertex2f(0.6,0.2);
      glVertex2f(0.6,0.1);
      glVertex2f(0.6,.0);
      glVertex2f(0.6,-0.1);
      glVertex2f(0.6,-0.2);
      glVertex2f(0.6,-0.3);
      glVertex2f(.6,-0.4);
      glVertex2f(.6,-0.5);
      glVertex2f(.6,-0.6);
      glVertex2f(0.6,-0.7);
      glVertex2f(0.6,-0.8);
      glVertex2f(0.6,-0.9);
      glEnd();
      glPopMatrix();
      //negative side copy rains starts//
      glPushMatrix();
      glTranslatef(0,rain_position1, 0.0f);
      glTranslatef(2,2,0);
      glBegin(GL_LINES);
      glColor3f(1.0f, 1.0f, 1.0f);
      //2nd row
      glVertex2f(-0.6,0.7);
      glVertex2f(-0.6,0.6);
      glVertex2f(-0.6,0.4);
      glVertex2f(-0.6,0.3);
      glVertex2f(-0.6,0.2);
      glVertex2f(-0.6,0.1);
      glVertex2f(-0.6,0.0);
      glVertex2f(-0.6,-0.1);
      glVertex2f(-0.6,-0.2);
      glVertex2f(-0.6,-0.3);
      glVertex2f(-0.6,-0.4);
      glVertex2f(-0.6,-0.5);
      glVertex2f(-0.6,-0.6);
      glVertex2f(-0.6,-0.7);
      glVertex2f(-0.6,-0.8);
      glVertex2f(-0.6,-0.9);
       glVertex2f(-0.2,1);//4th row
      glVertex2f(-0.2,0.9);
      glVertex2f(-0.2,0.7);
      glVertex2f(-0.2,0.6);
      glVertex2f(-0.2,0.4);
      glVertex2f(-0.2,0.3);
      glVertex2f(-0.2,0.2);
      glVertex2f(-0.2,0.1);
      glVertex2f(-0.2,0.0);
      glVertex2f(-0.2,-0.1);
      glVertex2f(-0.2,-0.2);
      glVertex2f(-0.2,-0.3);
      glVertex2f(-0.2,-0.4);
      glVertex2f(-0.2,-0.5);
      glVertex2f(-0.2,-0.6);
      glVertex2f(-0.2,-0.7);
      glVertex2f(-0.2,-0.8);
      glVertex2f(-0.2,-0.9);
    //////////////////////////////
      glVertex2f(0.2,1);//6th row
      glVertex2f(0.2,0.9);
      glVertex2f(0.2,0.7);
      glVertex2f(0.2,0.6);
      glVertex2f(0.2,0.4);
      glVertex2f(0.2,0.3);
      glVertex2f(0.2,0.2);
      glVertex2f(0.2,0.1);
      glVertex2f(0.2,0.0);
      glVertex2f(0.2,-0.1);
      glVertex2f(0.2,-0.2);
      glVertex2f(0.2,-0.3);
      glVertex2f(0.2,-0.4);
      glVertex2f(0.2,-0.5);
      glVertex2f(0.2,-0.6);
      glVertex2f(0.2,-0.7);
      glVertex2f(0.2,-0.8);
      glVertex2f(0.2,-0.9);
      glVertex2f(0.8,1); //7st row
      glVertex2f(0.8,0.9);
      glVertex2f(0.8,0.7);
      glVertex2f(0.8,0.6);
      glVertex2f(0.8,0.4);
      glVertex2f(0.8,0.3);
      glVertex2f(0.8,0.2);
      glVertex2f(0.8,0.1);
      glVertex2f(0.8,0.0);
      glVertex2f(0.8,-0.1);
      glVertex2f(0.8,-0.2);
      glVertex2f(0.8,-0.3);
      glVertex2f(0.8,-0.4);
      glVertex2f(0.8,-0.5);
      glVertex2f(0.8,-0.6);
      glVertex2f(0.8,-0.7);
      //8th row
      glVertex2f(0.6,0.7);
      glVertex2f(0.6,0.6);
      glVertex2f(0.6,0.4);
      glVertex2f(0.6,0.3);
      glVertex2f(0.6,0.2);
      glVertex2f(0.6,0.1);
      glVertex2f(0.6,0.0);
      glVertex2f(0.6,-0.1);
      glVertex2f(0.6,-0.2);
      glVertex2f(0.6,-0.3);
      glVertex2f(0.6,-0.4);
      glVertex2f(0.6,-0.5);
      glVertex2f(0.6,-0.6);
      glVertex2f(0.6,-0.7);
      glVertex2f(0.6,-0.8);
      glVertex2f(0.6,-0.9);
      glEnd();
      glPopMatrix();    //Negative side copy rains stops//
                        //Raining close//
	                    //Rain body Ends//
*/


//*********************************************************************************************//
   glFlush();
}
   int main(int argc, char** argv) {
   glutInit(&argc, argv);
   glutInitWindowSize(1280,820);
   glutInitWindowPosition(50, 50);
   glutCreateWindow("Victory Day");
   glutDisplayFunc(display);
   init();
   glutKeyboardFunc(handleKeypress);
   sndPlaySound("PurboDigonte.wav",SND_ASYNC|SND_LOOP);

   glutMouseFunc(handleMouse);
   glutTimerFunc(1000, update, 0);
   glutTimerFunc(1000, updateSun, 0);
   glutTimerFunc(100, updateCloud1, 0);
   glutTimerFunc(100, updateCar, 0);
   // glutTimerFunc(100, Rain, 0);
   glutTimerFunc(100, updateCar2, 0);
   //glutTimerFunc(1500, rain_update1, 0);               //rain
   //glutTimerFunc(1000, rain_update2, 0);
   glutTimerFunc(100, human, 0);
   glutTimerFunc(500, updateFlag, 0);
   glutMainLoop();

   return 0;
}
