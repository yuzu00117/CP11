
#include "scene.h"
#include "title.h"
#include "game.h"
#include "result.h"
#include <stdlib.h>


//始めたいシーンで初期化しておく
SCENE g_Scene = SCENE_TITLE;		//現在動作中のシーン
SCENE g_SceneNext = SCENE_TITLE;	//移行先シーン



//シーンの初期化
void SceneInit(void)
{
	switch (g_Scene)
	{
	case SCENE_TITLE:
		//タイトル画面の初期化
		TitleInit();
		break;
	case SCENE_GAME:
		//ゲーム本編の初期化
		GameInit();
		break;
	case SCENE_RESULT:
		//結果表示の初期化
		ResultInit();
		break;
	}
}

//シーンの終了処理
void SceneUninit(void)
{
	switch (g_Scene)
	{
	case SCENE_TITLE:
		//タイトル画面の終了処理
		TitleUninit();
		break;
	case SCENE_GAME:
		//ゲーム本編の終了処理
		GameUninit();
		break;
	case SCENE_RESULT:
		//結果表示の終了処理
		ResultUninit();
		break;
	}
}

//シーンの更新処理
void SceneUpdate(void)
{
	switch (g_Scene)
	{
	case SCENE_TITLE:
		//タイトル画面の更新処理
		TitleUpdate();
		break;
	case SCENE_GAME:
		//ゲーム本編の更新処理
		GameUpdate();
		break;
	case SCENE_RESULT:
		//結果表示の更新処理
		ResultUpdate();
		break;
	}
}

//シーンの描画処理
void SceneDraw(void)
{
	switch (g_Scene)
	{
	case SCENE_TITLE:
		//タイトル画面の描画処理
		TitleDraw();
		break;
	case SCENE_GAME:
		//ゲーム本編の描画処理
		GameDraw();
		break;
	case SCENE_RESULT:
		//結果表示の描画処理
		ResultDraw();
		break;
	}
}

//移行先シーンをセットする
void SetScene(SCENE next)
{
	g_SceneNext = next;
}

//移行先シーンがセットされているかチェックする
void CheckScene(void)
{
	//現在動作しているシーンと移行先シーンが違っているか、をチェックする
	if (g_Scene != g_SceneNext)
	{
		//現在動作中のシーンを終了させる
		SceneUninit();

		//現在のシーンを移行先シーンで更新する
		g_Scene = g_SceneNext;

		//移行先シーンを初期化する
		SceneInit();

		//画面のクリア
		system("cls");
	}
}
