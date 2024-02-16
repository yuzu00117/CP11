//main.cpp以外のすべての.cppでconioexを使うときは#define CONIOEXを追加する
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
		//アイテム座標をランダムにセットする
		g_Item[i].posx = rand() % SCREEN_RIGHT + 1;//1～40のランダム
		g_Item[i].posy = rand() % SCREEN_BOTTOM + 1;//1～20のランダム
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
			//現在の場所
			gotoxy(floatToInt(g_Item[i].posx), floatToInt(g_Item[i].posy));
			printf("+");
		}
	}
}


void ItemDelete(int id)
{
	//生存フラグをオフにする
	g_Item[id].use = 0;

	//アイテムの表示を強制的に削除
	gotoxy(floatToInt(g_Item[id].posx), floatToInt(g_Item[id].posy));
	printf(" ");
}


//g_Itemのゲッター関数
ITEM* GetItem()
{
	return g_Item;
}

