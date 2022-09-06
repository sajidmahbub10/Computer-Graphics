#include<windows.h>
#include<stdio.h>
#include <GL/glut.h>
#include <iostream>
#include <string>

///game speed
int FPS = 50;

///game trackers
int start_flag=0;
int gameover_flag=0;
//int level = 0;

///score
int score = 0;

///track moving
int roadDivTopMost = 0;
int roadDivTop = 0;
int roadDivMdl = 0;
int roadDivBtm = 0;

///for left/right
int lrIndex = 0 ;

///opposite car
int car1 = 0;
int lrIndex1=0;
int car2 = +35;
int lrIndex2=0;
int car3 = +70;
int lrIndex3=0;

///text display
const int font1=(int)GLUT_BITMAP_TIMES_ROMAN_24;
const int font2=(int)GLUT_BITMAP_HELVETICA_18 ;
const int font3=(int)GLUT_BITMAP_8_BY_13;

//char s[30];
void renderBitmapString(float x, float y, void *font,const char *string)
{
    const char *c;
    glRasterPos2f(x, y);
    for (c=string; *c != '\0'; c++) {
        glutBitmapCharacter(font, *c);
    }
}

///1st dispaly
void startGame(){

    ///road
    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2i(20,0);
    glVertex2i(20,100);
    glVertex2i(80,100);
    glVertex2i(80,0);
    glEnd();

    ///road left border
    glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    glVertex2i(20,0);
    glVertex2i(20,100);
    glVertex2i(23,100);
    glVertex2i(23,0);
    glEnd();

    ///road right border
    glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    glVertex2i(77,0);
    glVertex2i(77,100);
    glVertex2i(80,100);
    glVertex2i(80,0);
    glEnd();

    ///road divider
    //top
    glColor3ub(230, 230, 0);
    glBegin(GL_POLYGON);
    glVertex2i(48,roadDivTop+80);
    glVertex2i(48,roadDivTop+100);
    glVertex2i(52,roadDivTop+100);
    glVertex2i(52,roadDivTop+80);
    glEnd();
    roadDivTop--;
    if(roadDivTop<-100){
        roadDivTop =20;
        score++;
    }

    //middle
    glColor3ub(230, 230, 0);
    glBegin(GL_POLYGON);
    glVertex2i(48,roadDivMdl+40);
    glVertex2i(48,roadDivMdl+60);
    glVertex2i(52,roadDivMdl+60);
    glVertex2i(52,roadDivMdl+40);
    glEnd();
    roadDivMdl--;
    if(roadDivMdl<-60){
        roadDivMdl =60;
        score++;
    }
    //bottom
    glColor3ub(230, 230, 0);
    glBegin(GL_POLYGON);
    glVertex2i(48,roadDivBtm+0);
    glVertex2i(48,roadDivBtm+20);
    glVertex2i(52,roadDivBtm+20);
    glVertex2i(52,roadDivBtm+0);
    glEnd();
    roadDivBtm--;
    if(roadDivBtm<-20){
        roadDivBtm=100;
        score++;
    }
    ///score board
    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2i(80,97);
    glVertex2i(100,97);
    glVertex2i(100,90);
    glVertex2i(80,90);
    glEnd();

    ///score
    char buffer [50];
    sprintf (buffer, "SCORE: %d", score);
    glColor3ub(64, 255, 0);
    renderBitmapString(80.5,95,(void *)font3,buffer);

    ///speed
    char buffer1 [50];
    sprintf (buffer1, "SPEED:%dKm/h", FPS);
    glColor3ub(64, 255, 0);
    renderBitmapString(80.5,93,(void *)font3,buffer1);


    ///main car
    //front tire
    glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    glVertex2i(lrIndex+24,5);
    glVertex2i(lrIndex+24,7);
    glVertex2i(lrIndex+32,7);
    glVertex2i(lrIndex+32,5);
    glEnd();
    //back tire
    glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    glVertex2i(lrIndex+24,1);
    glVertex2i(lrIndex+24,3);
    glVertex2i(lrIndex+32,3);
    glVertex2i(lrIndex+32,1);
    glEnd();
    //body
    glColor3ub(0, 102, 102);
    glBegin(GL_POLYGON);
    glVertex2i(lrIndex+26,1);
    glVertex2i(lrIndex+26,8);
    glVertex2i(lrIndex+28,10);
    glVertex2i(lrIndex+30,8);
    glVertex2i(lrIndex+30,1);
    glEnd();


    ///Opposite car 1
    //front tire
    glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    glVertex2i(lrIndex1+24,car1+96);
    glVertex2i(lrIndex1+24,car1+94);
    glVertex2i(lrIndex1+32,car1+94);
    glVertex2i(lrIndex1+32,car1+96);
    glEnd();
    //back tire
    glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    glVertex2i(lrIndex1+24,car1+100);
    glVertex2i(lrIndex1+24,car1+98);
    glVertex2i(lrIndex1+32,car1+98);
    glVertex2i(lrIndex1+32,car1+100);
    glEnd();
    //body
    glColor3ub(255, 51, 0);
    glBegin(GL_POLYGON);
    glVertex2i(lrIndex1+26,car1+100);
    glVertex2i(lrIndex1+26,car1+93);
    glVertex2i(lrIndex1+28,car1+91);
    glVertex2i(lrIndex1+30,car1+93);
    glVertex2i(lrIndex1+30,car1+100);
    glEnd();
    car1--;
    if(car1 < -100){
        car1=0;
        lrIndex1=lrIndex;
    }
    //kill check car1
    if((abs(lrIndex-lrIndex1)<8) && (car1+100<10)){

            start_flag = 0;
            gameover_flag=1;

    }

    ///Opposite car 2
    //front tire
    glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    glVertex2i(lrIndex2+24,car2+96);
    glVertex2i(lrIndex2+24,car2+94);
    glVertex2i(lrIndex2+32,car2+94);
    glVertex2i(lrIndex2+32,car2+96);
    glEnd();
    //back tire
    glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    glVertex2i(lrIndex2+24,car2+100);
    glVertex2i(lrIndex2+24,car2+98);
    glVertex2i(lrIndex2+32,car2+98);
    glVertex2i(lrIndex2+32,car2+100);
    glEnd();
    //body
    glColor3ub(92, 0, 153);
    glBegin(GL_POLYGON);
    glVertex2i(lrIndex2+26,car2+100);
    glVertex2i(lrIndex2+26,car2+93);
    glVertex2i(lrIndex2+28,car2+91);
    glVertex2i(lrIndex2+30,car2+93);
    glVertex2i(lrIndex2+30,car2+100);
    glEnd();
    car2--;
    if(car2 < -100){
        car2=0;
        lrIndex2=lrIndex;
    }
    //kill check car2
    if((abs(lrIndex-lrIndex2)<8) && (car2+100<10)){

            start_flag = 0;
            gameover_flag=1;
    }


    ///Opposite car 3
    //front tire
    glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    glVertex2i(lrIndex3+24,car3+96);
    glVertex2i(lrIndex3+24,car3+94);
    glVertex2i(lrIndex3+32,car3+94);
    glVertex2i(lrIndex3+32,car3+96);
    glEnd();
    //back tire
    glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    glVertex2i(lrIndex3+24,car3+100);
    glVertex2i(lrIndex3+24,car3+98);
    glVertex2i(lrIndex3+32,car3+98);
    glVertex2i(lrIndex3+32,car3+100);
    glEnd();
    //body
    glColor3ub(255, 163, 26);
    glBegin(GL_POLYGON);
    glVertex2i(lrIndex3+26,car3+100);
    glVertex2i(lrIndex3+26,car3+93);
    glVertex2i(lrIndex3+28,car3+91);
    glVertex2i(lrIndex3+30,car3+93);
    glVertex2i(lrIndex3+30,car3+100);
    glEnd();
    car3--;
    if(car3 < -100){
        car3=0;
        lrIndex3=lrIndex;
    }
    //kill check car3
    if((abs(lrIndex-lrIndex3)<8) && (car3+100<10)){

            start_flag = 0;
            gameover_flag=1;  ///flag

    }

     ///home1
    glColor3ub(105,105,105);
    glBegin(GL_POLYGON);
    glVertex2i(5,40);
    glVertex2i(15,40);
    glVertex2i(10,50);
    glEnd();

    glColor3ub(189,183,107);
    glBegin(GL_POLYGON);
    glVertex2i(5,40);
    glVertex2i(15,40);
    glVertex2i(15,30);
    glVertex2i(5,30);
    glEnd();

    glColor3ub(105,105,105);
    glBegin(GL_POLYGON);
    glVertex2i(9,30);
    glVertex2i(9,33);
    glVertex2i(11,33);
    glVertex2i(11,30);
    glEnd();

    ///home2
    glColor3ub(105,105,105);
    glBegin(GL_POLYGON);
    glVertex2i(85,40);
    glVertex2i(95,40);
    glVertex2i(90,50);
    glEnd();

    glColor3ub(189,183,107);
    glBegin(GL_POLYGON);
    glVertex2i(85,40);
    glVertex2i(95,40);
    glVertex2i(95,30);
    glVertex2i(85,30);
    glEnd();

    glColor3ub(105,105,105);
    glBegin(GL_POLYGON);
    glVertex2i(89,30);
    glVertex2i(89,33);
    glVertex2i(91,33);
    glVertex2i(91,30);
    glEnd();

}

///inside design

void fristDesign(){


        ///menu
        //middle
        glColor3ub(0,0,0);
        glBegin(GL_POLYGON);
        glVertex2i(28,85);
        glVertex2i(78,85);
        glVertex2i(78,65);
        glVertex2i(28,65);
        glEnd();

        glColor3ub(0,0,0);
        glBegin(GL_POLYGON);
        glVertex2i(28,75);
        glVertex2i(78,75);
        glVertex2i(78,55);
        glVertex2i(28,55);
        glEnd();



        ///text info
        if(gameover_flag==1){

        glColor3ub(0,0,0);
        glBegin(GL_POLYGON);
        glVertex2i(27,45);
        glVertex2i(78,45);
        glVertex2i(78,25);
        glVertex2i(27,25);
        glEnd();

            glColor3ub(255, 0, 0);
            renderBitmapString(47,31,(void *)font1,"GAME OVER");
            glColor3ub(255, 0, 0);
            char buffer2 [50];
            sprintf (buffer2, "Your Score is : %d", score);
            renderBitmapString(47,36,(void *)font1,buffer2);

        }

        glColor3ub(179, 0, 0);
        renderBitmapString(41,80,(void *)font1,"Road Runner");

        glColor3ub(0, 179, 0);
        renderBitmapString(38,75,(void *)font1,"Press SPACE to START");
        renderBitmapString(38,72,(void *)font1,"Press ESC to Exit");

        glColor3ub(255, 255, 255);
        renderBitmapString(30,68,(void *)font3,"              Press UP to increase Speed");
        renderBitmapString(30,66,(void *)font3,"              Press DOWN to decrease Speed");
        renderBitmapString(30,64,(void *)font3,"              Press RIGHT to turn Right");
        renderBitmapString(30,62,(void *)font3,"              Press LEFT to turn Left");

}


void display(){
    glClear(GL_COLOR_BUFFER_BIT);

    if(start_flag==1){

        glClearColor(0, 392, 0,1);
        startGame();
    }

    else{
        fristDesign();
    }
    glFlush();
    glutSwapBuffers();
}



void spe_key(int key, int x, int y){

    switch (key) {

        case GLUT_KEY_DOWN:
            if(FPS>50)
            FPS=FPS-2;
            break;
        case GLUT_KEY_UP:
            FPS=FPS+2;
            break;


        case GLUT_KEY_LEFT:
            if(lrIndex>=0){
                lrIndex = lrIndex - (FPS/10);
                if(lrIndex<0){

                    lrIndex=-1;
                }
            }
            break;

        case GLUT_KEY_RIGHT:
            if(lrIndex<=44){
                lrIndex = lrIndex + (FPS/10);
                if(lrIndex>44){
                    lrIndex = 45;
                }
            }
            break;

        default:
                break;
        }

}

void processKeys(unsigned char key, int x, int y) {

      switch (key)
            {
                case ' ':
            if(start_flag==0){
                start_flag = 1;
                gameover_flag = 0;
                FPS = 50;
                roadDivTopMost = 0;
                roadDivTop = 0;
                roadDivMdl = 0;
                roadDivBtm = 0;
                lrIndex = 0 ;
                car1 = 0;
                lrIndex1=0;
                car2 = +35;
                lrIndex2=0;
                car3 = +70;
                lrIndex3=0;
                score=0;
                //level=0;
            }
             break;

             case 27:
                 exit(0);
             break;
             default:
                break;
        }
}

void timer(int){
    glutPostRedisplay();
    glutTimerFunc(1000/FPS,timer,0);
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);

    glutInitWindowSize(500,650);
    glutInitWindowPosition(200,20);
    glutCreateWindow("Road Runner");

    glutDisplayFunc(display);
    glutSpecialFunc(spe_key);
    glutKeyboardFunc(processKeys );

    glOrtho(0,100,0,100,-1,1);
    glClearColor(0, 255, 0,1);

    glutTimerFunc(1000,timer,0);
    glutMainLoop();

    return 0;
}
