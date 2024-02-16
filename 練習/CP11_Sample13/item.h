#pragma once


//アイテムの数を定義する
#define NUM_ITEM (3)


//プレイヤーデータ構造体
struct ITEM
{
	float posx;//現在のX座標
	float posy;//現在のY座標

	int use;//使用しているか使用していないかのフラグ
};

void ItemInit(void);
void ItemUninit(void);
void ItemUpdate(void);
void ItemDraw(void);

void ItemCreate(void);
void ItemDelete(int id);

ITEM* GetItem();
