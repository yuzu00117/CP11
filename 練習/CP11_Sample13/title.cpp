
#include <stdio.h>

#define CONIOEX	//main.cpp�ȊO��conioex.h���C���N���[�h����Ƃ��͏�ɂ��������
#include "conioex.h"

#include "scene.h"


void TitleInit(void)
{

}

void TitleUninit(void)
{

}

void TitleUpdate(void)
{
	//�G���^�[�L�[�������ꂽ��
	if (inport(PK_ENTER))
	{
		//�V�[�����Q�[���{�҂֐؂�ւ���
		SetScene(SCENE_GAME);
	}
}

void TitleDraw(void)
{
	gotoxy(1, 1);

	printf("***********************************\n");
	printf("*          �^�C�g�����           *\n");
	printf("***********************************\n");
}
