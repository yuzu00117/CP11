// main.cpp�ȊO�̂��ׂĂ�.cpp��conioex���g���Ƃ���#define CONIOEX��ǉ�����
#define CONIOEX

#include "main.h"
#include <stdio.h>
#include "conioex.h"
#include "player.h"

PLAYER g_Player;

// �e�̍��W
float g_bulletX;
float g_bulletY;
// ��O�̒e�̍��W
float g_bulletOldX;
float g_bulletOldY;

// �e�����˂���Ă��邩
bool isFire;

void PlayerInit(void)
{
	// �v���C���[����ʂ̒��S�i���炢�j�ɃZ�b�g����
	g_Player.posx = SCREEN_RIGHT / 2;
	g_Player.posy = SCREEN_BOTTOM / 2;
	g_Player.pos_oldx = g_Player.posx;
	g_Player.pos_oldy = g_Player.posy;
	g_Player.speedx = 0.1f;
	g_Player.speedy = 0.06f;

	// ���݂̏ꏊ�Ƀv���C���[��`�悷��
	gotoxy(floatToInt(g_Player.posx), floatToInt(g_Player.posy));
	printf("@");
}

void PlayerUninit(void)
{
}

void PlayerUpdate(void)
{
	// �O����W��ۑ�����
	g_Player.pos_oldx = g_Player.posx;
	g_Player.pos_oldy = g_Player.posy;

	g_bulletOldX = g_bulletX;
	g_bulletOldY = g_bulletY;

	// �L�[�{�[�h�̃J�[�\���L�[���������ꂽ
	if (inport(PK_LEFT))
	{
		g_Player.posx -= g_Player.speedx;
	}
	// ��ʂ���o�Ă����Ȃ��l�ɕ␳����
	if (g_Player.posx < SCREEN_LEFT)
	{
		g_Player.posx = SCREEN_LEFT;
	}

	// �L�[�{�[�h�̃J�[�\���L�[�E�������ꂽ
	if (inport(PK_RIGHT))
	{
		g_Player.posx += g_Player.speedx;
	}
	// ��ʂ���o�Ă����Ȃ��l�ɕ␳����
	if (g_Player.posx > SCREEN_RIGHT)
	{
		g_Player.posx = SCREEN_RIGHT;
	}

	// �L�[�{�[�h�̃J�[�\���L�[�オ�����ꂽ
	if (inport(PK_UP))
	{
		g_Player.posy -= g_Player.speedy;
	}
	// ��ʂ���o�Ă����Ȃ��l�ɕ␳����
	if (g_Player.posy < SCREEN_TOP)
	{
		g_Player.posy = SCREEN_TOP;
	}

	// �L�[�{�[�h�̃J�[�\���L�[���������ꂽ
	if (inport(PK_DOWN))
	{
		g_Player.posy += g_Player.speedy;
	}
	// ��ʂ���o�Ă����Ȃ��l�ɕ␳����
	if (g_Player.posy > SCREEN_BOTTOM)
	{
		g_Player.posy = SCREEN_BOTTOM;
	}

	// �e�𔭎�
	// �t���O���I���ł���Βe���E�Ɉړ������\��
	if (isFire == true)
	{
		g_bulletX += 1.0f;
	}
	// Space�L�[�������ꂽ��t���O���I���ɂ��A���W���v���C���[�̈�E��
	if (inport(PK_SP))
	{
		isFire = true;
		g_bulletX = g_Player.posx + 1;
		g_bulletY = g_Player.posy;
	}
	
	// �e���ǂɓ���������t���O������
	if (g_bulletX < SCREEN_LEFT || g_bulletX > SCREEN_RIGHT)
	{
		gotoxy(floatToInt(g_bulletOldX), floatToInt(g_bulletOldY));
		printf(" ");
		isFire = false;
	}
	if (g_bulletY < SCREEN_TOP || g_bulletY > SCREEN_BOTTOM)
	{
		gotoxy(floatToInt(g_bulletOldX), floatToInt(g_bulletOldY));
		printf(" ");
		isFire = false;
	}
}

void PlayerDraw(void)
{
	// �������W���X�V����Ă�����`����s��
	if ((floatToInt(g_Player.pos_oldx) != floatToInt(g_Player.posx)) ||
		(floatToInt(g_Player.pos_oldy) != floatToInt(g_Player.posy)))
	{
		// �ЂƂO�̏ꏊ�̒e���폜
		gotoxy(floatToInt(g_Player.pos_oldx), floatToInt(g_Player.pos_oldy));
		printf(" ");

		// ���݂̏ꏊ�ɍĕ`��
		gotoxy(floatToInt(g_Player.posx), floatToInt(g_Player.posy));
		printf("@");
	}

	// �e�����˂���Ă���Ƃ�
	if (isFire == true)
	{
		// ���W�̍X�V����������`��
		if ((floatToInt(g_bulletOldX) != floatToInt(g_bulletX)) ||
			(floatToInt(g_bulletOldY) != floatToInt(g_bulletY)))
		{
			// ��O�̏ꏊ
			gotoxy(floatToInt(g_bulletOldX), floatToInt(g_bulletOldY));
			printf(" ");

			// ���݂̏ꏊ
			gotoxy(floatToInt(g_bulletX), floatToInt(g_bulletY));
			printf("=");
		}
	}
}

// g_Player�̃Q�b�^�[�֐�
PLAYER *GetPlayer()
{
	return &g_Player;
}
