//main.cpp�ȊO�̂��ׂĂ�.cpp��conioex���g���Ƃ���#define CONIOEX��ǉ�����
#define CONIOEX

#include "enemy.h"
#include "main.h"
#include <stdio.h>
#include "conioex.h"


ENEMY g_Enemy[NUM_ENEMY];


void EnemyInit(void)
{
	//�G�l�~�[���W�������_���ɃZ�b�g����
	for (int i = 0; i < NUM_ENEMY; i++)
	{
		g_Enemy[i].posx = rand() % SCREEN_RIGHT + 1;//1�`40�̃����_��
		g_Enemy[i].posy = rand() % SCREEN_BOTTOM + 1;//1�`20�̃����_��
		g_Enemy[i].pos_oldx = g_Enemy[i].posx;
		g_Enemy[i].pos_oldy = g_Enemy[i].posy;
		g_Enemy[i].speedx = (float)(rand() % 1000) / 10000;
		g_Enemy[i].speedy = (float)(rand() % 1000) / 20000;
		g_Enemy[i].use = 1;//�����t���O�I��

		//���݂̏ꏊ�ɃG�l�~�[��`�悷��
		gotoxy(floatToInt(g_Enemy[i].posx), floatToInt(g_Enemy[i].posy));
		printf("#");
	}
}


void EnemyUninit(void)
{

}


void EnemyUpdate(void)
{
	for (int i = 0; i < NUM_ENEMY; i++)
	{
		//i�Ԗڂ̓G�̐����t���O���I�t�Ȃ牽�����Ȃ�
		if (g_Enemy[i].use == 0)
			continue;

		//�O����W��ۑ�����
		g_Enemy[i].pos_oldx = g_Enemy[i].posx;
		g_Enemy[i].pos_oldy = g_Enemy[i].posy;

		//�G�l�~�[���W��g_Enemy.speed�̂Ԃ񑝂₷
		g_Enemy[i].posx += g_Enemy[i].speedx;
		g_Enemy[i].posy += g_Enemy[i].speedy;

		//SCREEN_RIGHT��SCREEN_LEFT�Œ��˕Ԃ�
		if (g_Enemy[i].posx > SCREEN_RIGHT || g_Enemy[i].posx < SCREEN_LEFT)
		{
			//X�̈ړ������𔽓]������
			g_Enemy[i].speedx *= -1;
		}

		//SCREEN_TOP��SCREEN_BOTTOM�Œ��˕Ԃ�
		if (g_Enemy[i].posy > SCREEN_BOTTOM || g_Enemy[i].posy < SCREEN_TOP)
		{
			//Y�̈ړ������𔽓]������
			g_Enemy[i].speedy *= -1;
		}
	}
}


void EnemyDraw(void)
{
	for (int i = 0; i < NUM_ENEMY; i++)
	{
		//i�Ԗڂ̓G�̐����t���O���I�t�Ȃ牽�����Ȃ�
		if (g_Enemy[i].use == 0)
			continue;

		//�������W���X�V����Ă�����`����s��
		if ((floatToInt(g_Enemy[i].pos_oldx) != floatToInt(g_Enemy[i].posx)) ||
			(floatToInt(g_Enemy[i].pos_oldy) != floatToInt(g_Enemy[i].posy)))
		{
			//�ЂƂO�̏ꏊ
			gotoxy(floatToInt(g_Enemy[i].pos_oldx), floatToInt(g_Enemy[i].pos_oldy));
			printf(" ");

			//���݂̏ꏊ
			gotoxy(floatToInt(g_Enemy[i].posx), floatToInt(g_Enemy[i].posy));
			printf("#");
		}
	}
}


void EnemyDelete(int id)
{
	//�����t���O���I�t�ɂ���
	g_Enemy[id].use = 0;

	//�G�̕\���������I�ɍ폜
	gotoxy(floatToInt(g_Enemy[id].posx), floatToInt(g_Enemy[id].posy));
	printf(" ");
}


//g_Enemy[]�̃Q�b�^�[�֐�
ENEMY* GetEnemy()
{
	return g_Enemy;
}
