
#include <stdio.h>

#define CONIOEX	//main.cpp�ȊO��conioex.h���C���N���[�h����Ƃ��͏�ɂ��������
#include "conioex.h"

#include "scene.h"
#include "main.h"


void ResultInit(void)
{

}

void ResultUninit(void)
{

}

void ResultUpdate(void)
{
	//�o�b�N�X�y�[�X�L�[�������ꂽ��
	if (inport(PK_BS))
	{
		//�V�[�����^�C�g����ʂ֐؂�ւ���
		SetScene(SCENE_TITLE);
	}
}

void ResultDraw(void)
{
	gotoxy(1, 1);

	if (GetClearFlag() == 1)
	{
		printf("***********************************\n");
		printf("*          �Q�[���I�[�o�[         *\n");
		printf("***********************************\n");
	}
	else
	{
		printf("***********************************\n");
		printf("*             �N���A�I            *\n");
		printf("***********************************\n");
	}
}
