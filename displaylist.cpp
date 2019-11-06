#include "displaylist.h"

#include <GLUT/glut.h>
#include <cmath>


void buildDl(){
  dlWireCircle();
  dlWireRect();
  dlWireTriangle();
  dlWireHexagon();

  dlSolidCircle();
  dlSolidRect();
  dlSolidTriangle();
  dlSolidHexagon();
}

void dlWireCircle(){
  glNewList(id_dlWireCircle, GL_COMPILE);

  glBegin(GL_LINE_LOOP);
  for(int i = 0; i < 360; i++) {
		double x = cos(i * M_PI /180.0);
		double y = sin(i * M_PI /180.0);
    glVertex2d(x,y); 
	}

  glEnd();
  glEndList();
}
void dlWireRect(){
  glNewList(id_dlWireRect, GL_COMPILE);

  glBegin(GL_LINE_LOOP);
  glVertex3d(-1,-1,0);
  glVertex3d(1,-1,0);
  glVertex3d(1,1,0);
  glVertex3d(-1,1,0);

  glEnd();
  glEndList();
}
void dlWireTriangle(){
  glNewList(id_dlWireTriangle, GL_COMPILE);

  glBegin(GL_LINE_LOOP);
  glVertex3d(-0.9, -0.8, 0); // 頂点位置の指定(1つめ)
  glVertex3d( 0.9, -0.8, 0); // 頂点位置の指定(2つめ)
  glVertex3d( 0.0,  0.8, 0); // 頂点位置の指定(3つめ)

  glEnd();
  glEndList();
}
void dlWireHexagon(){
  glNewList(id_dlWireHexagon, GL_COMPILE);

  glBegin(GL_LINE_LOOP);
  for(int i = 0; i < 360; i+=60) {
		double x = cos(i * M_PI /180.0);
		double y = sin(i * M_PI /180.0);
    glVertex2d(x,y); 
	}

  glEnd();
  glEndList();
}
void dlSolidCircle(){
  glNewList(id_dlSolidCircle, GL_COMPILE);

  glBegin(GL_POLYGON);
  for(int i = 0; i < 360; i++) {
		double x = cos(i * M_PI /180.0);
		double y = sin(i * M_PI /180.0);
    glVertex2d(x,y); 
	}

  glEnd();
  glEndList();
}
void dlSolidRect(){
  glNewList(id_dlSolidRect, GL_COMPILE);

  glBegin(GL_POLYGON);
  glVertex3d(-1,-1,0);
  glVertex3d(1,-1,0);
  glVertex3d(1,1,0);
  glVertex3d(-1,1,0);

  glEnd();
  glEndList();
}
void dlSolidTriangle(){
  glNewList(id_dlSolidTriangle, GL_COMPILE);

  glBegin(GL_POLYGON);
  glVertex3d(-0.9, -0.8, 0); // 頂点位置の指定(1つめ)
  glVertex3d( 0.9, -0.8, 0); // 頂点位置の指定(2つめ)
  glVertex3d( 0.0,  0.8, 0); // 頂点位置の指定(3つめ)

  glEnd();
  glEndList();
}
void dlSolidHexagon(){
  glNewList(id_dlSolidHexagon, GL_COMPILE);

  glBegin(GL_POLYGON);
  for(int i = 0; i < 360; i+=60) {
		double x = cos(i * M_PI /180.0);
		double y = sin(i * M_PI /180.0);
    glVertex2d(x,y); 
	}

  glEnd();
  glEndList();
}
