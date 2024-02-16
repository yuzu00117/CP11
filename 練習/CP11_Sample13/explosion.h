#pragma once


//爆発アニメーション構造体
struct EXPLOSION
{
	float posx;//現在のX座標
	float posy;//現在のY座標

	int frame;//経過フレーム（時間）

	int use;//使用しているか使用していないかのフラグ
};


void ExplosionInit(void);
void ExplosionUninit(void);
void ExplosionUpdate(void);
void ExplosionDraw(void);

void ExplosionStart(float posx, float posy);
