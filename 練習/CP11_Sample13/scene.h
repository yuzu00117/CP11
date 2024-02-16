#pragma once


enum SCENE
{
	SCENE_TITLE,	//タイトル画面
	SCENE_GAME,		//ゲーム本編
	SCENE_RESULT,	//リザルト表示

};


void SceneInit(void);
void SceneUninit(void);
void SceneUpdate(void);
void SceneDraw(void);

void SetScene(SCENE next);
void CheckScene(void);
