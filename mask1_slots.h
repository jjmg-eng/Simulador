//###############################################################
//# mask1_slots.h for ProcessViewServer created: dom jun 21 20:38:58 2020
//# please fill out these slots
//# here you find all possible events
//# Yours: Lehrig Software Engineering
//###############################################################

// todo: uncomment me if you want to use this data aquisiton
// also uncomment this classes in main.cpp and pvapp.h
// also remember to uncomment rllib in the project file
//extern rlModbusClient     modbus;  //Change if applicable
//extern rlSiemensTCPClient siemensTCP;
//extern rlPPIClient        ppi;
#include "rlsvganimator.h"

int drawSVG(PARAM *p, int id,rlSvgAnimator *s)
{
	if(s->isModified == 0) return 0;
	gBeginDraw(p,id);
	s->writeSocket();
	gEndDraw(p);
	return 0;
}

int initSVG(PARAM *p, int id, rlSvgAnimator *s, const char *filename, int x, int y, int w, int h)
{
	pvSetGeometry(p,id,x,y,w,h);
	s->setSocket(&p->s);
	s->setId(id);
	s->read(filename);
	return 0;	
}

typedef struct // (todo: define your data structure here)
{
 rlSvgAnimator s,m;
 int Q1,Q2;
}
DATA;

#define SCALE 5
static int slotInit(PARAM *p, DATA *d)
{
  if(p == NULL || d == NULL) return -1;
  memset(d,0,sizeof(DATA));
  initSVG(p,obj1,&d->s,"unifilar.svg",21,9,30*SCALE,30*SCALE);
  initSVG(p,obj2,&d->m,"medidor.svg",81,318,110,55);
  pvSetBackgroundColor(p,obj1,BG_COLOR);
  pvSetBackgroundColor(p,obj2,BG_COLOR);
  d->s.setScale(SCALE); // seu desenho é muito pequeno
  d->s.setWindowSize(30,30);
  //d->s.setXY0(-100,0);
  d->s.setMainObject("main");
  //d->s.setMainObjectMatrix();
  d->s.setMatrix ("main", SCALE, 0*acos(-1)/180, 0, 0, SCALE*15, SCALE*15);
  return 0;
}

static int slotNullEvent(PARAM *p, DATA *d)
{
  static int alpha=0;
  char buf[80];
  if(p == NULL || d == NULL) return -1;
  if (Rtrig(tag.OSC,&d->Q1)) d->s.svgChangeStyleOption("barra1","stroke:","#ff0000");
  if (Ftrig(tag.OSC,&d->Q2)) d->s.svgChangeStyleOption("barra1","stroke:","#00ff00");
  d->s.setMatrix ("main", SCALE, alpha*acos(-1)/180, -50, -5, SCALE*29.109489,SCALE*(12.896401));
    alpha+= alpha==330 ? -345 : 15;
  drawSVG(p,obj1,&d->s);

  d->m.svgPrintf("VAL","d=","%s",describeArc(buf, 84.288689, 125.02084, 50, 180, 180+((tag.TRI+100)/200.0*180))); 
  d->m.svgTextPrintf("TAG","%4.0f",tag.TRI);
  d->m.setMatrix ("NEEDLE", 1, tag.TRI/100.0*90*acos(-1)/180, 0,0, 84.288689,125.02084);
  drawSVG(p,obj2,&d->m);
  return 0;
}

static int slotButtonEvent(PARAM *p, int id, DATA *d)
{
  if(p == NULL || id == 0 || d == NULL) return -1;
  return 0;
}

static int slotButtonPressedEvent(PARAM *p, int id, DATA *d)
{
  if(p == NULL || id == 0 || d == NULL) return -1;
  return 0;
}

static int slotButtonReleasedEvent(PARAM *p, int id, DATA *d)
{
  if(p == NULL || id == 0 || d == NULL) return -1;
  return 0;
}

static int slotTextEvent(PARAM *p, int id, DATA *d, const char *text)
{
  if(p == NULL || id == 0 || d == NULL || text == NULL) return -1;
  return 0;
}

static int slotSliderEvent(PARAM *p, int id, DATA *d, int val)
{
  if(p == NULL || id == 0 || d == NULL || val < -1000) return -1;
  return 0;
}

static int slotCheckboxEvent(PARAM *p, int id, DATA *d, const char *text)
{
  if(p == NULL || id == 0 || d == NULL || text == NULL) return -1;
  return 0;
}

static int slotRadioButtonEvent(PARAM *p, int id, DATA *d, const char *text)
{
  if(p == NULL || id == 0 || d == NULL || text == NULL) return -1;
  return 0;
}

static int slotGlInitializeEvent(PARAM *p, int id, DATA *d)
{
  if(p == NULL || id == 0 || d == NULL) return -1;
  return 0;
}

static int slotGlPaintEvent(PARAM *p, int id, DATA *d)
{
  if(p == NULL || id == 0 || d == NULL) return -1;
  return 0;
}

static int slotGlResizeEvent(PARAM *p, int id, DATA *d, int width, int height)
{
  if(p == NULL || id == 0 || d == NULL || width < 0 || height < 0) return -1;
  return 0;
}

static int slotGlIdleEvent(PARAM *p, int id, DATA *d)
{
  if(p == NULL || id == 0 || d == NULL) return -1;
  return 0;
}

static int slotTabEvent(PARAM *p, int id, DATA *d, int val)
{
  if(p == NULL || id == 0 || d == NULL || val < -1000) return -1;
  return 0;
}

static int slotTableTextEvent(PARAM *p, int id, DATA *d, int x, int y, const char *text)
{
  if(p == NULL || id == 0 || d == NULL || x < -1000 || y < -1000 || text == NULL) return -1;
  return 0;
}

static int slotTableClickedEvent(PARAM *p, int id, DATA *d, int x, int y, int button)
{
  if(p == NULL || id == 0 || d == NULL || x < -1000 || y < -1000 || button < 0) return -1;
  return 0;
}

static int slotSelectionEvent(PARAM *p, int id, DATA *d, int val, const char *text)
{
  if(p == NULL || id == 0 || d == NULL || val < -1000 || text == NULL) return -1;
  return 0;
}

static int slotClipboardEvent(PARAM *p, int id, DATA *d, int val)
{
  if(p == NULL || id == -1 || d == NULL || val < -1000) return -1;
  return 0;
}

static int slotRightMouseEvent(PARAM *p, int id, DATA *d, const char *text)
{
  if(p == NULL || id == 0 || d == NULL || text == NULL) return -1;
  //pvPopupMenu(p,-1,"Menu1,Menu2,,Menu3");
  return 0;
}

static int slotKeyboardEvent(PARAM *p, int id, DATA *d, int val, int modifier)
{
  if(p == NULL || id == 0 || d == NULL || val < -1000 || modifier < -1000) return -1;
  return 0;
}

static int slotMouseMovedEvent(PARAM *p, int id, DATA *d, float x, float y)
{
  if(p == NULL || id == 0 || d == NULL || x < -1000 || y < -1000) return -1;
  return 0;
}

static int slotMousePressedEvent(PARAM *p, int id, DATA *d, float x, float y)
{
  if(p == NULL || id == 0 || d == NULL || x < -1000 || y < -1000) return -1;
  return 0;
}

static int slotMouseReleasedEvent(PARAM *p, int id, DATA *d, float x, float y)
{
  if(p == NULL || id == 0 || d == NULL || x < -1000 || y < -1000) return -1;
  return 0;
}

static int slotMouseOverEvent(PARAM *p, int id, DATA *d, int enter)
{
  if(p == NULL || id == 0 || d == NULL || enter < -1000) return -1;
  return 0;
}

static int slotUserEvent(PARAM *p, int id, DATA *d, const char *text)
{
  if(p == NULL || id == 0 || d == NULL || text == NULL) return -1;
  return 0;
}
