
#include "explosion.h"

#define CONIOEX
#include "conioex.h"

#include "main.h"
#include <stdio.h>


//*******************************************
//�O���[�o���ϐ�
//*******************************************
EXPLOSION g_Explosion;


void ExplosionInit(void)
{
	g_Explosion.posx = 0;
	g_Explosion.posy = 0;

	g_Explosion.frame = 0;

	g_Explosion.use = 0;
}


void ExplosionUninit(void)
{

}


void ExplosionUpdate(void)
{

}


void ExplosionDraw(void)
{
	//use�t���O���I���ł���Ε`����s��
	if (g_Explosion.use != 0)
	{
		gotoxy(floatToInt(g_Explosion.posx), floatToInt(g_Explosion.posy));

		//�A�j���[�V�����p�^�[���\��
		if (g_Explosion.frame < 5)
			printf("=");
		else if(g_Explosion.frame < 10)
			printf("*");
		else
			printf("-");

		//���Ԍo��
		g_Explosion.frame++;

		//���Ԍo�߂ŕ\��������
		if (g_Explosion.frame > 15)
		{
			//use�t���O�I�t
			g_Explosion.use = 0;

			//�\���폜
			gotoxy(floatToInt(g_Explosion.posx), floatToInt(g_Explosion.posy));
			printf(" ");
		}
	}
}


void ExplosionStart(float posx, float posy)
{
	//���݃A�j���[�V���������s���Ă��Ȃ��Ȃ�V�����Z�b�g����
	if (g_Explosion.use == 0)
	{
		g_Explosion.posx = posx;
		g_Explosion.posy = posy;
		g_Explosion.frame = 0;//�o�ߎ��Ԃ����Z�b�g����
		g_Explosion.use = 1;//use�t���O�I��
	}
}