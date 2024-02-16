// main.cpp�ȊO�̂��ׂĂ�.cpp��conioex���g���Ƃ���#define CONIOEX��ǉ�����
#define CONIOEX

#include "bullet.h"
#include "main.h"
#include <stdio.h>
#include "conioex.h"

BULLET g_Bullet;

void BulletInit(void)
{
	// �G�l�~�[���W�������_���ɃZ�b�g����
		g_Bullet.posx = 1;
		g_Bullet.posy = 1;
		g_Bullet.pos_oldx = g_Bullet.posx;
		g_Bullet.pos_oldy = g_Bullet.posy;
		g_Bullet.speedx = 1.0f;
		g_Bullet.speedy = 1.0f;
		g_Bullet.isFire = false // �f�t�H���g�̓I�t
	}
}

void BulletUninit(void)
{
}

void BulletUpdate(void)
{
	g_Bullet.pos_oldx = g_Bullet.posx;
	g_Bullet.pos_oldy = g_Bullet.posy;

	// �e�̍��W�X�V
	if (g_Bullet.g_Bullet.isFire == true)
	{
		g_Bullet.posx += g_Bullet.speedx;
	}
}

void BulletDraw(void)
{
	// �e�����˂���Ă���Ƃ�
	if (g_Bullet.g_Bullet.isFire == true)
	{
		// ���W�̍X�V����������`��
		if ((floatToInt(g_Bullet.pos_oldx) != floatToInt(g_Bullet.posx)) ||
			(floatToInt(g_Bullet.pos_oldy) != floatToInt(g_Bullet.posy)))
		{
			// ��O�̏ꏊ
			gotoxy(floatToInt(g_Bullet.pos_oldx), floatToInt(g_Bullet.pos_oldy));
			printf(" ");

			// ���݂̏ꏊ
			gotoxy(floatToInt(g_Bullet.posx), floatToInt(g_Bullet.posy));
			printf("=");
		}
	}
}

void BulletDelete(int id)
{
	// �e���ǂɓ���������t���O������
	if (g_Bullet.posx < SCREEN_LEFT || g_Bullet.posx > SCREEN_RIGHT)
	{
		gotoxy(floatToInt(g_Bullet.pos_oldx), floatToInt(g_bulletOldY));
		printf(" ");
		g_Bullet.isFire = false;
	}
	if (g_Bullet.posy < SCREEN_TOP || g_Bullet.posy > SCREEN_BOTTOM)
	{
		gotoxy(floatToInt(g_Bullet.pos_oldx), floatToInt(g_bulletOldY));
		printf(" ");
		g_Bullet.isFire = false;
	}
}

// g_Bullet[]�̃Q�b�^�[�֐�
BULLET *GetBullet()
{
	return g_Bullet;
}
