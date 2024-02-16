#pragma once


enum SCENE
{
	SCENE_TITLE,	//�^�C�g�����
	SCENE_GAME,		//�Q�[���{��
	SCENE_RESULT,	//���U���g�\��

};


void SceneInit(void);
void SceneUninit(void);
void SceneUpdate(void);
void SceneDraw(void);

void SetScene(SCENE next);
void CheckScene(void);
