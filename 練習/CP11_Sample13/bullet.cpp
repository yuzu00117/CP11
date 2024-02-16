//main.cpp�ȊO�̂��ׂĂ�.cpp��conioex���g���Ƃ���#define CONIOEX��ǉ�����
#define CONIOEX

#include "bullet.h"
#include "main.h"
#include <stdio.h>
#include "conioex.h"


BULLET g_Bullet;


void BulletInit(void)
{
	//�G�l�~�[���W�������_���ɃZ�b�g����
	g_Bullet.posx = 1;
	g_Bullet.posy = 1;
	g_Bullet.pos_oldx = g_Bullet.posx;
	g_Bullet.pos_oldy = g_Bullet.posy;
	g_Bullet.speedx = 1.0f;
	g_Bullet.speedy = 0.0f;
	g_Bullet.use = 0;//�ŏ��͕\������Ă��Ȃ��̂Ńt���O�I�t
}


void BulletUninit(void)
{

}


void BulletUpdate(void)
{
	//�O��l�̕ۑ�
	g_Bullet.pos_oldx = g_Bullet.posx;
	g_Bullet.pos_oldy = g_Bullet.posy;


	//�e�̍��W�X�V
	if (g_Bullet.use == 1)
	{
		g_Bullet.posx += g_Bullet.speedx;
	}
}


void BulletDraw(void)
{
	//�e�����˒��ł���Ε`����s��
	if (g_Bullet.use == 1)
	{
		//�E�[�̕ǁi40�j���e�̍��W���傫���Ȃ���
		if (floatToInt(g_Bullet.posx) > SCREEN_RIGHT)
		{
			//�ǂɓ��������̂Œe�����ł�����
			g_Bullet.use = 0;
			//�G������
			gotoxy(floatToInt(g_Bullet.pos_oldx), floatToInt(g_Bullet.pos_oldy));
			printf(" ");
		}
		else
		{
			//�������W���X�V����Ă�����`����s��
			if ((floatToInt(g_Bullet.pos_oldx) != floatToInt(g_Bullet.posx)) ||
				(floatToInt(g_Bullet.pos_oldy) != floatToInt(g_Bullet.posy)))
			{
				//�ЂƂO�̏ꏊ
				gotoxy(floatToInt(g_Bullet.pos_oldx), floatToInt(g_Bullet.pos_oldy));
				printf(" ");

				//���݂̏ꏊ
				gotoxy(floatToInt(g_Bullet.posx), floatToInt(g_Bullet.posy));
				printf("=");
			}
		}
	}
}


void BulletShot(float player_x, float player_y)
{
	//�e���g�p���̏ꍇ�͎��s���Ȃ�
	if (g_Bullet.use == 0)
	{
		g_Bullet.use = 1;//�e�̃X�e�[�^�X�𔭎˒��ɕύX����
		g_Bullet.posx = floatToInt(player_x) + 1;//�v���C���[���W�̂ЂƂE������e�𔭎˂���
		g_Bullet.posy = player_y;//�c�̓v���C���[�ƈꏏ
	}
}


void BulletDelete(void)
{
	//�e�̃X�e�[�^�X�𖢎g�p��ԂɍX�V����
	g_Bullet.use = 0;

	//�e�̕\���������I�ɍ폜
	gotoxy(floatToInt(g_Bullet.pos_oldx), floatToInt(g_Bullet.pos_oldy));
	printf(" ");
}


//g_Bullet�̃Q�b�^�[�֐�
BULLET* GetBullet()
{
	return &g_Bullet;
}
