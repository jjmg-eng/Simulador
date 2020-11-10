//***************************************************************************
//                          pvapp.h  -  description
//                             -------------------
//  begin            : dom jun 21 20:38:58 2020
//  generated by     : pvdevelop (C) Lehrig Software Engineering
//  email            : lehrig@t-online.de
//***************************************************************************
#ifndef _PVAPP_H_
#define _PVAPP_H_

#ifdef USE_INETD
static int trace=0; // todo: set trace=0 if you do not want printf() within event loop
#else
static int trace=1; // todo: set trace=0 if you do not want printf() within event loop
#endif

#include "processviewserver.h"
// todo: comment me out
#include "rlmodbusclient.h"
//#include "rlsiemenstcpclient.h"
//#include "rlppiclient.h"
#include "modbusdaemon.h"             // this is generated. Change for name.h -> "name.mkmodbus"
//#include "siemensdaemon.h"            // this is generated
//#include "ppidaemon.h"                // this is generated

int show_mask1(PARAM *p);


//***************************************************************************
// Meu código

#include "stdlib.h"
#include "math.h"
#include "rlthread.h"
#define BG_COLOR 239,235,231

typedef struct
{
  float SIN;
  float TRI;
  float SQR;
  int OSC;
  float x;
  int i;
} TAGS;

#ifdef _MAIN_
rlThread thread;
rlMutex mutex;
TAGS tag;
#else
extern TAGS tag;
#endif

int Ton(int IN, int PT, int *Q);
int Toff(int IN, int PT, int *Q);
int Ftrig(int IN, int *Q);
int Rtrig(int IN, int *Q);
long blkInt(long I, int Ctrl);
short DI_I(long I);
short Integrator(short I, char SET, short VAL, short *Q);
long DIntegrator(long I, char SET, long VAL, long *Q);
int PT1(long I, long T, long *Q);
int P(long I, int Vp, char SET, int VAL);
int PI(long I, int Vp, int TA, char SET, int VAL, long *INT, long *Q);
int PID(long I, int Vp, int Vhf, int TA, int TB, char SET, int VAL, long *INT, long *INT1, long *Q);
int LAG(long I, int V0, int Vp, int TA, char SET, int VAL, long *INT, long *Q);
int LEADLAG(long I, int V0, int Vp, int Vhf, int TA, int TB, char SET, int VAL, long *INT, long *INT1, long *Q);
int WashOut(long I, long T, long *INT, int *Q);
char *describeArc(char *buf, float x, float y, float radius, float startAngle, float endAngle);

// meu código termina aqui
//***************************************************************************


#endif