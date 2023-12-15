#pragma once


//画面の大きさを定義する
#define SCREEN_LEFT   1
#define SCREEN_TOP    1
#define SCREEN_RIGHT  40
#define SCREEN_BOTTOM 20


//プレイヤーデータ構造体
struct PLAYER
{
	float posx;		//現在のX座標
	float posy;		//現在のY座標
	float pos_oldx;	//前回のX座標
	float pos_oldy;	//前回のY座標

	float speedx;	//横への移動速度
	float speedy;	//縦への移動速度

	int use;		// 使用しているか使用していないかのフラグ
};

PLAYER* GetPlayer();
PLAYER* GetEnemy();
int floatToInt(float f);//座標を実数から整数に変換する

// ヘッダーファイルにはメモリを使用するものを置かない
