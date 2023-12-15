#pragma once

//画面の大きさを定義する
#define SCREEN_LEFT   1
#define SCREEN_TOP    1
#define SCREEN_RIGHT  40
#define SCREEN_BOTTOM 20

//プレイヤーデータ構造体
struct PLAYER
{
	float posx;//現在のX座標
	float posy;//現在のY座標
	float pos_oldx;//前回のX座標
	float pos_oldy;//前回のY座標

	float speedx;//横への移動速度
	float speedy;//縦への移動速度
};

PLAYER* GetPlayer();

int floatToInt(float f);

int floatToInt(float f)
{
	return (int)(f + 0.5f);
}
