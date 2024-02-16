//main.cpp�ȊO�̂��ׂĂ�.cpp��conioex���g���Ƃ���#define CONIOEX��ǉ�����
#define CONIOEX

#include "item.h"
#include "main.h"
#include <stdio.h>
#include "conioex.h"


ITEM g_Item[NUM_ITEM];


void ItemInit(void)
{
	for (int i = 0; i < NUM_ITEM; i++)
	{
		//�A�C�e�����W�������_���ɃZ�b�g����
		g_Item[i].posx = rand() % SCREEN_RIGHT + 1;//1�`40�̃����_��
		g_Item[i].posy = rand() % SCREEN_BOTTOM + 1;//1�`20�̃����_��
		g_Item[i].use = 1;
	}
}


void ItemUninit(void)
{

}


void ItemUpdate(void)
{

}


void ItemDraw(void)
{
	for (int i = 0; i < NUM_ITEM; i++)
	{
		if (g_Item[i].use == 1)
		{
			//���݂̏ꏊ
			gotoxy(floatToInt(g_Item[i].posx), floatToInt(g_Item[i].posy));
			printf("+");
		}
	}
}


void ItemDelete(int id)
{
	//�����t���O���I�t�ɂ���
	g_Item[id].use = 0;

	//�A�C�e���̕\���������I�ɍ폜
	gotoxy(floatToInt(g_Item[id].posx), floatToInt(g_Item[id].posy));
	printf(" ");
}


//g_Item�̃Q�b�^�[�֐�
ITEM* GetItem()
{
	return g_Item;
}

