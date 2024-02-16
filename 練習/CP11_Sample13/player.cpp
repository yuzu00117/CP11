//main.cpp�ȊO�̂��ׂĂ�.cpp��conioex���g���Ƃ���#define CONIOEX��ǉ�����
#define CONIOEX

#include "main.h"
#include <stdio.h>
#include "conioex.h"
#include "player.h"
#include "bullet.h"


//�v���C���[�p�f�[�^
PLAYER g_Player;

struct BLOCK
{
	int posx;
	int posy;
};

BLOCK g_Block;

void PlayerInit(void)
{
	//�v���C���[����ʂ̒��S�i���炢�j�ɃZ�b�g����
	g_Player.posx = SCREEN_RIGHT / 2;
	g_Player.posy = SCREEN_BOTTOM / 2;
	g_Player.pos_oldx = g_Player.posx;
	g_Player.pos_oldy = g_Player.posy;
	g_Player.speedx = 0.1f;
	g_Player.speedy = 0.06f;

	g_Player.maxhp = 3;
	g_Player.hp = g_Player.maxhp;

	g_Player.jump_pow = 0.0f;
	g_Player.gravity = 0.1f;
	g_Player.is_ground = 1;

	//���݂̏ꏊ�Ƀv���C���[��`�悷��
	gotoxy(floatToInt(g_Player.posx), floatToInt(g_Player.posy));
	printf("@");

	// �u���b�N�̂�����W��ݒ�
	g_Block.posx = 20;
	g_Block.posy = 8;
}

void PlayerUninit(void)
{

}

void PlayerUpdate(void)
{
	//�O����W��ۑ�����
	g_Player.pos_oldx = g_Player.posx;
	g_Player.pos_oldy = g_Player.posy;

	//�L�[�{�[�h�̃J�[�\���L�[���������ꂽ
	if (inport(PK_LEFT))
	{
		g_Player.posx -= g_Player.speedx;
	}
	//��ʂ���o�Ă����Ȃ��l�ɕ␳����
	if (g_Player.posx < SCREEN_LEFT)
	{
		g_Player.posx = SCREEN_LEFT;
	}

	//�L�[�{�[�h�̃J�[�\���L�[�E�������ꂽ
	if (inport(PK_RIGHT))
	{
		g_Player.posx += g_Player.speedx;
	}
	//��ʂ���o�Ă����Ȃ��l�ɕ␳����
	if (g_Player.posx > SCREEN_RIGHT)
	{
		g_Player.posx = SCREEN_RIGHT;
	}

	// �����ɉ����Ȃ��ꍇ
	if (g_Player.posy < (SCREEN_BOTTOM / 2))
	{
		if (floatToInt(g_Player.posy + 1.0f) != g_Block.posy ||
			floatToInt(g_Player.posx) != g_Block.posx)
		{
			if (g_Player.is_ground == 1)
			{
				g_Player.jump_pow = 0.0f;//�W�����v�͂�ݒ�
				g_Player.gravity = 0.1f;
				g_Player.is_ground = 0;//�ڒn�t���O�I�t
			}
		}
	}

	//�W�����v����
	if (inport(PK_SP) && (g_Player.is_ground == 1))
	{
		g_Player.jump_pow = 1.0f;//�W�����v�͂�ݒ�
		g_Player.gravity = 0.1f;
		g_Player.is_ground = 0;//�ڒn�t���O�I�t
	}

	//�ڒn���Ă��Ȃ��Ȃ�
	if (g_Player.is_ground == 0)
	{
		//�W�����v�͕��̍�����ς���
		g_Player.posy -= g_Player.jump_pow;
		//�W�����v�͂��d�͂̕���������������
		g_Player.jump_pow -= g_Player.gravity;

		// �u���b�N�Ƃ̐ڒn�`�F�b�N
		if (floatToInt(g_Player.posy + 1.0f) == g_Block.posy &&
			floatToInt(g_Player.posx) == g_Block.posx)
		{
			g_Player.posy = (g_Block.posy - 1);
			g_Player.is_ground = 1;
		}
		
		//�ڒn�`�F�b�N
		if (g_Player.posy > (SCREEN_BOTTOM / 2))
		{
			g_Player.posy = (SCREEN_BOTTOM / 2);
			g_Player.is_ground = 1;
		}
	}
}

void PlayerDraw(void)
{
	//�������W���X�V����Ă�����`����s��
	if ((floatToInt(g_Player.pos_oldx) != floatToInt(g_Player.posx)) ||
		(floatToInt(g_Player.pos_oldy) != floatToInt(g_Player.posy)))
	{
		//�ЂƂO�̏ꏊ
		gotoxy(floatToInt(g_Player.pos_oldx), floatToInt(g_Player.pos_oldy));
		printf(" ");

		//���݂̏ꏊ
		gotoxy(floatToInt(g_Player.posx), floatToInt(g_Player.posy));
		printf("@");
	}

	gotoxy(1, 11);
	printf("########################################");
	gotoxy(20, 8);
	printf("########");
}


void PlayerDrawHP(void)
{
	gotoxy(1, 22);
	printf("PlayerHP : %d", g_Player.hp);
}


//g_Player�̃Q�b�^�[�֐�
PLAYER* GetPlayer()
{
	return &g_Player;
}


void PlayerDamage(void)
{
	//�v���C���[�̃q�b�g�|�C���g��1����
	g_Player.hp--;
}


int PlayerGetHP(void)
{
	//���݂�HP��Ԃ�
	return g_Player.hp;
}

void PlayerHeal(void)
{
	g_Player.hp = g_Player.maxhp;
}
