#pragma once


//プレイヤーデータ構造体
struct PLAYER
{
	float posx;//現在のX座標
	float posy;//現在のY座標
	float pos_oldx;//前回のX座標
	float pos_oldy;//前回のY座標

	float speedx;//横への移動速度
	float speedy;//縦への移動速度

	int use;//使用しているか使用していないかのフラグ
};


void PlayerInit(void);
void PlayerUninit(void);
void PlayerUpdate(void);
void PlayerDraw(void);

PLAYER* GetPlayer();
