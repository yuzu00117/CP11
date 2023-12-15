#pragma once

//敵の数を定義する
#define NUM_ENEMY (20)

void EnemyInit(void);	//初期化
void EnemyUninit(void);	//終了処理
void EnemyUpdate(void);	//更新
void EnemyDraw(void);	//描画
void EnemyDelete(int id);