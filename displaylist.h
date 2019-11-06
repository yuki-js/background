#ifndef DISPLAYLIST_H
#define DISPLAYLIST_H

void buildDl(void);

const int id_dlWireCircle = 1;
void dlWireCircle(void);

const int id_dlWireRect = 2;
void dlWireRect(void);

const int id_dlWireTriangle = 3;
void dlWireTriangle(void);

const int id_dlWireHexagon = 4;
void dlWireHexagon(void);

const int id_dlSolidCircle = 5;
void dlSolidCircle(void);

const int id_dlSolidRect = 6;
void dlSolidRect(void);

const int id_dlSolidTriangle = 7;
void dlSolidTriangle(void);

const int id_dlSolidHexagon = 8;
void dlSolidHexagon(void);


#endif /* DISPLAYLIST_H */
