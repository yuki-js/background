#include <GLUT/glut.h>
#include <cmath>
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include "displaylist.h"
#include "ai.h"
#include "draw.h"

int windowWidth=1920;
int windowHeight=1080;
bool windowMode = false;

int bpm = 65;
double bg = 1.0;
bool bgOnly = false;
void reshape(int w, int h){
  glViewport(0, (h-w)/2, w, w);
}

void display(void){
  if(!windowMode){
    reshape(1920,1080);
  }
	glClearColor (bg, bg, bg, 1.0);  // 消去色指定
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);       // 画面と奥行き情報を初期化  

  //glMatrixMode(GL_PROJECTION);
  //glLoadIdentity();
	//gluPerspective(45.0, 1, 1, 100.0);
  glMatrixMode(GL_MODELVIEW);
  
	glLoadIdentity();
  glPushMatrix();
  drawBackground();
  glPopMatrix();

  glPushMatrix();
  if(!bgOnly)drawMain();
  glPopMatrix();
  
  glutSwapBuffers();
}

void playSound(){
  // omitted
}

void setBpm(int newbpm){
  bpm = newbpm;
}
void setBg(int newbg){
  bg = (double)newbg;
}
void setBgOnly(int){
  bgOnly=true;
}
struct Timer{
  double time;
  void (*func)(int);
  int arg;
};
struct Timer timers[] = {
                         {1000/fps, timer, 0},
                         {1000*60/bpm, beatTimer, 0},
                         {(60*3+10)*1000, exit, 0},
                         {(2*60+3)*1000, setBpm, 130},
                         {(2*60+18)*1000, setBpm, 65},
                         {(60+34)*1000, setBg, 0},
                         {(60+48)*1000, setBg, 1},
                         {(2*60+18)*1000, setBg, 0},
                         {(2*60+35)*1000, setBg, 1},
                         {(2*60+50)*1000, setBgOnly, 1}
};

int main(int argc, char *argv[]){
  //std::srand(std::time(NULL));
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
  if(argc>1 && argv[1][0]=='y'){

    windowMode=true;
    glutInitWindowSize(640 , 360);  // ウィンドウサイズを指定
    glutCreateWindow("AIAIAI");      // ウィンドウを作成
    glutReshapeFunc(reshape);
    reshape(640,360);
  }else{
    glutGameModeString("1920x1080:32@60");
    glutEnterGameMode();
    reshape(1920,1080);
    glutSetCursor(GLUT_CURSOR_NONE);
  }
	glutDisplayFunc(display);       // 表示関数を指定
  glutPassiveMotionFunc(drawMouse);
  for(int i=0;i<sizeof(timers)/sizeof(timers[0]);i++){
    glutTimerFunc(timers[i].time, timers[i].func, timers[i].arg);
  }
  buildDl();
  playSound();
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  glEnable( GL_BLEND );
  initParticles();
	glutMainLoop();                 // イベント待ち
  
	return 0;
}
