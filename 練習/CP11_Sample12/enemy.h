#pragma once


//敵の数を定義する
#define NUM_ENEMY (20)


//プレイヤーデータ構造体
struct ENEMY
{
	float posx;//現在のX座標
	float posy;//現在のY座標
	float pos_oldx;//前回のX座標
	float pos_oldy;//前回のY座標

	float speedx;//横への移動速度
	float speedy;//縦への移動速度

	int use;//使用しているか使用していないかのフラグ
};


void EnemyInit(void);
void EnemyUninit(void);
void EnemyUpdate(void);
void EnemyDraw(void);

void EnemyDelete(int id);

ENEMY* GetEnemy();
