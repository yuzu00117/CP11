// main.cpp�ȊO�̂��ׂĂ�.cpp��conioex���g���Ƃ���
#define CONIOEX

#include <stdio.h>
#include "main.h"
#include "conioex.h"

void Player_Init(void);	    //������
void Player_Uninit(void);	//�I������
void Player_Update(void);	//�X�V
void Player_Draw(void);	    //�`��

void PlayerInit(void)
{
	PLAYER* pPlayer = GetPlayer();

    //�v���C���[����ʂ̒��S�i���炢�j�ɃZ�b�g����
	pPlayer->posx = SCREEN_RIGHT / 2;
	pPlayer->posy = SCREEN_BOTTOM / 2;
	pPlayer->pos_oldx = pPlayer->posx;
	pPlayer->pos_oldy = pPlayer->posy;
	pPlayer->speedx = 0.1f;
	pPlayer->speedy = 0.06f;

	//���݂̏ꏊ�Ƀv���C���[��`�悷��
	gotoxy(floatToInt(pPlayer->posx), floatToInt(pPlayer->posy));
	printf("@");

}