#ifndef AI_H
#define AI_H

#define GL_SILENCE_DEPRECATION 1

const int fps=30;
extern int bpm;



#define RND ((double)rand() / ((double)RAND_MAX))
#define PNRND (((double)rand() / ((double)RAND_MAX)) * 2.0 - 1.0)

void display(void);
void playSound(void);

#endif /* AI_H */
