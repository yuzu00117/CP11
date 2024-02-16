
#include "scene.h"
#include "title.h"
#include "game.h"
#include "result.h"
#include <stdlib.h>


//�n�߂����V�[���ŏ��������Ă���
SCENE g_Scene = SCENE_TITLE;		//���ݓ��쒆�̃V�[��
SCENE g_SceneNext = SCENE_TITLE;	//�ڍs��V�[��



//�V�[���̏�����
void SceneInit(void)
{
	switch (g_Scene)
	{
	case SCENE_TITLE:
		//�^�C�g����ʂ̏�����
		TitleInit();
		break;
	case SCENE_GAME:
		//�Q�[���{�҂̏�����
		GameInit();
		break;
	case SCENE_RESULT:
		//���ʕ\���̏�����
		ResultInit();
		break;
	}
}

//�V�[���̏I������
void SceneUninit(void)
{
	switch (g_Scene)
	{
	case SCENE_TITLE:
		//�^�C�g����ʂ̏I������
		TitleUninit();
		break;
	case SCENE_GAME:
		//�Q�[���{�҂̏I������
		GameUninit();
		break;
	case SCENE_RESULT:
		//���ʕ\���̏I������
		ResultUninit();
		break;
	}
}

//�V�[���̍X�V����
void SceneUpdate(void)
{
	switch (g_Scene)
	{
	case SCENE_TITLE:
		//�^�C�g����ʂ̍X�V����
		TitleUpdate();
		break;
	case SCENE_GAME:
		//�Q�[���{�҂̍X�V����
		GameUpdate();
		break;
	case SCENE_RESULT:
		//���ʕ\���̍X�V����
		ResultUpdate();
		break;
	}
}

//�V�[���̕`�揈��
void SceneDraw(void)
{
	switch (g_Scene)
	{
	case SCENE_TITLE:
		//�^�C�g����ʂ̕`�揈��
		TitleDraw();
		break;
	case SCENE_GAME:
		//�Q�[���{�҂̕`�揈��
		GameDraw();
		break;
	case SCENE_RESULT:
		//���ʕ\���̕`�揈��
		ResultDraw();
		break;
	}
}

//�ڍs��V�[�����Z�b�g����
void SetScene(SCENE next)
{
	g_SceneNext = next;
}

//�ڍs��V�[�����Z�b�g����Ă��邩�`�F�b�N����
void CheckScene(void)
{
	//���ݓ��삵�Ă���V�[���ƈڍs��V�[��������Ă��邩�A���`�F�b�N����
	if (g_Scene != g_SceneNext)
	{
		//���ݓ��쒆�̃V�[�����I��������
		SceneUninit();

		//���݂̃V�[�����ڍs��V�[���ōX�V����
		g_Scene = g_SceneNext;

		//�ڍs��V�[��������������
		SceneInit();

		//��ʂ̃N���A
		system("cls");
	}
}
