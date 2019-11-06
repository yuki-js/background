#ifndef FIGURE_H
#define FIGURE_H
#include <GLUT/glut.h>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#define GL_SILENCE_DEPRECATION 1

struct FigureColor{
  uint8_t r;
  uint8_t g;
  uint8_t b;
};
struct FigureColor colors[] =
  {
   {0,255,0},
   {255,0,0},
   {0,0,255}
  };

double rnd(){ // return [0,1) random
  return (double)rand() / ((double)RAND_MAX);
}
double screenrnd(){ // return [-1,1)
  return (double)rand() / ((double)RAND_MAX)*2.0 - 1.0;
}
double pnrnd(){ // return -1 or 1 randomly
  if(rnd()<0.5){
    return 1;
  }else{
    return -1;
  }
}


class Figure{
public:
  int dlId;
  int color;
public:
  Figure(){
    dlId=1 + (rand() % 8);
    color=rand() % (int)(sizeof(colors)/sizeof(colors[0]));
    
  }
};

class Figure2d : public Figure{
public:
  double posX;
  double posY;
  int maxDeg;
  
  double maxSize;
public:
  Figure2d() : Figure(){
    posX=screenrnd();
    posY=screenrnd();
    maxDeg = pnrnd()*60;
    
    maxSize=rnd()*0.5+0.2;
  }
  double curve(double ratioRaw){
    return sin(ratioRaw*1.5);
  }
  void draw(double ratioRaw){
    if(ratioRaw>1){
      return;
    }
    ratioRaw+=0.01;
    double ratio=curve(ratioRaw);
    glColor4f((float)colors[color].r/255.0f, (float)colors[color].g/255.0f, (float)colors[color].b/255.0f, 1.0f-(float)ratio);
    glPushMatrix();
    glLoadIdentity();
    glTranslated(posX,posY,0);
    glRotated(maxDeg*ratio, 0,0,1);
    glScaled(maxSize*ratio,maxSize*ratio, 1);
    glCallList(dlId);
    glPopMatrix();
  }
  ~Figure2d(){
    
  }
};
const double size = 0.02;

class Figure3d : public Figure{
public:
  double posX;
  double posY;
  double posZ;
  double rotVecX;
  double rotVecY;
  double rotVecZ;
  double tangent;
public:
  Figure3d():Figure(){
    posX = screenrnd();
    posY = screenrnd()+2;
    posZ = 0.8;
    rotVecX = screenrnd();
    rotVecY = screenrnd();
    rotVecZ = screenrnd();
    tangent = 0.3*screenrnd();
  }
  Figure3d(double defPosY):Figure(){
    posX = screenrnd();
    
    posZ = 0.8;
    rotVecX = screenrnd();
    rotVecY = screenrnd();
    rotVecZ = screenrnd();
    tangent = 0.3*screenrnd();
    posY=defPosY;
  }
  Figure3d(double defPosX, double defPosY):Figure(){
    posZ = 0.8;
    rotVecX = screenrnd();
    rotVecY = screenrnd();
    rotVecZ = screenrnd();
    tangent = 0.3*screenrnd();
    posX=defPosX;
    posY=defPosY;
  }
  void draw(){
    posY-=0.001;
    
    glPushMatrix();
    glColor4f((float)colors[color].r/255.0f, (float)colors[color].g/255.0f, (float)colors[color].b/255.0f, 0.7f);
    //glColor3f(0,0,0);
    glLoadIdentity();
    glTranslated(posX+tangent*posY, posY, 0);
    glRotated(posY*1000, rotVecX, rotVecY, rotVecZ);
    
    glScaled(size, size, 1);
    glCallList(dlId);
    glPopMatrix();
  }
};

#endif /* FIGURE_H */
