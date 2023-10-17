# include "iGraphics.h"
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int x = 20, y = 0;//duck
int tx1 = 400, ty1 = 100;//tree
int hx = 650, hy = 0;//hunter
int cx1 = 500, cy1 = 450;//cloud
int bgx1 = 10, bgy1 = 400;
int p = 0;//counter
int point;//point
char str[10000];//point to string
int stic_x = 20, stic_y = 10;
int dx = 990, dy = 20;//bullet
int dx1 = 900, dy1 = 100;//bullet 1
int dx2 = 950, dy2 = 200;//bullet 2
int dx3 = 1200, dy3 = 250;//bullet 3
int dx4 = hx, dy4 = hy + 100;//hunter bullet
int die = 0;//die
bool jump = false;//duck jump
bool jump1 = false;//up and down
bool high = false;//up
bool again = false;// permission to jump
bool left = false;//bullet left
bool left1 = false;//bullet1 left
bool left2 = false;//bullet 2 left
bool left3 = false;//bullet 3 left
bool left4 = false;//bullet 4 left
bool start = false;
bool gameover = false;
bool boss = false;
bool help = false;

void iDraw()
{

	iClear();
	if (start == false)
	{
		//start page 
		//background
		iSetColor(10, 20, 5);
		iShowBMP(0,0,"image\\cover.bmp");
		iShowBMP(330, 200, "image\\play.bmp");
		iShowBMP(330, 140, "image\\help.bmp");
		iShowBMP(330, 80, "image\\exit.bmp");
		if (help == true)
		{
			iShowBMP(0, 0, "image\\help1.bmp");
			iShowBMP(340, 20, "image\\back.bmp");

		}
		
	}
	if (start == false && gameover == true)
	{
		//last page game over
		//background
		iSetColor(10, 20, 5);
		iFilledRectangle(0, 0, 800, 600);
		iShowBMP(330, 200, "image\\playagain.bmp");
		iShowBMP(330, 300, "image\\mainmenu.bmp");
		iSetColor(250, 250, 250);
		iText(380, 400, str, GLUT_BITMAP_TIMES_ROMAN_24);
	}

	if (start == true)
	{
		//background
		iSetColor(255, 255, 255);
		iFilledRectangle(0, 0, 800, 600);
		iSetColor(250, 0, 250);
		iShowBMP(tx1, ty1, "image\\tree.bmp");
		iShowBMP(dx1, dy1, "image\\bullet.bmp");
		iShowBMP(dx2, dy2, "image\\bullet.bmp");
		iShowBMP(dx3, dy3, "image\\bullet.bmp");
		iShowBMP(dx, dy, "image\\bullet.bmp");
		if (boss == true){
			iShowBMP(hx, hy, "image\\hunter1.bmp");
			iShowBMP(dx4, dy4, "image\\bullet.bmp");
		}
		iShowBMP(cx1, cy1, "image\\cloud.bmp");
		iShowBMP(x, y, "image\\duck.bmp");
		//life
		iSetColor(250, 0, 0);
		iFilledRectangle(20, 550, die, 10);
		//life bar
		iSetColor(0, 0, 250);
		iRectangle(20, 550, 20, 10);
		iRectangle(20, 550, 40, 10);
		iRectangle(20, 550, 60, 10);
		iRectangle(20, 550, 80, 10);
		iSetColor(0, 0, 0);
		iText(680, 550, str, GLUT_BITMAP_TIMES_ROMAN_24);
		iText(300, 550, "p=pause  , r=resume ", GLUT_BITMAP_TIMES_ROMAN_10);
	}
}

void time()
{
	boss = true;
}
void movement()
{
	if (start == true)
	{
		if (jump == true)
		{
			//duck jump
			if (y < 2)
				jump1 = true;
			if (jump1 == true && again == false)
				high = true;
			if (y > 300)
			{
				high = false;
				again = true;
			}
			if (high == true)
				y += 2;
			if (high == false)
			{
				if (y != 0)
					y -= 2;
			}
		}
		//score
		p++;
		printf("%d", p);
		point = p / 100;
		sprintf_s(str, "Score: %d", point);

		//bullet 1
		if (dx > 800)
			left = true;
		if (left == true)
			dx -= 2;
		if (dx < 0)
			dx = 950;
		//bullet2
		if (dx1 > 800)
			left1 = true;
		if (left1 == true)
			dx1 -= 2;
		if (dx1 < 0)
			dx1 = 850;

		//bullet 3
		if (dx2 > 800)
			left2 = true;
		if (left2 == true)
			dx2 -= 3;
		if (dx2 < 0)
			dx2 = 800;

		//bullet 4
		if (dx3 > 800)
			left3 = true;
		if (left3 == true)
			dx3 -= 4;
		if (dx3<0)
			dx3 = 800;
		if (boss == true)
		{
			if (dx4 >= hx)
				left4 = true;
			if (left4 == true)
				dx4 -= 2;
			if (dx4 < 0)
				dx4 = hx;
		}
		//cloud
		if (cx1 >= -20)
			cx1 -= 2;
		if (cx1<-20)
			cx1 = 830;


		//die
		if (die > 80)
		{
			start = false;
			die = 0;
			x = 0;
			gameover = true;
		}

		
		if (dx <= x + 80 && dx + 20 >= x && dy <= y + 80 && dy + 10 > y)
		{
			die+=20;
			dx = 950;
		}
		if (dx1 <= x + 80 && dx1 + 20 >= x && dy1 <= y + 80 && dy1 + 10 > y)
		{
			die+=20;
			dx1 = 860;
		}
		if (dx2 <= x + 80 && dx2 + 20 >= x && dy2 <= y + 80 && dy2 + 10 > y)
		{
			die+=20;
			dx2 = 900;
		}
		if (dx3 <= x + 80 && dx3 + 20 >= x && dy3 <= y + 80 && dy3 + 10 > y)
		{
			die+=20;
			dx3 = 950;
		}
		if (dx4 <= x + 80 && dx4 + 20 >= x && dy4 <= y + 80 && dy4 + 10 > y)
		{
			die+=20;
			dx4 = hx+20;
		}
		//hunter
		if (hx <= x + 80 && hx + 180 >= x && hy <= y + 80 && hy + 180 > y)
		{
			p += 20;
			boss = false;
		}
	}
}

void iMouseMove(int mx, int my)
{

}

void iMouse(int button, int state, int mx, int my)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if (gameover != true)
		{
			if (mx <= 470 && mx >= 320 && my >= 200 && my <= 240)
			{
				start = true;
				p = 0;
				point = 0;
				sprintf_s(str, "Point: %d", point);
				x = 20, y = 0;
				tx1 = 400, ty1 = 100;
				help = false;
			}
			if (mx <= 470 && mx >= 320 && my >= 140 && my <= 180)
			{
				help = true;
			}
			if (help == true)
			{
				if (mx <= 420 && mx >= 340 && my >= 20 && my <= 60)
				{
					start = false;
					gameover = false;
					help = false;
				}
			}
			if (mx <= 470 && mx >= 320 && my >= 80 && my <= 120)
			{
				if (start == false)
					exit(0);
			}

		}
		if (gameover == true)
		{
			if (mx <= 510 && mx >= 330 && my >= 200 && my <= 260)
			{
				start = true;
				p = 0;
				point = 0;
				sprintf_s(str, "Point: %d", point);
				x = 20, y = 0;
				tx1 = 400, ty1 = 100;
				jump = false;
				jump1 = false;
			}
			if (mx <= 510 && mx >= 330 && my >= 300 && my <= 360)
			{
				start = false;
				gameover = false;
			}
		}
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here	
	}
}

/*
function iKeyboard() is called whenever the user hits a key in keyboard.
key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
	if (key == 'p')
	{
		if (start == true)
			iPauseTimer(0);

	}
	if (key == 'r')
	{
		if (start == true)
			iResumeTimer(0);

	}
	//place your codes for other keys here
}

/*
function iSpecialKeyboard() is called whenver user hits special keys like-
function keys, home, end, pg up, pg down, arraows etc. you have to use
appropriate constants to detect them. A list is:
GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{

	if (key == GLUT_KEY_UP)
	{
		jump = true;
		again = false;
	}
	if (key == GLUT_KEY_DOWN)
	{
		high = false;
		again = true;
	}
	if (key == GLUT_KEY_LEFT)
	{
		if (x > 5)
		{
			x -= 6;
			tx1 += 2;
		
		}
		
	}
	if (key == GLUT_KEY_RIGHT)
	{
		if (x < 720)
		{
			x += 6;
			tx1 -= 2;
		
		}
		
	}
	//place your codes for other keys here
}

int main()
{
	//place your own initialization codes here.
	iSetTimer(1, movement);
	if (boss == false)
	{
		iSetTimer(15000, time);
	}
	PlaySound("music\\quack", NULL, SND_LOOP | SND_ASYNC);
	iInitialize(800, 600, "quack duck");
	return 0;
}

