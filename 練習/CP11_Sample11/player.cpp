#define CONIOEX

#include "main.h"
#include <stdio.h>
#include "conioex.h"


void PlayerInit(void)
{
	PLAYER* pPlayer = GetPlayer();

	//�v���C���[����ʂ̒��S�i���炢�j�ɃZ�b�g����
	pPlayer->posx = SCREEN_RIGHT / 2;
	pPlayer->posy = SCREEN_BOTTOM / 2;
	pPlayer->pos_oldx = pPlayer->posx;
	pPlayer->pos_oldy = pPlayer->posy;
	pPlayer->speedx = 0.1f;
	(*pPlayer).speedy = 0.06f;

	//���݂̏ꏊ�Ƀv���C���[��`�悷��
	gotoxy(floatToInt(pPlayer->posx), floatToInt(pPlayer->posy));
	printf("@");
}

void PlayerUninit()
{

}

void PlayerUpdate()
{
	PLAYER* pPlayer = GetPlayer();

	//�O����W��ۑ�����
	pPlayer->pos_oldx = pPlayer->posx;
	pPlayer->pos_oldy = pPlayer->posy;

	//�L�[�{�[�h�̃J�[�\���L�[���������ꂽ
	if (inport(PK_LEFT))
	{
		pPlayer->posx -= pPlayer->speedx;
	}
	//��ʂ���o�Ă����Ȃ��l�ɕ␳����
	if (pPlayer->posx < SCREEN_LEFT)
	{
		pPlayer->posx = SCREEN_LEFT;
	}

	//�L�[�{�[�h�̃J�[�\���L�[�E�������ꂽ
	if (inport(PK_RIGHT))
	{
		pPlayer->posx += pPlayer->speedx;
	}
	//��ʂ���o�Ă����Ȃ��l�ɕ␳����
	if (pPlayer->posx > SCREEN_RIGHT)
	{
		pPlayer->posx = SCREEN_RIGHT;
	}

	//�L�[�{�[�h�̃J�[�\���L�[�オ�����ꂽ
	if (inport(PK_UP))
	{
		pPlayer->posy -= pPlayer->speedy;
	}
	//��ʂ���o�Ă����Ȃ��l�ɕ␳����
	if (pPlayer->posy < SCREEN_TOP)
	{
		pPlayer->posy = SCREEN_TOP;
	}

	//�L�[�{�[�h�̃J�[�\���L�[���������ꂽ
	if (inport(PK_DOWN))
	{
		pPlayer->posy += pPlayer->speedy;
	}
	//��ʂ���o�Ă����Ȃ��l�ɕ␳����
	if (pPlayer->posy > SCREEN_BOTTOM)
	{
		pPlayer->posy = SCREEN_BOTTOM;
	}
}

void PlayerDraw()
{
	PLAYER* pPlayer = GetPlayer();

	//��ʃN���A
	//system("cls");

	//�������W���X�V����Ă�����`����s��
	if ((floatToInt(pPlayer->pos_oldx) != floatToInt(pPlayer->posx)) ||
		(floatToInt(pPlayer->pos_oldy) != floatToInt(pPlayer->posy)))
	{
		//�ЂƂO�̏ꏊ
		gotoxy(floatToInt(pPlayer->pos_oldx), floatToInt(pPlayer->pos_oldy));
		printf(" ");

		//���݂̏ꏊ
		gotoxy(floatToInt(pPlayer->posx), floatToInt(pPlayer->posy));
		printf("@");
	}
}