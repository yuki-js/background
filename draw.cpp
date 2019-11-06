#include <GLUT/glut.h>
#include <cstdio>
#include "draw.h"
#include "ai.h"
#include "displaylist.h"
#include "figure.hpp"

const int maxFigures = 8;
const int maxParticles = 64;
const int maxMouseParticles = 64;
int mouseParticlesIndex=0;

double ratio;
Figure2d *figure;
Figure2d *figures[maxFigures];
Figure3d *particles[maxParticles];
Figure3d *mouseParticles[maxMouseParticles];


void drawMain(){
  for (int i = maxFigures; i >= 0; --i) {
    if(figures[i]){
      figures[i]->draw(ratio);
    }
  }
}
void drawBackground(){
  for (int i = maxParticles; i >= 0; --i) {
    if(particles[i]->posY>=-1.1){
      particles[i]->draw();
    }else{
      particles[i] = new Figure3d();
    }
  }
  for (int i = maxMouseParticles; i >= 0; --i) {
    if(mouseParticles[i] && particles[i]->posY>=-1.1){
      mouseParticles[i]->draw();
    }
  }
}
void drawMouse(int x, int y){
  GLint m_viewport[4]={};
  glGetIntegerv( GL_VIEWPORT, m_viewport );
  double sx=(double)x/(double)m_viewport[2]*2.0-1.0;
  double sy=1.0-(double)y/(double)m_viewport[3]*2.0;
  int i = (mouseParticlesIndex++) % maxMouseParticles;
  if(mouseParticles[i]){
    delete mouseParticles[i];
  }
  mouseParticles[i] = new Figure3d(sx,sy);
  
}
void timer(int){
  if(0<ratio && ratio<=1){
    ratio+=0.03;
  }else if(ratio>1){
    ratio=0;
    
  }
  glutPostRedisplay(); // 再描画命令
	glutTimerFunc(1000/fps , timer , 0); // 100ミリ秒後に自身を実行する
}
void beatTimer(int){
  glutTimerFunc(1000*60/bpm , beatTimer , 0);

  
  for (int i = maxFigures; i >= 0; --i) {
    if(figures[i]){
      delete figures[i];
    }
    figures[i] = new Figure2d();
  }
  
  ratio=0.01;
}

void initParticles(){
  for (int i = maxParticles; i >= 0; --i) {
    particles[i] = new Figure3d(screenrnd());
  }
}
